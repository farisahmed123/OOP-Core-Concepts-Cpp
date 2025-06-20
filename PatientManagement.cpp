#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Appointment {
public:
    string patientName;
    int urgencyLevel;
    Appointment(string name, int urgency) {
        patientName = name;
        urgencyLevel = urgency;
    }
};

class PriorityAppointmentQueue {
    vector<Appointment> appointmentList;

    int getParentIndex(int i) { return (i - 1) / 2; }
    int getLeftChildIndex(int i) { return 2 * i + 1; }
    int getRightChildIndex(int i) { return 2 * i + 2; }

    void swapAppointments(Appointment &a, Appointment &b) {
        Appointment temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && appointmentList[index].urgencyLevel < appointmentList[getParentIndex(index)].urgencyLevel) {
            swapAppointments(appointmentList[index], appointmentList[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = getLeftChildIndex(index);
        int right = getRightChildIndex(index);

        if (left < appointmentList.size() && appointmentList[left].urgencyLevel < appointmentList[smallest].urgencyLevel)
            smallest = left;
        if (right < appointmentList.size() && appointmentList[right].urgencyLevel < appointmentList[smallest].urgencyLevel)
            smallest = right;

        if (smallest != index) {
            swapAppointments(appointmentList[index], appointmentList[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void scheduleAppointment(const Appointment &appt) {
        appointmentList.push_back(appt);
        heapifyUp(appointmentList.size() - 1);
    }

    void sendNextPatientToDoctor() {
        if (appointmentList.empty()) {
            cout << "No appointments to send.\n";
            return;
        }
        cout << "Next patient: " << appointmentList[0].patientName
             << " (Urgency: " << appointmentList[0].urgencyLevel << ")\n";
        appointmentList[0] = appointmentList.back();
        appointmentList.pop_back();
        heapifyDown(0);
    }

    void updateUrgencyLevel(const string &name, int newUrgency) {
        for (int i = 0; i < appointmentList.size(); i++) {
            if (appointmentList[i].patientName == name) {
                int oldUrgency = appointmentList[i].urgencyLevel;
                appointmentList[i].urgencyLevel = newUrgency;
                if (newUrgency < oldUrgency)
                    heapifyUp(i);
                else
                    heapifyDown(i);
                cout << "Urgency updated for " << name << ".\n";
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    void displayAppointments() {
        if (appointmentList.empty()) {
            cout << "No appointments to display.\n";
            return;
        }
        cout << "Appointments:\n";
        for (const auto &appt : appointmentList) {
            cout << "- " << appt.patientName << " (Urgency: " << appt.urgencyLevel << ")\n";
        }
    }
};

int main() {
    PriorityAppointmentQueue queue;
    int choice;

    do {
        cout << "\n--- Appointment Menu ---\n";
        cout << "1. Schedule Appointment\n";
        cout << "2. Display Appointments\n";
        cout << "3. Send Next Patient\n";
        cout << "4. Update Urgency\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name;
                int urgency;
                cout << "Enter patient name: ";
                getline(cin, name);
                cout << "Enter urgency level (1=high priority): ";
                cin >> urgency;
                queue.scheduleAppointment(Appointment(name, urgency));
                break;
            }
            case 2:
                queue.displayAppointments();
                break;
            case 3:
                queue.sendNextPatientToDoctor();
                break;
            case 4: {
                string name;
                int urgency;
                cout << "Enter patient name to update: ";
                getline(cin, name);
                cout << "Enter new urgency level: ";
                cin >> urgency;
                queue.updateUrgencyLevel(name, urgency);
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}

