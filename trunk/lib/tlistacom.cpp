# include <iostream>

using namespace std;

# include "tlistacom.h"

# include "tcomplejo.h"

TListaNodo::TListaNodo ():e(), anterior(NULL), siguiente(NULL)
{
}

TListaNodo::TListaNodo (const TListaNodo &lis)
{
	this -> e = lis.e;
}

TListaNodo::~TListaNodo ()
{
	anterior = NULL;
	
	siguiente = NULL;
}

TListaNodo& 
TListaNodo::operator= (const TListaNodo &lis)
{
	if (this != &lis)
	{
		if (anterior != NULL)
		{
			delete anterior;
			
			anterior = NULL;
		}
		
		if (siguiente != NULL)
		{
			delete siguiente;

			siguiente = NULL;
		}
		
		e = lis.e;
	}
	
	return (*this);
}


TListaPos::TListaPos (): pos(NULL)
{
}

TListaPos::TListaPos (const TListaPos& lpos)
{
	pos = lpos.pos;
}

TListaPos::~TListaPos ()
{
	if (pos != NULL)
	{
		pos = NULL;
	}
}

TListaPos& 
TListaPos::operator= (const TListaPos& lpos)
{
	if (this != &lpos)
	{
		pos = lpos.pos;
	}
	
	return (*this);
}

bool 
TListaPos::operator== (const TListaPos& lpos) const
{
	return (pos == lpos.pos);
}

bool 
TListaPos::operator!= (const TListaPos& lpos)
{
	return (pos != lpos.pos);
}

TListaPos 
TListaPos::Anterior ()
{
	TListaPos aux;
	
	if (pos != NULL && pos -> anterior != NULL)
	{
		aux.pos = pos -> anterior;
	}
	
	return (aux);
}

TListaPos 
TListaPos::Siguiente ()
{
	TListaPos aux;
	
	aux.pos = NULL;
	
	if (pos != NULL && pos -> siguiente != NULL)
	{
		aux.pos = pos -> siguiente;
	}
	
	return (aux);
}

bool 
TListaPos::EsVacia () const
{
	return (pos == NULL);
}


TListaCom::TListaCom ():primero(NULL), ultimo(NULL)
{
}

TListaCom::TListaCom (const TListaCom& lcom):primero(NULL), ultimo(NULL)
{
	TListaPos aux_this;
	
	TListaPos aux_lcom;
	
	aux_lcom.pos = lcom.primero;
	
	if (lcom.primero != NULL)
	{
		aux_this.pos = new TListaNodo;
		
		aux_this.pos -> e = aux_lcom.pos -> e;
		
		primero = aux_this.pos;
		
		ultimo = aux_this.pos;
		
		do
		{
			if (aux_lcom.Siguiente().pos != NULL)
			{
				aux_lcom = aux_lcom.Siguiente();
				
				aux_this.pos -> siguiente = new TListaNodo;
				
				aux_this.pos -> siguiente -> e = aux_lcom.pos -> e;
				
				aux_this.pos -> siguiente -> anterior = aux_this.pos;
				
				aux_this = aux_this.Siguiente();
			}
		}
		while (aux_lcom.pos != lcom.ultimo);
		
		ultimo = aux_this.pos;
	}
}

TListaCom::~TListaCom ()
{
	TListaPos aux_anterior;
	
	TListaPos aux_siguiente;
	
	aux_anterior.pos=primero;
	
	aux_siguiente.pos=primero;
	
	if (primero != NULL)
	{
		do
		{
			aux_siguiente = aux_siguiente.Siguiente();
			
			delete aux_anterior.pos;
			
			aux_anterior = aux_siguiente;	
		}
		while (aux_siguiente.pos != NULL);
		
		primero = NULL;
		
		ultimo = NULL;
	}
}

TListaCom& 
TListaCom::operator= (const TListaCom& lcom)
{
	if (this != &lcom)
	{
		TListaPos aux_anterior;
		
		TListaPos aux_siguiente;
		
		aux_anterior.pos = primero;
		
		aux_siguiente.pos = primero;
		
		if (primero != NULL)
		{
			do
			{
				aux_siguiente = aux_siguiente.Siguiente();
				
				delete aux_anterior.pos;
				
				aux_anterior = aux_siguiente;		
			}
			while (aux_siguiente.pos != NULL);
			
			primero = NULL;
			
			ultimo = NULL;
		}
		
		TListaPos aux_this;
		
		TListaPos aux_lcom;
		
		aux_lcom.pos = lcom.primero;
		
		if (lcom.primero != NULL)
		{
			aux_this.pos = new TListaNodo;
			
			aux_this.pos -> e = aux_lcom.pos -> e;
			
			primero = aux_this.pos;
			
			ultimo = aux_this.pos;
			
			do
			{
				if (aux_lcom.Siguiente().pos != NULL)
				{
					aux_lcom = aux_lcom.Siguiente();
					
					aux_this.pos -> siguiente = new TListaNodo;
					
					aux_this.pos -> siguiente -> e = aux_lcom.pos -> e;
					
					aux_this.pos -> siguiente -> anterior = aux_this.pos;
					
					aux_this = aux_this.Siguiente();
				}
			}
			while (aux_lcom.pos != lcom.ultimo);
			
			ultimo = aux_this.pos;
		}
	}
	
	return (*this);
}

bool 
TListaCom::operator== (const TListaCom& lcom) const
{
	bool salida = true;
	
	TListaPos aux_this;
	
	TListaPos aux_lcom;
	
	if (Longitud() == lcom.Longitud() && Longitud() > 0 && lcom.Longitud() > 0)
	{
		aux_this.pos = primero;
		
		aux_lcom.pos = lcom.primero;
		
		do
		{
			if (aux_this.pos -> e != aux_lcom.pos -> e)
			{
				salida = false;
			}
			
			else
			{
				aux_this = aux_this.Siguiente();
				
				aux_lcom = aux_lcom.Siguiente();
			}
			
		}
		while (aux_this.pos != ultimo && salida == true);	
	}
	
	else
	{
		salida = false;
	}
	
	return (salida);
}

bool 
TListaCom::operator!= (const TListaCom& lcom) const
{
	return (!(*(this) == lcom));
}

TListaCom 
TListaCom::operator+ (const TListaCom& lcom) const
{
	TListaCom aux_iz (*this);
	
	TListaCom aux_der (lcom);
	
	if (aux_iz.EsVacia())
	{
		aux_iz.primero = aux_der.primero;
	}
	
	else
	{
		aux_iz.ultimo -> siguiente = aux_der.primero;
	}
	
	aux_der.primero -> anterior = aux_iz.ultimo;
	
	aux_iz.ultimo = aux_der.ultimo;
	
	aux_der.primero = NULL;
	
	aux_der.ultimo = NULL;

	return (aux_iz);	
}

TListaCom 
TListaCom::operator- (const TListaCom& lcom) const
{
	TListaCom salida;
	
	TListaPos aux_this;
	
	TListaPos aux_salida;
	
	aux_this.pos = primero;
	
	if (aux_this.pos != NULL)
	{	
			while ((aux_this).pos != NULL)
			{
				if (aux_salida.pos == NULL && lcom.Buscar(aux_this.pos -> e) == false)
				{
					salida.primero = new TListaNodo;
					
					salida.primero -> e = aux_this.pos -> e;
					
					aux_salida.pos = salida.primero;
					
					salida.ultimo = aux_salida.pos;
				}	
				
				else if (aux_salida.pos != NULL && lcom.Buscar(aux_this.pos -> e) == false)
				{
					aux_salida.pos -> siguiente = new TListaNodo;
					
					aux_salida.pos -> siguiente -> e = aux_this.pos -> e;
					
					aux_salida.pos -> siguiente -> anterior = aux_salida.pos;
					
					aux_salida = aux_salida.Siguiente();
					
					salida.ultimo = aux_salida.pos;
				}
				
				aux_this = aux_this.Siguiente();
			}
	}
	
	return (salida);
}

bool 
TListaCom::EsVacia () const
{
	return (primero == NULL);
}

bool 
TListaCom::InsCabeza (const TComplejo& com)
{
	TListaPos aux;
	
	bool salida = false;
	
	aux.pos = primero;
	
	if (primero == NULL)
	{
		primero = new TListaNodo;
		
		if (primero != NULL)
		{
			primero -> e = com;
			
			ultimo = primero;
			
			salida = true;
		}
	}
	
	else
	{
		primero = new TListaNodo;
		
		if (primero != NULL)
		{
			primero -> e = com;
			
			primero -> siguiente = aux.pos;
			
			aux.pos -> anterior = primero;
			
			salida = true;
		}
	}
	
	return (salida);
}

bool 
TListaCom::InsertarI (const TComplejo& com, const TListaPos& lpos)
{
	TComplejo aux;
	
	bool salida = false;
	
	if (Obtener(lpos) != aux)
	{
		if (lpos.pos == primero)
		{
			salida = InsCabeza(com);
		}
		
		else
		{
			lpos.pos -> anterior -> siguiente = NULL;
			
			lpos.pos -> anterior -> siguiente = new TListaNodo;
			
			if (lpos.pos -> anterior -> siguiente != NULL)
			{
				lpos.pos -> anterior -> siguiente -> e = com;
				
				salida = true;
				
				TListaPos aux_ant;
				
				aux_ant.pos = lpos.pos->anterior;
				
				aux_ant.pos -> siguiente -> anterior = aux_ant.pos;
				
				aux_ant.pos -> siguiente -> siguiente = lpos.pos;
				
				lpos.pos -> anterior = aux_ant.pos -> siguiente;
			}
		}
	}
	
	return (salida);
}

bool 
TListaCom::InsertarD (const TComplejo& com, const TListaPos& lpos)
{
	TComplejo aux;
	
	bool salida = false;
	
	if (Obtener (lpos)!=aux)
	{
		if (lpos.pos==ultimo)
		{
			lpos.pos -> siguiente = new TListaNodo;
			
			if (lpos.pos -> siguiente != NULL)
			{
				lpos.pos -> siguiente -> e = com;
				
				salida = true;
				
				ultimo = lpos.pos -> siguiente;
				
				ultimo -> anterior = lpos.pos;
			}
		}
		
		else
		{
			TListaPos aux;
			
			aux.pos = lpos.pos -> siguiente;
			
			lpos.pos -> siguiente = NULL;
			
			lpos.pos -> siguiente = new TListaNodo;
			
			if (lpos.pos -> siguiente != NULL)
			{
				lpos.pos -> siguiente -> e = com;
				
				salida = true;
				
				lpos.pos -> siguiente -> anterior = lpos.pos;
				
				lpos.pos -> siguiente -> siguiente = aux.pos;
				
				aux.pos -> anterior = lpos.pos -> siguiente;
			}
		}
	}
	
	return (salida);
}

bool 
TListaCom::Borrar (const TComplejo& com)
{
	bool salida = false;
	
	TListaPos aux;
	
	aux.pos = primero;
	
	while (aux.pos != NULL && !salida)
	{
		if (aux.pos -> e == com)
		{
			salida = true;
			
			if (aux.pos == primero)
			{
				primero = aux.pos -> siguiente;
				
				aux.pos -> siguiente -> anterior = NULL;
				
				delete aux.pos;
			}
			
			else if (aux.pos == ultimo)
			{
				ultimo = aux.pos -> anterior;
				
				aux.pos -> siguiente = NULL;
				
				delete aux.pos;
			}
			
			else
			{
				aux.pos -> anterior -> siguiente = aux.pos -> siguiente;
				
				aux.pos -> siguiente -> anterior = aux.pos -> anterior;
				
				delete aux.pos;
			}
		}
		
		else
		{
			aux = aux.Siguiente();
		}
	}
	
	return (salida);
}

bool 
TListaCom::BorrarTodos (const TComplejo& com)
{
	bool salida = false;
	
	TListaPos aux;
	
	aux.pos = primero;
	
	while (aux.pos != NULL)
	{
		if (aux.pos -> e == com)
		{
			salida = true;
			
			if (aux.pos == primero)
			{
				primero = aux.pos -> siguiente;
				
				aux.pos -> siguiente -> anterior = NULL;
				
				delete aux.pos;
				
				aux.pos = primero;
			}
			
			else if (aux.pos == ultimo)
			{
				ultimo = aux.pos -> anterior;
				
				aux.pos -> siguiente = NULL;
				
				delete aux.pos;
				
				aux.pos = NULL;
			}
			
			else
			{
				TListaPos pos_sig;
				
				pos_sig.pos = aux.pos -> siguiente;
				
				aux.pos -> anterior -> siguiente = aux.pos -> siguiente;
				
				aux.pos -> siguiente -> anterior = aux.pos -> anterior;
				
				delete aux.pos;
				
				aux = pos_sig;
			}
		}
		
		else
		{
			aux = aux.Siguiente();
		}
	}
	
	return (salida);
}

bool 
TListaCom::Borrar (const TListaPos& lpos)
{
	TComplejo aux;
	
	bool salida = false;
	
	if (Obtener(lpos) != aux)
	{
		salida = true;
		
		if (lpos.pos == primero)
		{
			primero = lpos.pos->siguiente;
			
			if (primero != NULL)
			{
				lpos.pos -> siguiente -> anterior = NULL;
			}
			
			else
			{
				ultimo = NULL;
			}
			
			delete lpos.pos;
		}
		
		else if (lpos.pos == ultimo)
		{
			ultimo = lpos.pos -> anterior;
			
			if (ultimo != NULL)
			{
				ultimo -> siguiente = NULL;
			}
			
			else
			{
				primero = NULL;
			}
			
			delete lpos.pos;
		}
		
		else
		{
			lpos.pos -> anterior -> siguiente = lpos.pos -> siguiente;
			
			lpos.pos -> siguiente -> anterior = lpos.pos -> anterior;
			
			delete lpos.pos;
		}
	}
	
	return (salida);
}

TComplejo 
TListaCom::Obtener (const TListaPos& lpos) const
{
	TListaPos aux;
	
	TComplejo aux_com;
	
	aux.pos = primero;
	
	while (aux.pos != NULL && aux.pos != lpos.pos)
	{
		aux = aux.Siguiente();
	}
	
	if (aux.pos != NULL)
	{
		aux_com = aux.pos -> e;
	}
	
	return (aux_com);
}

bool 
TListaCom::Buscar (const TComplejo& com) const
{
	bool salida = false;
	
	TListaPos aux;
	
	aux.pos = primero;
	
	while (aux.pos != NULL && aux.pos -> e != com)
	{
		aux = aux.Siguiente ();
	}
	
	if (aux.pos != NULL)
	{
		salida = true;
	}
	
	return (salida);
}

int 
TListaCom::Longitud () const
{
	int i = 0;
	
	TListaPos aux;
	
	aux.pos = primero;
	
	while (aux.pos != NULL)
	{
		aux = aux.Siguiente();
		
		i++;
	}
	
	return (i);
}

TListaPos 
TListaCom::Primera () const
{
	TListaPos aux;
	
	aux.pos = primero;
	
	return (aux);
}

TListaPos 
TListaCom::Ultima () const
{
	TListaPos aux;
	
	aux.pos = ultimo;
	
	return (aux);
}

ostream& operator<< (ostream& os, const TListaCom& lcom)
{
	TListaPos aux;
	
	aux = lcom.Primera();
	
	os << '{';
	
	if (!lcom.EsVacia())
	{
		do
		{
			os << lcom.Obtener(aux);
			
			if (aux != lcom.Ultima())
			{
				os << ' ';
			}
			
			aux = aux.Siguiente();
			
		}
		while (aux.pos != NULL);
	}
	
	os << '}';
	
	return (os);
}

TListaCom
TListaCom::SRListas(const TListaCom &l)	const
{
	TListaCom salida;

	TListaPos it1,it2,it3;
	
	it1=this->Primera ();
	it2=l.Primera();

	while (!it1.EsVacia () || !it2.EsVacia())
	{
		if (!it1.EsVacia () && !it2.EsVacia())
		{
			if (l.Obtener (it2).Re()>(this->Obtener (it1).Re()))
			{
				salida.InsFinal (l.Obtener (it2)+this->Obtener (it1));
			}
			else if (l.Obtener (it2).Re()<(this->Obtener (it1).Re()))
			{
				salida.InsFinal (this->Obtener (it1)-l.Obtener (it2));
			}
			else
			{
				if (l.Obtener (it2).Im()>this->Obtener (it1).Im())
				{
					salida.InsFinal (l.Obtener (it2)+this->Obtener (it1));
				}
				else if (l.Obtener (it2).Im()<this->Obtener (it1).Im())
				{
					salida.InsFinal (this->Obtener (it1)-l.Obtener (it2));
				}
				else
				{
					salida.InsFinal (this->Obtener (it1)-l.Obtener (it2));
				}
			}
		}
		else
		{
			if (it1.EsVacia())
			{
				salida.InsFinal (l.Obtener (it2));
			}
			else
			{
				salida.InsFinal (this->Obtener (it1));
			}
		}

		it1=it1.Siguiente();
		it2=it2.Siguiente();
	}
	return salida;

}

void
TListaCom::InsFinal (const TComplejo &c)
{
	if (ultimo==NULL)
	{
		primero=new TListaNodo;
		ultimo=primero;
		primero->e=c;
	}
	else
	{
		ultimo->siguiente=new TListaNodo;
		ultimo->siguiente->e=c;
		ultimo=ultimo->siguiente;
	}
}
