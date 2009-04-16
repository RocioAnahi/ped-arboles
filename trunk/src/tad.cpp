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
	
	TComplejo c1 (5,5), c2 (80,80), c3 (73,73), c4 (18,18), c5 (30,30), c6 (74,74), c7 (78,78), 
	c8 (89,89), c9 (99,99), c10 (76,76), c11(75,75), c12(10,10), c14(90,90), c15(7,7), c16(1,1),c17;
	
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
	a.Insertar (c12);
	a.Insertar (c14);
	a.Insertar (c17);
	a.Insertar (c16);
	
	cout << a.Inorden () << endl<< endl;
	
	cout << a.Niveles () << endl<< endl;
	
	cout << a.Nodos() << " nodos" << endl << endl;
	
	cout << a.NodosHoja () << " hojas" << endl << endl;
	
	cout << "altura " << a.Altura() << endl << endl;
	
	if (!a.Buscar (c15))
	{
		cout << "Busca bien" << endl;
	}
	
	else
	{
		cout << "No busca" << endl;
	}
	
	//~ TA234Com b(a);
	
	//~ cout << b.Inorden () << endl;
	//~ if (b == a)
	//~ {
		//~ cout << "Parece que el ctor de copia funciona" << endl << endl;
	//~ }
	
	# endif
}
