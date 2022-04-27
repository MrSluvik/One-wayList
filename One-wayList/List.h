#pragma once
template <typename T>
class List
{
private:
	template <typename T>
	class Node {
	public:
		Node* nextNode;
		T data;
		Node(T data, Node* nextNode = nullptr) {
			this->data = data;
			this->nextNode = nextNode;
		}
	};

	Node<T>* head;
	int size;
public:
	List(void);
	~List(void);
	void pushBack(T data);
	void pop_front();
	void clear();
	int getSize() { return size; }
	T& operator[](const int index);
	void pushFront(T data);
	void removeAt(int index);
	void popBack();
	void insert(T data, int index);
	int list_count(T x);
};

template<typename T>
inline List<T>::List(void)
{
	head = nullptr;
	size = 0;
}

template<typename T>
inline List<T>::~List(void)
{
	clear();
}

template<typename T>
inline void List<T>::pushBack(T data)
{
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* temp = this->head;
		while (temp->nextNode != nullptr) {
			temp = temp->nextNode;
		}
		temp->nextNode = new Node<T>(data);
	}
	size++;
}

template<typename T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->nextNode;
	delete temp;
	size--;
}

template<typename T>
inline void List<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	Node<T>* temp = this->head;
	int count = 0;	
	while (temp != nullptr) {
		if (count == index) {
			return temp->data;
		}
		temp = temp->nextNode;
		count++;
	}
	
}

template<typename T>
inline void List<T>::pushFront(T data)
{	head=new Node<T>(data,head);
	size++;
}

template<typename T>
inline void List<T>::removeAt(int index) 
{
	if (index == 0) 
	{
		pop_front();//видалення першого елемента
	}
	else
	{
		Node<T>* temp = this->head;
		for (int i = 0; i < index-1; i++)
		{
			temp = temp->nextNode;
		}
		Node<T>*deleteMe= temp->nextNode;
		temp->nextNode = deleteMe->nextNode;
		delete deleteMe;
		size--;
	}


}

template<typename T>
inline void List<T>::popBack()
{
	removeAt(size - 1);
}

template<typename T>
inline void List<T>::insert(T data, int index) 
{
	if (index == 0)
	{
		pushFront(data);
	}
	else
	{
		Node<T>* temp = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->nextNode;
		}
		Node<T>* pushMe = new Node<T>(data,temp->nextNode);
		temp->nextNode = pushMe;
		size++;
	}
}

template<typename T>
inline int List<T>::list_count(T x) {
	Node<T>* temp = this->head;
	int count = 0;	
	while (temp != nullptr) {		
			if (temp->data == x) 
			{ 
				count++;
			}		
		temp = temp->nextNode;
	}
	return count;
}



