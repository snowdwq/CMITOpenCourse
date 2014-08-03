#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node* next;
};

struct node* nalloc(int data)
{
    struct node* p = malloc(sizeof(struct node));
    if(p!=NULL)
    {
        p->next = NULL;
        p->data = data;
    }

    return p;
}

struct node* addfront(struct node* head, int data)
{
    struct node* p = nalloc(data);
    if(p==NULL) return head; /*no change*/
    p->next = head;
    return p;
}

void display(struct node* head)
{
    struct node* p;
    for(p = head; p!=NULL; p=p->next)
    {
        printf("%d ", p->data);
    }
    printf("\n");
}

struct node* addback(struct node* head, int data)
{
    struct node* p = nalloc(data);
    struct node* curr = NULL;
    if(p == NULL) return head;
    /*special case: empty list*/
    if(head == NULL)
    {
        head = p;
        return p;
    }
    else {

        for(curr=head; curr->next!=NULL; curr=curr->next)
            ;
        curr->next = p;
        return head;
    }
}

void freelist(struct node* head)
{
    struct node* p = NULL;
    while(head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

struct node* find(struct node* head, int data)
{
    struct node* curr = NULL;
    for(curr=head; curr/*site has curr->next which is wrong*/!=NULL; curr=curr->next)
    {
        if(curr->data == data) return curr;
    }
    return NULL;
}

struct node* delnode(struct node* head, struct node* pnode)
{
    struct node* p = NULL;
    struct node* q = NULL;
    for(p=head; p!=NULL && p!=pnode; p=p->next)
        q=p; /*follows p*/

    if(p==NULL)/* not found */
        return head ;
    if(q==NULL)/* head element */
    {
        head=head->next ;
        free(p);
    }
    else
    {
        q->next=p->next;/* skip p */
        free(p);
    }
    return head;
}

int main(void)
{
    struct node* head=NULL;
    struct node* np=NULL;
    puts("should display empty");
    display(head);

    head=addfront(head,10);
    np=find(head,10);
    puts("should display 10");
    display(np);
    head=addfront(head,20);
    puts("should display 20,10");
    display(head);

    freelist(head);
    head = NULL;
    puts("should display empty");
    display(head);

    head=addback(head,10);
    head=addback(head,20);
    head=addback(head,30);
    puts("should display 10,20,30");
    display(head);

    np=find(head,-20);
    puts("should display empty");
    display(np);

    np=find(head,20);
    puts("should display 20,30");
    display(np);

    head=delnode(head,np);
    puts("should display 10,30");
    display(head);

    np=find(head,10);
    head=delnode(head,np);
    puts("should display 30");
    display(head);

    freelist(head);

    return 0;
}
