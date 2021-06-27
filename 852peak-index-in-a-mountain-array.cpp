#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int beginIndex = 0, endIndex = arr.size() -1;
        while (beginIndex < endIndex)
        {
            int mid = beginIndex + (endIndex - beginIndex) / 2;
            if (mid > 0 && mid < arr.size() -1 && arr[mid + 1] < arr[mid] && arr[mid] > arr[mid -1])
            {
                return mid;
            }

            if (mid < arr.size() -1 && arr[mid + 1] > arr[mid])
            {
                beginIndex = mid + 1;
            }
            else if (mid > 0 && arr[mid] < arr[mid -1])
            {
                endIndex = mid - 1;
            }
        }
        return beginIndex;
    }

    void test()
    {
        vector<int> case1Vec{3,5,3,2,0};
        cout << peakIndexInMountainArray(case1Vec) << " " << 1 << endl;

        // vector<int> case2Vec{0,2,1,0};
        // cout << peakIndexInMountainArray(case2Vec) << " " << 1 << endl;
        
        // vector<int> case3Vec{0,10,5,2};
        // cout << peakIndexInMountainArray(case3Vec) << " " << 1 << endl;

        // vector<int> case4Vec{3,4,5,1};
        // cout << peakIndexInMountainArray(case4Vec) << " " << 2 << endl;

        // vector<int> case5Vec{24,69,100,99,79,78,67,36,26,19};
        // cout << peakIndexInMountainArray(case5Vec) << " " << 2 << endl;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    solution.test();
    return 0;
}