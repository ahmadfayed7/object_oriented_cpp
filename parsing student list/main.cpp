#include <iostream>
#include "studentlist.h"

using namespace std;
void print_student(student s)
{
  cout << s.get_first_name()<<"\n" << endl;
    cout << s.get_last_name()<<"\n" << endl;
    cout << s.get_id()<<"\n" << endl;
    cout << s.get_gpa()<<"\n" << endl;


}

int main(int c , const char *arg[])
{

    try {
    if(c !=2)
    {
       cout<< "no path file entered"<<endl;
       return -1;
    }
       studentlist sl(arg[1]);
      vector<student> l;
    cout <<"first student"<<endl<<endl;
    print_student(sl.get_val_dicroration());
    cout <<"honor students"<<endl<<endl;
      l= sl.get_high_students();
    for(int i=0;i<l.size();i++)
     print_student(l.at(i));
     cout <<"falling students"<<endl<<endl;
      l= sl.get_fall_students();
    for(int i=0;i<l.size();i++)
     print_student(l.at(i));
    }
    catch (exception &e)
    {
    cout <<e.what()<<endl;
    return -1;
    }

    return 0;
}
