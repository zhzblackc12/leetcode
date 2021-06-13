#include <iostream>
#include <string>
#include <stack>

using namespace std;
    
class Solution {
public:
    bool isValid1(string s) {
        if (s.empty()){
            return true;
        }

        stack<char> par;
        int iStackIndex = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
            {
                par.push(s[i]);
            }
            else
            {
                if (par.empty())
                {
                    return false;
                }

                if (s[i] == ')' && par.top() != '(')
                {
                    return false;
                }
                else if (s[i] == ']' && par.top() != '[')
                {
                    return false;
                }
                else if (s[i] == '}' && par.top() != '{')
                {
                    return false;
                }
                par.pop();
            }
        }
        
        return par.empty();
    }

    bool isValid(string s) {
        if (s.empty()){
            return true;
        }

        int iStackLen = 0;
        int iStackTopIndex = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
            {
                iStackTopIndex = i;
                ++iStackLen;
            }
            else
            {
                if (0 == iStackLen)
                {
                    return false;
                }

                if (s[i] == ')' && s[iStackTopIndex] != '(')
                {
                    return false;
                }
                else if (s[i] == ']' && s[iStackTopIndex]  != '[')
                {
                    return false;
                }
                else if (s[i] == '}' && s[iStackTopIndex]  != '{')
                {
                    return false;
                }
                --iStackLen;

                if (0 != iStackLen)
                {
                    iStackTopIndex = iStackTopIndex - 1;
                }
            }
        }
        
        return 0 == iStackLen;
    }
};


int main(int argc, char* argv[])
{
    // std::string  testString = "()[]{}";
    std::string  testString = "{[]}";

    Solution solution;
    bool bValid = solution.isValid(testString);
    std::cout<< bValid  << std::endl;
    return 0;
}