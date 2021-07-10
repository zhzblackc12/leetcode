#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        _timeMap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& item = _timeMap[key];
        pair<int, string> p = {timestamp, string({127})};
        auto foundIter = upper_bound(item.begin(), item.end(), p);
        if (foundIter != item.begin())
        {
            return (foundIter - 1)->second;
        }

        return "";
    }

private:
    unordered_map<string, vector<pair<int, string>>>  _timeMap;
};

void test()
{
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo",  1) << " bar " << endl;
    cout << timeMap.get("foo",  3) << " bar " << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo",  4) << " bar2 " << endl;
    cout << timeMap.get("foo",  4) << " bar2 " << endl;
    
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}