/*
 * list.h
 *
 *  Created on: Apr 15, 2014
 *      Author: Kainan Wang
 */

#ifndef LIST_H_
#define LIST_H_

namespace test
{

#ifndef NULL
#define NULL 0
#endif

template <class T>
class list {
public:
	class iterator;
	list();
	~list();
	int size() const;
	void push_front(const T &data);
	void push_back(const T &data);
	void pop_front();
	void pop_back();
	void sort();
	void sort(bool (*cmp)(const T &data1, const T &data2));
	iterator begin();
	iterator end();

private:
	// void quick_sort(Node *begin, Node *end, int state = 0);
	struct Node;
	void merge_sort(Node *left_begin, Node *right_end, int size);
	void merge_sort(Node *left_begin, Node *right_end, int size, bool (*cmp)(const T &data1, const T &data2));
	void insert_prev(Node *to, Node *from);
	void insert_next(Node *to, Node *from);
	void swap(Node *node1, Node *node2); // swap two nodes, not pointer.

public:
	class iterator
	{
	public:
		iterator(Node *pointer = NULL);
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(const iterator &it2) const;
		bool operator!=(const iterator &it2) const;
		T operator*() const;
	private:
		Node *pointer_;
	};
	
private:
	struct Node{
		Node(Node *prev = NULL, Node *next = NULL);
		Node(const T &data, Node *prev = NULL, Node *next = NULL);
		T data_;
		Node *prev_, *next_;
	};

	Node *head_, *tail_;
	int size_; 
};

}

#endif /* LIST_H_ */


