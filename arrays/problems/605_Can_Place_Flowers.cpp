/*

    Explicacion:
        Dado un vector con 1 y 0, determinar si es posible agregar otros n's 1.
        para agregar 1 solo se puede si no hay 1 ni atras ni adelante.

    Solucion:
        Greedy no hay de otra, buscar todos los casos.

*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int s = flowerbed.size();
        
        if(s == 1 && n == 1)
            return flowerbed[0] == 0 ? true : false;
        
        
        for(int i = 0; i < flowerbed.size()-1; i++){
            if(!n)
                return true;

            if(flowerbed[i] == 1)
                continue;
            
            if(i == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
                continue;
            }
            
            if(flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
        }
        
        if(s > 1 && flowerbed[s - 1] == 0 && flowerbed[s - 2] == 0){
            flowerbed[s - 1] = 1;
            n--;
        }
        
        return n==0 ? true : false;
    }
};