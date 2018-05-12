Node* Delete(Node* head, int position){
	Node* flag = head;

	if (position==0){
		head = flag->next;
		free(flag);
		return head;
	}
		
	for (int i = 0; i < position-1; i++)
		flag = flag->next;
	
	Node* flag2 = flag->next;
	flag->next = flag2->next;

	free(flag2);
	return head;
}