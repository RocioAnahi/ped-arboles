#include <iostream>
using namespace std;

#include "tavlcom.h"

int main ()
{
	TComplejo c1 (10,10), c2 (87,87), c3 (39,39), c4 (38,38), c5 (46,46), c6 (69,69), c7 (25,25), c8 (6,6);
	TAVLCom a;
	
	a.Insertar (c1);
	a.Insertar (c2);
	a.Insertar (c3);
	a.Insertar (c4);
	a.Insertar (c5);
	a.Insertar (c6);
	a.Insertar (c7);
	a.Insertar (c8);
	
	cout << "Preorden: " << a.Preorden () << endl;
}
