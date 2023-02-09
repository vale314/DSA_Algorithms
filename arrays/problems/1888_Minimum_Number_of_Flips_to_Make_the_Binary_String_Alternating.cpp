/*
    Explicacion:
    
    Mismo problema que:
        https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

    En este caso podemos borrar el primer elemento y agregarlo al final.

    Solucion:
        En este caso se realizo con 

        Tiempo COmputacional: O(N2)
        Memoria: O(1)

        Por lo que fue imposible pasar el test por tiempo.

        Se agrega el elem, en la poscion final y luego se manda a cambiar y 
        buscar el menor de los cambios con esa variacion.

        y se nos quedamos con el menor entre:
             en menor anterior o el menor de la iteracion

*/

class Solution {
public:
    int find(string &S){
        string aux1 (1, S[0]);
        int prevNumber = stoi(aux1);
        int count1 = 0;

        for(int i = 1; i < S.length(); i++){
            string aux2 (1, S[i]);
            int actual = stoi(aux2);
            
            if(prevNumber == actual){
                count1++;
                prevNumber = actual == 1 ? 0 : 1; 
                continue;
            }

            prevNumber = actual;

        }

        string aux3 (1, S[0]);
        prevNumber = stoi(aux3) == 1 ? 0 : 1;
        int count2 = 1;

        for(int i = 1; i < S.length(); i++){
            string aux4(1, S[i]);
            int actual = stoi(aux4);

            if(prevNumber == actual){
                count2++;
                prevNumber = actual == 1 ? 0 : 1;
                continue;
            }

            prevNumber = actual;
        }

        return min(count2, count1);
    }

    int minFlips(string S) {
        int minNumber = INT_MAX;
        
        minNumber = min(minNumber, find(S));
        
        int n = S.length();

        for(int i = 1; i < n; i++){
            char actual = S[0];
            S = S.erase(0,1);
            S.push_back(actual);
            // cout << actual << endl;
            // cout << S << endl;
            minNumber = min(minNumber, find(S));
        }

        return minNumber;
    }
};


// Valentin Alejandro Ruiz Ortiz

// https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/