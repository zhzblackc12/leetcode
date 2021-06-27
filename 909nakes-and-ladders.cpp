#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        len = board.size();
        auto get = [&](vector<vector<int>>& board) -> vector<int> {
            vector<int> ret(len * len + 1, 0);
            bool bStartLeft = true;
            int index = 1;
            for (int i = len - 1; i >= 0; i--) {
                for (int j = (bStartLeft ? 0 : len - 1); bStartLeft ? j < len : j >= 0; j += bStartLeft ? 1 : -1) {
                    ret[index++] = board[i][j];
                }
                bStartLeft = !bStartLeft;
            }

            return ret;
        };

        auto nums = get(board);
        for (auto& item : nums)
        {
            cout << item << " ";
        }
        
        return 0;
        // return bfs(nums);
    }

    int bfs(const vector<int>& nums) {
        queue<pair<int, int>>        waitQueue;
        unordered_set<int>           visitedSet;
        waitQueue.push({1, 0});
        while (!waitQueue.empty()) {
            auto statusPair = waitQueue.front();
            auto status = statusPair.first;
            auto step = statusPair.second;
            waitQueue.pop();

            if (status == len * len)
            {
                return step;
            }
            
            for (int i = 0; i < 6; i++)
            {
                int index = status + i;
                if (index < 0 || index > len * len) {
                    continue;
                }

                if (nums[index] != -1) {
                    index = nums[index];
                }

                if (visitedSet.count(index) != 0) {
                    continue;
                }

                waitQueue.push(make_pair(index, step + 1));
                visitedSet.insert(index);
            }
        }

        return -1;
    }


private:
    int     len;
  
};



int main(int argc, char* argv[])
{
    vector<vector<int>>board = {
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,35,-1,-1,13,-1},
                            {-1,-1,-1,-1,-1,-1},
                            {-1,15,-1,-1,-1,-1}};

    Solution solution;
    // cout << solution.snakesAndLadders(board) << " expect: 4"<< endl;

    board = {{-1,1,2,-1},{2,13,15,-1},{-1,10,-1,-1},{-1,6,2,8}};
    cout << solution.snakesAndLadders(board) << " expect: 2"<< endl;
    return 0;
}