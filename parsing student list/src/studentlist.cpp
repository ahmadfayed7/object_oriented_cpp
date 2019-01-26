#include "studentlist.h"
#include <iostream>
#define falling_grade 65
#define honor_grade 90
using namespace std;
studentlist::studentlist(string file_path)
{
    ifstream ss(file_path);
    string temp;
     getline(ss,temp);
    while(!ss.eof())
    {
     student s(temp);
     students.push_back(s);
     getline(ss,temp);
    }
    ss.close();
    sort (students.begin(),students.end(),[](student &s1 ,student &s2)
                                            {
                                             return s1.get_gpa() > s2.get_gpa();
                                            });

}

student studentlist::get_val_dicroration()
{
    if(students.size()==0 || students.at(0).get_gpa()<falling_grade)
      throw novaleexception();
    return students.at(0);
}
vector<student> studentlist::get_high_students()
{
  vector<student> toreturn ;
  for(int i =0 ; i<students.size();i++)
  {
    if(students.at(i).get_gpa()<honor_grade)
      break;
    else
     toreturn.push_back(students.at(i));
  }
  return toreturn;
}
vector<student>  studentlist::get_fall_students()
{
 vector<student> toreturn ;
  for(int i =students.size()-1; i>=0;i--)
  {
    if(students.at(i).get_gpa()>falling_grade)
      break;
    else
     toreturn.push_back(students.at(i));
  }
  return toreturn;
}
