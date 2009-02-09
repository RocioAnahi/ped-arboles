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

//~ bool
//~ TAVLCom::operator==(const TAVLCom &a)	const
//~ {
	//~ return (Niveles ()==a.Niveles() && Inorden ()==a.Inorden());
//~ }
//~ 
//~ bool
//~ TAVLCom::operator!= (const TAVLCom &a)	const
//~ {
	//~ return (Niveles ()!=a.Niveles() || Inorden ()!=a.Inorden());
//~ }
//~ 
bool
TAVLCom::EsVacio ()	const
{
	return (raiz==NULL);
}

bool
TAVLCom::Insertar (const TComplejo &c)
{
	bool salida;
	
	if (raiz==NULL)
	{
		raiz=new TAVLNodo;
		raiz->item=c;
		salida=true;	
	}
	else
	{
		if (raiz->item==c)
		{
			salida=false;
		}
		else
		{
			if (raiz->iz.EsVacio() && raiz->de.EsVacio())
			{
				if (Comparar (raiz->item))
				{
					raiz->iz.raiz=new TAVLNodo;
					raiz->iz.raiz->item=c;
					salida=true;
				}
				else
				{
					raiz->de.raiz=new TAVLNodo;
					raiz->de.raiz->item=c;
					salida=true;
				}
			}
			else if (raiz->iz.EsVacio() && Comparar (raiz->item))
			{
				raiz->iz.raiz=new TAVLNodo;
				raiz->iz.raiz->item=c;
				salida=true;
			}
			else if (raiz->de.EsVacio() && !Comparar (raiz->item))
			{
				raiz->de.raiz=new TAVLNodo;
				raiz->de.raiz->item=c;
				salida=true;
			}
			else
			{
				if (Comparar (raiz->item))
				{
					salida=raiz->iz.Insertar (c);
				}	
				else
				{
					salida=raiz->de.Insertar (c);
				}
			}
		}
	}
	
	return salida;
}

bool
TAVLCom::Comparar (TComplejo &c)
{
	bool salida;
	
	if (raiz->item.Mod () < c.Mod())
	{
		salida=false;
	}
	else if (raiz->item.Mod () > c.Mod ())
	{
		salida=true;
	}
	else
	{
		if (raiz->item.Re () < c.Re ())
		{
			salida=false;
		}
		else if (raiz->item.Re () > c.Re ())
		{
			salida=true;
		}
		else
		{
			if (raiz->item.Im () < c.Im ())
			{
				salida=false;
			}
			else if (raiz->item.Im () > c.Im ())
			{
				salida=true;
			}
		}
	}
	return salida;
}
