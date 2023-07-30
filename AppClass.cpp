#include "AppClass.h"
#include "VectorItr.h"
#include <iostream>

using namespace std;

AppClass::AppClass ()
{
	theVector = new VectorMgr(INITIAL_SIZE);
}

void AppClass::run ()
{
	int ch = menu();
	while(ch != EXIT)
	{
		switch(ch)
		{
			case ADD: add();
				break;
			case DELETE : remove();
				break;
			case RETRIEVE : retrieve();
				break;
			case FIND : find();
				break;
			case LIST : list();
				break;
			case SIZE : size();
				break;
			case NUMB_ELEMENTS : numb_elements ();
				break;
			case RESIZE : resize();
				break;
		}
		ch = menu();
	}
}

int AppClass::menu ()
{
	int choice ;
	cout << "You can : " << endl;
	cout << "1. Add an element " << endl;
	cout << "2. Delete and element " << endl;
	cout << "3. Retrieve an element by its position " << endl;
	cout << "4. Find an element's position  " << endl;
	cout << "5. List all the elements in the ds " << endl;
	cout << "6. Size of the ds " << endl;
	cout << "7. No. of elements in the ds " << endl;
	cout << "8. Resize the vector " << endl;
	cout << "Choice : " << endl;
	cin >> choice ;
	return choice ;
}

void AppClass::add ()
{
	int value ;
	cout << " Enter the value to add " << endl;
	cin >> value ;
	bool result = theVector->addElement(value);
	if (result)
		cout << " Added successfully " << endl;
	else 
	{
		cout << " Couldn't add as size is full. Do you want to resize ? " << endl;
		char yes_no;
		cin>> yes_no ;
		if(yes_no =='y')
			resize();
	}
}

void AppClass::remove()
{
	int pos ;
	cout << "Enter the position to delete " << endl;
	cin >> pos ;
	bool result = theVector->deleteElement(pos);
	if(result) 
		cout << " Deletion was successful " << endl;
	else 
		cout << " Position out of range " << endl;
}

void AppClass::retrieve()
{
	int pos, value;
	cout << "Enter the position " << endl;
	cin >> pos;
	bool result = theVector->getElement(pos, value);
	if(result) 
                cout << " The vlaue at this position is  "<< value << endl;
        else 
                cout << " Position out of range " << endl;
}

void AppClass::find()
{
	int value, pos ;
	cout << " Enter a value to find"<< endl;
	cin >> value ;
	 bool result = theVector->findElement(value, pos);
        if(result) 
                cout << " The value is at  "<< pos << endl;
        else 
                cout << " No such value  " << endl;
}

void AppClass::list()
{
	int value ;
	VectorItr *theItr = new VectorItr( theVector, theVector->getSize());
	bool result = theItr->getNext(value);
	int i =0;
	while(result)
	{
		cout << i+1 << " : " << value << endl;
		result = theItr->getNext(value);
		i++ ;
		if(i>=theVector->getNumberElements())
			result = false;
	}
}

void AppClass::size()
{
	cout << "size "<< theVector->getSize() << endl;
}


void AppClass::numb_elements()
{
	cout << "Number of elements " << theVector->getNumberElements() << endl;
}

void AppClass::resize()
{
	int newSize ;
	cout << "Enter a new size for the vector " << endl;
	cin >> newSize ;
	theVector->resize(newSize);
}

