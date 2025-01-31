#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data=value;
        next=NULL;
    }
};

class linkedlist{
    public:
    node *head;
    int count;

    linkedlist(){
        this->head=NULL;
        this->count=0;
    }
    // -------------ADD---------------

    void addAtbegin(int ele){
        node* newnode=new node(ele);
        newnode->next=this->head;
        this->head=newnode;
        this->count++;
    }

    void addAtend(int ele){
        node* newnode= new node(ele);
        if(this->head==NULL){
            this->head=newnode;
        }
        else{
            node* ptr=this->head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            this->count++;
        }
    }

    void addAtposition(int ele,int position){
        node* newnode= new node(ele);
        if(position==0){
            newnode->next=NULL;
            this->head=newnode;
        }
        else{
            node* ptr=this->head;
            for(int i=1;i<position-1;i++){
                ptr=ptr->next;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;
            this->count++;
        }
    }

    // ------------------UPDATE---------------
    void update(int ele,int pos){
        if(pos<0 || pos>this->count){
            cout<<"Invalid position..";
            return;
        }
        else{
        node* ptr=this->head;
        for(int i=0;i<pos-1;i++){
            ptr=ptr->next;
        }
        ptr->data=ele;
        }
    }


    // ---------------DELETE--------------------
    void deletebegin(){
        if(this->head==NULL || this->count==0){
            cout<<"List is empty..";
            return;
        }
        node* ptr=this->head;
        this->head=head->next;
        delete ptr;
        ptr=NULL;
    }

     void deleteend(){
        if(this->head==NULL || this->count==0){
            cout<<"List is empty..";
            return;
        }
        else{
        node* ptr=this->head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        delete ptr->next;
        ptr->next=NULL;
        delete ptr;
        ptr=NULL;
        }
    }

    void deleteAtpos(int pos){
        if(this->head==NULL || this->count==0){
            cout<<"List is empty..";
        }
        else{
            node* prev=this->head;
            node* curr=this->head;
            for(int i=0;i<pos;i++){
                curr=curr->next;
            }
            for(int i=0;i<pos-1;i++){
                prev=prev->next;
            }
            prev->next=curr->next;
            delete curr;
            curr=NULL;
            delete prev;
            prev=NULL;
            this->count--;
        }
    }


    // ----------------DISPLAY-------------
    void show(){
        node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
};

int main(){
    linkedlist a;
    int choice,ele,pos;

    do{
        cout<<"Press 1 for adding a node at beginning."<<endl;
        cout<<"Press 2 for adding a node at end."<<endl;
        cout<<"Press 3 for adding a node at particular position."<<endl;
        cout<<"Press 4 for display element."<<endl;
        cout<<"Press 5 for update an element."<<endl;
        cout<<"Press 6 for delete an element at beginning."<<endl;
        cout<<"Press 7 for delete an element at end."<<endl;
        cout<<"Press 8 for delete an element at particular position."<<endl;
        cout<<"Press 0 for exit."<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter your element : ";
            cin>>ele;
            cout<<endl;
            a.addAtbegin(ele);
            cout<<"Element added at beginning successfully..."<<endl<<endl;
            break;

            case 2:
            cout<<"Enter your element : ";
            cin>>ele;
            cout<<endl;
            a.addAtend(ele);
            cout<<"Element added at end successfully..."<<endl<<endl;
            break;

            case 3:
            cout<<"Enter your element : ";
            cin>>ele;
            cout<<"Enter your position : ";
            cin>>pos;
            cout<<endl;
            a.addAtposition(ele,pos);
            cout<<"Element added at position successfully..."<<endl<<endl;
            break;

            case 4:
            a.show();
            cout<<endl;
            break;

            case 5:
            cout<<"Enter your element : ";
            cin>>ele;
            cout<<"Enter your position : ";
            cin>>pos;
            cout<<endl;
            a.update(ele,pos);
            cout<<"Element updated successfully..."<<endl<<endl;
            break;

            case 6:
            a.deletebegin();
            cout<<"Element deleted at begin is successfull.."<<endl<<endl;
            break;

            case 7:
            a.deleteend();
            cout<<"Element deleted at end is successfull.."<<endl<<endl;
            break;

            case 8:
            cout<<"Enter your position : ";
            cin>>pos;
            cout<<endl;
            a.deleteAtpos(pos);
            cout<<"Element deleted at position is successfull.."<<endl<<endl;
            break;

            case 0:
            break;

            default:
            cout<<"Enter valid choice....."<<endl<<endl;
            break;
        }
    }while(choice!=0);

}