#include <iostream>
#include <vector>

// 假设链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

auto ReverseList(ListNode *head) -> ListNode * {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

auto IsPalindRome(ListNode *head) -> bool {
    if ((head == nullptr) || (head->next == nullptr)) {
        return true; // An empty list or a single-node list is considered a
                     // palindrome.
    }

    ListNode *slow = head;
    ListNode *fast = head;

    // Move slow to the middle of the list
    while ((fast != nullptr) && (fast->next != nullptr)) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    ListNode *reversed_second_half = ReverseList(slow);

    // Compare the first half with the reversed second half
    while (reversed_second_half != nullptr) {
        if (head->val != reversed_second_half->val) {
            return false;
        }
        head = head->next;
        reversed_second_half = reversed_second_half->next;
    }

    return true;
}

auto GenerateTestList(const std::vector<int> &values) -> ListNode * {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int value : values) {
        auto *new_node = new ListNode(value);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

void FreeSpace(ListNode *head) {
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

auto main() -> int {
    std::vector<int> values = {};
    auto *head = GenerateTestList(values);
    std::cout << std::boolalpha << IsPalindRome(head) << '\n';
    FreeSpace(head);
    return 0;
}
