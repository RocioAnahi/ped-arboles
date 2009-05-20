#include <iostream>
#include "ta234com.h"

using namespace std;

int
main(void)
{
  TA234Com a;
  TComplejo c1(1, 1), c2(2, 2), c3(3, 3), c4(4, 4);
  TComplejo c5(5, 5), c6(6, 6), c7(7, 7);

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c4);
  a.Insertar(c5);
  a.Insertar(c6);
  a.Insertar(c7);

  if(a.Buscar(c1))
    cout << "Si" << endl;
  else
    cout << "No" << endl;

  if(a.Buscar(c3))
    cout << "Si" << endl;
  else
    cout << "No" << endl;

  if(a.Buscar(c7))
    cout << "Si" << endl;
  else
    cout << "No" << endl;

  if(a.Buscar(c7 + c7))
    cout << "Si" << endl;
  else
    cout << "No" << endl;

  return 0;
}
