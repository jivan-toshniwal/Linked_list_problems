#include <iostream>
#include <string>
#include <unordered_map>
class Node {
public:
	int data;
	Node* next, * head, * last;
	Node(int val = 0)
		:data(val) {
		head = last = next = NULL;
	}

	void createList(int* arr, int size) {
		for (int i = 0; i < size; i++) {
			Node* n = new Node(arr[i]);
			if (!head) {
				head = last = n;
			}
			else {
				last->next = n;
				last = last->next;
			}
		}
	}

	void display() {
		Node* temp = head;
		while (temp) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
};


bool is_palindrom(Node* head) {
	std::string str = "";
	Node* temp = head;
	while (temp)
	{
		str += std::to_string(temp->data);
		temp = temp->next;
	}
	int k = str.size();
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[--k]) {
			return false;
		}
	}
	return true;
}
void swap_data(Node* head, int x, int y) {
	if (x == y) return;
	Node* temp = head;
	while (temp)
	{
		if (temp->data == x) {
			temp->data = y;
		}
		else if (temp->data == y) {
			temp->data = x;
		}
		temp = temp->next;
	}
}

Node* pair_swap_Node(Node* head, int k) {
	Node* pre = NULL;
	Node* mid = nullptr;
	Node* cur = head;
	int x = k;
	while (cur && x--)
	{
		pre = mid;
		mid = cur;
		cur = cur->next;
		mid->next = pre;
	}
	if (cur) {
		head->next = pair_swap_Node(cur, k);
	}
	return mid;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	Node n;
	n.createList(arr, 7);
	n.display();
	Node* newNode = pair_swap_Node(n.head, 7);
	n.head = newNode;

	n.display();
}