#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node() : val(0), left(NULL), right(NULL) {}
    Node(int x) : val(x), left(NULL), right(NULL) {}
    Node(int x, Node *l, Node *r) : val(x), left(l), right(r) {} 
};

Node* buildTreeFromArray(const vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildTreeFromArray(arr, 2 * i + 1);
    root->right = buildTreeFromArray(arr, 2 * i + 2);
    return root;
}

void preorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

int main()
{
    vector<int> arr = {1, -1, 2, 3};
    Node *root = buildTreeFromArray(arr, 0);
    vector<int> ans;
    preorder(root, ans);
    for (auto t : ans)
    {
        cout << t << " ";
    }
}
