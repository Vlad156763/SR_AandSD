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

template<typename Compare> class quickSort {
	Compare compare;
public:
	quickSort();
	template<typename T> void sort(T* array, const int& left, const int& right);
};

template<typename Compare> quickSort<Compare>::quickSort() {}
template<typename Compare> template<typename T> void quickSort<Compare>::sort(T* array, const int& left, const int& right) {
	T buffer;
	int i = left;
	int j = right;
	T pivot = array[(i + j) / 2];
	while (i <= j)
	{
		while (compare(array[i], pivot)) ++i;
		while (compare(pivot, array[j])) --j;
		if (i <= j) {
			buffer = array[i];
			array[i] = array[j];
			array[j] = buffer;
			++i;
			--j;
		}
	}
	if (j > left) sort(array, left, j);
	if (i < right) sort(array, i, right);
}
#endif // !ALGORITHMS_H

