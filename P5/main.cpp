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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        if(isSameTree(p->left,q->left)&& isSameTree(p->right,q->right))
            return true;
        return false;
    }
};
int main() {
    Solution test1;
    TreeNode *r1 = new TreeNode(1);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(3);
    TreeNode *r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    r2->right = new TreeNode(3);
    bool a=test1.isSameTree(r1,r2);
    if (a==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;
    Solution test2;
    TreeNode *r3 = new TreeNode(1);
    r3->left = new TreeNode(2);
    TreeNode *r4 = new TreeNode(1);
    r4->left = new TreeNode();
    r4->right = new TreeNode(2);
    bool b=test2.isSameTree(r3,r4);
    if (b==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;
    Solution test3;
    TreeNode *r5 = new TreeNode(1);
    r5->left = new TreeNode(2);
    r5->right = new TreeNode(1);
    TreeNode *r6 = new TreeNode(1);
    r6->left = new TreeNode(1);
    r6->right = new TreeNode(2);
    bool c=test2.isSameTree(r5,r6);
    if (c==1) {
        cout << "true" << endl;
    } else
        cout << "false" << endl;
    return 0;
}
