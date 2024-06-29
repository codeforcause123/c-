#include <bits/stdc++.h>
using namespace std;
class node
{ //Tree structure
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkmirror(node *root1, node *root2)
{ // Utility Function
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 && root2 && root1->data == root2->data)
    {
        return checkmirror(root1->left, root2->right) && checkmirror(root1->right, root2->left);
    }
    return false;
}
bool issymmetric(node *root)
{
    return checkmirror(root, root);
}
int main()
{                             /*
                  1
               /    \
              2      2
            /  \   /  \
           3   4  4    3
    */
    node *root = new node(1); //creating tree
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    root->right->right = new node(3);
    if (issymmetric(root))
    {
        cout << "Tree is Symmetric" << endl;
    }
    else
    {
        cout << "Tree is not Symmetric" << endl;
    }
    return 0;
}