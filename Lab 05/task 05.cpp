#include <iostream>

using namespace std;

class Doctor {
    string name;
    string specialization;
    int experience;

public:
    Doctor(string name, string specialization, int experience)
        : name(name), specialization(specialization), experience(experience) {}

    void display() {
        cout << "--------------------------" << endl;
        cout << "Doctor: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Hospital {
    string name;
    Doctor** doctors; 
    int numDoctors;
    int capacity;

public:
    Hospital(string name, int capacity) : name(name), numDoctors(0), capacity(capacity) {
        doctors = new Doctor*[capacity]; 
    }

    ~Hospital() {
        
        for (int i = 0; i < numDoctors; i++) {
            delete doctors[i];
        }
        delete[] doctors; 
        cout << "Hospital " << name << " is closed, memory freed!" << endl;
    }

    void addDoctor(string name, string specialization, int experience) {
        if (numDoctors < capacity) {
            doctors[numDoctors] = new Doctor(name, specialization, experience); 
            numDoctors++;
        } else {
            cout << "Hospital is at full doctor capacity!" << endl;
        }
    }

    void display() {
        cout << "--------------------------" << endl;
        cout << "Hospital: " << name << endl;
        cout << "Doctors currently working here:" << endl;
        if (numDoctors == 0) {
            cout << "No doctors assigned yet." << endl;
        } else {
            for (int i = 0; i < numDoctors; i++) {
                doctors[i]->display();
            }
        }
    }
};

int main() {
    Hospital h1("Liaqat National", 10);

    h1.addDoctor("Dr. A. Rafay", "Heart Surgeon", 10);
    h1.addDoctor("Dr. Asif", "Cardiology", 7);

    h1.display();

    return 0;
}
