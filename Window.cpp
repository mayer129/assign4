#include "Window.h"

Window::Window()
{

}

Window::Window(int t, int iT)
{
  windowTime = t;
  idleTime = iT;
}

Window::~Window()
{

}

bool operator<(const Window &w1, const Window &w2) //overloads operator < allowing for sort
{
  return w1.idleTime < w2.idleTime;
}
