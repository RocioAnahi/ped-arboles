# include <iostream>

using namespace std;

# include "tavlcom.h"

# include "ta234com.h"

int main ()
{	
	# ifdef _MAIN_

	// Prueba súper exhaustiva al árbol AVL
	
	TAVLCom a;

	if (a.EsVacio ())
	{
		cout << "El árbol está vacío" << endl; 
	}

	else
	{
		cout << "El árbol debería estar vacío" << endl;
	}

	cout << a.Preorden () << endl << a.Postorden () << endl << a.Inorden () << endl << a.Niveles () << endl;

	TComplejo c1(80,80), c2(40,40), c3(140,140), c4(20,20), c5(60,60), c6(120,120), c7(160,160), c8(100,100);
	
	a.Insertar (c1);

	a.Insertar (c2);

	a.Insertar (c3);

	a.Insertar (c4);

	a.Insertar (c5);

	a.Insertar (c6);

	a.Insertar (c7);

	a.Insertar (c8);

	cout << a.Preorden () << endl << a.Postorden () << endl << a.Inorden () << endl << a.Niveles () << endl;

	if (!a.EsVacio ())
	{
		cout << "El árbol NO está vacío" << endl; 
	}

	else
	{
		cout << "El árbol  NO debería estar vacío" << endl;
	}

	TAVLCom b(a);

	TAVLCom c(a);

	if (b == c && b == a && c ==a)
	{
		cout << "Funcionan el ctor de copia y el operador '=='" << endl;
	}

	TComplejo c9 (90, 90), c10 (110,100), c11 (220,220), c12  (10,10), c13 (2,2);

	if (b.Insertar (c9))
	{
		cout << "Se ha insertado el complejo " << c9 << endl;

		if (b.Insertar (c10))
		{
			cout << "Se ha insertado el complejo " << c10 << endl;

			if (b.Insertar (c11))
			{
				cout << "Se ha insertado el complejo " << c11 << endl;

				if (b.Insertar (c12))
				{
					cout << "Se ha insertado el complejo " << c12 << endl;

					if (b.Insertar (c13))
					{
						cout << "Se ha insertado el complejo " << c13 << endl;
					}

					else
					{
						cout << "Interrumpida la inserción debido a un error en " << c13 << endl;
					}
				}

				else
				{
					cout << "Interrumpida la inserción debido a un error en " << c12 << endl;
				}
			}

			else
			{
				cout << "Interrumpida la inserción debido a un error en " << c11 << endl;
			}
		}

		else
		{
			cout << "Interrumpida la inserción debido a un error en " << c10 << endl;
		}
	}

	else
	{
		cout << "Interrumpida la inserción debido a un error en " << c9 << endl;
	}

	if (b != a && b != c && a == c)
	{
		cout << "Funciona el operador '!='" << endl;
	}

	cout << b.Preorden () << endl << b.Postorden () << endl << b.Inorden () << endl << b.Niveles () << endl;

	c = b;

	if (c == b)
	{
		cout << "Funciona el operador asignación (y sin perder memoria)" << endl;
	}

	TComplejo c14 (200,200);

	if (b.Buscar(c7))
	{
		cout << "Busca bien en el árbol" << endl;
	}

	else
	{
		cout << "NO busca bien en el árbol" << endl;
	}

	if (!b.Buscar(c14))
	{
		cout << "Busca bien en el árbol" << endl;
	}

	else
	{
		cout << "NO busca bien en el árbol" << endl;
	}

	if (c.Borrar (c6))
	{
		cout << "Borrado el complejo " << c6 << endl;
	}

	else
	{
		cout << "No se ha borrado el complejo " << c6 << endl;
	}

	if (c.Borrar (c1))
	{
		cout << "Borrado el complejo " << c1 << endl;
	}

	else
	{
		cout << "No se ha borrado el complejo " << c1 << endl;
	}

	if (!c.Borrar (c14))
	{
		cout << "Bien con el complejo " << c14 << endl;
	}

	else
	{
		cout << "Mal con el complejo " << c14 << endl;
	}

	cout << c.Postorden() << endl << c.Preorden() << endl << c.Inorden() << endl << c.Niveles() << endl;

	cout << "El árbol c es de altura " << c.Altura() << endl;

	cout << "El árbol c tiene " << c.Nodos() << " nodos, de los cuales " << c.NodosHoja() << " son hojas" << endl;


	
	# else


	
	TA234Com a;

	TComplejo c1(10,10), c2(20,20), c3(12,12), c4(23,23), c5(21,21), c6(22,22), c7(19,19), c8(7,7), c9(6,6), c10(1,1), c11(3,3), c12(4,4), c13(9,9), c14(14,14), c15;

	if (a.EsVacio ())
	{
		cout << "El árbol está vacío" << endl; 
	}

	else
	{
		cout << "El árbol debería estar vacío" << endl;
	}

	cout << a.Inorden () << endl << a.Niveles () << endl;
	
	if (a.Insertar(c1))
	{
		cout << "Se ha insertado con éxito el complejo " << c1 << endl;
		
		if (a.Insertar(c2))
		{
			cout << "Se ha insertado con éxito el complejo " << c2 << endl;
			
			if (a.Insertar(c3))
			{
				cout << "Se ha insertado con éxito el complejo " << c3 << endl;
				
				if (a.Insertar(c4))
				{
					cout << "Se ha insertado con éxito el complejo " << c4 << endl;
					
					if (a.Insertar(c5))
					{
						cout << "Se ha insertado con éxito el complejo " << c5 << endl;
						
						if (a.Insertar(c6))
						{
							cout << "Se ha insertado con éxito el complejo " << c6 << endl;
							
							if (a.Insertar(c7))
							{
								cout << "Se ha insertado con éxito el complejo " << c7 << endl;
								
								if (a.Insertar(c8))
								{
									cout << "Se ha insertado con éxito el complejo " << c8 << endl;
									
									if (a.Insertar(c9))
									{
										cout << "Se ha insertado con éxito el complejo " << c9 << endl;
										
										if (a.Insertar(c10))
										{
											cout << "Se ha insertado con éxito el complejo " << c10 << endl;
											
											if (a.Insertar(c11))
											{
												cout << "Se ha insertado con éxito el complejo " << c11 << endl;
												
												if (a.Insertar(c12))
												{
													cout << "Se ha insertado con éxito el complejo " << c12 << endl;
													
													if (a.Insertar(c13))
													{
														cout << "Se ha insertado con éxito el complejo " << c13 << endl;
														
														if (a.Insertar(c14))
														{
															cout << "Se ha insertado con éxito el complejo " << c14 << endl;
														}
														
														else
														{
															cout << "No se ha podido insertar el complejo " << c14 << endl;
														}
													}

													else
													{
														cout << "No se ha podido insertar el complejo " << c13 << endl;
													}
												}

												else
												{
													cout << "No se ha podido insertar el complejo " << c12 << endl;
												}
											}

											else
											{
												cout << "No se ha podido insertar el complejo " << c11 << endl;
											}
										}

										else
										{
											cout << "No se ha podido insertar el complejo " << c10 << endl;
										}
									}

									else
									{
										cout << "No se ha podido insertar el complejo " << c9 << endl;
									}
								}

								else
								{
									cout << "No se ha podido insertar el complejo " << c8 << endl;
								}
							}

							else
							{
								cout << "No se ha podido insertar el complejo " << c7 << endl;
							}
						}

						else
						{
							cout << "No se ha podido insertar el complejo " << c6 << endl;
						}
					}

					else
					{
						cout << "No se ha podido insertar el complejo " << c5 << endl;
					}
				}

				else
				{
					cout << "No se ha podido insertar el complejo " << c4 << endl;
				}
			}

			else
			{
				cout << "No se ha podido insertar el complejo " << c3 << endl;
			}
		}

		else
		{
			cout << "No se ha podido insertar el complejo " << c2 << endl;
		}
	}

	else
	{
		cout << "No se ha podido insertar el complejo " << c1 << endl;
	}

	if (!a.EsVacio ())
	{
		cout << "El árbol NO está vacío" << endl; 
	}

	else
	{
		cout << "El árbol NO debería estar vacío" << endl;
	}

	cout << a.Inorden () << endl << a.Niveles () << endl;
	
	if (a.Insertar (c7))
		cout << "mal" << endl;
	
	cout << "para coño" << endl;
	
	/*TComplejo c1 (5,5), c2 (80,80), c3 (73,73), c4 (18,18), c5 (30,30), c6 (74,74), c7 (78,78), 
	c8 (89,89), c9 (99,99), c10 (76,76), c11(75,75), c12(10,10), c14(90,90), c15(7,7), c16(1,1),c17;
	
	TA234Com a;
	
	a.Insertar (c1);
	a.Insertar (c2);
	a.Insertar (c3);
	a.Insertar (c4);
	a.Insertar (c5);
	a.Insertar (c6);
	a.Insertar (c7);
	a.Insertar (c8);
	a.Insertar (c9);
	a.Insertar (c10);
	a.Insertar (c11);
	a.Insertar (c12);
	a.Insertar (c14);
	a.Insertar (c17);
	a.Insertar (c16);
	
	cout << a.Inorden () << endl<< endl;
	
	cout << a.Niveles () << endl<< endl;
	
	cout << a.Nodos() << " nodos" << endl << endl;
	
	cout << a.NodosHoja () << " hojas" << endl << endl;
	
	cout << "altura " << a.Altura() << endl << endl;
	
	if (!a.Buscar (c15))
	{
		cout << "Busca bien" << endl;
	}
	
	else
	{
		cout << "No busca" << endl;
	}*/
	
	# endif
}
