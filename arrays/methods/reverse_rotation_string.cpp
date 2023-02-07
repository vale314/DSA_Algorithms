#include <bits/stdc++.h>
using namespace std;
 
 
// In-place rotates s towards left by d
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}
 
// In-place rotates s towards right by d
void rightrotate(string &s, int d)
{
   leftrotate(s, s.length()-d);
}

  
// Driver program
int main()
{

    string str1 = "GeeksforGeeks";
    leftrotate(str1, 15 % str1.length());
    cout << str1 << endl;
 
    string str2 = "GeeksforGeeks";
    rightrotate(str2, 2 % str1.length());
    cout << str2 << endl;

    return 0;
}