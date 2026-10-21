#include <iostream>
using namespace std;


struct Sendero{
    long long costo;
    int u;
    int v;
};


class MinHeap{
    private:
    Sendero* datos;
    int cantidad;
    int capacidad;
    
    public:
    MinHeap(int capacidad){
        this->datos = new Sendero[capacidad];
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
        while( (datos[num].costo < datos[padre(num)].costo) && num >0){
            Sendero aux = datos[num];
            datos[num] = datos[padre(num)];
            datos[padre(num)] = aux;
            num = padre(num);  
        }
    }

    void hundir(int num){   //tuve que ver el repositorio de la clase de Heap porque no me acordaba esta funcion :(
        while(hijoIzq(num) < cantidad){
            int menorH = hijoIzq(num);
            if(datos[hijoDer(num)].costo < datos[hijoIzq(num)].costo && hijoDer(num) < cantidad  ){
                menorH = hijoDer(num);
            }
            if(datos[num].costo <= datos[menorH].costo){
                return;
            }

            Sendero aux = datos[num];
            datos[num] = datos[menorH];
            datos[menorH] = aux;
            num = menorH;
        }
    }

    void insertar(Sendero num){
        if(cantidad == capacidad){
            return;
        }
        datos[cantidad] = num;
        flotar(cantidad);
        cantidad++;
    }

    Sendero sacarMin(){
        
        Sendero min = datos[0];
        datos[0] = datos[cantidad-1];
        cantidad --;
        if(cantidad >0){
            hundir(0);
        }
        return min;

    }

    
};