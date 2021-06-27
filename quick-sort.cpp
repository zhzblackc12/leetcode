#include <iostream>
#include <vector>


using namespace std;

//! 快排主要是分两步  
//! 1. 分区
//! 2. 递归调用  
//! 思路是相当于军训排队，要求中间散开，比指定的人高的排左边，比指定矮的人排右边
//! 下面默认是最后一个元素作为pivotValue

int partition(vector<int>& nums, int p, int r)
{
    if (nums.empty() || 1 == nums.size())
    {
        return -1;
    }

    if (p >= r)
    {
        return -1;
    }

    if (p  < 0)
    {
        return -1;
    }

    if (r >= nums.size())
    {
        return -1;
    }

    int i = p - 1;
    int x = nums[r];
    for (int j = p; j < r; j++)
    {
        if (nums[j] < x)
        {
            i++;
            if (i != j)
            {
                swap(nums[i], nums[j]);
            }
        }
    }

    swap(nums[r], nums[i + 1]);
    return i+1;    
}

void quick_sort(vector<int>& nums, int p, int r)
{
    if (p >= r)
    {
        return;
    }

    // for (auto& item : nums)
    // {
    //     cout << item << " ";
    // }
    // cout << endl;

    int foundIndex = partition(nums, p, r);
    // for (int i = p; i <= r; ++i)
    // {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;


    // cout << "p: " << p << " r: " <<  r << " foundIndex: " << foundIndex << endl;
    quick_sort(nums, p, foundIndex - 1);
    quick_sort(nums, foundIndex + 1, r);
}

void test_partition()
{
   vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 5};
    for (auto& item : nums)
    {
        cout << item << " ";
    }
    cout << endl;

    int foundIndex = partition(nums, 0, nums.size() - 1);
    for (auto& item : nums)
    {
        cout << item << " ";
    }

    cout << endl;
    cout << "foundIndex: "  << foundIndex;
    cout << endl;
    
}


void test_quick_sort()
{
   vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 5};
    for (auto& item : nums)
    {
        cout << item << " ";
    }
    cout << endl;

    quick_sort(nums, 0, nums.size() - 1);
    for (auto& item : nums)
    {
        cout << item << " ";
    }

    cout << endl;
}

int main(int argc, char* argv[])
{
    test_quick_sort();
    return 0;
}