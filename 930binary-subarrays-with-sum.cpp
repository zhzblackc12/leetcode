#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> sumMap;
        int sum = 0;
        int ret = 0;
        for (auto &item : nums)
        {
            sumMap[sum]++;
            sum += item;
            ret += sumMap[sum - goal];
        }
        return ret;
    }
};


void test()
{
    Solution solution;
    vector<int> nums = {1,0,1,0,1};
    int goal  = 2;
    int sums = solution.numSubarraysWithSum(nums, goal);
    cout << sums << " 4" << endl;

    nums = {0,0,0,0,0};
    goal  = 0;
    sums = solution.numSubarraysWithSum(nums, goal);
    cout << sums << " 15" << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}