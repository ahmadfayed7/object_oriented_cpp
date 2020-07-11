#include <iostream>
#include "Stack_array_based.h"
using namespace std;

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
   s.pop();
    cout << s.top()<< endl;
    return 0;
}
