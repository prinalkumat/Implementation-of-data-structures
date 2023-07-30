#ifndef APPCLASS_H
#define APPCLASS_H

#include "VectorMgr.h"

#define INITIAL_SIZE 10
#define ADD 1
#define DELETE 2
#define RETRIEVE 3
#define FIND 4
#define LIST 5
#define SIZE 6
#define NUMB_ELEMENTS 7
#define RESIZE 8
#define EXIT 9

class AppClass 
{
	private : 
		VectorMgr * theVector ;
		int menu() ;
		void add();
		void remove();
		void retrieve();
		void find ();
		void list();
		void size ();
		void numb_elements ();
		void resize ();

	public :
		AppClass ();
		void run();
};
#endif 

