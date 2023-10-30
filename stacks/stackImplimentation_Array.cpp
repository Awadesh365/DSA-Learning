#include <bits/stdc++.h>
using namespace std;

class Stack
{

    // Properties
public:
    int *arr;
    int top;
    int size;

    // behaviour
    // Contructor
    Stack(int size)
    {
        this->size = size;
        arr = new int[size]; // creation of object
        top = -1;
    }

    void push(int element)
    {
        // check for overflow condition, so top will always equal or smaller than size allocated
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            showError("OverFlow");
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            showError("UnderFlow");
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            showError("undefined behaviour"); // when stack is empty and still calling the peek function
            return -1;
        }
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void showError(string errorType)
    {
        cout << (errorType) << endl;
    }
};

int main()
{
    Stack st(5);

    st.peek();
    st.pop();

    for (int i = 0; i < 5; i++)
        st.push(i);

    cout << st.peek() << endl;
    st.push(5);
    cout << st.isEmpty() << endl;

    /*
    undefined behaviour
    UnderFlow
    4
    OverFlow
    0
    */
}