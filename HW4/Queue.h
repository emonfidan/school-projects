#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
template class<ItemType>
class Queue{
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        return front==-1;
    }
    bool isFull(){
        return rear==4 && front==0;
    }
    void enqueue(ItemType& item){
        if(!isFull){
            if(front==-1)front=0;
            rear++;
            arr[rear]=item;
        }
    }
    int dequeue(){
        int item;
        if(!isEmpty()){
            item=arr[front];
            if(front>=rear){
                front=-1;
                rear=-1;
            }
            else{
                front++;
            }
            return item;
        }
    }
private:
    int front;
    int rear;
    ItemType arr[5];
};


#endif // QUEUE_H_INCLUDED
