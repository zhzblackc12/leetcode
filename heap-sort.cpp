#include <iostream>
#include <vector>


using namespace std;

//! 堆排序主要是分三步  大顶堆来说明
//! 1. 堆化 主要是数据下沉
//! 2. 建堆 
//! 3. 排序 这里主要的办法是把取出最大元素放在后面，并且改变数据长度

int len = 0;

//! 堆的性质，左边结点索引是2i, 右边索引是2*index + 1
void max_heapify(vector<int>& nums, int index)
{
    if (nums.empty())
    {
        return;
    }

    int size = len;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int largestIndex = index;
    //! 找出最大值的索引，先和左结点比较，再和右结点比较 
    if (leftIndex < size && nums[leftIndex] > nums[index])
    {
        largestIndex = leftIndex;
    }

    if (rightIndex < size && nums[rightIndex] > nums[largestIndex])
    {
        largestIndex = rightIndex;
    }

    if (largestIndex == index)
    {
        return;
    }
    
    //! 把最大索引结点交换到index
    swap(nums[index], nums[largestIndex]);
    max_heapify(nums, largestIndex);
}

void build_max_heap(vector<int>& nums)
{
    int size = nums.size();
    len = size;
    for (int i = size / 2; i >= 0; i--)
    {
        max_heapify(nums, i);
    }
    
}

void heap_sort(vector<int>& nums)
{
    len = nums.size();
    build_max_heap(nums);
    for (int i = nums.size() - 1; i >= 1; i--)
    {
        swap(nums[0], nums[i]);
        len--;
        max_heapify(nums, 0);
    }
    
}

void test_max_heapify()
{
   vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    for (auto& item : nums)
    {
        cout << item << " ";
    }
    cout << endl;

    max_heapify(nums, 1);
    for (auto& item : nums)
    {
        cout << item << " ";
    }

    cout << endl;
}

void test_build_heap()
{
   vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    for (auto& item : nums)
    {
        cout << item << " ";
    }
    cout << endl;

    build_max_heap(nums);
    for (auto& item : nums)
    {
        cout << item << " ";
    }

    cout << endl;
}

void test_heap_sort()
{
   vector<int> nums = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    for (auto& item : nums)
    {
        cout << item << " ";
    }
    cout << endl;

    heap_sort(nums);
    for (auto& item : nums)
    {
        cout << item << " ";
    }

    cout << endl;
}


int main(int argc, char* argv[])
{
    test_heap_sort();
    return 0;
}