#include <iostream>
#include <vector>
using namespace std;

class PostOrder
{
private:
    int preIndex;

    string acc;

    // Used to Search in the vector for the index of the next item in the preOrder

    int search(vector<char> v, int startIn, int endIn, char data)
    {
        int i = 0;
        for (i = startIn; i < endIn; i++)
        {
            if (v[i] == data)
            {
                return i;
            }
        }
        return i;
    };

    void getPostOrder(vector<char> preOrder, vector<char> inOrder, int inStrt, int inEnd)
    {
        // Safe check
        if (inStrt > inEnd)
        {
            return;
        }

        int inIndex = search(inOrder, inStrt, inEnd, preOrder[preIndex++]);

        // We traverse the left tree
        getPostOrder(inOrder, preOrder, inStrt, inIndex - 1);

        // We traverse the right tree
        getPostOrder(inOrder, preOrder, inIndex + 1, inEnd);

        acc += inOrder[inIndex];
    };
    void getCharFromString(string str, vector<char> &v)
    {
        for (int x = 0; x < str.length(); x++)
        {
            v.push_back(str[x]);
        }
    };

public:
    void printPostOrder(string preOrder, string inOrder)
    {
        vector<char> pre;
        getCharFromString(preOrder, pre);

        vector<char> in;
        getCharFromString(inOrder, in);

        int len = inOrder.length();

        getPostOrder(pre, in, 0, len - 1);

        cout << acc << " ";

        preIndex = 0;
        acc = "";
    }

    PostOrder()
    {
        preIndex = 0;
        acc = "";
    };
};

int main()
{
    PostOrder *po = new PostOrder();

    po->printPostOrder("ABFGC", "FBGAC");

    po->printPostOrder("ZDFAS", "GDSZD");

    po->printPostOrder("ERWQE", "HFBFD");

    po->printPostOrder("EQWTK", "WQREW");

    po->printPostOrder("PPOIO", "REWFK");
}
