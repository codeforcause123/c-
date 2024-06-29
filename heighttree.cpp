#include <bits/stdc++.h>
using namespace std;
class node
{ // Tree structure
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool isbalanced(node *root, int *height)
{ // Function for checking tree is balanced
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isbalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (isbalanced(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    /*
                   1
                /     \
               2       3
             /  \     / \
            4    5   6   7
           /
          8
    */
    int height = 0;
    node *root = new node(1); //creating tree
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    if (isbalanced(root, &height))
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is Unbalanced" << endl;
    }
    return 0;
}