/*
 * class.h
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#ifndef CLASS_H_
#define CLASS_H_

#include<iostream>
#include<iomanip>

using namespace std;

class insufficient_funds
{
	private:
		int acc_id;
		double current_balane;
		double withdraw_amount;
	public:

		insufficient_funds(int id,double balance,double amount);
		void display();
};


class account
{
	enum accountType
	{
		SAVING=1, CURRENT, DEMAT
	};
	private:
		int id;
		int accounttype;
		double balance;
	public:
		account();
		account(int id, int accounttype, double balance);
		void accept();
		void display();
		void set_id(int id);
		void set_accounttype(int type);
		int getId();
		int getType();
		double getBalance();
		void deposit(double amount);
		void withdraw(double amount) throw (insufficient_funds);
};

int menu();



#endif /* CLASS_H_ */
