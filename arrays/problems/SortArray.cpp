//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void merge(vector<int> &arr, int left, int mid, int rigth){
        
        int sizeLeft = mid - left + 1;
        int sizeRigth = rigth - mid;
        
        vector<int> arrLeft;
        vector<int> arrRigth;
        
        // arrLeft.resize(sizeLeft);
        // arrRigth.resize(sizeRigth);
        
        for(int i = 0; i < sizeLeft; i++)
            arrLeft.push_back(arr[left + i]);
        for(int i = 0; i < sizeRigth; i++)
            arrRigth.push_back(arr[i + mid + 1]);
            
        int i = 0;
        int j = 0;
        
        int k = left;
        
        while(i < sizeLeft && j < sizeRigth){
            if(arrLeft[i] < arrRigth[j]){
                arr[k] = arrLeft[i];
                i++;
                k++;
            } 
            else {
                arr[k] = arrRigth[j];
                j++;
                k++;
            }
        }
        
        while(i < sizeLeft){
            arr[k] = arrLeft[i];
            i++;
            k++;
        }
        
        while(j < sizeRigth) {
            arr[k] = arrRigth[j];
            j++;
            k++;
        }
    }
    
    public:
    void mergeSort(vector<int> &arr, int left, int rigth){
        
        if(left>=rigth)
            return;
        
        int mid = (left + rigth) / 2;
        
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, rigth);
        
        merge(arr, left, mid, rigth);
    }
    
    public:
    vector<int> sortArr(vector<int>arr, int n){
    //complete the function here
        mergeSort(arr, 0, arr.size() - 1);
        
        return arr;
    }
};


//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        Solution ob;
        vector<int>v = ob.sortArr(s, n);
        for(auto i : v)
            cout << i << ' ';
        cout << endl;
    }
return 0;
}


// } Driver Code Ends


//Valentin Alejandro Ruiz Ortiz

// https://practice.geeksforgeeks.org/problems/sort-the-array0055/1