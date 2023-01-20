#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class minHeap{
    private:
        long size;
        long capacity;
        
        vector<long> heap;
        
        long parent(long i){return ((i-1)/2);}
        long child_left(long i){return ((2*i)+1);}
        long child_right(long i){return ((2*i)+2);}
    
    public:
        
       minHeap(long capacity);
       long find(long element);
       void erase(long id);
       void insert(long element);
       long one();
       long extracMin();
       void hepify(long i);
       void printHeap();
       
};

minHeap::minHeap (long capacity){
    this->size = 0;
    this->capacity = capacity;
    heap.resize(capacity);
}

void minHeap::insert(long element){
    if(this->size == capacity){
        cout<<"Capacidad Maxima de insersiones"<<endl;
        return;
    }
    long i = this->size;
    heap[i] = element;
    
    this->size++;
    
    while(i != 0 && heap[i] < heap[parent(i)]){
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void minHeap::hepify(long i){
    
    long left = this->child_left(i);
    long right = this->child_right(i);
    long smallest = i;
    
    //si tiene hijo izq, y es menor al root
    if(left < size && heap[left] < heap[smallest])
        smallest = left; 
    
    if(right < size && heap[right] < heap[smallest])
        smallest = right;
    
    //si hubo cambio con alguno de sus hijos ahora hay que ver
    // ese elemento este correcto con sus hijos
    if(smallest != i){
        swap(heap[i], heap[smallest]);
        hepify(smallest);
    }
    
}

void minHeap::erase(long id){
    if(size == 1){
        size--;
        heap[0] = heap[1];
    }else{
        
        heap[id] = heap[size - 1];
        size--;
        hepify(id);
    }   
}

long minHeap::one(){
    if(size == 0){
        cout<<"No hay elemntos" << endl;
        return -1;
    }
    return heap[0];
}

long minHeap::extracMin(){
    if(size == 0){
        cout << "Se encuentra vacio" << endl;
        return -1;
    }
    
    else if(size == 1){
        size--;
        return (heap[0]);
    }else{
    
        long aux = heap[0];
        heap[0] = heap[size - 1];
        size--;
        hepify(0);
        return aux;
    }
}

// void minHeap::printHeap(){
//     int power = 0;
//     int value = 1;
//     for(int i = 0; i < size; i++){
//         if(i == value){
//             cout << endl;
//             power += 1;
//             value += (1 << power);
//         }
//         cout << heap[i] << "  ";
//     }
//     cout << endl;
// }

long minHeap::find(long element){
    auto it = std::find(heap.begin(), heap.end(), element);
    
    long id = -1;
    
    if(it != heap.end())
        id = it - heap.begin();
    
    // cout << "id: " << id << endl;
    return id;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    int q;
    cin >> q;
    minHeap heap(99999 + 1);
    for (int i = 0; i < q; i++) {
        long t, v;
        cin >> t;
        
        switch (t) {
        case 1:
            cin >> v;
            heap.insert(v);
            break;
        case 2:
            cin >> v;
            heap.erase(heap.find(v));
            // heap.extracMin();
            break;
        case 3:
            cout << heap.one() << endl;
            break;
        }
    }
    
    return 0;
}



// Valentin Alejandro Ruiz Ortiz

// https://www.hackerrank.com/challenges/qheap1/problem?isFullScreen=true