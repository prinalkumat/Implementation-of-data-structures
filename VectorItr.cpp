#include "VectorItr.h"

VectorItr::VectorItr(VectorMgr * invector, int iElement )
{
	theVector = invector ;
	numb_elements = iElement ;
	current_index = 0;;
}

bool VectorItr::getNext(int& value )
{
	bool result = false;
	if( current_index < numb_elements)
	{
		result = theVector->getElement(current_index, value);
		current_index ++;
		result = true;
	}
	return result ;
}


		
