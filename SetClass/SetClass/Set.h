#pragma once
template <typename T >
struct node {
    T data;
    node* left;
    node* right;
    int height;
};
template <class T>
class Set
{
public:
    Set();
    virtual ~Set();
    Set(const Set<T>& other);
    Set<T>& operator=(const Set<T>& other);
    void clear();
    ////////////////////capacity////////////////
    int size();
    int max_size();
    bool empty();
    /////////////////Modifiers/////////////////
    void insert(T new_data);
    void erase(T data);
    bool  find(T data);
    void inorder();
protected:

private:
    node<T>* root;
    int curr_size;
};
