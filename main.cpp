#include "bus1.h"
#include <iostream>
#include <string.h>

using namespace std;
static int p = 0;

void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void Bus::install()
{
  cout<<"Enter bus no: ";
  cin>>bus[p].busno;

  cout<<"\nEnter Driver's name: ";
  cin>>bus[p].driver;

  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;

  cout<<"\nDeparture: ";
  cin>>bus[p].depart;

  cout<<"\nFrom: \t";
  cin>>bus[p].from;

  cout<<"\nTo: \t";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
}
void Bus::allotment()
{
  int seat;
  string number;
  top:
  cout<<"Bus no: ";
  cin>>number;

  int n;
  for(n=0;n<=p;n++)
  {
    if (bus[n].busno==number)
    break;
  }

  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
      if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
        {
          cout<<"Enter passanger's name: ";
          cin>>bus[n].seat[seat/4][(seat%4)-1];
          break;
        }
      else
        cout<<"The seat no. is already reserved.\n";
    }
  }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
}

void Bus::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
      strcpy(bus[p].seat[i][j], "Empty");
  }
}

void Bus::show()
{
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(bus[n].busno==number)
    break;
  }
  while(n<=p)
  {
    vline('*');
    cout<<"\n\t\tBus no: "<<bus[n].busno;
    cout<<"\nDriver: "<<bus[n].driver;
    cout<<"\t\tArrival time: "<<bus[n].arrival<<"\t\tDeparture time:"<<bus[n].depart;
    cout<<"\nFrom:\t"<<bus[n].from<<"\t\tTo:\t"<<bus[n].to<<endl;

    vline('*');
    bus[0].position(n);
    int a=1;
    for (int i=0; i<8; i++)
    {
      for(int j=0;j<4;j++)
      {
        a++;
        if(strcmp(bus[n].seat[i][j],"Empty")!=0)
          cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j];
      }
    }
    break;
  }
    //if(n>p)
      //cout<<"Enter correct bus no: ";
}

void Bus::position(int l)
{

  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busno;
}

void Bus::avail()
{
  for(int n=0;n<p;n++)
  {
    cout<<endl;
    vline('*');
    cout<<"\n\t\t\tBus no: "<<bus[n].busno<<endl;
    cout<<"Driver: "<<bus[n].driver;
    cout<<"\t\tArrival time: \t"<<bus[n].arrival;
    cout<<"\tDeparture Time: "<<bus[n].depart<<endl;
    cout<<"From:\t"<<bus[n].from;
    cout<<"\t\tTo:\t"<<bus[n].to<<endl;
    vline('*');
    cout<<endl;
    

  }
}

int main()
{
  system("cls");
  int w;
  while(1)
  {
      //system("cls");

    cout<<"\n\n\n";
    cout<<"\t\t\t1.Install\n\t\t\t"
    <<"2.Reservation\n\t\t\t"
    <<"3.Show\n\t\t\t"
    <<"4.Buses Available. \n\t\t\t"
    <<"5.Exit";

    cout<<"\n\t\t\tEnter your choice:-> ";
    cin>>w;

    switch(w)
    {
      case 1:  bus[p].install();
        break;
      case 2:  bus[p].allotment();
        break;
      case 3:  bus[0].show();
        break;
      case 4:  bus[0].avail();
        break;
      case 5:  exit(0);
    }
  }
  return 0;

}