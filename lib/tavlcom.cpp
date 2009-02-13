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

TAVLCom::TAVLCom (const TAVLCom &a):raiz(NULL)
{
	if (a.raiz!=NULL)
	{
		raiz=new TAVLNodo (*(a.raiz));
	}
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
		
		raiz=NULL;
		
		if (a.raiz!=NULL)
		{
			raiz=new TAVLNodo (*a.raiz);
		}
	}
	
	return (*this);
}

bool
TAVLCom::operator==(TAVLCom &a)
{
	return (Niveles ()==a.Niveles() && Inorden ()==a.Inorden());
}

bool
TAVLCom::operator!= (TAVLCom &a)
{
	return (Niveles ()!=a.Niveles() || Inorden ()!=a.Inorden());
}

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

TListaCom 
TAVLCom::Postorden ()
{
	TListaCom recorrido;
	
	if (!EsVacio())
	{
		PostordenAux (recorrido);
	}
	
	return (recorrido);
}

void
TAVLCom::PostordenAux (TListaCom &l)
{
	if (!EsVacio())
	{
		raiz -> iz.PostordenAux (l);
		
		raiz -> de.PostordenAux (l);
		
		l.InsFinal (raiz -> item);
	}
}

TListaCom 
TAVLCom::Inorden ()
{
	TListaCom recorrido;
	
	if (!EsVacio())
	{
		InordenAux (recorrido);
	}
	
	return (recorrido);
}

void
TAVLCom::InordenAux (TListaCom &l)
{
	if (!EsVacio())
	{
		raiz -> iz.InordenAux (l);
		
		l.InsFinal (raiz -> item);
		
		raiz -> de.InordenAux (l);		
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
		if (raiz->de.raiz->fe==1 || raiz->de.raiz->fe==0)
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
		else if (raiz->iz.raiz->fe==-1 || raiz->iz.raiz->fe==0)
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

bool
TAVLCom::Borrar (TComplejo &c)
{
	bool salida;
	
	if (raiz!=NULL)
	{
		if (raiz->item==c)
		{
			if (raiz->iz.EsVacio () && raiz->de.EsVacio())
			{
				delete raiz;
				raiz=NULL;
			}
			else if (!raiz->iz.EsVacio())
			{
				TAVLNodo *mayor=NULL;
				TComplejo aux;
				
				mayor=raiz->iz.Mayor_Iz ();
				aux=mayor->item;
				mayor->item=raiz->item;
				raiz->item=aux;
				
				salida=raiz->iz.Borrar (c);
				raiz->fe=raiz->de.Altura ()-raiz->iz.Altura();
				Equilibrar ();
			}
			else
			{
				TAVLNodo *menor=NULL;
				TComplejo aux;
				
				menor=raiz->de.Menor_De ();
				aux=menor->item;
				menor->item=raiz->item;
				raiz->item=aux;
				
				salida=raiz->de.Borrar (c);
				raiz->fe=raiz->de.Altura ()-raiz->iz.Altura();
				Equilibrar ();
			}
			
			salida=true;
		}
		else
		{
			if (Comparar (c))
			{
				salida=raiz->iz.Borrar (c);
				raiz->fe=raiz->de.Altura ()-raiz->iz.Altura();
				Equilibrar ();
			}
			else
			{
				salida=raiz->de.Borrar (c);
				raiz->fe=raiz->de.Altura ()-raiz->iz.Altura();
				Equilibrar ();
			}
		}
	}
	else
	{
		salida=false;
	}
	
	return salida;
}

TAVLNodo*
TAVLCom::Mayor_Iz ()
{
	TAVLNodo *aux=NULL;
	
	if (raiz->de.EsVacio())
	{
		aux=raiz;
	}
	else
	{
		aux=raiz->de.Mayor_Iz ();
	}
	
	return aux;
}

TAVLNodo*
TAVLCom::Menor_De ()
{
	TAVLNodo *aux=NULL;
	
	if (raiz->iz.EsVacio())
	{
		aux=raiz;
	}
	else
	{
		aux=raiz->iz.Menor_De ();
	}
	
	return aux;
}

int
TAVLCom::Nodos ()	const
{
	int salida=0;
	
	if (raiz!=NULL)
	{
		salida=1+raiz->de.Nodos()+raiz->iz.Nodos();
	}
	
	return salida;
}

int
TAVLCom::NodosHoja ()	const
{
	int salida=0;
	
	if (raiz!=NULL)
	{
		if (raiz->iz.EsVacio () && raiz->de.EsVacio ())
		{
			salida=1;
		}
		else
		{
			salida=raiz->iz.NodosHoja() + raiz->de.NodosHoja ();
		}
	}
	
	return salida;
}

TListaCom
TAVLCom::Niveles ()
{
	TColaAVLCom cola;
	TListaCom salida;
	TAVLCom *aux;
	
	if (!EsVacio ())
	{
		cola.Encolar (this);
		
		while (!cola.EsVacia ())
		{
			aux=cola.Cabeza ();
			
			salida.InsFinal (aux->raiz->item);
			
			cola.Desencolar ();
			
			if (!aux->raiz->iz.EsVacio ())	cola.Encolar (&aux->raiz->iz);
			if (!aux->raiz->de.EsVacio ())	cola.Encolar (&aux->raiz->de);
		}
	}
	
	return salida;
}

bool
TAVLCom::Buscar (TComplejo &c)
{
	bool salida;
	
	if (!EsVacio ())
	{
		if (raiz->item==c)
		{
			salida=true;
		}
		else
		{
			if (Comparar (c))
			{
				salida=raiz->iz.Buscar (c);
			}
			else
			{
				salida=raiz->de.Buscar (c);
			}
		}
	}
	else
	{
		salida=false;
	}
	
	return salida;
}

TElemColaAVLCom::TElemColaAVLCom ():arbol(NULL),sig(NULL)
{
	
}

TElemColaAVLCom::TElemColaAVLCom (const TElemColaAVLCom &c):sig (NULL)
{
	arbol=c.arbol;
}

TElemColaAVLCom::~TElemColaAVLCom ()
{
	arbol=NULL;
	sig=NULL;	
}

TElemColaAVLCom&
TElemColaAVLCom::operator= (const TElemColaAVLCom &c)
{
	if (this!=&c)
	{
		arbol=NULL;
		sig=NULL;
		
		arbol=c.arbol;	
	}
	
	return (*this);
}

TAVLCom *
TElemColaAVLCom::Arbol ()
{
	return (arbol);
}

TColaAVLCom::TColaAVLCom ():primero(NULL),ultimo(NULL)
{
}

TColaAVLCom::TColaAVLCom (const TColaAVLCom &c):primero(NULL),ultimo(NULL)
{
	if (c.primero!=NULL)
	{
		TElemColaAVLCom *aux=c.primero;
		
		primero=new TElemColaAVLCom (*c.primero);
		ultimo=primero;
		aux=aux->sig;
		
		while (aux!=NULL)
		{
			ultimo->sig=new TElemColaAVLCom (*aux);
			ultimo=ultimo->sig;
			aux=aux->sig;
		}
	}
}

TColaAVLCom::~TColaAVLCom ()
{
	TElemColaAVLCom *aux;
	aux=primero;
	
	while (aux!=NULL)
	{
		primero=aux->sig;
		delete aux;
		aux=primero;
	}
	ultimo=NULL;
}

TColaAVLCom&
TColaAVLCom::operator= (const TColaAVLCom &c)
{
	if (this!=&c)
	{
		TElemColaAVLCom *aux;
		aux=primero;
		
		while (aux!=NULL)
		{
			primero=aux->sig;
			delete aux;
			aux=primero;
		}
		ultimo=NULL;

	//______________________________________________________________
		
		if (c.primero!=NULL)
		{
			TElemColaAVLCom *aux=c.primero;
			
			primero=new TElemColaAVLCom (*c.primero);
			ultimo=primero;
			aux=aux->sig;
			
			while (aux!=NULL)
			{
				ultimo->sig=new TElemColaAVLCom (*aux);
				ultimo=ultimo->sig;
				aux=aux->sig;
			}
		}	
		
	}
	
	return (*this);
}

bool
TColaAVLCom::Encolar (TAVLCom *a)
{
	if (ultimo==NULL)
	{
		ultimo=new TElemColaAVLCom;
		primero=ultimo;
		ultimo->arbol=a;
		return true;
	}
	else
	{
		ultimo->sig=new TElemColaAVLCom;
		
		if (ultimo->sig!=NULL)
		{
			ultimo=ultimo->sig;
			ultimo->arbol=a;
			return true;
		}
		else 	return false;
	}
}

bool
TColaAVLCom::Desencolar ()
{
	TElemColaAVLCom *aux;
	
	aux=primero;
	
	if (aux!=NULL)
	{
		if (primero==ultimo)
		{
			delete aux;
			primero=ultimo=NULL;
			return true;
		}
		else
		{		
			primero=primero->sig;
			
			delete aux;
			
			return true;
		}
	}
	else 	return false;
}

TAVLCom *
TColaAVLCom::Cabeza ()
{
	TAVLCom *aux=NULL;
	
	if (primero!=NULL)
	{
		aux=primero->arbol;
	}
	
	return aux;
}

bool
TColaAVLCom::EsVacia ()
{
	return (primero==NULL);
}
