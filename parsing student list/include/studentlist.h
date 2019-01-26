#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "student.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
class studentlist
{
    public:
        studentlist(std::string file_path);
        student get_val_dicroration();
        std::vector<student> get_high_students();
        std::vector<student> get_fall_students();

//private:
    std::vector<student> students;
};


class novaleexception : public std::exception
{

   const char* what()  const throw ()
   {

   return "studentlist : no valedicooration";
   }
};
#endif // STUDENTLIST_H
