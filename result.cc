//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: result.cc
// Implementation file for Result class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#include"./result.h"
#include<iomanip>
using namespace std;

Result::Result(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e,
	       unsigned f,
	       unsigned g, unsigned h)
{
   custServed = a;
   notServed = b;
   avgWaitTime = c;
   numLE5 = d;
   numLE10 = e;
   numLE20 = f;
   numLE60 = g;
   numM60 = h;
}

void Result::served(unsigned int n)
{
   custServed = n;
}
void Result::noService(unsigned int n)
{
   notServed = n;
}
void Result::avgWait(unsigned t)
{
   avgWaitTime = t;
}

void Result::le5(unsigned int n)
{
   numLE5 += n;
}
void Result::le10(unsigned int n)
{
   numLE10 += n;
}

void Result::le20(unsigned int n)
{
   numLE20 += n;
}
void Result::le60(unsigned int n)
{
   numLE60 += n;
}

void Result::m60(unsigned int n)
{
   numM60 += n;
}


unsigned int Result::getCustServed() const
{
   return custServed;
}
unsigned int Result::getNotServed() const
{
   return notServed;
}
unsigned int Result::getWaitTime() const
{
   return avgWaitTime;
}

bool operator<(const Result& r1, const Result& r2)
{
   //cout << r2.getCustServed() << ' ' << r1.getCustServed() << endl;
   if(r1.getCustServed() == r2.getCustServed())
   {
      if(r1.getNotServed() == r2.getNotServed())
	 return r1.getWaitTime() < r2.getWaitTime();
      return r1.getNotServed() < r2.getNotServed();
   }
   return r1.getCustServed() > r2.getCustServed();
}

ostream& operator<<(ostream& oStr, const Result& r)
{
   cout << setw(4) << r.custServed << setw(4) << r.notServed << setw(4)
	<< r.avgWaitTime << " (" << setw(4) << left << r.numLE5 << right
	<< setw(4) << r.numLE10 << setw(4) << r.numLE20 << setw(3) << r.numLE60
	<< setw(4) << r.numM60 << ')';
   return oStr;
}
