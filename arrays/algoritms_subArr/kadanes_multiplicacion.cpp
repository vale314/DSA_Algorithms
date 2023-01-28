// https://www.codingninjas.com/blog/2020/09/17/a-quick-look-at-kadanes-algorithm/
/*

    Algortimo Kadanes (Multipliacion)
    
    (Este algoritmo funciona con las bases al anteior.
    Es programacion dinamica, con la memoria de lo anterior.)
    
    
    Explicacion del problema:
        [2, 3, -2, 4]
    
        Encontrar el resultado de la multiplicacion del mayor sub-arr.
        En este caso es [2, 3] = 2 * 3 = 6.
        
        En los otros sub-arreglos quedan los resultados negativos.
        
        Es aqui la importancia de guardar tambien esa posibilidad de los valores negativos
        recordar que: (-) * (-) = +.
        
        *** Entonces si tenemos un numero muy grande (-) y se descarta y mas adelante hay un (-),
        se volvera (+). ***
        
    
    Explicacion del algoritmo:
        
        Establecemos un maximo_global
        un maximo numero del producto -> el maximo del producto positivo (+)
        un minimo numero del producto -> el minimo del producto negativo (-) 
                                        // por si se vuelve positivo mas adelnate
        
        multiplicamos el current por el maximo y el minimo
        a y b.
        
        obtenemos el mayor entre a, b y el numero actual.
            (a, por si es +, y el b es por si llevamos un (-) y por un (-), da (+))
        
        obtenemos el minimo entre a, b y el current, para tener el otro extremo (-) guardado
        
        el maximo_global esta en max(maximo_global, max_current),
        
    
*/

#include<iostream>
using namespace std;

//Function to find maximum sum contiguous subarray in a given set of integers

int kadane(int nums[], int n)
{
        int max_global = nums[0];
        int max_product = nums[0];
        int min_product = nums[0];

        for(int i = 1; i < nums.size(); i++){

            int a = nums[i] * max_product;
            int b = nums[i] * min_product;

            max_product = max(max(a,b), nums[i]);
            min_product = min(min(a,b), nums[i]);

            max_global = max(max_product, max_global);

            // cout << "Num: " << nums[i] << endl;
            // cout << "min_product: "<< min_product << endl;
            // cout << "max_product: "<< max_product << endl;
            // cout << "max_global: "<< max_global << endl << endl;

        }
        
        return max_global;
}

int main()
{
 	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 	int n = sizeof(arr)/sizeof(arr[0]);
 	cout << "Maximum sum contiguous subarray is "<<kadane(arr, n);
 	return 0;
}