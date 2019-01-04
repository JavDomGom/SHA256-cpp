#include <iostream>
#include <sstream>
#include <vector>
#include "sha256.h"

using namespace std;

void printSplittedSHA256(string);
void printVector(vector<string>);

int main(int argc, char *argv[]) {
	string msg = argv[1];
	msg = "1 2 3";
	vector<string> leafNodeVector;
	vector<string> auxVector;
	istringstream buf(msg);

	for (string node; buf >> node;)
		leafNodeVector.push_back(node);

	int n = leafNodeVector.size();
	cout << "n = " << n << "\n" << endl;

	auxVector.push_back(leafNodeVector[0]+leafNodeVector[1]);
	auxVector.push_back(leafNodeVector[2]);

	printVector(leafNodeVector);
	cout << "\n" << endl;
	printVector(auxVector);

	return 0;
}

void printVector(vector<string> v) {
	int i = 0;
	while (i <= v.size()) {
		cout << v[i] << endl;
		i++;
	}
}

void printSplittedSHA256(string input) {
	string output = sha256(input);

	cout << "sha256('" << input << "'): " << output << endl;
}

