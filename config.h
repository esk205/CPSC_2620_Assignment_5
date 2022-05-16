//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: config.h
// Definition file for Config class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************
#ifndef CONFIG_H
#define CONFIG_H

#include<string>
#include<iostream>
using namespace std;

class Config
{
  public:
   // numTellers, initial customers, max new cust, task maximum, policy
   Config(int=1,int=5,unsigned=5,unsigned=10,string="FCFS");
   int getNumAgts() const;
   int getNumInitClients() const;
   string getPolicy() const;
   unsigned getTaskMax() const;
   unsigned getMaxNew() const;
  private:
   int numAgts;
   int numInitClients;
   unsigned maxNewCust;
   unsigned taskMax;
   string policyType;
   friend ostream& operator<<(ostream&, const Config&);
};
#endif
