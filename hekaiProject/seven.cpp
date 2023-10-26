#include<iostream>
using namespace std;

class Account{
private:
	int id;
	double balance,rate;  //balanceһ��Ҫdouble���ͣ��������ʧ���� 
	char type;
public:
	Account(int id,char type,double balance,double rate=0.005); //Ĭ�ϲ��� 
	Account(const Account &b);
	void calrate();
	void display();
};

Account::Account(int id,char type,double balance,double rate):id(id),type(type),balance(balance),rate(rate){}
Account::Account(const Account &b)
{
	rate=0.015;
	id=b.id+50000000;
	type=b.type;
	balance=b.balance;
} 

void Account::calrate()
{
	balance=(1+rate)*balance;
	cout<<"Account="<<id<<"-sum="<<balance<<endl;
}

void Account::display()
{
	cout<<"Account="<<id;
	if(type=='P') cout<<"-Person-";
	else cout<<"-Enterprise-";
	
	cout<<"sum="<<balance<<"-rate="<<rate<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int id;
		double balance;
		char type;
		cin>>id>>type>>balance;
		Account a1(id,type,balance);
		Account a2(a1);   //�������Ҫ���̿��� 
		
		char op1,op2;
		cin>>op1>>op2;
		
		if(op1=='C')
		{
			a1.calrate();
		}
		else
		{
			a1.display();
		}
		
		if(op2=='C')
		{
			a2.calrate();
		}
		else
		{
			a2.display();
		}
	}
	return 0;
}

/*
2
12345678 P 10000
C P
23456789 E 20000
P C
*/

//output
/*
Account=12345678�Csum=10050
Account=62345678�CPerson�Csum=10000�Crate=0.015
Account=23456789�CEnterprise�Csum=20000�Crate=0.005
Account=73456789�Csum=20300
*/
