#include <iostream>
using namespace std;

class Node{
	public:
	int status,stime,min,max;
	Node* next;
};

class Appointment{
	public:
		Node* head;
		
		Appointment(){
			head = NULL;
		}
		
		void create(){
			Node* temp = new Node{0,9,0,0,NULL};
			head = temp;
			
			for(int i=10;i<17;++i){
				temp->next = new Node{0,i,0,0,NULL};
				temp = temp->next;
			}
		}
		
		void displayFreeSlots(){
			Node* temp = head;
			
			while(temp){
				if(temp->status==0){
					cout << "Slot at " << temp->stime << " is available." << endl;
				}
				temp = temp->next;
			}
		}
		
		void bookSlot(){
			int time;
			cout << "Enter time for booking slot (9-17): ";
			cin >> time;
			
			Node* slot = findSlot(time);
			if(slot&&slot->status==0){
				slot->status = 1;
				cout << "Enter minimum time: ";
				cin >> slot->min;
				cout << "Enter maximum time: ";
				cin >> slot->max;
				cout << "Slot at " << slot->stime << " has been booked successfully." << endl;
			}
			else{
				cout << (slot ? "Booking already exists":"Invalid time");
			}
		}
		
		void cancelSlot(){
			int time;
			cout << "Enter time for booking slot (9-17): ";
			cin >> time;
			
			Node* slot = findSlot(time);
			if(slot&&slot->status==1){
				slot->status=0;
				cout << "Slot at " << slot->stime << " has been cancelled successfully." << endl;
			}
			else{
				cout << (slot ? "No booking exists":"Invalid time");
			}	
		}
		
		Node* findSlot(int time){
			Node* temp = head;
			
			while(temp&&temp->stime!=time){
				temp = temp->next;
			}
			return temp;
		}
		
};

int main(){
	Appointment a;
	a.create();
	
	int choice;
	bool continueFlag = true;
	
	while(continueFlag){
		cout << "\n1.Check Free Slots \n2.Book a slot \n3.Cancel a slot" << endl;
		cout << "Enter the choice: ";
		cin >> choice;
		
		switch(choice){
			case 1: a.displayFreeSlots(); break;
			case 2: a.bookSlot(); break;
			case 3: a.cancelSlot(); break;
			default: cout << "Invalid choice. Try again." << endl;
		}
		cout << "Do you want to continue (1 for yes and 0 for no): ";
		cin >> continueFlag;
	}
	return 0;
}
