/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode l3(-1, NULL);
        ListNode *current = &l3;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        current->next = l1 == NULL ? l2 : l1;

        return l3.next;
    }
};

void print_list(struct ListNode* head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    struct ListNode n14(4, NULL);
    struct ListNode n12(2, &n14);
    struct ListNode n11(1, &n12);

    print_list(&n11);

    struct ListNode n24(4, NULL);
    struct ListNode n23(3, &n24);
    struct ListNode n21(1, &n23);

    print_list(&n21);

    Solution s;
    print_list(s.mergeTwoLists(&n11, &n21));
}
