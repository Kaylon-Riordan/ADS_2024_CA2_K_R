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
	
	void add(Entity<K, V>& entity);
	bool remove(Entity<K, V>& entity);
	void clear();
	int count();

	bool containsKey(K key);
	//V& get(K key);
	//BinaryTree<K> keySet();
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