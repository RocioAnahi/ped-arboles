# include <iostream>

using namespace std;

# include "ta234com.h"

TA234Nodo::TA234Nodo (): tipo_nodo(0)
{
}

TA234Nodo::TA234Nodo (const TA234Nodo &n): tipo_nodo(n.tipo_nodo), itIz(n.itIz), itMe(n.itMe), itDe(n.itDe), hijoIz(n.hijoIz), hijoMeIz(n.hijoMeIz), hijoMeDe(n.hijoMeDe), hijoDe(n.hijoDe)
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

void
TA234Nodo::DivideHijoDe2 (TA234Nodo* p)
{
	TComplejo aux, aux2;
	
	if (p == hijoIz.raiz)
	{
		itMe = itIz;

		hijoMeDe.raiz = hijoMeIz.raiz;

		tipo_nodo++;

		itIz = hijoIz.raiz -> itMe;

		hijoMeIz.raiz = new TA234Nodo;

		hijoMeIz.raiz -> tipo_nodo = 1;

		hijoMeIz.raiz -> itIz = hijoIz.raiz -> itDe;

		hijoMeIz.raiz ->hijoIz.raiz = hijoIz.raiz->hijoMeDe.raiz;

		hijoMeIz.raiz ->hijoMeIz.raiz = hijoIz.raiz->hijoDe.raiz;

		hijoIz.raiz->hijoDe.raiz = NULL;

		hijoIz.raiz->hijoMeDe.raiz = NULL;

		hijoIz.raiz -> tipo_nodo = 1;
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

bool
TA234Nodo::InsertarAux (TComplejo &c)
{
	bool salida = false;
	
	if (tipo_nodo == 1)
	{
		if (c != itIz)
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
			
			tipo_nodo++;
			
			salida = true;
		}
	}
	
	else if (tipo_nodo == 2)
	{
		if (c != itIz && c != itMe)
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
			
			salida = true;
			
			tipo_nodo++;
		}
	}
	
	return (salida);
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

void
TA234Nodo::BorrarAux (TComplejo &c)
{
	if (tipo_nodo == 1)
	{
		tipo_nodo = 0;
	}
	
	else if (tipo_nodo == 2)
	{
		if (itIz == c)
		{
			itIz = itMe;

			tipo_nodo = 1;
		}
		
		else
		{
			tipo_nodo = 1;
		}
	}
	
	else
	{
		if (itIz == c)
		{
			itIz = itMe;

			itMe = itDe;

			tipo_nodo = 2;
		}
		
		else if (itMe == c)
		{
			itMe = itDe;

			tipo_nodo = 2;
		}
		
		else
		{
			tipo_nodo = 2;
		}
	}
}

void
TA234Nodo::Sustituir (TA234Nodo *hijo, TA234Nodo *hermano, TComplejo& c)
{
	TComplejo *complejo = NULL;

	TComplejo *sustituir = NULL;

	TComplejo aux;
	
	if (tipo_nodo == 1)
	{
		sustituir = hijoIz.Mayor ();
			
		complejo = &itIz;	
	}
	
	else if (tipo_nodo == 2)
	{
		if (itIz == c)
		{
			sustituir = hijoIz.Mayor ();
			
			complejo = &itIz;
		}
		
		else
		{
			sustituir = hijoMeIz.Mayor ();
			
			complejo = &itMe;
		}
	}
	
	else
	{
		if (itIz == c)
		{
			sustituir = hijoIz.Mayor ();
			
			complejo = &itIz;
		}
		
		else if (itMe == c)
		{
			sustituir = hijoMeIz.Mayor ();
				
			complejo = &itMe;
		}
		
		else
		{
			sustituir = hijoMeDe.Mayor ();
				
			complejo = &itDe;
		}
	}
	
	aux = *complejo;

	*complejo = *sustituir;

	*sustituir = aux;
}

void
TA234Nodo::Ceder (TA234Nodo *hijo, TA234Nodo *hermano, int comparar)
{
	cout << "entro en ceder" << endl;
	
	switch (comparar)
	{
		case 1:
			
			hijoIz.raiz -> itMe = itIz;

			itIz = hijoMeIz.raiz -> itIz;

			hijoIz.raiz -> hijoMeDe.raiz = hijoMeIz.raiz -> hijoIz.raiz;

			hijoIz.raiz -> tipo_nodo++;

			hijoMeIz.raiz -> tipo_nodo--;

			hijoMeIz.raiz -> hijoIz.raiz = hijoMeIz.raiz -> hijoMeIz.raiz;

			hijoMeIz.raiz -> hijoMeIz.raiz = hijoMeIz.raiz -> hijoMeDe.raiz;

			hijoMeIz.raiz -> hijoMeDe.raiz = hijoMeIz.raiz -> hijoDe.raiz;

			hijoMeIz.raiz -> itIz = hijoMeIz.raiz -> itMe;

			hijoMeIz.raiz -> itMe = hijoMeIz.raiz -> itDe;
			
			hijoMeIz.raiz -> hijoDe.raiz=NULL;
			
		break;

		case 2:
			
			hijoMeIz.raiz -> itMe = hijoMeIz.raiz -> itIz;

			hijoMeIz.raiz -> hijoMeDe.raiz = hijoMeIz.raiz -> hijoMeIz.raiz;

			hijoMeIz.raiz -> hijoMeIz.raiz = hijoMeIz.raiz -> hijoIz.raiz;

			hijoMeIz.raiz -> itIz = itIz;

			hijoMeIz.raiz -> tipo_nodo++;

			if (hermano -> tipo_nodo == 2)
			{
				hijoMeIz.raiz -> hijoIz.raiz = hijoIz.raiz -> hijoMeDe.raiz;

				itIz = hijoIz.raiz -> itMe;

				hijoIz.raiz -> tipo_nodo--;
				
				hijoIz.raiz->hijoMeDe.raiz=NULL;
			}

			else
			{
				hijoMeIz.raiz -> hijoIz.raiz = hijoIz.raiz -> hijoDe.raiz;

				itIz = hijoIz.raiz -> itDe;

				hijoIz.raiz -> tipo_nodo--;
				
				hijoIz.raiz->hijoDe.raiz=NULL;
			}
		
		break;

		case 3:

			hijoMeDe.raiz -> itMe = hijoMeDe.raiz -> itIz;

			hijoMeDe.raiz -> hijoMeDe.raiz = hijoMeDe.raiz -> hijoMeIz.raiz;

			hijoMeDe.raiz -> hijoMeIz.raiz = hijoMeDe.raiz -> hijoIz.raiz;

			hijoMeDe.raiz -> itIz = itMe;

			hijoMeDe.raiz -> tipo_nodo++;

			if (hermano -> tipo_nodo == 2)
			{
				hijoMeDe.raiz -> hijoIz.raiz = hijoMeIz.raiz -> hijoMeDe.raiz;

				itMe = hijoMeIz.raiz -> itMe;

				hijoMeIz.raiz -> tipo_nodo--;
				
				hijoMeIz.raiz->hijoMeDe.raiz=NULL;
			}
			
			else
			{
				hijoMeDe.raiz -> hijoIz.raiz = hijoMeIz.raiz -> hijoDe.raiz;

				itMe = hijoMeIz.raiz -> itDe;

				hijoMeIz.raiz -> tipo_nodo--;
				
				hijoMeIz.raiz->hijoDe.raiz=NULL;
			}
			
		break;

		case 4:

			hijoDe.raiz -> itMe = hijoDe.raiz -> itIz;

			hijoDe.raiz -> hijoMeDe.raiz = hijoDe.raiz -> hijoMeIz.raiz;

			hijoDe.raiz -> hijoMeIz.raiz = hijoDe.raiz -> hijoIz.raiz;

			hijoDe.raiz -> itIz = itDe;

			hijoDe.raiz -> tipo_nodo++;

			if (hermano -> tipo_nodo == 2)
			{
				hijoDe.raiz -> hijoIz.raiz = hijoMeDe.raiz -> hijoMeDe.raiz;

				itDe = hijoMeDe.raiz -> itMe;

				hijoMeDe.raiz -> tipo_nodo--;
				
				hijoMeDe.raiz->hijoMeDe.raiz=NULL;
			}

			else
			{
				hijoDe.raiz -> hijoIz.raiz = hijoMeDe.raiz -> hijoDe.raiz;

				itDe = hijoMeDe.raiz -> itDe;

				hijoMeDe.raiz -> tipo_nodo--;
				
				hijoMeDe.raiz->hijoDe.raiz=NULL;
			}
			
		break;
	}
}

void
TA234Nodo::Combinar (TA234Nodo *&hijo, TA234Nodo *&hermano, int comparar)
{
	cout << "entro en combinar" << endl;
	
	switch (comparar)
	{
		case 1:

			hijoIz.raiz -> itMe = itIz;

			hijoIz.raiz -> itDe = hijoMeIz.raiz -> itIz;

			hijoIz.raiz -> hijoMeDe.raiz = hijoMeIz.raiz -> hijoIz.raiz;

			hijoIz.raiz -> hijoDe.raiz = hijoMeIz.raiz -> hijoMeIz.raiz;
			
			hijoMeIz.raiz -> hijoIz.raiz = NULL;

			hijoMeIz.raiz -> hijoMeIz.raiz = NULL;
			
			hijoIz.raiz -> tipo_nodo = 3;
			
			itIz = itMe;

			itMe = itDe;
			
			if (hijoMeIz.raiz!=NULL)
				delete (hijoMeIz.raiz);
			
			hijoMeIz.raiz = hijoMeDe.raiz;

			hijoMeDe.raiz = hijoDe.raiz;

			hijoDe.raiz = NULL;

			tipo_nodo--;

			hijo = hijoIz.raiz;

			hermano = hijoMeIz.raiz;
			
		break;

		case 2:
			
			hijoIz.raiz -> itMe = itIz;

			hijoIz.raiz -> itDe = hijoMeIz.raiz -> itIz;

			hijoIz.raiz -> hijoMeDe.raiz = hijoMeIz.raiz -> hijoIz.raiz;

			hijoIz.raiz -> hijoDe.raiz = hijoMeIz.raiz -> hijoMeIz.raiz;
			
			hijoMeIz.raiz -> hijoIz.raiz = NULL;

			hijoMeIz.raiz -> hijoMeIz.raiz = NULL;
			
			hijoIz.raiz -> tipo_nodo = 3;
			
			itIz = itMe;

			itMe = itDe;
			
			if (hijoMeIz.raiz!=NULL)
				delete (hijoMeIz.raiz);
			
			hijoMeIz.raiz = hijoMeDe.raiz;

			hijoMeDe.raiz = hijoDe.raiz;

			hijoDe.raiz = NULL;

			tipo_nodo--;

			hijo = hijoIz.raiz;

			hermano = hijoMeIz.raiz;
			
		break;

		case 3:
			
			hijoMeIz.raiz -> itMe = itMe;

			hijoMeIz.raiz -> itDe = hijoMeDe.raiz -> itIz;

			hijoMeIz.raiz -> hijoMeDe.raiz = hijoMeDe.raiz -> hijoIz.raiz;

			hijoMeIz.raiz -> hijoDe.raiz = hijoMeDe.raiz -> hijoMeIz.raiz;
			
			hijoMeDe.raiz -> hijoIz.raiz = NULL;

			hijoMeDe.raiz -> hijoMeIz.raiz = NULL;
			
			hijoMeIz.raiz -> tipo_nodo = 3;
			
			itMe = itDe;
			
			if (hijoMeDe.raiz!=NULL)
				delete (hijoMeDe.raiz);
			
			hijoMeDe.raiz = hijoDe.raiz;

			hijoDe.raiz = NULL;

			hijo = hijoMeIz.raiz;

			hermano = hijoIz.raiz;
			
			tipo_nodo--;
			
		break;

		case 4:

			hijoMeDe.raiz -> itMe = itDe;

			hijoMeDe.raiz -> itDe = hijoDe.raiz -> itIz;

			hijoMeDe.raiz -> hijoMeDe.raiz = hijoDe.raiz -> hijoIz.raiz;

			hijoMeDe.raiz -> hijoDe.raiz = hijoDe.raiz -> hijoMeIz.raiz;
			
			hijoMeDe.raiz -> tipo_nodo = 3;
			
			tipo_nodo--;
			
			if (hijoDe.raiz!=NULL)
				delete (hijoDe.raiz);
			
			hijoDe.raiz = NULL;

			hijo = hijoMeDe.raiz;

			hermano = hijoMeIz.raiz;
			
		break;
	}
}

void
TA234Nodo::CombinarEnUno ()
{
	cout << "entro en combinar en uno" << endl;
	
	TA234Nodo *iz = hijoIz.raiz;

	TA234Nodo *de = hijoMeIz.raiz;
	
	itMe = itIz;

	itIz = hijoIz.raiz -> itIz;

	itDe = hijoMeIz.raiz -> itIz;
	
	hijoIz.raiz = iz -> hijoIz.raiz;

	hijoMeIz.raiz = iz -> hijoMeIz.raiz;

	hijoMeDe.raiz = de -> hijoIz.raiz;

	hijoDe.raiz = de -> hijoMeIz.raiz;
	
	iz -> hijoIz.raiz = NULL;

	iz -> hijoMeIz.raiz = NULL;

	de -> hijoIz.raiz = NULL;

	de -> hijoMeIz.raiz = NULL;
	
	tipo_nodo = 3;
	
	if (iz!=NULL)
	{
		cout << "mato a iz" << endl;
		delete (iz);
	}

	if (de!=NULL)
	{
		cout << "mato a de" << endl;
		delete (de);
	}

	iz = NULL;

	de = NULL;
}

TA234Com::TA234Com (): raiz(NULL)
{
}

TA234Com::TA234Com (const TA234Com &a)
{
	raiz = NULL;
	
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
		if (raiz -> tipo_nodo == 1)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
		}
		
		else if (raiz -> tipo_nodo == 2)
		{
			raiz -> hijoIz.InordenAux (l);
			
			l.InsFinal (raiz -> itIz);
			
			raiz -> hijoMeIz.InordenAux (l);
			
			l.InsFinal (raiz -> itMe);
			
			raiz -> hijoMeDe.InordenAux (l);
		}
		
		else if (raiz -> tipo_nodo == 3)
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
			
			if (aux -> raiz -> tipo_nodo == 1)
			{
				salida.InsFinal (aux -> raiz -> itIz);
			}
			
			else if (aux -> raiz -> tipo_nodo == 2)
			{
				salida.InsFinal (aux -> raiz -> itIz);
				
				salida.InsFinal (aux -> raiz -> itMe);
			}
			
			else if (aux -> raiz -> tipo_nodo == 3)
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

		salida = true;
	}
	
	else
	{
		if (q -> tipo_nodo == 3)
		{
			DivideRaiz(q, p);
			
			p = q = raiz;
		}
		
		noencontrado = true;
		
		while (noencontrado)
		{
			if (p -> tipo_nodo == 3)
			{
				if (q -> tipo_nodo == 1)
				{
					q -> DivideHijoDe2 (p);
					
					p=q;
				}
				
				else
				{
					q -> DivideHijoDe3 (p);
					
					p=q;
				}
			}
			
			switch (p -> Comparar (c))
			{
				case 0:
				
					noencontrado = false;
					
					salida = false;
					
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
					
					salida = p -> InsertarAux (c);
					
					noencontrado = false;
					
					break;
			}
		}
	}
	
	return (salida);
}

void
TA234Com::DivideRaiz (TA234Nodo* q, TA234Nodo* p)
{
	TA234Nodo* aux = new TA234Nodo;
	
	TA234Nodo* hijo_aux = new TA234Nodo;
	
	aux -> tipo_nodo = hijo_aux -> tipo_nodo = 1;
	
	aux -> hijoMeIz.raiz = hijo_aux;
	
	hijo_aux -> itIz = q -> itDe;
	
	aux -> itIz = q -> itMe;
	
	hijo_aux -> hijoIz.raiz = q -> hijoMeDe.raiz;
	
	q -> hijoMeDe.raiz = NULL;
	
	hijo_aux -> hijoMeIz.raiz = q -> hijoDe.raiz;
	
	q -> hijoDe.raiz = NULL;
	
	q-> itMe = q -> itDe = 0;
	
	q -> tipo_nodo = 1;
	
	aux -> hijoIz.raiz = q;
	
	this -> raiz = aux;
}

bool
TA234Com::EsHoja () const
{
	if (raiz!=NULL)
	{
		return (raiz -> hijoIz.raiz == NULL && raiz -> hijoMeIz.raiz == NULL && 
		raiz -> hijoMeDe.raiz == NULL && raiz -> hijoDe.raiz == NULL);
	}
	
	else
	{
		return (false);
	}
}

int
TA234Com::Nodos() const
{
	int salida;
	
	if (!EsVacio ())
	{
		salida = 1 + raiz -> hijoIz.Nodos() + raiz -> hijoMeIz.Nodos() + raiz -> hijoMeDe.Nodos() + raiz -> hijoDe.Nodos();
	}
	
	else
	{
		salida = 0;
	}
	
	return (salida);
}

int
TA234Com::NodosHoja () const
{
	int salida = 0;
	
	if (!EsVacio())
	{
		if (EsHoja())
		{
			salida = 1;
		}
		
		else
		{
			salida = raiz -> hijoIz.NodosHoja() + raiz -> hijoMeIz.NodosHoja () + raiz -> hijoMeDe.NodosHoja () + raiz -> hijoDe.NodosHoja ();
		}
	}
	
	return (salida);
}

int
TA234Com::Altura () const
{
	int salida = 0;
	
	if (!EsVacio())
	{
		if (EsHoja())
		{
			salida = 1;
		}
		
		else
		{
			salida = 1 + raiz -> hijoIz.Altura();
		}
	}
		
	return (salida);
}

bool 
TA234Com::Buscar (TComplejo &c) const
{
	bool salida = false;
	
	if (!EsVacio())
	{
		if (raiz -> tipo_nodo == 1)
		{
			if (c == raiz -> itIz)
			{
				salida = true;
			}
			
			else
			{
				if (c.Comparar (raiz -> itIz))
				{
					salida = raiz -> hijoIz.Buscar(c);
				}
				
				else
				{
					salida = raiz -> hijoMeIz.Buscar(c);
				}
			}
		}
		
		else if (raiz -> tipo_nodo == 2)
		{
			if (c == raiz -> itIz || c == raiz -> itMe)
			{
				salida = true;
			}
			
			else
			{
				if (c.Comparar (raiz -> itIz))
				{
					
					salida = raiz -> hijoIz.Buscar (c);
					
				}	
				
				else
				{
					if (c.Comparar (raiz -> itMe))
					{
						salida = raiz -> hijoMeIz.Buscar (c);
					}
					
					else
					{
						salida = raiz -> hijoMeDe.Buscar (c);
					}
				}
			}
		}
		
		else if (raiz -> tipo_nodo == 3)
		{
			if (c == raiz -> itIz || c == raiz -> itMe || c == raiz -> itDe)
			{
				salida = true;
			}
			
			else
			{
				if (c.Comparar (raiz -> itIz))
				{
					salida = raiz -> hijoIz.Buscar (c);
				}
				
				else
				{
					if (c.Comparar (raiz -> itMe))
					{
						salida = raiz -> hijoMeIz.Buscar (c);
					}
					
					else
					{
						if (c.Comparar (raiz -> itDe))
						{
							salida = raiz -> hijoMeDe.Buscar (c);
						}
						
						else
						{
							salida = raiz -> hijoDe.Buscar (c);
						}
					}
				}
			}
		}
	}
	
	return (salida);
}

bool
TA234Com::Borrar (TComplejo &c)
{
	TA234Nodo *padre = NULL;
	
	TA234Nodo *hijo = NULL;

	TA234Nodo *hermano = NULL;

	int comparar;

	bool salida = false;

	bool error = false;

	bool rotar = false; 

	bool combinar = false;

	bool combina3 = false;
	
	bool sustituido = false;
	
	if (!EsVacio())
	{
		padre = hijo = hermano = raiz;
		
		while (!error)
		{	
			if (!rotar)
			{
				switch ((comparar = padre -> Comparar (c)))
				{
					case 0:
						
						if (padre -> itIz == c)
						{
							hijo = padre -> hijoIz.raiz;

							hermano = padre -> hijoMeIz.raiz;

							comparar = 1;
						}
						
						else if (padre -> itMe == c)
						{
							hijo = padre -> hijoMeIz.raiz;

							hermano = padre -> hijoIz.raiz;

							comparar = 2;
						}
						
						else
						{
							hijo = padre -> hijoMeDe.raiz;

							hermano = padre -> hijoMeIz.raiz;

							comparar = 3;
						}
						
						padre -> Sustituir (hijo, hermano, c);

						sustituido = true;

					break; // Añadido después (quitar si deja de funcionar)

					case 1:
						
						hijo = padre -> hijoIz.raiz;

						hermano = padre -> hijoMeIz.raiz;

					break;

					case 2:
						
						hijo = padre -> hijoMeIz.raiz;

						hermano = padre -> hijoIz.raiz;

					break;

					case 3:
						
						hijo = padre -> hijoMeDe.raiz;

						hermano = padre -> hijoMeIz.raiz;

					break;

					case 4:
						
						hijo = padre -> hijoDe.raiz;

						hermano = padre -> hijoMeDe.raiz;

					break;

						//~ hoja
					case 5:

						if (padre -> itIz == c || padre -> itMe == c || padre -> itDe == c)
						{
							padre -> BorrarAux(c);

							salida = true;
						}

						error=true;

					break;
				}
			}
			
			else if (sustituido && combinar)
			{
				hijo = padre -> hijoMeIz.raiz;

				hermano = padre -> hijoIz.raiz;
				
				combinar = false;

				sustituido = false;
			}

			else if (sustituido && combina3)
			{
				combina3 = false;

				sustituido = false;

				padre = hijo;

				hijo = padre -> hijoMeIz.raiz;

				hermano = padre -> hijoIz.raiz;

			}
			
			rotar = false;
			
			if (comparar != 5 && !salida)
			{
				if (hijo -> tipo_nodo == 1)
				{
					if (hermano -> tipo_nodo == 1 && padre -> tipo_nodo == 1)
					{
						padre -> CombinarEnUno ();

						hijo = padre;

						hermano = padre;

						combinar = true;
					}
					
					else if (hermano -> tipo_nodo == 1)
					{
						padre -> Combinar (hijo, hermano, comparar);

						combina3 = true;
					}
					
					else
					{
						padre -> Ceder (hijo, hermano, comparar);
					}
						
					rotar = true;
				}
			}
					
			if (!rotar)
			{
				padre = hijo;

				hermano = hijo;
			}
		}
	}
	
	return (salida);
}

TComplejo*
TA234Com::Mayor ()
{
	TComplejo* aux[]={&raiz -> itIz, &raiz -> itMe, &raiz -> itDe};

	TA234Com* hijos[]={&raiz -> hijoIz, &raiz -> hijoMeIz, &raiz -> hijoMeDe, &raiz -> hijoDe};

	TComplejo *mayor = &raiz -> itIz;
	
	for (int i = 1; i < raiz -> tipo_nodo; i++)
	{
		if (!aux[i] -> Comparar (*mayor))
		{
			mayor = aux[i];
		}
	}
	
	for (int i = 0; i < raiz -> tipo_nodo + 1; i++)
	{
		TComplejo *hijo;
		
		if (hijos[i] -> raiz != NULL)
		{
			hijo = hijos[i] -> Mayor();
			
			if (!hijo -> Comparar (*mayor))
			{
				mayor = hijo;
			}
		}
	}
	
	return (mayor);
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
