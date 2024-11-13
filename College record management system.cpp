#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
    public:
        int id;
        string name;
        string department;
        string year;

        Student(int id, string name, string department, string year) {
            this->id = id;
            this->name = name;
            this->department = department;
            this->year = year;
        }
};

vector<Student> students;
const int MAX_STUDENTS = 2;

void addStudent(int id, string name, string department, string year) {
    if (students.size() >= MAX_STUDENTS) {
        cout << "Cannot add more students. Maximum limit reached!" << endl;
        return;
    }
    Student newStudent(id, name, department, year);
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void deleteStudent(int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student with ID " << id << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students found." << endl;
        return;
    }
    for (const Student& s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name << ", Department: " << s.department << ", Year: " << s.year << endl;
    }
}

int main() {
    int choice, id;
    string name, department, year;

    while (true) {
        cout << "\n1. Add Student\n2. Delete Student\n3. View Students\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, department);
                cout << "Enter Year: ";
                getline(cin, year);
                addStudent(id, name, department, year);
                break;
            case 2:
                cout << "Enter ID of student to delete: ";
                cin >> id;
                deleteStudent(id);
                break;
            case 3:
                viewStudents();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
