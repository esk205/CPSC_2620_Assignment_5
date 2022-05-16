// ********************************************************************
// CPSC2620 Spring 2016
// File Name: pqTest.cc
// Purpose: Tests the Queue class
// Created on: Mar 24, 2016
// Author: Michael Wynnychuk
// ********************************************************************
#include "./pq.h"
#include<iostream>
using namespace std;

int main()
{
   Priority_Queue<int> s1,s2;   // Recall queue is: First in, First out
   cout << "The front of the queue s1 is: " << s1.front() << endl;
   s1.push(5);  
   s1.push(7);

   //s1 = s2;
 
   cout << "The queue (s1) has the values: ";
   cout << endl;
/*
   cout << "The queue (s2) has the values: ";
   s2.push(3);
   s2.push(6);
   s2.push(9);
   s2.print();
   cout << endl;

   cout << "The front of queue s1 is: ";
   s1.front();

   cout << endl << "The front of queue s2 is: " << s2.pop() << endl;
   s2.front();
   cout << endl;
   */
   /*
     s.push(5); // pushes a element into queue "s"
     s.pop();   // removes the next element in queue "s"
     s.size();  // returns the number of elements in the queue.
     s.front(); // returns a reference to the next element in the queue
   
     s.print();
   */
   return 0;
}
