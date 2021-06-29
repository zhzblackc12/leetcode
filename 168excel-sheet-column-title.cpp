#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if (columnNumber <= 0) 
        {
            return "";
        }
        
        int num = 26;
        string ret;
        while (columnNumber > 0)
        {
            int mod = (columnNumber - 1)  % num + 1;
            columnNumber = (columnNumber - mod) / num;
            ret.push_back('A' + mod - 1); 
        }

        reverse(ret.begin(), ret.end());
        return ret;        
    }
};


int main(int argc, char* argv[])
{
    Solution solution;
    int testNum = 701;

    cout << solution.convertToTitle(testNum) << " " << " ZY ";
    cout << endl;
    
    testNum = 28;
    cout << solution.convertToTitle(testNum) << " " << " AB ";
    cout << endl;
    
    testNum = 2147483647;
    cout << solution.convertToTitle(testNum) << " " << " FXSHRXW ";
    cout << endl;
    return 0;
}