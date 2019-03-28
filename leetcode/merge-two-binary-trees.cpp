#include <iostream>

/**
 *Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
{
    if (!t1 && !t2)
        return nullptr;

    if (!t1)
    {
        return t2;
    }

    if (t2)
    {
        t1->val += t2->val;
    }
    else
    {
        return t1;
    }

    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

int main (int argc, char* argv[])
{
    TreeNode* input_left = new TreeNode(2);
    TreeNode* input_right = new TreeNode(3);

    TreeNode* res = mergeTrees(input_left, input_right);

    return 0;
}
