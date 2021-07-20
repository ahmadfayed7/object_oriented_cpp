#include <iostream>
#include "AVLTree.h"
using namespace std;

int main()
{
    AVLTree t1;

    /* Constructing tree given in
    the above figure */
    t1.insertElement(10);
    t1.insertElement(20);
    t1.insertElement(30);
    t1.insertElement(40);
    t1.insertElement(50);
    t1.insertElement(25);

    t1.deleteElement(20);
    /* The constructed AVL Tree would be
             30
            / \
          20   40
         /  \     \
        10 25     50
    */

    t1.printTree();
    //preOrder(root);

    return 0;
}
