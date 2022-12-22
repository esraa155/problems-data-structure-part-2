#include <iostream>

using namespace std;
template <class T>
class queue
{
    T *arr;
    int maxsize;
    T f,r;
    int count;

public:
queue()//default constructor
{
    arr = new T[1000];
    maxsize = 1000;
    f= -1;
    r = -1;
    count = 0;
}

T dequeue()//removing and returning the first element
{
    if(f==-1){
        throw new exception();//throw exception if the queue is empty
    }
    else{
    T x = arr[f];
    f = (f + 1) % maxsize;
    count--;//decrement the size of the queue after the removing the first element
    return x;
    }
}

void enqueue(T item)//inserting the new element at the end of the queue
{
    if(count>maxsize){
        throw new exception();
    }
    else{
    r = (r + 1) % maxsize;
    if(f==-1){
        f=r;
    }
    arr[r] = item;
    count++;//increment the size of the queue
    }
}


T front()
{
    return arr[f];//return  the first element in the queue
}

int size() {
    return count;
}


bool empty() {
    return (size() == 0);
}

~queue() {
    //destructor
    delete[] arr;
}

};


class Stack
{
private:
    queue<int> q;
public:

    void push(int val){
    int s = q.size();
    q.enqueue(val);

    for (int i=0; i<s; i++)
    {
        q.enqueue(q.front());
        q.dequeue();
    //Pop all previous elements and put them after current element
    }
}

    void pop(){
        //remove the top element
    if (q.empty())
        cout << "No elements\n";
    else
        q.dequeue();
}
    int top(){
        //return the top element
    if(!q.empty()){
       return q.front();
        }
}
    bool empty(){
    return (q.empty());
}

};


int main()
{
    try{
    Stack a;
    a.push(1);
    a.push(2);
    a.push(6);
    a.push(10);
    cout<<"top of queue: "<<a.top()<<endl;
    cout<<"After Remove the first element"<<endl;
    a.pop();
    cout<<"top of queue: "<<a.top()<<endl;
    cout<<"After Remove the second element"<<endl;
    a.pop();
    cout<<"top of queue: "<<a.top()<<endl;
    a.pop();
    a.pop();

    }
    catch(...){
        cout<<"Error";

    }
    return 0;
}
