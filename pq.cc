// ********************************************************************
// CPSC2620 Spring 2016
// File Name: queue.cc
// Purpose: Implementation file for the Queue class functions
// Created on: Mar 24, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include"./pq.h"
#include<iostream>
using namespace std;

template<typename T>
Priority_Queue<T>::Priority_Queue() // Default constructor
{
   // An empty Queue has just two points and a dummy node. 
   // The dummy node makes it easier to add (push) nodes onto Queue.
   headPtr = new Node(); // creates dummy node
   tailPtr = headPtr; // tailPtr now points to what headPtr points so
}
template<typename T>
Priority_Queue<T>::~Priority_Queue() // Destructor
{
   deallocate();      // entire Queue excluding dummy node
   delete headPtr;    // delete dummy node
   headPtr = nullptr; // set headPtr to null
   tailPtr = nullptr; // set tailPtr to null
}
template<typename T>
void Priority_Queue<T>::deallocate() // deallocates everything except the dummy node
{
   if(!empty()) // Executes unless Queue is empty
   {
      Node* tempPtr = headPtr; // node pointer (acts like iterator)
	  while (tempPtr != nullptr)// go through Queue and delete the nodes
	  {
	     if (tempPtr->nextPtr == tailPtr)
	     {
			tailPtr = tempPtr; // move tail pointer to 2nd from front position
			tempPtr = tempPtr->nextPtr; // point tempPtr to the next pointer
			tailPtr->nextPtr = nullptr; // set the front nodes nextPtr to null

			delete tempPtr; // advance the front object to the next
			tempPtr = headPtr; // reset tempPtr back to the start of the Queue	  
	     }	
		 tempPtr = tempPtr->nextPtr; // move the tempPtr to the next node in the queue
	  }	
 	  delete tempPtr; // deletes the last node in the queue (except the dummy node
    }
}
template<typename T>
Priority_Queue<T>& Priority_Queue<T>::operator=(const Priority_Queue<T>& QueueToCopy) // Overloaded assignment operator
{
   if(this!=&QueueToCopy)
   {
      deallocate();  // overwrite all nodes for the left
      copy(QueueToCopy); // copy all nodes to the empty Queue
      return *this;  // return queue object
   }
   return *this;  // return queue object
}
template<typename T>
Priority_Queue<T>::Priority_Queue(const Priority_Queue& QueueToCopy) // Copy constructor
{
   headPtr = new Node(); // Creates the dummy node 
   tailPtr = headPtr;    // reset the Queues tailPtr
   copy(QueueToCopy);    // copy all nodes to the Queue
}
template<typename T>
void Priority_Queue<T>::copy(const Priority_Queue& QueueToCopy) // MODIFY
{
   Node* tempPtr = headPtr->nextPtr; // acts like a iterator
   while(tempPtr->nextPtr!=nullptr) // traverse the queue
   {
      this->push(tempPtr->data); // push data into queue 
      tempPtr = tempPtr->nextPtr; // move the tempPtr to the next node
   }
   tailPtr = tempPtr->nextPtr; // tailPtrs is now pointing at the front node
}
template<typename T>
bool Priority_Queue<T>::empty() const // Checks if Queue is empty
{
   return headPtr == tailPtr; // check if headPtr is pointing at tailPtr
}
template<typename T> 
ostream& Priority_Queue<T>::operator<<(ostream &out, const Priority_Queue& q)
{
	while (!q.empty) // Check if queue is not empty
	{
		out << q.push << ' '; // display the node then push off queue
	}
   return out; // return output
}
// Returns the first value of the Queue but does not remove it
template<typename T>
int Priority_Queue<T>::front()
{
   if(!empty()) // if the queue is not empty
   { 
      return tailPtr->data; // returns the front queues data
   }
   return 0; // default value if there's no front node
}
// Adds a value to the Queue
template<typename T>
void Priority_Queue<T>::push(int val)
{
   headPtr->nextPtr = new Node(val, headPtr->nextPtr); // add a node to the queue
   if(empty) // True if Queue has no nodes (besides dummy node)
   {
      tailPtr = headPtr->nextPtr; // move tailPtr
   }
   /*
   else if () find min value
   {
		  // assume the first node is the smallest
   }
   else if () // find max
   {
		 // assume the first node is the largest
   }
   else { // find the median value
	   Node* tempPtr = headPtr->nextPtr; // acts like a iterator
	   Node* median = nullptr; // points to the median node
	   bool done = false; // flag to stop the loop
	   // swap nodes by comparing it the nodes with median node
	   while (done)
	   {	   
		   tempPtr = tempPtr->nextPtr; // move the tempPtr
	   }
   }
   */
}
// Removes the first value in the Queue and returns it
template<typename T>
int Priority_Queue<T>::pop() {
   int firstValData = tailPtr->data; // copy the data of the front node
   delete tailPtr;      // delete first value in the Queue
   tailPtr = nullptr;   // ensures no dangling pointer
   Node* tempPtr = headPtr->nextPtr; // acts like a iterator  
   while(tempPtr != nullptr) // find the front of Queue
   {
      if(tempPtr->nextPtr == nullptr) // check if the node points to null
      {
       	 tailPtr = tempPtr; // make tailPtr point the front node
      }
      tempPtr = tempPtr->nextPtr; // look at the next nodes "nextPtr"
   }
   delete tailPtr;      // delete first value in the Queue
   tailPtr = tempPtr;   // ensures no dangling pointer
   return firstValData;
}
// Returns the number of values in the Queue
template<typename T>  
int Priority_Queue<T>::size()
{
   int sizeOfQ = 0; // number of values in the Queue
   Node* tempPtr = headPtr->nextPtr; // acts like a iterator
   for (int i = 0; tempPtr != nullptr; i++)
   {
      sizeOfQ++; // increases sizeofQ by 1
      tempPtr = tempPtr->nextPtr; // Move on to the next node
   }
   return sizeOfQ; // return the size of the Queue
}

   


