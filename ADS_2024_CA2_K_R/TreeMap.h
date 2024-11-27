#pragma once
#include "BinaryTree.h"
#include "Entity.h"

using namespace std;
template <typename K, typename V>
class TreeMap
{
	BinaryTree<Entity<K, V>> binaryTree;

public:
	TreeMap();

	BinaryTree<Entity<K, V>>& getBinaryTree();

	void put(K key, V value);
	bool removeKey(K key);
	void clear();
	int size();

	bool containsKey(K key);
	V& get(K key);

	BinaryTree<K> keySet();
	BSTNode<K>* keySetNode(const BSTNode<Entity<K, V>>* other);

	V& operator[](K key);
};

template <typename K, typename V>
TreeMap<K, V>::TreeMap()
{
	this->binaryTree = BinaryTree<Entity<K, V>>();
}

template <typename K, typename V>
BinaryTree<Entity<K, V>>& TreeMap<K, V>::getBinaryTree()
{
	return this->binaryTree;
}

template <typename K, typename V>
void TreeMap<K, V>::put(K key, V value)
{
	Entity<K, V> entity(key, value);
	if (containsKey(key))
	{
		this->binaryTree.get(entity).setValue(value);
	}
	else
	{
		this->binaryTree.add(entity);
	}
}
template <typename K, typename V>
bool TreeMap<K, V>::removeKey(K key)
{
	Entity<K, V> entity(key);
	return this->binaryTree.remove(entity);
}
template <typename K, typename V>
void TreeMap<K, V>::clear()
{
	this->binaryTree.clear();
}
template <typename K, typename V>
int TreeMap<K, V>::size()
{
	return this->binaryTree.count();
}

template <typename K, typename V>
bool TreeMap<K, V>::containsKey(K key)
{
	Entity<K, V> entity(key);

	try {
		this->binaryTree.get(entity);
	}
	catch (logic_error)
	{
		return false;
	}
	return true;
}
template <typename K, typename V>
V& TreeMap<K, V>::get(K key)
{
	Entity<K, V> entity(key);

	try
	{
		return this->binaryTree.get(entity).getValue();
	}
	catch (logic_error)
	{
		V notFound = V();
		return notFound;
	}
}

template <typename K, typename V>
BinaryTree<K> TreeMap<K, V>::keySet()
{
	BinaryTree<K> keyTree;
	BinaryTree<Entity<K, V>> otherTree = this->binaryTree;

	keyTree.root = nullptr;
	if (otherTree.root != nullptr)
	{
		keyTree.root = keySetNode(otherTree.root);
	}

	return keyTree;
}
template <typename K, typename V>
BSTNode<K>* TreeMap<K, V>::keySetNode(const BSTNode<Entity<K, V>>* other)
{
	BSTNode<Entity<K, V>> otherNode = *other;
	BSTNode<K>* keyNode = new BSTNode<K>(otherNode.getItem().getKey());

	keyNode->setLeft(nullptr);
	keyNode->setRight(nullptr);
	if (otherNode.getLeft() != nullptr)
	{
		keyNode->setLeft(keySetNode(otherNode.getLeft()));
	}
	if (otherNode.getRight() != nullptr)
	{
		keyNode->setRight(keySetNode(otherNode.getRight()));
	}

	return keyNode;
}

template <typename K, typename V>
V& TreeMap<K, V>::operator[](K key)
{
	Entity<K, V> entity(key);
	Entity<K, V>& nodeItem = this->binaryTree.get(entity);
	return nodeItem.getValue();
}