#include <iostream>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
struct brac
{
    brac(char type, int position) : type(type),
                                    position(position)
    {
    }
    bool Match1(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    char type;
    int position;
};

int main()
{
    string text;
    getline(cin, text);

    int error_pos = 0;

    stack<brac> opening_bracs_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];
        if (next == '(' || next == '[' || next == '{')
        {
            brac b(next, position + 1);
            opening_bracs_stack.push(b);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            if (opening_bracs_stack.empty())
            {
                error_pos = position + 1;
                break;
            }
            brac top = opening_bracs_stack.top();
            opening_bracs_stack.pop();
            if (!top.Match1(next))
            {
                error_pos = position + 1;
                break;
            }
        }
    }

    if (error_pos == 0 && opening_bracs_stack.empty())
        cout << "Success";
    else
    {
        if (error_pos == 0)
        {
            while (opening_bracs_stack.size() > 1)
                opening_bracs_stack.pop();
            error_pos = opening_bracs_stack.top().position;
        }
        cout << error_pos;
    }
    return 0;
}