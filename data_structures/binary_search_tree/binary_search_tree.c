#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool insert(treenode **rootptr, int value)
{
    treenode *root = *rootptr;

    if (root == NULL)
    {
        (*rootptr) = create(value);
        return true;
    }

    if (value == root->value)
    {
        // do nothing
        return false;
    }

    if (value < root->value)
    {
        return insert(&(root->left), value);
    }

    else
    {
        return insert(&(root->right), value);
    }
}

bool find(treenode *root, int value)
{
    if (root == NULL)
        return false;

    if (root->value == value)
    {
        return true;
    }

    if (root->value < value)
    {
        return find(root->right, value);
    }

    else
    {
        return find(root->left, value);
    }
}

int main()
{
    treenode *root = NULL;

    insert(&root, 15);
    insert(&root, 11);
    insert(&root, 24);
    insert(&root, 5);
    insert(&root, 16);

    print_tree(root);

    printf("%d (%d)\n", 16, find(root, 16)); // true
    printf("%d (%d)\n", 22, find(root, 22)); // false
    printf("%d (%d)\n", 22, find(root, 24)); // true

    return 0;
}