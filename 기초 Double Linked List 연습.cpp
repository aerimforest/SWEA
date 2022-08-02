// 기초 Double Linked List 연습
#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head, *tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);

    head -> prev = nullptr;
    head -> next = tail;

    tail -> prev = head;
    tail -> next = nullptr;
}

void addNode2Head(int data) 
{
	Node *node = getNode(data);
    head -> next -> prev = node;
    node -> next = head -> next;
    node -> prev = head;
    head -> next = node;
}

void addNode2Tail(int data) 
{
	Node *node = getNode(data);
    tail -> prev -> next = node;
    node -> prev = tail -> prev;
    node -> next = tail;
    tail -> prev = node;
}

void addNode2Num(int data, int num) 
{
	int cnt = 1;
    Node *pre_ptr = head;
    Node *node = getNode(data);

    while(cnt < num) {
        cnt++;
        pre_ptr = pre_ptr -> next;
    }
    pre_ptr -> next -> prev = node;
    node -> next = pre_ptr -> next;
    node -> prev = pre_ptr;
    pre_ptr -> next = node;
}

int findNode(int data) 
{
	int idx = 0;
    Node *ptr = head;
    while(ptr -> data != data) {
        idx++;
        ptr = ptr -> next;
    }
    return idx;
}

void removeNode(int data) 
{
	Node *pre_ptr = head;
    while(pre_ptr -> next != nullptr && pre_ptr -> next -> data != data) {
        pre_ptr = pre_ptr -> next;
    }
    if(pre_ptr -> next != nullptr) {
        pre_ptr -> next -> next -> prev = pre_ptr;
        pre_ptr -> next = pre_ptr -> next -> next;
    }
}

int getList(int output[MAX_NODE]) 
{
	int tmpCnt = 0;
    Node *pre_ptr = head -> next;
    while(pre_ptr -> next != nullptr) {
        output[tmpCnt++] = pre_ptr -> data;
        pre_ptr = pre_ptr -> next;
    }
    return tmpCnt;
}

int getReversedList(int output[MAX_NODE]) 
{
	int tmpCnt = 0;
    Node *pre_ptr = tail -> prev;
    while(pre_ptr -> prev != nullptr) {
        output[tmpCnt++] = pre_ptr -> data;
        pre_ptr = pre_ptr -> prev;
    }
    return tmpCnt;
}