#include<iostream>
using namespace std;

struct LinkedList{
    int data;
    LinkedList *next;
};
struct LinkedList* CreateLinkedList(){
    struct LinkedList *temp=0;
    temp=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    if(!temp){   return 0;    }
    else{    temp->next=0; return temp;   } 
}
void InsertData(int d,struct LinkedList* temp){
    while(temp->next != 0){    temp=temp->next;    }
    temp->next = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    temp = temp->next;
    temp->next = 0;
    temp->data = d;
}
struct LinkedList* InsertAtHead(int d,struct LinkedList* head){
    struct LinkedList *temp=(struct LinkedList*)malloc(sizeof(struct LinkedList));
    temp->next=head;
    head=temp;
}
int SearchInLinkedList(int d,struct LinkedList* temp){
    int pos=0;
    while(temp->next!=0){   pos++; if (temp->data == d)   return pos;
        temp = temp->next;    }
    return -1;
}

void DeleteLinkedList(struct LinkedList* temp){
    struct LinkedList *nextNode=0;
    while(temp!=0){   nextNode=temp->next;free(temp);temp=nextNode;  }
}

void printElement(struct LinkedList* temp){
     while(temp->next!=0){    cout<<temp->data<<" ";temp=temp->next;    }
}
int main(){
    int option=1,d;
    struct LinkedList* head=0;
    cout<<"Enter Your Options:\n 0.Exit\n 1.Create Linked List\n 2.Insert Data\n 3.Insert At Head\n 4.Search In Linked List\n 5.Delete Linked List\n 6.print Element\n";
    while(option){
        
        switch(option){
            case 1: head=CreateLinkedList();
                    break;

            case 2: cin>>d;
                    InsertData(d,head);
                    break;
                    
            case 3: cin>>d;
                    head = InsertAtHead(d,head);
                    break;
            
            case 4: cin>>d;
                    SearchInLinkedList(d,head);
                    break;
            
            case 5: DeleteLinkedList(head);
                    break;
            
            case 6: printElement(head);
        }
        cin>>option;
    }
    return 0;
}
