#pragma once
#include "TreeMap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Print.h"

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

TreeMap<string, carDetails> readCSVFile();