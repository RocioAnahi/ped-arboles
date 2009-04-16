# include <iostream>

using namespace std;

# include "tavlcom.h"
# include "ta234com.h"

int main ()
{	
	# ifdef _MAIN_
	
	TComplejo c1 (5,5), c2 (90,90), c3 (83,83), c4 (28,28), c5 (67,67),
	c6 (81,81), c7 (50,50), c8 (43,43), c9 (55,55), c10(45,45),c_inventao(69,69);
	
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
	
	TAVLCom b(a);
	
	cout << "Inordena: " << a.Inorden () << endl;
	
	cout << "Inordenb: " << b.Inorden () << endl;
	
	cout << "Nivelesa: " << a.Niveles () << endl;
	
	cout << "Nodos: " << a.Nodos () << endl;
	
	cout << "Nodos Hoja: " << a.NodosHoja () << endl;
	
	if (a==b)	cout << "Son Iguales" << endl;
	
	a.Borrar (c5);
	
	cout << "Preorden: " << a.Preorden () << endl;
	
	if (a.Buscar (c10))	cout << "Encuentra el c10" << endl;
	
	if (!a.Buscar (c_inventao))	cout << "No encuentra el inventao" << endl;

	# else
	
	TComplejo c1 (5,5), c2 (90,90), c3 (83,83), c4 (28,28), c5 (40,40), c6 (84,84), c7 (88,88), 
	c8 (99,99), c9 (110,110), c10 (86,86), c11(85,85), c12(20,20), c14(100,100);
	
	TA234Com a;
	
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
	a.Insertar (c11);
	//~ a.Insertar (c12);
	a.Insertar (c14);
	a.Insertar (c12);
	
	cout << a.Inorden () << endl<< endl;
	cout << a.Niveles () << endl;
	
	# endif
}
