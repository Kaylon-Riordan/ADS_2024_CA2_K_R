#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>

void sortByInitial();

void chooseTree(TreeMap<char, BinaryTree<string>> treeMap);
int chooseSortOrder();

TreeMap<char, BinaryTree<string>> readTXTFile();

template <class T>
void print(BinaryTree<T> tree, int sort);