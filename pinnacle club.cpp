#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int prn;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() {
    head = NULL;
	}

    void addPresident(string name, int prn) {
        Node* newNode = new Node{name, prn, head};
        head = newNode;
        cout << "President added: " << name << " (PRN: " << prn << ")\n";
    }

    // Function to add a secretary
    void addSecretary(string name, int prn) {
        Node* newNode = new Node{name, prn, NULL};
        if (head == NULL) {
            cout << "Error: Add the president first.\n";
            delete newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Function to add a general member
    void addGeneralMember(string name, int prn) {
        if (head == NULL) {
            cout << "Error: Add the president first.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->next != NULL)
            temp = temp->next;
        Node* newNode = new Node{name, prn, temp->next};
        temp->next = newNode;
    }

    // Function to delete a member
    void deleteMember(int prn) {
        if (head == NULL) {
            cout << "No members to delete.\n";
            return;
        }

        if (head->prn == prn) {
            Node* toDelete = head;
            head = head->next;
            cout << "Deleted member: " << toDelete->name << " (PRN: " << prn << ")\n";
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->prn != prn)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Member with PRN " << prn << " not found.\n";
        } else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            cout << "Deleted member: " << toDelete->name << " (PRN: " << prn << ")\n";
            delete toDelete;
        }
    }

    // Function to compute total number of members
    int totalMembers() const {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display members
    void displayMembers() const {
        if (head == NULL) {
            cout << "No members in the club.\n";
            return;
        }
        Node* temp = head;
        cout << "Club Members:\n";
        cout << "----------------------------------\n";
        while (temp != NULL) {
            cout << "Name: " << temp->name << ", PRN: " << temp->prn << "\n";
            temp = temp->next;
        }
        cout << "----------------------------------\n";
    }

    // Function to concatenate two lists
    void concatenate(PinnacleClub& other) {
        if (head == NULL) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = other.head;
        }
        other.head = NULL; // Clear the second list
        cout << "Lists concatenated successfully.\n";
    }

    // Function to add members based on input
    void addMembers() {
        int numMembers;
        cout << "Enter the total number of members to add (including president and secretary): ";
        cin >> numMembers;

        if (numMembers < 2) {
            cout << "Error: At least 2 members are required (President and Secretary).\n";
            return;
        }

        // Add president
        string name;
        int prn;
        cout << "Enter President's Name: ";
        cin >> name;
        cout << "Enter President's PRN: ";
        cin >> prn;
        addPresident(name, prn);

        // Add general members
        for (int i = 1; i <= numMembers - 2; i++) {
            cout << "Enter General Member " << i << "'s Name: ";
            cin >> name;
            cout << "Enter General Member " << i << "'s PRN: ";
            cin >> prn;
            addGeneralMember(name, prn);
        }

        // Add secretary
        cout << "Enter Secretary's Name: ";
        cin >> name;
        cout << "Enter Secretary's PRN: ";
        cin >> prn;
        addSecretary(name, prn);
    }
};

int main() {
    PinnacleClub divisionA, divisionB;
    int choice;

    do {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add Members to Division A\n";
        cout << "2. Add Members to Division B\n";
        cout << "3. Delete Member from Division A\n";
        cout << "4. Delete Member from Division B\n";
        cout << "5. Display Members of Division A\n";
        cout << "6. Display Members of Division B\n";
        cout << "7. Concatenate Division B into Division A\n";
        cout << "8. Display Total Members in Division A\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Adding members to Division A:\n";
                divisionA.addMembers();
                break;
            case 2:
                cout << "Adding members to Division B:\n";
                divisionB.addMembers();
                break;
            case 3: {
                int prn;
                cout << "Enter PRN of Member to Delete from Division A: ";
                cin >> prn;
                divisionA.deleteMember(prn);
                break;
            }
            case 4: {
                int prn;
                cout << "Enter PRN of Member to Delete from Division B: ";
                cin >> prn;
                divisionB.deleteMember(prn);
                break;
            }
            case 5:
                cout << "\nMembers of Division A:\n";
                divisionA.displayMembers();
                break;
            case 6:
                cout << "\nMembers of Division B:\n";
                divisionB.displayMembers();
                break;
            case 7:
                divisionA.concatenate(divisionB);
                cout << "Concatenated Division B into Division A.\n";
                break;
            case 8:
                cout << "Total Members in Division A: " << divisionA.totalMembers() << "\n";
                break;
            case 9:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

