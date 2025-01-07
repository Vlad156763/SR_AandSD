#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <fstream> //для файлів
#include <unordered_map> //для швидкого пошуку пар ключ-значення
#include <unordered_set> //для швидкого пошуку елементу
#include <queue> // для алгоритму BFS
#include <vector> 
#include <string> 
#include <iostream>
#include "exceptions.h"
#include "Console.h"

using std::unordered_map;
using std::unordered_set;
using std::fstream;
using std::priority_queue;
using std::queue;
using std::vector;
using std::string;
using std::cout;

class methodHuffman;
template<typename VERTEX> class ForestNode;
template<typename VERTEX> class forest;
template<typename Compare> class quickSort;
template<typename VERTEX> class no_weighted_graph;


namespace CEG { // класифікація ребер графів
	enum stateEdge {
		Tree_edge,
		Back_edge,
		Forward_edge,
		Cross_edge
	};
	enum TypeVertex {
		No_visited,
		Active,
		Visited
	};
	struct stateVertex {
		TypeVertex type = No_visited;
		int counter = 0;
		stateVertex() = default;
		stateVertex(TypeVertex type, int counter) : counter(counter), type(type) {}
	};
	
	template<typename VERTEX> struct triple {
		VERTEX From = VERTEX();
		VERTEX To = VERTEX();
		stateEdge typeEdge;
		triple(VERTEX From, VERTEX To, stateEdge typeEdge) : From(From), To(To), typeEdge(typeEdge) {}
		triple(const triple& other) { this->From = other.From; this->To = other.To; this->typeEdge = other.typeEdge; }
		const char* typeEdgeTo_c_str() const {
			switch (this->typeEdge) {
			case Tree_edge: return "Tree_edge"; 
			case Back_edge: return "Back_edge"; 
			case Forward_edge: return "Forward_edge";
			case Cross_edge: return "Cross_edge";
			default:return "Unknown";
			}
		}
	};
	template<typename VERTEX> struct pair {
		VERTEX From = VERTEX();
		VERTEX To = VERTEX();
		pair(const VERTEX& From, const VERTEX& To) : From(From), To(To) {}
		pair(const pair& other) { this->From = other.From; this->To = other.To; }
		bool operator==(const pair& other) const { return From == other.From && To == other.To; }
	};
}
namespace std {
	template<typename VERTEX> struct hash<CEG::pair<VERTEX>> {
		size_t operator()(const CEG::pair<VERTEX>& p) const { return hash<VERTEX>()(p.From) ^ (hash<VERTEX>()(p.To) << 1); }
	};
}

template<typename VERTEX>
class ForestNode {
private:
	VERTEX v = VERTEX();
	vector<ForestNode<VERTEX>*> child;
public:
	inline void setVertex(const VERTEX& vertex);
	ForestNode<VERTEX>* addChild(VERTEX vertex);
	inline VERTEX& getVertex();
	inline vector<ForestNode<VERTEX>*>& childData();
};

template<typename VERTEX> class forest {
private:
	vector<ForestNode<VERTEX>*> d;
	void deleteTree(ForestNode<VERTEX>* root);
	void walkTreeRecursion(vector<vector<VERTEX>>& paths, ForestNode<VERTEX>* currentNode);
	void walkTreeBFS(vector<VERTEX>& paths, ForestNode<VERTEX>* currentNode);

public:
	forest();
	ForestNode<VERTEX>* addRoot(const VERTEX& val);
	[[nodiscard]]
	vector<vector<VERTEX>> getTreeWalkDFS(int indexTree);
	[[nodiscard]]
	vector<VERTEX> getTreeWalkBFS(int indexTree);
	inline size_t size() const;
	[[nodiscard]]
	inline vector<ForestNode<VERTEX>*>& data();
	forest(const forest<VERTEX>& other);
	~forest();
};

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
	Compare compare = Compare();
public:
	template<typename T> void sort(T* array, const int& left, const int& right);
};

template<typename VERTEX> class no_weighted_graph {
private:
	unordered_map<VERTEX, vector<VERTEX>> d;
public:
	//поверне true якщо задана вершина є у графі
	bool isVertex(const VERTEX& V);
	//directed може бути "<-", "->", "<->", інакше кидає виключення ex("Невірний символ орієнтації ребра")
	void add(const VERTEX& From, const char* directed, const VERTEX& To);
	//is_directed відповідає за орієнтацію ребра, якщо вказано 1 тоді порядок вершин важливий
	//From To (орієнтоване_ребро) From -> To
	void add(const VERTEX& From, const VERTEX& To, bool is_directed);
	vector<VERTEX>& operator[](const VERTEX& Vertex);
	//якщо вершини немає, кидає виключення ex("Вершини немає")
	[[nodiscard]]
	forest<VERTEX> DFS(VERTEX startV);
	//якщо вершини немає, кидає виключення ex("Вершини немає")
	[[nodiscard]]
	forest<VERTEX> BFS(VERTEX startV);
	//якщо вершини немає, кидає виключення ex("Вершини немає")
	[[nodiscard]]
	vector<CEG::triple<VERTEX>> classificationEdges(VERTEX startV, bool& graphHasLoop);
private:
	void DFSRecursion(const VERTEX& startV, const VERTEX& To, unordered_set<VERTEX>& visited, forest<VERTEX>& forestTreeResult, ForestNode<VERTEX>* currentNode = nullptr);
	void BFSSecondary(const VERTEX& startV, forest<VERTEX>& forestTreeResult, unordered_set<VERTEX>& visited);
	void DFSRecursionForClassification(const VERTEX& startV, unordered_map<VERTEX, CEG::stateVertex>& visited, vector<CEG::triple<VERTEX>>& result, bool& graphHasLoop);
	bool edgeIsDirected(const VERTEX& From, const VERTEX& To);
};

#include "algorithms.hpp" //реалізація всіх шаблонних класів
#endif // !ALGORITHMS_H