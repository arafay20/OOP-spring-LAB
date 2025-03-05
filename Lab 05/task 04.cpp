#include <iostream>

using namespace std;

class AlarmSystem {
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {}

    void display() {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
    
    ~AlarmSystem(){
    	cout << "Alarm system Destroyed" << endl;
	}
};

class SmartHome {
    AlarmSystem alarm;  

public:
    SmartHome(string securityLevel) : alarm(securityLevel) {
    }

    ~SmartHome() {
       cout << "SmartHome Destroyed" << endl; 
        
    }

    void display() {
        cout << "SmartHome Details:" << endl;
        alarm.display();
    }
};

int main() {
    SmartHome home("High"); 
    home.display();

    return 0; 
}
