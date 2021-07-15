#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        
        for (auto& item : buildings) 
        {
            all.insert({item[0], -item[2]}); // critical point, left corner
            all.insert({item[1], item[2]}); // critical point, right corner
        }
        
        multiset<int> heights({0}); // 保存当前位置所有高度。
        vector<int> last = {0, 0}; // 保存上一个位置的横坐标以及高度
        for (auto& p : all) 
        {
            if (p.second < 0)
            {
                heights.insert(-p.second); // 左端点，高度入堆
            }
            else
            {
                heights.erase(heights.find(p.second)); // 右端点，移除高度
            }
            
            // 当前关键点，最大高度
            auto maxHeight = *heights.rbegin();
            // 当前最大高度如果不同于上一个高度，说明这是一个转折点
            if (last[1] != maxHeight) 
            {
                // 更新 last，并加入结果集
                last[0] = p.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        
        return res;
    }
};


void test()
{
    vector<vector<int>> buildings = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution solution;
    auto ret = solution.getSkyline(buildings);
    for (auto &item : ret)
    {   
        cout << "{" <<item[0] << "," << item[1] << "}" << ",";        
    }

    cout << endl;
    
    vector<vector<int>> out =  {{2,10},{3,15},{7,12},{12,0},{15,10},{20,8},{24,0}};
    for (auto &item : out)
    {   
        cout << "{" <<item[0] << "," << item[1] << "}" << ",";        
    }
    cout << endl;

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

