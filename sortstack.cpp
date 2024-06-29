#include <bits/stdc++.h>
using namespace std;
#define n 100
class Stack
{   //Defining Stack and member functions
    int *arr;
    int top;
    public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "No element to pop" << endl;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top == -1;
    }
};
void stacksort(int arr[], int n1)
{   //Recursive Bubble Sort
    for (int i = 0; i < n1 - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    if (n1 - 1 > 1)
    {
        stacksort(arr, n1 - 1);
    }
}
int main()
{
    Stack st;
    int no;
    cout << "Enter number of elements to be inserted in stack: ";
    cin >> no;
    cout << "Enter elements: ";
    for (int i = 0; i < no; i++)
    {   //Scanning and pushing elements into stack
        int val;
        cin >> val;
        st.push(val);
    }
    int arr[no], k = 0;
    while (!st.empty())
    {   //extracting elements from stack and storing in array
        arr[k] = st.peek();
        st.pop();
        k++;
    }
    cout << "Stack before sorting: ";
    for (int l = 0; l < no; l++)
    {
        cout << arr[l] << " | ";
    }
    cout << endl;
    stacksort(arr, no); //sort function call
    for (int k = 0; k < no; k++)
    {   //putting elements back in stack
        st.push(arr[k]);
    }
    cout << "Stack after sorting: ";
    while (!st.empty())
    {
        cout << st.peek() << " | ";
        st.pop();
    }
    return 0;
}