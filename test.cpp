#include "test.h"

void __test::show() {
	no_weighted_graph<const char*> qa;
	qa.add("A1", "<->", "A2");
	qa.add("A1", "<->", "A3");
	qa.add("A2", "<->", "At");
	qa.add("At", "<->", "Ak");
	qa.add("A3", "<->", "A4");
	qa.add("A4", "->", "A6");
	qa.add("A6", "->", "A5");
	qa.add("A5", "->", "A4");
	qa.add("B1", "<->", "B2");
	qa.add("A5", "<->", "A11");
	qa.add("A5", "<->", "A22");
	
	
	/*qa.add("X1", "<-", "X2");
	qa.add("X1", "<-", "X3");
	qa.add("X1", "<->", "X4");
	qa.add("X2", "<->", "X5");
	qa.add("X2", "<->", "X4");
	qa.add("X3", "->", "X5");
	qa.add("X3", "<-", "X4");
	qa.add("X4", "->", "X5");
	qa.add("X5", "<->", "X5");*/








	vector<vector<vector<const char*>>>resultPaths = qa.DFS("A1");
	unordered_map< const char*, const char*> buffer;//буфер для гарного виводу вершин
	cout << "Початок: A1" << out::endl;
	for (int indexSubGraph = 0; indexSubGraph < resultPaths.size(); indexSubGraph++) {
		cout << indexSubGraph << ":  Підграф" << out::endl;
		for (int indexWay = 0; indexWay < resultPaths[indexSubGraph].size(); indexWay++) {
			cout << out::tab << indexWay << ": ";
			for (int indexVertex = 0; indexVertex < resultPaths[indexSubGraph][indexWay].size(); indexVertex++) {
				if (buffer.find(resultPaths[indexSubGraph][indexWay][indexVertex]) == buffer.end()) {
					buffer[resultPaths[indexSubGraph][indexWay][indexVertex]];
					cout << out::rgb(0, 255, 0);
				}
				else cout << out::reset;
				cout << resultPaths[indexSubGraph][indexWay][indexVertex] << " " << out::reset;
			}
			cout << out::endl;
		}
	}

}	