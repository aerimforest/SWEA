#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    head.next = nullptr;
}

// 맨 앞에 노드 추가
void addNode2Head(int data) 
{
    Node *node = getNode(data);
    node -> next = head.next;
    head.next = node;
}

// 맨 뒤에 노드 추가
void addNode2Tail(int data) 
{
    Node *node = getNode(data);
    Node *pre_ptr = &head;
    while(pre_ptr -> next != nullptr) {
        pre_ptr = pre_ptr -> next;
    }
    pre_ptr -> next = node;
}

// 지정된 순서에(num) 노드 추가
void addNode2Num(int data, int num) 
{
    int cnt = 1;
    Node *pre_ptr = &head;
    Node *node = getNode(data);
    while(cnt < num) {
        cnt++;
        pre_ptr = pre_ptr -> next;
    }
    node -> next = pre_ptr -> next;
    pre_ptr -> next = node;
}

void removeNode(int data) 
{
    Node *pre_ptr = &head;
    while(pre_ptr -> next != nullptr && pre_ptr -> next -> data != data) {
        pre_ptr = pre_ptr -> next;
    }
    if(pre_ptr -> next != nullptr) {
        pre_ptr -> next = pre_ptr -> next -> next;
    }
}

int getList(int output[MAX_NODE]) 
{
    int cnt = -1;
    Node *pre_ptr = &head;
    while(pre_ptr != nullptr) {
        output[cnt] = pre_ptr -> data;
        pre_ptr = pre_ptr -> next;
        cnt++;
    }
    return cnt;
}