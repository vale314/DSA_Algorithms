//{ Driver Code Starts
// C program for insertion sort

// Explicacion del algoritmo

/*
    Algortimo Insertion Sort

    Para el algoritmo de insercion funciona comenzado del segundo elemento
    Si es N = 1 Elemento regresamos arr[x]

    Ordenamos el conjunto de atras
    Vamos buscando el espacio indicado del elemento que tenemos y vamos
    recorriendo (copiando el anterior) los elementos
    cuando encontramos su lugar lo sobre-escribimos
    porque el elemento ya esta copiado en la siguinete posicion

    x-> el conjunto ya ordenado
    z -> el elemento a ordenar dentro de x

    xzyyyyyy

        si es menor z que x, guardamos z y recorremos las x hasta
        que no sea menor algun x que z.
        y escribimos z en x en su poscion adecuada.

*/


#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void insert(int arr[], int i)
    {
        
        insertionSort(arr,i);
        
        //code here
        
       
    }
    
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        if(n==1)
            return;
        
        //code here
        for(int i = 1; i < n; i++){
            
            //el primer elemento se guarda para no perderlo
            int frente = arr[i];
            
            // dejamos listo j el el elemnto [0] para empezar comp    
            int j = i - 1;
            
            // recorremos todos los elementos hasta que:
            // j sea 0 o el elemento del frente ya no sea menor
            while(j >= 0 && frente < arr[j]){
                arr[j+1] = arr[j]; // recorremos los datos
                j--;
            }
            
            // + 1 porque nos quedemos en uno extra por el j-- for
            arr[j+1] = frente; 
            
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;

    scanf("%d",&T);

    while(T--){

    scanf("%d",&n);

    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.insertionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends




// Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/insertion-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article