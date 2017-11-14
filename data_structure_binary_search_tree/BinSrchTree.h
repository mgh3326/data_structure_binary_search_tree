#pragma once
#include "BinaryTree.h"

class BinSrchTree : public BinaryTree
{
public :
	BinSrchTree(void) {}
	BinSrchTree(void) {}

	//���� Ž�� Ʈ���� Ž�� ����
	void remove(BinaryNode *parent, BinaryNode *node) {
		//case 1: �����Ϸ��� ��尡 �ܸ� ��� �� ���
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
			//case2:�����Ϸ��� ��尡 �����̳� ������ �ڽĸ� ���� ���
		else if (node->getLeft() == NULL || node->getRight() == NULL) {
			//������ ����� ������ �ڽ� ��� =>child
			BinaryNode *child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight;//������ ��尡 ��Ʈ�̸� ==>chlid�� ���ο� root�� ��
			if (node == root)root = child;
			//�ƴϸ�==> �θ� ����� �ڽ����� �ڽ� ��� chlid�� ���� ����
			else {
				if (parent->getLeft() == node)
					parent->setLeft(child);
				else
					parent->setRight(child);
			}
		}
		else {
			//�����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���
			//succ==>�İ� ���: ������ ���� Ʈ������ ���� key�� ���� ���
			//succp => �İ� ����� �θ� ���
			BinaryNode* succp = node;
			BinaryNode*succ = node->getRight();
			while (succ->getLeft() != NULL) {//�İ� ��� Ž��
				succp = succ;
				succ = succ->getLeft();
			}
			//�İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����
			if (succp->getLeft() == succ)
				succp->setLeft(succ->getRight());
			else
				succp->setRight(succ->getRight());

			node->setData(succ->getData());

			node = succ;
		}
		delete node;
	}
	//���� Ž�� Ʈ���� ���� ����

	//���� Ž�� Ʈ���� ���� ����

	BinaryNode* searchRecur(BinaryNode* n, int key) {//Ű ������ ��带 Ž���ϴ� �Լ� (��ȯ���� �Լ�)
		//�Ϲ� �Լ��� ����(BinSrchTree�� ����Լ��� �־��)
		if (n == NULL)return NULL;//n�� NULL
		if (key == n->getData())//getData()�� ���� ���
			return n;
		else if (key < n->getData())
			return searchRecur(n->getLeft(), key);
		else
			return searchRecur(n->getRight(), key);
	}

	BinaryNode* searchIter(BinaryNode* n, int key) {//Ű ������ ��带 Ž���ϴ� �Լ� (�ݺ����� �Լ�)
													 //�Ϲ� �Լ��� ����(BinSrchTree�� ����Լ��� �־��)
		while (n != NULL) {
			if (n == NULL)return NULL;//n�� NULL
			if (key == n->getData())//getData()�� ���� ���
				return n;
			else if (key < n->getData())
				n = n->getLeft();//n=node->getLeft(); ��Ÿ�ΰ�?
			else
				return n->getRight();//n=node->getRight(); ��Ÿ�ΰ�?
		}
		return NULL;
		}

	BinaryNode*  BinaryNode::search(int key) {//Ű ������ ��带 Ž���ϴ� �Լ� (��ȯ���� �Լ�)
										 // ��� Ŭ������ ����� ���� (�Ϲ� �Լ��� �ƴ�)
		if (key == data)//data�� �������� data
			return this;
		else if (key < data&&left != NULL)
			return left->search(key);
		else if (key < data&&right != NULL)
			return right->search(key);
		else
			return NULL;
	}
	void insertRecur(BinaryNode* r, BinaryNode* n) {//���� Ž�� Ʈ�� ���� �Լ� (��ȯ���� �Լ�)
													//�Ϲ� �Լ��� ����(BinSrchTree�� ����Լ��� �־��)
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