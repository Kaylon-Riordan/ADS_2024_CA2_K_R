#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct carDetails {
	string make;
	string model;
	int year;
	string owner;
	friend std::ostream& operator<<(std::ostream& out, const carDetails& entity) {
		out << "[Make: " << entity.make << ", Model: " << entity.model << ", Year: " << entity.year << ", Owner: " << entity.owner << "]";
		return out;
	}
};

void sortByIndexOrFilter();

void chooseIndexOrFilter(TreeMap<string, carDetails> treeMap);
int chooseTreeSortOrder();

TreeMap<string, carDetails> chooseFilterField(TreeMap<string, carDetails> tree);
void filterNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, carDetails>& tree, int field, string input);

TreeMap<string, carDetails> readCSVFile();

void printTree(BinaryTree<Entity<string, carDetails>> tree, int sort);
template <class T>
void printIndex(BinaryTree<T> tree, int sort);