//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: customer.h
// Definition file for Customer class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;

class Customer
{
  public:
   Customer(int=5, int=0, int=0, bool = false); //default taskTime,
   int taskTime() const;
   int waitTime() const;
   int finishTime() const;
   void enteredAt(int);
   void servedAt(int);
   bool operator==(const Customer&);
  private:
   int taskMin;
   int enterMin;
   int servedMin;
   bool wasServed;
   int id;
   static int idProduce;

};
bool operator<(const Customer&,const Customer&);
#endif
