#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <string>

void sortByInitial();
int chooseSortOrder();
TreeMap<char, BinaryTree<string>> readFile();
void printKeys(BinaryTree<char> tree, int sort);
void printAll(BinaryTree<Entity<char, BinaryTree<string>>> tree, int sort);