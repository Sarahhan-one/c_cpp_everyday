#include <stdio.h>
#include <stdlib.h>

//DLL(Double Linked List) - list structure with 2 linking info 
// Head, Tail - dummy nodes

typedef int ElementType; 
typedef struct _nodeDLL {
	ElementType Data;
	struct _nodeDLL* prev;
	struct _nodeDLL* next;
}nodeDLL;

typedef struct _nodeT {
	ElementType Data;
	struct _nodeT* left;
	struct _nodeT* right;
}nodeT; 

typedef nodeDLL* p_nodeDLL; 
typedef nodeT* p_nodeT; 

nodeDLL* DLL_CreateNode(ElementType value) {
	//allcoate memory
	//reset the members in struct 
	nodeDLL* node = (nodeDLL*)malloc(sizeof(nodeDLL)); 
	if (node == NULL) {
		exit(1); 
		return;
	}
	node->Data = value; 
	node->prev = NULL; 
	node->next = NULL; 
	return node;
}

nodeT* T_CreateNode(ElementType value) {
	p_nodeT node = (p_nodeT)malloc(sizeof(nodeT)); 
	if (node == NULL) {
		exit(1);
		return; 
	}
	node->Data = value; 
	node->left = NULL; 
	node->right = NULL;
	return node;
}

void DLL_AppendNode(p_nodeDLL Tail, p_nodeDLL newNode) {
	newNode->prev = Tail->prev; 
	newNode->next = Tail;
	Tail->prev->next = newNode;
	Tail->prev = newNode;
}

void DLL_PrintNode(p_nodeDLL Head, p_nodeDLL Tail) {
	for (p_nodeDLL curr = Head->next; curr != Tail; curr = curr->next) {
		printf("%d ", curr->Data);
	}
}

p_nodeDLL searchNode(ElementType num, p_nodeDLL head, p_nodeDLL tail) {
	for (p_nodeDLL curr = head->next; curr != tail; curr = curr->next) {
		if (curr->Data == num) return curr; 
	}
	return NULL; 
}

void destroyNode(p_nodeDLL* dnode) {
	free(*dnode);
	*dnode = NULL;
}

void deleteNode(p_nodeDLL dnode) {
	if (dnode == NULL) return;
	dnode->next->prev = dnode->prev; 
	dnode->prev->next = dnode->next; 
	destroyNode(&dnode);
}

void insertAfter(p_nodeDLL fnode, p_nodeDLL newnode) {
	newnode->next = fnode->next; 
	newnode->prev = fnode; 
	fnode->next->prev = newnode;
	fnode->next = newnode;
}

void insertBefore(p_nodeDLL fnode, p_nodeDLL newnode) {
	newnode->next = fnode; 
	newnode->prev = fnode->prev; 
	fnode->prev->next = newnode; 
	fnode->prev = newnode;
}

int main() {
	p_nodeDLL Head = DLL_CreateNode(0);
	p_nodeDLL Tail = DLL_CreateNode(0);
	Head->next = Tail;
	Tail->prev = Head;

	DLL_AppendNode(Tail, DLL_CreateNode(10));
	DLL_AppendNode(Tail, DLL_CreateNode(20));
	DLL_AppendNode(Tail, DLL_CreateNode(30));
	DLL_PrintNode(Head, Tail);
	printf("%d ", searchNode(10, Head, Tail)->Data);

	p_nodeDLL dnode = searchNode(10, Head, Tail);
	deleteNode(dnode);
	deleteNode(dnode);
	//printf("%d %d %d\n", Head->next->Data, Head->next->next->Data, Head->next->next->next->Data);

#if 0
	//option 1 : 
	//nodeDLL Head = { 0 }; 
	//nodeDLL Tail = { 0 };
	//Head.next = &Tail;
	//Tail.prev = &Head; 

	//option 2 : 
	p_nodeDLL Head = DLL_CreateNode(0); // dummy val 
	p_nodeDLL Tail = DLL_CreateNode(0);
	Head->next = Tail;
	Tail->prev = Head;

	//nodeDLL A, B, C; 
		//option 1:
		//A.prev = &Head; 
		//A.next = &B;
		//A.Data = 10; 

		//B.prev = &A;
		//B.next = &C;
		//B.Data = 20;

		//C.prev = &B;
		//C.next = &Tail;
		//C.Data = 30;

		//A = (nodeDLL){ 10, NULL, &B };
		//B = (nodeDLL){ 20, &A, &C };
		//C = (nodeDLL){ 30, &B, NULL };
		//printf("%d %d %d\n", A.Data, A.next->Data, A.next->next->Data);
		//printf("%d %d %d\n", B.prev->Data, B.Data, B.next->Data);
		//printf("%d %d %d\n", C.prev->prev->Data, C.prev->Data, C.Data);
#endif 

#if 0
	p_nodeT A, B, C, D, E;

	A = T_CreateNode(1);
	B = T_CreateNode(2);
	C = T_CreateNode(3);
	D = T_CreateNode(4);
	E = T_CreateNode(5);

	A->left = B;
	A->right = C;

	B->left = D; 
	B->right = E; 

	printf("%d %d %d\n", A->Data, A->left->Data, A->left->left->Data); 
	printf("%d %d %d\n", A->Data, A->left->Data, A->left->right->Data);
#endif
}