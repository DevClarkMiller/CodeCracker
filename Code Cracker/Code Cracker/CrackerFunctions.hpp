#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>

typedef unsigned counter;
void setPercents(string& s, map<char, double>& map);
void printMap(map<char, double>& map);
void replaceChar(string& s, char replacing, char sub);
void setNewlines(string& s);
void combineStrings(string& original, string& updated, string& copy);