#include <iostream>
#include <algorithm>
using namespace std;
class HashAbierto{
        private:
            class Nodo{
                public:
                string palabra;
                int cantPalabras;
                Nodo* sig;
                Nodo(): palabra(""), cantPalabras(0), sig(NULL){}
            };
            Nodo ** lista;
            int largo;
            int cajonGrande;
            int distintosCajones;
            public:
            HashAbierto(int esperados){
                this->largo = esperados;
                this->cajonGrande = 0;
                this->distintosCajones = 0;
                this->lista = new Nodo*[this->largo];
                for (int i = 0; i < this->largo; i++){
                    this->lista[i] = NULL;
                }
            }
            int hash(string palabra){
                int h = 0;
                for(int i=0;i<palabra.size(); i++){
                    h = h*33 + palabra[i];
                }
                return h;
            }
            int norm(int x){
                if(x<0) x = -x;
                return x % this->largo;
            }
            string ordenarAZ(string palabra){
                sort(palabra.begin(), palabra.end());
                return palabra; //No estoy seguro de que tan "legal" es esto, pero no hay ninguna restriccion
            }
            void registrar(string palabra){
                string clave = ordenarAZ(palabra);
                int h = hash(clave);
                int pos = norm(h);
                Nodo* cur = lista[pos];
                while (cur){
                    if(cur->palabra == clave){
                        cur->cantPalabras++;
                        if(cur->cantPalabras > this->cajonGrande){
                        cajonGrande = cur->cantPalabras;
                        }
                        return;
                    }
                    cur = cur->sig;
                }
                Nodo* nuevo = new Nodo;
                nuevo->cantPalabras = 1;
                nuevo->palabra = clave;
                nuevo->sig = lista[pos];
                lista[pos] = nuevo;
                distintosCajones++;
                if(cajonGrande == 0){
                    cajonGrande =1;
                }
        
            }

            int consultar(string palabra){
                string clave = ordenarAZ(palabra);
                int h = hash(clave);
                int pos = norm(h);
                Nodo* cur = lista[pos];
                int cant = 0;
                bool encontre = false;
                while(cur && !encontre){
                    if(cur->palabra == clave){
                        cant = cur->cantPalabras;
                        encontre = true;
                    }
                    cur = cur->sig;
                }
                return cant;
            }

            void tirarDatos(){
                cout << this->distintosCajones << " " << this->cajonGrande << "\n";
            }
};