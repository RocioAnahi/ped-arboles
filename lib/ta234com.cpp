# include <iostream>

using namespace std;

# include "ta234com.h"

TA234Nodo::TA234Nodo ()
{
}

TA234Nodo::TA234Nodo (const TA234Nodo &n): tipo_nodo(0), itIz(n.itIz), itMe(n.itMe), itDe(n.itDe), hijoIz(n.hijoIz), hijoMeIz(n.hijoMeIz), hijoMeDe(n.hijoMeDe), hijoDe(n.hijoDe)
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
		if (raiz->tipo_nodo == 1)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
		}
		
		else if (raiz->tipo_nodo == 2)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
			
			l.InsFinal (raiz -> itMe);
			
			raiz -> hijoMeDe.InordenAux (l);
		}
		
		else if (raiz->tipo_nodo == 3)
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
			
			if (aux->raiz->tipo_nodo == 1)
			{
				salida.InsFinal (aux -> raiz -> itIz);
			}
			
			else if (aux->raiz->tipo_nodo == 2)
			{
				salida.InsFinal (aux -> raiz -> itIz);
				
				salida.InsFinal (aux -> raiz -> itMe);
			}
			
			else if (aux->raiz->tipo_nodo == 3)
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
				cola.Encolar (&(aux -> raiz -> hijoMeIz));
			}
			
			if (!aux -> raiz -> hijoMeDe.EsVacio ())	
			{
				cola.Encolar (&(aux -> raiz -> hijoMeDe));
			}

			if (!aux -> raiz -> hijoDe.EsVacio ())	
			{
				cola.Encolar (&aux -> raiz -> hijoDe);
			}
		}
	}
	
	return (salida);
}

//~ bool
//~ TA234Com::Insertar (TComplejo &c)
//~ {
	//~ bool salida=false;
	//~ 
	//~ if (raiz!=NULL)
	//~ {
		//~ if (raiz->tipo_nodo==3)
		//~ {
			//~ DivideRaiz();
		//~ }
		//~ else
		//~ {
			//~ TA234Nodo *aux=raiz;
			//~ TA234Nodo *aux2;
			//~ 
			//~ while (true)
			//~ {
				//~ 
				//~ if (!aux->EsHoja ())
				//~ {
					//~ switch (aux->Comparar (c))
					//~ {
						//~ case 0:
							//~ return false;
						//~ 
						//~ case 1:
							//~ aux2=&aux->hijoIz;	
							//~ if (aux->hijoIz.raiz->tipo_nodo==3)	aux->DivideHijo ();
							//~ aux=aux2;
							//~ 
						//~ case 2:
							//~ aux2=&aux->hijoMeIz;	
							//~ if (aux->hijoMeIz.raiz->tipo_nodo==3)	aux->DivideHijo ();
							//~ aux=aux2;
						//~ case 3:
							//~ aux2=&aux->hijoMeDe;	
							//~ if (aux->hijoMeDe.raiz->tipo_nodo==3)	aux->DivideHijo ();
							//~ aux=aux2;
						//~ case 4:
							//~ if (aux->hijoDe.raiz->tipo_nodo==3)	aux->DivideHijo ();
					//~ }
				//~ }
				//~ else
				//~ {
					//~ return (aux->InsertarAux (c));
				//~ }
			//~ }
		//~ }
	//~ }
	//~ else
	//~ {
		//~ raiz=new TA234Nodo;
		//~ 
		//~ raiz->itIz=c;
		//~ raiz->tipo_nodo=1;
	//~ }
	//~ 
	//~ return (salida);	
//~ }


bool
TA234Com::Insertar (TComplejo &c)
{
	TA234Nodo *p; // hijo
	
	TA234Nodo *q; // padre
	
	bool noencontrado, salida;
	
	p = raiz;
	
	q = p;
	
	if (EsVacio())
	{
		raiz = new TA234Nodo;
		
		raiz -> tipo_nodo = 1;
		
		raiz -> itIz = c;
	}
	
	else
	{
		if (p -> tipo_nodo == 3)
		{
			DivideRaiz(p);
		}
		
		noencontrado = true;
		
		switch (raiz -> Comparar (c))
		{
			case 0:
				
				salida = false;
				
				noencontrado = false;
				
				break;
			
			case 1:
				
				p = raiz -> hijoIz.raiz;
				
				break;
			
			case 2:
				
				p = raiz -> hijoMeIz.raiz;
				
				break;
			
			case 3:
			
				p = raiz -> hijoMeDe.raiz;
				
				break;
			
			case 4:
			
				p = raiz -> hijoDe.raiz;
				
				break;
			
			case 5: // el nodo es una hoja
				
				raiz -> InsertarAux (c);
				
				noencontrado = false;
				
				salida = true;
		}
		
		while (noencontrado)
		{
			if (p -> tipo_nodo == 3)
			{
				if (q -> tipo_nodo == 1)
				{
					q->DivideHijoDe2 (p);
					
					if (!c.Comparar(q->itIz))
					{
						p = q -> hijoMeIz.raiz;
					}
					
					if (!c.Comparar (q -> itMe))
					{
						p = q -> hijoMeDe.raiz;
					}
				}
				
				else
				{
					q->DivideHijoDe3 (p);
					
					if (!c.Comparar(q->itIz))
					{
						p = q -> hijoMeIz.raiz;
					}
					
					if (!c.Comparar(q->itMe))
					{
						p = q -> hijoMeDe.raiz;
					}
					
					if (!c.Comparar(q->itDe))
					{
						p = q -> hijoDe.raiz;
					}
				}
			}
			
			switch (p -> Comparar (c))
			{
				case 0:
				
					noencontrado = false;
					
					salida=false;
					
					break;
					
				case 1:
					
					q = p;
					
					p = p -> hijoIz.raiz;
					
					break;
					
				case 2:
					q = p;
					
					p = p -> hijoMeIz.raiz;
					
					break;
					
				case 3:
					
					q = p;
					
					p = p -> hijoMeDe.raiz;
					
					break;
					
				case 4:
					
					q = p;
					
					p = p -> hijoDe.raiz;
					
					break;
					
				case 5:
					
					p -> InsertarAux (c);
					
					salida = true;
					
					noencontrado = false;
					
					break;
			}
		}
	}
	
	return (salida);
}

void
TA234Nodo::DivideHijoDe2 (TA234Nodo* p)
{
	TComplejo aux, aux2;
	
	if (p == hijoIz.raiz)
	{
		aux = p -> itIz;
		
		aux2 = p -> itDe;
		
		hijoMeDe.raiz = hijoMeIz.raiz;
		
		itMe = itIz;
		
		tipo_nodo++;
		
		itIz = p -> itMe;
		
		hijoMeIz.raiz = new TA234Nodo;
		
		hijoMeIz.raiz -> itIz = aux2;
		
		hijoMeIz.raiz -> hijoIz = p -> hijoMeDe;
		
		hijoMeIz.raiz -> hijoMeIz = p -> hijoDe;
		
		hijoMeIz.raiz -> tipo_nodo = 1;
		
		p -> itMe = p -> itDe = 0;
		
		p -> tipo_nodo = 1;
		
		p -> hijoMeDe.raiz = p -> hijoDe.raiz = NULL;
	}
	
	else if (p == hijoMeIz.raiz)
	{
		aux = p -> itDe;
		
		itMe = p -> itMe;
		
		tipo_nodo++;
		
		hijoMeDe.raiz = new TA234Nodo;
		
		hijoMeDe.raiz -> tipo_nodo = 1;
		
		hijoMeDe.raiz -> itIz = aux;
		
		hijoMeDe.raiz -> hijoIz.raiz = p -> hijoMeDe.raiz;
		
		hijoMeDe.raiz -> hijoMeIz.raiz = p -> hijoDe.raiz;
		
		hijoMeIz.raiz -> hijoMeDe.raiz = NULL;
		
		hijoMeIz.raiz -> hijoDe.raiz = NULL;
		
		hijoMeIz.raiz -> itMe = hijoMeIz.raiz -> itDe = 0;
		
		hijoMeIz.raiz -> tipo_nodo = 1;
	}
}

void
TA234Nodo::DivideHijoDe3 (TA234Nodo* p)
{
	TComplejo aux, aux2;
	
	if (p == hijoIz.raiz)
	{
		aux = p -> itIz;
		
		aux2 = p -> itDe;
		
		hijoDe.raiz = hijoMeDe.raiz;
		
		hijoMeDe.raiz = hijoMeIz.raiz;
		
		itDe = itMe;
		
		itMe = itIz;
		
		itIz = p -> itMe;
		
		tipo_nodo++;
	
		hijoMeIz.raiz = new TA234Nodo;
		
		hijoMeIz.raiz -> itIz = aux2;
		
		hijoMeIz.raiz -> hijoIz.raiz = p -> hijoMeDe.raiz;
		
		hijoMeIz.raiz -> hijoMeIz.raiz = p -> hijoDe.raiz;
		
		hijoMeIz.raiz -> tipo_nodo = 1;
		
		p -> itMe = p -> itDe = 0;
		
		p -> tipo_nodo = 1;
		
		p -> hijoMeDe.raiz = p -> hijoDe.raiz = NULL;
	}
	
	else if (p == hijoMeIz.raiz)
	{
		aux = p -> itIz;
		
		aux2 = p -> itDe;
		
		hijoDe.raiz = hijoMeDe.raiz;
		
		itDe = itMe;
		
		tipo_nodo++;
		
		itMe = hijoMeIz.raiz -> itMe;
		
		hijoMeDe.raiz = new TA234Nodo;
		
		hijoMeDe.raiz -> tipo_nodo = 1;
		
		hijoMeIz.raiz -> tipo_nodo = 1;
		
		hijoMeDe.raiz -> itIz = aux2;
		
		hijoMeDe.raiz -> hijoIz.raiz = p -> hijoMeDe.raiz;
		
		hijoMeDe.raiz -> hijoMeIz.raiz = p -> hijoDe.raiz;
		
		hijoMeIz.raiz -> hijoMeDe.raiz = NULL;
		
		hijoMeIz.raiz -> hijoDe.raiz = NULL;
		
		hijoMeIz.raiz -> itMe = hijoMeIz.raiz -> itDe = 0;
	}
	
	else if (p == hijoMeDe.raiz)
	{
		aux = p -> itIz;
		
		aux2 = p -> itDe;
		
		tipo_nodo++;
		
		itDe = hijoMeDe.raiz -> itMe;
		
		hijoMeDe.raiz -> tipo_nodo = 1;
		
		hijoDe.raiz = new TA234Nodo;
		
		hijoDe.raiz -> tipo_nodo = 1;
		
		hijoDe.raiz -> hijoIz.raiz = hijoMeDe.raiz -> hijoMeDe.raiz;
		
		hijoDe.raiz -> hijoMeIz.raiz = hijoMeDe.raiz -> hijoDe.raiz;
		
		hijoMeDe.raiz -> hijoMeDe.raiz = NULL;
		
		hijoMeDe.raiz -> hijoDe.raiz = NULL;
		
		hijoDe.raiz -> itIz = aux2;
		
		hijoMeDe.raiz -> itMe = hijoMeDe.raiz -> itDe = 0;
	}
}

void
TA234Com::DivideRaiz (TA234Nodo *a)
{	
	raiz = new TA234Nodo;
	
	raiz -> hijoIz.raiz = new TA234Nodo;
	
	raiz -> hijoIz.raiz -> itIz = a -> itIz;
	
	raiz -> hijoMeIz.raiz = new TA234Nodo;
	
	raiz -> hijoMeIz.raiz -> itIz = a -> itDe;
	
	raiz -> itIz = a -> itMe;
	
	raiz -> hijoIz.raiz -> hijoIz = a -> hijoIz;
	
	raiz -> hijoIz.raiz -> hijoMeIz = a -> hijoMeIz;
	
	raiz -> hijoMeIz.raiz -> hijoIz = a -> hijoMeDe;
	
	raiz -> hijoMeIz.raiz -> hijoMeIz = a -> hijoDe;
	
	a -> hijoIz.raiz = NULL;
	
	a -> hijoMeIz.raiz = NULL;
	
	a -> hijoMeDe.raiz = NULL;
	
	a -> hijoDe.raiz = NULL;
	
	delete a;
	
	a = raiz;
	
	raiz -> tipo_nodo = 1;
	
	raiz -> hijoIz.raiz -> tipo_nodo = 1;
	
	raiz -> hijoMeIz.raiz -> tipo_nodo = 1;
}

void
TA234Nodo::InsertarAux (TComplejo &c)
{
	if (tipo_nodo == 1)
	{
		if (c.Comparar (itIz))
		{
			itDe = itMe;
			
			itMe = itIz;
			
			itIz = c;
		}
		
		else
		{
			itDe = itMe;
			
			itMe = c;
		}
	}
	
	else if (tipo_nodo == 2)
	{
		if (c.Comparar (itIz))
		{
			itDe = itMe;
			
			itMe = itIz;
			
			itIz = c;
		}
		
		else if (c.Comparar (itMe))
		{
			itDe = itMe;
			
			itMe = c;
		}
		
		else
		{
			itDe = c;
		}
	}
	
	tipo_nodo++;
}

bool
TA234Com::EsHoja ()
{
	return (raiz -> hijoIz.raiz == NULL && raiz -> hijoMeIz.raiz == NULL && 
	raiz -> hijoMeDe.raiz == NULL && raiz -> hijoDe.raiz == NULL);
}

int
TA234Nodo::Comparar (TComplejo &c)
{
	if (tipo_nodo == 1 && hijoIz.raiz != NULL && hijoMeIz.raiz != NULL)
	{
		if (c == itIz)
		{
			return 0;
		}
		
		else if (c.Comparar(itIz))
		{
			return 1;
		}
		
		else
		{
			return 2; 
		}
	}
	
	else if (tipo_nodo == 2 && hijoIz.raiz != NULL && hijoMeIz.raiz != NULL && hijoMeDe.raiz != NULL)
	{
		if (c == itIz || c == itMe)
		{
			return 0;
		}
		
		else if (c.Comparar(itIz))
		{
			return 1; 
		}
		
		else if (c.Comparar (itMe))
		{
			return 2; 
		}
		
		else
		{
			return 3; 
		}
		
	}
	
	else if (tipo_nodo == 3 && hijoIz.raiz != NULL && hijoMeIz.raiz != NULL && hijoMeDe.raiz != NULL && hijoDe.raiz != NULL)
	{
		if (c == itIz || c == itMe || c == itDe)
		{
			return 0;
		}
		
		else if (c.Comparar(itIz))
		{
			return 1; 
		}
		
		else if (c.Comparar (itMe))
		{
			return 2; 
		}
		
		else if (c.Comparar (itDe))
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
		return 5;
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
