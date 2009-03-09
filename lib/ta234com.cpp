# include <iostream>

using namespace std;

# include "ta234com.h"

TA234Nodo::TA234Nodo ()
{
}

TA234Nodo::TA234Nodo (const TA234Nodo &n): tipo_nodo(0), itIz(n.itIz), itDe(n.itDe), itMe(n.itMe), hijoIz(n.hijoIz), hijoMeIz(n.hijoMeIz), hijoMeDe(n.hijoMeDe), hijoDe(n.hijoDe)
{
}

TA234Nodo::~TA234Nodo ()
{
	tipo_nodo = 0;
}

TA234Nodo&
TA234Nodo::operator= (const TA234Nodo &n)
{
	if (this != &n)
	{
		tipo_nodo = n.tipo_nodo;
		
		itIz = n.itIz;
		
		itDe = n.itDe;
		
		itMe = n.itMe;
		
		hijoIz = n.hijoIz;
		
		hijoMeIz = n.hijoMeIz;
		
		hijoMeDe = n.hijoMeDe;
		
		hijoDe = n.hijoDe;
	}
	
	return (*this);
}

TA234Com::TA234Com (): raiz(NULL)
{
}

TA234Com::TA234Com (const TA234Com &a)
{
	if (a.raiz != NULL)
	{
		raiz = new TA234Nodo (*(a.raiz));
	}
}

TA234Com::~TA234Com ()
{
	if (raiz != NULL)
	{
		delete raiz;
		
		raiz = NULL;
	}
}

TA234Com&
TA234Com::operator= (const TA234Com &a)
{
	if (this != &a)
	{
		if (raiz != NULL)
		{
			delete raiz;
		
			raiz = NULL;
		}
		
		
		if (a.raiz != NULL)
		{
			raiz = new TA234Nodo (*(a.raiz));
		}
	}
	
	return (*this);
}

bool
TA234Com::operator== (TA234Com &a)
{
	return (Niveles() == a.Niveles() && Inorden() == a.Inorden());
}

bool
TA234Com::operator!= (TA234Com &a)
{
	return (Niveles() != a.Niveles() || Inorden() != a.Inorden());
}

bool
TA234Com::EsVacio () const
{
	return (raiz == NULL);
}

TListaCom 
TA234Com::Inorden () const
{
	TListaCom recorrido;
	
	if (!EsVacio())
	{
		InordenAux (recorrido);
	}
	
	return (recorrido);
}

void
TA234Com::InordenAux (TListaCom &l) const
{
	if (!EsVacio())
	{
		if (raiz->tipo_nodo == 2)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
		}
		
		else if (raiz->tipo_nodo == 3)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
			
			l.InsFinal (raiz -> itMe);
			
			raiz -> hijoMeDe.InordenAux (l);
		}
		
		else if (raiz->tipo_nodo == 4)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
			
			l.InsFinal (raiz -> itMe);
			
			raiz -> hijoMeDe.InordenAux (l);
			
			l.InsFinal (raiz -> itDe);
			
			raiz -> hijoDe.InordenAux (l);
		}
	}
}

TListaCom
TA234Com::Niveles ()
{
	TColaA234Com cola;
	
	TListaCom salida;
	
	TA234Com *aux;
	
	if (!EsVacio ())
	{
		cola.Encolar (this);
		
		while (!cola.EsVacia ())
		{
			aux = cola.Cabeza ();
			
			if (raiz->tipo_nodo == 2)
			{
				salida.InsFinal (aux -> raiz -> itIz);
			}
			
			else if (raiz->tipo_nodo == 3)
			{
				salida.InsFinal (aux -> raiz -> itIz);
				
				salida.InsFinal (aux -> raiz -> itMe);
			}
			
			else if (raiz->tipo_nodo == 4)
			{
				salida.InsFinal (aux -> raiz -> itIz);
				
				salida.InsFinal (aux -> raiz -> itMe);
				
				salida.InsFinal (aux -> raiz -> itDe);
			}
			
			
			cola.Desencolar ();
			
			if (!aux -> raiz -> hijoIz.EsVacio ())	
			{
				cola.Encolar (&aux -> raiz -> hijoIz);
			}
			
			if (!aux -> raiz -> hijoMeIz.EsVacio ())	
			{
				cola.Encolar (&aux -> raiz -> hijoMeIz);
			}
			
			if (!aux -> raiz -> hijoMeDe.EsVacio ())	
			{
				cola.Encolar (&aux -> raiz -> hijoMeDe);
			}

			if (!aux -> raiz -> hijoDe.EsVacio ())	
			{
				cola.Encolar (&aux -> raiz -> hijoDe);
			}
		}
	}
	
	return (salida);
}

bool
TA234Com::Insertar (TComplejo &c)
{
	bool salida;
	
	
	return (salida);	
}

bool
TA234Com::EsHoja ()
{
	return (raiz->hijoIz.raiz==NULL && raiz->hijoMeIz.raiz==NULL && raiz->hijoMeDe.raiz==NULL && raiz->hijoDe.raiz==NULL);
}


int
TA234Com::Comparar (TComplejo &c)
{
	if (raiz->tipo_nodo == 1)
	{
		if (c.Comparar(raiz->itIz))
		{
			return 1;
		}
		
		else
		{
			return 2; 
		}
	}
	
	else if (raiz->tipo_nodo == 2)
	{
		if (c.Comparar(raiz->itIz))
		{
			return 1; 
		}
		
		else if (c.Comparar (raiz->itMe))
		{
			return 2; 
		}
		
		else
		{
			return 3; 
		}
		
	}
	
	else if (raiz->tipo_nodo == 3)
	{
		if (c.Comparar(raiz->itIz))
		{
			return 1; 
		}
		
		else if (c.Comparar (raiz->itMe))
		{
			return 2; 
		}
		
		else if (c.Comparar (raiz->itDe))
		{
			return 3; 
		}
		
		else
		{
			return 4;
		}
	}
	else
	{
		return 0;
	}
}

TElemColaA234Com::TElemColaA234Com (): arbol(NULL), sig(NULL)
{
}

TElemColaA234Com::TElemColaA234Com (const TElemColaA234Com &c): sig(NULL)
{
	arbol = c.arbol;
}

TElemColaA234Com::~TElemColaA234Com ()
{
	arbol = NULL;
	
	sig = NULL;	
}

TElemColaA234Com&
TElemColaA234Com::operator= (const TElemColaA234Com &c)
{
	if (this != &c)
	{
		arbol = NULL;
		
		sig = NULL;
		
		arbol = c.arbol;	
	}
	
	return (*this);
}

TA234Com *
TElemColaA234Com::Arbol ()
{
	return (arbol);
}

TColaA234Com::TColaA234Com (): primero(NULL), ultimo(NULL)
{
}

TColaA234Com::TColaA234Com (const TColaA234Com &c): primero(NULL), ultimo(NULL)
{
	if (c.primero != NULL)
	{
		TElemColaA234Com *aux = c.primero;
		
		primero = new TElemColaA234Com (*c.primero);
		
		ultimo = primero;
		
		aux = aux -> sig;
		
		while (aux != NULL)
		{
			ultimo -> sig = new TElemColaA234Com (*aux);
			
			ultimo = ultimo -> sig;
			
			aux = aux -> sig;
		}
	}
}

TColaA234Com::~TColaA234Com ()
{
	TElemColaA234Com *aux;
	
	aux = primero;
	
	while (aux != NULL)
	{
		primero = aux -> sig;
		
		delete aux;
		
		aux = primero;
	}
	
	ultimo = NULL;
}

TColaA234Com&
TColaA234Com::operator= (const TColaA234Com &c)
{
	if (this != &c)
	{
		TElemColaA234Com *aux;
		
		aux = primero;
		
		while (aux != NULL)
		{
			primero = aux -> sig;
			
			delete aux;
			
			aux = primero;
		}
		
		ultimo = NULL;

		if (c.primero != NULL)
		{
			TElemColaA234Com *aux = c.primero;
			
			primero = new TElemColaA234Com (*c.primero);
			
			ultimo = primero;
			
			aux = aux -> sig;
			
			while (aux != NULL)
			{
				ultimo -> sig = new TElemColaA234Com (*aux);
				
				ultimo = ultimo -> sig;
				
				aux = aux -> sig;
			}
		}	
	}
	
	return (*this);
}

bool
TColaA234Com::Encolar (TA234Com *a)
{
	if (ultimo == NULL)
	{
		ultimo = new TElemColaA234Com;
	
		primero = ultimo;
	
		ultimo -> arbol = a;
	
		return (true);
	}
	
	else
	{
		ultimo -> sig = new TElemColaA234Com;
		
		if (ultimo -> sig != NULL)
		{
			ultimo = ultimo -> sig;
			
			ultimo -> arbol = a;
			
			return (true);
		}
		
		else 	
		{
			return (false);
		}
	}
}

bool
TColaA234Com::Desencolar ()
{
	TElemColaA234Com *aux;
	
	aux = primero;
	
	if (aux != NULL)
	{
		if (primero == ultimo)
		{
			delete aux;
			
			primero = ultimo = NULL;
			
			return (true);
		}
		
		else
		{		
			primero = primero -> sig;
			
			delete aux;
			
			return (true);
		}
	}
	
	else 	
	{
		return (false);
	}
}

TA234Com *
TColaA234Com::Cabeza ()
{
	TA234Com *aux = NULL;
	
	if (primero != NULL)
	{
		aux = primero -> arbol;
	}
	
	return (aux);
}

bool
TColaA234Com::EsVacia ()
{
	return (primero == NULL);
}

