#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>


using namespace std;
class Solution {
private:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        auto get = [&](string& status) -> vector<string> {
            vector<string> ret;
            int x = status.find('0');
            for (int y : neighbors[x]) {
                swap(status[x], status[y]);
                ret.push_back(status);
                swap(status[y], status[x]);
            }

            return ret;
        };

        string initial;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                initial += char(board[i][j] + '0');
            }
        }

        if (initial == "123450") {
            return 0;
        }

        queue<pair<string, int>> q;
        q.emplace(initial, 0);
        unordered_set<string> visitedSet = {initial};

        while (!q.empty()) {
            auto statusPair = q.front();
            auto status = statusPair.first;
            auto step = statusPair.second;
            // auto [status, step] = q.front();
            q.pop();
            for (auto&& nextStatus : get(status)) {
                if (visitedSet.count(nextStatus) != 0) {
                    continue;
                }

                if (nextStatus == "123450") {
                    return step + 1;
                }

                q.emplace(nextStatus, step + 1);
                visitedSet.insert(move(nextStatus));
            }
        }

        return -1;
    }
};



int main(int argc, char* argv[])
{
    vector<vector<int>>board = {{4,1,2},{5,0,3}};
    Solution solution;
    cout << solution.slidingPuzzle(board) << endl;
    return 0;
}