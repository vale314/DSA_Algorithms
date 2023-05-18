/*

    Explicacion:
        Obtener el mayor area dado un vector.

        Ejemplo:
            [1,8,6,2,5,4,8,3,7]

            Realizar una area dado los numeros fueran altura
            y las posiciones fueran el ancho.
        
        Salida:
            49

    Solucion:
        O(N): Iterar mientras (i < j) sobre el arreglo con dos punteros, uno al principio i
        y uno al final j, y realizar el calculo de area, guardar si es mayor
        a lo guardado.

        De ambos punteros el menor el valor de height iterar, 
        si es i, ++ y si es j, --.
        
        O(N2): Realizar una iteracion sobre cada uno de los elementos
        e ir comprobando si es mayor a lo que tenemos

    Tiempo: O(n2)
    Memoria:(1)


*/


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size() - 1;

        int res = INT_MIN;

        while(i < j){
            int aux = min(height[i], height[j]);
            aux = aux * ((j+1) - (i+1));
            res = max(aux, res);


            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return res;



        // int res = INT_MIN;

        // for(int i = 0; i < height.size(); i++){
        //     for(int j = i + 1; j < height.size(); j++){
        //         int aux = min(height[i], height[j]);
        //         aux = aux * ((j + 1) - (i + 1));

        //         res = max(res, aux);
        //     }
        // }

        // return res;
    }
};