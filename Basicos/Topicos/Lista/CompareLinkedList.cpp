int CompareLists(Node* headA, Node* headB){
	if (!headA && !headB)	/*Los dos nodos son iguales porque son NULL*/
		return 0;

	if ( (!headA && headB) || (headB && !headA) ) /*Alguno de los dos es NULL*/
		return 0;
	
	while(headA && headB){
		if (headA->data == headB->data){
			headA = headA->next;
			headB = headB->next;

			if (!headA && headB)
				return 0;
			
			if (!headB && headA)
				return 0;
			
		}else return 0;
	}
    return 1;
}