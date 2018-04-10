#include <iostream>

Node* MergeLists(Node* headA, Node* headB){
	Node* mergeList = new Node();
	Node* tempA = headA;
	Node* tempB = headB;

	if (tempA==NULL){		return headB;	}
	else if (tempB==NULL){	return headA;	}
	else if (tempA==NULL &&
			 tempB==NULL){	return NULL;	}

	while(tempA!=NULL && tempB!=NULL){
		if (tempA->data <= tempB->data){
			mergeList = tempA;
			tempA = headA->next;
		}else{
			mergeList = tempB;
			tempB = headB->next;
		}
	}
	return mergeList;  
}