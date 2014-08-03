#include <stdlib.h>
#include <stdio.h>

struct tnode
{
    int data;
    struct tnode* left;
    struct tnode* right;
};

struct tnode* talloc(int data)
{
    struct tnode* p = malloc(sizeof(struct tnode));
    if(p!=NULL)
    {
        p->data = data;
        p->left = p->right = NULL;
    }
    return p;
}

struct tnode* addnode(struct tnode* root, int data)
{
    if(root == NULL)
    {
        struct tnode* node = talloc(data);
        return (root = node);
    }
    else if(data<root->data)
    {
        root->left = addnode(root->left, data);
    }
    else
    {
        root->right = addnode(root->right, data);
    }

    return root;
}

void preorder(struct tnode* root)
{
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct tnode* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct tnode* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int deltree(struct tnode* root)
{
    int count = 0;
    if(root == NULL) return 0;
    count+=deltree(root->left);
    count+=deltree(root->right);
    free(root);
    return ++count;
}

int main(void)
{
    struct tnode* root = NULL;
    int count = 0;
    root=addnode(root,3);
    root=addnode(root,1);
    root=addnode(root,0);
    root=addnode(root,2);
    root=addnode(root,8);
    root=addnode(root,6);
    root=addnode(root,5);
    root=addnode(root,9);

    puts("should print 3,1,0,2,8,6,5,9");
    preorder(root);
    puts("");

    puts("should print 0,1,2,3,5,6,8,9");
    inorder(root);
    puts("");

    puts("should print postorder");
    postorder(root);
    puts("");

    count=deltree(root);
    root=NULL;
    puts("should expect 8 nodes deleted");
    printf("%d nodes deleted\n", count);

    return 0;
}
