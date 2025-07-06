#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int val;
	Node* next;
	Node* prev;

	Node(int val, Node* next, Node* prev) {
		this->val = val;
		this->next = next;
		this->prev = prev;
	}
};

void display(Node* head) {
	Node* temp = head;
	Node* lastNode;

	while(temp) {
		string tail = (temp->next == nullptr) ? "" : " -> ";
		cout << temp->val << tail;
		lastNode = (!temp->next) ? temp : nullptr;
		temp = temp->next;		
	}

	cout << endl;
	temp = lastNode;
	
	while(temp) {
		string tail = (temp->prev == nullptr) ? "" : " <- ";
		cout << temp->val << tail;
		temp = temp->prev;
	}
}

void findPairs(Node* head, int target, vector<vector<int>>& result) {
	Node* temp = head;
	
	while(temp) {
		Node* temp1 = temp->next;
		while(temp1 && temp->val + temp1->val <= target) {
			if(temp->val + temp1->val == target) {
				vector<int> arr = {temp->val, temp1->val};
				result.push_back(arr);				
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}
//TC - O(n^2)

void findPairs(Node* head, int target, vector<vector<int>>& result) {
	Node* temp = head;
	Node* tail = head;

	while(tail->next) {
		tail = tail->next;
	}

	while(temp->val <= tail->val) {
		if(temp->val + tail->val == target) {
			vector<int> arr = {temp->val, temp1->val};
			result.push_back(arr);
			temp = temp->next;
			tail = tail->prev;
		} else if(temp->val + tail->val < target) {
			temp = temp->next;
		} else {
			tail = tail->prev;
		}
	}
}

void removeDuplicates(Node* head) {
	if(head == nullptr || head->next == nullptr)
		return head;
	
	Node* temp = head;
	Node* temp1 = head->next;
	
	while(temp && temp1) {
		while(temp1 && temp->val == temp1->val) {
			temp1 = temp1->next;
		}

		temp->next = temp1;
		if(temp1) temp1->prev = temp;

		temp = temp->next;
		temp1 = temp1->next;
	}
}

Node* reverse(Node* temp) {
	Node* prev = nullptr;
	Node* curr = temp;
	Node* after = curr;

	while(curr) {
		after = after->next;
		curr->next = prev;
		prev = curr;
		curr = after;
	}
	return prev;
}

Node* kthNode(Node* temp, int k) {
	while(temp != nullptr && k > 0) {
		temp = temp->next;
		k--;
	}
	return (k == 0) ? temp : nullptr;
}

void reverseKGroups(Node* head, int k) {
	Node* temp = head;	
	Node* prevLast = nullptr;

	while(temp) {
		Node* nodeK = kthNode(temp, k);
		
		if(!nodeK) {
			if(prevLast) prevLast->next = temp;
			break;
		}

		Node* nextNode = nodeK->next;
		nodeK->next = nullptr;
		Node* newHead = reverse(temp);

		if(temp == head) {
			head = nodeK;
		} else {
			prevLast->next = nodeK;
		}

		prevLast = temp;
		temp = nextNode;
	}	
}

1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 ; k = 3
3 - 2 - 1 - 6 - 5 - 4 - 9 - 8 - 7 - 10

int main() {
	Node* head = new Node(1, nullptr, nullptr);
	Node* temp = head;

	vector<int> input = {2, 3, 4, 5, 6};

	for(int i = 0; i < input.size(); i++) {
		Node* newNode = new Node(input[i], nullptr, temp);
		temp->next = newNode;
		temp = temp->next;
	}

	vector<vector<int>> result;
	int target = 10;

	//display(head);
	findPairs(head, target, result);

	for(int i = 0; i < result.size(); i++) {
		for(auto ele : result[i]) {
			cout << ele << " ";
		}
		cout << endl;
	}
}