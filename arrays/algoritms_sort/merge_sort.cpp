// Explicacion de Merge Sort

/*

https://media.geeksforgeeks.org/wp-content/uploads/20220722205737/MergeSortTutorial.png


    Algoritmo Merge Sort

    Para este algoritmo recordar como funiona una pila (Stack)
    porque usa recirsividad y dentro de C++ funionan las tareas a realizar
    en C++ en una pila (recursividad).

    Lo cual ayuda a comprender como funciona el algoritmo.

    Complejidad Computacional: (logn)
    Memoria: (N) (para la version programada posteriormente)

*/


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
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
    void merge(int arr[], int left, int mid, int right)
    {
        
        // creamos dos arreglos para copiar la informacion
        int const subArrayOne = mid - left + 1; // el tamano de la izq
        int const subArrayTwo = right - mid;    // el tamano de la der
     
        // crear dos arreglos temporales del tamano adecuado para cada uno
        int *leftArray = new int[subArrayOne];
        int *rightArray = new int[subArrayTwo];
        
        // Copiar el data a los arr temporales 
        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = arr[left + i]; //left[izq + i]
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = arr[mid + 1 + j]; //mid[der + j + 1] -> 1 porque arriba es [incluye desde x hasta y]
        
        int i, j; // los idx de cada arreglo temporal para saber donde vamos
        i = 0;
        j = 0;

        // desde que elemento emepezamos en nuestro arreglo origianl siempre es left
        int k = left;
        
        // mientras ambos arrgelos tengan algo
        while(i < subArrayOne && j < subArrayTwo){
            // dependiendo cual sea mayor se guarda en el orginal
            if(leftArray[i] <= rightArray[j]){
                arr[k] = leftArray[i];
                i++; // recorremos el sub arreglo del que se tomo
            }
            else{
                arr[k] = rightArray[j];
                j++; // recorremos el sub arreglo del que se tomo
            }
            // recorremos el original para guardar el siguiente elemento
            k++;
        }
        // si quedo algo en el primer arreglo se pasa directo al orginal
        while(i < subArrayOne){
            arr[k] = leftArray[i];
            i++;
            k++;
        }
        //si quedo algo en el segundo arreglo se pasa directo al original
        while(j < subArrayTwo){
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
       //code here
        
        // recursion funciona con un stack - pila
        // si no comprendes realiza la funcion y mete la recursion siguiente en la pila y lo entederas
        /*
            
                                [4, 1, 3, 9, 7]
                                                ordenar() [1, 3, 4, 7, 9]
                    1 -> [1, 4]   ordernar()[1, 4]                  2 -> [3, 9, 7] ordenar() [3, 7, 9]
                            
                2 -> acaba [4] # 3 -> acaba[1]      4 -> [3]        5 -> [7, 9] (ordenar) [7, 9]
                                                                
                                                                6 ->[9]     7 -> [7]
            
            
        */
        
        // Que el apuntador de la izquierda no sea mayor al de dere
        // hasta que llegue a un solo elemento y regresa
        if (left >= right)
            return; // Returns recursively
        
        // por lo mismo siempre operamos cuando arr[] tenga 2 elementos
        int mid = (left + right) / 2; // partimos a la mitad el arr
        mergeSort(arr, left, mid); // enviamos la mitdad del arr ha recursion izquerda
        
        // enviamos recursion de derecha, mid + 1 es para que tome el elemento correcto
        // arr[1, 2, 3, 4]
        //        mid
        //           mid+1

        mergeSort(arr, mid + 1, right); // enviamos la otra mitad derecha ha recursion
        

        // en realiad siempre enviamos un arr con minimo 2 elementos es lo mas bajo cuando acaba la recursion
        //enviamos a ordernar de donde inicia, donde es la mitad y donde termina
        merge(arr, left, mid, right);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


// Valentin Alejandro Ruiz Ortiz

//https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article