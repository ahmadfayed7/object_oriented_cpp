#include <iostream>
#include "Queue_array_based.h"
using namespace std;

int main()
{
    Queue<int> q;
    q.push(10);
    cout << q.front()<<"  " <<q.back()<< endl;
        q.push(20);
    cout << q.front()<<"  " <<q.back()<< endl;
        q.push(30);
    cout << q.front()<<"  " <<q.back()<< endl;
        q.push(40);
    cout << q.front()<<"  " <<q.back()<< endl;
        q.push(50);
        q.pop();
    cout << q.front()<<"  " <<q.back()<< endl;
    return 0;
}
