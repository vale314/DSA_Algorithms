//{ Driver Code Starts
//Initial Template for C++

/*

    Explicacion del problema:

        Buscar la suma menor del sub-arr 

    Solucion:

        Aplicamos Kadanes, como el algoritmo.

        Llevamos el minimo del recorrido y nos quedamos
            con el menor entre la suma de el con el sub-arr
            o y si es menor el proximo elemento.
        
        y si es menor al global.

*/

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      
      int minGlobal = a[0];
      int minCurrent = a[0];
      
      for(int i = 1; i < a.size(); i++){
          
          minCurrent = min(minCurrent + a[i], a[i]);
          minGlobal = min(minCurrent, minGlobal);
          
      }
      
      return minGlobal;
  }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends



// https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Valentin Alejandro Ruiz Ortiz