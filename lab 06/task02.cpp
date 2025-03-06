#include<iostream>

using namespace std;

class Vehicle {
	protected :
		
	string brand;
	int speed;
	
	public :
		
		Vehicle(string b, int s) : brand(b), speed(s){}
		
		void display(){
			cout << "Vehicle details :" << endl;
			cout << "-------------------------------" << endl;
			cout << "brand : " << brand << endl;
			cout << "speed : " << speed << " mph" << endl;
		}
	
	
};

class Car : public Vehicle {
	protected :
		int seats;
		
		public :
			
			Car(string b, int s, int seatsss) : Vehicle(b,s), seats(seatsss){}
			
			void display() {
				Vehicle :: display();
				cout << "seats : " << seats << endl;
			}
			
};

class Electriccar : public Car{
	protected :
		
	int batterylife;
	
	public : 
	
	Electriccar(string b, int s, int seatsss, int life) : Car(b,s, seatsss) , batterylife(life){}
	
	void display(){
		Car :: display();
		cout << "battery life : " << batterylife << " years " << endl;
	} 
	
};

int main (){
	
	Electriccar e1("tesla", 240, 4, 10);
	
	e1.display();
}
