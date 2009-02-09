#include <iostream>
using namespace std;

#include "tavlcom.h"

int main ()
{
	TComplejo c1 (2,3), c2 (1,1);
	TAVLCom a;
	
	if (a.Insertar (c1))
	{
		cout << "bien" << endl;
	}
	
	if (a.Insertar (c1))
	{
		cout << "Maaal" << endl;
	}
	
	if (a.Insertar (c2))
	{
		cout << "reketebien" << endl;
	}
}
