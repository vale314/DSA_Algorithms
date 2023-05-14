/*

    Expliacacion:
        Dado un string con carecters mayusculas y minusculas, 
        solo voltear de posicion las vocales y dejar las demas iguales.

        Ejemplo:
            hello
        
        Output:
            holle

        
    Solucion:
        Para solucionar este problema basta con recorrer el arreglo de string
        y en una pila poner todas las vocales.

        Volver a recorrer el arreglo y poner las vocales como estan en la pila.


*/


class Solution {
public:
    string reverseVowels(string s) {
        stack<int> st;

        for(char c: s){
                if(
                    c == 'a' || c == 'e' || c == 'i' ||c == 'o' || c == 'u' || 
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
                )
                    st.push(c);
        }

        for(int i = 0; i < s.length(); i++){
            if(
                    s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
                    s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
                ){
                    char t = st.top(); st.pop();
                    s[i] = t;
                }   
        }
        
        return s;
    }
};