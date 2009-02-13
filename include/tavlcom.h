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
		
		bool operator==(TAVLCom &);
		bool operator!=(TAVLCom &);
		bool EsVacio ()	const;
		bool Insertar (TComplejo &);
		bool Buscar (TComplejo &);
		int Altura ()	const;
		int Nodos ()	const;
		int NodosHoja ()	const;
		TListaCom Inorden ();
		TListaCom Preorden ();
		TListaCom Postorden ();
		TListaCom Niveles ();
		bool Borrar (TComplejo &);
		
	private:
		TAVLNodo *raiz;
		
		bool Equilibrar ();
		void InordenAux (TListaCom &);
		void PreordenAux (TListaCom &);
		void PostordenAux (TListaCom &);
		TAVLNodo* Mayor_Iz ();
		TAVLNodo* Menor_De ();
		
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

class TColaAVLCom;

class TElemColaAVLCom
{
	friend class TColaAVLCom;
	
	public:
		TElemColaAVLCom ();
		TElemColaAVLCom (const TElemColaAVLCom &);
		~TElemColaAVLCom ();
		TElemColaAVLCom& operator= (const TElemColaAVLCom &);
		
		TAVLCom* Arbol ();
		
	private:
		TAVLCom *arbol;
		TElemColaAVLCom *sig;
};

class TColaAVLCom
{
	public:
		TColaAVLCom ();
		TColaAVLCom (const TColaAVLCom &);
		~TColaAVLCom ();
		TColaAVLCom& operator= (const TColaAVLCom &);
		
		bool Encolar (TAVLCom *);
		bool Desencolar ();
		TAVLCom * Cabeza ();
		bool EsVacia ();
		
		private:
			TElemColaAVLCom *primero;
			TElemColaAVLCom *ultimo;
};



#endif
