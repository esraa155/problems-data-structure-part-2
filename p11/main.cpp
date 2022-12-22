#include <bits/stdc++.h>
using namespace std;
//Node class.
template<class T>
class BSTNode
{
public:
    T key;
    BSTNode* right;//greater nodes on right.
    BSTNode* left;//smaller nodes on left.
public:
    //setting initial values to left and right pointers.
    BSTNode()
    {
        right = NULL;
        left = NULL;
    }
    //to be able to send data only as a parameter.
    BSTNode(T DATA, BSTNode* right = 0, BSTNode* left = 0)
    {
        key = DATA;
        this->right = right;
        this->left = left;
    }
};

//class with all used functions .
template<class T>
class BSTFCI
{
public:
    //Base node in BST.
    BSTNode<T>* root;
public:
    BSTFCI()
    {
        root = NULL;
    }

    //Recursion Function - Inserting new node to the binary search tree.
    BSTNode<T>* Insert_Node(T DATA, BSTNode<T>* node)
    {
        //InCase there is no node create root node.
        if (node == NULL)
        {
            node = new BSTNode<T>;
            node->key = DATA;
            node->left = node->right = NULL;
        }

            //InCase given key > node key -- > Go right subtree.
        else if (DATA > node->key)
            node->right = Insert_Node(DATA, node->right); //Calling it self.

            //InCase given key < node key -- > Go left subtree.
        else if (DATA < node->key)
            node->left = Insert_Node(DATA, node->left);

        return node;
    }

    //Function to call insert function.
    void Insert(T DATA)
    {
        root = Insert_Node(DATA, root);
    }

    //Printing nodes left then root then right.
    void PrintTreeInOrder(BSTNode<T> * node)
    {
        if (node != NULL)
        {
            PrintTreeInOrder(node->left);
            cout << node->key<<setw(3) ;
            PrintTreeInOrder(node->right);
        }
    }

    //Function to call PrintTreeInOrder function.
    void PrintTreeInOrder()
    {
        PrintTreeInOrder(root);
        cout << endl<<endl;
    }

    ///Problem#1------------------------------------------------------------------
    //Function returns true if BST balanced.
    template<class T2>
    friend bool isBalanced( BSTNode<T2> *root);


    ///Problem#2------------------------------------------------------------------

    //Recursion Function to check if two subtrees are identical.
    template <typename T2>
    friend bool areIdentical(BSTNode<T2> * root1, BSTNode<T2> * root2);

    template <typename T2>
    friend bool isSubtree(BSTNode<T2> *t, BSTNode<T2> *S);

    template <typename T2>
    friend bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2);


    ///Problem#3------------------------------------------------------------------

    //function to print all nodes in the given range.
    template <typename T2>
    friend void PrintRange(BSTNode<T2> *root, int k1, int k2);

};

//function to calculate the height of each node .
template<class T2>
int height(BSTNode<T2>* node)
{
    if(node == NULL)
        return 0;
    //height = 1 + max of left height and right heights
    return 1 + max(height(node->left),height(node->right));
}

//Function returns true if BST balanced.
template<class T2>
bool isBalanced( BSTNode<T2> *root)
{
    int lh; //hight of left subtree.
    int rh; //hight of right subtree.

    if(root == NULL)
        return 1;

    //Hight of left and right subtree.
    lh = height(root->left);
    rh = height(root->right);
    //difference between left and right must be less than or equal to 1.
    if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    //tree is not balanced.
    return 0;
}

//Recursion Function to check if two nodes are identical.
template<class T2>
bool areIdentical(BSTNode<T2> * root1, BSTNode<T2> *root2)
{
    if (root1 == NULL && root2 == NULL)     //Both equal NULLs
        return true;

    if (root1 == NULL || root2 == NULL)     //if both nodes are not equal
        return false;

    return (root1->key == root2->key &&                 //check both nodes are equal
            areIdentical(root1->left, root2->left) &&   //check left nodes are equal
            areIdentical(root1->right, root2->right));  //check right nodes are equal
}

//Recursion Function to check if two nodes are identical.
template<class T2>
bool isSubtree(BSTNode<T2> *t, BSTNode<T2> *S)
{
    if (S == NULL)
        return true;

    if (t == NULL)
        return false;

    if (areIdentical(t, S))
        return true;

    return isSubtree(t->left, S) ||
           isSubtree(t->right, S);
}

template<class T2>
bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2)
{
    return isSubtree(t1->root, t2->root);
}

//function to print all nodes in the given range.
template <typename T2>
void PrintRange(BSTNode<T2> *root, int k1, int k2)
{
    if ( root == NULL )
        return ;
    // If root->data is greater than k1,then data in left subtree.
    if ( k1 < root->key )
        PrintRange(root->left, k1, k2);
    // if root's data lies in range,then prints root's data .
    if ( k1 <= root->key && k2 >= root->key )
        cout<<root->key<<" ";
    // If root->data is less than k1,then data in right subtree.
    if ( k2 > root->key )
        PrintRange(root->right, k1, k2);
}

int main()
{
    BSTFCI <int> * test1 = new BSTFCI <int>();
    BSTFCI <int> * test2 = new BSTFCI <int>();
    BSTFCI <int> * test3 = new BSTFCI <int>();
    BSTFCI <int> * test4 = new BSTFCI <int>();
    BSTFCI <int> * test5 = new BSTFCI <int>();

    test1->Insert(5);
    test1->Insert(7);
    test1->Insert(3);
    test1->Insert(9);
    test1->Insert(2);
    test1->Insert(4);
    test1->Insert(8);
    test1->Insert(10);
    test1->Insert(1);
    cout<<"the tree of test 1"<<endl;
    test1->PrintTreeInOrder();


    test2->Insert(3);
    test2->Insert(4);
    test2->Insert(2);
    test2->Insert(1);
    cout<<"the tree of test 2"<<endl;
    test2->PrintTreeInOrder();

    test3->Insert(9);
    test3->Insert(10);
    test3->Insert(8);
    cout<<"the tree of test 3"<<endl;
    test3->PrintTreeInOrder();


    test4->Insert(20);
    test4->Insert(9);
    test4->Insert(11);
    cout<<"the tree of test 4"<<endl;
    test4->PrintTreeInOrder();


    test5->Insert(5);
    test5->Insert(4);
    test5->Insert(1);
    test5->Insert(2);
    test5->Insert(8);
    cout<<"the tree of test 5"<<endl;
    test5->PrintTreeInOrder();


    if(!isBalanced(test1->root))
        cout <<"test1 unBalanced"<< endl;
    else
        cout <<"test1 Balanced"<< endl;

    if(!isBalanced(test2->root))
        cout <<"test2 unBalanced"<< endl;
    else
        cout <<"test2 Balanced"<< endl;



    if(!isBalanced(test3->root))
        cout <<"test3 unBalanced"<< endl;
    else
        cout <<"test3 Balanced"<< endl;

    if(!isBalanced(test4->root))
        cout <<"test4 unBalanced"<< endl;
    else
        cout <<"test4 Balanced"<< endl;



    if(!isBalanced(test5->root))
        cout <<"test5 unBalanced"<< endl;
    else
        cout <<"test5 Balanced"<< endl;

bool falge=true;
cout<<"\ncheck the test1 is subTree of test2 "<<endl;
if(falge==isSubTree(test1, test2)){
    cout << "Yes" <<endl;}
    else{
        cout <<"No"<<endl;
    }
    cout<<"check the test1 is subTree of test3 "<<endl;
    if(falge==isSubTree(test1, test3)){
        cout << "Yes" <<endl;}
    else{
        cout <<"No"<<endl;
    }
    cout<<"check the test3 is subTree of test5 "<<endl;
    if(falge==isSubTree(test3, test5)){
        cout << "Yes" <<endl;}
    else{
        cout <<"No"<<endl;
    }
    cout<<"check the test5 is subTree of test4 "<<endl;
    if(falge==isSubTree(test5, test4)){
        cout << "Yes" <<endl;}
    else{
        cout <<"No"<<endl;
    }
    cout<<"check the test4 is subTree of test1 "<<endl;
    if(falge== isSubTree(test4, test1)){
        cout << "Yes" <<endl;}
    else {
        cout << "No" << endl;
    }


cout<<endl;
cout<<"print test1 between range(3,6)"<<endl;
    PrintRange(test1->root,3 ,6);
    cout<<endl;
    cout<<"print test2 between range(6,6)"<<endl;
    PrintRange(test2->root, 6,6);
    cout<<"None"<<endl;
    cout<<"print test3 between range(8,15)"<<endl;
    PrintRange(test3->root, 8,15);
    cout<<endl;
    cout<<"print test4 between range(7,22)"<<endl;
    PrintRange(test4->root, 7,22);
    cout<<endl;
    cout<<"print test5 between range(4,6)"<<endl;
    PrintRange(test5->root, 4,6);
    cout<<endl;

    return 0;
}
