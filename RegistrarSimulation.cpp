#include "RegistrarSimulation.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <numeric>

using namespace std;

RegistrarSimulation::RegistrarSimulation(string file)
{
  ifstream textFile(file);

  if (textFile.is_open() && textFile.good()) //checks if file is opened and readable and writable and other state flags
  {
    int numWindows = 0;
    string line = "";

    getline(textFile, line); //takes the numWindows
    numWindows = stoi(line);

    //cout << "Num Windows: " << numWindows << endl; //TESTING

    tobeQueue = new GenQueue<Student>;
    vector<Window> windows;
    vector<Student> waitTime;

    for (int i = 0; i < numWindows; ++i) //adds numWindows to windows vector, and assigns default values
      windows.push_back(Window(-1, 0));

    while (!textFile.eof()) //while textFile isn't at end, continue
    {
       int time = 0, numStudents = 0;

       getline(textFile, line); //takes the time of arrival
       time = stoi(line);

       getline(textFile, line); //takes the numStudents in this batch
       numStudents = stoi(line);

       for (int i = 0; i < numStudents; ++i) //read and add all students and their arrival time into queue and waitTime vector
       {
         getline(textFile, line);
         waitTime.push_back(Student(time, stoi(line)));
         tobeQueue->insert(Student(time, stoi(line)));
       }
    }

    //for (int i = 0; i < waitTime.size(); ++i) //TESTING
      //cout << "Arrival Time: " << waitTime[i].wait << endl;

    int currIndex = 0, currTime = 0; //keeps index of students in waitTime vector, and sets the currTime to first in queue

    while (!tobeQueue->isEmpty() && isIdle(windows) != -1 || !tobeQueue->isEmpty()) //if students in queue or window, continue
    {
      //cout << "Time: " << currTime << endl; //TESTING
      //for (int i = 0; i < windows.size(); ++i) //TESTING
        //cout << "Window Times: " << windows[i].windowTime << endl;

      int idleIndex = isIdle(windows); //gets index of open window/if window is open
      if (!tobeQueue->isEmpty() && idleIndex != -1 && currTime >= waitTime[currIndex].wait) //if window available, calculate wait time, increment queue index, remove from queue and add to window
      {
        waitTime[currIndex].wait = currTime - waitTime[currIndex].wait;
        currIndex++;
        windows[idleIndex].windowTime = tobeQueue->remove().windowTime;
        continue;
      }

      currTime++; //increment current time

      for (int i = 0; i < windows.size(); ++i) //decrement student time at window, possibly increment idleTime
      {
        if (windows[i].windowTime < 1)
          windows[i].idleTime++;
        windows[i].windowTime--;
      }
    }

    //for (int i = 0; i < waitTime.size(); ++i) //TESTING
      //cout << "Wait Times: " << waitTime[i].wait << endl;

    double mean = 0, meanIdle = 0; //default values
    int median = 0, longest = 0, waitTen = 0, longestIdle = 0, idleFive = 0; //default values
    size_t size = waitTime.size(); //shortened for ease of use

    sort(waitTime.begin(), waitTime.end()); //sort vector to find median
    if (size % 2 == 0) //find median
      median = (waitTime[(size / 2) - 1].wait + waitTime[size / 2].wait) / 2;
    else
      median = waitTime[size / 2].wait;

    for (int i = 0; i < size; ++i) //iterates waitTime vector to find mean and waitTime over 10 min
    {
      if (waitTime[i].wait > 10)
        waitTen++;
      mean += waitTime[i].wait;
    }

    for (int i = 0; i < windows.size(); ++i) //iterates windows vector to find longest idle, mean, and idle over 5 min
    {
      if (longestIdle < windows[i].idleTime)
        longestIdle = windows[i].idleTime;
      meanIdle += windows[i].idleTime;
      if (windows[i].idleTime > 5)
        idleFive++;
    }

    mean = mean / size; //calculate mean
    longest = waitTime.back().wait; //longest is back value in sorted vector
    meanIdle = meanIdle / windows.size(); //calculate mean
    //mean = accumulate(waitTime.begin(), waitTime.end(), 0.0) / size; //another way to find mean

    cout << "Mean Student Wait Time: " << mean << endl;
    cout << "Median Student Wait Time: " << median << endl;
    cout << "Longest Student Wait Time: " << longest << endl;
    cout << "Number of Students Waiting Over 10 Minutes: " << waitTen << endl;

    cout << "Mean Window Idle Time: " << meanIdle << endl;
    cout << "Longest Window Idle Time: " << longestIdle << endl;
    cout << "Number of Windows Idle Over 5 Minutes: " << idleFive<< endl;

    //for (int i = 0; i < windows.size(); ++i) //TESTING
      //cout << "Idle Times: " << windows[i].idleTime << endl;

  }
  else //If file can't be opened
    cout << "Error: Unable to open file" << endl;

}

RegistrarSimulation::~RegistrarSimulation()
{
  delete tobeQueue;
}

int RegistrarSimulation::isIdle(vector<Window> vect)
{
  for (int i = 0; i < vect.size(); ++i)
  {
    if (vect[i].windowTime < 1)
      return i;
  }
  return -1;
}
