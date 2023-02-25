/*

    Explicacion:
        Con dos strings:
            Jewels: zcx (son las piedras preciosas)
            Strones:  xds (todas las rocas)

        Encontrar en las rocas, cuantas piedras preciosas tenemos en base
        a nuestro string de jewels.

    Solucion:
        crear un hash, donde guardamos las piedras preciosas que tenemos,
        en una iteracion buscar si la encontramos en las rocas si es asi
        aumentamos nuestro contador.

        Sl final regresamos el contador.

*/


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map <char, int> hash;

        for(int i = 0; i < jewels.length(); i++)
            hash[jewels[i]] = 1;

        int count = 0;

        for(int i = 0; i < stones.length(); i++){
            if(hash.find(stones[i]) != hash.end())
                count++;
        }

        return count;
    }
};