#include <iostream>
#include "List.h"
using namespace std;

int main()
{
   List<int> l (10,100) ;
    l.push_back(50);
    List<int>::iterator i=l.end();
   for(i=l.begin();i != l.end();++i)
        cout<<*i<<endl;
     cout<<*i<<endl;
 //  l.print();
}
