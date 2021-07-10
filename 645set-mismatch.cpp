#include <iostream>
#include <string>
#include <vector>

//! 1. 第一反应是多叉树的前序遍历
//! 网上有多叉转二叉的办法  就是把兄弟放在左边，孩子放右边
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> numList(nums.size(), 0);
        for (auto& item : nums)
        {
            numList[item - 1]++;
        }

        vector<int> retList(2, 0);
        for (int i = 0; i < numList.size(); i++)
        {
            int item = numList[i];
            if (item > 1)
            {
                retList[0] = i + 1;
            }

            if (item == 0)
            {
                retList[1] = i + 1;
            }
        }
        return retList;        
    }
};

void test()
{
    Solution solution;
    vector<int> nums = {1,2,2,4};
    vector<int> expectNums = {2, 3};
    for (auto &item : expectNums)
    {
        cout << item << " ";
    }
    cout << endl;

    vector<int> retList = solution.findErrorNums(nums);
    for (auto &item : retList)
    {
        cout << item << " ";
    }

    cout << endl;
}


int main(int argc, char* argv[])
{
    test();
    return 0;
}