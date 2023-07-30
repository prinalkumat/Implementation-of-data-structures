#ifndef VECTOR_ITR_H
#define VECTOR_ITR_H

#include "VectorMgr.h"

class VectorItr
{
	private:
		VectorMgr * theVector;
		int numb_elements ;
		int current_index;
	public :
		VectorItr ( VectorMgr *, int);
		bool getNext (int &);
};
#endif 

