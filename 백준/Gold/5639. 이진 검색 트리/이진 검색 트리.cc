#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int num;
    Node* left;
    Node* right;
};

void postorder(Node* root)
{
    if(root->left != nullptr)
        postorder(root->left);
    if (root->right != nullptr)
        postorder(root->right);
    cout << root->num << "\n";
}

Node* insert(Node* root, int cur)
{
    if (root == nullptr)
    {
        Node* newNode = new Node();
        newNode->num = cur;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    if (cur < root->num)
        root->left = insert(root->left, cur);

    if (cur > root->num)
        root->right = insert(root->right, cur);

    return root;
}

using namespace std;

int main()
{
    Node* root = nullptr;
    int n;
    while (scanf("%d", &n) != EOF)
        root = insert(root, n);
    postorder(root);
}