#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tempNums1(nums1);
        sort(tempNums1.begin(), tempNums1.end());
        int maxNum = 0;
        int sum = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % mod;
            int j = lower_bound(tempNums1.begin(), tempNums1.end(), nums2[i]) - tempNums1.begin();
            if (j < nums1.size())
            {
                maxNum = max(maxNum, diff - (tempNums1[j] - nums2[i]));
            }
            
            if (j > 0)
            {
                maxNum = max(maxNum, diff - (nums2[i] - tempNums1[j - 1]));
            }
        }

        return (sum - maxNum + mod) % mod;
        
    }

    const int mod = 1'000'000'007;
};

int test()
{
    Solution newSolution;
    vector<int> nums1 = {1,7,5};
    vector<int> nums2 = {2,3,5};
    int sum = newSolution.minAbsoluteSumDiff(nums1, nums2);
    cout << sum << " " << 3 << endl;
    return 0;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}