/*

    Explicacion:
        Realizar la secuencia de los numeros 0 1 1 2 3 4 5 8 13
            //es la secuencia de los numeros anteriores en sumatoria.

    Solucion:
        Se soluciona por recurrencia.
        En este caso la condicion de paro es cuando n sea menor o igual 1 
        y llamamos la funcion recursiva para n - 1 y n - 2.

        (Muy distino a dp) 

*/

class Solution {
public:

    int fib_rec(int n){
        
        if(n <= 1)
            return n;
        return fib_rec(n - 1) + fib_rec(n - 2);
    }

    int fib(int n){
        return fib_rec(n);
    }

};