#include "Window.h"
#include "Student.h"
#include "GenQueue.h"
#include <vector>
#include <iostream>

using namespace std;

class RegistrarSimulation
{
public:
  RegistrarSimulation(string file);
  ~RegistrarSimulation();

  int isIdle(vector<Window> vect);

  GenQueue<Student>* tobeQueue;
};
