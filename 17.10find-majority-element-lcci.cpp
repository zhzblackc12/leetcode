#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int foundValue = 0;
        for (auto &item : nums)
        {
            if (0 == count)
            {
                foundValue = item;
                count++;
            }
            else
            {
                if (item == foundValue)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }

        if (0 == count)
        {
            return -1;
        }

        int foundCount = 0;
        for (auto &item : nums)
        {
            if (item == foundValue)
            {
                foundCount++;
            }
        }
        
        if (foundCount > nums.size() / 2)
        {
            return foundValue;
        }

        return -1;
    }
};

void test()
{
    Solution solution;

    vector<int> nums = {3,2};
    int ret = solution.majorityElement(nums);
    cout << ret << " " << -1 << endl;

    nums = {2,2,1,1,1,2,2};
    ret = solution.majorityElement(nums);
    cout << ret << " " << -1 << endl;

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}