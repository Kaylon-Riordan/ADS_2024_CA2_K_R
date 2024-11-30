#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>

struct carDetails {
	string make;
	string model;
	int year;
	string owner;
};

void sortByIndexOrFilter();

TreeMap<string, carDetails> readCSVFile();