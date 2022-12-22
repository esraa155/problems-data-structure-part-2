#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int start, end, size;
    int *queue;

public:
    Queue(int s)
    {
        start = end = 0;
        size = s;
        queue = new int;
    }

    bool isFull()
    {
        return size == end;
    }

    bool isEmpty()
    {
        return start == end;
    }

    // Adds an item at the end of an array
    void push(int data)
    {
        if (isFull())
        {
            return;
        }
        // insert element at the end of the array
        else
        {
            queue[end] = data;
            end++;
        }
        return;
    }

    // Removes the first item from the array
    void shift()
    {
        if (isEmpty())
        {
            return;
        }

        // Shift all the elements from index 2 till end
        // to the left by one

        // Shifts the array elements removing the first item in the array
        else
        {
            for (int i = 0; i < end - 1; i++)
            {
                queue[i] = queue[i + 1];
            }

            // decrement end
            end--;
        }
        return;
    }

    // get the first item of the queue
    int getFirst()
    {
        if (isEmpty())
        {
            return -1;
        }

        return queue[start];
    }

    ~Queue() { delete[] queue; }
};

int getTimeTaken(int *tickets, int s, int k)
{
    Queue q(s);

    for (int i = 0; i < s; i++)
    {
        q.push(i);
    }

    int time = 0;

    while (q.isEmpty() == false)
    {
        // Gets the first person which their value corresponds to the index of the tickets
        // the person is allowed to buy
        int personPosition = q.getFirst();

        // Moves the first person from the start of the line
        q.shift();

        // If they have tickets we decrease the tickets count and move them to the end of the line
        if (tickets[personPosition] > 0)
        {
            tickets[personPosition]--;
            q.push(personPosition);
            time++;
        }

        // If the choosen person purchasable tickets are empty
        if (tickets[k] == 0)
        {
            break;
        }
    }
    return time;
}

void test(int c)
{
    cout << "Test case " << c << endl;
    int time = 0;
    switch (c)
    {
    case 1:
    {
        int people_num = 3;
        int tickets[people_num] = {2, 3, 2};
        time = getTimeTaken(tickets, people_num, 2);
        cout << "tickets = [2,3,2]" << endl;
        cout << "k = 2" << endl;
        cout << "Should be 6" << endl;
        break;
    }

    case 2:
    {
        int people_num = 4;
        int tickets[people_num] = {5, 1, 1, 1};
        time = getTimeTaken(tickets, people_num, 0);
        cout << "tickets = [5,1,1,1]" << endl;
        cout << "k = 0" << endl;
        cout << "Should be 8" << endl;
        break;
    }
    case 3:
    {
        int people_num = 2;
        int tickets[people_num] = {4, 3};
        time = getTimeTaken(tickets, people_num, 0);
        cout << "tickets = [4,3]" << endl;
        cout << "k = 0" << endl;
        cout << "Should be 7" << endl;
        break;
    }
    case 4:
    {
        int people_num = 4;
        int tickets[people_num] = {2, 1, 3, 2};
        time = getTimeTaken(tickets, people_num, 2);
        cout << "tickets = [2,1,3,2]" << endl;
        cout << "k = 2" << endl;
        cout << "Should be 8" << endl;
        break;
    }
    case 5:
    {
        int people_num = 3;
        int tickets[people_num] = {4, 3, 8};
        time = getTimeTaken(tickets, people_num, 1);
        cout << "tickets = [4,3,8]" << endl;
        cout << "k = 1" << endl;
        cout << "Should be 8" << endl;
        break;
    }
    }

    cout << time << endl;
    cout << "" << endl;
}

int main(void)
{
    test(1);
    test(2);
    test(3);
    test(4);
    test(5);
}
