#include<iostream>
using namespace std;

class Queue{
    int* ar;
    int front;
    int rear;
    int count;
    int capacity;

    public:
    Queue(int capacity){
        ar=new int[capacity];
        front=-1;
        rear=-1;
        count=0;
        this->capacity=capacity;
    }

    void enqueue(int ele){
        if(rear==capacity-1){
            cout<<"Queue overflow.."<<endl;
        }
        else if(front==-1 && rear==-1){
            front=rear=0;
            ar[rear]=ele;
            count++;
        }
        else{
            rear++;
            ar[rear]=ele;
            count++;
        }
    }

    void dequeue(){
        if(front==-1 && rear==-1){
            cout<<"Queue underflow.."<<endl;
        }
        else if (front==0 && rear==0){
            front=rear=-1;
            count--;
        }
        else{
            front++;
            count--;
        }
    }

    void getfront(){
        if(front==-1){
            cout<<"Queue is empty.."<<endl;
        }
        else{
            cout<<ar[front];
        }
    }

    void getrear(){
        if(front==-1){
            cout<<"Queue is empty.."<<endl;
        }
        else{
            cout<<ar[rear];
        }
    }

    void display(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty.."<<endl;
        }
        else{
            for(int i=front;i<=rear;i++){
                cout<<ar[i]<<" ";
            }
        }
        cout<<endl;
    }

    void isEmpty(){
        if(front==-1 && rear==-1){
            cout<<"Queue is empty.."<<endl;
        }
        else{
            cout<<"Queue is not empty.."<<endl;
        }
    }

    void isFull(){
        if(rear==capacity-1){
            cout<<"Queue is full.."<<endl;
        }
        else{
            cout<<"Queue is not full.."<<endl;
        }
    }

    void size(){
        cout<<"Size of queue : "<<count<<endl;
    }
};


int main(){
    Queue q(5);
    int choice;

    do{
        cout<<"Press 1 for enqueue operation"<<endl;
        cout<<"Press 2 for dequeue operation"<<endl;
        cout<<"Press 3 for front operation"<<endl;
        cout<<"Press 4 for rear operation"<<endl;
        cout<<"Press 5 for display operation"<<endl;
        cout<<"Press 6 for isEmpty operation"<<endl;
        cout<<"Press 7 for isFull operation"<<endl;
        cout<<"Press 8 for size operation"<<endl;
        cout<<"Press 0 for exit"<<endl<<endl;

        cout<<"Enter your choice";
        cin>>choice;

        switch(choice){
            case 1:
            int ele;
            cout<<"Enter your element : ";
            cin>>ele;
            q.enqueue(ele);
            cout<<endl;
            break;

            case 2:
            q.dequeue();
            cout<<endl;
            break;

            case 3:
            q.getfront();
            break;

            case 4:
            q.getrear();
            break;

            case 5:
            q.display();
            break;

            case 6:
            q.isEmpty();
            break;

            case 7:
            q.isFull();
            break;

            case 8:
            q.size();
            break;

            case 0:
            break;

            default:
            cout<<"Invalid choice..."<<endl;
        }
    }while(choice!=0);

}