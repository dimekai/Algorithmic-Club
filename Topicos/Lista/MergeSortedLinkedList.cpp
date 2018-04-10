Node* MergeLists(Node* headA, Node* headB){
	Node* merge = new Node();
	Node* tempA = headA;
	Node* tempB = headB;

	if (tempA==NULL){		return headB;	}
	else if (tempB==NULL){	return headA;	}
	else if (tempA==NULL &&
			 tempB==NULL){	return NULL;	}

	/*Veo en qué lista está el dato más pequeño*/
	if (tempA->data <= tempB->data){
		merge = tempA;
		tempA = tempA->next;
	}else{
		merge = tempB;
		tempB = tempB->next;
	}

	Node* head = merge; /*Establezco la lista donde esta
							el dato más chico: head*/

	while(tempA!=NULL && tempB!=NULL){
		if (tempA->data <= tempB->data){
			merge->next = tempA;
			tempA = tempA->next;
		}else{
			merge->next = tempB;
			tempB = tempB->next;
		}
		merge = merge->next; 
	}/*cierra while: termina de recorrer las listas
	   o alguna de ellas, A o B, terminó antes*/

	if (tempB!=NULL){ /*La lista A terminó antes de B*/
		merge->next = tempB;
	}
	if (tempA!=NULL){/*La lista B terminó antes de A*/
		merge->next = tempA;
	}
	return head;
}
