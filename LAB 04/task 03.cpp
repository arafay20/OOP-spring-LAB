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

    
    Car(string brandd, string m, float rent, bool a) {
        brand = brandd;
        model = m;
        price = rent;
        avail = a;
    }

    
    Car(const Car &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
        avail = other.avail;
    }

   
    ~Car() {}

    
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
            if (days > 5 && days < 10) {
                price *= 0.95;  
            } else if (days >= 10) {
                price *= 0.90;  
            }
            cout << "Car available, booked!" << endl;
            avail = false;  
        }
    }

    void display() {
        cout << "Brand: " << brand << endl;
		cout << "Model: " << model << endl;
        cout << "Price: $" << price << endl;
		cout << "Available: " << (avail ? "Yes" : "No") << endl;
    }
};

int main() {
    
    Car c1;
    cout << "Default Car Details:" << endl;
    c1.display();
    c1.request(4);
    c1.display(); 

    cout << "\n----------------------------------\n";

    Car c2("Toyota", "Corolla", 50.0, true);
    cout << "Before Renting:\n";
    c2.display();
    c2.request(7);  
    c2.display(); 

    cout << "\n----------------------------------\n";

   
    Car c3 = c2;
    cout << "Copied Car Details (Before modification):\n";
    c3.display();

    
    c2.setCar("Toyota", "Camry", 60.0, true);
    cout << "\nAfter modifying original car details:\n";
    c2.display();
    cout << "Copied Car Details:\n";
    c3.display();  

    return 0;
}
