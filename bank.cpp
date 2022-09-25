#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class Bank
{
	public:
	char B_name[100],B_address[100],manager[100];
	int Br_no;
	Bank(char name[],char address[],char man[],int no)
	{
		strcpy(B_name,name);
		strcpy(B_address,address);
		strcpy(manager,man);
		Br_no=no;
	}
};
class Account
{
	public:
	char acc_no[9];
	float bal;
	Account()
	{
		strcpy(acc_no,"00000000");
		bal=0.00;
	}
	virtual void get_bal(){}
	virtual float deposit(){return 0;}
	virtual float withdraw(){return 0;}
	~Account(){};
};
class savings:virtual public Account
{
	public:
	savings():Account(){}
    float amount;
	float deposit()
	{
		cout<<"Enter the Amount to Deposit: ";
	    cin>>amount;
	    bal+=amount;
	    return bal;
	}
	float withdraw()
	{
		cout<<"Enter the Amount to Withdraw: ";
	    cin>>amount;
	    bal-=amount;
	    return bal;
	}
};
class checking:virtual public Account
{
	public:
	void get_bal()
	{
		cout<<"Balance: "<<bal<<endl;
	}
};
class customer
{
    public:
    char C_name[100],C_address[100];
};
class employee
{
    public:
	char E_name[100],E_address[100],desig[100];
	int salary;
};
class Person:public savings,public checking,public customer,public employee
{
	friend void operator -(Person p1)
	{
		p1.bal-=1.50;
	}
};
int main()
{
	char name[100],address[100],man[100];
	int no;
	cout<<"Enter Bank Name: ";
	cin>>name;
	cout<<"Enter Bank Address: ";
	cin>>address;
	cout<<"Enter Bank Manager Name: ";
	cin>>man;
	cout<<"Enter Branch Number: ";
	cin>>no;
	Bank b1(name,address,man,no);
	Person acc[100];
	int spos=0,i;
	char accno[9];
	cout<<setfill('=')<<setw(40)<<'='<<endl,
	cout<<"\t\tMAIN MENU"<<endl,
	cout<<"\n1. NEW ACCOUNT\n2. DEPOSIT AMOUNT\n3. WITHDRAW AMOUNT\n4. BALANCE ENQUIRY",
	cout<<"\n5. CUSTOMER LIST\n6. CLOSE ACCOUNT\n7. MODIFY ACCOUNT\n8. EXIT"<<endl,
	cout<<setfill('=')<<setw(40)<<'=';
	int choice;
	while(1)
	{
		cout<<"\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n\tACCOUNT CREATION\n";
				cout<<"Enter a 8 Digit Account Number: ";
				cin>>acc[spos].acc_no;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<=spos;i++);
				if(i>=spos)
				{
				    cout<<"Enter the Customer Name: ";
				    cin>>acc[spos].C_name;
				    cout<<"Enter the Customer Address: ";
				    cin>>acc[spos].C_address;
				    spos++;
				}
				else
				    cout<<"\nAccount Exist\n";
				break;
			case 2:
				cout<<"\n\tAMOUNT DEPOSIT\n";
				cout<<"Enter the 8 Digit Account Number to Deposit: ";
				cin>>accno;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<spos;i++);
				if(i<spos)
				{
				    acc[i].bal=acc[i].deposit();
				    -acc[i];
				}
				else
				    cout<<"\nACCOUNT NOT FOUND\n";
				break;
			case 3:
				cout<<"\n\tAMOUNT WITHDRAW\n";
				cout<<"Enter the 8 Digit Account Number to Withdraw: ";
				cin>>accno;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<spos;i++);
				if(i<spos)
				{
				    acc[i].bal=acc[i].withdraw();
				    -acc[i];
				}
				else
				    cout<<"\nACCOUNT NOT FOUND\n";
				break;
			case 4:
				cout<<"\n\tCHECK BALANCE\n";
				cout<<"Enter the 8 Digit Account Number to Check Balance: ";
				cin>>accno;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<spos;i++);
				if(i<spos)
				    acc[i].get_bal();
				else
				    cout<<"\nACCOUNT NOT FOUND\n";
				break;
			case 5:
				cout<<"\n\tCUSTOMER LIST\n";
				cout<<setfill('=')<<setw(40)<<'='<<endl;
				cout<<"\nCUSTOMER\tBALANCE\n";
				for(i=0;i<spos;i++)
				{
				    cout<<i+1<<". "<<acc[i].C_name<<"\t\t"<<acc[i].bal<<endl;
			    }
				cout<<endl<<setfill('=')<<setw(40)<<'='<<endl;
				break;
			case 6:
				cout<<"\n\tACCOUNT DELETION\n";
				cout<<"Enter the 8 Digit Account Number to Delete: ";
				cin>>accno;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<spos;i++);
				if(i<spos)
				{
					int j;
				    for(j=i;j<spos;j++)
					    acc[j]=acc[j+1];
					    spos--;
			    }
			    else
				    cout<<"\nACCOUNT NOT FOUND\n";
				break;
			case 7:
				cout<<"\n\tACCOUNT MODIFICATION\n";
				cout<<"Enter the 8 Digit Account Number to Modify: ";
				cin>>accno;
				for(i=0;strcmp(accno,acc[i].acc_no)!=0&&i<spos;i++);
				if(i<spos)
				{
				    cout<<"Enter the Customer Name: ";
				    cin>>acc[i].C_name;
				    cout<<"Enter the Customer Address: ";
				    cin>>acc[i].C_address;
				}
				else
				    cout<<"\nACCOUNT NOT FOUND\n";
				break;
			default:
				exit(0);
		}
	}
	return 0;
}