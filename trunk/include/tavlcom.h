#ifndef _TAVLCOM_
#define _TAVLCOM_

#include <iostream>
using namespace std;

#include "tcomplejo.h"
#include "tlistacom.h"

class TAVLNodo;

class TAVLCom
{	
	public:
		TAVLCom ();
		TAVLCom (const TAVLCom &);
		~TAVLCom ();
		TAVLCom& operator= (const TAVLCom&);
		
		bool operator==(const TAVLCom &)	const;
		bool operator!=(const TAVLCom &)	const;
		bool EsVacio ()	const;
		bool Insertar (TComplejo &);
		bool Buscar (const TComplejo &)	const;
		int Altura ()	const;
		int Nodos ()	const;
		int NodosHoja ()	const;
		TListaCom Inorden ();
		TListaCom Preorden ();
		TListaCom Postorden ();
		TListaCom Niveles ();
		bool Borrar (const TComplejo &);
		
	private:
		TAVLNodo *raiz;
		
		bool Equilibrar ();
		void InordenAux (TListaCom &);
		void PreordenAux (TListaCom &);
		void PostdenAux (TListaCom &);
		
		//True:	derecha
		//False: izquierda
		bool Comparar (TComplejo &);
};

class TAVLNodo
{
	friend class TAVLCom;
	
	public:
		TAVLNodo ();
		TAVLNodo (const TAVLNodo &);
		~TAVLNodo ();
		TAVLNodo& operator= (const TAVLNodo &);
		
	private:
		TComplejo item;
		TAVLCom iz,de;
		int fe;
};





#endif
