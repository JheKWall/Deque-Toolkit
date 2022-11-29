/**
 * @file main.cpp
 * @author William Hayes, Jackson Horton, and Kenneth Wallace
 * @date 2022-11-22
 * @brief short
 * 
 * long
 */


#include <iostream>
#include "deque.h"

using namespace std;

int main() {
  deque<int> mydeque;

  if (mydeque.empty())
    cout << "The deque is empty!" << endl;

  for (int i = 0; i < 12345; i++) {
    // push elements to front and back
    if (i % 2)
      mydeque.push_back(i);
    else
      mydeque.push_front(i);
  }

  mydeque.print();

  
  return 0;
}
