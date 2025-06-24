#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
};

node* insert_at_start(node* head , int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = head;
	return newNode;
}

node* insert_at_end(node* head , int data){
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL){
		return newNode;
	}
	
	node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	temp->next = newNode;
	return head;
}

void displayNode(node* head){
	while(head != NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"Null\n";
}

int main(){
	node* asad = NULL;
	
	asad = insert_at_start( asad ,  5);
	asad = insert_at_start( asad ,  2);
	asad = insert_at_end( asad ,  10);
	
	displayNode( asad);
}
