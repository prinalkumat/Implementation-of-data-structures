#ifndef VECTORMGR_H
#define VECTORMGR_H

class VectorMgr
{
	private : 
		int total_elements, current_size ;
		int * theVector;
	public :
		VectorMgr (int);
		~VectorMgr ();
		bool addElement (int);
		bool getElement (int, int&);
		bool deleteElement (int);
		bool findElement (int, int&);
		int getNumberElements ();
		int getSize();
		bool isEmpty ();
		void resize (int);
};

#endif

