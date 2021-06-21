// constructing bitsets
#include <iostream>       
#include <string>        
#include <bitset>        
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63; // 用位运算取出高 4 位和低 6 位
            std::bitset<1024> bar(i);
            if (h < 12 && m < 60 && bar.count() == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};

int main ()
{
    Solution solution;
    vector<string> ans = solution.readBinaryWatch(1);
    for (auto& item : ans)
    {
        cout << item << " , ";
    }
    
    return 0;
}
