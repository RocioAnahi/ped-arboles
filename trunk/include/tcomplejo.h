//!	\brief	Autores:

/*!	Alejandro Navarro Fulleda   48627484-X
	Daniel Mora Pastor			74366414-P*/

# ifndef __TCOMPLEJO__

# define __TCOMPLEJO__

# include <iostream>

using namespace std;

//!	\brief	Clase TComplejo (tcomplejo.h)
/*!	Clase que representa un número complejo
 * 	mediante su parte real y su parte imaginaria*/
	
class TComplejo
{
	//!	\brief	Sobrecarga del operador '<<'
	/*!	Sobrecarga del operador '<<' para la clase TComplejo*/
	friend ostream& operator<< (ostream &, const TComplejo &);
	
	//!	\brief	Sobrecarga del operador '+'
	/*!	Sobrecarga del operador '+' para la clase TComplejo operando,
	 * 	en este orden, un real con un complejo, sumando su parte
	 * 	real al número real pasado por parámetro, sin operar la parte imaginaria*/
	friend TComplejo operator+ (double, const TComplejo &);
	
	//!	\brief	Sobrecarga del operador '-'
	/*!	Sobrecarga del operador '-' para la clase TComplejo operando,
	 * 	en este orden, un real con un complejo, restando su parte
	 * 	real al número real pasado por parámetro, sin operar la parte imaginaria*/		
	friend TComplejo operator- (double, const TComplejo &);
	
	//!	\brief	Sobrecarga del operador '*'
	/*!	Sobrecarga del operador '*' para la clase TComplejo operando,
	 * 	en este orden, un real con un complejo, multiplicando su parte
	 * 	real con el número real pasado por parámetro, sin operar la parte imaginaria*/	
	friend TComplejo operator* (double, const TComplejo &);
	
	public:
	
		//!	\brief	Constructor por defecto
		/*!	Devuelve el número complejo con parte real e imaginaria 
		 * 	con valor 0*/
		TComplejo ();
		
		//!	\brief	Constructor sobrecargado
		/*!	Devuelve el número complejo con parte real igual al parámetro 
		 * 	y la parte imaginaria con valor 0*/
		TComplejo (double);
		
		//!	\brief	Constructor sobrecargado
		/*!	Devuelve el número complejo con la parte real igual al primer
		 * 	parámetro y la parte imaginaria con valor igual al segundo parámetro*/
		TComplejo (double, double);
		
		//!	\brief	Constructor de copia
		/*!	Constructor de copia de la clase TComplejo*/	
		TComplejo (const TComplejo&);

		//!	\brief	Destructor
		/*!	Destructor de la case TComplejo*/
		~TComplejo ();
		
		//!	\brief	Sobrecarga del operador '='
		/*!	Sobrecarga del operador '=' para la clase TComplejo*/
		TComplejo& operator= (const TComplejo &);
		
		//!	\brief	Sobrecarga del operador '+'
		/*!	Sobrecarga del operador '+' para la clase TComplejo*/
		TComplejo operator+ (const TComplejo &);
		
		//!	\brief	Sobrecarga del operador '-'
		/*!	Sobrecarga del operador '-' para la clase TComplejo*/
		TComplejo operator- (const TComplejo &);
		
		//!	\brief	Sobrecarga del operador '*'
		/*!	Sobrecarga del operador '*' para la clase TComplejo*/
		TComplejo operator* (const TComplejo &);
		
		//!	\brief	Sobrecarga del operador '+'
		/*!	Sobrecarga del operador '+' para la clase TComplejo operando,
		 * 	en este orden, un complejo con un real, sumando éste a la parte
		 * 	real del complejo*/
		TComplejo operator+ (double);
		
		//!	\brief	Sobrecarga del operador '-'
		/*!	Sobrecarga del operador '-' para la clase TComplejo operando,
		 * 	en este orden, un complejo con un real, restando éste a la parte
		 * 	real del complejo*/
		TComplejo operator- (double);
		
		//!	\brief	Sobrecarga del operador '*'
		/*!	Sobrecarga del operador '*' para la clase TComplejo operando,
		 * 	en este orden, un complejo con un real, multiplicando éste con la parte
		 * 	real del complejo*/
		TComplejo operator* (double);
		
		//!	\brief	Sobrecarga del operador '=='
		/*!	Sobrecarga del operador '==' para la clase TComplejo*/
		bool operator== (const TComplejo &);
		
		//!	\brief	Sobrecarga del operador '!='
		/*!	Sobrecarga del operador '!=' para la clase TComplejo*/
		bool operator!= (const TComplejo &);
		
		//!	\brief	Método para obtener el atributo re (parte real)
		/*!	Método para obtener el atributo re (parte real) de la clase TComplejo*/
		double Re ();
		
		//!	\brief	Método para obtener el atributo im (parte imaginaria)
		/*!	Método para obtener el atributo im (parte imaginaria) de la clase TComplejo*/
		double Im ();
		
		//!	\brief	Método para establecer el atributo re (parte real)
		/*!	Método para establecer el atributo re (parte real) de la clase TComplejo*/
		void Re (double);
		
		//!	\brief	Método para establecer el atributo im (parte imaginaria)
		/*!	Método para establecer el atributo im (parte imaginaria) de la clase TComplejo*/
		void Im (double);
		
		//!	\brief	Método que calcula el argumento de un número complejo (en radianes)
		/*!	Método que calcula el argumento de un número complejo (en radianes) mediante
		 * 	el cálculo del arcotangente del cociente entre la parte real y la parte imaginaria\n
		 * 		-Entradas: no hay parámetros de entrada\n
		 * 		-Salida: un número real*/
		double Arg (void);
		
		//!	\brief	Método que calcula el módulo de un número complejo
		/*!	Método que calcula el módulo de un número complejo mediante el cálculo de
		 * 	la raíz cuadrada de la suma de los cuadrados de la parte real y la parte imaginaria\n
		 * 		-Entradas: no hay parámetros de entrada\n
		 * 		-Salida: un número real*/
		double Mod (void)	const;
		
	private:
		//! \brief	Parte real
		/*! Parte real del número complejo*/
		double re;
		
		//! \brief	Parte imaginaria
		/*! Parte imaginaria del número complejo*/
		double im;
};

# endif
