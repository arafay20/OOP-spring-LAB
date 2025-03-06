#include<iostream>

using namespace std;

class Employee {
	
	private :
		string name;
		float salary;
		
	public :
	
		Employee(string n, float pay) : name(n), salary(pay){}
		
		void display(){
			cout << "Employee details : " << endl ;
			cout << "-----------------------------" << endl;
			cout << "name : " << name << endl;
			cout << "salary : " << salary << endl;
			
		}
};

class Manager : public Employee {
	float bonus ;
	
	public :
		Manager(string n, float pay, float extra) : Employee(n, pay), bonus(extra) {}
		
		void display(){
			Employee::display();
			cout << "bonus : " << bonus << endl;
		}
};

int main (){
	
	Manager m("rafay", 350000, 50000);
	
	m.display();
}
