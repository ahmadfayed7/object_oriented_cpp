#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <sstream>
class student
{
    public:
        student(std::string student_info);
        virtual ~student();
     std::string get_first_name();
     std::string get_last_name();
     int get_id();
     int get_gpa();
    private:
    std::string first_name;
    std::string last_name;
    int id;
    int gpa;
};

#endif // STUDENT_H
