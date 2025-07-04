#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Class for Linked List operations
class LinkedList {
private:
    Node* head;

    // Helper to find middle node
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // Helper to reverse the list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Check if the linked list is a palindrome
    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node* middle = getMid(head);
        Node* secondHalf = reverse(middle->next);
        Node* firstHalf = head;

        Node* tempSecond = secondHalf; // Keep for restoring

        bool isPalin = true;
        while (secondHalf != nullptr) {
            if (firstHalf->data != secondHalf->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the original list
        middle->next = reverse(tempSecond);

        return isPalin;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements of linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        list.insert(value);
    }

    cout << "Linked List: ";
    list.display();

    if (list.isPalindrome()) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is NOT a palindrome." << endl;
    }

    return 0;
}
