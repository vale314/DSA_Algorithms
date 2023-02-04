//{ Driver Code Starts
/*

    Explicacion:
        enviar el vector[] con la suma mayor, un kadanes normal
        pero regresando el vector de los elementos que se usaron.

        El 0 tambien se toma como elemento + (Solo se sumaran elementos positivos)

        tomar en cuenta:
            [1,1,-7,2]

            [1,1] es el correcto y no [2]
            (por eso end = -1)

    Solucion:
        Tomamos desde el primer elemento
        creamos start, end, y aux(es el current de start).

        inicializacion:
            start = 0 (se inicializa desde el primer elemento)
            end = -1 (no deben de ser igual start y end)
                si es igual el apuntador esta en el mismo elemento
            aux = 0 es el current de start

        iteramos sobre todos los elemtnos y el elemento debe ser mayor a -1
        maxCurrent lo suma como un kadannes
        de lo contrario si es negativo current = 0, y el aux(current), es 
        igual al siguiente elemento.

        cuando maxCurrent sea mayor a maxGlobal y aux(current) sea difernete de i
        (osea que no sean el mismo elemento por las restriciones del problema)
        actualizamos el mayor, asi como start es aux(current de start) y end el
        elemento actual de i.

*/

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int nums[], int n) {
	    // code here
	    
	    int maxCurrent = 0;
	    int maxGlobal = 0;
	    vector<int> v;
	    
	    int start = 0;
	    int end = -1;
	    int aux= 0;
	        
	    for(int i = 0; i < n; i++){
	       if(nums[i] >= 0)
	           maxCurrent += nums[i];
	       else{
	           maxCurrent = 0;
	           aux = i + 1;
	       }
	       
	       if(maxCurrent > maxGlobal && aux != i){
	            maxGlobal = maxCurrent;
	            start = aux;
	            end = i;
	       }
	       
	    }
	    
	    if(maxGlobal < 1)
	        return {-1};
	   
	   // cout << start <<" "<< end << endl;
	    for(int i = start; i <= end; i++){
	        v.push_back(nums[i]);
	    }
	    
	    return v;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//Valentin Alejandro Ruiz Ortiz