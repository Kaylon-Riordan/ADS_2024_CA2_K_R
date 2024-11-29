#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>

void sortByInitial();
TreeMap<char, string> readFile();
void printKeys(BinaryTree<char> tree);
void printAll(BinaryTree<Entity<char, string>> tree);