#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 总结：
// 主要是思维转变，转变成第n个，找n前面有多个几匹配的，这样避免判断太多
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int maxValue = 0;
        for (int i = 0; i < deliciousness.size(); i++)
        {
            int item = deliciousness[i];
            if (item > maxValue)
            {
                maxValue = item;
            }
        }

        int maxSum = 2 * maxValue;        
        int retValue = 0;
        unordered_map<int, int> deliciousMap;
        for (int i = 0; i < deliciousness.size(); i++)
        {
            int item = deliciousness[i];
            for (int sum = 1; sum <= maxSum; sum <<= 1)
            {
                int foundValue = sum - item;
                int count = deliciousMap.count(foundValue) == 0 ? 0 : deliciousMap[foundValue];
                retValue = (retValue + count) %  MOD;                
            }

            deliciousMap[item]++;
        }

        return retValue;
    }

    const int MOD = 1000000007;

};


void test()
{
    Solution solution;
    vector<int> deliciousness = {1,3,5,7,9};
    int nums = solution.countPairs(deliciousness);
    cout << nums << " " << 4 << endl;

    deliciousness = {1,1,1,3,3,3,7};
    nums = solution.countPairs(deliciousness);
    cout << nums << " " << 15 << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}