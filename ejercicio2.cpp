#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HashAbierto.cpp"
using namespace std;

int main()
{
    int n;
    cin >> n;
    HashAbierto* lista = new HashAbierto(2*n);
    for(int i =0; i<n; i++){
        string pal;
        cin >> pal;
        lista->registrar(pal);
    }
    int N;
    cin >> N;
    for(int i=0; i<N;i++){
        string pal;
        cin >> pal;
        int ret = lista->consultar(pal);
        cout << ret << "\n";
    }
    lista->tirarDatos();




    return 0;
}