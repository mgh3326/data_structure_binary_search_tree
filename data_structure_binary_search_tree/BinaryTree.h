#pragma once
#include "BinaryNode.h"
#include "CircularQueue.h"//교재에는 추가 하라는 말이 없는데 추가 시키네
class BinaryTree
{
	
public:
	BinaryNode* root;//BinSrchTree.h에서 사용하기 위해 public으로 가져옴
	BinaryTree() : root(NULL) {}
	void setRoot(BinaryNode* node) { root = node; }
	BinaryNode* getRoot() { return root; }
	bool isEmpty() { return root == NULL; }

	//이진트리의 inoder 순회 연산
	void inorder() { printf("\n   inorder: "); inorder(root); }
	void inorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			if (node->getLeft() != NULL)inorder(node->getLeft());
			printf(" [%c] ", node->getData());
			if (node->getRight() != NULL)inorder(node->getRight());
		}
	}
	//이진 트리의 preorder 순회 연산
	void preorder() { printf("\n  preorder: "); preorder(root); }
	void preorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			printf(" [%c] ", node->getData());
			if (node->getLeft() != NULL)preorder(node->getLeft());
			if (node->getRight() != NULL)preorder(node->getRight());
		}
	}
	//이진 트리의 postorder 순회 연산
	void postorder() { printf("\n postorder: "); postorder(root); }
	void postorder(BinaryNode *node) {//순환적인 트리의 순회함수
		if (node != NULL) {
			if (node->getLeft() != NULL)postorder(node->getLeft());
			if (node->getRight() != NULL)postorder(node->getRight());
			printf(" [%c] ", node->getData());

		}
	}
	void levelorder() {
		printf("\n levelorder: ");
		if (!isEmpty()) {
			CircularQueue q;
			q.enqueue(root);
			while (!q.isEmpty()) {
				BinaryNode* n = q.dequeue();
				if (n != NULL) {
					printf("[%c]  ", n->getData());
					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());
				}
			}
			printf("\n");
		}
	}
	//이진트리의 추가연산
	int getCount() {
		return isEmpty() ? 0 : getCount(root);
	}
	int getCount(BinaryNode* node) {
		if (node == NULL)return 0;
		return 1 + getCount(node->getLeft()) + getCount(node->getRight());
	}
	int getLeafCount() {
		return isEmpty() ? 0 : getLeafCount(root);
	}
	int getLeafCount(BinaryNode* node) {
		if (node == NULL)return 0;
		if (node->isLeaf())return 1;
		else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
	}
	int getHeight() {
		return isEmpty() ? 0 : getHeight(root);
	}
	int getHeight(BinaryNode* node) {
		if (node == NULL)return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return(hLeft > hRight) ? hLeft + 1 : hRight + 1;
	}
	int evaluate() { return evaluate(root); }
	int evaluate(BinaryNode *node) {
		if (node == NULL)return 0;
		if (node->isLeaf())return node->getData();
		else {
			int op1 = evaluate(node->getLeft());
			int op2 = evaluate(node->getRight());
			switch (node->getData()) {
			case'+':return op1 + op2;
			case'-':return op1 - op2;
			case'*':return op1 * op2;
			case'/':return op1 / op2;

			}
			return 0;

		}
	}
	//디렉토리 용량 계산 함수
	int calcSize() { return calcSize(root); }
	//순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수
	int calcSize(BinaryNode *node) {
		if (node == NULL)return 0;
		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
	}
};