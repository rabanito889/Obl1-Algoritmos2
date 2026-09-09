#ifndef AVL_H
#define AVL_H

template <class T>
class AVL
{
private:
	class Nodo
	{
	public:
		T dato;
		int altura;
		Nodo* izq;
		Nodo* der;

		Nodo(T elem);
	};

	Nodo* raiz;

	int altura(Nodo* t);
	void actualizarAltura(Nodo* t);
	int calcBalance(Nodo* t);
	Nodo* rotacionIzq(Nodo* A, Nodo* B);
	Nodo* rotacionDer(Nodo* A, Nodo* B);
	Nodo* insertar(Nodo* t, T elem);
	bool buscar(Nodo* t, T elem);

public:
	AVL();
	void insertar(T elem);
	bool buscar(T elem);
    void rango(T desde, T hasta);
};

#endif
