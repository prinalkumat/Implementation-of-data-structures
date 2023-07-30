#include "VectorMgr.h"
#include <iostream> 

using namespace std;

VectorMgr::VectorMgr (int size)
{
	theVector = new int[size] ;
	if(!theVector)
	{
		cout<< "Cannot create vector" << endl;
		return ;
	}
	total_elements =0;
	current_size = size;
}

VectorMgr::~VectorMgr()
{
	delete[] theVector ;
}

bool VectorMgr::addElement(int value)
{
	if(total_elements == current_size)
		return false;
	theVector [total_elements++] = value;
	return true;
}

bool VectorMgr::getElement(int element, int & value )
{
	if(element >= total_elements)
		return false;
	value = theVector[element];
	return true;
}

bool VectorMgr::deleteElement( int element)
{
	bool result = false;
	if(element >= total_elements)
		result = false;
	for(int i =element ; i<total_elements - 1; i++)
	{
		theVector[i] = theVector[i+1];
		total_elements --;
		result = true;
	}
	return result;
}


bool VectorMgr::findElement(int value, int& element )
{
	int i =0;
	while(i < total_elements )
	{
		if(theVector[i] == value)
		{
			element = i;
			return true;
		}
		i++;
	}
	return false ;
}

int VectorMgr::getNumberElements()
{
	return total_elements;
}

int VectorMgr::getSize()
{
	return current_size;
}

bool VectorMgr::isEmpty()
{
	if(total_elements ==0)
		return true;
	return false ;
}

void VectorMgr::resize(int newSize)
{
	char yes_no;
	if(newSize < total_elements)
	{
		cout << " The new size is too small to contain the vector. Do you still want to truncate it ?" << endl;
		cin >> yes_no ;
		if(yes_no =='y')
		{
			total_elements = newSize;
		}
		else 
			return ;
	}

	int * newVector = new int(newSize);
	if (!newVector )
	{
		cout << "Cannot create vector" << endl;
		return;
	}
	for(int i=0; i< total_elements; i++)
		newVector[i]= theVector[i];
	delete[] theVector;
	theVector = newVector;
	current_size = newSize;
}

