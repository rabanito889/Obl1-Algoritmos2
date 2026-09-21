#include <iostream>
#include <algorithm>
using namespace std;
class MinHeap{
    private:
    int* datos;
    int cantidad;
    int capacidad;
    int costo;
    public:
    MinHeap(int capacidad){
        this->datos = new int[capacidad];
        this->cantidad = 0;
        this->capacidad = capacidad;
        this->costo = 0;
    }
    ~MinHeap(){
        delete[] datos;
    }

    int padre(int num){
        return (num-1)/2;
    }
    int hijoIzq(int num){
        return num*2 + 1;
    }
    int hijoDer(int num){
        return num*2 + 2;
    }
    bool esVacio(){
        return cantidad == 0;
    }
    void sumarCosto(int num){
        this->costo += num;
    }

    void salida(){
        cout << this->costo << endl;
    }
    
    void flotar(int num){
        while(datos[num] < datos[padre(num)] && num >0){
            int aux = datos[num];
            datos[num] = datos[padre(num)];
            datos[padre(num)] = aux;
            num = padre(num);  
        }
    }

    void hundir(int num){   //tuve que ver el repositorio de la clase de Heap porque no me acordaba esta funcion :(
        while(hijoIzq(num) < cantidad){
            int menorH = hijoIzq(num);
            if(datos[hijoDer(num)] < datos[hijoIzq(num)] && hijoDer(num) < cantidad  ){
                menorH = hijoDer(num);
            }
            if(datos[num] <= datos[menorH]){
                return;
            }

            int aux = datos[num];
            datos[num] = datos[menorH];
            datos[menorH] = aux;
            num = menorH;
        }
    }

    void insertar(int num){
        if(cantidad == capacidad){
            return;
        }
        datos[cantidad] = num;
        flotar(cantidad);
        cantidad++;
    }

    int eliminarYDevolver(){
        if(cantidad == 0){
            cout << "Heap vacio" << endl;
            return -1;
        }
        int min = datos[0];
        datos[0] = datos[cantidad-1];
        cantidad --;
        if(cantidad >0){
            hundir(0);
        }
        return min;

    }

    int tamano(){
        return cantidad;
    }
    
};