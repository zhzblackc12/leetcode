#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.

 
class Solution {
public:
     int calPoints(vector<string>& ops) {
         stack<int> numStack;
         for (auto &item : ops)
         {
            if (0 == item.compare("C"))
            {
                numStack.pop();
            }
            else if (0 == item.compare("D"))
            {
                numStack.push(numStack.top() * 2);
            }
            else if (0 == item.compare("+"))
            {
                int popValue = numStack.top();
                numStack.pop();
                int sum = popValue + numStack.top();
                numStack.push(popValue);
                numStack.push(sum);
            }
            else
            {
                int res = 0, num = 0, sign = 1;
                for (char ch : item)
                {
                    if (ch == '-')
                    {
                        sign = -1;
                    }
                    if (ch >= '0' && ch <= '9')
                    {
                        num = num * 10 + (ch - '0');
                        continue;
                    }
                }
                res = sign * num;
                if (res != 0)
                {
                    numStack.push(res);
                }
            }
         }

        int res = 0;
        while (!numStack.empty())
        {
            int popValue = numStack.top();
            numStack.pop();
            res += popValue;
        }

        return res;
    }
};


int main(int argc, char* argv[])
{
    vector<string> ops1{"1","C","-62","-45","-68"};
    // vector<string> ops2{"5","-2","4","C","D","9","+","+"};

    Solution solution;
    cout << solution.calPoints(ops1) << " " << -175 << endl; 
    // cout << solution.calPoints(ops2) << " " << 27 << endl; 
    
    return 0;
}