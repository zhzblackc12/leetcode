#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        if (s.empty())
        {
            return ans;
        }

        permutation(s, 0);
        return ans;
    }

    void permutation(string s, int begIndex) {
        if (begIndex == s.size() - 1)
        {
            ans.push_back(s);
            return ;
        }

        unordered_set<int> st;
        for (int i = begIndex; i < s.size(); i++)
        {
            if (st.count(s[i]) != 0)
            {
                continue;
            }

            st.insert(s[i]);
            swap(s[i], s[begIndex]);
            permutation(s, begIndex + 1);
            swap(s[i], s[begIndex]);
        }
    }
private:
    vector<string>  ans;
};



int main(int argc, char* argv[])
{
    return 0;
}