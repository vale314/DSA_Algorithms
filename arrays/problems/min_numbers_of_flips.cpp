/*

    Explicacion:
        Debemos de cambiar la cantidad minima de veces los 1 x 0, 0 x 1.

        Y retornar numero menores de cambios en el string 
        para que queden intercalados los numeros.

        Ejemplo: 

            001
            101

            -=== 1
            
            Solo se ocupo cambiar una vez.
    
    Solucion:
        Para solucionar el problema tomamos el primer digito y lo recorremos
        en un ciclo, el numero anterior debe de ser diferente al actual y 
        aumetamos el contador y el anterior de cambia para la siguiente iteracion funcione

        en caso contrario se guarda tal cual el anterior.

        y en el caso del segundo for, se toma que el primer elemento se debe cambiar
        y se vuelve a correr.

        Tiempo Computacional O(n)
        Memoria: O(1)

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    
    string s(1, S[0]);
    int countChange1 = 0;
    int prevNumber = stoi(s);
    
    for(int i = 1; i < S.length(); i++){
        string s1(1, S[i]);
        int actual = stoi(s1);
        
        // cout << actual << " - " << prevNumber << endl;
        if(actual == prevNumber){
            countChange1++;
            prevNumber = actual ? 0 : 1;
        }
        else 
            prevNumber = actual;
    }
    
    
    string s2(1, S[0]);
    int countChange2 = 1;
    prevNumber = stoi(s2) == 1 ? 0 : 1;
    
    for(int i = 1; i < S.length(); i++){
        string s3(1, S[i]);
        int actual = stoi(s3);
        
        // cout << actual << " - " << prevNumber << endl;
        if(actual == prevNumber){
            countChange2++;
            prevNumber = actual ? 0 : 1;
        }
        else 
            prevNumber = actual;
    }

    return (min(countChange2, countChange1));
    
};



// Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article