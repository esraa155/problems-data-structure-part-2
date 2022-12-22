#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};
class Solution{
public:
    bool isMirror(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 && root2 && root1->val == root2->val)
            return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
        return false;
    }
    bool isSymmetric(TreeNode* root)
    {
        return isMirror(root, root);
    }
    };
int main() {
    Solution test1;
    TreeNode *r1 = new TreeNode(1);
    r1->left = new TreeNode(2);
    r1->left->left = new TreeNode(3);
    r1->left->right = new TreeNode(4);
    r1->right = new TreeNode(2);
    r1->right->left = new TreeNode(4);
    r1->right->right = new TreeNode(3);
    bool a=test1.isSymmetric(r1);
    if (a==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;

    Solution test2;
    TreeNode *r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->left->right = new TreeNode(3);
    r2->right = new TreeNode(2);
    r2->right->right = new TreeNode(3);
    bool b=test2.isSymmetric(r2);
    if (b==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;

    Solution test3;
    TreeNode *r3 = new TreeNode(4);
    r3->left = new TreeNode(9);
    r3->left->left = new TreeNode(2);
    r3->left->right = new TreeNode(5);
    r3->right = new TreeNode(6);
    r3->right->left = new TreeNode(5);
    r3->right->right = new TreeNode(2);
    bool c=test3.isSymmetric(r3);
    if (c==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;

}
