#include <iostream>
#include <queue>

using namespace std;

static int counter ()
    {
       static int counter = 0;
       return counter ++;
    }

struct node
{
    int value;
    node* left = NULL;
    node* right = NULL;
};

void levelOrderTraversal(node* root, int* NP)
{
    if(root == NULL)
        return;
    
    queue<node*> q;
    q.emplace(root);

    int total = q.size();

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
}

void preOrderTraversal(node* cur, int* NP) 
{ 
    if (cur == NULL) 
        return; 
        
    if(cur->value % 2 != 0)
    {
        NP[counter()] = cur->value;
    }

    preOrderTraversal(cur->left, NP); 
    preOrderTraversal(cur->right, NP); 
}

void inOrderTraversal(node* cur, int* NP) 
{ 
    if (cur == NULL) 
        return; 
  
    inOrderTraversal(cur->left, NP); 
    
    if(cur->value % 2 != 0)
    {
        NP[counter()] = cur->value;
    }

    inOrderTraversal(cur->right, NP); 
} 

void postOrderTraversal(node* cur, int* NP) 
{ 
    if (cur == NULL) 
        return; 
  
    postOrderTraversal(cur->left, NP); 
    postOrderTraversal(cur->right, NP); 

    if(cur->value % 2 != 0)
    {
        NP[counter()] = cur->value;
    }
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

void UTS(int* a, int size, int* NP)
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

    cout<<"[1]levelorder traversal [2]preorderTraversal [3]inordertraversal [4]postordertraversal: ";

    int input;
    cin>>input;

    int idx = 0;

    cout<<"Array hasil :"<<endl;
    switch (input)
    {
    case 1:
        levelOrderTraversal(root, NP);
        break;
    case 2:
        preOrderTraversal(root, NP);
        break;
    case 3:
        inOrderTraversal(root, NP);
        break;
    case 4:
        postOrderTraversal(root, NP);
        break;
    default:
        break;
    }
   
    for (int i = 0; i < 15; i++)
    {
        cout<<NP[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int NA[] = {150, 275, 110, 130, 200, 350, 75, 125, 175, 105, 215, 65, 471, 144, 295};
    int size = sizeof(NA)/sizeof(NA[0]);

    cout<<"Array awal :"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<NA[i]<<" ";
    }
    cout<<endl;

    int NP[15] = {};

    UTS(NA, size, NP);
    return 0;
}
