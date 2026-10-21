#include <iostream>
#include <algorithm>
using namespace std;

struct Modulo{
    long long prioridad;
    int id;
};

bool esMenor(Modulo a, Modulo b){
    if(a.prioridad != b.prioridad){
        return a.prioridad < b.prioridad;
    }
    return a.id < b.id;
}

class MinHeap{
    private:
    Modulo* datos;
    int cantidad;
    int capacidad;
    
    public:
    MinHeap(int capacidad){
        this->datos = new Modulo[capacidad];
        this->cantidad = 0;
        this->capacidad = capacidad;
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
    
    
    void flotar(int num){
        while(esMenor(datos[num], datos[padre(num)]) && num >0){
            Modulo aux = datos[num];
            datos[num] = datos[padre(num)];
            datos[padre(num)] = aux;
            num = padre(num);  
        }
    }

    void hundir(int num){   //tuve que ver el repositorio de la clase de Heap porque no me acordaba esta funcion :(
        while(hijoIzq(num) < cantidad){
            int menorH = hijoIzq(num);
            if(esMenor(datos[hijoDer(num)] , datos[hijoIzq(num)]) && hijoDer(num) < cantidad  ){
                menorH = hijoDer(num);
            }
            if(!esMenor(datos[menorH] , datos[num])){
                return;
            }

            Modulo aux = datos[num];
            datos[num] = datos[menorH];
            datos[menorH] = aux;
            num = menorH;
        }
    }

    void insertar(Modulo num){
        if(cantidad == capacidad){
            return;
        }
        datos[cantidad] = num;
        flotar(cantidad);
        cantidad++;
    }

    Modulo eliminarYDevolver(){
        
        Modulo min = datos[0];
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