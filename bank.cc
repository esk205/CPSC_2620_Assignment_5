//************************************************************************
// CPSC2620 Spring 2016
// Assignment #4  Bank Simulation Project
// File: bank.h
// Definition file for Bank class
// Written by: Arie
// Date: Feb 24, 2016
//************************************************************************

#include"./bank.h"
#include"./customer.h"
#include"./config.h"
#include"./result.h"
#include<list>
#include<queue>
using namespace std;

int Customer::idProduce=0;

Bank::Bank(const Config& c)
{
   numTellers = c.getNumAgts();
   initCust = c.getNumInitClients();
   policy = c.getPolicy(); // priority default is set to
   maxNewCust = c.getMaxNew();
   taskMax = c.getTaskMax();
}

void Bank::runSimulation()
{
   int tTime, newCust;
   // Get the first customers into the queue.  Sets a random task time b/w 1
   // and taskMax.  Puts into the queue or priority_queue depending on policy
   // type FCFS - first come first served or SJF - shortest job first.
   for(int i=0; i<initCust; i++)
   {
      tTime = rand() % taskMax + 1; // tasktime
      Customer c(tTime);
      c.enteredAt(0);
      if(policy == "FCFS")
		line.push(c);
      else // SJF
		 pLine.push(c);
   }

   for(int t=0; t<480; t++) // start clock
   {
      if((t+1) % 10 == 0) // if 10 min has passed put more cust in queue
      {
		newCust = rand() % maxNewCust + 1;
		 for(int j = 0; j<newCust; j++)
		 {
			tTime = rand() % taskMax + 1; // get a task time b/w  and 10
			Customer c(tTime,t); // t is the time they entered in bank
			if(policy=="FCFS")
			   line.push(c);
			else
			   pLine.push(c);
		 }
      }
      
      // now start processing customers
      while(atTeller.size() < numTellers && (!line.empty() || !pLine.empty()))
      {
	 Customer c;
	 if(policy == "FCFS")
	 {
	    c = line.front();
	    line.pop();
	 }
	 else
	 {
	    c = pLine.top();
	    pLine.pop();
	 }
	 c.servedAt(t);
	 atTeller.push_back(c); // put into list of customers at teller
      }
      list<Customer> remove;
      for (auto it = atTeller.begin(); it != atTeller.end(); ++it)
      {
	 if (it->finishTime() <= t)
	 {
	    Customer done = *it;
	    remove.push_back(done);
	    //cout << *c << " finished" << endl;
	 }
      }
      for (Customer c : remove)
      {
		 atTeller.remove(c);
		 doneTask.push_back(c);
      }

      remove.clear();
   }
}

Result Bank::result()
{
   Result r;
   unsigned ttlTime = 0;
   unsigned numberNotServed;
   //cout << "Customers Served: " << doneTask.size() << endl;
   r.served(doneTask.size());

   numberNotServed = (policy=="FCFS" ? line.size() : pLine.size());
   //cout << "Number not served: " << numberNotServed << endl;
   r.noService(numberNotServed);
   for(deque<Customer>::iterator it = doneTask.begin();
       it != doneTask.end(); ++it)
   {
      //cout << "Wait time: " << it->waitTime() << endl;
      ttlTime += it->waitTime();
   }
   r.avgWait(ttlTime/doneTask.size());

   for(auto c : doneTask)
   {
      if(c.waitTime() <= 5)
	 r.le5(1);
      else if(c.waitTime() <=10)
	 r.le10(1);
      else if(c.waitTime() <=20)
	 r.le20(1);
      else if(c.waitTime() <=60)
	 r.le60(1);
      else if(c.waitTime() >60)
	 r.m60(1);
   }
   
   
   return r;
}
      
/*   else
   {
      priority_queue<Customer> l1;
      for(int i=0; i<initCust; i++)
	 l1.push(rand() % 100 +1);
   }
*/
