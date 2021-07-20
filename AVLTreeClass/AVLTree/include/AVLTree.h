#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
using namespace std;
#define NULL 0
struct TreeNode{
    TreeNode  * left ;
     TreeNode  * right ;
     int key;
     int height;
};
class AVLTree
{
    public:
        AVLTree();
        virtual ~AVLTree();
          void createTree();
         void insertElement( int key );
         void deleteElement( int key );
         void printTree();

    protected:

    private:
  TreeNode *root;
};

#endif // AVLTREE_H
