//{ Driver Code Starts
// C++ program for implementation of Heap Sort

/*

    Explicacion del problema:

        Realizar un ordenamiento, O(NLog(N)). 

        Se realiza un minHeap, y se inserta el todos los elementos de arr

        Sabemos que siempre estara el menor en el tope, por lo que solo
        debemos de sacar el tope y guardarlo en orden asendente en el arr.

        Complejidad Computacional: (Log N)
        Memoria: (N)

*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class minHeap {
    private:
        long size;
        long capacity;
        
        vector<int> heap;
        
        long parent(int i){return ((i-1)/2);}
        long child_left(int i){return ((i*2) + 1);}
        long child_rigth(int i){return ((i*2) + 2);}
        
    public:
    
        minHeap(long capacity){
            this->size = 0;
            this->capacity = capacity;
            heap.resize(capacity);
        }
        
        void insert(long e);
        long top();
        void heapify(long i);
    
};

void minHeap::insert(long e){
    if(this->size == this->capacity){
        cout << "Capacicty is full" << endl; 
        return;
    }
    
    int i = this->size;
    heap[i] = e;
    
    this->size++;
    
    while(i != 0 && heap[i] < heap[parent(i)]){
        std::swap(heap[i],  heap[parent(i)]);
        i = parent(i);
    }
}

void minHeap::heapify(long i){
    long left = child_left(i);
    long rigth = child_rigth(i);
    long smallest = i;
    
    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    
    if(rigth < size && heap[rigth] < heap[smallest])
        smallest = rigth;
        
    if(smallest == i) return;
    
    swap(heap[i], heap[smallest]);
    heapify(smallest);
        
}

long minHeap::top(){
    if(size == 0) return - 1;
    
    long e = -1;
    
    if (size == 1){
        e = heap[0];
        size--;
    }
    
    e = heap[0];
    heap[0] = heap[size - 1];
    
    size--;
    
    heapify(0);
    
    return e;
    
}


class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        
        minHeap menorHeap(n);
        
        for(int i = 0; i < n; i++)
            menorHeap.insert(arr[i]);
            
        for(int i = 0; i < n; i++){
            arr[i] = menorHeap.top();
        }
            
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends


// Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/heap-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article