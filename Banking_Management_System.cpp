#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Bank
{
int amt,acno;
string name,actyp;
public:
void input()
{
	 acno=rand();
	 cout<<"Enter Customer Name: ";
	 cin.ignore();
	 getline(cin,name);
	 cout<<"Enter Account type: ";
	 cin>>actyp;
	 cout<<"Enter the Amount: ";
	 cin>>amt;
}
friend void display(Bank);
int show_amt()
{
return(amt);
}
int show_acno()
{
return(acno);
}
int deposit()
{
int d;
cout<<"\nEnter the amount to be deposit: ";
cin>>d;
amt+=d;
return amt;
}
int withdraw()
{
int w;
if(amt<500)
{
cout<<endl;
cout<<"\nError!!! Insuficient Balance! Your last transaction was cancelled";
exit(1);
}
else
{
cout<<"\nEnter the amount to be withdrawn: \n";
cin>>w;
amt-=w;
cout<<"\nAmount successfully withdrew";
}
return amt;
}
};
void display(Bank obj)
{
cout<<"Account No : "<<obj.acno<<endl;
cout<<"Name : "<<obj.name<<endl;
cout<<"Account Type : "<<obj.actyp<<endl;
cout<<"Amount : "<<obj.amt<<endl;
}
int main()
{
Bank B1[10];
int account,amount,i,ch,check=0;
do
{
start:
	cout<<"\n\t     *********BANKING*********\n";
	cout<<"\t\tEnter Your Choice: \n";
	cout<<"\t\t1.CREATE ACCOUNT\n";
	cout<<"\t\t2.DEPOSIT\n";
	cout<<"\t\t3.WITHDRAW\n";
	cout<<"\t\t4.DISPLAY ALL ACCOUNT\n";
	cout<<"\t\t5.SEARCH\n";
	cout<<"\t\t0.EXIT\n";
	cin>>ch;
	switch(ch)
	{
	case 1:
		int cust;
		cout<<"Enter Number of Customers : ";
		cin>>cust;
		for(i=0;i<cust;i++)
		{
		  cout<<i+ 1<<". ACCOUNT\n";
		  B1[i].input();
		  cout<<"\n";
		  cout<<"Account Created Successfully\n\n";
		}
		break;
	case 2:
		cout<<"\nEnter the Account No:";
		cin>>account;
		for(i=0;i<cust;i++)
		{
		 if(account==B1[i].show_acno())
		 {
		   B1[i].deposit();
		   cout<<"\nAmount Successfully Deposit\n";
		   check=1;
		 }
		}
		if(!check)
		{
		  cout<<"\nSorry! Account Not Found :(";
		}
		break;
case 3:
		cout<<"\nEnter the account No:";
		cin>>account;
		for(i=0;i<cust;i++)
		{
		 if(account==B1[i].show_acno())
		 {
		   B1[i].withdraw();
		   check=1;
		 }
		}
		if(!check)
		{
		 cout<<"\nSorry! Account Not Found :(";
		}
		break;
case 4:
		int a;
		cout<<"\tALL ACCOUNT DISPLAY:\n";
		cout<<"==================================\n";
		for(i=0;i<cust;i++)
		{
		 if(B1[i].show_acno()==0)
		    return 0;
		 cout<<i+1<<". ACCOUNT\n";
		 cout<<"\n--------------------------------------\n";
		 display(B1[i]);
		 cout<<"\n=====================================\n";
		}
		break;
case 5:
		int search;
		cout<<"\nEnter Account Number to search: ";
		cin>>search;
		for(i=0;i<cust;i++)
		{
		 if(search==B1[i].show_acno())
		 {
		   cout<<endl<<i+1<<". ACCOUNT\n";
		   display(B1[i]);
		   check=1;
		 }
		}
		if(!check)
		{
		   cout<<"\nThis Acount Not Available....Try Again.\n";
		   goto start;
	      }
		   break;
case 0:
exit(0);
	      break;
default:
cout<<"\nInvalid Choice";
		goto start;
	}
}while(ch!=0);
}
