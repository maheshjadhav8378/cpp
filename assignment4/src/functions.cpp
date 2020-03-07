#include<iostream>
#include<iomanip>
#include "class.h"

using namespace std;


account::account():id (0),accounttype(SAVING),balance(0.00){ }

account::account(int id, int accounttype, double balance)
{

this->id=id;
this->accounttype=accounttype;
this->balance=balance;

}

void account::accept()
	{
		cout<<"\nenter account number"<<endl;
		cin>>this->id;

		cout<<"1.SAVING\n2.CURRENT\n3.DEMAT"<<endl;
		cout<<"enter account type	:"<<endl;
		cin>>this->accounttype;

		cout<<"enter account balance"<<endl;
		cin>>this->balance;
	}

void account::display()
{
	cout<<"ACCOUNT INFO	:"<<endl;
	cout<<"account number	:"<<this->id<<endl;

	cout<<"account type	:"<<this->accounttype<<endl;

	cout<<"account balance	:"<<this->balance<<endl;
}

void account::set_id(int id)
{
	this->id=id;
}
void account::set_accounttype(int type)
{
	this->accounttype=type;
}

int account::getId()
{
	return this->id;
}

int account::getType()
{
	return this->accounttype;
}

double account::getBalance()
{
	return this->balance;
}

void account::deposit(double amount)
{
	this->balance=this->balance+amount;
}

void account::withdraw(double amount) throw (insufficient_funds)
{

	if(this->balance<amount)
	{
		throw insufficient_funds(this->id,this->balance,amount);
	}
	this->balance=this->balance-amount;
}

insufficient_funds::insufficient_funds(int id,double balance,double amount)
{
	this->acc_id=id;
	this->current_balane=balance;
	this->withdraw_amount=amount;

}
void insufficient_funds::display()
{
	cout<<"INSUFFICIENT BALANCE!!!!!"<<endl;
	cout<<"account id	:"<<this->acc_id<<endl;
	cout<<"account current balance	:"<<this->current_balane<<endl;
	cout<<"withdraw	amount:"<<this->withdraw_amount<<endl;
}

int menu()
{
	int choice;
	cout<<"\n0.EXIT\n1.accept details\n2.display details\n3.deposit\n4.withdraw\nEnter choice	:\n"<<endl;
	cin>>choice;
	return choice;
}

