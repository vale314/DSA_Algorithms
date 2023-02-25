/*

    Explicacion:
        Longest common subsequence:
            Debemos encnontrar la subsecuencia mas grande entre dos strings en comun.

            Una subsquencia es las posibles string a formar con los string siguientes

            Ejemplo:
                str1 = ABCDGH
                str2 = AEDFHR

            Output:
                    ADH

            Solucion Por recursividad:
                Tenemos dos apuntadores, uno hacia la palabra 1, y otro de palabra 2

                Si alguno de los dos llega al final se retorna 0

                si ambos string tienen ese caracter en comun se retorna 1 +
                llamarse de nuevo, y avanzamos ambos apuntadores.

                En caso que no: buscamos el maximo entre la izquerda y el derecho

                Complijidad de tiempo: n^2
                Memoria: (1)


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
    int lcs(int x, int y, string &s1, string &s2, int l = 0)
    {
        if(l==0){
            x=0;
            y=0;
        }
        
        // your code here
        if(x >= s1.length() || y >= s2.length())
            return 0;
        
        if(s1[x] == s2[y])
            return (1 + lcs(x+1, y+1, s1, s2, 1));
        else
            return max(lcs(x+1, y, s1, s2, 1), lcs(x, y+1, s1, s2, 1));
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