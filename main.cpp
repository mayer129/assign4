#include "RegistrarSimulation.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{

  if (argc != 2) //checking if filepath was entered. If no filepath given, program ends
  {
    cout << "Error: Please run again and include the filepath" << endl;
    return 0;
  }

  RegistrarSimulation* regSim = new RegistrarSimulation(argv[1]);

  delete regSim;
  return 0;
}
