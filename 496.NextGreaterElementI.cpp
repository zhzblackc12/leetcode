#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

// leetcode上关于栈的题目大家可以先做20,155,232,844,224,682,496.

 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        nextGreaterElement(nums2);
        vector<int> retVec(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            auto iter = nextGreaterMap.find(nums1[i]);
            if (iter != nextGreaterMap.end()) 
            {
                retVec[i] = iter->second;
            }
        }
       
        return retVec;
    }

    vector<int> nextGreaterElement(const vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> nextGreaterStack;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!nextGreaterStack.empty() && nums[i] > nextGreaterStack.top())
            {
                nextGreaterStack.pop();
            }
            
            int nextGreaterValue = -1;
            if (!nextGreaterStack.empty())
            {
                nextGreaterValue = nextGreaterStack.top();
            }
            ans[i] = nextGreaterValue;
            nextGreaterStack.push(nums[i]);
            nextGreaterMap.insert(make_pair(nums[i], nextGreaterValue));
        }
        return ans;
    }
private:
    unordered_map<int, int> nextGreaterMap;
};


int main(int argc, char* argv[])
{
    vector<int> nums1 {4,1,2};
    vector<int> nums2 {1,3,4,2};


    vector<int> nums3 {2,4};
    vector<int> nums4 {1,2,3,4};

    // vector<string> ops2{"5","-2","4","C","D","9","+","+"};

    Solution solution;
    // auto ans1 = solution.nextGreaterElement(nums1, nums2);
    // for (auto &item : ans1)
    // {
    //     cout << item << " "; 
    // }
    // cout << endl;
        
    auto ans2 = solution.nextGreaterElement(nums3, nums4); 
    // auto ans2 = solution.nextGreaterElement(nums4); 
    for (auto &item : ans2)
    {
        cout << item << " "; 
    }
    cout << endl;
        
    return 0;
}