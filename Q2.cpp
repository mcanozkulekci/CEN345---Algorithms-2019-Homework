#include <iostream>

using namespace std;
class Node{
    public:
    Node *next;
    int data;

};

class Stack{

    private:
    Node *top;
    public:
    Stack(){top=NULL;}
    void push(int x);
    int pop();
    void Display();
    int StackSize();
};



int Stack::StackSize(){
    int count=0;
    if(top==NULL){
        return 0;
        cout<<"Stack is Empty!\n";
    }else{
        Node *t=top;
        while(t!=NULL){
            count++;
            t=t->next;
        }

    }

    return count;

}








void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL){
        cout<<"Stack Overflow!\n";
    
    }else{
        t->data=x;
        t->next=top;
        top=t;

    }

}

int Stack::pop(){

    int x=-1;
    if(top==NULL){
        cout<<"Stack Underflow\n";
    }else{
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;


    }
    return x;
}


void Stack::Display(){

    Node *t =top;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }

    cout<<endl;


}

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}


void swapinArray(int A[],int i,int j){
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;

}
void NonRecSort(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }

}

void recurSelectionSort(int A[],int i,int n){


    //find the min element in the UNSORTED subrray[i...n-1]
    //and swap it with A[i]
    int min=i;
    for(int j=i+1;j<n;j++){
        //if A[j] element is less,then it is the new min
        if(A[j]<A[min]){
            min=j;
        }

    }
    swapinArray(A,min,i);
    if(i+1<n){
        recurSelectionSort(A,i+1,n);
    }

}

int main(){


    Stack stk;
    int opt,x,i,sizeofArray;
    int *A=NULL;
    
   
    
    
    while(1){
        cout<<"1-Yığına ekleme işlemi\n2-Sıralama işlemi 1: Recursive Sort\n3-Sıralama işlemi 2: Nonrecursive Sort\n4-Listeleme işlemi\n5-Çıkış\n";
        cin>>opt;
        cout<<"\n";
        switch(opt){
            case 1:
                
                cout<<"Lütfen Stacke Eklemek İstediğiniz Sayiyi Giriniz:\n";
                cin>>x;
                stk.push(x);
                
                break;
            case 2:
                sizeofArray=stk.StackSize();
                A=new int[sizeofArray];
                for(i=0;i<sizeofArray;i++){
                    
                    A[i]=stk.pop();
                    

                }

                recurSelectionSort(A,0,sizeofArray);
                cout<<"Recursive Sorted Array is:\n";
                for(i=sizeofArray-1;i>= 0;i--){
                    stk.push(A[i]);
                }
                
                stk.Display();
                
                
                
                
                break;
            case 3:
                sizeofArray=stk.StackSize();
                A=new int[sizeofArray];
                for(i=0;i<sizeofArray;i++){
                    
                    A[i]=stk.pop();
                    

                }

                
                NonRecSort(A,sizeofArray);
                cout<<"Non-Recursive Sorted Array is:\n";
                for(i=sizeofArray-1;i>= 0;i--){
                    stk.push(A[i]);
                }
                stk.Display();
                
                
                break;
            case 4: 
                
                stk.Display();
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