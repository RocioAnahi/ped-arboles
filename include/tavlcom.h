//!	\brief	Autores:

/*!	Alejandro Navarro Fulleda   48627484-X
	Daniel Mora Pastor			74366414-P*/
	
# ifndef _TAVLCOM_

# define _TAVLCOM_

# include <iostream>

using namespace std;

# include "tcomplejo.h"

# include "tlistacom.h"

//!	\brief	Declaración forward de la clase TAVLNodo
/*!	Declaración forward de la clase TAVLNodo para poder declarar amistad y definir las funciones de TAVLCom*/
class TAVLNodo;

//!	\brief	Clase TAVLCom (tavlcom.h)
/*!	Clase que representa un árbol AVL cuyos ítems son números complejos*/
class TAVLCom
{	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TAVLCom*/
		TAVLCom ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TAVLCom*/
		TAVLCom (const TAVLCom &);

		//!	\brief	Destructor
		/*!	Destructor de la clase TAVLCom*/
		~TAVLCom ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TAVLCom*/		
		TAVLCom& operator= (const TAVLCom&);

		//!	\brief	Sobrecarga del operador '=='
		/*!	Sobrecarga del operador '==' para la clase TAVLCom*/		
		bool operator== (TAVLCom &);
		
		//!	\brief	Sobrecarga del operador '!='
		/*!	Sobrecarga del operador '!=' para la clase TAVLCom*/	
		bool operator!= (TAVLCom &);
		
		//!	\brief	Método que indica si un árbol está vacío
		/*!	Método que, devolviendo un booleano, indica si el árbol está vacío.*/		
		bool EsVacio ()	const;
		
		//!	\brief	Método que inserta nuevos números complejos en el árbol
		/*!	Método que realiza la inserción de un nuevo número complejo en el árbol
		 * 	si éste no se haya ya en él. Se encarga también de realizar el reequilibrado del
		 * 	árbol en caso de que sea necesario después de la inserción.\n
		 * 		-Entrada: el complejo a insertar\n
		 * 		-Salida: un booleano\n
		 * 			--True: se ha podido realizar la inserción\n
		 * 			--False: en caso contrario*/		
		bool Insertar (TComplejo &);
		
		//!	\brief	Método que busca un complejo en el aŕbol
		/*!	Método que busca un número complejo en el árbol.\n
		 * 		-Entrada: el complejo a buscar en el árbol\n
		 * 		-Salida: un booleano\n
		 * 			--True: el complejo está en el aŕbol\n
		 * 			--False: en caso contrario*/		
		bool Buscar (TComplejo &);
		
		//!	\brief	Método que devuelve la altura del árbol
		/*!	Método que devuelve la altura del aŕbol.*/		
		int Altura () const;
		
		//!	\brief	Método que indica el número de nodos del árbol
		/*!	Método que devuelve el número de nodos del árbol.*/		
		int Nodos () const;
		
		//!	\brief	Método que devuelve el número de hojas del árbol
		/*!	Método que devuelve el número de hojas del árbol*/		
		int NodosHoja () const;
		
		//!	\brief	Método que devuelve el recorrido Inorden del árbol
		/*!	Método que devuelve una lista que representa el recorrido Inorden del árbol*/		
		TListaCom Inorden ();
		
		//!	\brief	Método que devuelve el recorrido Preorden del árbol
		/*!	Método que devuelve una lista que representa el recorrido Preorden del árbol*/	
		TListaCom Preorden ();
		
		//!	\brief	Método que devuelve el recorrido Postorden del árbol
		/*!	Método que devuelve una lista que representa el recorrido Postorden del árbol*/		
		TListaCom Postorden ();
		
		//!	\brief	Método que devuelve el recorrido Niveles del árbol
		/*!	Método que devuelve una lista que representa el recorrido Niveles del árbol*/		
		TListaCom Niveles ();
		
		//!	\brief	Método que borra un complejo del árbol
		/*!	Método que borrar, en el caso de que lo encuentre, un complejo del árbol, 
		 * 	realizando los reequilibrados necesarios.*/		
		bool Borrar (TComplejo &);
		
	private:
	
		//!	\brief	Puntero a nodo del árbol
		/*!	Puntero a nodo del árbol que representa la raíz del mismo*/	
		TAVLNodo *raiz;
		
		//!	\brief	Método que realiza el reequilibrado del árbol
		/*!	Método que realiza el reequilibrado del árbol tanto para la inserción como para el borrado de elementos.*/		
		bool Equilibrar ();
		
		//!	\brief	Método auxiliar del recorrido Inorden
		/*!	Método auxiliar del recorrido Inorden*/		
		void InordenAux (TListaCom &);
		
		//!	\brief	Método auxiliar del recorrido Preorden
		/*!	Método auxiliar del recorrido Preorden*/		
		void PreordenAux (TListaCom &);
		
		//!	\brief	Método auxiliar del recorrido Postorden
		/*!	Método auxiliar del recorrido Postorden*/		
		void PostordenAux (TListaCom &);
		
		//!	\brief	Método que devuelve el mayor ítem por la rama izquierda del árbol
		/*!	Método que devuelve el mayor ítem por la rama izquierda del árbol*/	
		TAVLNodo* Mayor_Iz ();
		
		//!	\brief	Método que devuelve el menor ítem por la rama derecha del árbol
		/*!	Método que devuelve el menor ítem por la rama derecha del árbol*/			
		TAVLNodo* Menor_De ();
		
		//!	\brief	Método que compara dos complejos
		/*!	Método que compara dos complejos del árbol y determina si debemos seguir hacia
		 * 	la rama de la derecha o la rama de la izquierda.\n
		 * 		-Entrada: el complejo a comparar\n
		 * 		-Salida: un booleano\n
		 * 			--True: el complejo es mayor que el de árbol. Vamos a la rama de la derecha\n
		 *			--False: el complejo es menor o igual que el del árbol. Vamos a la rama izquierda.*/		
		bool Comparar (TComplejo &);
};


//!	\brief	Clase TAVLNodo (tavlcom.h)
/*!	Clase que representa cada uno de los nodos que componen un árbol AVL*/
class TAVLNodo
{
	//!	\brief	Declaración de amistad con la clase TAVLCom
	/*!	Declaración de amistad con la clase TAVLCom*/
	friend class TAVLCom;
	
	public:

		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TAVLNodo*/	
		TAVLNodo ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TAVLNodo*/		
		TAVLNodo (const TAVLNodo &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TAVLNodo*/		
		~TAVLNodo ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TAVLNodo*/		
		TAVLNodo& operator= (const TAVLNodo &);
		
	private:
	
		//!	\brief	Número complejo del nodo
		/*!	Número complejo del nodo del árbol*/	
		TComplejo item;
		
		//!	\brief	Subárbol izquierdo
		/*!	Subárbol o rama izquierda*/		
		TAVLCom iz;
		
		//!	\brief	Subárbol derecho
		/*!	Subárbol o rama derecha*/	
		TAVLCom de;
		
		//!	\brief	Factor de equilibrio
		/*!	Factor de equilibrio del nodo (altura_dcha - altura_izqda)*/		
		int fe;
};


//!	\brief	Declaración forward de la clase TColaAVLCom
/*!	Declaración forward de la clase TAVLCom para poder declarar amistad entre TColaAVLCom y TElemColaAVLCom*/
class TColaAVLCom;

//!	\brief	Clase TElemColaAVLCom (tavlcom.h)
/*!	Clase que representa cada uno de los nodos de una cola de árboles AVL*/
class TElemColaAVLCom
{
	//!	\brief	Declaración de amistad con la clase TColaAVLCom
	/*!	Declaración de amistad con la clase TColaAVLCom*/
	friend class TColaAVLCom;
	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TElemColaAVLCom*/
		TElemColaAVLCom ();

		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TElemColaAVLCom*/
		TElemColaAVLCom (const TElemColaAVLCom &);
		
		//!	\brief	Destructor
		/*!	Destructor de la clase TElemColaAVLCom*/		
		~TElemColaAVLCom ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TElemColaAVLCom*/		
		TElemColaAVLCom& operator= (const TElemColaAVLCom &);

		//!	\brief	Método que devuelve un puntero al árbol contenido en el nodo
		/*!	Método que devuelve un puntero al árbol contenido en el nodo*/		
		TAVLCom* Arbol ();
		
	private:
	
		//!	\brief	Puntero al árbol que contiene el nodo
		/*!	Puntero al árbol que contiene el nodo*/	
		TAVLCom *arbol;
		
		//!	\brief	Puntero al siguiente elemento de la cola
		/*!	Puntero al siguiente elemento de la cola*/		
		TElemColaAVLCom *sig;
};


//!	\brief	Clase TColaAVLCom (tavlcom.h)
/*!	Clase que representa un cola de árboles AVL para poder realizar su recorrido por niveles*/
class TColaAVLCom
{
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Constructor por defecto de la clase TColaAVLCom*/	
		TColaAVLCom ();
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TColaAVLCom*/		
		TColaAVLCom (const TColaAVLCom &);

		//!	\brief	Destructor
		/*!	Destructor de la clase TColaAVLCom*/	
		~TColaAVLCom ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TColaAVLCom*/		
		TColaAVLCom& operator= (const TColaAVLCom &);

		//!	\brief	Método que añade un nuevo elemento a la cola
		/*!	Método que añade un nuevo elemento a la cola, insertándolo al final de la misma\n
		 * 		-Entrada: el árbol a encolar\n
		 * 		-Salida: un booleano\n
		 * 			--True: ha sido posible encolar el árbol\n
		 * 			--False: en caso contrario.*/		
		bool Encolar (TAVLCom*);
		
		//!	\brief	Método que elimina el primer elemento de la cola
		/*!	Método que elimina el primer elemento de la cola.*/		
		bool Desencolar ();
		
		//!	\brief	Método que devuelve el primer elemento de la cola
		/*!	Método que devuelve el primer elemento de la cola*/		
		TAVLCom* Cabeza ();
		
		//!	\brief	Método que indica si una cola está vacía
		/*!	Método que indica si una cola está vacía*/		
		bool EsVacia ();
		
	private:
		
		//!	\brief	Puntero al primer elemento de la cola
		/*!	Puntero al primer elemento de la cola*/		
		TElemColaAVLCom *primero;
		
		//!	\brief	Puntero al último elemento de la cola
		/*!	Puntero al último elemento de la cola*/		
		TElemColaAVLCom *ultimo;
};

# endif
