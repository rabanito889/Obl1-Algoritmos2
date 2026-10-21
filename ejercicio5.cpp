#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/Heap5.cpp"
#include "tads/MFSet.cpp"

using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    if(V == 1){
        cout << "0\n";
        return 0;
    }

    MinHeap heap(E +1);
    for(int i = 0; i<E; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        Sendero s;
        s.u = u;
        s.v = v;
        s.costo = w;
        heap.insertar(s);
    }

    MFSet set(V);

    long long costoTotal = 0;
    int senderosUsados = 0;
    while(!heap.esVacio() && senderosUsados < V-1){
        Sendero s = heap.sacarMin();

        if(set.unir(s.u, s.v)){
            costoTotal += s.costo;
            senderosUsados++;
        }
    }
    if(senderosUsados == V -1){
        cout << costoTotal << endl;
    }else{
        cout << "imposible\n";
    }

    return 0;
};