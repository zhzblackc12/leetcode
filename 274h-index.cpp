#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> nums(n + 1, 0);
        for (auto &item : citations)
        {
            if (item >= n)
            {
                nums[n]++;
            }
            else
            {
                nums[item]++;
            }
        }
        
        int sum = 0;
        for (int i = n; i >= 0; i--)
        {
            sum += nums[i];
            if (sum >= i)
            {
                return i;
            }
        }
        return 0;
    }
};

void test()
{
   vector<int> citations = {3,0,6,1,5};
    Solution solution;
    cout << solution.hIndex(citations) << " " << 3 << endl;;
    
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}