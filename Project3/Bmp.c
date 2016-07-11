/***************************************************************************************************************
 * FILE: Bmp.c
 *
 * DESCRIPTION
 * See comments in Bmp.h.
 *
 * CSE 220
 **************************************************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "Bmp.h"
#include "Error.h"
#include "File.h"

//==============================================================================================================
// PREPROCESSOR MACROS
//==============================================================================================================

// Asserts that 'cond' is true. If it is not, then we close the file stream 'stream' and return from the
// BmpRead() function with the return value 'error'.
#define BmpAssert(cond, stream, error) if (!(cond)) { if ((stream)) FileClose((stream)); return error; }

//==============================================================================================================
// PUBLIC CONSTANT DEFINTIONS
//==============================================================================================================

const size_t cSizeofBmpHeader = 14; // Size of the BMPHEADER struct.
const size_t cSizeofBmpInfoHeader = 40; // Size of the BMPINFOHEADER struct.

//==============================================================================================================
// PRIVATE CONSTANT DEFINTIONS
//==============================================================================================================

// A valid BMP file has to be at least 58 bytes in size.
const size_t cBmpMinFileSize = 58;

//==============================================================================================================
// PRIVATE FUNCTION DECLARATIONS
//==============================================================================================================

static int BmpCalcFileSize(int pWidth, int pHeight);
static int BmpCalcPad(int pWidth);

//==============================================================================================================
// FUNCTION DEFINITIONS
//==============================================================================================================

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpCalcFileSize()
 *
 * DESCRIPTION
 * Calculate the file size based on the image width and height. This value is written to the BMPHEADER structure
 *------------------------------------------------------------------------------------------------------------*/
static int BmpCalcFileSize(int pWidth, int pHeight)
{
	int bytesForPixels = pHeight * (3 * pWidth + BmpCalcPad(pWidth)) + 54;
	return bytesForPixels;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpCalcPad()
 *
 * DESCRIPTION
 * Calculate the number of padding bytes that are at the end of each row of pixel data in the pixel array.
 *------------------------------------------------------------------------------------------------------------*/
static int BmpCalcPad(int pWidth)
{
	int overBy = pWidth % 4;
	int padBytes;
	if (overBy == 0)
		padBytes = 0;
	else
		padBytes = 4 - overBy;
	return padBytes;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpPixelAlloc()
 *------------------------------------------------------------------------------------------------------------*/
tPixel **BmpPixelAlloc(int pWidth, int pHeight)
{
	tPixel **pixels = (tPixel **) calloc(pHeight, sizeof (tPixel*));
	for (int row = 0; row < pHeight; row++)
	{
		pixels[row] = (tPixel*) calloc(pWidth, sizeof (tPixel));
	}
	return pixels;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpPixelFree()
 *------------------------------------------------------------------------------------------------------------*/
void BmpPixelFree(tPixel **pPixel, int pHeight)
{
	for (int row = 0; row < pHeight; row++)
	{
		free(pPixel[row]);
	}
	free(pPixel);
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpRead()
 *
 * DESCRIPTION
 *------------------------------------------------------------------------------------------------------------*/

tError BmpRead(char *pFilename, tBmp * pBmp)
{
	/*
	 * Verify the size of the file is greater than or equal to cBmpMinFileSize bytes. Use FileSize().
	 * Open the file FileOpen();
	 * Read BMPHeader structure and initialize the tBmpHeader Structure. FileRead() and memcpy()
	 * Validate the contents of the BMPHeader
	 * Corrupted test: given the width and height determine the size of the file. if the size we calculated does not match the actual file size then we assum corrupted. Use BmpCalcFileSize()
	 * If they are the same, read pixel array. Dynamically allocate a 2D array which is height x width with each element being at tPixel. Don't forget to read the padding bytes and check they are zero. Use BmpPixelAlloc() and BmpCalcPad()
	 * Everything is done. Close the File and Return NoError. use FileClose()
	 * BMPWrite is the reverse of BMPRead() and we don't need to do the test.
	 */
	if (FileSize(pFilename) >= cBmpMinFileSize)
	{
		FILE* bmpFile = FileOpen(pFilename, "rb");
		if (bmpFile == NULL) return ErrorFileOpen;
		byte *buffer = calloc(14, sizeof (byte));
		if (fread(buffer, sizeof (byte), cSizeofBmpHeader, bmpFile) != cSizeofBmpHeader) return ErrorFileRead;
		pBmp->header.sigB = buffer[0];
		pBmp->header.sigM = buffer[1];
		memcpy(&pBmp->header.fileSize, &buffer[2], sizeof (pBmp->header.fileSize));
		memcpy(&pBmp->header.resv1, &buffer[6], sizeof (pBmp->header.resv1));
		memcpy(&pBmp->header.resv2, &buffer[8], sizeof (pBmp->header.resv2));
		memcpy(&pBmp->header.pixelOffset, &buffer[10], sizeof (pBmp->header.pixelOffset));
		free(buffer);
		byte isValid = 1;
		if (pBmp->header.sigB != 'B') isValid = 0;
		if (pBmp->header.sigM != 'M') isValid = 0;
		if (pBmp->header.fileSize != FileSize(pFilename)) isValid = 0;
		if (pBmp->header.resv1 != 0) isValid = 0;
		if (pBmp->header.resv2 != 0) isValid = 0;
		if (pBmp->header.pixelOffset != 54) isValid = 0;
		if (!isValid) return ErrorBmpInv;
		buffer = calloc(40, sizeof (byte));
		if (fread(buffer, sizeof (byte), cSizeofBmpInfoHeader, bmpFile) != cSizeofBmpInfoHeader) return ErrorFileRead;
		memcpy(&pBmp->infoHeader.size, &buffer[0], sizeof (pBmp->infoHeader.size));
		memcpy(&pBmp->infoHeader.width, &buffer[4], sizeof (pBmp->infoHeader.width));
		memcpy(&pBmp->infoHeader.height, &buffer[8], sizeof (pBmp->infoHeader.height));
		memcpy(&pBmp->infoHeader.colorPlanes, &buffer[12], sizeof (pBmp->infoHeader.colorPlanes));
		memcpy(&pBmp->infoHeader.bitsPerPixel, &buffer[14], sizeof (pBmp->infoHeader.bitsPerPixel));
		memcpy(&pBmp->infoHeader.zeros, &buffer[16], sizeof (pBmp->infoHeader.zeros));
		free(buffer);
		if (pBmp->infoHeader.size != cSizeofBmpInfoHeader) isValid = 0;
		if (pBmp->infoHeader.colorPlanes != 1) isValid = 0;
		if (pBmp->infoHeader.bitsPerPixel != 24) isValid = 0;
		int fileSize = BmpCalcFileSize(pBmp->infoHeader.width, pBmp->infoHeader.height);
		if (pBmp->header.fileSize != fileSize) isValid = 0;
		if (!isValid) return ErrorBmpInv;
		byte* padding = calloc(3, sizeof (byte));
		int bytesOfPadding = BmpCalcPad(pBmp->infoHeader.width);
		pBmp->pixel = BmpPixelAlloc(pBmp->infoHeader.width, pBmp->infoHeader.height);
		for (int row = 0; row < pBmp->infoHeader.height; row++)
		{
			if (fread(pBmp->pixel[row], sizeof (tPixel), pBmp->infoHeader.width, bmpFile) != pBmp->infoHeader.width) return ErrorFileRead;
			if (fread(padding, sizeof (byte), bytesOfPadding, bmpFile) != bytesOfPadding) return ErrorFileRead;
			for (int index = 0; index < bytesOfPadding; index++)
				if (padding[index] != 0) return ErrorBmpCorrupt;
		}
		FileClose(bmpFile);
		return ErrorNone;
	}
	else
	{
		return ErrorBmpInv;
	}

}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: BmpWrite()
 *------------------------------------------------------------------------------------------------------------*/
tError BmpWrite(char *pFilename, tBmp * pBmp)
{
	FILE* bmpFile = FileOpen(pFilename, "wb");
	byte *buffer = calloc(14, sizeof (byte));
	buffer[0] = pBmp->header.sigB;
	buffer[1] = pBmp->header.sigM;
	memcpy(&buffer[2], &pBmp->header.fileSize, sizeof (pBmp->header.fileSize));
	memcpy(&buffer[6], &pBmp->header.resv1, sizeof (pBmp->header.resv1));
	memcpy(&buffer[8], &pBmp->header.resv2, sizeof (pBmp->header.resv2));
	memcpy(&buffer[10], &pBmp->header.pixelOffset, sizeof (pBmp->header.pixelOffset));
	if (fwrite(buffer, sizeof (byte), cSizeofBmpHeader, bmpFile) != cSizeofBmpHeader) return ErrorFileWrite;
	free(buffer);
	buffer = calloc(40, sizeof (byte));
	memcpy(&buffer[0], &pBmp->infoHeader.size, sizeof (pBmp->infoHeader.size));
	memcpy(&buffer[4], &pBmp->infoHeader.width, sizeof (pBmp->infoHeader.width));
	memcpy(&buffer[8], &pBmp->infoHeader.height, sizeof (pBmp->infoHeader.height));
	memcpy(&buffer[12], &pBmp->infoHeader.colorPlanes, sizeof (pBmp->infoHeader.colorPlanes));
	memcpy(&buffer[14], &pBmp->infoHeader.bitsPerPixel, sizeof (pBmp->infoHeader.bitsPerPixel));
	memcpy(&buffer[16], &pBmp->infoHeader.zeros, sizeof (pBmp->infoHeader.zeros));
	if (fwrite(buffer, sizeof (byte), cSizeofBmpInfoHeader, bmpFile) != cSizeofBmpInfoHeader) return ErrorFileWrite;
	free(buffer);
	byte* padding = calloc(3, sizeof (byte));
	int bytesOfPadding = BmpCalcPad(pBmp->infoHeader.width);
	for (int row = 0; row < pBmp->infoHeader.height; row++)
	{
		if (fwrite(pBmp->pixel[row], sizeof (tPixel), pBmp->infoHeader.width, bmpFile) != pBmp->infoHeader.width) return ErrorFileWrite;
		if (fwrite(padding, sizeof (byte), bytesOfPadding, bmpFile) != bytesOfPadding) return ErrorFileWrite;
	}
	FileClose(bmpFile);
}
