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
        // code here
        
        if(low >= high) return;
       
        int pv = partition (arr, low, high);
        
        quickSort(arr, low, pv - 1);
        quickSort(arr, pv + 1, high);
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       int pv = arr[high];
       int iMenor = low;
       
       for(int i = low; i < high; i++){
        //   if(arr[i] > pv) continue;
           
           if(arr[i] < pv){
               swap(&arr[i], &arr[iMenor]);
               iMenor++;
           }
       }
       
       swap(&arr[iMenor], &arr[high]);
       return (iMenor);
       
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



// Valentin Alejandro Ruiz Ortiz


// https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article