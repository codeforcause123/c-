#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *right, *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
int evenoddsum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> q;
    q.push(root);
    int level = 0;
    int oddsum = 0, evensum = 0;
    while (!q.empty())
    {
        int size = q.size();
        level += 1;
        while (size > 0)
        {
            node *temp = q.front();
            q.pop();
            if (level % 2 != 0)
            {
                oddsum += temp->data;
            }
            if (level % 2 == 0)
            {
                evensum += temp->data;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            size -= 1;
        }
    }
    return oddsum - evensum;
}

int main()
{
    node *root = new node(5);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->left->right->left = new node(3);
    root->right->right = new node(8);
    root->right->right->right = new node(9);
    root->right->right->left = new node(7);
    cout << evenoddsum(root) << endl;
    return 0;
}