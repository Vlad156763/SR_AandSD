#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include "exceptions.h"
#include "Console.h"
using std::unordered_map;
using std::fstream;
using std::priority_queue;
using std::vector;
using std::string; 
using std::cout;
namespace fs = std::filesystem;

class methodHuffman {
private:
	struct node {
		char ch;
		int order;
		node* left = nullptr;
		node* right = nullptr;
	public:
		node(char, int);
	};
	struct compare {
	public: 
		bool operator ()(node*, node*);
	};


private:
	unordered_map<char, int> order;
	void DeleteAllNode(node*);
	void fillCharCodes(node*, unordered_map<char, vector<bool>>&, vector<bool>*);
public:
	methodHuffman();
	void Squeeze(fstream&, const string&);
	string Decoder(const string&);
};
#endif // !ALGORITHMS_H

