#include <iostream>
#include <string>
#include <vector>

using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.

 
class Solution {
public:

    string backSpace(string s) {
        if (s.empty()) {
            return s;
        }

        char buffer[200];
        int bufferIndex = 0;
        int spaceCnt = 0;
        for (int i = s.size() - 1; i >=  0; --i)
        {
            if (s[i] == '#') {
                ++spaceCnt;
            }
            else
            {
                if (0 == spaceCnt)
                {
                    buffer[bufferIndex++] = s[i];
                }
                else
                {
                    --spaceCnt;
                }
            }
        }

        buffer[bufferIndex++] = '\0';
        return string(buffer);
    }

    bool backspaceCompare(string s, string t) {
        string subS = backSpace(s);
        string subT = backSpace(t);
        return 0 == subS.compare(subT);        

    }
};


int main(int argc, char* argv[])
{
    Solution solution;
    cout << solution.backspaceCompare("ab#c", "ad#c") << " " << true << endl; // true
    cout << solution.backspaceCompare("ab##", "c#d#") << " " << true << endl; // true
    cout << solution.backspaceCompare("a##c", "#a#c") << " " << true << endl; // true
    cout << solution.backspaceCompare("a#c", "b") << " " << false << endl; // false
    return 0;
}