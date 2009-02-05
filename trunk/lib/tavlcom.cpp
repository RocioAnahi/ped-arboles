#include <iostream>
using namespace std;

#include "tavlcom.h"

TAVLNodo::TAVLNodo ():fe(0)
{
}

TAVLNodo::TAVLNodo (const TAVLNodo &n)
{
	item=n.item;
	iz=n.iz;
	de=n.de;
	fe=n.fe;
}

TAVLNodo::~TAVLNodo ()
{
	fe=0;
}

TAVLNodo&
TAVLNodo::operator= (const TAVLNodo &n)
{
	if (this!=&n)
	{
		item=n.item;
		iz=n.iz;
		de=n.de;
		fe=n.fe;
	}
	
	return (*this);
}

TAVLCom::TAVLCom ():raiz(NULL)
{
}

TAVLCom::TAVLCom (const TAVLCom &a)
{
	raiz=new TAVLNodo (*a.raiz);
}

TAVLCom::~TAVLCom ()
{
	if (raiz!=NULL)
	{
		delete raiz;
	}
}

TAVLCom&
TAVLCom::operator= (const TAVLCom &a)
{
	if (this!=&a)
	{
		if (raiz!=NULL)	delete raiz;
		
		raiz=new TAVLNodo (*a.raiz);
	}
	
	return (*this);
}

bool
TAVLCom::operator==(const TAVLCom &a)	const
{
	return (Niveles ()==a.Niveles() && Inorden ()==a.Inorden());
}

bool
TAVLCom::operator!= (const TAVLCom &a)	const
{
	return (Niveles ()!=a.Niveles() || Inorden ()!=a.Inorden());
}

bool
TAVLCom::EsVacio ()	const
{
	return (Preorden().EsVacia() && Inorden().EsVacia() && Postorden().EsVacia() && Niveles().EsVacia());
}

bool
TAVLCom::Insertar ()
{
	
}
