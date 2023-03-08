class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;

        for(char i: s){
            
            if(i == '(' || i == '[' || i == '{') 
                sta.push(i);

            else {
                
                if(sta.empty()) return false;

                char current = sta.top(); sta.pop();

                if( i == ')' && current == '(') continue;
                if( i == ']' && current == '[') continue;
                if( i == '}' && current == '{') continue;

                return false;
            }

        }

        if(sta.empty()) return true;
        return false;
    }
};

// Valentin Alejandro Ruiz Ortiz

// https://leetcode.com/problems/valid-parentheses/description/