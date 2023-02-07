/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void reverseStr(string &s, int n){
    
    for(int i = 0; i < s.length()/2; i++)
        swap(s[i], s[s.length() - i - 1]);
    
}

int main()
{
    string s ="valentin";
    
    // reverse(s.begin(), s.end());
    reverseStr(s,0);
    
    cout << s << endl;

    return 0;
}

