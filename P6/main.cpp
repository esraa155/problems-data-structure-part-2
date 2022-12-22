#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

class TreeNode{
    //A class for tree node
public:
    char data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(char value) {
       data = value;
       left = NULL;
       right= NULL;
   }
};


class stacknode
{
    //A class for stack
public:
   TreeNode *Nodetree;
   stacknode *snext;
   stacknode(TreeNode*newnode)
   {
       Nodetree= newnode;
       snext = NULL;
   }
};

class ExpTree{
    //A class for expression tree
private:
    stacknode *top;//the topmost node in the stack
public:
    ExpTree(){
        top=NULL;//default constructor
    }
    void clear() {
      top = NULL;//clearing the tree
   }
   void push(TreeNode* Tnode){
       if(top==NULL){
        top=new stacknode(Tnode);
       }
       else{
            stacknode*sptr=new stacknode(Tnode);
            sptr->snext=top;//pushing the new node into the stack
            top=sptr;
            }
            }

    TreeNode *pop(){
    if(top==NULL){
        throw new out_of_range ("empty");
    }
    else{
        TreeNode *Tnode=top->Nodetree;
         top = top->snext;
         return Tnode;
    }
    }


   void insert(char value) {
      if (isDigit(value)) {
         TreeNode *Tnode = new TreeNode(value);
         push(Tnode);//if it is digit ,push it to the stack
      }
      else if (isOperator(value)) {
         TreeNode *Tnode = new TreeNode(value);//if it is operator pop two elements from the stack
         Tnode->left = pop();//the left node of the tree node will hold the same value as the the value popped from the stack
         Tnode->right= pop();//the right node of the tree node will hold the same value as the the second value popped from the stack
         push(Tnode);
      } else {
         cout<<"Not valid"<<endl;
         return;
      }
   }

    bool isDigit(char ch) {
      return ch >= '0' && ch <= '9';
   }

   bool isOperator(char ch) {
      return ch == '+' || ch == '-' || ch == '*' || ch == '/';
   }

   int toDigit(char ch) {
      return ch - '0';
   }

     TreeNode *peek() {
      return top->Nodetree;//return the root
   }

   void CreateTree(string str) {
      for (int i = str.length() - 1; i >= 0; i--)
         insert(str[i]);//creating and building the tree by inserting the elements of the expression
   }

   double evaluation(TreeNode* TNode) {
       //evaluation of the expression
        if (TNode->left == 0 && TNode->right == 0) {
            return toDigit(TNode->data);//if there are no left or right node to the tree node we will return its value
        }
        else {
            double res = 0.0;
            double left = evaluation(TNode->left);
            double right = evaluation(TNode->right);

            char operation = TNode->data;
            switch (operation) {
            case '+':
                res = left + right;
                break;
            case '-':
                res = left - right;
                break;
            case '*':
                res = left * right;
                break;
            case '/':
                res = left / right;
                break;
            }

            return res;
        }
    }

    double TreeEval() {
        return evaluation(peek());
    }

   void printPreorder(TreeNode *Tnode) {
    if(Tnode != NULL){
            //printing the tree in pre order
    cout<<Tnode->data;
    printPreorder(Tnode->left);
    printPreorder(Tnode->right);
    }
}

   void prefix() {
      printPreorder(peek());
   }




};










int main() {
    try{
   string s1,s2,s3,s4,s5;
   ExpTree et1,et2,et3,et4,et5;


   s1="+3*4/82";
   et1.CreateTree(s1);
   cout<<"Prefix expression : ";
   et1.prefix();
   cout<<endl;
   cout<<"Evaluation: "<<et1.TreeEval()<<endl;
   cout<<"----------"<<endl;

   s2="+9*26";
   et2.CreateTree(s2);
   cout<<"Prefix expression : ";
   et2.prefix();
   cout<<endl;
   cout<<"Evaluation: "<<et2.TreeEval()<<endl;
   cout<<"----------"<<endl;

   s3="-+7*45+20";
   et3.CreateTree(s3);
   cout<<"Prefix expression : ";
   et3.prefix();
   cout<<endl;
   cout<<"Evaluation: "<<et3.TreeEval()<<endl;
   cout<<"----------"<<endl;

   s4="-+8/632";
   et4.CreateTree(s4);
   cout<<"Prefix expression: ";
   et4.prefix();
   cout<<endl;
   cout<<"Evaluation: "<<et4.TreeEval()<<endl;
   cout<<"----------"<<endl;

   s5="*+69-31";
   et5.CreateTree(s5);
   cout<<"Prefix expression: ";
   et5.prefix();
   cout<<endl;
   cout<<"Evaluation: "<<et5.TreeEval()<<endl;
   cout<<"----------"<<endl;


    }
    catch (...){
        cout<<"Exception!"<<endl;
    }


return 0;

}






