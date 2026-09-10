#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <algorithm>

using namespace std;
template <class T>
class AVL{
    private:
        class Nodo{
            public:
                T dato;
                int altura;
                Nodo *izq;
                Nodo *der;
                Nodo(T elem): dato(elem),altura(1), izq(NULL), der(NULL){}
        };
        Nodo * raiz;
        int altura(Nodo * t){
            if(!t) return 0;
            return t->altura;
        }
        void actualizarAltura(Nodo * t){
            t->altura = 1 + max(altura(t->izq), altura(t->der));
        }
        int calcBalance(Nodo* t){
            return altura(t->der) - altura(t->izq);
        }
        Nodo* rotacionIzq(Nodo* A, Nodo* B){
            A->der = B->izq;
            B->izq =A;
            actualizarAltura(A);
            actualizarAltura(B);
            return B;
        }
        Nodo* rotacionDer(Nodo* A, Nodo* B){
            A->izq = B->der;
            B->der =A;
            actualizarAltura(A);
            actualizarAltura(B);
            return B;
        }

        Nodo* insertar(Nodo* t, T elem){
            if(!t){
                return new Nodo(elem);
            }
            if(t->dato == elem){
                return t;
            }
            else if(t->dato > elem){
                t->izq = insertar(t->izq, elem);
            }
            else{
                t->der = insertar(t->der,elem);
            }
            actualizarAltura(t);
            int balance = calcBalance(t);
            if(balance >1 && t->der &&t->der->dato < elem){
                return rotacionIzq(t,t->der);
            }
            if(balance >1 && t->der &&t->der->dato > elem){
                t->der = rotacionDer(t->der, t->der->izq);
                return rotacionIzq(t,t->der);
            }
            if(balance < -1 && t->izq &&t->izq->dato > elem){
                return rotacionDer(t,t->izq);
            }
            if(balance < -1 && t->izq &&t->izq->dato < elem){
                t->izq = rotacionIzq(t->izq, t->izq->der);
                return rotacionDer(t,t->izq);
            }
            return t;
        }

        bool buscar(Nodo*t, T elem){
            if(!t){
                return false;
            }
            if(t->dato == elem){
                return true;
            }
            else if(t->dato > elem){
                return buscar(t->izq, elem);
            }
            else{
                return buscar(t->der, elem);
            }   
        }
        void rango(Nodo* t, T desde, T hasta){
            if(!t) return;
            if(t->dato > desde){
                rango(t->izq, desde, hasta);
            }
            if(t->dato >= desde && t->dato <= hasta){
                cout << t->dato << "\n";
            }
            if(t->dato < hasta){
                rango(t->der, desde, hasta);
            } 
        }



    public:
        AVL(): raiz(NULL) {}
        void insertar(T elem){
            this->raiz = insertar(this->raiz, elem);
        }
        bool buscar(T elem){
            return buscar(this->raiz, elem);
        }
        void rango(T desde, T hasta){
            rango(this->raiz,desde, hasta);
        }

};

#endif