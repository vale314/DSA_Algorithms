//{ Driver Code Starts

// explicacion del algoritmo
/*
    Buscar el elemento mas bajo y cambiarlo por el primero
    avanzamos un elemento y buscar el elemento mas bajo y cambiarlo por el segundo

    xyyyyyyyy
    buscar la y mas pequena y si es menor a x se cambia y avanza x

    zxyyyyyy
    buscar la [Y] menor y si es menor que x cambiarla

    zzxyyyyy
    realizamos este proceso sucesivamente hasta finalizar

    zzzxyyyy
    zzzzxyyy
    zzzzzxyy
    zzzzzzxy
    zzzzzzzy
    zzzzzzzx

    complejidad computacional: Comparar todos con todos O(N2)
    memoria: Si se trabaja sobre el arreglo no se duplica  O(1)

*/

#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}



// } Driver Code Ends
class Solution
{
    public:
    int select(int arr[], int i)
    {
        int N = sizeof(arr) / sizeof(int);
        // code here such that selectionSort() sorts arr[]
        selectionSort(arr, N);
    }
     
    void selectionSort(int arr[], int n)
    {
       for(int i = 0; i < n-1; i++){
           int min = i;
           
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[min])
                    min = j;
            }
            swap(arr[i], arr[min]);
       }
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
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends



//Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/selection-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article