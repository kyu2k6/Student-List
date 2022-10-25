//Kevin Yu
//11-4-22

#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//student struct for all the students
struct Student {
	char fname[30];
	char lname[30];	
	int id;
	float gpa;
};

void add(vector<Student*> &storage);
void del(vector<Student*> &storage);
void print(vector<Student*> &storage);

int main() {
	bool play = true;

	//storage for all the student structs	
	vector<Student*> storage;

	while (play == true) {
		
		//Gets add or delete or print or quit 
		char str[10]; 
		Student s;
		cout << "Input: ADD, DELETE, PRINT, or QUIT: "; 
		cin.get(str, 10);
		cin.get();

		//Checks if add or delete or print or quit
		if (strcmp(str, "ADD") == 0) {
			add(storage);
		}
		if (strcmp(str, "DELETE") == 0) {
			del(storage);
		}
		if (strcmp(str, "PRINT") == 0) {	
			print(storage);
		}
		if (strcmp(str, "QUIT") == 0) {
			play = false;	
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
}

void add(vector<Student*> &storage) {
	//makes new student
	Student* s = new Student();
	cout << "First name: ";
	cin >> s->fname;
	cout << "Last name: ";
	cin >> s->lname;
	cout << "ID: ";
	cin >> s->id;
	cout << "GPA: ";
	cin >> s->gpa;
	cin.ignore(10, '\n');
	//pushues new studnet into vector
	storage.push_back(s);
}

void del(vector<Student*> &storage) {
	int tmpID;
	cout << "ID: ";
	cin >> tmpID;
	cin.ignore(10, '\n');
	//goes through each element in the vector and checks if the id value is equal to the inputed one
	for (vector<Student*>::iterator it = storage.begin(); it != storage.end(); ++it) {
		if ((*it)->id == tmpID) {
			//delete from memory
			delete *it;
			//delete from storage
			storage.erase(it);	
			break;
		}
	}
}
void print(vector<Student*> &storage) {	
	//goes through each element in the vector and prints out all the structs
	for (vector<Student*>::iterator it = storage.begin(); it != storage.end(); ++it) {          //cut off to 2 decimal
		cout << (*it)->fname << ' ' << (*it)->lname << ", " << (*it)->id << ", " << fixed << setprecision(2) << (*it)->gpa << endl;
	}
}
