/*

    Explicacion: 
        Buscar un lca (Longest conmmon ancestor)
        buscar en un arbol binario, el padre de un par de hojas.

        retornar:
            El padre.

        Solucion:
            Relizar un camino desde el nodo hasta el primer elemento, y posteior al segundo.
            iterar el camino e invertirlo, buscar el commun y retornar elemento.

        Complejidad:
            O(V/2).

            Se itera sobre el arbol para la busqueda O(V + E), luego se hace una busqueda
            de ambos caminos el comun en posicion invertida.
        
        Memoria:
            O(1)

*/

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    bool 
        path(Node *root, vector < Node* > &aux, int &d){
            
            if(root == NULL || root == nullptr)
                return false;
            
            aux.push_back(root);
            
            if(root -> data == d) return true;
            
            if( 
                (path(root -> left, aux, d)) ||
                (path(root -> right, aux, d))
            )
                return true;
                
            aux.pop_back();
            return false;
                
        }
        
    void print(vector <Node*> aux){
        for(auto e: aux)
            cout << e -> data << " - ";
        
        cout << endl;
    }
  
    Node *lca(Node * root, int v1,int v2) {
		// Write your code here.
        
        vector < Node* > aux1;
        vector < Node* > aux2;
        
        path(root, aux1, v1);
        path(root, aux2, v2);
        
        // print(aux1); cout << endl << endl;
        // print(aux2);
        
        for(int i = aux1.size() - 1; i >= 0; i -- )
            for(int j = aux2.size() - 1; j >= 0; j -- )

                if(aux1[i] -> data == aux2[j] -> data)
                    return aux1[i];
        
        return root;
    }

}; //End of Solution