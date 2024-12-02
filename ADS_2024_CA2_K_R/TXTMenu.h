#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>

void chooseTree();
int chooseSortOrder();

TreeMap<char, BinaryTree<string>> readTXTFile();

template <class T>
void print(BinaryTree<T> tree, int sort);