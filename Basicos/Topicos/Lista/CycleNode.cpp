bool has_cycle(Node* head) {
	if (!head)
		return false;

	Node* flag = head;
	Node* flag2 = head->next;
	Node* aux = NULL;
    
    while(flag && flag2 && flag2->next){
    	if (flag == flag2)
    		return true;
    	
    	flag = flag->next;
    	aux = flag2->next;
    	flag2 = aux->next;
    }
    return false;
}