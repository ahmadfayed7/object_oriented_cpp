#include "student.h"
using namespace std;
student::student(string student_info)
{
    stringstream ss(student_info);
    ss>>first_name;
    ss>>last_name;
    ss>>id;
    ss>>gpa;
}
string student::get_first_name()
{
return first_name;
}
string student::get_last_name()
{
 return last_name;
}
int student::get_id()
{
return id;
}
int student::get_gpa()
{
return gpa;
}

student::~student()
{
    //dtor
}
