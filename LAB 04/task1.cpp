#include<iostream>

using namespace std;



class car{
	private :
	string brand;
	string model;
	float price;
	bool avail;
	
	public :
	
	car(){
		
		brand ="unknown";
		model = "generic";
		price = 0;
		avail = 1;
	}
	
	
	void setcar(string brandd, string m, float rent, bool a){
		
		brand =brandd;
		model = m;
		price = rent;
		avail =  a;
	}
	
	void request(){
		
		if(!avail){
			cout << "not avialble, car already rented" << endl;
		}else if(avail){
			
			cout << "car available , booked" << endl;
			
			
			avail = 0;
		}
	}
};

int main (){
	
	car c1;
	
	c1.request();
	
	
	return 0;
}
