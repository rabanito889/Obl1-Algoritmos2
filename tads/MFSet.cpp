#include <iostream>
using namespace std;

class MFSet{
    private:
        int* padre;
        int* altura;
        int capacidad;

    public:
        MFSet(int n){
            this->capacidad = n+1;
            this->padre = new int[this->capacidad];
            this->altura = new int[this->capacidad];
            for(int i = 0; i< this->capacidad; i++){
                this->padre[i] = i;
                this->altura[i] = 0;
            }
        }

        ~MFSet(){
            delete[] padre;
            delete[] altura;
        }

        int find(int x){
            if(this->padre[x] != x){
                this->padre[x] = find(this->padre[x]);
            }
            return this->padre[x];
        }

        bool unir(int x, int y){
            int raizX = find(x);
            int raizY = find(y);


            if(this->altura[raizX]< this->altura[raizY]){
                this->padre[raizX] = raizY;
            }
            else if (this->altura[raizX] > this->altura[raizY]){
                this->padre[raizY] = raizX;
            }
            else {
                this->padre[raizY] = raizX;
                this->altura[raizX]++;
            }
            return true;
        }
};