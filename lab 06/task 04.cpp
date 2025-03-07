#include<iostream>
using namespace std;

class Account{
	protected :
	int accnum;
	float balance;
	
	public :
		Account(int acc,float bal ) : accnum(acc), balance(bal) {}
		
		void display(){
			cout << "====================================" << endl;
			cout << "Account number : " << accnum << endl;
			cout << "Balance : " << balance << endl;
			 
		}
		
		
};

class Savingsaccount : public Account {
	
	protected :
		float interestrate;
		
		public : 
		
		Savingsaccount(int acc,float bal, float rate) : Account(acc, bal) , interestrate(rate){}
		
		void display(){
			cout << "====================================" << endl;
		    cout << "Savings Account details :" << endl ; 
		    Account::display();
			cout << "Interest Rate : " << interestrate << endl; 
			cout << "====================================" << endl;	
		     	
		}
		
};

class Checkingsaccount : public Account{
	protected : 
	
	float limit;
	
	public :
		Checkingsaccount(int acc,float bal, float maxlimit) : Account(acc, bal) , limit(maxlimit) {}
		
		void display(){
			 cout << "====================================" << endl;
			 cout << "Checkings Account details :" << endl ;
			 Account::display();
			 cout << "Overdraft limit : " << limit << endl;
			 cout << "====================================" << endl;
		}
};

int main () {
	
	Savingsaccount s(1001, 50000, 2.5);
	s.display();
	
	Checkingsaccount c(1002, 150000, 500000);
	c.display();
	
	return 0;
}
