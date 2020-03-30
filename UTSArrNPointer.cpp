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

    int total = q.size();

    int NP[15] = {};
    int k = 0;

    while(q.size() > 0)
    {
        node* cur = q.front();
        q.pop();

        if(cur->value % 2 != 0)
        {
            NP[k] = cur->value;
            k++;
        }
        
        if(cur->left != NULL) 
            q.emplace(cur->left);
        if(cur->right != NULL)
            q.emplace(cur->right); 
    } 
    
    for (int i = 0; i < 15; i++)
    {
        cout<<NP[i]<<" ";
    }
}

void preOrderTraversal(node* cur) 
{ 
    if (cur == NULL) 
        return; 
        
    cout<<cur->value<<" "; 
    preOrderTraversal(cur->left); 
    preOrderTraversal(cur->right); 
}

void inOrderTraversal(node* cur) 
{ 
    if (cur == NULL) 
        return; 
  
    inOrderTraversal(cur->left); 
    cout<<cur->value<<" "; 
    inOrderTraversal(cur->right); 
} 

void postOrderTraversal(node* cur) 
{ 
    if (cur == NULL) 
        return; 
  
    postOrderTraversal(cur->left); 
    postOrderTraversal(cur->right); 
    cout<<cur->value<<" "; 
} 

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
    if(mid % 2 != 0)
        root->value = mid;
    
    createTree(a, 0, midIdx - 1, root);
    createTree(a, midIdx + 1, size - 1, root);

    postOrderTraversal(root);
}

int main(int argc, char const *argv[])
{
    int NA[] = {150, 275, 110, 130, 200, 350, 75, 125, 175, 105, 215, 65, 471, 144, 295};
    int size = sizeof(NA)/sizeof(NA[0]);

    int NP[15] = {};

    for (int i = 0; i < size; i++)
    {
        cout<<NA[i]<<" ";
    }
    cout<<endl;

    UTS(NA, size);
    return 0;
}