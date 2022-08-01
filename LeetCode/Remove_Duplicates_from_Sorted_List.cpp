#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

void deleteList(ListNode *head) {
    if (head == nullptr) return;
    deleteList(head->next);
    delete head;
}

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode* ptr = head->next;
    ListNode* last = head;
    while (ptr) {
        if (ptr->val == last->val) {
            ListNode* temp = ptr;
            last->next = ptr->next;
            ptr = ptr->next;
            delete temp;
        } else {
            last = last->next;
            ptr = ptr->next;
        }
    }

    return head;
}

ListNode* createList (int n) {
    ListNode* ptr = new ListNode(0);
    ListNode* first = ptr;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) {
            ListNode* temp = new ListNode(j);
            ptr->next = temp;
            ptr = ptr->next;
        }
        for (int j = 3; j >= 1; j--) {
            ListNode* temp = new ListNode(j);
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
    return first;
}

void printList(ListNode *head) {
    if (head == nullptr) return;
    cout << head -> val << endl;
    printList(head->next);
}

int main()
{
    int t = 99999999;
    while (t--) {
        ListNode *head = createList(5);
        deleteDuplicates(head);
        deleteList(head);
    }

    return 0;
}