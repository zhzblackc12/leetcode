#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>

//! 1. 第一反应是多叉树的前序遍历
//! 网上有多叉转二叉的办法  就是把兄弟放在左边，孩子放右边
using namespace std;
class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king{move(kingName)} {

    }
    
    void birth(string parentName, string childName) {
        edges[move(parentName)].push_back(move(childName));
    }
    
    void death(string name) {
        dead.insert(move(name));
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;

        function<void(const string&)>  getOrder = [&](const string& name) {
            if (0 != dead.count(name)) {
                return;
            }

            ans.push_back(name);

            if (0 == edges.count(name)) {
                return;
            }

            for (const string& childName : edges[name]) {
                getOrder(childName);
            }
        };

        getOrder(king);
        return ans;
    }

private:
    unordered_map<string, vector<string>>   edges;
    unordered_set<string>                   dead;
    string                                  king;
};



int main(int argc, char* argv[])
{
    return 0;
}