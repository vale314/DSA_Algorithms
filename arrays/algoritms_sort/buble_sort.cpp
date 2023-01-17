//{ Driver Code Starts
//Initial Template for C++

// C program for implementation of Bubble sort


// Explicacion del algoritmo

/*
    En algoritmo de Buble_Sort -> Burbuja ordenacion

    Comparar cada elemento es menor con el siguiente N veces

    x1 - x2 y - y - y - y

        Si x2 es menor que x1 se cambia
    
    x - x1 - x2 - y - y - y

        Si x2 es menor a x1 se cambia
    
    Se realiza este proceso N por cada elemento
    Se detiene si en la iteracion del ciclo for, no hubo ningun cambio
    quiere decir que todo esta ordenado

    Complejidad computacional: O(N2)
    Memoria: O(1)

*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// swapping the elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        int check = 0;
        for(int i = 0; i < n; i++){
            int check = 0;
            for(int j = 0; j < n - 1; j++){
                if(arr[j+1] < arr[j]){
                    check = 1;
                    swap(arr[j], arr[j+1]);
                }
            }
            
            if(!check) return;
        }
        
        // for(int i = 0; i < n; i++)
        //     cout << arr[i] << " - ";
        // cout << endl;
    }
};


//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
      
    ob.bubbleSort(arr, n);
    printArray(arr, n);
    }
    return 0;;
}
// } Driver Code Ends




// Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/bubble-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article