#include <stdio.h>

struct link_node {
    int val;
    struct link_node *next;
};

struct link_node *reverse(struct link_node *h1) {
    struct link_node *h2 = NULL;
    struct link_node *current = h1;
    while (current != NULL) {
        struct link_node *tmp = current->next;
        current->next = h2;
        h2 = current;
        current = tmp;
    }
    return h2;
}

int main(int argc, char *argv[]) {
    /* 1->2->3->4->5->NULL */
    struct link_node n5 = {5, NULL};
    struct link_node n4 = {4, &n5};
    struct link_node n3 = {3, &n4};
    struct link_node n2 = {2, &n3};
    struct link_node n1 = {1, &n2};

    struct link_node *h = reverse(&n1);
    while (h != NULL) {
        printf("%d\n", h->val);
        h = h->next;
    }

    return 0;
}
