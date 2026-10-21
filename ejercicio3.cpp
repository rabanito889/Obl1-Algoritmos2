#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MinHeap.cpp"

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if(n == 1){
        cout << "0" << endl;
        return 0;
    }
    MinHeap heap(n);
    for(int i = 0; i<n; i++){
        int m;
        cin >> m;
        heap.insertar(m);
    }
    while(heap.tamano() > 1){
        long long min = heap.eliminarYDevolver();
        long long otroMin = heap.eliminarYDevolver();
        heap.sumarCosto(min+otroMin);
        heap.insertar(min+otroMin);
    }
    heap.salida();
    

    return 0;
}