/*
 * 2018.6.12 linked list practice
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* makeNew(int n)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = n;
    new->next = NULL;
    return new;
}

Node* tellLast(Node* w)
{
    while(w->next!=NULL){
       w = w->next;
    }
    return w;
}

Node* addNew(Node* h, Node* t, Node* n)
{
    Node* head = h, *tail = t;

    if(head == NULL)
        head = n;
    else if(head->data != n->data){
        tail->next = n;
    }
    tail = n;
    return head;
}

void delNode(Node* h, Node* t, int n)
{
    Node *p_prev=h, *p=h->next;
    Node *temp = NULL;

    if(p_prev == NULL){
        printf("There is no data.\n");
        return;
    }

    while(p != NULL){
        if(p_prev->data == n){
            temp = p_prev;
            p_prev = p;
            p = p->next;
            free(temp);
        }
        else if(p->data==n){
            temp = p;
            p_prev->next = p->next;
            free(temp);
        }
        else if(p==t && p->data == n){
            temp = p;
            p=p_prev;
            p->next = NULL;
            free(temp);
        }
        p_prev = p_prev->next;
        p = p->next;
    }
}

void showAll(Node* w)
{
    while(w!=NULL){
        printf("%d ", w->data);
        w = w->next;
    }
}

void deAlloc(Node* w)
{
    Node* temp;
    while(w!=NULL){
        temp = w;
        w = w->next;
        free(temp);
    }
}

Node* setList(Node* w)
{
    Node* head = w, *temp;
    int n = 0;
    FILE* infp = fopen("./input.bin", "rb");
    if(infp == NULL){
        printf("No input files.\n");
        return NULL;
    }

    while(!fread((int*)n,sizeof(int),1,infp)){
        if(head == NULL){
            head = (Node*) malloc(sizeof(Node));
            head->data = n;
            temp = (Node*) malloc(sizeof(Node));
            head->next = temp;
        }
        else{
            temp->data = n;
            temp->next = (Node*)malloc(sizeof(Node));
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    int n = 0;
    char select = '\0';
    Node *head = NULL, *tail = NULL, *new = NULL;

    head = setList(head);
    showAll(head);

    printf("Let's make linked list! [Y/N] -> ");
    select = (char)getchar();
    if(select == 'Y' || select == 'y'){
        printf("Enter the number you wanna input in list : ");
        scanf("%d", &n);
        new = makeNew(n);
        head = addNew(head, tail, new);
        rewind(stdin);
        while(1){
            printf("More data? [Y/N] -> ");
            select = (char)getchar();
            if(select == 'Y' || select == 'y'){
                printf("Enter number : ");
                scanf("%d", &n);
                tail=tellLast(head);
                new = makeNew(n);
                head = addNew(head, tail, new);
                rewind(stdin);
            }
            else{
                rewind(stdin);
                break;
            }
        }
    }
    else {
        printf("Ok, bye!\n");
        return -1;
    }

    printf("Here is List you made -> ");
    showAll(head);

    printf("\nDelete something? [Y/N] ");
    select = (char)getchar();
    printf("Enter the number you wanna delete : ");
    scanf("%d", &n);
    delNode(head, tail, n);
    rewind(stdin);
    while(1){
        printf("More delete? [Y/N]");
        scanf("%c", &select);
        if(select == 'Y' || select == 'y'){
            printf("Enter the number you wanna delete : ");
            scanf("%d", &n);
            delNode(head, tail, n);
            rewind(stdin);
        }
        else if(select == 'N' || select == 'n'){
            rewind(stdin);
            break;
        }
    }
    printf("Here is List after delete -> ");
    showAll(head);

    deAlloc(head);
    return 0;
}
