/* 翻转一棵二叉树。
示例：
输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

#include <stdio.h>

struct btree_node {
    int val;
    struct btree_node *left;
    struct btree_node *right;
};

static void print_btree1(struct btree_node *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        print_btree1(root->left);
        print_btree1(root->right);
    }
}

static void print_btree2(struct btree_node *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        print_btree2(root->right);
        print_btree2(root->left);
    }

}

struct btree_node *reverse_btree(struct btree_node *root) {
    if (root != NULL) {
        reverse_btree(root->left);
        reverse_btree(root->right);
        struct btree_node *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
    return root;
}

int main(int argc, char *argv[]) {
    struct btree_node n1 = {1, NULL, NULL};
    struct btree_node n3 = {3, NULL, NULL};
    struct btree_node n6 = {6, NULL, NULL};
    struct btree_node n9 = {9, NULL, NULL};
    struct btree_node n2 = {2, &n1, &n3};
    struct btree_node n7 = {7, &n6, &n9};
    struct btree_node n4 = {4, &n2, &n7};

    print_btree1(&n4);
    printf("\n");
    print_btree2(&n4);
    printf("\n");
    struct btree_node *root = reverse_btree(&n4);
    print_btree1(root);

    return 0;
}
