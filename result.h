//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: result.h
// Definition file for Result class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#ifndef RESULT_H
#define RESULT_H
#include<iostream>
using namespace std;

class Result
{
  public:
   Result(unsigned int=0,unsigned int=0,unsigned int=0,unsigned int=0,
	  unsigned int=0,unsigned int=0,unsigned int=0,unsigned int=0);
   unsigned int getCustServed() const;
   unsigned int getNotServed() const;
   unsigned int getWaitTime() const;
   void served(unsigned int);
   void noService(unsigned int);
   void avgWait(unsigned int);
   void le5(unsigned int);
   void le10(unsigned int);
   void le20(unsigned int);
   void le60(unsigned int);
   void m60(unsigned int);

  private:
   unsigned custServed;
   unsigned int notServed;
   unsigned avgWaitTime;
   unsigned int numLE5;
   unsigned int numLE10;
   unsigned int numLE20;
   unsigned int numLE60;
   unsigned int numM60;
   friend ostream& operator<<(ostream&, const Result&);
};
bool operator<(const Result&, const Result&);
#endif

   
