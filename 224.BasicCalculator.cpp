#include <iostream>
#include <string>
#include <stack>

using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.

 
class Solution {
public:
    int calculate(string s) {
        stack<int> signStack;
        signStack.push(1);
        int res = 0, num = 0, op = 1;
        for (char &ch : s)
        {
            if (ch == ' ') {
                continue;
            }    

            if (ch >= '0' && ch <= '9')
            {
                num = num * 10 + (ch - '0');
                continue;
            }
            res += op * num;
            num = 0;

            if (ch == '+') {
                op = signStack.top();
            } else if (ch == '-') {
                op = -signStack.top();
            } else if (ch == '(') {
                signStack.push(op);
            } else if (ch == ')') {
                signStack.pop();
            } 
        }
        res += op * num;
        return res;
    }
};


int main(int argc, char* argv[])
{
    Solution solution;
    // cout << solution.calculate("1 + 1") << " " << 2 << endl; // true
    // cout << solution.calculate(" 2-1 + 2 ") << " " << 3 << endl; // true
    // cout << solution.calculate("(1+(4+5+2)-3)+(6+8)") << " " << 23 << endl; // true
    // cout << solution.calculate("+48 + -48") << " " << 0 << endl; // false
    cout << solution.calculate("2147483647") << " " << 2147483647 << endl; // false

    
    
    return 0;
}