#include "AVLTree.h"

AVLTree::AVLTree()
{
    root = NULL;
}

AVLTree::~AVLTree()
{
    //dtor
}

void AVLTree::createTree()
{

    root = NULL;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int getBalance(TreeNode* t)
{
    int l = 0, r = 0;
    if(t->left)
       l = t->left->height;
    if (t->right)
       r = t->right->height;
    return l-r;
}
int updateHeight(TreeNode* t)
{
    if (t == NULL)
        return 0;
    return t->height;
}
TreeNode* leftrot(TreeNode* t)
{
    TreeNode* n = t->right;
    t->right = n->left;
    n->left = t;
    t->height = 1 + max(updateHeight(t->left), updateHeight(t->right));
    n->height = 1 + max(updateHeight(t->left), updateHeight(t->right));
    return n;




}
TreeNode* rightrot(TreeNode* t)
{
    TreeNode* n = t->left;
    t->left = n->right;
    n->right = t;
    t->height = 1 + max(updateHeight(t->left), updateHeight(t->right));
    n->height = 1 + max(updateHeight(t->left), updateHeight(t->right));
    return n;

}
TreeNode* insertElementAux(TreeNode* t, int key)
{
    TreeNode* p = new TreeNode();
    p->left = NULL;
    p->right = NULL;
    p->key = key;
    p->height = 1;

    if (t == NULL)
        return p;
    if (t->key > key)
        t->left = insertElementAux(t->left, key);
    else if (t->key < key)
        t->right = insertElementAux(t->right, key);   //
    else
        return t;

    t->height = 1 + max(updateHeight(t->left), updateHeight(t->right));

    int balance = getBalance(t);

    //right
    if (balance == -2)
    {
        int b = getBalance(t->right);
        if (b == 1)
            t->right = rightrot(t->right);
        t = leftrot(t);
    }


    if (balance == 2)
    {
        int b = getBalance(t->left);
        if (b == -1)
            t->left = leftrot(t->left);
        t = rightrot(t);
    }

    return t;


}

TreeNode* deleteElementAux(TreeNode* t, int key)
{
    TreeNode* temp ,*prev,*curr;

    if (t == NULL)
        return NULL;
    if (t->key > key)
        t->left = deleteElementAux(t->left, key);
    else if (t->key < key)
        t->right = deleteElementAux(t->right, key);   //
    else
    {
        if (t->left == NULL || t->right == NULL)
        {

            if (t->left )
            {
                temp = t->left;
            }
            else
            {
                temp = t->right;
            }

            if (temp == NULL)
            {
                temp = t;
                t = NULL;
            }
            else
            {
                *t = *temp;
            }
            delete(temp);
        }
        else
        {

            for (curr = t->left; curr->right;  prev = curr , curr = curr->right);
            t->key = curr->key;
            t->left = deleteElementAux(t->left, curr->key);
        }

    }
    if (t == NULL)
        return NULL;
    t->height = 1 + max(updateHeight(t->left), updateHeight(t->right));

    int balance = getBalance(t);

    //right
    if (balance == -2)
    {
        int b = getBalance(t->right);
        if (b == 1)
            t->right = rightrot(t->right);
        t = leftrot(t);
    }


    if (balance == 2)
    {
        int b = getBalance(t->left);
        if (b == -1)
            t->left = leftrot(t->left);
        t = rightrot(t);
    }

    return t;

}
void AVLTree::insertElement(int key)
{
    root = insertElementAux(root, key);
}
void AVLTree::deleteElement(int key)
{
    root = deleteElementAux(root, key);
}
void printTreeAux(TreeNode* t)
{
    if (t == NULL)
        return;
    printTreeAux(t->left);
    cout << t->key;
    printTreeAux(t->right);

}
void AVLTree::printTree()
{
    printTreeAux(root);
}
