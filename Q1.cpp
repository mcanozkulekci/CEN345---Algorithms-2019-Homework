#include <stdio.h>
#include <stdlib.h>
#include <iostream>


struct Node{
	int data;
	struct Node *next;

}*first=NULL;


class LinkedList{
	
	public:
	
	void create(int A[],int n);
	Node *RSearch(struct Node *p,int key);
	void Insert(struct Node *p,int index,int x);
	int  count(struct Node *p);
	void Display(struct Node *p);

	};







void LinkedList::create(int A[],int n){
	int i;
	struct Node *t,*last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++){
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;

	}


}


 Node* LinkedList ::RSearch(struct Node *p,int key){
	int i;
	struct Node *q=first;
	
	int count;
	if(p==NULL){
	
		return NULL;
	
	}
	if(p->data == key){
		printf("Listedeki elemanların pozitif tam bolenleri:\n");
		while(q){
			printf("%d sayisinin pozitif tam bolenleri: -->",q->data);
			for(i=1;i<=q->data;i++){
				if(q->data % i == 0){

					
					printf("%d ",i);

					

				}
			}
			printf("\n");
			q=q->next;
		}

		return p;
	}

	return RSearch(p->next,key);
}


void LinkedList:: Insert(struct Node *p,int index,int x){
	struct Node *t;
	int i;
	if(index <0)
		return;
	t=(struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	if(index==0){
		t->next=first;
		first=t;
}
	else{
		for(i=0;i<index-1;i++){
			p=p->next;
		}

		t->next=p->next;
		p->next=t;

	}
}

int LinkedList:: count(struct Node *p){
	int count=0;
	while(p){
		count++;
		p=p->next;
	}
	return count;


}

void LinkedList:: Display(struct Node *p){
	int i=1;
	while(p){
		printf("%d. element is %d \n",i,p->data);
		p=p->next;
		i++;
	}
}


int main(){
	int n,i;
	int *arr;
	int val;
	struct Node *temp;
	LinkedList l;
	printf("Linked list in kaç elemanı olmalı?");
	scanf("%d",&n);
	if(n<1){
		printf("Uygun bir sayi giriniz!\n");
		exit(-1);
	}
	arr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		printf("Lütfen %d. elemanı giriniz.\n ",i+1);
		
		scanf("%d",&arr[i]);

	}
	l.create(arr,n);
	l.Display(first);

	printf("Linked Listte Aramak İstediğiniz Elemanı Giriniz:\n");
	scanf("%d",&val);
	temp =l.RSearch(first,val);
	if(temp){
		printf("Listede Var.");
		


	}else{
		printf("Listede Yok.");

	}



	return 0;
}