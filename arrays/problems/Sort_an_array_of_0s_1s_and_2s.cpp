/*

    Explicacion del problema:
        Un arreglo con 0, 1, 2;
        [0, 0, 1, 2, 0, 1, 2]

        ordenarlo en tiempo O(N) y espacio O(1)

    Solucion:
        
        Contar la cantidad de zeros, unos y dos

        escribirlos en el arreglo de manera secuencial.


        Tiempo Computacional: O(N)
        Espacio Memoria: O(1)

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        
        int zero = 0;
        int ones = 0;
        int twos = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0)
                zero++;
            
            if(a[i] == 1)
                ones++;
            
            if(a[i] == 2)
                twos++;
        }
        
        for(int i = 0; i < n; i++){
            if(zero > 0){
                a[i] = 0; 
                zero--;
                continue;
            }
            
            if(ones > 0){
                a[i] = 1;
                ones--;
                continue;
            }
            
            if(twos > 0){
                a[i] = 2;
                twos--;
                continue;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends