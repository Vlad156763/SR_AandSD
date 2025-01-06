#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
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
template<typename VERTEX> inline void ForestNode<VERTEX>::setVertex(const VERTEX& v) { this->v = v; }
template<typename VERTEX> ForestNode<VERTEX>* ForestNode<VERTEX>::addChild(VERTEX v) {
	ForestNode<VERTEX>* newChild = new ForestNode<VERTEX>();
	newChild->v = v;
	this->child.push_back(newChild);
	return this->child.back();
}
template<typename VERTEX> inline VERTEX& ForestNode<VERTEX>::getVertex() { return this->v; }
template<typename VERTEX> inline vector<ForestNode<VERTEX>*>& ForestNode<VERTEX>::childData() { return this->child; }
template<typename VERTEX> void forest<VERTEX>::deleteTree(ForestNode<VERTEX>* root) {
	for (int i = 0; i < root->childData().size(); i++) {
		deleteTree(root->childData()[i]);
	}
	delete root;
}
template<typename VERTEX> void forest<VERTEX>::walkTreeRecursion(vector<vector<VERTEX>>& paths, ForestNode<VERTEX>* currentNode) {
	static vector<VERTEX> currentWay;
	currentWay.push_back(currentNode->getVertex());
	if (currentNode->childData().size() == 0) {
		paths.push_back(currentWay);
		currentWay.pop_back();
		return;
	}
	for (int i = 0; i < currentNode->childData().size(); i++) {
		walkTreeRecursion(paths, currentNode->childData()[i]);
	}
	currentWay.pop_back();
}
template<typename VERTEX> void forest<VERTEX>::walkTreeBFS(vector<VERTEX>& paths, ForestNode<VERTEX>* currentNode) {
	queue<ForestNode<VERTEX>*> q;
	q.push(currentNode); paths.push_back(q.front()->getVertex());
	for (; q.size() > 0;) {
		for (int i = 0; i < q.front()->childData().size(); i++) {
			q.push(q.front()->childData()[i]);
			paths.push_back(q.front()->childData()[i]->getVertex());
		}
		q.pop();
	}
}
template<typename VERTEX> ForestNode<VERTEX>* forest<VERTEX>::addRoot(const VERTEX& val) {
	ForestNode<VERTEX>* newRoot = new ForestNode<VERTEX>();
	newRoot->setVertex(val);
	this->d.push_back(newRoot);
	return newRoot;
}
template<typename VERTEX> vector<vector<VERTEX>> forest<VERTEX>::getTreeWalkDFS(int indexTree) {
	if (indexTree >= this->d.size()) throw ex("Індекс не дійсний");
	vector<vector<VERTEX>> pathsInTree;
	walkTreeRecursion(pathsInTree, (this->d[indexTree]));
	return pathsInTree;
}
template<typename VERTEX> vector<VERTEX> forest<VERTEX>::getTreeWalkBFS(int indexTree) {
	if (indexTree >= this->d.size()) throw ex("Індекс не дійсний");
	vector<VERTEX> pathsInTree;
	walkTreeBFS(pathsInTree, (this->d[indexTree]));
	return pathsInTree;
}
template<typename VERTEX> inline size_t forest<VERTEX>::size() const { return this->d.size(); }
template<typename VERTEX> forest<VERTEX>::forest(const forest<VERTEX>& other) {
	//всі динамічно створені змінні перенести у this із  other

	//ітеруюсь по кожному дереву
	for (int i = 0; i < other.d.size(); i++) {
		ForestNode<VERTEX>* currentNodeThis = this->addRoot(other.d[i]->getVertex());
		queue<ForestNode<VERTEX>*> qOther;
		queue<ForestNode<VERTEX>*> qThis;
		qOther.push(other.d[i]);
		qThis.push(currentNodeThis);
		while (!qOther.empty()) {
			for (int j = 0; j < qOther.front()->childData().size(); j++) {
				qOther.push(qOther.front()->childData()[j]);
				qThis.push(qThis.front()->addChild(qOther.front()->childData()[j]->getVertex()));
			}
			qOther.pop();
			qThis.pop();
		}
	}
}
template<typename VERTEX> vector<ForestNode<VERTEX>*>& forest<VERTEX>::data() { return this->d; }
template<typename VERTEX> forest<VERTEX>::forest() {}
template<typename VERTEX> forest<VERTEX>::~forest() {
	for (int i = 0; i < this->d.size(); i++) {
		deleteTree(this->d[i]);
	}
}
template<typename VERTEX> bool no_weighted_graph<VERTEX>::isVertex(const VERTEX& V) {
	return this->d.find(V) != this->d.end();
}
template<typename VERTEX> void no_weighted_graph<VERTEX>::add(const VERTEX& From, const char* directed, const VERTEX& To) {
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
template<typename VERTEX> void no_weighted_graph<VERTEX>::add(const VERTEX& From, const VERTEX& To, bool is_directed) {
	if (!is_directed) {
		this->d[To].push_back(From);
	}
	this->d[From].push_back(To);
}
template<typename VERTEX> vector<VERTEX>& no_weighted_graph<VERTEX>::operator[](const VERTEX& Vertex) { return this->d.at(Vertex); }
template<typename VERTEX> forest<VERTEX> no_weighted_graph<VERTEX>::DFS(VERTEX startV) {
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
	return forest<VERTEX>(forestTreeResult);
}
template<typename VERTEX> forest<VERTEX> no_weighted_graph<VERTEX>::BFS(VERTEX startV) {
	if (this->d.find(startV) == this->d.end()) {
		throw ex("Вершини немає");
	}
	queue<VERTEX> qResult;
	unordered_set<VERTEX> visited;//відвідані вершини
	forest<VERTEX> forestTreeResult;
	bool exit = false;
	bool was_in_loop = false;
	while (!exit) {
		was_in_loop = false;
		BFSSecondary(startV, forestTreeResult, visited);

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
	return forestTreeResult;
}
template<typename VERTEX> void no_weighted_graph<VERTEX>::DFSRecursion(const VERTEX& startV, const VERTEX& To, unordered_set<VERTEX>& visited, forest<VERTEX>& forestTreeResult, ForestNode<VERTEX>* currentNode) {
	if (visited.find(startV) != visited.end()) {
		return;
	}
	if (startV == To) {
		currentNode = forestTreeResult.addRoot(startV);
	}
	else
		currentNode = currentNode->addChild(startV);
	visited.insert(startV);
	// якщо вершини немає, треба це відслідковувати
	if (this->d.find(startV) != this->d.end()) {
		for (const auto& v : this->d.find(startV)->second) {
			DFSRecursion(v, startV, visited, forestTreeResult, currentNode);
		}
	}
}
template<typename VERTEX> void no_weighted_graph<VERTEX>::BFSSecondary(const VERTEX& startV, forest<VERTEX>& forestTreeResult, unordered_set<VERTEX>& visited) {
	queue<ForestNode<VERTEX>*> qResult;
	ForestNode<VERTEX>* currentNode = forestTreeResult.addRoot(startV);
	qResult.push(currentNode);
	visited.insert(startV);
	for (int i = 0; qResult.size() > 0;) {
		if (this->d.find(qResult.front()->getVertex()) != this->d.end()) {
			for (const auto& v : this->d.find(qResult.front()->getVertex())->second) {
				if (visited.find(v) != visited.end()) { continue; }
				currentNode = qResult.front()->addChild(v);
				visited.insert(currentNode->getVertex());
				qResult.push(currentNode);
			}
		}
		qResult.pop();
	}
}
template<typename VERTEX> void no_weighted_graph<VERTEX>::classificationEdges(VERTEX startV) {
	using namespace CEG;
	vector<triple<VERTEX>> result;
	unordered_map<VERTEX, vector<VERTEX>> copy_d;
	for (auto key : this->d) {
		vector<pair<VERTEX>> tmp;
		for (int i = 0; i < key.second.size(); i++) {
			tmp.push_back(pair(key.second[i]));
		}
		copy_d[key.first] = tmp;
	}
	unordered_map<VERTEX, stateVertex> visited;
	



	/*
	обхід дерева в глибину
	*/
	

	/*
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
	*/
	


	/*
	1. DFS
	2. Спочатку всі вершини невідвідані
	3. Починаючи з вершини startV позначаю її сірою. Рухаючись у глиб кожну білу вершину позначаю сірою і кожне ребро між вершинами вважаю ребром дерева.
	4. Якщо при русі в глибину знайдено сіру вершину, позначаю ребро яке є між сірими вершинами - ребром назад і записую що граф має цикл 
	5. Якщо при русі в глибину знайдено чорну вершину, позначаю ребро яке є між сірою та чорною вершинами - ребром вперед 
	6. неорієновані графи матимуть тільки ребра дерева і ребра назад
	*/

}

template<typename VERTEX> void no_weighted_graph<VERTEX>::DFSRecursionForClassification(const VERTEX& startV, unordered_map<VERTEX, CEG::stateVertex>& visited, vector<CEG::triple<VERTEX>>& result, unordered_map<VERTEX, vector<VERTEX>>& copy_d) {
	static unordered_set<VERTEX> wayDFS;
	wayDFS.insert(startV);
	if (visited.find(startV) != visited.end()) { return; }
	visited[startV] = CEG::stateVertex::Active;
	// якщо ключа-вершини немає, це означає що вона не має шляхів кудись окрім одного, звідки прийшов алгоритм
	if (copy_d.find(startV) != copy_d.end()) {
		for (VERTEX& v : copy_d.find(startV)->second) {
			if (visited.find(v) != visited.end() && visited[v] == CEG::stateVertex::Active) { // якщо вершина є у відвіданих і вона активна, то це ребро назад
				result.push_back(CEG::triple(startV, v.To, CEG::stateEdge::Back_edge));
				continue;
			}
			if (visited.find(v) != visited.end() && visited[v] == CEG::stateVertex::Visited) { // якщо вершина є у відвіданих і вона вже відвідана (її обробка завершена), то це ребро вперед
				result.push_back(CEG::triple(startV, v.To, CEG::stateEdge::Cross_edge));
				continue;
			}
			if (wayDFS.find(v.To) != wayDFS.end()) { //якщо 

			}
			result.push_back(CEG::triple(startV, v.To, CEG::stateEdge::Tree_edge));
			DFSRecursionForClassification(v.To, visited, result, copy_d);
			v.state = CEG::stateVertex::Visited;
			wayDFS.erase(v.To);
		}
	}
}
#endif // !NO_WEIGHT_GRAPH_HPP