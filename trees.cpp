#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inOrder(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
bool getpath(TreeNode *root, vector<int> &arr, TreeNode *p)
{
    if (!root)
        return false;
    arr.push_back(root->data);
    if (root->data == p->data)
    {
        return true;
    }
    if (getpath(root->left, arr, p) || getpath(root->right, arr, p))
    {
        return true;
    }
    arr.pop_back();
    return false;
}
int getindex(vector<int> v1, vector<int> v2)
{
    int size = min(v1.size(), v2.size());
    for (int i = 0; i < size; i++)
    {
        if (v1[i] != v2[i])
        {
            return i - 1;
        }
    }
    return size - 1;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node10 = new TreeNode(10);
    TreeNode *node11 = new TreeNode(11);
    TreeNode *node12 = new TreeNode(12);
    TreeNode *node13 = new TreeNode(13);
    TreeNode *node14 = new TreeNode(14);
    TreeNode *node15 = new TreeNode(15);

    // Building the tree
    root->left = node2;
    root->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node4->left = node8;
    node4->right = node9;
    node5->left = node10;
    node5->right = node11;
    node6->left = node12;
    node6->right = node13;
    node7->left = node14;
    node7->right = node15;
    inOrder(root);
    cout << endl;
    vector<int> path1;
    vector<int> path2;
    getpath(root, path1, node8);
    getpath(root, path2, node15);
    int lcaindex = getindex(path1, path2);
    int lca = path1[lcaindex];
    for (auto i : path1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto j : path2)
    {
        cout << j << " ";
    }
    cout << endl;
    cout << "LCA = " << path1[lcaindex] << endl;
    cout << endl;
    vector<int> pathbetNodes;
    for (int i = path2.size() - 1; i >= 0; i--)
    {
        if (path2[i] == lca)
        {
            break;
        }
        else
        {
            pathbetNodes.push_back(path2[i]);
        }
    }
    for (int j = lcaindex; j < path1.size(); j++)
    {
        pathbetNodes.push_back(path1[j]);
    }
    for (auto i : pathbetNodes)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}