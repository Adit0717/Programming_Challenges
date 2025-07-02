#include <bits/stdc++.h>

class Node{
private:
	int value;
	Node* next;

public:
	Node(int value) {
		this->value = value;
		next = nullptr;
	}
	
	int getValue() {
		return value;
	}

	void setValue(int value) {
		this->value = value;
	}

	Node* getNext() {
		return next;
	}

	void setNext(Node* nextNode) {
		next = nextNode;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	int getHead(){
		return head->getValue();
	}

	int getTail(){
		return tail->getValue();
	}

	int getLength() {
		return length;
	}

	void prepend(int value){
		Node* newNode = new Node(value);
		length++;
		newNode->setNext(head);
		head = newNode;
	}

	void append(int value) {
		Node* newNode = new Node(value);
		length++;
		tail->setNext(newNode);
		tail = newNode;
	}	

	void printList() {
		Node* temp = head;
		while(temp){
			string tailEnd = (temp->getNext() == nullptr) ? "" : " -> ";
			cout << temp->getValue() << tailEnd;
			temp = temp->getNext();
		}
	}

	void deleteLast() {
		if(length == 0) {
			return;
		} else {
			Node* temp = head;
			Node* prev = head;
			if (length == 1) {
				head = nullptr, tail = nullptr;
				delete temp;				
			} else {
				while(temp->getNext() != nullptr){
					prev = temp;
					temp = temp->getNext();
				}
				tail = prev;				
				prev->setNext(nullptr);
				delete temp;
			}
			length--;			
		}		
	}

	Node* getAtIndex(int index){
		if(index < 0 || index >= length){
			return nullptr;
		}
		else{
			Node* temp = head;
			for(int i = 0; i < index; i++){
				temp = temp->getNext();
			}
			return temp;
		}
	}

	bool setAtIndex(int index, int value){
		if(index < 0 || index >= length){
			return false;
		} else{
			Node* temp = getAtIndex(index);
			
			if(temp){
				temp->setValue(value);
				return true;
			}			
		}
		return false;
	}

	bool insertAtIndex(int value, int index){
		if(index < 0 || index >= length){
			return false;
		}

		if(index == 0){
			prepend(value);
			return true;
		}

		if(index == length){
			append(value);
			return true;
		}

		Node* newNode = new Node(value);
		Node* temp = getAtIndex(index - 1);
		newNode->setNext(temp->getNext());
		temp->setNext(newNode);
		length++;
		return true;		
	}

	bool deleteAtIndex(int index) {
		if(index < 0 || index >= length){
			return false;
		}

		if(index == 0) {
			Node* temp = head;
			head = head->getNext();			
			delete temp;
			length--;
			return true;
		}

		if(index == length - 1){
			deleteLast();			
			return true;
		}

		Node* prev = getAtIndex(index - 1);
		Node* temp = prev->getNext();
		prev->setNext(temp->getNext());
		delete temp;
		length--;
		return true;
	}	

	void reverse() {
		Node* prev = nullptr;
		Node* curr = head;
		Node* temp = head;
		tail = curr;
		
		while(temp){
			temp = temp->getNext();
			curr->setNext(prev);
			prev = curr;
			curr = temp;
		}
		head = prev;
	}

	~LinkedList() {
		Node* temp = head;
		while (temp) {
			Node* nextNode = temp->getNext();
			delete temp;
			temp = nextNode;
		}
	}
};

class ListNode {
public:
	int val;
  	ListNode *next;
  	ListNode() : val(0), next(nullptr) {}
  	ListNode(int x) : val(x), next(nullptr) {}
  	ListNode(int x, ListNode *next) : val(x), next(next) {}

  	static ListNode* reverse(ListNode* head) {
  		ListNode* prev = nullptr;
  		ListNode* curr = head;
  		ListNode* after = curr;

  		while(curr != nullptr) {
  			after = after->next;
  			curr->next = prev;
  			prev = curr;
  			curr = after;
  		}
  		return prev;
  	}

  	static void displayList(ListNode* head) {
		if(head == nullptr) return;
  		ListNode* temp = head;
  		
  		while(temp != nullptr) {
  			string result = "";

  			result = (temp->next == nullptr) ? "" : " -> ";
  			cout << temp->val << result;
  			temp = temp->next;
  		}
  		cout << endl;
  	}

  	static ListNode* addOne(ListNode* head) {
  		if(head == nullptr) return head;	
  		
  		head = reverse(head);
  		ListNode* temp = head;
  		ListNode* prev = nullptr;
  		int carry = 1;
  		
  		while(temp != nullptr) {
  			int sum = temp->val + carry;
  			carry = sum / 10;
  			temp->val = sum % 10;

  			prev = temp;
  			temp = temp->next;
  		}

  		if(carry != 0) {
  			prev->next = new ListNode(carry);
  		}

  		ListNode* result = reverse(head);
  		return result;
  	}
};

int main() {

	ListNode* temp = new ListNode(9);
	ListNode* head = temp;
	temp->next = new ListNode(9);
	temp = temp->next;
	temp->next = new ListNode(9);

	ListNode* result = ListNode::addOne(head);
	ListNode::displayList(result);

	/*
	LinkedList* newList = new LinkedList(1);	
    newList->append(2);
    newList->append(3);
    newList->append(4);
    newList->append(5);
	*/

    /*
    cout << "Length: " << newList->getLength() << endl;
    cout << "List: " << endl;
    newList->printList();	

    cout << newList->getHead() << " ";
    cout << newList->getTail() << " ";

    newList->printList();
    cout << endl;
    newList->deleteLast();

    newList->printList();
    cout << endl;
    newList->deleteLast();

    newList->printList();
    */
    /*
    newList->printList();
    cout << endl;
    newList->reverse();
    newList->printList();

    delete newList;
    */



	return 0;
}