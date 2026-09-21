#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MinHeap.cpp"

using namespace std;

int main()
{
    int n;
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
        int min = heap.eliminarYDevolver();
        int otroMin = heap.eliminarYDevolver();
        heap.sumarCosto(min+otroMin);
        heap.insertar(min+otroMin);
    }
    heap.salida();
    

    return 0;
}