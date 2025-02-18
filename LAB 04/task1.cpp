#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool avail;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        avail = true;
    }
    
    void setCar(string brandd, string m, float rent, bool a) {
        brand = brandd;
        model = m;
        price = rent;
        avail = a;
    }

    void request(int days) {
        if (!avail) {
            cout << "Not available, car already rented." << endl;
        } else {
            
            cout << "Car available, booked!" << endl;
            cout << "Final Rent Price: $" << price << endl;
            avail = false;  
        }
    }

    
    void display() {
        cout << "Brand: " << brand << ", Model: " << model
             << ", Price: $" << price << ", Available: " << (avail ? "Yes" : "No") << endl;
    }
};

int main() {
   
    Car c1;
    
    c1.display();
    c1.request(4);
    c1.display(); 

   

   

    return 0;
}

