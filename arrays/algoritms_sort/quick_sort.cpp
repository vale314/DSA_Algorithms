// Explicacion de Quick  Sort

/*

    Quick Sort - Rapido Ordenamiento en C++

    Quick sort, funciona eligiendo un pv (elemento)
    y sobre el buscar su poscion, dejar lo menores a la izq, 
    y mayores a la derecha.

    Hay varias formas de elegir el pv, al incio, en medio, operacion matematicas.
    Mejora con respecto a eso
    Este algoritmo usa elegir al final

    Complidad Computacional: O(N2) en el peor de los casos cuando 
        estan parcial, completa o inversa ordenados...
    
    Memoria: (1)
        No requerimos de nada en auxilar (arr, vectores, matrices, etc).

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
    void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
  
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {

        // low y high son apuntadores dentro del arreglo incian siendo ambos extremos
        // se detiene cuando el menor sea igual o mayor a el apuntador high
        if(low >= high) return;
       
        // mandamos el arr a que nos regrese la posicion de pivote correcto
        int pv = partition (arr, low, high);
        
        quickSort(arr, low, pv - 1); // mandamos por izquierda, y pv-1, porque pv ya esta ordenado
        quickSort(arr, pv + 1, high); //mandamos por derecha, y p + 1, porque pv ya esta ordenado igual jeje.
        
    }
    
    // esta funcion nos manda la posicion correcta del pivote, ese elemento esta en la posicion correcta
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       // pivote =  elemento que se encontrara en la poscion corecta dentro del arrglo
       // por encima de el, todos son mayoes, por debajo todos son menores

       int pv = arr[high]; // Tomamos nuestro pivote como el ultimo elemento
       int iMenor = low; // y el idx como el mas bajo 
       
       // recorremos el sub-arreglo enviado
       for(int i = low; i < high; i++){
           
           // si el elemnto actual es menor que el pivote
           if(arr[i] < pv){
                // cambiamos el elemento actual con el menor
                swap(&arr[i], &arr[iMenor]);
                iMenor++;
                // menor siempre va uno adelante, osea listo para cambiar, en el elemento siguiente del menor
           }
       }
       
       //ponemos el eleemnto pivote en su posicion.
       swap(&arr[iMenor], &arr[high]);
       return (iMenor); // retornamos la posicion del pivote para que ahora ordene en arreglo izquiero al pivote y derecho
       
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
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends