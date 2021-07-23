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
	Node* createList2(int* arr, int size) {
		Node* h, * l;
		h = l = NULL;
		for (int i = 0; i < size; i++) {
			Node* n = new Node(arr[i]);
			if (!h) {
				h = l = n;
			}
			else {
				l->next = n;
				l = l->next;
			}
		}
		return h;
	}
};

void display(Node* temp) {
	while (temp) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

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

void MoveLast_to_front(Node*& head) {
	Node* temp;
	temp = head;
	while (temp->next->next)
	{
		temp = temp->next;
	}
	Node* n = temp->next;
	n->next = head;
	temp->next = NULL;
	head = n;
}

Node* findIntersection(Node* head1, Node* head2)
{
	std::unordered_map<int, int> map;
	Node* t = head1;
	while (t)
	{
		map[t->data]++;
		t = t->next;
	}
	t = head2;
	Node* t1 = new Node(0);
	Node* l1 = t1;
	while (t)
	{
		map[t->data]++;
		if (map[t->data] == 2) {
			Node* n = new Node(t->data);
			l1->next = n;
			l1 = l1->next;
		}
		t = t->next;
	}
	t1 = t1->next;
	return t1;
}

int intersectPoint(Node* head1, Node* head2)
{
	std::unordered_map<Node*, int> map;
	while (head1)
	{
		map[head1]++;
		head1 = head1->next;
	}

	while (head2)
	{
		map[head2->next]++;
		if (map[head2] == 2) {
			return head2->data;
		}
		head2 = head2->next;
	}
	return -1;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	Node n;
	Node* p1 = n.createList2(arr, 7);
	int arr2[] = { 8,2,9,4,5,10,7 };
	Node* p2 = n.createList2(arr2, 7);
	Node* p3 = findIntersection(p1, p2);
	display(p3);
}