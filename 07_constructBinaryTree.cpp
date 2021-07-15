#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


struct BinaryTreeNode
{
    int             value;
    BinaryTreeNode*     left;
    BinaryTreeNode*     right;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (nullptr == preorder || nullptr == inorder || length <= 0)
    {
        return nullptr;
    }


}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->value = rootValue;
    root->left = root->right = nullptr;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder = *startInorder)
        {
            return root;
        }
        else
        {
            throw std::exception("Invalid input.");
        }
    }

    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    if (rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw std::exception("invalid input.");
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLegnth;
    if (leftLength > 0)
    {
        root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder -1);
    }

    if (leftLength < endPreorder - startPreorder)
    {
        root->right = ConstructCore(leftPreorderEnd + 1), endPreorder, rootInorder+1, endInorder);
    }

    return root;

}

int main(int argc, char* argv[])
{
    return 0;
}