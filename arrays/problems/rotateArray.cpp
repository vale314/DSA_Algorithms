//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        
        //Obtebemos el modulo pues siempre debera ser la rotacion dentro de N
        d = d % n;
        if(d == 0) return; // si es 0, es igual la rotacion
        
        int arrAux[n]; //creamos un arreglo Auxiliar de tam N
        int j = 0; // el Index de arraux
        
        // copiamos los primeros elementos de donde inicia 
        // la rotacion del orginial a Arraux
        for(int i = d; i < n; i++){
            arrAux[j] = arr[i];
            j++;
        }
        
        // Copiamos los primero elementos de arr hasta el elemento de rotacion
        for(int i = 0; i < d; i++){
            arrAux[j] = arr[i];
            j++;
        }
        
        // Copiamos los elementos al arr original
        for(int i = 0; i < n; i++){
            arr[i] = arrAux[i];
        }
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends


// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

// Valentin Alejandro Ruiz Ortiz