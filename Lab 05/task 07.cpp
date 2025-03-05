#include <iostream>
#include <cstring>

using namespace std;

class Product {
    int id;
    string name;
    int quantity;

public:
    Product(int idd, string n, int q) : id(idd), name(n), quantity(q) {}

    int getID() { return id; }
    string getName() { return name; }
    int getQuantity() { return quantity; }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    Product** inventory;
    int capacity;
    int size;

public:
    Warehouse(int capacity) {
        this->capacity = capacity;
        inventory = new Product*[capacity];
        size = 0;
    }

    ~Warehouse() {
        for (int i = 0; i < size; i++) {
            delete inventory[i];
        }
        delete[] inventory;
    }

    void addProduct(int id, string name, int quantity) {
        if (size < capacity) {
            inventory[size] = new Product(id, name, quantity);
            size++;
        } else {
            cout << "Warehouse is full!" << endl;
        }
    }

    void sortProducts() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (inventory[j]->getName().compare(inventory[j + 1]->getName()) > 0) {
                    Product* temp = inventory[j];
                    inventory[j] = inventory[j + 1];
                    inventory[j + 1] = temp;
                }
            }
        }
    }

    void searchByID(int id) {
        for (int i = 0; i < size; i++) {
            if (inventory[i]->getID() == id) {
                cout << "Product Found: ";
                inventory[i]->display();
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    void displayProducts() {
        cout << "Warehouse Inventory:" << endl;
        for (int i = 0; i < size; i++) {
            inventory[i]->display();
        }
    }
};

int main() {
    Warehouse w1(10);
    w1.addProduct(1, "Table", 10);
    w1.addProduct(2, "Chair", 5);
    w1.addProduct(3, "Laptop", 2);
    w1.addProduct(4, "Phone", 8);

    cout << "Before Sorting:" << endl;
    cout << "------------------------" << endl;
    w1.displayProducts();

    w1.sortProducts();

    cout << "\nAfter Sorting:" << endl;
    cout << "------------------------" << endl;
    w1.displayProducts();

    cout << "\nSearching for product with ID 2:" << endl;
    w1.searchByID(2);

    return 0;
}
