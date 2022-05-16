//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: customer.cc
// Implementation file for Customer class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#include"./customer.h"

// Default construct that sets his/her number of minutes to complete task
Customer::Customer(int t, int e, int s, bool ws)
{
   id = Customer::idProduce++;
   taskMin = t;
   enterMin = e;
   servedMin = s;
   wasServed = ws;
}

// returns this customer's task time
int Customer::taskTime() const
{
   return taskMin;
}

// returns the amount of time that this customer waited
int Customer::waitTime() const
{
   return servedMin - enterMin;
}

// returns the time at which this customer was finished
int Customer::finishTime() const
{
   return servedMin + taskMin;
}

// sets the time at which this customer entered bank
void Customer::enteredAt(int eA)
{
   enterMin = eA;
}
// sets the time when this customer got served
void Customer::servedAt(int sA)
{
   servedMin = sA;
}

bool operator<(const Customer& c1, const Customer& c2)
{
   return c1.taskTime() < c2.taskTime();
}

bool Customer::operator==(const Customer& c)
{
   //return this->finishTime() == c.finishTime();
   return this->id == c.id;
}
