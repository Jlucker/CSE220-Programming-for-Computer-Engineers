/***************************************************************************************************************
 * FILE: Image.c
 *
 * DESCRIPTION
 * See comments in Image.h.
 *
 * CSE 220
 **************************************************************************************************************/
#include "Bmp.h"
#include "Image.h"

//==============================================================================================================
// FUNCTION DEFINITIONS
//==============================================================================================================

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ImageFlipHoriz()
 *------------------------------------------------------------------------------------------------------------*/
void ImageFlipHoriz(tBmp *pBmp)
{
	tPixel* flippedRow;
	for (int rowIndex = 0; rowIndex < pBmp->infoHeader.height; rowIndex++)
	{
		flippedRow = calloc(pBmp->infoHeader.width, sizeof (tPixel));
		for (int columnIndex = 0; columnIndex < pBmp->infoHeader.width; columnIndex++)
		{
			int index = pBmp->infoHeader.width - columnIndex - 1;
			tPixel pixel = pBmp->pixel[rowIndex][columnIndex];
			flippedRow[index].red = pixel.red;
			flippedRow[index].green = pixel.green;
			flippedRow[index].blue = pixel.blue;
		}
		free(pBmp->pixel[rowIndex]);
		pBmp->pixel[rowIndex] = flippedRow;
	}
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ImageRotRight()
 *------------------------------------------------------------------------------------------------------------*/
void ImageRotRight(tBmp *pBmp)
{
	tPixel **rotatedPixels = BmpPixelAlloc(pBmp->infoHeader.height, pBmp->infoHeader.width);
	for(int rowIndex = 0; rowIndex < pBmp->infoHeader.height; rowIndex++)
	{
		for(int columnIndex = 0; columnIndex < pBmp->infoHeader.width; columnIndex++)
		{
			rotatedPixels[columnIndex][rowIndex].red = pBmp->pixel[rowIndex][columnIndex].red;
			rotatedPixels[columnIndex][rowIndex].green = pBmp->pixel[rowIndex][columnIndex].green;
			rotatedPixels[columnIndex][rowIndex].blue = pBmp->pixel[rowIndex][columnIndex].blue;
		}
	}
	int width = pBmp->infoHeader.height;
	int height = pBmp->infoHeader.width;
	pBmp->infoHeader.width = width;
	pBmp->infoHeader.height = height;
	pBmp->pixel = rotatedPixels;
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ImageRotRightMult()
 *
 * REMARKS
 * nTimes will be 0, 1, 2, or 3. If it is 0, we don't need to do anything. Rotate right one time,
 *
 *     1 2
 *                                 5 3 1
 *     3 4    rotate right 1 -->
 *                                 6 4 2
 *     5 6
 *
 * Rotate right twice,
 *
 *     1 2                         6 5
 *
 *     3 4    rotate right 2 -->   4 3
 *
 *     5 6                         2 1
 *
 * Rotate right three times,
 *
 *     1 2
 *                                 2 4 6
 *     3 4    rotate right 3 -->
 *                                 1 3 5
 *     5 6
 *------------------------------------------------------------------------------------------------------------*/
void ImageRotRightMult(tBmp *pBmp, int nTimes)
{
	int rotations;
	if(nTimes > 4)
		rotations = nTimes % 4;
	else
		rotations = nTimes;
	switch(rotations)
	{
		case 1:
			ImageRotRight(pBmp);
			break;
		case 2:
			ImageFlipVert(pBmp);
			break;
		case 3:
			ImageRotRight(pBmp);
			ImageFlipHoriz(pBmp);
			break;
		case 4:
			// Do nothing.
			break;
	}
}

/*--------------------------------------------------------------------------------------------------------------
 * FUNCTION: ImageFlipVert()
 *------------------------------------------------------------------------------------------------------------*/
void ImageFlipVert(tBmp *pBmp)
{
	tPixel *rowA;
	tPixel *rowB;
	for (int rowIndex = 0; rowIndex < (pBmp->infoHeader.height) / 2; rowIndex++)
	{
		rowA = pBmp->pixel[rowIndex];
		rowB = pBmp->pixel[pBmp->infoHeader.height - rowIndex - 1];
		pBmp->pixel[rowIndex] = rowB;
		pBmp->pixel[pBmp->infoHeader.height - rowIndex - 1] = rowA;
	}
}
