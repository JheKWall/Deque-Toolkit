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
 * Deq Parameterized constructor; useful for resizing a deque. Takes a block size and map size
 *
 * @param int block_size the number of ints stored in a block
 * @param int map_size the number of blocks stored in the blockmap
 * @pre 
 * @post A deque has been instantiated with the given parameters
 * 
 */
  deque(int block_size, int map_size);
  
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


/**
 * Prints all the elements in a deque
 *
 * @pre A deque should exist with elements
 * @return void 
 * @post All elements across all blocks are printed to console
 * 
 */
  void print();

/**
 * Resized the internal 2D array of the deque to be twice as large
 *
 * @pre A deque of a temp size
 * @return void 
 * @post The deque is now twice as large as it originally was with the contents still in the 2D array
 * 
 */
  void resize();
};


template <typename T>
void deque<T>::print() {
  // loop through the 2D array
  int row, col;
  for (uint i = 0; i < num_of_elements; i++) {
    row = first_block + ((first_element + i) / block_size);
    col = (first_element + i) % block_size;
    cout << blockmap[row][col] << " ";
  }
  cout << endl;
}


template <typename T>
deque<T>::deque() {
  // set helper variables
  num_of_elements = 0;
  first_block = 3;
  first_element = 3;
  block_size = 8;
  map_size = 8;

  // initialize 2D array
  blockmap = new T*[map_size];

  for (uint row = 0; row < map_size; row++) {
    // fill map with blocks
    blockmap[row] = new T[block_size];
    for (uint column = 0; column < block_size; column++) {
      // initialize all values to 0 in each block
      blockmap[row][column] = 0;
    }
  }
}


template <typename T>
deque<T>::deque(int block_size, int map_size) {
  // set helper variables
  num_of_elements = 0;
  this->block_size = 8;
  this->map_size = 8;
  
  first_block = map_size/4;
  first_element = block_size/4;
 

  // initialize 2D array
  blockmap = new T*[map_size];

  for (uint row = 0; row < map_size; row++) {
    // fill map with blocks
    blockmap[row] = new T[block_size];
    for (uint column = 0; column < block_size; column++) {
      // initialize all values to 0 in each block
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
uint deque<T>::size() {
  return num_of_elements;
}


template <typename T>
void deque<T>::push_front(T n) {
  // calculate the row and column the index 0 element should be at
  int row = first_block;
  int col = first_element;
  cout << "First element at [" << row << "][" << col
       << "]" << endl;

  // move backward one position
  col -= 1;
  // did that break stuff?
  if (col < 0) {
    col = block_size - 1;
    row -= 1;
  }

  // add n at the position before current [0] index
  cout << "Putting " << n << " at [" << row
       << "][" << col << "]" << endl;
  blockmap[row][col] = n;
  
  // adjust member variables
  num_of_elements++;
  first_block = row;
  first_element = col;
}


template <typename T>
void deque<T>::push_back(T n) {
  // calculate the row and column of the last element
  int row = first_block + ((first_element + num_of_elements -1) /block_size);
  int col = (first_element + num_of_elements -1) % block_size;
  cout << "last element at [" << row << "][" << col
       << "]" << endl;

  // move forward one position
  col += 1;

  // did that break something? uh oh too big? big boy go boom?
  if (col >= block_size) {
    col = 0;
    row += 1;
  }

  // set the position after the last element to n
  blockmap[row][col] = n;

  //adjust member variables
  num_of_elements++;
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
  int row = first_block + ((first_element + i) / block_size);

  //Column Calculation
  int col = (first_element + i) % block_size;

  //Index && Return
  return blockmap[row][col];
}











#endif //DEQUE_H
