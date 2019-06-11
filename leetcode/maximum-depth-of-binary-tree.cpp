#include <iostream>

class TreeNode {
public:
    TreeNode(int x)
    : val(x),
    left(nullptr),
    right(nullptr)
    {

    }

    int val;
    TreeNode* left;
    TreeNode* right;


};

// TODO: Is there another way of solving this without using a global variable?
int gMaxCnt;

void traverse(TreeNode* root, int cnt)
{
    ++cnt;

    if(root->left)
        traverse(root->left, cnt);

    if(root->right)
        traverse(root->right, cnt);

    if(cnt > gMaxCnt)
        gMaxCnt = cnt;

    --cnt;
}

int maxDepth(TreeNode* root) 
{
    if(!root)
        return 0;

    traverse(root, 0);
    return gMaxCnt;
}

int main(int argc, char* argv[])
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int res = maxDepth(root);

    return 0;
}

