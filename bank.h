//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: bank.h
// Definition file for Bank class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#ifndef BANK_H
#define BANK_H

#include<string>
#include<queue>
#include<list> // allows for efficient removal of items 
#include<deque> // allows for push_front as well as push_back
#include"./result.h"
#include"./config.h"
#include"./customer.h"
using namespace std;

class Bank
{
  public:
   Bank(const Config&); // can only create a bank object with a config
   void runSimulation(); // run a bank simulation
   Result result(); // process the results of the simulation
   
  private:
   unsigned numTellers;
   int initCust;
   string policy; // First Come First Served or Shortest Job First
   unsigned maxNewCust, taskMax;
   queue<Customer> line; // queue for first come first served (FCFS)
   priority_queue<Customer> pLine; // priority queue for customers
   deque<Customer> doneTask; // deque of finished customers
   list<Customer> atTeller; // list of customers currently being serviced.
   
};
#endif
   
   
