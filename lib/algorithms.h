#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include "exceptions.h"
#include "Console.h"
using std::unordered_map;
using std::unordered_set;
using std::fstream;
using std::priority_queue;
using std::vector;
using std::string; 
using std::pair;
using std::cout;

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


namespace {
	template<typename VERTEX>
	class ForestNode {
	private:
		VERTEX v;
		vector<ForestNode<VERTEX>*> child;
	public:
		ForestNode() {}
		inline void setVertex(const VERTEX& v) { this->v = v; }
		ForestNode<VERTEX>* addChild(const VERTEX& child) {
			ForestNode<VERTEX>* newChild = new ForestNode<VERTEX>();
			newChild->setVertex(child);
			this->child.push_back(newChild);
			return this->child.back();
		}
		inline VERTEX getVertex() { return this->v; }
		inline vector<ForestNode<VERTEX>*>& childData() { return this->child; }
	};
	template<typename VERTEX> class forest {
	private:
		vector<ForestNode<VERTEX>*> d;
		void deleteTree(ForestNode<VERTEX>* root) {
			for (int i = 0; i < root->childData().size(); i++) {
				deleteTree(root->childData()[i]);
			}
			delete root;
		}
		void walkTreeRecursion(vector<vector<VERTEX>>& paths, ForestNode<VERTEX>& currentNode) {
			static vector<VERTEX> currentWay;
			currentWay.push_back(currentNode.getVertex());
			if (currentNode.childData().size() == 0) {
				paths.push_back(currentWay);
				currentWay.pop_back();
				return;
			}
			for (int i = 0; i < currentNode.childData().size(); i++) {
				walkTreeRecursion(paths, *currentNode.childData()[i]);
			}
			currentWay.pop_back();
		}
	public:
		forest() {}
		ForestNode<VERTEX>* addRoot(const VERTEX& val) {
			ForestNode<VERTEX>* newRoot = new ForestNode<VERTEX>();
			newRoot->setVertex(val);
			this->d.push_back(newRoot);
			return newRoot;
		}
		vector<vector<VERTEX>> getTreeWalk(int indexTree) {
			if (this->d.size() <= indexTree) throw ex("Індекс не дійсний");
			vector<vector<VERTEX>> pathsInTree;
			walkTreeRecursion(pathsInTree, *(this->d[indexTree]));
			return pathsInTree;

		}
		size_t size() { return this->d.size(); }
		~forest() {
			for (int i = 0; i < this->d.size(); i++) {
				deleteTree(this->d[i]);
			}
		}
	};
}



template<typename VERTEX>class no_weighted_graph {
private:
	unordered_map<VERTEX, vector<VERTEX>> d;

	
public:
	no_weighted_graph() {}
	//directed може бути "<-", "->", "<->", інакше кидає виключення ex("Невірний символ орієнтації ребра")
	void add(const VERTEX& From, const char* directed,  const VERTEX& To) {
		if (directed == "->") {
			this->d[From].push_back(To);
		}
		else if (directed == "<-") {
			this->d[To].push_back(From);
		}
		else if (directed == "<->") {
			this->d[From].push_back(To);
			this->d[To].push_back(From);
		}
		else {
			throw ex("Невірний символ орієнтації ребра");
		}
	}
	//is_directed відповідає за орієнтацію ребра, якщо вказано 1 тоді порядок вершин важливий
	//From To (орієнтоване_ребро) From -> To
	void add(const VERTEX& From, const VERTEX& To, bool is_directed) {
		if (!is_directed) {
			this->d[To].push_back(From);
		}
		this->d[From].push_back(To);
	}
	vector<VERTEX>& operator[](const VERTEX& Vertex) {
		return this->d.at(Vertex);
	}
	//повертає кубічний масив [підграф][шлях][вершини]
	//якщо вершини немає, кидає виключення ex("Вершини немає")
	vector<vector<vector<VERTEX>>> DFS(VERTEX startV) {
		if (this->d.find(startV) == this->d.end()) {
			throw ex("Вершини немає");
		}
		unordered_set<VERTEX> visited;//відвідані вершини
		forest<VERTEX> forestTreeResult;
		bool exit = false; 
		bool was_in_loop = false;
		while (!exit) {
			was_in_loop = false;
			DFSRecursion(startV, startV, visited, forestTreeResult);
			//перевіряю кожну вершину чи є вона у масиві відвіданих, якщо якоїсь вершини немає, повторюю рекурсивний обхід у глибину
			//для зв'язаних вершин доти, доки всі вершини будуть відвіданими
			for (auto& key : this->d) {
				if (visited.find(key.first) == visited.end()) {
					startV = key.first;
					was_in_loop = true;
					break;
				}
			}
			if (!was_in_loop) break;
		}
		vector<vector<vector<VERTEX>>> result;
		for (int i = 0; i < forestTreeResult.size(); i++) {
			result.push_back(forestTreeResult.getTreeWalk(i));
		}
		return result;
	}
private:
	void DFSRecursion(
		const VERTEX& startV, 
		const VERTEX& To,  
		unordered_set<VERTEX>& visited, 
		forest<VERTEX>& forestTreeResult,
		ForestNode<VERTEX>* currentNode = nullptr
	) {
		if (visited.find(startV) != visited.end()) { 
			return; 
		}
		if (startV == To) { 
			currentNode = forestTreeResult.addRoot(startV);
		} else 
			currentNode = currentNode->addChild(startV);
		visited.insert(startV);
		// якщо вершини немає, треба це відслідковувати
		if (this->d.find(startV) != this->d.end()) {
			for (const auto& v : this->d.find(startV)->second) {
				DFSRecursion(v, startV, visited, forestTreeResult, currentNode);
			}
		}
	}
};

//template<typename VERTEX, typename WEIGHT> class edgeWithWeight {
//private:
//	VERTEX From;
//	VERTEX To;
//	bool is_directed = false;
//	WEIGHT Weight;
//public:
//	edgeWithWeight(const VERTEX& From, const VERTEX& To, const WEIGHT& Weight, bool is_directed) {
//		this->From = From;
//		this->To = To;
//		this->is_directed = is_directed;
//	}
//
//};
//template<typename VERTEX, typename WEIGHT> class weighted_graph {
//private:
//	vector<edgeWithWeight<VERTEX, WEIGHT>> edges;
//public:
//	weighted_graph() {}
//	void push_back(const VERTEX& From, const VERTEX& To, const WEIGHT& Weight, bool is_directed) {
//		this->edges.push_back(edgeWithWeight<VERTEX, WEIGHT>(From, To, Weight, is_directed));
//	}
//};

#endif // !ALGORITHMS_H