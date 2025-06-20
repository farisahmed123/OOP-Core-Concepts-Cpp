#include <iostream>
#include <string>
using namespace std;

struct CS {
	int noofstudent;
	char section_name[5] = {'A', 'B', 'C', 'D', 'E'};
};

struct Admin {
	string name;
	string designation;
	string password;
	CS section;
};

struct Student {
	int roll;
	string student_name;
	char section;
	string student_password;
};

int main() {
	Admin a[5];
	Student b[50];
	CS c;
	int option;

	cout << "\n------------ WELCOME TO COMPUTER DATABASE PROGRAM ------------\n\n";

	do {
		cout << "1. Login as Admin\n";
		cout << "2. Login as Student\n";
		cout << "0. Logout\n";
		cout << "Enter your option: ";
		cin >> option;
		cout << endl;

		if (option == 1) {
			string input_name, input_password;
			bool logged_in = false;

			cout << "Username: ";
			cin >> input_name;
			cout << "Password: ";
			cin >> input_password;

			if (input_name == "admin" && input_password == "admin") {
				logged_in = true;
			}

			if (!logged_in) {
				cout << "Invalid admin credentials.\n";
				continue;
			}

			cout << "Welcome Admin\n";
			int opt;
			cout << "1. Add/Update/View Admins\n";
			cout << "2. Add/Update/View Students\n";
			cout << "0. Logout\n";
			cin >> opt;

			if (opt == 1) {
				int opte;
				cout << "1. Add Admin\n";
				cout << "2. Update Admin\n";
				cout << "3. View Admin\n";
				cout << "4. View All Admins\n";
				cin >> opte;

				if (opte == 1) {
					for (int i = 0; i < 5; i++) {
						cout << "Enter new Admin Name: ";
						cin >> a[i].name;
						cout << "Enter designation: ";
						cin >> a[i].designation;
						cout << "Set password: ";
						cin >> a[i].password;

						char more;
						cout << "Add another admin? (y/n): ";
						cin >> more;
						if (more == 'n' || more == 'N') break;
					}
				} else if (opte == 2) {
					int idx;
					string field;
					cout << "Enter admin index to update: ";
					cin >> idx;
					cout << "What to update? (name/designation/password): ";
					cin >> field;
					if (field == "name") cin >> a[idx].name;
					else if (field == "designation") cin >> a[idx].designation;
					else if (field == "password") cin >> a[idx].password;
				} else if (opte == 3) {
					int idx;
					cout << "Enter admin index to view: ";
					cin >> idx;
					cout << "Name: " << a[idx].name << endl;
					cout << "Designation: " << a[idx].designation << endl;
					cout << "Password: " << a[idx].password << endl;
				} else if (opte == 4) {
					for (int i = 0; i < 5; i++) {
						if (!a[i].name.empty()) {
							cout << "--- Admin " << i << " ---\n";
							cout << "Name: " << a[i].name << endl;
							cout << "Designation: " << a[i].designation << endl;
							cout << "Password: " << a[i].password << endl;
						}
					}
				}
			} else if (opt == 2) {
				int student_opt;
				cout << "1. Add Students\n";
				cout << "2. Update Student\n";
				cout << "3. View Student\n";
				cout << "4. View All Students\n";
				cout << "5. View Section Wise Students\n";
				cin >> student_opt;

				if (student_opt == 1) {
					cout << "Enter number of students: ";
					cin >> c.noofstudent;
					for (int i = 0; i < c.noofstudent; i++) {
						cout << "Roll Number: ";
						cin >> b[i].roll;
						cout << "Name: ";
						cin >> b[i].student_name;
						cout << "Password: ";
						cin >> b[i].student_password;
						cout << "Section: ";
						cin >> b[i].section;
					}
				} else if (student_opt == 2) {
					int idx;
					string field;
					cout << "Enter student index to update: ";
					cin >> idx;
					cout << "What to update? (name/roll/password/section): ";
					cin >> field;
					if (field == "name") cin >> b[idx].student_name;
					else if (field == "roll") cin >> b[idx].roll;
					else if (field == "password") cin >> b[idx].student_password;
					else if (field == "section") cin >> b[idx].section;
				} else if (student_opt == 3) {
					string sname;
					cout << "Enter student name: ";
					cin >> sname;
					for (int i = 0; i < c.noofstudent; i++) {
						if (b[i].student_name == sname) {
							cout << "Name: " << b[i].student_name << endl;
							cout << "Roll: " << b[i].roll << endl;
							cout << "Section: " << b[i].section << endl;
							cout << "Password: " << b[i].student_password << endl;
						}
					}
				} else if (student_opt == 4) {
					for (int i = 0; i < c.noofstudent; i++) {
						cout << "Name: " << b[i].student_name << endl;
						cout << "Roll: " << b[i].roll << endl;
						cout << "Section: " << b[i].section << endl;
						cout << "Password: " << b[i].student_password << endl;
					}
				} else if (student_opt == 5) {
					char sec;
					cout << "Enter section: ";
					cin >> sec;
					for (int i = 0; i < c.noofstudent; i++) {
						if (b[i].section == sec) {
							cout << "Name: " << b[i].student_name << endl;
							cout << "Roll: " << b[i].roll << endl;
							cout << "Section: " << b[i].section << endl;
						}
					}
				}
			}

		} else if (option == 2) {
			string sname, pass;
			bool found = false;
			cout << "Enter student name: ";
			cin >> sname;
			cout << "Enter password: ";
			cin >> pass;

			for (int i = 0; i < 50; i++) {
				if (b[i].student_name == sname && b[i].student_password == pass) {
					cout << "--- Welcome Student ---\n";
					cout << "Name: " << b[i].student_name << endl;
					cout << "Roll: " << b[i].roll << endl;
					cout << "Section: " << b[i].section << endl;
					found = true;
					break;
				}
			}

			if (!found) {
				cout << "Invalid student login.\n";
			}
		}
	} while (option != 0);

	cout << "Program exited.\n";
	return 0;
}

