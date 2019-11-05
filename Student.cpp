#include "Student.h"

Student::Student()
{

}

Student::Student(int w, int t)
{
  wait = w;
  windowTime = t;
}

Student::~Student()
{

}

bool operator<(const Student &s1, const Student &s2) //overloads operator < allowing for sort
{
  return s1.wait < s2.wait;
}
