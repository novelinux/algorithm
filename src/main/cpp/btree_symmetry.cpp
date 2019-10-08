/*给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
*/

#include <stdio.h>

struct btree_node {
    int val;
    struct btree_node *left;
    struct btree_node *right;
};

static void print_btree(struct btree_node *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        print_btree(root->left);
        print_btree(root->right);
    }
}

bool compare(struct btree_node *left, struct btree_node *right) {
    if (left == NULL && right == NULL) { return true; }
    if (left == NULL || right == NULL) { return false; }

    return left->val == right->val &&
            compare(left->right, right->left) &&
            compare(left->left, right->right);
}

bool symmetry(struct btree_node *root) {
    if (root == NULL) {
        return true;
    }
    return compare(root->left, root->right);
}

int main(int argc, char *argv[]) {
    struct btree_node nl3 = {3, NULL, NULL};
    struct btree_node nr3 = {3, NULL, NULL};
    struct btree_node nl2 = {2, NULL, &nl3};
    struct btree_node nr2 = {2, NULL, &nr3};
    struct btree_node n1 = {1, &nl2, &nr2};

    print_btree(&n1);
    printf("\n");
    printf("%d\n", symmetry(&n1));

    return 0;
}
