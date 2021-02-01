#include <iostream>
#include <stdlib.h>

using namespace std;
struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
    static Node *getnode(int data){
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=data;
        newNode->next=newNode->prev=NULL;
        return newNode;
    }
};


class Queue{

private:
Node *front;
Node *rear;
int Size;

public:
//Constructor
Queue(){
    //Initialization
    front=rear=NULL;
    Size=0;
}
void enqueue(int data);
int dequeue();
void Display();
bool isEmpty();
int Qsize();


};

int Queue::Qsize(){
    return Size;


}
bool Queue::isEmpty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }

}

void Queue::enqueue(int data){
    Node *newNode = Node::getnode(data);
    if(newNode==NULL){
        cout<<"\nQueue Full!\n";
    }else{
        if(rear==NULL){
            front=rear=newNode;

        }else{
            newNode->prev=rear;
            rear->next=newNode;
            rear=newNode;
            
        }
        Size++;

    }

}

void Queue::Display(){
   if(isEmpty()){
        cout<<"\nDeque boş!!!\n";
    }else{
        Node *q=front;
        while(q!=rear->next){
            cout<<q->data<<"\t";
            q=q->next;
        }
    }

}

int Queue::dequeue(){
    if(isEmpty()){
        cout<<"\nQueue empty!\n";
    }else{
        int x=-1;
        Node *q=front;
        x=front->data;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }else{
            front->prev=NULL;
        }
        
        free(q);
        Size--;
        return x;

    }

}


void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}
// A function to implement bubble sort 
void RbubbleSort(int arr[], int n) 
{ 
    // Base case 
    if (n == 1) 
        return; 
  
    // One pass of bubble sort. After 
    // this pass, the largest element 
    // is moved (or bubbled) to end. 
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
  
    // Largest element is fixed, 
    // recur for remaining array 
    RbubbleSort(arr, n-1); 
} 

void IbubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  


int main(){

    Queue q;
    int opt,x,i,sizeofArray;
    int *A=NULL;
    while(1){
        cout<<"\n1-Kuyruğa ekleme işlemi\n2-Sıralama işlemi 1: Recursive Bubble Sort\n3-Sıralama işlemi 2: Iterative Bubble Sort\n4-Listeleme işlemi\n5-Çıkış\n";
        cin>>opt;
        cout<<"\n";
        switch(opt){

            case 1:
                cout<<"Lütfen Queueye Eklemek İstediğiniz Sayiyi Giriniz:\n";
                cin>>x;
                q.enqueue(x);
                
                break;

            case 2:
                sizeofArray=q.Qsize();
                A = new int[sizeofArray];
                for(i=0;i<sizeofArray;i++){
                    A[i]=q.dequeue();
                }

                
                RbubbleSort(A,sizeofArray);
                cout<<"Recursive Sorted Array is:\n";
                for(i=0;i<sizeofArray;i++){
                    q.enqueue(A[i]);
                }
                q.Display();
                 break;

            case 3:
                sizeofArray=q.Qsize();
                A = new int[sizeofArray];
                for(i=0;i<sizeofArray;i++){
                    A[i]=q.dequeue();
                }

                
                IbubbleSort(A,sizeofArray);
                cout<<"Iterative Sorted Array is:\n";
                for(i=0;i<sizeofArray;i++){
                    q.enqueue(A[i]);
                }
                q.Display();
                break;

            case 4:
                q.Display();
                for(i=1;i<sizeofArray+1;i++){
                     cout<<"Step "<<i<<": ->";
                    for(int j=0;j<i;j++){
                       cout<<A[j]<<" ";
                        

                    }
                    cout<<"\n";

                }   
                break;
            case 5:
                cout<<"Programdan Başarıyla Çıkış Yapıldı!\n";
                exit(-1);
                break;
            default:
                cout<<"Geçersiz Seçim Tekrar Deneyiniz!"<<endl;
                break;



        }




    }



    return 0;
}