#include<iostream>
#include<cstring>
using namespace std;

class Apartment {
	
	int id;
	string address;
	char *name;
	
	public :
		
		Apartment(int id, string address,const char* namee){
			this->id = id;
			this->address = address;
			int x = 0;
			
			name = new char[strlen(namee)+1];
			strcpy(name, namee);
		}
		
		Apartment(const Apartment &obj){
			this->id = obj.id;
			this->address =obj.address;
			this->name = obj.name;
		}
		
		void display(){
			cout << "name : " << name << endl;
			cout << "id : " << id << endl;
			cout << "address : " << address << endl;
		}
		
		~Apartment(){
			delete []name;
		}
};

int main () {
	
	Apartment a1(001, "d-180, rufi fountain, johar", "Abdul Rafay Paracha");
	a1.display();
	
	cout << "-----------------------------------" << endl;
	Apartment a2 = a1;
	
	a2.display();
	return 0;
}
