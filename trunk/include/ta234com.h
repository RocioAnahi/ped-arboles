//!	\brief	Autores:

/*!	Alejandro Navarro Fulleda   48627484-X
	Daniel Mora Pastor			74366414-P*/
	
# ifndef _TA234COM_

# define _TA234COM_

# include <iostream>

using namespace std;

# include "tcomplejo.h"

# include "tlistacom.h"

//!	\brief	Declaración forward de la clase TA234Com
/*!	Declaración forward de la clase TA234Com para poder declarar amistad y definir las funciones de TA234Nodo*/
class TA234Com;

//!	\brief	Clase TA234Nodo (ta234com.h)
/*!	Clase que representa cada uno de los nodos que componen un árbol 2-3-4*/
class TA234Nodo
{
	public:
		
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TA234Nodo*/
		TA234Nodo ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TA234Nodo*/
		TA234Nodo (const TA234Nodo &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TA234Nodo*/
		~TA234Nodo ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TA234Nodo*/
		TA234Nodo& operator= (const TA234Nodo &);
	
	private:
		
		int tipo_nodo;
		
		//!	\brief	Menor número complejo del nodo
		/*!	Menor número complejo del nodo*/
		TComplejo itIz;
		
		//!	\brief	Mayor número complejo del nodo
		/*!	Mayor número complejo del nodo*/
		TComplejo itDe;
		
		//!	\brief	Número complejo medio del nodo
		/*!	Número complejo medio del nodo*/
		TComplejo itMe;
		
		//!	\brief	Subárbol izquierdo
		/*!	Subárbol o rama izquierda del árbol*/
		TA234Com hijoIz;
		
		//!	\brief	Subárbol medio izquierdo
		/*!	Subárbol o rama media izquierda del árbol*/
		TA234Com hijoMeIz;
		
		//!	\brief	Subárbol medio derecho
		/*!	Subárbol o rama media derecha del árbol*/
		TA234Com hijoMeDe;
		
		//!	\brief	Subárbol derecho
		/*!	Subárbol o rama derecha del árbol*/
		TA234Com hijoDe;
};

//!	\brief	Clase TA234Com (ta234com.h)
/*!	Clase que representa un árbol 2-3-4 cuyos ítems son números complejos*/
class TA234Com
{
	public:
		
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TA234Com*/
		TA234Com ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TA234Com*/
		TA234Com (const TA234Com &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TA234Com*/
		~TA234Com ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TA234Com*/
		TA234Com& operator= (const TA234Com &);
		
		//!	\brief	Sobrecarga del operador '=='
		/*!	Sobrecarga del operador '==' para la clase TA234Com*/
		bool operator== (const TA234Com &);
		
		//!	\brief	Sobrecarga del operador '!='
		/*!	Sobrecarga del operador '!=' para la clase TA234Com*/
		bool operator!= (const TA234Com &);
		
		//!	\brief	Método que indica si un árbol está vacío
		/*!	Método que indica si un árbol 2-3-4 está vacío*/
		bool EsVacio ()	const;
		
		//!	\brief	Método para insertar nuevos elementos en el árbol
		/*!	Método que inserta un nuevo número complejo en el árbol, si éste no se haya
		 * 	ya en él. También se encarga de realizar las transformaciones necesarias en el camino
		 * 	desde la raíz hasta las hojas.\n
		 * 		-Entrada: el complejo a insertar\n
		 * 		-Salida: un booleano\n
		 * 			--True: ha sido posible realizar la inserción\n
		 * 			--False: en caso contrario*/
		bool Insertar (const TComplejo &);
		
		//!	\brief	Método que indica si un complejo está en el árbol
		/*!	Método que indica si un complejo está en el árbol\n
		 * 		-Entrada: el complejo a buscar\n
		 * 		-Salida: un booleano\n
		 * 			--True: el complejo está en el árbol\n
		 * 			--False: en caso contrario.*/
		bool Buscar (const TComplejo &)	const;
		
		//!	\brief	Método que indica la altura del árbol
		/*!	Método que indica la altura del árbol*/
		int Altura () const;
		
		//!	\brief	Método que indica el número total de nodos del árbol
		/*!	Método que indica el número total de nodos del árbol*/
		int Nodos () const;
		
		//!	\brief	Método que indica el número de hojas del árbol
		/*!	Método que indica el número de hojas del árbol*/
		int NodosHoja () const;
		
		//!	\brief	Método que devuelve el recorrido Niveles del árbol
		/*!	Método que devuelve una lista que representa el recorrido Niveles del árbol*/
		TListaCom Niveles () const;
		
		//!	\brief	Método que devuelve el recorrido Inorden del árbol
		/*!	Método que devuelve una lista que representa el recorrido Inorden del árbol*/
		TListaCom Inorden () const;
		
		//!	\brief	Método que borra un complejo del árbol
		/*!	Método que borra un complejo del árbol si éste se encuentra en él.
		 * 	Se encarga también de realizar las transformaciones necesarias en el camino
		 * 	desde la raíz al nodo buscado\n
		 * 		-Entrada: el complejo a borrar\n
		 * 		-Salida: un booleano\n
		 * 			--True: se ha podido borrar el elemento\n
		 * 			--False: en caso contrario.*/
		bool Borrar (const TComplejo &);
			
	private:
		
		//!	\brief	Puntero a nodo del árbol
		/*!	Puntero a nodo del árbol*/
		TA234Nodo *raiz;
		
		void InordenAux (TListaCom &);
};

//!	\brief	Clase TElemColaA234Com (ta234com.h)
/*!	Clase que representa cada uno de los nodos de una cola de árboles 2-3-4*/
class TElemColaA234Com
{
	//!	\brief	Declaración de amistad con la clase TColaA234Com
	/*!	Declaración de amistad con la clase TColaA234Com*/
	friend class TColaA234Com;
	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TElemColaA234Com*/
		TElemColaA234Com ();

		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TElemColaA234Com*/
		TElemColaA234Com (const TElemColaA234Com &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TElemColaA234Com*/		
		~TElemColaA234Com ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TElemColaA234Com*/		
		TElemColaA234Com& operator= (const TElemColaA234Com &);

		//!	\brief	Método que devuelve un puntero al árbol contenido en el nodo
		/*!	Método que devuelve un puntero al árbol contenido en el nodo*/		
		TA234Com* Arbol ();
		
	private:
	
		//!	\brief	Puntero al árbol que contiene el nodo
		/*!	Puntero al árbol que contiene el nodo*/	
		TA234Com *arbol;
		
		//!	\brief	Puntero al siguiente elemento de la cola
		/*!	Puntero al siguiente elemento de la cola*/		
		TElemColaA234Com *sig;
};


//!	\brief	Clase TColaA234Com (ta234com.h)
/*!	Clase que representa un cola de árboles 2-3-4 para poder realizar su recorrido por niveles*/
class TColaA234Com
{
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TColaA234Com*/	
		TColaA234Com ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TColaA234Com*/		
		TColaA234Com (const TColaA234Com &);

		//!	\brief	Destructor
		/*!	Destructor de la clase TColaA234Com*/	
		~TColaA234Com ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TColaA234Com*/		
		TColaA234Com& operator= (const TColaA234Com &);

		//!	\brief	Método que añade un nuevo elemento a la cola
		/*!	Método que añade un nuevo elemento a la cola, insertándolo al final de la misma\n
		 * 		-Entrada: el árbol a encolar\n
		 * 		-Salida: un booleano\n
		 * 			--True: ha sido posible encolar el árbol\n
		 * 			--False: en caso contrario.*/		
		bool Encolar (TA234Com*);
		
		//!	\brief	Método que elimina el primer elemento de la cola
		/*!	Método que elimina el primer elemento de la cola.*/		
		bool Desencolar ();
		
		//!	\brief	Método que devuelve el primer elemento de la cola
		/*!	Método que devuelve el primer elemento de la cola*/		
		TA234Com* Cabeza ();
		
		//!	\brief	Método que indica si una cola está vacía
		/*!	Método que indica si una cola está vacía*/		
		bool EsVacia ();
		
	private:
		
		//!	\brief	Puntero al primer elemento de la cola
		/*!	Puntero al primer elemento de la cola*/		
		TElemColaA234Com *primero;
		
		//!	\brief	Puntero al último elemento de la cola
		/*!	Puntero al último elemento de la cola*/		
		TElemColaA234Com *ultimo;
};

# endif
