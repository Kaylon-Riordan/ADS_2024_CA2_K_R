#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include "Print.h"

void sortByInitial();

void chooseTree(TreeMap<char, BinaryTree<string>> treeMap);

TreeMap<char, BinaryTree<string>> readTXTFile();