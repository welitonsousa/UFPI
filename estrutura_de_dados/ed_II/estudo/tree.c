#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *left;
    int info;
    struct Tree *rigth;
};
typedef struct Tree Tree;

void createSheet(Tree **sheet)
{
    *sheet = (Tree *)calloc(1, sizeof(Tree));
    printf("write value: ");
    scanf("%d", &(*sheet)->info);
}

void addSheet(Tree **tree, Tree *sheet)
{
    if (*tree == NULL)
    {
        *tree = sheet;
    }
    else if (sheet->info > (*tree)->info)
    {
        addSheet(&((*tree))->rigth, sheet);
    }
    else
    {
        addSheet(&((*tree)->left), sheet);
    }
}

void showTree(Tree *tree)
{
    if (tree != NULL)
    {
        printf(" %d\n", tree->info);
        showTree(tree->left);
        showTree(tree->rigth);
    }
}

int main()
{

#define MAX 6
    Tree *tree = NULL;
    for (int index = 0; index < MAX; index += 1)
    {
        Tree *sheet = NULL;
        createSheet(&sheet);
        addSheet(&tree, sheet);
    }
    showTree(tree);
    return 0;
}
