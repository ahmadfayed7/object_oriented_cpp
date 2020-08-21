#include "Set.h"
#include  <iostream>
using namespace std;
template <class T >
Set<T>::Set()
{
    root = nullptr;
    curr_size = 0;
}
template <class T >
Set<T>::~Set()
{
    clear();

}
template <class T >
void Set<T>::clear()
{
    root = nullptr;
}
template <class T >
Set<T>::Set(const Set& other)
{
    *this = other;
}
template <class T >
Set<T>& Set<T>:: operator=(const Set<T>& other)
{
    if (this == &other) return *this;
    else
    {
        this->clear();
        this->root = other.root;
        return *this;
    }

}

template <typename T >
struct node<T>* get_parent(node<T>* curr, node<T>* r)
{
    node<T>* ptr1 = r, ptr2 = r;
    while (ptr1 != nullptr)
    {
        if (ptr2->data < curr->data)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->left;
        }
        else if (ptr2->data > curr->data)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->right;
        }
        else
        {
            return ptr1;
        }
    }
    return ptr2;
}

/////////////////////Auxailrray function/////////////////////////
template <typename T >
struct node<T>* min_node(node<T>* curr)
{
    if (curr == nullptr)
        return nullptr;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;

}
template <typename T >
struct node<T>* max_node(node<T>* curr)
{
    if (curr == nullptr)
        return nullptr;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr;

}

////////////////////capacity////////////////
template <class T>
int Set<T>::size()
{
    return curr_size;
}
template <class T>
int Set<T>::max_size()
{
    return 20000;
}
template <class T>
bool Set<T>::empty()
{
    return (root == nullptr);
}
///////////////////Modifiers/////////////////////
template <class T>
void Set<T>::insert(T new_data)
{
    root = insert_aux(root, new_data);
}
/* case 1    balance >1
       x
      /
     y
    /
  new_data
   case 2    balance <-1
    x
      \
       y
        \
         new_data
     case3    balance >1
          x
         /
       y
         \
          new_data
  case4    balance <-1
    x
      \
       y
      /
  new_data

*/
template <typename T >
node<T>* insert_aux(node<T>* curr, T new_data)
{
    if (curr == nullptr)
    {
        node<T>* new_node = new node<T>();
        new_node->data = new_data;
        new_node->height = 1;
        return new_node;
    }
    if (new_data < curr->data)
        curr->left = insert_aux(curr->left, new_data);
    else if (new_data > curr->data)
        curr->right = insert_aux(curr->right, new_data);
    else
        return curr;
    curr->height = 1 + max(height(curr->left), height(curr->right));
    int balance = balance_calc(curr);

    if (balance > 1 && curr->left->data > new_data)
        return right_rotate(curr);

    if (balance < -1 && curr->right->data < new_data)
        return left_rotate(curr);

    if (balance > 1 && curr->left->data < new_data)
    {
        curr->left = left_rotate(curr->left);
        return right_rotate(curr);
    }
    if (balance<-1 && curr->right->data >new_data)
    {
        curr->right = right_rotate(curr->right);
        return left_rotate(curr);
    }
    return curr;
}
template <typename T >
int balance_calc(node<T>* curr)
{
    return (height(curr->left) - height(curr->right));
}
template <typename T >
int height(node<T>* curr) {
    // base case we reach a null node
    if (curr == NULL)
        return 0;
    // return height of root of this subtree
    return curr->height;
}
/*
       x                y
      / \              / \
     y   T3  ->     T1     x,
    / \      <-           / \
  T1   T2                T2   T3
*/
/*
       x              y
      /              /  \
     y    ->       T1    x
    /    <-
  T1
*/
template <typename T >
node<T>* right_rotate(node<T>* x)
{

    if (x == nullptr)
        return nullptr;
    node<T>* y = x->left;
    node<T>* T2 = y->right;

    y->right = x;
    x->left = T2;
    x->height = max(height(x->left), height(x->right));
    y->height = max(height(y->left), height(y->right));
    return y;
}
template <typename T >
node<T>* left_rotate(node<T>* y)
{
    if (y == nullptr)
        return nullptr;
    node<T>* x = y->right;
    node<T>* T2 = x->left;

    x->left = y;
    y->right = T2;
    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(x->right));
    return x;
}
template <class T>
void Set<T>::erase(T data)
{
    root = erase_aux(root, data);
}
template <typename T >
node<T>* erase_aux(node<T>* curr, T data)
{

    if (curr == nullptr)
        return curr;

    if (data < curr->data)
        curr->left = erase_aux(curr->left, data);
    else if (data > curr->data)
        curr->right = erase_aux(curr->right, data);
    else
    {
        if (curr->left == nullptr && curr->right == nullptr)
        {
            node<T>* temp = nullptr;
            curr = nullptr;
            delete temp;
        }
        else if (curr->left == nullptr)
        {
            node<T>* temp = curr->right;
            curr = temp;
            delete temp;

        }
        else if (curr->right == nullptr)
        {
            node<T>* temp = curr->left;
            curr = temp;
            delete temp;
        }
        else
        {
            node<T>* temp = min_node(curr->right);
            curr->data = temp->data;
            curr->right = erase_aux(curr->right, temp->data);
        }

    }
    if (curr = nullptr)
        return nullptr;

    curr->height = 1 + max(height(curr->left), height(curr->right));
    int balance = balance_calc(curr);

    if (balance > 1 && curr->left->data > data)
        return right_rotate(curr);

    if (balance < -1 && curr->right->data < data)
        return left_rotate(curr);

    if (balance > 1 && curr->left->data < data)
    {
        curr->left = left_rotate(curr->left);
        return right_rotate(curr);
    }
    if (balance<-1 && curr->right->data >data)
    {
        curr->right = right_rotate(curr->right);
        return left_rotate(curr);
    }
    return curr;

}
template <typename T >
bool Set<T>::find(T data)
{
    node<T>* curr = root;
    while (curr != nullptr)
    {
        if (data < curr->data)
            curr = curr->left;
        else if (data > curr->data)
            curr = curr->right;
        else
            return true;
    }
    return false;
}
template <typename T >
void Set<T>::inorder()
{
    inorder_aux(root);
}
template <typename T >
void inorder_aux(node<T>* curr)
{
    if (curr == nullptr)
        return;
    inorder_aux(curr->left);
    cout << curr->data;
    inorder_aux(curr->right);

}
template class Set<int>;
template struct node<int>;
