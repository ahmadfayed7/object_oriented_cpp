#include <iostream>
#include "Dequeue_array_based.h"
using namespace std;

int main()
{

    Dequeue<int> d;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);
    d.push_back(50);

   cout << "front:" << d.front()<<"back:"<<d.back()<< endl;
       d.print();
       cout<<endl;

       cout<<endl;
    d.push_back(60);
           d.print();
            cout<<endl;

     cout<<endl;
      d.push_front(20);
                 d.print();
            cout<<endl;

          cout<<endl;
          d.pop_front();
                d.print();
            cout<<endl;

          cout<<endl;
          d.pop_back();
      d.print();
            cout<<endl;

          cout<<endl;

             d.pop_back();
             d.pop_back();
            d.pop_back();
             d.pop_back();
              d.pop_back();
            d.print();
            cout<<endl;

          cout<<endl;
          d.push_front(10);
          d.push_front(20);
          d.push_front(30);
                      d.print();
            cout<<endl;

          cout<<endl;

   cout << "front:" << d.front()<<"back:"<<d.back()<< endl;
   d.pop_front();
    d.pop_front();
    d.pop_front();
                          d.print();
            cout<<endl;

          cout<<endl;

   cout << "front:" << d.front()<<"back:"<<d.back()<< endl;
    return 0;
}
