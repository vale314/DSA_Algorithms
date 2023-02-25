/*

    Explicacion:
        Retornar la longitud.

        Solucion:
            Creamos una solucion con programacion dinamica, en este caso
            creamos una matriz de m+1 x n+1, m=s1.length, n=s2.length.

            Inicializamos con 0 toda la matriz.

            si son iguales los caracteres, en la posicion actual es igual al 
            elemento de la diagonal + 1.
                //Es por que en la diagonal llevamos cuando son iguales

            Si no, nos quedamos con el elemento mayor de el superior y el anterior.


*/


//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string &s1, string &s2)
    {

        int lcs[s1.length()+1][s2.length()+1];
        
        for(int i = 0; i < s1.length() + 1; i++)
            for(int j = 0; j < s2.length() + 1; j++)
                lcs[i][j] = 0;
        
        for(int i = 1; i < s1.length() + 1 ; i++){
            for(int j = 1; j < s2.length() + 1; j++){
                if(s1[i - 1] == s2[j - 1])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
            
        return lcs[s1.length()][s2.length()];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends


// Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article