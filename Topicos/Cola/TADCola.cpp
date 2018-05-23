template<class T> struct Queu{
	struct Nodo{
		Node* next;
		T data;

		Node(T val){
			next = NULL;
			data = val;
		}
	};//cierra el nodo.

	Node* head;
	Node* tail;
	int size = 0;
	
	Queue(){
		head = tail = NULL;
		size = 0;
	}

	bool empty(){
		return (size==0);
	}

	T front(){
		if (size==0){
			throw runtime_error("queu is empty");
		}else
			return head->data;
	}

	void push(T data){
		Node* tmp = new Node(data);
		tmp->next = tail;
		tail = tmp;
		size++;
	}

	void pop(){
		if (size==0){
			throw runtime_error("stack is empty");
		else if(size==1)
			head = tail = NULL;
		else{
			Node* tmp = tail;
			while(tmp->next->next){
				tmp = tmp->next;
			}
			tmp->next = NULL;
		}
		size--;
	}

};//cierra estructura cola Queue