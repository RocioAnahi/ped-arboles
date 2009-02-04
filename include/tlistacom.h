//!	\brief	Autores:

/*!	Alejandro Navarro Fulleda   48627484-X
	Daniel Mora Pastor			74366414-P*/
	
# ifndef __TLISTACOM__

# define __TLISTACOM__

# include <iostream>

using namespace std;

# include "tcomplejo.h"

//!	\brief	Declaración forward de TListaPos
/*!	Declaración forward de TListaPos para poder declarar amistad entre TListaPos y TListaCom*/
class TListaPos;

//!	\brief	Declaración forward de TListaCom
/*!	Declaración forward de TListaCom para poder declarar amistad entre las clases TLista*/
class TListaCom;

//!	\brief	Declaración forward de TColaCom
/*!	Declaración forward de TColaCom para poder declarar amistad entre las clases TLista y TColaCom*/
class TColaCom;

//!	\brief	Declaración forward de TPilaCom
/*!	Declaración forward de TPilaCom para poder declarar amistad entre las clases TLista y TPilaCom*/
class TPilaCom;

class TVectorCom;


//!	\brief	Clase TListaNodo (tlistanodo.h)
/*!	Clase que representa cada uno de los nodos que componen
 * 	una lista. Es clase amiga de TListaPos.*/

class TListaNodo
{
	//!	\brief	Amistad con la clase TListaPos
	/*!	Amistad con la clase TListaPos*/
	friend class TListaPos;
	
	//!	\brief	Amistad con la clase TListaCom
	/*!	Amistad con la clase TListaCom*/
	friend class TListaCom;
	
	//!	\brief	Amistad con la clase TColaCom
	/*!	Amistad con la clase TColaCom*/
	friend class TColaCom;
	
	//!	\brief	Amistad con la clase TPilaCom
	/*!	Amistad con la clase TPilaCom*/
	friend class TPilaCom;
	
	//!	\brief	Amistad con el operador '<<' de la clase TListaCom
	/*!	Amistad con el operador '<<' de la clase TListaCom para que éste
	 * 	pueda acceder a la parte privada de la clase TListaNodo*/
	friend ostream& operator<< (ostream&, const TListaCom&);
	
	//!	\brief	Amistad con el operador '<<' de la clase TPilaCom
	/*!	Amistad con el operador '<<' de la clase TPilaCom para que éste
	 * 	pueda acceder a la parte privada de la clase TListaNodo*/
	friend ostream& operator<< (ostream&, const TPilaCom&);
	
	//!	\brief	Amistad con el operador '<<' de la clase TColaCom
	/*!	Amistad con el operador '<<' de la clase TColaCom para que éste
	 * 	pueda acceder a la parte privada de la clase TListaNodo*/
	friend ostream& operator<< (ostream&, const TColaCom&);
	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TListaNodo*/
		TListaNodo ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TListaNodo*/
		TListaNodo (const TListaNodo &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TListaNodo*/
		~TListaNodo ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TListaNodo*/
		TListaNodo& operator= (const TListaNodo &);
		
	private:
	
		//!	\brief	Número complejo
		/*!	Número complejo de la lista*/
		TComplejo e;
		
		//!	\brief	Puntero al nodo anterior
		/*!	Puntero al nodo anterior de la lista*/
		TListaNodo *anterior;
		
		//!	\brief	Puntero al siguiente nodo
		/*!	Puntero al siguiente nodo de la lista*/
		TListaNodo *siguiente;
};


//!	\brief	Clase TListaPos (tlistapos.h)
/*!	Clase que representa la posición de un elemento
 * 	dentro de la lista de números complejos*/

class TListaPos
{
	//!	\brief	Declaración de amistad con TListaCom
	/*!	Declaración de amistad con TListaCom*/
	friend class TListaCom;
	
	//!	\brief	Declaración de amistad con TColaCom
	/*!	Declaración de amistad con TColaCom*/
	friend class TColaCom;
	
	//!	\brief	Declaración de amistad con TPilaCom
	/*!	Declaración de amistad con TPilaCom*/
	friend class TPilaCom;
	
	//!	\brief	Amistad con el operador '<<' de TListaCom
	/*!	Amistad con el operador '<<' de TListaCom para poder
	 * 	acceder a la parte privada de TListaPos*/
	friend ostream& operator<< (ostream&, const TListaCom&);
	
	//!	\brief	Amistad con el operador '<<' de TPilaCom
	/*!	Amistad con el operador '<<' de TPilaCom para poder
	 * 	acceder a la parte privada de TListaPos*/
	friend ostream& operator<< (ostream&, const TPilaCom&);
	
	//!	\brief	Amistad con el operador '<<' de TColaCom
	/*!	Amistad con el operador '<<' de TColaCom para poder
	 * 	acceder a la parte privada de TListaPos*/
	friend ostream& operator<< (ostream&, const TColaCom&);
	
	public:
	
		//!	\brief Constructor por defecto	
		/*!	Constructor por defecto de la clase TListaPos*/
		TListaPos ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TListaPos*/
		TListaPos (const TListaPos&);
		
		//!	\brief	Destructor
		/*!	Destructor de la case TListaPos*/
		~TListaPos ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TListaPos*/
		TListaPos& operator= (const TListaPos&);
		
		//!	\brief	Sobrecarga del operador '=='
		/*!	Sobrecarga del operador '==' para la clase TListaPos*/
		bool operator== (const TListaPos&) const;
		
		//!	\brief	Sobrecarga del operador '!='
		/*!	Sobrecarga del operador '!=' para la clase TListaPos*/
		bool operator!= (const TListaPos&);
		
		//!	\brief	Método que devuelve la posición anterior
		/*!	Método que devuelve la posición anterior de la que nos
		 * 	encontramos actualmente.*/
		TListaPos Anterior ();
		
		//!	\brief	Método que devuelve la siguiente posición
		/*!	Método que devuelve la siguiente posición de la que nos
		 * 	encontramos actualmente.*/
		TListaPos Siguiente ();
		
		//!	\brief	Método que indica si la lista está vacía
		/*!	Método que indica si la lista está vacía*/
		bool EsVacia () const;
		
	private:
	
		//!	\brief	Puntero a un nodo de la lista
		/*!	Puntero a un nodo de la lista*/
		TListaNodo *pos;
};


//!	\brief	Clase TListaCom (tlistacom.h)
/*!	Clase que representa una lista doblemente enlazada
 * 	de números complejos accesible por una posición*/

class TListaCom
{
	//!	\brief	Declaración de amistad con TColaCom
	/*!	Declaración de amistad con TColaCom*/
	friend class TColaCom;
	
	//!	\brief	Declaración de amistad con TPilaCom
	/*!	Declaración de amistad con TPilaCom*/
	friend class TPilaCom;
	
	//!	\brief	Declaración de amistad con la clase TListaPos
	/*!	Declaración de amistad de la clase TListaPos*/
	friend class TListaPos;
	
	//!	\brief	Sobrecarga del operador '<<'
	/*!	Sobrecarga del operador '<<' para la clase TListaCom*/
	friend ostream& operator<< (ostream&, const TListaCom&);
	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TListaCom*/
		TListaCom ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TListaCom*/
		TListaCom (const TListaCom&);
		
		//!	\brief	Destructor
		/*!	Destructor de la case TListaCom*/
		~TListaCom ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TListaCom*/
		TListaCom& operator= (const TListaCom&);
		
		//!	\brief	Sobrecarga del operador '=='
		/*!	Sobrecarga del operador '==' para la clase TListaCom*/
		bool operator== (const TListaCom&) const;
		
		//!	\brief	Sobrecarga del operador '!='
		/*!	Sobrecarga del operador '!=' para la clase TListaCom*/
		bool operator!= (const TListaCom&) const;
		
		//!	\brief	Sobrecarga del operador '+'
		/*!	Sobrecarga del operador '+' para la clase TListaCom*/
		TListaCom operator+ (const TListaCom&) const;
		
		//!	\brief	Sobrecarga del operador '-'
		/*!	Sobrecarga del operador '-' para la clase TListaCom*/
		TListaCom operator- (const TListaCom&) const;
		
		//!	\brief	Método que indica si la lista está vacía
		/*!	Método que indica si la lista está vacía*/
		bool EsVacia () const;
		
		//!	\brief	Método que inserta un elemento en la lista
		/*!	Método que inserta un nuevo elemento en la lista, colocándolo
		 * 	en la primera posición de la lista.*/
		bool InsCabeza (const TComplejo&);
		
		//!	\brief	Método que inserta un elemento en la lista
		/*!	Método que inserta un nuevo elemento en la lista, colocándolo
		 * 	a la izquierda de la posición que se le pasa por parámetro.*/
		bool InsertarI (const TComplejo&, const TListaPos&);
		
		//!	\brief	Método que inserta un elemento en la lista
		/*!	Método que inserta un nuevo elemento en la lista, colocándolo
		 * 	a la derecha de la posición que se le pasa por parámetro.*/
		bool InsertarD (const TComplejo&, const TListaPos&);
		
		//!	\brief	Método que borra un elemento de la lista
		/*!	Método que borra la primera ocurrencia en la lista del elemento
		 *  que se le pasa por parámetro (si existe en la lista)\n
		 * 		-Entrada: un número complejo\n
		 * 		-Salida: un booleano\n
		 * 			--True: ha sido posible borrar el elemento\n
		 * 			--False: en caso contrario*/
		bool Borrar (const TComplejo&);
		
		//!	\brief	Método que borra elementos de la lista
		/*!	Método que borra de la lista todas las ocurrencias del 
		 * 	elemento que se le pasa por parámetro\n
		 * 		-Entrada: un número complejo\n
		 * 		-Salida: un booleano\n
		 * 			--True: se han podido borrar los elementos\n
		 * 			--False: en caso contrario*/
		bool BorrarTodos (const TComplejo&);
		
		//!	\brief	Método que borra un elemento de la lista
		/*!	Método que borra el elemento correspondiente a la posición
		 * 	que se le pasa por parámetro (si ésta existe en la lista)\n
		 * 		-Entrada: una posición\n
		 * 		-Salida: un booleano\n
		 * 			--True: ha sido posible borrar el elemento\n
		 * 			--False: en caso contrario*/
		bool Borrar (const TListaPos&);
		
		//!	\brief	Método que devuelve un elemento de la lista
		/*!	Método que devuelve el elemento de la lista correspondiente a la posición
		 * 	que se le pasa por parámetro. En caso de que ésta no exista en la lista,
		 * 	el método devuelve el complejo (0 0)*/
		TComplejo Obtener (const TListaPos&) const;
		
		//!	\brief	Método que indica si un elemento está en la lista
		/*!	Método que indica si un elemento está en la lista\n
		 * 		-Entrada: el número complejo a buscar\n
		 * 		-Salida: un booleano\n
		 * 			--True: si el elemento está en la lista\n
		 * 			--False: en caso contrario*/
		bool Buscar (const TComplejo&) const;
		
		//!	\brief	Método que devuelve la longitud de la lista
		/*!	Método que devuelve la longitud de la lista*/
		int Longitud () const;
		
		//!	\brief	Método que indica la primera posición de la lista
		/*!	Método que indica la primera posición de la lista devolviendo
		 * 	un puntero a la misma*/
		TListaPos Primera () const;
		
		//!	\brief	Método que indica la última posición de la lista
		/*!	Método que indica la última posición de la lista devolviendo
		 * 	un puntero a la misma*/
		TListaPos Ultima () const;
		
		//!	\brief Método de examen de Practicas
		/*!	Metodo de examen de practicas 08/09*/
		TListaCom SRListas(const TListaCom&)	const;
		
		//!	\brief Método que inserta al final de una lista
		/*!	Método que inserta al final de una lista*/
		void InsFinal (const TComplejo &);
		
	private:
	
		//!	\brief	Puntero al primer elemento de la lista
		/*!	Puntero al primer elemento de la lista*/
		TListaNodo *primero;
		
		//!	\brief	Puntero al último elemento de la lista
		/*!	Puntero al último elemento de la lista*/
		TListaNodo *ultimo;
};

# endif
