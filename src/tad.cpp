#include <iostream>
using namespace std;

#include "tavlcom.h"

int main ()
{
	TComplejo c1 (5,5), c2 (90,90), c3 (83,83), c4 (28,28), c5 (67,67), c6 (81,81), c7 (50,50), c8 (43,43), c9 (55,55), c10(45,45);
	TAVLCom a;
	
	a.Insertar (c1);
	a.Insertar (c2);
	a.Insertar (c3);
	a.Insertar (c4);
	a.Insertar (c5);
	a.Insertar (c6);
	a.Insertar (c7);
	a.Insertar (c8);
	a.Insertar (c9);
	a.Insertar (c10);
	
	cout << "Inorden: " << a.Inorden () << endl;
	
	//~ a.Borrar (c5);
	
	//~ cout << "Preorden: " << a.Preorden () << endl;

}
