/*

    Explicacion del problema:
        Obtener el sub-arreglo mas grande 0 continuos, y los 1 restan 1.

        Ejemplo:
            1 1 0 0 0 0 1 0 0 0 1
        
        El mayor sub-arr es 6 -> los 0 valen 1, y los 1 valen -1.

            1   1  [0  0  0  0  1  0  0  0]  1
           -1  -1   1  1  1  1 -1  1  1  1  -1

        retorno: 6

        Solucion:
            Para solucionar el problema debemos de tener en cuenta el algoritmo de kadanes

            Llevamos la cuenta cada 0 es 1, y diferente es -1.

            Llevamos la cuenta del Current si es mayor al global se guarda
            si el current es menor osea llevemos muchos 1 y ya se hizo negativo
            se deja en 0.

            Si el current es mayor, significa que estamos en el sub-arr con mas
            0 seguidos y se guarda en maxGlobal.


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	
    	int n = S.length();    
        int maxCurrent = 0;
        int maxGlobal = INT_MIN;
        
        for(int i = 0; i < n; i++){
            if(S[i] == '0')
                maxCurrent++;
            else
                maxCurrent--;
                
            if(maxCurrent > maxGlobal)
                maxGlobal = maxCurrent;
            
            if(maxCurrent < 0)
                maxCurrent = 0;
        }
	    
	    return maxGlobal;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends