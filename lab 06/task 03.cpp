#include<iostream>
using namespace std;

class Person {
	protected :
	string name;
	int age;
	
	public :
		
		Person(string n, int a) : name(n), age(a){}
		
		void display(){
			cout << "Details :" <<endl;
			cout << "------------------------" << endl;
			cout << "name : " << name << endl;
			cout << "age : " << age <<endl;
			
		}
};

class Teacher : public Person{
	protected :
		string subject;
		
	public :
	
		Teacher(string n, int a, string sub) : Person(n, a), subject(sub){}
		
		void display(){
			Person::display();
			cout << "subject : " << subject << endl;
		}
};

class Researcher :public Teacher {
	protected :
		
		string researcharea;
		
	public :
	
		Researcher(string n, int a, string sub, string rarea) : Teacher(n,a, sub), researcharea(rarea){}
		
		void display(){
			Teacher::display();
			cout << "research area : " << researcharea << endl;
		}
};

class Professor : public Researcher {
	protected :
		int publications;
		
	public :
	
		Professor(string n, int a, string sub, string rarea, int pub) : Researcher(n,a,sub,rarea), publications(pub){}
		
		
		void display(){
			Researcher::display();
			cout << "publications : " << publications << endl;
		}
		
		
};

int main () {
	
	Professor p("rafay", 39, "mathematics", "discreet mathematics", 3);
	
	p.display();
	
	return 0;
}
