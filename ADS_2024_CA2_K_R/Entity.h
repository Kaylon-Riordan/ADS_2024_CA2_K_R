#pragma once
#include <iostream>

using namespace std;
template <typename K, typename V>
class Entity
{
	K key;
	V value;

public:
	Entity(K k, V v);
	K getKey();
	V getValue();
	void setKey(K k);
	void setValue(V v);

	friend bool operator== (const Entity& e1, const Entity& e2);
	friend bool operator!= (const Entity& e1, const Entity& e2);
	friend bool operator> (const Entity& e1, const Entity& e2);
	friend bool operator>= (const Entity& e1, const Entity& e2);
	friend bool operator< (const Entity& e1, const Entity& e2);
	friend bool operator<= (const Entity& e1, const Entity& e2);
};

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
bool operator== (const Entity<K, V>& e1, const Entity<K, V>& e2)
{return (e1.value == e2.value);}
template <typename K, typename V>
bool operator!= (const Entity<K, V>& e1, const Entity<K, V>& e2)
{ return (e1.value != e2.value); }
template <typename K, typename V>
bool operator> (const Entity<K, V>& e1, const Entity<K, V>& e2)
{ return (e1.value > e2.value); }
template <typename K, typename V>
bool operator>= (const Entity<K, V>& e1, const Entity<K, V>& e2)
{ return (e1.value >= e2.value); }
template <typename K, typename V>
bool operator< (const Entity<K, V>& e1, const Entity<K, V>& e2)
{ return (e1.value < e2.value); }
template <typename K, typename V>
bool operator<= (const Entity<K, V>& e1, const Entity<K, V>& e2)
{ return (e1.value <= e2.value); }

