

int insertion_book()
{
	struct book *p;
	p = (struct contact *) calloc(sizeof(struct book));
	if (p == 0)
	{
		cout << "Out of memory." << endl;
		
		return -1;
	}
	
	cout << endl << "@Inserting book node.........." << endl;
	cout << "Enter the title: ";
	cin.ignore(); // fflush()
	cin.getline(title, 100);
	cout << "Enter the url (http address): ";
	cin.getline(birthday, 11);

}

class Student: public Personnel
{
	typedef enum {true, false}
	boolean;
	typedef enum {freshman, sophomore, junior, senior} level;
private:
	
public:

	void setDepartment(char *cDepartment)
	{
		strcpy(this->cDepartment, cDepartment);
	}

	void setSalary(float fSalary)
	{
		this->fSalary = fSalary;
	}

	char* getDepartment()
	{
		return cDepartment;
	}

	float getSalary()
	{
		return fSalary;
	}

	void display()
	{
		Personnel::display();
		cout << "EMPLOYEE" << endl;
		cout << "Department:\t" << getDepartment() << endl;
		cout << "Salary:\t" << getSalary() << endl;
		cout << "Rank:\t" << getRank() << endl;
	}

	Employee(char *cName, char *cBirthday, char *cAddress, char *cPhone, char *cEmail, char
			*cDepartment, float fSalary, char *cRank)
	: Personnel(cName, cBirthday, cAddress, cPhone, cEmail)
	{
		setDepartment(cDepartment);
		setSalary(fSalary);
		setRank(cRank);
	}

	virtual ~Employee()
	{
		// destructor
		delete pContact;
		// delete the object linked to pContact
		pContact = NULL;
		// Make sure pContact does not point to
	}
	// any object
};