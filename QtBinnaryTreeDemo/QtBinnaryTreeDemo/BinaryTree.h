#pragma once
#ifndef __CUSTOM_BINARY_TREE__
#define __CUSTOM_BINARY_TREE__
#include <memory>
#include "StringSerialization.h"
using uint = unsigned int;
using namespace std;


template <typename T>
class BinarySearchTree {
protected:
	struct Node {
		uint LeftHeight;
		uint RightHeight;
		std::string name;
		T value;
		shared_ptr<Node> leftChild;
		shared_ptr<Node> rightChild;
		Node() :value(), name(), leftChild(), rightChild() { LeftHeight = 0; RightHeight = 0; }
		Node(T newValue, std::string nodeName) :value(newValue), name(nodeName), leftChild(), rightChild() { LeftHeight = 0; RightHeight = 0; }
	};

	shared_ptr<Node> root;
	string NameCode;
	uint TreeHeight;

	bool remove(const T& NodeValue, const string& name, std::shared_ptr<Node>& node);

	bool push(const T& nodeValue, shared_ptr<Node>& node, string& newNodeName);
	uint balanceTree(shared_ptr<Node>& node);
	string GenerateName();
	virtual string GetValue(const shared_ptr<Node>& node) {
		return toString<T>(node->value);
	}
	string serialize(const shared_ptr<Node>& node) const {
		if (node->leftChild && node->rightChild)
			return serialize(node->leftChild) + "<name " + node->name + "> <value " + toString<T>(node->value) + "> " + serialize(node->rightChild);
		else if (node->leftChild)
			return serialize(node->leftChild) + "<name " + node->name + "> <value " + toString<T>(node->value) + "> ";
		else if (node->rightChild)
			return "<name " + node->name + "> <value " + toString<T>(node->value) + "> " + serialize(node->rightChild);
		else return "<name " + node->name + "> <value " + toString<T>(node->value) + "> ";
	}
private:
	BinarySearchTree& operator =(const BinarySearchTree&) {}
public:
	BinarySearchTree(std::initializer_list<T> init) :root() {
		NameCode = "A";
		TreeHeight = 0;
		for (T element : init) {
			 this->push(element);
		}
	}
	 BinarySearchTree() :root() { NameCode = "A"; TreeHeight = 0; }
	~BinarySearchTree() {
		while (root) remove(root->value, root->name, root);
	}
	BinarySearchTree(BinarySearchTree&&) = default;
	BinarySearchTree& operator =(BinarySearchTree&&) = default;

	BinarySearchTree(const BinarySearchTree&) = delete;
	string serialize() {
		if (!root) return "";
		return serialize(root);

	}
	string push(const T& nodeValue) {
		string newNodeName;
		if (!root) {
			root = shared_ptr<Node>(new Node(nodeValue, newNodeName = GenerateName()));
			TreeHeight = 1;
		}
		else if (push(nodeValue, root, newNodeName)) {
			TreeHeight = balanceTree(root)+1;
		}
		return newNodeName;
	}

	bool remove(const T& nodeValue,const string& name) {
		bool result = remove(nodeValue, name, root);
		if (result) {
			TreeHeight = root->RightHeight > root->LeftHeight ? root->RightHeight : root->LeftHeight;
			balanceTree(root);
		}
		return result;
	}
	bool GetValueByPosition(string nodePosition, T& Data, string& name);
	uint GetTreeHeight() const {return TreeHeight;}
};


template<typename T>
string BinarySearchTree<T>::GenerateName()
{
	string newName = NameCode;
	int i = 0;
	for (; i< NameCode.size() && NameCode[i] == 'Z'; i++) 
			NameCode[i] = 'A';
	if (i==NameCode.size()) NameCode += 'A';
	else NameCode[i]++;
	return newName;
}

template<typename T>
bool BinarySearchTree<T>::GetValueByPosition(string nodeName, T& Data, string& name)
{	
	if (!root) return false;
	if (nodeName.size() < 1) return false;
	if (nodeName[0] != 'N') return false;
	if (nodeName.size() == 1) {
		Data = root->value;
		name = root->name;
		return true;
	}
	shared_ptr<Node> TempPtr = root;
	for (int i = 1; i < nodeName.size(); i++) {
		if (nodeName[i] == 'L') 
			if (TempPtr->leftChild) 
				TempPtr = TempPtr->leftChild;
			else return false;
		else if (nodeName[i] == 'R')
			if (TempPtr->rightChild) 
				TempPtr = TempPtr->rightChild;
			else return false;
		else return false;
	}
	name = TempPtr->name;
	Data = TempPtr->value;
	return true;
	
}

template<typename T>
bool BinarySearchTree<T>::remove(const T& NodeValue, const string& name, std::shared_ptr<Node>& node)
{
	bool result;
	if (!node) return false;

	if (NodeValue < node->value) {
		result = remove(NodeValue, name, node->leftChild);
		if (result){
			if (node->leftChild) node->LeftHeight = (node->leftChild->LeftHeight > node->leftChild->RightHeight? node->leftChild->LeftHeight: node->leftChild->RightHeight) + 1;
			else node->LeftHeight = 0;
		}
		return result;
	}
	if (NodeValue > node->value || (NodeValue == node->value && name!=node->name)) {
		result = remove(NodeValue, name, node->rightChild);
		if (result) {
			if (node->rightChild) node->RightHeight = (node->rightChild->LeftHeight > node->rightChild->RightHeight ? node->rightChild->LeftHeight : node->rightChild->RightHeight) + 1;
			else node->RightHeight = 0;
		}
		return result;
	}
	if (node->value == NodeValue && name==node->name) {
		if (!(node->leftChild)) {
			node = node->rightChild;
		}
		else if (!node->rightChild) {
			node = node->leftChild;
		}
		else {
			shared_ptr<Node> nodeBitSmallerThanNode = node->leftChild;
			while (nodeBitSmallerThanNode->rightChild) {
				nodeBitSmallerThanNode->RightHeight--;
				nodeBitSmallerThanNode = nodeBitSmallerThanNode->rightChild;
			}
			node->value = nodeBitSmallerThanNode->value;
			node->name = nodeBitSmallerThanNode->name;
			remove(nodeBitSmallerThanNode->value, nodeBitSmallerThanNode->name, node->leftChild);
			if (node->leftChild) node->LeftHeight = (node->leftChild->LeftHeight > node->leftChild->RightHeight ? node->leftChild->LeftHeight : node->leftChild->RightHeight) + 1;
			else node->LeftHeight = 0;
		}
		return true;
	}
	return false;
}template<typename T>
bool BinarySearchTree<T>::push(const T& nodeValue, shared_ptr<Node>& node, string& newNodeName)
{
	bool DoesHeightIncreased;
	if (node->value > nodeValue) {
		if (!node->leftChild) {
			node->leftChild = shared_ptr<Node>(new Node(nodeValue, newNodeName = GenerateName()));
			node->LeftHeight++;
			if (!node->rightChild) return true;
			else return false;
		}
		DoesHeightIncreased = push(nodeValue, node->leftChild, newNodeName);
		node->LeftHeight += DoesHeightIncreased;
		return DoesHeightIncreased;
	}
	else {
		if (!node->rightChild) {
			node->rightChild = shared_ptr<Node>(new Node(nodeValue, newNodeName = GenerateName()));
			node->RightHeight++;
			if (!node->leftChild) return true;
			else return false;
		}
		DoesHeightIncreased = push(nodeValue, node->rightChild, newNodeName);
		node->RightHeight += DoesHeightIncreased;
		return DoesHeightIncreased;
	}
}

template<typename T>
uint BinarySearchTree<T>::balanceTree(shared_ptr<Node>& node)
{	
	int balance = node->RightHeight - node->LeftHeight;
	if (balance == 0) return node->RightHeight;

	if (balance < 0){
		if (balance < -1) {
			shared_ptr<Node> TempNode = node->leftChild;
			node->leftChild = TempNode->rightChild;
			TempNode->rightChild = node;
			if (node->leftChild)
				node->LeftHeight = (node->leftChild->RightHeight > node->leftChild->LeftHeight ? node->leftChild->RightHeight : node->leftChild->LeftHeight) + 1;
			else node->LeftHeight = 0;
			node = TempNode;		
		}
	}
	else if (balance > 1) {
		shared_ptr<Node> TempNode = node->rightChild;
		node->rightChild = TempNode->leftChild;
		TempNode->leftChild = node;
		if (node->rightChild)
			node->RightHeight = (node->rightChild->LeftHeight > node->rightChild->RightHeight ? node->rightChild->LeftHeight : node->rightChild->RightHeight) + 1;
		else node->RightHeight = 0;
		node = TempNode;
	}
	if (node->leftChild) node->LeftHeight = balanceTree(node->leftChild) + 1;
	if (node->rightChild) node->RightHeight = balanceTree(node->rightChild) + 1;
	return (node->LeftHeight > node->RightHeight ? node->LeftHeight : node->RightHeight);
}
#endif // !__CUSTOM_BINARY_TREE__


