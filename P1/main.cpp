#include <iostream>
#include<string>
#include<cstring>

using namespace std;


template <class t>
struct node{
    t data;
    node<t>* next;
    node<t>* prev;
};


template <class t>
class stack{
private:
node<t>* topstack;
int count;
public:
    stack ()//A default constructor
    {
        topstack=0;
        count=0;
            }
void push(t elem)//A function to push the new node at the top of the stack
{
    node<t>*newnode=new node<t>;//initializing a new node
    newnode->data=elem;
    newnode->next=0;//the new node will point to null
    if (topstack==0){
        topstack=newnode;//if the stack is empty then the top node will be the new node
        count++;
    }
    else{
    //in case there is a node or nodes already in the stack
    topstack->next=newnode;//the top node in the stack will point to the new node
    newnode->prev=topstack;
    topstack=newnode;
    count++;//the size of the stack will be incremented after pushing the new node into the stack
    }
}


//A function to remove the top element from the stack
t pop(){
 if (topstack ==0){
    //Throw exception if the stack is empty
      throw new out_of_range ("stack is empty");}
else{
node<t> *temp;
t value=topstack->data;
temp=topstack;
if(count==1){
  topstack=0;
}
else{
topstack=topstack->prev;}
delete temp;
count--;//decrement the size of the stack when we remove the node
return value;//returning the value of the node popped
}
}


t top(){
if (topstack== 0){
      throw new out_of_range ("stack is empty");}
else{
        return topstack->data;//return the value of top node
}
}

bool empty(){
return (topstack==0);
}

int size(){
    return count;//return the size of the stack
}


};




string Simplify(string str){
    stack<string> stack1;
    stack <string>stack2;// a stack which will contain the reverse of stack1
    string directory;
    string res;
    res.append("/");
    for(int i=0;i<str.length();i++)
        {
         directory.clear();//clearing the string from it preparing it for a new directory name
         //if there is / in the string we will skip it
         while(str[i]=='/'){
            i++;
         }
         while(str[i]!='/'&&i<str.length()){
            directory+=str[i];
            i++;
         }
        if (directory=="..") {
                //pop the top element in the stack if there is ".." in the directory
            if (!stack1.empty())
                stack1.pop();
        }
        else if (directory==".")
            continue;
         else if(directory.length() != 0){
            stack1.push(directory);
            }
            }
         while(!stack1.empty()){
            stack2.push(stack1.top());//pushing the element which is in stack 1 into stack 2
            stack1.pop();//popping the the node pushed in stack 2 from stack 1
         }
         while(!stack2.empty()){
             //stack2 contains the result
            string temp=stack2.top();
             if (stack2.size() != 1)
                res.append(temp + "/");
            else
                res.append(temp);
            stack2.pop();
         }
         return res;

}





int main()
{
try{
    string str1="/home/";
    string res1 = Simplify(str1);
    cout<<"input: "<<str1<<endl;
    cout <<"output: "<< res1<<endl;
    cout<<"-------------"<<endl;
     string str2="/../";
    string res2 = Simplify(str2);
    cout<<"input: "<<str2<<endl;
    cout <<"output: "<< res2<<endl;
    cout<<"-------------"<<endl;
     string str3="/a/./b/../../c/";
    string res3 = Simplify(str3);
    cout<<"input: "<<str3<<endl;
    cout <<"output: "<< res3<<endl;
     cout<<"-------------"<<endl;

     string str4="/home//foo/";
    string res4 = Simplify(str4);
    cout<<"input: "<<str4<<endl;
    cout <<"output: "<< res4<<endl;
    cout<<"-------------"<<endl;

    string str5=" /a/../";
    string res5 = Simplify(str5);
    cout<<"input: "<<str5<<endl;
    cout <<"output: "<< res5<<endl;
    cout<<"-------------";

    }
catch(...){
    cout<<"exception!";
    }
    return 0;
}


