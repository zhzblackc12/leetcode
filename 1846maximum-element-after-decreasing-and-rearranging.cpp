#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int item = arr[i];
            if (0 == i)
            {
                arr[i] = 1;
                max = 1;
            }
            else
            {
                if (arr[i] > arr[i - 1])
                {
                    arr[i] = arr[i - 1] + 1;
                    max = arr[i];
                }
            }
        }

        return max;
    }
};

int test()
{
    Solution newSolution;
    vector<int> arr = {1000, 1, 1000};
    int sum = newSolution.maximumElementAfterDecrementingAndRearranging(arr);
    cout << sum << " " << 3 << endl;

    arr = {1,2,3,4,5};
    sum = newSolution.maximumElementAfterDecrementingAndRearranging(arr);
    cout << sum << " " << 5 << endl;
    return 0;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}