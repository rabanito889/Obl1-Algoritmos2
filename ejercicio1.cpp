#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.h"

using namespace std;

int main()
{
    AVL<int> monedas;
    AVL<string> pinturas;
    int N;
    cin >> N;
    while(N--){
        string operacion;
        string coleccion;
        cin >> operacion >> coleccion;
        if(operacion == "ALTA"){
            if(coleccion == "M"){
                int x;
                cin >> x;
                monedas.insertar(x);
            } else{
                string t;
                cin >> t;
                pinturas.insertar(t);
            }
        }
        else if(operacion =="BUSCAR"){
            if(coleccion =="M"){
                int c;
                cin >> c;
                if(monedas.buscar(c)){
                    cout << "si" << endl;
                }
                else{
                    cout << "no" << endl;
                }
            }
            else{
                string t;
                cin >> t;
                if(pinturas.buscar(t)){
                    cout << "si" << endl;
                }
                else{
                    cout << "no" << endl;
                }
            }
        }
        else if (operacion == "RANGO"){
            if(coleccion == "M"){
                int desde;
                int hasta;
                cin >> desde >> hasta;
                monedas.rango(desde,hasta);
            }
            else{
                string desde;
                string hasta;
                cin >> desde >> hasta;
                pinturas.rango(desde, hasta);
            }
        }
    }
    
    
    return 0;
}