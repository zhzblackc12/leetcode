#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0;
        int nums = 0;
        for (auto& cost : costs) {
            if (sum + cost > coins) {
                break;
            }
            sum += cost;
            nums++;
        }

        return nums;        
    }
};


void test()
{
    Solution solution;
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    int nums = solution.maxIceCream(costs, coins);
    cout << nums << " 4" << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}