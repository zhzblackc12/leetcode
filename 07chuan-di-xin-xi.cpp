#include <iostream>
#include <string>
#include <functional>
#include <vector>


using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> edges(n);
        for (auto& edge : relation) {
            int src = edge[0];
            int dst = edge[1];
            edges[src].push_back(dst);
        }

        int nums = 0;
        function<void(int, int)> dfs = [&](int index, int step){
            if (step == k) {
                if (index == n - 1) {
                    nums++;
                }

                return;
            }

            if (index >= n) {
                return;
            }

            for (int dst : edges[index]) {
                dfs(dst, step + 1);
            }
        };

        dfs(0, 0);
        return nums;
    }
};


void test()
{
    int n = 5, k = 3;
    vector<vector<int>>  relation = {{0,2},{2,1},{3,4},{2,3},{1,4},{2,0},{0,4}};

    Solution solution;
    int nums = solution.numWays(n, relation, k);
    cout << nums << " 3 " << endl;
    
    // relation = {{0,2},{2,1}};
    // nums = solution.numWays(n, relation, k);
    // cout << nums << " 3 " << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}