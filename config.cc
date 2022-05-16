//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: config.cc
// Implementation file for Config class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#include"./config.h"

Config::Config(int na, int nic, unsigned mnc, unsigned mtt, string t)
{
   numAgts = na;
   numInitClients = nic;
   policyType = t;
   maxNewCust = mnc;
   taskMax = mtt;
}

int Config::getNumAgts() const
{
   return numAgts;
}
string Config::getPolicy() const
{
   return policyType;
}
int Config::getNumInitClients() const
{
   return numInitClients;
}
unsigned Config::getTaskMax() const
{
   return taskMax;
}
unsigned Config::getMaxNew() const
{
   return maxNewCust;
}

ostream& operator<<(ostream& oStr, const Config& c)
{
   oStr << c.numAgts << ' ' << c.numInitClients << ' ' << c.policyType << endl;
   return oStr;
}
