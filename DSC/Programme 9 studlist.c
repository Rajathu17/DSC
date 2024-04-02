#include<justdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct n{
    char name[34];
    struct n *next;

}Node;
Node *head=NULL,*temp,*prev;

void insert(char name[]){
    Node *newNode=(Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->next=NULL;

    if(head==NULL || strcmp(head->name,name)>0){
        newNode->next=head;
        head=newNode;
    }
    else 
    {
        temp=head;
    while(temp->next !=0 && strcmp(temp->next->name,name)<0)
    {
        temp=temp->next;

    }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}
void delete(char name[]){
    temp=head;
    while(temp!=0){
        if(strcmp(temp->name,name)==0)
        {
            if(temp==head)
                head=head->next;
            
            else if (temp->next==0)
                prev->next==NULL;
            else
              prev->next=temp->next;
            
           free(temp);
           return; 
        }
    prev=temp;
    temp=temp->next;
    }
}
void display() {
     Node* curr = head;
    while (curr != NULL) {
        printf("%s -> ", curr->name);
        curr = curr->next;
    }
    printf("NULL\n");
}
int main(){
    int ch;char name[32];
    while(1){
        printf("\nentr\n1.tocreate or insert\n2.delete\n3.display\n4.Exxit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter the name to be inserted\t");
            scanf("%s",name);
            insert(name);
            break;
            case 2:
            printf("Enter the name to be delete\t");
            scanf("%s",name);
            delete(name);
            break;
            case 3: display();
            break;
            case 4: exit(0);

            default:
             printf("Enter the name to be inserted");
             break;

        }
    }
}


