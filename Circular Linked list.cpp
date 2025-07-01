#include <iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
};

void display(node* head);
void count_length(node* head);
void insert_at_start(node*& head , int x);
void insert_at_end(node*& head , int x);


int main(){
	node* asad = NULL;
	display(asad);
	count_length(asad);
	insert_at_start(asad , 50);
	display(asad);
	count_length(asad);
	insert_at_start(asad , 40);
	insert_at_start(asad , 30);
	insert_at_start(asad , 20);
	insert_at_start(asad , 10);
	insert_at_end(asad , 60);
	insert_at_end(asad , 65);
	insert_at_end(asad , 70);
	display(asad);
	count_length(asad);
	
	return 0;
}

void display(node* head){
	if(head == NULL){
		cout<<"List is empty.\n";
		return;
	}
	
	node* temp = head;
	
	do{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp != head);
	
	cout<<"NULL\n";
}

void count_length(node* head){
	if(head == NULL){
		cout<<"List is empty.\n";
		return;
	}
	
	int count = 0;
	
	node* temp = head;
	
	do{
		count++;
		temp = temp->next;
	}while(temp != head);
	
	cout<<"Length of list : "<<count<<endl;
}

void insert_at_start(node*& head , int x){
	node* newNode = new node();
	newNode->data = x;
	
	if(head == NULL){
		head = newNode;
		head->next = head;
		return;
	}
	
	node* temp = head;
	
	while(temp->next != head){
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->next = head;
	head = newNode;
}

void insert_at_end(node*& head , int x){
	node* newNode = new node();
	newNode->data = x;
	
	if(head == NULL){
		head = newNode;
		head->next = head;
		return;
	}
	
	node* temp = head;
	
	while(temp->next != head){
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->next = head;
}

