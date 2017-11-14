#pragma once
// BinaryNode.h: 이진트리를 위한 노드 클래스
#include <cstdio>

class BinaryNode {
protected:
	int data;
	BinaryNode* left;
	BinaryNode* right;
public:

	BinaryNode(int val = 0, BinaryNode* l = NULL, BinaryNode* r = NULL)
		: data(val), left(l), right(r) { }

	void		setData(int val) { data = val; }
	void		setLeft(BinaryNode* l) { left = l; }
	void		setRight(BinaryNode* r) { right = r; }
	int			getData() { return data; }
	BinaryNode*	getLeft() { return left; }
	BinaryNode*	getRight() { return right; }
	bool		isLeaf() { return !left && !right; }


	/*void		inOrder();
	void		preOrder();
	void		postOrder();
	int			getCount();
	int			getLeafCount();
	bool        find(BinaryNode* node);
	private:
	T			data;
	BinaryNode*	left;
	BinaryNode*	right;*/
};
//
//template<typename T>
//void BinaryNode<T>::inOrder()
//{
//	if (left) left->inOrder();
//	printf(" [%c] ", data);
//	if (right) right->inOrder();
//}
//
//template<typename T>
//void BinaryNode<T>::preOrder()
//{
//	printf(" [%c] ", data);
//	if (left) left->preOrder();
//	if (right) right->preOrder();
//}
//
//template<typename T>
//void BinaryNode<T>::postOrder()
//{
//	if (left) left->postOrder();
//	if (right) right->postOrder();
//	printf(" [%c] ", data);
//}
//
//template<typename T>
//inline int BinaryNode<T>::getCount()
//{
//	if (!this)
//		return 0;
//	else
//		return 1 + left->getCount() + right->getCount();
//}
//
//template<typename T>
//int BinaryNode<T>::getLeafCount()
//{
//	if (!this)
//		return 0;
//
//	if (isLeaf())
//		return 1;
//	else
//		return left->getLeafCount() + right->getLeafCount();
//}
//
//template<typename T>
//bool BinaryNode<T>::find(BinaryNode * node)
//{
//	if (!this)
//		return false;
//	if (this == node)
//		return true;
//	else
//		return false || left->find(node) || right->find(node);
//}
//};