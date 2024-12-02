#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

// create a struct to hold the last 4 details of the cars csv, the id will be stored as the key of the entity
struct carDetails {
	string make;
	string model;
	int year;
	string owner;
};

void chooseIndexOrFilter();

TreeMap<string, int> chooseIndexField(TreeMap<string, carDetails> tree);
TreeMap<string, carDetails> chooseFilterField(TreeMap<string, carDetails> tree);

void indexNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, int>& tree, int field);
void filterNodes(BSTNode<Entity<string, carDetails>>* root, TreeMap<string, carDetails>& tree, int field, string input);

TreeMap<string, carDetails> readCSVFile();

void printTree(BSTNode<Entity<string, carDetails>>* root);
void printTreeIndex(BSTNode<Entity<string, int>>* root);