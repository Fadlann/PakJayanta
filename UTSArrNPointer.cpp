#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int value;
    node* left = NULL;
    node* right = NULL;
};

void levelOrderTraversal(node* root)
{
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.emplace(root);

    while(q.size() > 0)
    {
        node* cur = q.front();
        q.pop();

        cout<<cur->value<<" ";

        if(cur->left != NULL) 
            q.emplace(cur->left);
        if(cur->right != NULL)
            q.emplace(cur->right); 
    } 
}

// l and r are inclusive (index based)
void createTree(int* a, int l, int r, node* parent)
{
    if(l > r)
        return;

    int midIdx = (l+r+1)/2;
    int mid = a[midIdx];

    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = mid;

    if(parent->left == NULL)
        parent->left = newNode;
    else
        parent->right = newNode;

    createTree(a, l, midIdx - 1, newNode);
    createTree(a, midIdx + 1, r, newNode);
}

void UTS(int* a, int size)
{
    if(size <= 0)
        return;

    int midIdx = size/2;
    int mid = a[midIdx];

    node* root = (node*)malloc(sizeof(node));
    root->value = mid;
    
    createTree(a, 0, midIdx - 1, root);
    createTree(a, midIdx + 1, size - 1, root);

    levelOrderTraversal(root);
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int size = sizeof(a)/sizeof(a[0]);
    UTS(a, size);
    return 0;
}