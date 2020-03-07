#include<iostream>
#include<iomanip>
#include "class.h"

using namespace std;

int main ()
{
	int num=0;
	int amt=0;
	int choice;
	account arr[5];

	while((choice=menu())!=0)
	{
		switch(choice)
		{
			case 1:
				for(int i=0;i<5;i++)
				{
					arr[i].accept();
					arr[i].display();
				}
				break;
			case 2:
				for(int i=0;i<5;i++)
				{
					arr[i].display();
				}
				break;
			case 3:

				cout<<"enter account id";
				cin>>num;
				cout<<"enter deposit amount";
				cin>>amt;
				try
				{
					for(int i=0;i<5;i++)
					{
						if (arr[i].getId()==num)
						{
							arr[i].deposit(amt);
							cout<<"your updated account balance is "<<arr[i].getBalance()<<"	Rs."<<endl;
						}
					}
					throw 1;
				}
				catch(int a)
				{
					cout<<"enter valid account id";
				}
				break;
			case 4:
				cout<<"enter account id";
				cin>>num;
				cout<<"enter withdraw amount";
				cin>>amt;
				try
				{
					try
					{
						for(int i=0;i<5;i++)
						{
							if (arr[i].getId()==num)
							{
								arr[i].withdraw(amt);
								cout<<"your updated account balance is "<<arr[i].getBalance()<<"Rs."<<endl;
							}
						}
						throw 1;
					}
					catch(insufficient_funds &error)
					{
						error.display();
					}

				}
				catch(int a)
				{
					cout<<"enter valid account id";
				}

				break;
		}
	}
	return 0;
}



