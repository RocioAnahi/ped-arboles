# include <iostream>

# include <math.h>

using namespace std;

# include "tcomplejo.h"

TComplejo::TComplejo ()
{
	re = 0;
	
	im = 0;
}

TComplejo::TComplejo (double re)
{
	this -> re = re;
	
	this -> im = 0;
}

TComplejo::TComplejo (double re, double im)
{
	this -> re = re;
	
	this -> im = im;
}

TComplejo::TComplejo (const TComplejo& complejo)
{
	this -> re = complejo.re;
	
	this -> im = complejo.im;
}

TComplejo::~TComplejo ()
{
	re = 0;
	
	im = 0;	
}

TComplejo&
TComplejo::operator= (const TComplejo &complejo) 
{
	if (this != &complejo)
	{
		(*this).~TComplejo ();
		
		this -> re = complejo.re;
		
		this -> im = complejo.im;
	}
	
	return (*this);
}

TComplejo 
TComplejo::operator+ (const TComplejo &complejo)
{
	TComplejo aux;
	
	aux.re = re + complejo.re;
	
	aux.im = im + complejo.im;
	
	return (aux);
}

TComplejo 
TComplejo::operator- (const TComplejo &complejo)
{
	TComplejo aux;
	
	aux.re = re - complejo.re;
	
	aux.im = im - complejo.im;
	
	return (aux);	
}

TComplejo 
TComplejo::operator* (const TComplejo &complejo)
{
	TComplejo aux;
	
	aux.re = ((*this).re * complejo.re) - ((*this).im * complejo.im);
	
	aux.im = ((*this).re * complejo.im) + ((*this).im * complejo.re);
	
	return (aux);	
}

TComplejo
TComplejo::operator+ (double real)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = (*this) + aux;
	
	return (aux2);
}

TComplejo 
TComplejo::operator- (double real)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = (*this) - aux;
	
	return (aux2);	
}

TComplejo
TComplejo::operator* (double real)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = (*this) * aux;
	
	return (aux2);	
}

TComplejo operator+ (double real, const TComplejo &complejo)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = aux + complejo;
	
	return (aux2);	
}
		
TComplejo operator- (double real, const TComplejo &complejo)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = aux - complejo;
	
	return (aux2);	
}
		
TComplejo operator* (double real, const TComplejo &complejo)
{
	TComplejo aux (real);
	
	TComplejo aux2;
	
	aux2 = aux * complejo;
	
	return (aux2);	
}

bool 
TComplejo::operator== (const TComplejo &complejo)
{
	return (((*this).re == complejo.re) && ((*this).im == complejo.im));
}
		
bool 
TComplejo::operator!= (const TComplejo &complejo)
{
	return !((((*this).re == complejo.re) && ((*this).im == complejo.im)));
}

double 
TComplejo::Re ()
{
	return (re);
}

double 
TComplejo::Im ()
{
	return (im);
}


void 
TComplejo::Re (double real) 
{
	(*this).re = real;
}
		
void 
TComplejo::Im (double imaginario)
{
	(*this).im = imaginario;
}

double 
TComplejo::Arg (void)
{
	double resultado = 0;
	
	resultado = atan2 (im,re);
	
	return (resultado);
}
		
double 
TComplejo::Mod (void)
{
	double resultado = 0;
	
	resultado = sqrt (pow (re,2) + pow (im,2));
	
	return (resultado);	
}

ostream& operator<< (ostream &os, const TComplejo &complejo)
{
	os << "(";
	
	os << complejo.re;
			
	os << " ";
			
	os << complejo.im;
			
	os << ")";
	
	return (os);
}

