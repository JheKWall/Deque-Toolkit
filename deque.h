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
  unsigned int size, mapsize, blocksize, first_block, first_element;
  
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
  T &operator[](int index);
};

template <typename T>
T &operator[](int index) {

  if (index < 0 || index > size) {
    cout << "Invalid Index" << endl;
    return;
  }
  
  //Row Calculation
  int row = first_block * ((first_element + i) / block-size);

  //Column Calculation
  int col = (first_element + i) % block_size;

  //Index && Return
  return blockmap[row][col];
}












#endif //DEQUE_H
