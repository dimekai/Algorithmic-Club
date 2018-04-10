#include <iostream>

Node* MergeLists(Node* headA, Node* headB){
	Node* merge = new Node();
	Node* tempA = headA;
	Node* tempB = headB;

	if (tempA==NULL){		return headB;	}
	else if (tempB==NULL){	return headA;	}
	else if (tempA==NULL &&
			 tempB==NULL){	return NULL;	}

	while(tempA!=NULL || tempB!=NULL){
		if (tempB!=NULL && tempA!=NULL){
			if (tempA->data <= tempB->data){ //El mas chico está en A.
				merge->next = tempA;
				//merge = tempA;
				tempA = headA->next;
			}else{				//El mas chico esta en B
				merge->next = tempB;
				//merge = tempB;
				tempB = headB->next;
			}
		}else if(tempA==NULL){ //La lista A acabó antes de la B 
			merge->next = tempB;
			tempB = headB->next;
		}else if(tempB==NULL){	//La lista B se acabó antes de la A
			merge->next = tempA;
			tempA = headA->next;
		}
	}
	merge-next = NULL;
	return merge;  
}
