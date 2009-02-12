#include <iostream>
using namespace std;

#include "tavlcom.h"

int main ()
{
	TComplejo c1 (5,5), c2 (4,4), c3 (9,9), c4 (6,6), c5 (10,10), c6 (3,3), c7 (7,7), c8 (6,6);
	TAVLCom a;
	
	a.Insertar (c1);
	a.Insertar (c2);
	a.Insertar (c3);
	a.Insertar (c4);
	a.Insertar (c5);
	a.Insertar (c6);
	a.Insertar (c7);
	//~ a.Insertar (c8);
	
	cout << "Preorden: " << a.Preorden () << endl;
	
	a.Borrar (c1);
	
	cout << "Preorden: " << a.Preorden () << endl;

}
