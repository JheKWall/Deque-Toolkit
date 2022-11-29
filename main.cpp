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
  deque<int> test;
  
  
  
  if (mydeque.empty())
    cout << "The deque is empty!" << endl;

  cout << "Pushing 12345 integers front and back..." << endl << endl;
  
  for (int i = 0; i < 12345; i++) {
    // push elements to front and back
    if (i % 2)
      mydeque.push_back(i);
    else
      mydeque.push_front(i);
  }

  cout << "All push_front's and push_back's completed!" << endl;
  cout << "Size of deque: " << mydeque.size() << endl << endl;
  
  cout << "Testing print method..." << endl << endl;
  
  mydeque.print();

  cout << endl;

  cout << "Testing front() and back()..." << endl << endl;;

  cout << "Front(): " << mydeque.front() << endl;
  cout << "Back(): " << mydeque.back() << endl << endl;

  cout << "Testing pop_front and pop_back..." << endl << endl;

  mydeque.pop_front();
  mydeque.pop_back();

  cout << "Printing new front and back..." << endl << endl;
  
  cout << "New front(): " << mydeque.front() << endl;
  cout << "New back(): " << mydeque.back() << endl << endl;

  cout << "Popping all elements in array..." << endl;

  unsigned int temp = mydeque.size();
  
  for(unsigned int i = 0; i < temp; i++) {
    if(i % 2)
      mydeque.pop_back();
    else
      mydeque.pop_front();
  }
  
  cout << "All elements popped!" << endl << endl;


  cout << "Testing overloaded []'s..." << endl << endl;
  cout << "Creating deque of 5 integers" << endl;

  for(unsigned int i = 0; i < 5; i++){
    mydeque.push_back(i);
  }

  cout << "Printing deque using []'s: " << endl;
  for(unsigned int i = 0; i < mydeque.size(); i++) {
    cout << "mydeque[" << i <<"]: " << mydeque[i] << endl;
  }

  cout << "Modifying deque data using []'s:" << endl;
  mydeque[0] = 42;
  mydeque[3] = 7777;

  for(unsigned int i = 0; i < mydeque.size(); i++) {
    cout << "mydeque[" << i << "]: " << mydeque[i] << endl;
  }
  
  return 0;
}
