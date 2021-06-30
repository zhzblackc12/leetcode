#include <iostream>
#include <string>
#include <list>


using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        reserialize(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> dataList;
        string str;
        for (auto& ch : data) {
            if (',' == ch) {
                dataList.push_back(str);
                str.clear();
            } else {
                str += ch;
            }
        }  
        return redeserialize(dataList);
    }

private:
    void reserialize(TreeNode* root, string& ans)
    {
        if (nullptr == root)
        {
            ans += "None,";
        }
        else 
        {
            ans += to_string(root->val) + ",";
            reserialize(root->left, ans);
            reserialize(root->right, ans);
        }
    }

    TreeNode* redeserialize(list<string>& dataList)
    {
        if (dataList.front() == "None")
        {
            dataList.erase(dataList.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataList.front()));
        dataList.erase(dataList.begin());
        root->left = redeserialize(dataList);
        root->right = redeserialize(dataList);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void printNode(TreeNode* node)
{
    if (nullptr == node)
    {
        cout << "None ";
        return;
    }

    cout << node->val << ", ";
    printNode(node->left);
    printNode(node->right);
}

void test()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->left->left = nullptr;
    root->left->right = new TreeNode(3);
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;


    root->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = nullptr;
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;


    printNode(root);
    cout << endl;

    Codec codec;

    string str = codec.serialize(root);
    cout << "seriialize: " << str << endl;

    printNode(codec.deserialize(str));
    cout << endl;
}


int main(int argc, char* argv[])
{
    test();
    return 0;
}