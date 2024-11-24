#pragma once
#include <iostream>

using namespace std;
template <typename K, typename V>
class Entity
{
	K key;
	V value;

public:
	Entity();
	Entity(K k);
	Entity(K k, V v);
	K getKey();
	V getValue();
	void setKey(K k);
	void setValue(V v);

	bool operator== (Entity<K, V>& other);
	bool operator> (Entity<K, V>& other);
	bool operator< (Entity<K, V>& other);
};

template <typename K, typename V>
Entity<K, V>::Entity()
{
	this->key = K();
	this->value = V();
}

template <typename K, typename V>
Entity<K, V>::Entity(K k)
{
	this->key = k;
	this->value = V();
}

template <typename K, typename V>
Entity<K, V>::Entity(K k, V v)
{
	this->key = k;
	this->value = v;
}

template <typename K, typename V>
K Entity<K, V>::getKey()
{
	return this->key;
}
template <typename K, typename V>
V Entity<K, V>::getValue()
{
	return this->value;
}

template <typename K, typename V>
void Entity<K, V>::setKey(K k)
{
	this->key = k;
}
template <typename K, typename V>
void Entity<K, V>::setValue(V v)
{
	this->value = v;
}

template <typename K, typename V>
bool Entity<K, V>::operator== (Entity<K, V>& other)
{
	return (this->key == other.getKey());
}
template <typename K, typename V>
bool Entity<K, V>::operator> (Entity<K, V>& other)
{
	return (this->key > other.getKey());
}
template <typename K, typename V>
bool Entity<K, V>::operator< (Entity<K, V>& other)
{
	return (this->key < other.getKey());
}