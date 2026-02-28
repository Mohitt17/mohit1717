#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int id;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int id)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int id)
{
    if (root == NULL)
    {
        return createNode(id);
    }

    if (id < root->id)
    {
        root->left = insert(root->left, id);
    }
    else if (id > root->id)
    {
        root->right = insert(root->right, id);
    }

    return root;
}

int search(struct Node *root, int id)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->id == id)
    {
        return 1;
    }

    if (id < root->id)
    {
        return search(root->left, id);
    }
    else
    {
        return search(root->right, id);
    }
}

void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->id);
    inorder(root->right);
}

int main()
{
    printf("Enter No. of operations :-\n");
    int N;
    scanf("%d", &N);

    struct Node *root = NULL;
    char operation[20];
    int value;

    for (int i = 0; i < N; i++)
    {
        scanf("%s", operation);

        if (strcmp(operation, "ADD") == 0)
        {
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if (strcmp(operation, "SEARCH") == 0)
        {
            scanf("%d", &value);
            if (search(root, value))
            {
                printf("FOUND\n");
            }
            else
            {
                printf("NOT FOUND\n");
            }
        }
        else if (strcmp(operation, "INORDER") == 0)
        {
            if (root == NULL)
            {
                printf("EMPTY\n");
            }
            else
            {
                inorder(root);
                printf("\n");
            }
        }
    }

    return 0;
}