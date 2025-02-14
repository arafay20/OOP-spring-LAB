#include<iostream>
using namespace std;

class wallet {
	
	string name;
	double totalbalance;
	string transaction[100];
	int transactioncount;
	
	public :
		
		wallet(string namee, double balance){
			name =  namee;
			totalbalance = balance;
			transactioncount = 0;
		}
		
		void addmoney(double amount){
			
			
			if(transactioncount <= 100){
				totalbalance+= amount;
				transactioncount++;
				
				transaction[transactioncount] = to_string(amount) + "added!";
			}
			
			cout << amount << " amount added!" << endl;
			
			
		}
		
		void spendmoney(double amount){
			if(amount > totalbalance){
				cout<< "not enough balance !" <<endl;
			}
			else if(transactioncount <= 100){
				totalbalance-= amount;
				transactioncount++;
				
				transaction[transactioncount] = to_string(amount) + " spent";
				cout << amount << "amount spent!" << endl;
			}
			
			
		}
		
		void transactionhistory(){
			 
			 cout << "transaction history : " ;
			 
			 for(int i=0 ;i<= transactioncount ; i++){
			 	cout << transaction[i] << endl;
			 }
			 
		}
};

int main (){
	wallet a1("saad", 1100);
	
	a1.addmoney(50);
	a1.spendmoney(3330);
	a1.addmoney(20);
	a1.transactionhistory();
	
	return 0;
	
		
}
