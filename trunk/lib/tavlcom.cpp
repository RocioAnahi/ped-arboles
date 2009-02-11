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
		raiz=NULL;
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
TAVLCom::Insertar (TComplejo &c)
{
	bool salida;
	bool eq;
	
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
				if (Comparar (c))
				{
					raiz->iz.raiz=new TAVLNodo;
					raiz->iz.raiz->item=c;
					salida=true;
					raiz->fe--;
				}
				else
				{
					raiz->de.raiz=new TAVLNodo;
					raiz->de.raiz->item=c;
					salida=true;
					raiz->fe++;
				}
			}
			else if (raiz->iz.EsVacio() && Comparar (c))
			{
				raiz->iz.raiz=new TAVLNodo;
				raiz->iz.raiz->item=c;
				salida=true;
				raiz->fe--;
			}
			else if (raiz->de.EsVacio() && !Comparar (c))
			{
				raiz->de.raiz=new TAVLNodo;
				raiz->de.raiz->item=c;
				salida=true;
				raiz->fe++;
			}
			else
			{
				if (Comparar (c))
				{
					salida=raiz->iz.Insertar (c);
					if (salida==true)
					{
						raiz->fe--;
						raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
						eq=Equilibrar ();
					}
				}	
				else
				{
					salida=raiz->de.Insertar (c);
					if (salida==true)
					{
						raiz->fe++;
						raiz->fe=raiz->de.Altura()-raiz->iz.Altura();
						eq=Equilibrar ();
					}
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

TListaCom
TAVLCom::Preorden ()
{
	TListaCom recorrido;
	
	if (!EsVacio())
	{
		PreordenAux (recorrido);
	}
	
	return recorrido;
}

void
TAVLCom::PreordenAux (TListaCom &l)
{
	if (!EsVacio ())
	{
		l.InsFinal (raiz->item);
		raiz->iz.PreordenAux (l);
		raiz->de.PreordenAux (l);
	}
}

bool
TAVLCom::Equilibrar ()
{
	bool salida=false;
	
	TAVLNodo *aux=NULL;
	TAVLNodo *aux2=NULL;
	TAVLNodo *aux3=NULL;
	
	if (raiz->fe==2)
	{
		if (raiz->de.raiz->fe==1)
		{
			aux=raiz;
			raiz=aux->de.raiz;
			aux2=raiz->iz.raiz;
			raiz->iz.raiz=aux;
			aux->de.raiz=aux2;

			salida=true;
		}
		else if (raiz->de.raiz->fe==-1)
		{
			aux=raiz;
			aux2=raiz->de.raiz->iz.raiz->de.raiz;
			aux3=raiz->de.raiz->iz.raiz->iz.raiz;
			
			raiz=aux->de.raiz->iz.raiz;
			raiz->iz.raiz=aux;
			raiz->de.raiz=aux->de.raiz;
			raiz->iz.raiz->de.raiz=aux3;
			raiz->de.raiz->iz.raiz=aux2;
			
			salida=true;
		}
	}
	else if (raiz->fe==-2)
	{
		if (raiz->iz.raiz->fe==1)
		{
			aux=raiz;
			aux2=raiz->iz.raiz->de.raiz->de.raiz;
			aux3=raiz->iz.raiz->de.raiz->iz.raiz;
			
			raiz=aux->iz.raiz->de.raiz;
			raiz->iz.raiz=aux->iz.raiz;
			raiz->de.raiz=aux;
			raiz->iz.raiz->de.raiz=aux3;
			raiz->de.raiz->iz.raiz=aux2;
			
			
			
			salida=true;
		}
		else if (raiz->iz.raiz->fe==-1)
		{	
			aux=raiz;
			raiz=aux->iz.raiz;
			aux2=raiz->de.raiz;
			raiz->de.raiz=aux;
			aux->iz.raiz=aux2;
			
			salida=true;
		}
	}
	
	return salida;
}

int
TAVLCom::Altura()	const
{
	int a1, a2;
	
	if (raiz!=NULL)
	{
		a1=raiz->iz.Altura();
		a2=raiz->de.Altura();
		if (a1<a2)
		{
			return (1+a2);
		}
		else
		{
			return (1+a1);
		}
	}
	else
	{
		return 0;
	}
}
