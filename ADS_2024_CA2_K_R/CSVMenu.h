#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

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

TreeMap<string, int> chooseIndexField(TreeMap<string, carDetails> tree);
TreeMap<string, carDetails> chooseFilterField(TreeMap<string, carDetails> tree);

void indexNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, int>& tree, int field);
void filterNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, carDetails>& tree, int field, string input);

TreeMap<string, carDetails> readCSVFile();

void printTree(BSTNode<Entity<string, carDetails>>* root);
void printTreeIndex(BSTNode<Entity<string, int>>* root);