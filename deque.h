/**
 * @file deque.h
 * @author Kenneth Wallace
 * @date 2022-11-17
 * @brief Deque header file
 * 
 * Contains implementations and definitions for the Deque class
 */

#ifndef DEQUE_H
#define DEQUE_H

#include <string>

using namespace std;

/**
 * Custom deque implementation
 *
 * @class deque deque.h "Deque-Toolkit/deque.h"
 * @brief 
 *
 */
template <typename T>
class deque {
 private:
  //
  T** blockmap; 

  //
  unsigned int num_of_elements, map_size, block_size, first_block, first_element;
  
 public:

/**
 * Deque default constructor
 *
 * @pre A Deque
 * @post A default deque is constructed
 * 
 */
  deque();

/**
 * Deque destructor
 *
 * @pre A Deque
 * @post The deque is destroyed
 * 
 */
  ~deque();

/**
 * Add to the front of the deque
 *
 * @param T n The item to add to the front of the deque
 * @pre A Deque
 * @return void 
 * @post The item is added to the front of the deque
 * 
 */
  void push_front(T n);

/**
 * Remove the item at the front of the deque
 *
 * @pre A Deque
 * @return void 
 * @post The item at the front of the deque is removed
 * 
 */
  void pop_front();

/**
 * Add to the end of the deque
 *
 * @param T n The item to add to the end of the deque
 * @pre A Deque
 * @return void 
 * @post The item is added to the end of the deque
 * 
 */
  void push_back(T n);

/**
 * Remove the item at the end of the deque
 *
 * @pre A Deque
 * @return void 
 * @post The item at the end of the deque is removed
 * 
 */
  void pop_back();

/**
 * Returns a copy of the item at the front of the deque
 *
 * @pre A Deque
 * @return T A copy of the item at the front of the deque
 * @post 
 * 
 */
  T front();

/**
 * Returns a copy of the item at the end of the deque
 *
 * @pre A Deque
 * @return T A copy of the item at the end of the deque
 * @post 
 * 
 */
  T back();

/**
 * Method to check if the deque is empty or not
 *
 * @pre A Deque
 * @return bool True if not empty, False if empty
 * @post 
 * 
 */
  bool empty();

/**
 * Method for getting the size of the deque
 *
 * @pre A Deque
 * @return unsigned int The size of the deque
 * @post 
 * 
 */
  unsigned int size();

/**
 * Bracket overload for getting an item at a specific index in the deque
 *
 * @param int index The index of the item
 * @pre A Deque
 * @return T The item at the given index
 * @post 
 * 
 */
  T& operator[](uint index);
};

template <typename T>
deque<T>::deque() {
  num_of_elements = 0;
  first_block = 1;
  first_element = 3;
  block_size = 8;
  map_size = 8;
  blockmap = new T*[map_size];

  for (uint row = 0; row < map_size; row++) {
    blockmap[row] = new T[block_size];
    for (uint column = 0; column < block_size; column++) {
      blockmap[row][column] = 0;
    }
  }

}


template <typename T>
deque<T>::~deque() {
  // deletes all the blocks
  for (uint row = 0; row < map_size; row++) {
    delete[] blockmap[row];
  }  
 
  // deletes the map to the blocks
  delete[] blockmap;
}


template <typename T>
T& deque<T>::operator[](uint i) {

  // checks if index given is <0, which would be an invalid index
  if (i < 0) {
    throw string("Out of bounds");
  }
  // convert i to unsigned int
  i = (unsigned int) i;
  // checks if the index given is greater than the bounds of the map
  if (i > num_of_elements) { // should this be >= ?
    throw string("Out of bounds");
  }
  
  //Row Calculation
  int row = first_block * ((first_element + i) / block_size);

  //Column Calculation
  int col = (first_element + i) % block_size;

  //Index && Return
  return blockmap[row][col];
}











#endif //DEQUE_H
