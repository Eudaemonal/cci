#ifndef RBTREE_H
#define RBTREE_H


#include <assert>
#include <string>


template <typename T>
class RBTree{
public:

	
private:
	class RBTreeNode{
	public:
		enum Color{
			RED = 0,
			BLACK = 1,
		};

		enum Side{
			LEFT = 0,
			RIGHT = 1,
		};

		RBTreeNode(long long k, T *o, RBTree *t) :
			obj(o), key(k), color(RED), parent(NULL), tree(t)
		{
			this->link[LEFT] = RBTree<T>::nil;
			this->link[RIGHT] = RBTree<T>::nil;	
		}

	private:
		T *obj;
		long long key;
		Color color;
		RBTreeNode *parent, *link[2];
		RBTree *tree;

	} *root;
};




#endif RBTREE_H
