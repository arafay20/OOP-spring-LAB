#include<iostream>
using namespace std;

class Student {
	int id;
	string name ;
	int *scores;
	int numscores;
	
	public : 
	
	Student (int id, string namee, int *score, int numscores){
		this->id = id;
		name = namee;
		this->numscores = numscores;
		
		scores = new int[numscores];
		
		for(int i =0 ;i<numscores; i++) {
			scores[i] = score[i];
		}
		
	}
	
	Student (const Student &obj){
		this->id=obj.id;
		name = obj.name;
		this->numscores = obj.numscores;
		
		scores = new int[numscores];
		for(int i =0 ;i<numscores; i++) {
			scores[i] = obj.scores[i];
		}
		
	}
	
	void display(){
		 cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < numscores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
	}
	
	
	~Student(){
		delete[] scores;
	}
};

int main () {
	cout << " ----------------------------------------" << endl;
	
	int examscores[] = {78,98,56,87,78};
	
	Student s1(800, "Abdul Rafay Paracha",examscores,5 );
	s1.display();
	
	cout << " ----------------------------------------" << endl;
	
	Student s2 = s1;
	s2.display();
	return 0;
}
