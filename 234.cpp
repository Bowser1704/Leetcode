#include <iostream>
// #include <array>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    ListNode *fast = head, *slow = head, *prev = nullptr, *tmp = nullptr;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;

        //上下部分一定不能交换顺序，否则就会把slow指针后面的都变成nullptr了。
        tmp = slow;
        slow = slow->next;

        tmp->next = prev;
        prev = tmp;

    }

    if (fast != nullptr) {
        slow = slow->next;
    }

    while (slow != nullptr) {
        if (slow->val != prev->val) return false;
        slow = slow->next;
        prev = prev->next;
    }
    return true;
}

int main() {
    ListNode* root = new ListNode(1);
    ListNode* next = new ListNode(2);
    root->next = next;
    cout << isPalindrome(root);
    return 0;
}