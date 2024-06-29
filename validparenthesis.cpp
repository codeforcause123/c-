#include <bits/stdc++.h>
using namespace std;
#define n 100
class Stack
{   //Defining Stack and member functions
    char *arr;
    int top;
    public:
    Stack()
    {
        arr = new char[n];
        top = -1;
    }
    void push(char x)
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
bool isValid(string s)
{   //function for valid string checking
    int len = s.size();
    Stack st;
    bool ans = true;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {   //pushing opening brackets
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {   // encountering closing bracket
            if (!st.empty() && st.peek() == '(')
            {   // checking if closing bracket has a matching opening bracket at stack top
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.peek() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.peek() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {   //checking for leftover brackets
        ans = false;
    }
    return ans;
}
int main()
{
    string s;
    cout << "Enter brackets: ";
    cin >> s;
    if (isValid(s))
    {
        cout << "True. String is valid" << endl;
    }
    else
    {
        cout << "False. String is invalid" << endl;
    }
    return 0;
}