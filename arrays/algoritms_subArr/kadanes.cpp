// https://www.codingninjas.com/blog/2020/09/17/a-quick-look-at-kadanes-algorithm/
/*

    Algortimo Kadanes
    
    Nos permite obtener la suma de mayor sub-arreglo de un arreglo
    
    Ejemplo:
        [1,2,3,4,5]
        
    For element at 0th index	{1}, {1,2}, {1,2,3}, {1,2,3,4}, {1,2,3,4,5}
    For element in 1st index	{2}, {2,3}, {2,3,4}, {2,3,4,5}
    For element in 2nd index	{3}, {3,4}, {3,4,5}
    For element in 3rd index	{4}, {4,5}
    For element in 4th index	{5}
    
    En este caso es {1,2,3,4,5}.
    
    Pero este algorimo nos permite saber el mayor con un Arreglo: + y -.
    
    Ejemplo:
    
        {-2, -3, 4, -1, -2, 1, 5, -3}
    
    El sub arreglo mayor es [4, -1, -2, 1, 5] = 7.
    
    La Complejidad Computacional es: O(N).
    Complejidad Memoria: (1).
    
    
    Este ejemplo solo funciona buscando un maximo global que sea positivo.
    No buscando la suma tambien de numeros negativos.
*/

#include<iostream>
using namespace std;

//Function to find maximum sum contiguous subarray in a given set of integers

//Solo obtiene el mayor de valores +
int kadane(int nums[], int n)
{
	int max_global = 0; // Almacena en mayor maximo del sub-arr encontrado
    int max_iterativo = 0;  // Almacena en mayor actual del recorrido

    for(int i = 0; i < n; i++){

        max_iterativo += nums[i]; // el igual al elemento i en suma con sus acomuldaos consecutivos

        if(max_iterativo < 0)  //  si es menor a 0 el acomulado se vuelve 0
            max_iterativo = 0;
            
        if(max_iterativo > max_global) // si es mayor el acomulado al global se resguarda.
            max_global = max_iterativo;
    }

    return max_global; // retornamos el maximo global
}

//Obtinene el mayor de numeros + y -
int kadane_simplificado_positivos_negativos(int nums[], int n){
    
    int mayorCurrent = nums[0];
    int mayorGlobal = nums[0];


    for(int i = 0; i < n; i++){
        
        mayorCurrent = max(mayorCurrent + nums[i], nums[i]);
        mayorGlobal = max(mayorCurrent, mayorGlobal);

    }

    return mayorGlobal;
}


int main()
{
 	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	// cout << "Maximum sum contiguous subarray is "<<kadane(arr, n);
 	cout << "Maximum sum contiguous subarray is "<<kadane_simplificado_positivos_negativos(arr, n)<<endl;
 	return 0;
}