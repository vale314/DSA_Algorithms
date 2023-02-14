/*

    Explicacion:
        Dado un entero K, generar el numero las combinaciones posibles de un arreglo
        de tamano K, con solo 0 y 1.

        Donde no tenga 1 consecutivos

        Ejemplo:
            K = 3

            000 100 101 010 001

            Output: 5
        
        Solucion:

            Existen varias soluciones:

                Fibonacci: Generar un fibonacci, y el numero que buscamos esta en uno mas


*/


#include <iostream>
#include <vector>

using namespace std;

// Fibonacci - DP
int solve(int n){
    
    vector<int> fib(n + 2, 0);

    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i <= n + 1; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    return fib[n + 1];
}

// Recurrencia
int solve(int prev,int n)
	{
	   if(n==0) return 0;
	   if(n==1)
	   {
	       if(prev==0)
	       return 2;
	       if(prev==1)
	       return 1;
	   }
	   if(prev==0)
	   return solve(0,n-1)+solve(1,n-1);
	   if(prev==1)
	   return solve(0,n-1);
	}

int main()
{
    int n; cin >> n;
    // cout << solve(0, n) << endl;
    cout << solve(n) << endl;

    return 0;
}


// Valentin Alejandro Ruiz Ortiz

// https://www.geeksforgeeks.org/generate-binary-strings-without-consecutive-1s/

// Tipos de soluciones:
// https://leetcode.com/discuss/general-discussion/1287402/count-number-of-binary-strings-without-consecutive-1s