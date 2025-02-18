#include <iostream>
using namespace std;

class Car {
private:
    string brand;
    string model;
    float price;
    bool avail;
    float revenue;
    string regNumber;

public:
    Car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        avail = true;
        revenue = 0.0;
        regNumber = "N/A";
    }

    Car(string reg, string brandd, string m, float rent, bool a) {
        regNumber = reg;
        brand = brandd;
        model = m;
        price = rent;
        avail = a;
        revenue = 0.0;
    }

    Car(const Car &other) {
        regNumber = other.regNumber;
        brand = other.brand;
        model = other.model;
        price = other.price;
        avail = other.avail;
        revenue = other.revenue;
    }

    ~Car() {
        cout << "Car object for " << brand << " " << model << " (Reg: " << regNumber << ") is being destroyed." << endl;
    }

    void request(int days) {
        if (!avail) {
            cout << "Not available, car already rented." << endl;
        } else {
            float finalPrice = price * days;

            if (days > 5 && days < 10) {
                finalPrice *= 0.95;
            } else if (days >= 10) {
                finalPrice *= 0.90;
            }

            revenue += finalPrice;

            cout << "Car available, booked for " << days << " days!" << endl;
            cout << "Final Rent Price: $" << finalPrice << endl;

            avail = false;
        }
    }

    void display() {
        cout << "Registration Number: " << regNumber << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price per Day: $" << price << endl;
        cout << "Available: " << (avail ? "Yes" : "No") << endl;
        cout << "Total Revenue: $" << revenue << endl;
    }
};

int main() {
    Car c1("BFN172", "honda", "city", 100.0, true);

    c1.display();
    c1.request(7);
    c1.display();

    return 0;
}
