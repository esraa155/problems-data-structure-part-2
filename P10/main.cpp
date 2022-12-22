#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data , counter=0;
	Node* left, * right;
};

struct Node *createNode(int data)
{
	Node * new_Node = new Node;
	new_Node->left = NULL;
	new_Node->right = NULL;
	new_Node->data = data;
	return new_Node;
}


struct Node * insert(Node *node, int key)
{
	if (node == NULL)
		return createNode(key);

	if (node->data > key)
		node->left = insert(node->left, key);

	else if (node->data < key)
		node->right = insert(node->right, key);

	return node;
}


void inorder(Node* temp , int &counter)
{
    if (temp == NULL)
        return;

    inorder(temp->left , counter);
	temp->counter = counter++;
    inorder(temp->right, counter);

}

int lessThanK(Node *temp, int k ,int &sum)
{
	if (temp == NULL){
 		return 0;
    }

    if(temp->counter < k) {
        sum = sum + temp->data;
    }

    lessThanK(temp->left , k , sum);
    lessThanK(temp->right, k, sum);
	return sum;
}




int sumOfLessThanK(struct Node *node ,int k){
	int counter=0 , sum=0;
	inorder(node, counter);
	lessThanK(node,k,sum);
    return sum;
}

int main()
{
	Node *root = NULL;
	root = insert(root, 54);
	root = insert(root, 51);
	root = insert(root, 49);
	root = insert(root, 52);
	root = insert(root, 74);
	root = insert(root, 75);
	root = insert(root, 85);
    cout << sumOfLessThanK(root , 3) << endl;


    Node *root2 = NULL;
	root2 = insert(root2, 22);
	root2 = insert(root2, 70);
	root2 = insert(root2, 10);
	root2 = insert(root2, 12);
	root2 = insert(root2, 13);
	root2 = insert(root2, 11);
	root2 = insert(root2, 6);
    cout << sumOfLessThanK(root2 , 4) << endl;

    Node *root3 = NULL;
	root3 = insert(root3, 40);
	root3 = insert(root3, 30);
	root3 = insert(root3, 50);
	root3 = insert(root3, 60);
	root3 = insert(root3, 70);
	root3 = insert(root3, 80);
    root3 = insert(root3, 90);
    cout << sumOfLessThanK(root3 , 4) << endl;

    Node *root4 = NULL;
	root4 = insert(root4, 9);
	root4 = insert(root4, 8);
	root4 = insert(root4, 7);
    cout << sumOfLessThanK(root4 , 3) << endl;

    Node *root5 = NULL;
	root5 = insert(root5, 9);
	root5 = insert(root5, 8);
	root5 = insert(root5, 7);
	root5 = insert(root5, 6);
    cout << sumOfLessThanK(root5 , 3) << endl;

}
