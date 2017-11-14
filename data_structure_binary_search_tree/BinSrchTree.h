#pragma once
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public :
	BinSrchTree(void) {}
	BinSrchTree(void) {}

	//이진 탐색 트리의 탐색 연산
	void remove(BinaryNode *parent, BinaryNode *node) {
		//case 1: 삭제하려는 노드가 단말 노드 일 경우
		if (node->isLeaf()) {
			if (parent == NULL)
				root = NULL;
			else {
				if (parent == NULL)
					root = NULL;
				else {
					if (parent->getLeft() == node)
						parent->setLeft(NULL);
					else
						parent->setRight(NULL);
				}
			}
		}
			//case2:삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			//삭제할 노드의 유일한 자식 노드 =>child
			BinaryNode *child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight;//삭제할 노드가 루트이면 ==>chlid가 새로운 root가 됨
			if (node == root)root = child;
			//아니면==> 부모 노드의 자식으로 자식 노드 chlid를 직접 연결
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		else {
			//삭제하려는 노드가 두개의 자식이 모두 있는 경우
			//succ==>후계 노드: 오른쪽 서브 트리에서 가장 key가 작은 노드
			//succp => 후계 노드의 부모 노드
			BinaryNode* succp = node;
			BinaryNode*succ = node->getRight();
			while (succ->getLeft() != NULL) {//후계 노드 탐색
				succp = succ;
				succ = succ->getLeft();
			}
			//후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());

			node = succ;
		}
		delete node;
	}
	//이진 탐색 트리의 삽입 연산

	//이진 탐색 트리의 삭제 연산

	BinaryNode* searchRecur(BinaryNode* n, int key) {//키 값으로 노드를 탐색하는 함수 (순환적인 함수)
		//일반 함수로 구현(BinSrchTree의 멤버함수로 넣어도됨)
		if (n == NULL)return NULL;//n이 NULL
		if (key == n->getData())//getData()는 현재 노드
			return n;
		else if (key < n->getData())
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}

	BinaryNode* searchIter(BinaryNode* n, int key) {//키 값으로 노드를 탐색하는 함수 (반복적인 함수)
													 //일반 함수로 구현(BinSrchTree의 멤버함수로 넣어도됨)
		while (n != NULL) {
			if (n == NULL)return NULL;//n이 NULL
			if (key == n->getData())//getData()는 현재 노드
				return n;
			else if (key < n->getData())
				n = n->getLeft();//n=node->getLeft(); 오타인가?
			else
				return n->getRight();//n=node->getRight(); 오타인가?
		}
		return NULL;
		}

	BinaryNode*  BinaryNode::search(int key) {//키 값으로 노드를 탐색하는 함수 (순환적인 함수)
										 // 노드 클래스의 멤버로 구현 (일반 함수가 아님)
		if (key == data)//data는 현재노드의 data
			return this;
		else if (key < data&&left != NULL)
			return left->search(key);
		else if (key < data&&right != NULL)
			return right->search(key);
		else
			return NULL;
	}
	void insertRecur(BinaryNode* r, BinaryNode* n) {//이진 탐색 트리 삽입 함수 (순환적인 함수)
													//일반 함수로 구현(BinSrchTree의 멤버함수로 넣어도됨)
		if (n->getData() == r->getData())
			return;
		else if (n->getData() < r->getData()) {
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else
				insertRecur(r->getLeft(), n);
		}
		else {
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insertRecur(r->getRight(), n);
		}
	}
};