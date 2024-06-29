#include <bits/stdc++.h>
using namespace std;

class orderPrint
{
    int n;
    vector<int> key;
    vector<int> left;
    vector<int> right;
    vector<int> result;

public:
    void read()
    {
        cin >> n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> key[i] >> left[i] >> right[i];
        }
    }

    vector<int> in_order()
    {
        result.clear();
        in_order_traversal(0);
        return result;
    }

    void in_order_traversal(int idx)
    {
        if (left[idx] != -1)
            in_order_traversal(left[idx]);
        result.push_back(key[idx]);
        if (right[idx] != -1)
            in_order_traversal(right[idx]);
    }

    vector<int> pre_order()
    {
        result.clear();
        pre_order_traversal(0);
        return result;
    }

    void pre_order_traversal(int idx)
    {
        result.push_back(key[idx]);
        if (left[idx] != -1)
            pre_order_traversal(left[idx]);
        if (right[idx] != -1)
            pre_order_traversal(right[idx]);
    }

    vector<int> post_order()
    {
        result.clear();
        post_order_traversal(0);
        return result;
    }

    void post_order_traversal(int idx)
    {
        if (left[idx] != -1)
            post_order_traversal(left[idx]);
        if (right[idx] != -1)
            post_order_traversal(right[idx]);
        result.push_back(key[idx]);
    }
};

void print(vector<int> array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        if (i > 0)
        {
            cout << ' ';
        }
        cout << array[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    orderPrint x;
    x.read();
    print(x.in_order());
    print(x.pre_order());
    print(x.post_order());
    return 0;
}