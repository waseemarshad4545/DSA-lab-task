#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}


    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode; 
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        Node* newNode = new Node{value, nullptr};
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

 
    void insertAtCenter(int value) {
        if (!head) {
            insertAtBeginning(value);
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* newNode = new Node{value, slow->next};
        slow->next = newNode;
    }

    void display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }

  
    void displayReverseHelper(Node* current, Node* start) {
        if (current->next == start) {
            cout << current->data << " -> ";
            return;
        }
        displayReverseHelper(current->next, start);
        cout << current->data << " -> ";
    }

    void displayReverse() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        displayReverseHelper(head, head);
        cout << "HEAD" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);
    cll.insertAtNth(15, 3);
    cll.insertAtCenter(25);

    cout << "Circular Linked List (In Order):" << endl;
    cll.display();

    cout << "Circular Linked List (Reverse Order):" << endl;
    cll.displayReverse();

    return 0;
}
