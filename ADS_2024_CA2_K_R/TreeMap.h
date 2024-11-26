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

	void add(Entity<K, V>& entity);
	bool remove(Entity<K, V>& entity);
	void clear();
	int count();

	bool containsKey(K key);
	V& get(K key);
	BinaryTree<K> keySet();
	BSTNode<K>* keySetNode(const BSTNode <Entity<K, V>>* other);
	//void put(K key, V value);
	//int size();
	//Bool removeKey(K key);
	//V& operator[K key];
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
void TreeMap<K, V>::add(Entity<K, V>& entity)
{
	this->binaryTree.add(entity);
}
template <typename K, typename V>
bool TreeMap<K, V>::remove(Entity<K, V>& entity)
{
	return this->binaryTree.remove(entity);
}
template <typename K, typename V>
void TreeMap<K, V>::clear()
{
	this->binaryTree.clear();
}
template <typename K, typename V>
int TreeMap<K, V>::count()
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

	if (this->binaryTree.root != nullptr)
	{
		keyTree.root = keySetNode(this->binaryTree.root);
	}

	return keyTree;
}
template <typename K, typename V>
BSTNode<K>* TreeMap<K, V>::keySetNode(const BSTNode< Entity<K, V>>* other)
{
	BSTNode<K> keyNode;
	BSTNode< Entity<K, V>> otherNodeData = *other;

	keyNode.setItem(otherNodeData.getItem().getKey());

	keyNode.setLeft(nullptr);
	keyNode.setRight(nullptr);
	if (otherNodeData.getLeft() != nullptr)
	{
		keyNode.setLeft(keySetNode(otherNodeData.getLeft()));
	}
	if (otherNodeData.getRight() != nullptr)
	{
		keyNode.setLeft(keySetNode(otherNodeData.getRight()));
	}
	return &keyNode;
}