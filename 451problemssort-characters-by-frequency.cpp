#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charNumMap;
        for (auto &ch : s)
        {
            charNumMap[ch]++;
        }

        vector<pair<char, int>>   charNumVec;
        for (auto &item : charNumMap)
        {
            charNumVec.emplace_back(item);
        }

        sort(charNumVec.begin(), charNumVec.end(), [](const pair<char, int>& a, const pair<char, int>& b){
            return a.second > b.second;
        });
        
        string ret;
        for (auto &item : charNumVec)
        {
            for (int i = 0; i < item.second; i++)
            {
                ret.push_back(item.first);
            }
        }
        return ret;        
    }
};

void test()
{
    Solution solution;
    string test1 = "tree";
    cout << solution.frequencySort(test1) << " " << test1 << endl;

    string test2 = "cccaaa";
    cout << solution.frequencySort(test2) << " " << test2 << endl;
    
    string test3 = "Aaabb";
    cout << solution.frequencySort(test3) << " " << test3<< endl;

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}