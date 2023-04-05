/********************************************************************/
/*                                                                  */
/*  A1 Part 2: DList starter file                                   */
/*                                                                  */
/*  Author1 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*  Author2 Name: <name here>                                       */
/*      - class/function list/main author or main checker           */
/*                                                                  */
/********************************************************************/

#include<iostream>
template <typename T>
class DList {
	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {
			data_ = data;
			next_ = next;
			prev_ = prev;
		}
	};

	Node* front_;
	Node* back_;
	int size_;
public:
	class const_iterator {
		friend class DList;
	protected:
		Node* curr_;
	public:
		// constructor for const_iterator
		const_iterator() {
			curr_ = nullptr;
		}
		// constructor for const_iterator
		// receives a reference to the node as its parameter
		const_iterator(Node* n) {
			curr_ = n;
		}
		// prefix ++ operator
		// makes constant iterator point to the next node in the list.
		// return a current object
		const_iterator& operator++() {
			curr_ = curr_->next_;
			return *this;
		}
		// postfix ++ operator
		// makes iterator point to the next node in the list.
		// return an node referred by constant it
		const_iterator operator++(int) {
			const_iterator temp = *this;
			curr_ = curr_->next_;
			return temp;
		}

		// prefix -- operator
		// makes const iterator point to the previous node in the list
		// return a current object
		const_iterator& operator--() {
			if (curr_)
				curr_ = curr_->prev_;
			return *this;
		}

		// postfix -- operator
		// makes const iterator point to the previous node in the list
		// return a node referred by constant it
		const_iterator operator--(int) {
			const_iterator ret = *this;
			if (curr_)
				curr_ = curr_->prev_;
			return ret;
		}

		// == operator is used for making comparision between the two constant iterator
		// return true or false depending on they are pointing to the same address or not
		bool operator==(const_iterator rhs) {
			return curr_ == rhs.curr_;
		}


		// != operator is used for making comparision between the two constant iterator
		// return true or false depending on they are pointing to the same address or not
		bool operator!=(const_iterator rhs) {
			return curr_ != rhs.curr_;
		}


		const T& operator*()const {
			return curr_->data_;
		}

		// postfix *( operator is used for makeingg it to multiply with the data
		// returns the result after calculation
		T& operator*() {
			return this->curr_->data_;
		}
	};
	class iterator :public const_iterator {
	public:
		// constructors, returns iterators to nullptrs
		iterator() :const_iterator() {};
		iterator(Node* n) :const_iterator(n) {}

		// prefix ++ operator
		// makes constant iterator point to the next node in the list.
		// return a current object
		iterator& operator++() {
			const_iterator::curr_ = const_iterator::curr_->next_;
			return *this;
		}

		// prefix ++ operator
		// makes iterator point to the next node in the list.
		// return an node referred by it
		iterator operator++(int) {
			iterator temp = *this;
			const_iterator::curr_ = const_iterator::curr_->next_;
			return temp;
		}

		// postfix -- operator
		// makes iterator point to the previous node in the list.
		// return the current state of the object
		iterator& operator--() {
			if (this->curr_)
				this->curr_ = this->curr_->prev_;
			return *this;
		}

		// postfix -- operator
		// makes iterator point to the previous node in the list.
		// return the node referred by it
		iterator operator--(int) {
			iterator ret = *this;
			if (this->curr_)
				this->curr_ = this->curr_->prev_;
			return ret;
		}

		// postfix *( operator is used for makeingg it to multiply with the data
		// returns the result after calculation
		T& operator*() {
			return this->curr_->data_;
		}

		// postfix *( operator is used for makeingg it to multiply with the data
		// returns the constant result after calculation
		const T& operator*()const {
			return this->curr_->data_;
		}


	};
	// default constructor - used for creating an empty DList. Accept no arguments and returns nothing
	DList();

	// destructor - used for deallocating old nodes, Accept no arguments and returns nothing.
	~DList();

	// copy constructor - used for initializing an object using another object of the same class.
	// Accept a reference as its parameter
	// returns nothing
	DList(const DList& rhs);

	// copy constructor - used for initializing an object using another object of the same class.
	// Accept a reference as its parameter
	// returns a reference to a current object
	DList& operator=(const DList& rhs);

	// move constructor - used for moving resources owned by rhs object to be momved into the current object without creating any copies.
	// Accept rvalue reference as its parameter
	// returns nothing
	DList(DList&& rhs);

	// move assignment - used for moving resources owned by rhs object to be momved into the current object without creating any copies.
	// Accept rvalue reference as its parameter
	// return a reference to the current object 
	DList& operator=(DList&& rhs);

	//adds new node containing data before the node refer to by it
	// accept an ierator and a reference to the data as its parameters
	//function returns iterator to newly added node
	iterator insert(iterator it, const T& data);

	//search a node containing data before the node refer to by it
	// accept an iteratoras its parameters
	//function returns iterator to the searched node
	iterator search(const T& data);

	// this function is used for erase a node referred to by it
	// removes the node referred to by it
	// returns iterator to node that follows the node that was removed
	iterator erase(iterator it);

	// this function is used for sort between the nodes
	// receive the node referred to by iterator first and last
	// returns nothing
	void sort(iterator first, iterator last);

	//function returns true if the list is empty, false otherwise
	bool empty() const;

	//function returns number of pieces of data stored in the list
	int size() const;

	// this function is used for swap the nodes including the link between them
	// receive the reference to two swapped nodes
	// return nothing
	void swapNode(Node* n1, Node* n2);

	// this function is used for helping sort to track and restrict the traversing between the first and last nodes (aka in the middle of the list)
	// receive iterator first and last as its parameters
	//return the number of nodes between the first to last(but not including last)
	int getDistance(iterator first, iterator last);


	// returns iterator to Node containing the first piece of data in the linked list
	iterator begin() {
		return iterator(front_->next_);
	}


	iterator end() {
		return iterator(back_);
	}

	//returns const_iterator to to Node containing the first piece of data in the linked list
	const_iterator cbegin() const {
		if (this->front_ != nullptr) {
			return const_iterator(front_->next_);

		}
	}

	// returns const_iterator to the Node after the node containing the last piece of data of the linked list
	const_iterator cend() const {
		return const_iterator(back_);
	}

	void erase(iterator first, iterator last) {
		Node* prev = first.curr_->prev_;
		while (first != last && first != end()) {
			++first;
			delete first.curr_->prev_;
			--size_;
		}
		Node* next = (first == last ? last.curr_ : back_);
		prev->next_ = next;
		next->prev_ = prev;
	}
	void push_back(const T& data) {
		back_->prev_ = back_->prev_->next_ = new Node(data, back_, back_->prev_);
		++size_;
	}

};

template <typename T>
DList<T>::DList() {
	back_ = new Node();
	front_ = new Node(T{}, back_);
	size_ = 0;
	back_->prev_ = front_;
}
template <typename T>
DList<T>::~DList() {
	Node* current = front_;

	while (current != back_)
	{
		if (this->front_ != nullptr) {
			front_ = front_->next_;
			delete current;
			current = front_;

		}

	}
}
template <typename T>
DList<T>::DList(const DList& rhs) {
	DList();
	for (const_iterator itor = rhs.front_; itor != nullptr; itor++) {
		// push_back
		Node* nn = new Node(*itor, nullptr, back_);

		if (back_) {
			back_->next_ = nn;
		}
		else {
			front_ = nn;
		}
		back_ = nn;

		++size_;
	}
	size_ -= 2;

}
template <typename T>
DList<T>& DList<T>::operator=(const DList& rhs) {
	erase(begin(), end());

	for (const_iterator itor = rhs.cbegin(); itor != rhs.cend(); itor++) {
		push_back(*itor);
	}

	return *this;
}
template <typename T>
DList<T>::DList(DList&& rhs) {
	/*DList();
	if (this->front_ != nullptr) {
		front_->next_ = rhs.front_->next_;
	}
	if (this->back_ != nullptr) {
		back_->prev_ = rhs.back_->prev_;
	}
	rhs.front_->next_ = rhs.back_->prev_ = nullptr;*/

	DList();
	for (const_iterator itor = rhs.front_; itor != nullptr; itor++) {
		// push_back
		Node* nn = new Node(*itor, nullptr, back_);

		if (back_) {
			back_->next_ = nn;
		}
		else {
			front_ = nn;
		}
		back_ = nn;

		++size_;
	}
	size_ -= 2;
}

template <typename T>
DList<T>& DList<T>::operator=(DList&& rhs) {

	erase(begin(), end());


	for (const_iterator itor = rhs.cbegin(); itor != rhs.cend(); itor++) {
		push_back(*itor);
	}

	return *this;
}


template <typename T>
typename DList<T>::iterator DList<T>::insert(iterator it, const T& data) {
	if (it.curr_) {
		it.curr_->prev_ = it.curr_->prev_->next_ = new Node(data, it.curr_, it.curr_->prev_);
		++size_;
	}
	return --it;
}

template <typename T>
typename DList<T>::iterator DList<T>::search(const T& data) {
	for (iterator itor = begin(); itor != end(); itor++) {
		if (*itor == data) {
			return itor;
		}
	}
	return end();
}


template <typename T>
typename DList<T>::iterator DList<T>::erase(iterator it) {
	if (it.curr_ && it != end()) {
		it.curr_->next_->prev_ = it.curr_->prev_;
		it.curr_->prev_->next_ = it.curr_->next_;
		//delete it.curr_;
		--size_;
	}
	return it.curr_->next_;
}

template <typename T>
void DList<T>::sort(iterator first, iterator last) {
	// find the length of first and last to traverse backward later
	int countSize = getDistance(first, last);
	if (countSize != size()) {
		// avoid the last node
		last = last.curr_->prev_;
		countSize--;
	}
	// if only sort 1 node
	if (countSize == 0) return;

	int counterOut = 0;
	bool continued = true;
	int count = 0;
	bool isLast = false;

	iterator start = first; // start to traverse the outer loop
	iterator head = first; // head of the first sorted Node
	iterator i;
	while (continued) {
		int counter = 0;
		for (i = head; counter < countSize; i++) {
			Node* leftN = i.curr_;
			Node* rightN = i.curr_->next_;

			if (rightN->data_ < leftN->data_ && rightN->next_ != nullptr) {
				// swapNode
				swapNode(rightN, leftN);

				// after swapping, setting i = new swapped node
				i.curr_ = rightN;
			}
			// keep track of the length of sorted nodes to make sure it wont sort redundant nodes
			counter++;

		}
		if (start.curr_ != nullptr) {
			start = start.curr_->next_;

		}
		// get the head of the sorted Nodes
		iterator temp = i;
		int distance = 0;
		while (distance < countSize) {
			temp--;
			distance++;
		}
		head = temp;
		counterOut++;

		// set flag to go to the outer loop
		if (countSize == size() && start == last || countSize != size() && counterOut == countSize - 1) {
			continued = false;
		}

	}

}
template <typename T>
bool DList<T>::empty() const {
	return front_->next_ == back_;
}
template <typename T>
int DList<T>::size() const {
	return size_;
}

template <typename T>
void DList<T>::swapNode(Node* n1, Node* n2) {
	n1->next_->prev_ = n2;
	n2->prev_->next_ = n1;
	n2->next_ = n1->next_;
	n1->prev_ = n2->prev_;
	n2->prev_ = n1;
	n1->next_ = n2;
}

template <typename T>
int DList<T>::getDistance(iterator first, iterator last) {
	int count = 0;
	while (first != last) {
		count++;
		first = first.curr_->next_;
	}
	return count;
}

