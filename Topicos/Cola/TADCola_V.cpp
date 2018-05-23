template<calss T> struct PQueu{
	
	vector<T> tree;
	int size;

	PQ(){
		tree = vector<T>(5);
		size = 0;
	}

	void swim(int pos){ /*Insertamos y sube si es necesario*/
		int k = pos;
		while(k/2 > 0 && tree[k/2] < tree[k]){
			swap(tree[k/2],tree[k]);
			k /= 2;   /* k = k/2 */
		}
	}

	void push(T val){
		if (size==tree.size()-1)
			resize(2*size+1);
		tree[++size] = val;
		swap(size);
	}

	T top(){
		if (size==0)
			throw runtime_error("PQueu is empty");
		return tree[1];
	}

	void sink(int pos){
		int k = pos;
		while(tree){
			if(2*k){
				/* code */
			}
		}
	}
};//cierra cola de prioridad