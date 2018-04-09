#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
	int value;
	ListNode* next;
	ListNode(int x = 0): value(x), next(NULL){}
};

// add a node to the end of the list
void addTail(ListNode** pHead, int val){
	ListNode* pNew = new ListNode(val);
	// pNew -> value = val;
	// pNew -> next = NULL;

	if (*pHead == NULL) { *pHead = pNew; }
	else{
		ListNode* pNode = *pHead; 
		while(pNode -> next != NULL) {
			pNode = pNode -> next;
		}
		pNode -> next = pNew;
	} 
}

// delete the node which contains certain value
void deleteNode(ListNode** pHead, int val){
	if (*pHead == NULL) { return; }
	if ( (*pHead) -> value == val){
		*pHead = (*pHead) -> next;
		return;
	}
	ListNode* prev = NULL;
	ListNode* node = *pHead;
	while ( node -> value != val){
		prev = node;
		node = node -> next;
		if (node == NULL) { 
			cout << val << " is not in the list." << endl;
			return;
		}
	}
	prev -> next = node -> next;
	if ((*pHead) -> value == 1 && (*pHead) -> next == NULL )
		cout << "True!" << endl;
}

void print(ListNode* node){
	cout << "The elements in the lists are ";
	while (node -> next != NULL){
		cout << node -> value << ", ";
		node = node -> next;
	} 
	cout << node -> value << endl;	
}

void print_reverse(ListNode* node){
	stack<int> s;
	while (node != NULL){
		s.push(node -> value);
		node = node -> next;
	}
	cout << "The elements in the lists in reverse order are ";
	while (!s.empty()){
		if (s.size()!=1){
			cout << s.top() << ", ";
		}
		else { cout << s.top() << endl; }
		s.pop();
	}
}

void print_reverse_recursive(ListNode* node){
	if (node != NULL){
		if (node -> next != NULL){ 
		print_reverse_recursive(node -> next);
		}
		cout << node -> value << ", ";
	}
}

void recursive(ListNode* node){
	cout << "The elements in the lists in reverse order are ";
	print_reverse_recursive(node);
	cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int extra = 0;
    ListNode ans(0);
    ListNode* p = &ans;
    while (l1 != NULL || l2 != NULL || extra != 0 ){
        int val = (l1? l1->value:0) + (l2? l2->value:0) + extra;
        p -> next = new ListNode(val%10);  
        p = p -> next;
        extra = val/10;
        l1 = l1? l1 -> next : l1;
        l2 = l2? l2 -> next : l2;
    }
    return ans.next;
}

int main(){
	ListNode* node = new ListNode(1);
	//ListNode** input = *node;
	addTail(&node, 2); 
	addTail(&node, 3);
	ListNode* add = addTwoNumbers(node,node);
	print(add);
	// deleteNode(&node,4);
	// print(node);
	// recursive(node);
	return 0;
}
