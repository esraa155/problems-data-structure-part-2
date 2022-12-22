#include <bits/stdc++.h>
using namespace std;

bool x;

class node {
public:
	int data;
	node* left;
	node* right;
};

bool foldability(node* root , node* nl , node* nr)
{

	if ( nl == NULL && nr == NULL ) {
		return x=true;
	}

	if (nl == NULL || nr == NULL) {
		return x=false;
	}

	else {
		foldability(root, nl->left, nr->right);
	    foldability(root, nl->right, nr->left);
	}

	return x;
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main(void)
{

	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	root->right->left->left = newNode(6);
	root->left->right->right = newNode(7);


	node* root2 = newNode(1);
	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->right = newNode(4);
	root2->right->left = newNode(5);
	root2->right->left->left = newNode(6);

	node* root3 = newNode(1);
	root3->left = newNode(2);
	root3->right = newNode(3);
	root3->left->right = newNode(4);
	root3->right->left = newNode(5);

	node* root4 = newNode(1);
	root4->left = newNode(2);
	root4->right = newNode(3);
	root4->left->right = newNode(4);



	node* root5 = newNode(0);


	if (foldability(root, root->left , root->right)) {
		cout << "Tree is foldable\n";
	}
	else {
		cout << "Tree is not foldable\n";
	}


	if (foldability(root2, root2->left , root2->right)) {
		cout << "Tree is foldable\n";
	}
	else {
		cout << "Tree is not foldable\n";
	}


	if (foldability(root3, root3->left , root3->right) ) {
		cout << "Tree is foldable\n";
	}
	else {
		cout << "Tree is not foldable\n";
	}


	if (foldability(root4, root4->left , root4->right) ) {
		cout << "Tree is foldable\n";
	}
	else {
		cout << "Tree is not foldable\n";
	}

	if (foldability(root5, root5->left , root5->right)) {
		cout << "Tree is foldable\n";
	}
	else {
		cout << "Tree is not foldable\n";
	}

	return 0;
}
