# Deque Toolkit Assignment
Jackson Horton, Kenneth Wallace, William Hayes

For this project we created a custom implementation of a deque.

<p align="center">
  <img src="https://user-images.githubusercontent.com/59177560/204605834-115e8f01-0e72-4f10-a867-2ee858a643d7.png" width=50%/>
</p>

# Template Parameter
The deque class uses templated types, so you can use a deque to store any type. You define the type a deque stores when defining it using the standard template syntax:
```
deque<int> = mydeque;
```

# Class parameters
By default, a deque is created as a 2D array (map) that points to 8 dynamic arrays (blocks).
There is also a parameterized constructor that takes a map size and block size to initialize a custom sized deque depending on how it will be used.

### Resizing
When a deque is full on either side and push_front() or push_back() is used, it will resize the deque to have double the block size and double the map size to increase the capacity of the deque before pushing the new element to it.
  
