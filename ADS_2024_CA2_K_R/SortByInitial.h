#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <string>

void sortByInitial();
TreeMap<char, BinaryTree<string>> readFile();
void printKeys(BinaryTree<char> tree);
void printAll(BinaryTree<Entity<char, BinaryTree<string>>> tree);