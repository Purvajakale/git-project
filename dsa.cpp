#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
        ListNode* nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    return prev;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    if(n <= 0) {
        cout << "List is empty." << endl;
        return 0;
    }
    
    cout << "Enter node values: ";
    int value;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* current = head;
    
    for (int i = 1; i < n; i++) {
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }
    
    cout << "Original List: ";
    printList(head);
    
    head = reverseList(head);
    
    cout << "Reversed List: ";
    printList(head);
    
    // Cleanup memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}