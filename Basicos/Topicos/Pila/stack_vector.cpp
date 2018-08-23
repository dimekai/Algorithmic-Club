
template<class T> struct stack{
	vector<T> items;
	int head;

	stack(){
		head=0;
		items = vector<T>(1);
	}

	void push(T val){
		if(head==items.size()){
			vecto<T> replacement(2*items.size());
			for (int i = 0; i < head; ++i)
				replacement[i] = items[i];
			items = replacement;	
		}
		items[head++] = val;
	}

	void pop(){
		if (head==0){
			throw runtime_error("--");
		}
		if (head <= items.size()/4){
			vector<T> replacement(items.size()/2);
			for (int i = 0; i < head; i++)
				replacement[i] = items[i];
			items = replacement;
		}
		head--;
	}

	T top(){
		if (head==0){
			throw
		}
		return items[head-1];
	}

	bool empty(){
		return head==0;
	}
};