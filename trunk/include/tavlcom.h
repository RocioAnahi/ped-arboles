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
		bool Insertar (const TComplejo &);
		bool Buscar (const TComplejo &)	const;
		int Altura ()	const;
		int Nodos ()	const;
		int NodosHoja ()	const;
		TListaCom Inorden ()	const;
		TListaCom Preorden ()	const;
		TListaCom Postorden ()	const;
		TListaCom Niveles ()	const;
		bool Borrar (const TComplejo &);
		
	private:
		TAVLNodo *raiz;
		
		void InordenAux (const TListaCom &);
		void PreordenAux (const TListaCom &);
		void PostdenAux (const TListaCom &);
};

class TAVLNodo
{
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
