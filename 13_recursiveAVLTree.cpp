#include<iostream>
#include<string>

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node
{
    public:
        int info;
        node *left;
        node *right;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
    }
};

node* parent(node* curr, node* p, node* par)
{
    if(curr == NULL)
        return NULL;

    if (curr == p)
    {
        return par;
    }
    else
    {
        node *t = NULL;
        t = parent(curr->left, p, curr);
        if(t!= NULL)
            return t;
        else
        {
            t = parent(curr->right, p, curr);
            return t;
        }

    }
}

node* sibling(node* root, node* p)
{
    node* par = parent(root, p, NULL);

    if (par->left == p)
        return par->right;
    else 
        return par->left;
}

void deleteTree(node* leaf)
{
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

int getLevel(node *ptr,int val,int level) 
{
   if (ptr == NULL)
      return -1;
   if (ptr->info == val)
      return level;
    int left = getLevel(ptr->left, val, level+1);
    int right = getLevel(ptr->right, val, level+1);

    if (left > right)
        return left;
    else 
        return right;

}

int maxDepth(node* n)  
{  
    if (n == NULL)  
        return -1;  
    else
    {  
        int lDepth = maxDepth(n->left);  
        int rDepth = maxDepth(n->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void preOrder(node *n)
{
    if(n == NULL)
        return;
    
    cout<<n->info<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}   

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}

void printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int checkBalance(node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1;

    int diff = leftHeight - rightHeight;

    if (diff > 1 || diff < -1)
        return -1;

    int maxHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    
    return maxHeight + 1;
}

bool isAVL(node* root) {
    return checkBalance(root) != -1;
}

int main() {
    node *root = new node(8);
    root->left = new node(4);
    root->right = new node(23);

    root->left->left = new node(1);
    root->left->right = new node(12);

    root->right->left = new node(9);
    root->right->right = new node(89);

    printTree(root, NULL, false);
    bool avl = isAVL(root);
    if(avl)
        cout<<"The tree is AVL Balanced"<<endl;
    else
        cout<<"The tree is not AVL Balanced"<<endl;

    node *n = parent(root, root->right->left, NULL);
    cout<<"Parent is: "<<n->info<<endl;

    node *sib = sibling(root, root->right->left); 
    cout<<"Sibling of 3 is: "<<sib->info<<endl;

    cout<<"Level of 9: "<<getLevel(root, 9, 0)<<endl;

    cout<<"Depth of the tree: "<<maxDepth(root)<<endl;
    deleteTree(root);

    node *order = NULL;
    order = new node(1);
    order->left = new node(2);
    order->right = new node(3);
    order->left->left = new node(4);
    preOrder(order);
    cout<<endl;
    inOrder(order);
    cout<<endl;
    postOrder(order);
    return 0;
}
