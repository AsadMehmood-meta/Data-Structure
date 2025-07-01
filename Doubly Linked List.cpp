#include<iostream>

using namespace std;

class node {
	public:
		int data;
		node* next;
		node* prev;
};

void insert_at_start(node*& head , int x);
void insert_at_end(node*& head , int x);
void display_node(node* head);
void count_length(node*& head);
void delete_at_start(node*& head);
void delete_at_end(node*& head);

int main(){
	node* asad = NULL;
	insert_at_start(asad , 50);
	delete_at_end(asad);
	display_node(asad);
	insert_at_start(asad , 40);
	insert_at_start(asad , 30);
	insert_at_start(asad , 20);
	insert_at_start(asad , 10);
	insert_at_start(asad , 5);
	insert_at_end(asad , 60);
	insert_at_end(asad , 70);
	display_node(asad);
	delete_at_end(asad);
	display_node(asad);
	delete_at_start(asad);
	display_node(asad);
	count_length(asad);
	
	return 0;
}

void count_length(node*& head){
	int count = 0;
	
	node* temp = head;
	
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	
	cout<<"Length of list : "<<count<<endl;
}

void display_node(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"NULL\n";
	
}

void insert_at_start(node*& head , int x){
	node* newNode = new node();
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = head;
	
	if(head != NULL){
		head->prev = newNode;
	}
	head = newNode;
}

void insert_at_end(node*& head , int x){
	node* newNode = new node();
	newNode->data = x;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		head->prev = NULL;
		return;
	}
	
	node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
	newNode->prev = temp;
}

void delete_at_start(node*& head){
	if(head == NULL){
		cout<<"List is empty.\n";
		return;
	}
	
	node* temp = head;
	head = temp->next;
	
	if(head != NULL){
	head->prev = NULL;	
	}
	
	delete temp;

}

void delete_at_end(node*& head){
	if(head == NULL){
		cout<<"List is empty.\n";
		return;
	}
	
	if(head->next == NULL){
		delete head;
		head = NULL;
		return;
	}
	
	node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
}


