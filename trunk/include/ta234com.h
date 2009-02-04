#ifndef _TA234COM_
#define _TA234COM_

#include <iostream>
using namespace std;

#include "tcomplejo.h"
#include "tlistacom.h"

class TA234Com;

class TA234Nodo
{
	public:
		TA234Nodo ();
		TA234Nodo (const TA234Nodo &);
		~TA234Nodo ();
		TA234Nodo& operator= (const TA234Nodo &);
	
	private:
		TComplejo itIz;
		TComplejo itDe;
		TComplejo itMe;
		TA234Com hijoIz;
		TA234Com hijoMeIz;
		TA234Com hijoMeDe;
		TA234Com hijoDe;
};

class TA234Com
{
	public:
		TA234Com ();
		TA234Com (const TA234Com &);
		~TA234Com ();
		TA234Com& operator= (const TA234Com &);
		
		bool operator== (const TA234Com &)	const;
		bool operator!= (const TA234Com &)	const;
		bool EsVacio ()	const;
		bool Insertar (const TComplejo &);
		bool Buscar (const TComplejo &)	const;
		int Altura ()	const;
		int Nodos ()	const;
		int NodosHoja ()	const;
		TListaCom Niveles ()	const;
		TListaCom Inorden ()	const;
		bool Borrar (const TComplejos &);
			
	private:
		TA234Com *raiz;
};


#endif
