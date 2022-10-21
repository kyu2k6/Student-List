//Kevin Yu
//11-4-22

#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

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

	vector<Student*> storage;

	while (play == true) {
		
		//Gets add or delete 
		char str[10]; 
		Student s;
		cout << "Input: ADD, DELETE, PRINT, or QUIT: "; 
		cin.get(str, 10);
		cin.get();

		//Checks if add or delete
		if (strcmp(str, "ADD") == 0) {
			add(storage);
		}
		else if (strcmp(str, "DELETE") == 0) {
			cout << "delete";
		}
		else if (strcmp(str, "PRINT") == 0) {	
			print(storage);
		}
		else if (strcmp(str, "QUIT") == 0) {
			play = false;	
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
}

void add(vector<Student*> &storage) {
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
	storage.push_back(s);
}

void del(vector<Student*> &storage) {
	cout << "ID: ";
	
}

void print(vector<Student*> &storage) {	
	for (vector<Student*>::iterator it = storage.begin(); it != storage.end(); ++it) {
		cout << (*it)->fname << ' ' << (*it)->lname << ", " << (*it)->id << ", " << fixed << setprecision(2) << (*it)->gpa << endl;
	}
}
