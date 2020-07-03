#include <iostream>
#include "include\Vector.h"
using namespace std;

int main()
{
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "Vector size : "
         << v.size() << endl;
    cout << "Vector capacity : "
         << v.capacity() << endl;

    cout << "Vector elements : " << endl;;
    v.print();

    v.insert(1,100);

    cout << "\nAfter updating 1st index"
         << endl;

    cout << "Vector elements : " << endl;;
   v.print();

    cout << "Element at 1st index : "
         << v.at(1) << endl;

        v.pop_back();

    cout << "\nAfter deleting last element"
         << endl;

    cout << "Vector size : "
         << v.size() << endl;
    cout << "Vector capacity : "
         << v.capacity() << endl;

    cout << "Vector elements : " << endl;
   v.print();

    return 0;

}
