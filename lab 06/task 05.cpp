#include <iostream>
using namespace std;

class device {
protected:
    int deviceID;
    bool status;

public:
    device(int id, bool stat) : deviceID(id), status(stat) {}

    void display() {
        cout << "device id: " << deviceID << endl;
        cout << "status: " << (status ? "on" : "off") << endl;
    }
};

class smartphone : public device {
protected:
    float screenSize;

public:
    smartphone(int id, bool stat, float size) : device(id, stat), screenSize(size) {}

    void display() {
        device::display();
        cout << "screen size: " << screenSize << " inches" << endl;
    }
};

class smartwatch : public device {
protected:
    bool heartRateMonitor;

public:
    smartwatch(int id, bool stat, bool hrm) : device(id, stat), heartRateMonitor(hrm) {}

    void display() {
        device::display();
        cout << "heart rate monitor: " << (heartRateMonitor ? "yes" : "no") << endl;
    }
};

class smartwearable : public smartphone, public smartwatch {
private:
    int stepCounter;

public:
    smartwearable(int id, bool stat, float size, bool hrm, int steps) : smartphone(id, stat, size), smartwatch(id, stat, hrm), stepCounter(steps) {}

    void display() {
    	cout << "============================" << endl;
        smartphone::display();
        cout << "heart rate monitor: " << (heartRateMonitor ? "yes" : "no") << endl;
        cout << "step counter: " << stepCounter << " steps" << endl;
    }
};

int main() {
    smartwearable w(101, true, 6.2, true, 5000);
    w.display();
    return 0;
}
