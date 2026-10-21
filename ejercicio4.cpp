#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MinHeapEj4.cpp"

using namespace std;

struct Nodo{
    int destino;
    Nodo* sig;
    Nodo(int d, Nodo* s) : destino(d), sig(s){}
};

int main()
{
    int V, A;
    cin >> V >> A;
    long long* prioridades = new long long[V + 1];
    for(int i = 1; i<= V; i++){
        cin >> prioridades[i];
    }

    Nodo** adj = new Nodo*[V+1];
    int* grados = new int[V+1];

    for(int i = 1 ; i<=V; i++){
        adj[i] = NULL;
        grados[i] = 0;
    }

    for(int i = 0; i < A; i++){
        int u,v;
        cin >> u >> v;
        adj[u] = new Nodo(v, adj[u]);
        grados[v]++;
    }

    MinHeap heap(V+1);

    for(int i = 1; i<=V; i++){
        if(grados[i] == 0){
            Modulo m = {prioridades[i], i};
            heap.insertar(m);
        }
    }
    int* salida = new int[V];
    int cantProcesados = 0;
    while(!heap.esVacio()){
        Modulo actual = heap.eliminarYDevolver();
        salida[cantProcesados] = actual.id;
        cantProcesados++;

        Nodo* cur = adj[actual.id];
        while(cur){
            int vecino = cur->destino;
            grados[vecino]--;
            if(grados[vecino] == 0){
                Modulo m = {prioridades[vecino], vecino};
                heap.insertar(m);
            }
            cur = cur->sig;
        }
    }
    if(cantProcesados < V){
        cout << "imposible\n";
    } else{
        for(int i = 0; i<V; i++){
            cout << salida[i] << "\n";
        }
    }



    return 0;
}