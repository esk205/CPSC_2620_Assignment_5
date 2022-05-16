// ********************************************************************
// CPSC2620 Spring 2016
// File Name: queue.h
// Purpose: Defines the prototype class methods and class members
// for the class Queue. Also a nested class Node is created
// in order to create Node objects with its own data and pointers
// Created on: Mar 19, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#ifndef PQ_H
#define PQ_H
#include<iostream>
using namespace std;

template<typename T>
class Priority_Queue 
{
  public :
	Priority_Queue();  // default constructor
   ~Priority_Queue(); // destructor (deletes all "new" variables)
   void deallocate(); // helper function for the destructor
 
   // Accessor methods  
   bool empty() const;  // returns true if the queue is empty
   ostream & operator<<(ostream & out, const Priority_Queue & q);
   int size();   // returns the number of values in the queue

   // Modifier methods
   int  front(); // returns the first value in the queue without modifying it
   void push(int); // adds a value to the queue (in PQ the items are kept in order)
   int  pop(); // removes the first value in the queue and returns it

   Priority_Queue& operator=(const Priority_Queue&);// overloaded assignment operator
   Priority_Queue(const Priority_Queue&); // copy constructor
   void copy(const Priority_Queue&); // helper function for copy constructor
   
  private:
   class Node // nested class
   {
      friend class Priority_Queue; // let sList have access to my private data
      public :
     Node(int item = 0, Node* node=nullptr) : data(item), nextPtr(node) {}
     private :
      int data;
      Node* nextPtr;
   };
   Node* headPtr;
   Node* tailPtr;
};
#include "./pq.cc"
#endif
   
      
   
   
