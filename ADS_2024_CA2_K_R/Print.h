#pragma once
#include "TreeMap.h"

class Print
{
public:
    template <class T>
    void operator () (BinaryTree<T> tree) const;
};

int chooseSortOrder();

template <class T>
void display(BinaryTree<T>, int sort);