/*将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include <stdio.h>
#include <stdlib.h>

struct link_node {
    int val;
    struct link_node* next;
};

void print_list(struct link_node* head) {
    struct link_node *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

struct link_node*
merge_sorted_list(struct link_node* h1, struct link_node* h2) {
    if (h1 == NULL) return h2;
    if (h2 == NULL) return h1;

    if (h1->val < h2->val) {
        h1->next = merge_sorted_list(h1->next, h2);
        return h1;
    } else {
        h2->next = merge_sorted_list(h1, h2->next);
        return h2;
    }
}


int main(int argc, char *argv[]) {
    struct link_node n14 = { 4, NULL };
    struct link_node n12 = { 2, &n14 };
    struct link_node n11 = { 1, &n12 };

    print_list(&n11);

    struct link_node n24 = { 4, NULL };
    struct link_node n23 = { 3, &n24 };
    struct link_node n21 = { 1, &n23 };

    print_list(&n21);

    print_list(merge_sorted_list(&n11, &n21));
}
