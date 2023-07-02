#ifndef BUS_H
#define BUS_H

#include<string>
#include <iostream>
using namespace std;
  // Class members and function prototypes here
  class Bus
{
    string busno, driver, arrival, depart, from, to;
    char seat[8][4][10];

  public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
} bus[10];


#endif