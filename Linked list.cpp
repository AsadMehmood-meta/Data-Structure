#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
};

void insert_at_start(node*& head , int data);
void insert_at_end(node*& head , int data);
void displayNode(node* head);
void delete_at_start(node*& head);
void delete_at_end(node*& head);
void search_data(node* head , int x);

int main(){
	node* asad = NULL;
	
	delete_at_start(asad);
	delete_at_end(asad);
	
	insert_at_start( asad ,  50);
	insert_at_start( asad ,  20);
	insert_at_start( asad ,  15);
	insert_at_start( asad ,  10);
	insert_at_end( asad ,  70);
	insert_at_end( asad ,  80);
	insert_at_end( asad ,  100);
	
	search_data(asad , 50);
	search_data(asad , 100);
	search_data(asad , 20);
	
	displayNode(asad);
	
	delete_at_start(asad);
	
	displayNode(asad);
	
	delete_at_end(asad);
	
	displayNode(asad);
	
	return 0;
}

void insert_at_start(node*& head , int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	return;
}

void insert_at_end(node*& head , int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		return;
	}
	
	node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
	return;
}

void displayNode(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"Null\n";
}

void delete_at_start(node*& head){
	if(head == NULL){
		cout<<"List is empty already.\n";
		return;
	} else{
		head = head->next;
		return;
	}
}

void delete_at_end(node*& head){
	if(head == NULL){
		cout<<"List is empty already.\n";
		return;
	}
	
	if(head->next == NULL){
		delete head;
		head = NULL;
		return;
	}
	
	node* temp = head;
	
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	
	delete temp->next;
	temp->next = NULL;
	return;
}


void search_data(node* head , int x){
	node* temp = head;
	int count = 1;
	bool found = false;
	
	while(temp != NULL){
		if(temp->data == x){
			cout<<x<<" is in "<<count<<" node.\n";
			found = true;
			break;
		}
		
		temp = temp->next;
		count++;
	}
	
	if(!found){
		cout<<x<<" is not exist in list.\n";
	}
}
