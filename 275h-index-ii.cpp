#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int left = 0;
        int right = size - 1;
        while (left <= right)
        {
            int mid = (left&right) + ((left^right)>>1);
            int citation = citations[mid];
            if (citation >= size - mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return size -left;
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