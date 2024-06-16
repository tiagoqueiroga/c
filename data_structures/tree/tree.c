#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *create(int value)
{
    treenode *tree = malloc(sizeof(treenode));
    if (tree == NULL)
    {
        fprintf(stderr, "Malloc error");
        exit(EXIT_FAILURE);
    }

    tree->left = NULL;
    tree->right = NULL;
    tree->value = value;

    return tree;
}

void print_tab(int num)
{
    for (int i = 0; i <= num; i++)
    {
        printf("\t");
    }
}

void print_tree_rec(treenode *root, int level)
{
    if (root == NULL)
    {
        printf("<empty>\n");
        return;
    }

    printf("%d\n", root->value);

    print_tab(level);
    print_tree_rec(root->left, level + 1);

    print_tab(level);
    print_tree_rec(root->right, level + 1);
}

void print_tree(treenode *root)
{
    print_tree_rec(root, 0);
}

int main()
{

    treenode *n1 = create(1);
    treenode *n2 = create(2);
    treenode *n3 = create(3);
    treenode *n4 = create(4);
    treenode *n5 = create(5);
    treenode *n6 = create(6);
    treenode *n7 = create(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    n5->left = n6;
    n5->right = n7;

    print_tree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);

    return 0;
}
