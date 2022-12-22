#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
void createTree(TreeNode* node, int i, vector<string>& arr) {
    if (node != nullptr) {
        if (2 * i + 1 < arr.size()) {
            if (arr[2 * i + 1] == "null")
                node->left = nullptr;
            else
                node->left = new TreeNode(stoi(arr[2 * i + 1]));
            createTree(node->left, 2 * i + 1, arr);
        }


        if (2 * i + 2 < arr.size()) {
            if (arr[2 * i + 2] == "null")
                node->right = nullptr;
            else
                node->right = new TreeNode(stoi(arr[2 * i + 2]));
            createTree(node->right, 2 * i + 2, arr);
        }
    }
}
void flip(TreeNode*node)
{
    //node doesn't exist
    if (node == NULL){
        return;
    }
    else
    {
        TreeNode * temp;
        flip(node->left);
        flip(node->right);
        //swapping two nodes using temp.
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}



TreeNode* levelOrderCreateTree(vector<string>& arr) {
    if (arr.size() == 0)
        return nullptr;
    TreeNode* head = new TreeNode(stoi(arr[0]));
    createTree(head, 0, arr);
    return head;
}
void printInorder(TreeNode* tree){
    if(tree == nullptr)
        return;
    printInorder(tree->left);
    cout<<tree->val<<' ';
    printInorder(tree->right);
}


int main(){
    vector<string> arr1={"1","3","2","4","5"};
    vector<string> arr2={"7","8","6"};
    vector<string> arr3={"28","34","2","10","5"};
    vector<string> arr4={"1","8","22","30"};
    vector<string> arr5={"20","3","5","7","5"};

    int n;
    while (n--) {


    }
    TreeNode* test1 = levelOrderCreateTree(arr1);
    TreeNode* test2 = levelOrderCreateTree(arr2);
    TreeNode* test3 = levelOrderCreateTree(arr3);
    TreeNode* test4= levelOrderCreateTree(arr4);
    TreeNode* test5 = levelOrderCreateTree(arr5);

cout<<"print the test1 before flip"<<endl;
    printInorder(test1);
    cout << '\n';
    flip(test1);
    cout<<"print the test1 after flip"<<endl;
    printInorder(test1);
    cout<<"\nprint the test2 before flip"<<endl;
    printInorder(test2);
    cout << '\n';
    flip(test2);
    cout<<"print the test2 after flip"<<endl;
    printInorder(test2);
    cout<<"\nprint the test3 before flip"<<endl;
    printInorder(test3);
    cout << '\n';
    flip(test3);
    cout<<"print the test3 after flip"<<endl;
    printInorder(test3);
    cout<<"\nprint the test4 before flip"<<endl;
    printInorder(test4);
    cout << '\n';
    flip(test4);
    cout<<"print the test4 after flip"<<endl;
    printInorder(test4);
    cout<<"\nprint the test5 before flip"<<endl;
    printInorder(test5);
    cout << '\n';
    flip(test5);
    cout<<"print the test5 after flip"<<endl;
    printInorder(test5);
}
