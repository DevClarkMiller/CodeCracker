#include "CrackerFunctions.hpp"

void setPercents(string& s, map<char, double>& map) {
	counter total = 0;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] != ' ' && s[i] != '\n' && s[i] != ',' && s[i] != '.' && s[i] != '-' && s[i] != ':' && s[i] != ';') {
			map[s[i]]++;
			total++;
		}
	}

	std::map<char, double>::iterator it;
	for (it = map.begin(); it != map.end(); it++) {
		it->second = (it->second / total) * 100;
	}
}

void printMap(map<char, double>& map) {
	for (auto const& pair : map) {
		cout << fixed << setprecision(1);
		cout << pair.first << " Frequency: " << pair.second << endl;
	}
}

void replaceChar(string& s, char replacing, char sub) {
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == replacing) {
			s[i] = sub;
		}
	}
}

void setNewlines(string& s) {
	for (size_t i = s.size(); i > 0; i--) {
		if (s[i - 1] == '.') {
			s.insert(i, 1, '\n');
		}
	}
}

void combineStrings(string& original, string& updated, string& copy) {
	for (size_t i = 0; i < original.length(); i++) {
		if (copy[i] != original[i]) {
			updated[i] = copy[i];
		}
	}
}