#ifndef _FIBONACCI_HEAP_H
#define _FIBONACCI_HEAP_H

#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <limits>
#include <cmath>

using std::cout;
using std::cerr;
using std::endl;

typedef struct node Node;

struct node	{
	long data;
	int verID;
	int degree;
	bool childCut;
	Node *parent;
	Node *child;
	Node *lsibling;
	Node *rsibling;

	node () : data (0), verID(-1), degree (0), childCut(false), parent (nullptr), child (nullptr), lsibling (nullptr), rsibling(nullptr) {}	
	~node () {
		parent = child = lsibling = rsibling = nullptr;
	}
};

class FibonacciHeap {
private:	
	Node *minNode;
	int numItem;
	
	void list_remove(Node *eraseMe);
	void list_insert(Node *firstListNode, Node *secondListNode);
	void meld_list (Node *firstListNode, Node *secondListNode);
	void cut_subtree (Node *rootIn);
	void cascading_cut (Node *beginNode);
	void find_next_min();
	Node* join_min_trees (Node * root1, Node * root2);
	void pairwise_combine ();
	
public:
	// Node *minNode;
	FibonacciHeap ();

	~FibonacciHeap ();

	Node* insert (long item, int verID);

	int remove_min (int &verID);

	void remove (Node *removeMe);

	void meld (FibonacciHeap &heap);

	void decrease_key (Node *decreaseMe, long newData);

	int size();
	void print();
};


#endif