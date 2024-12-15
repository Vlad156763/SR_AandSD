#include "algorithms.h"
methodHuffman::methodHuffman() {}
methodHuffman::node::node(char ch, int order) : ch(ch), order(order), left(nullptr), right(nullptr) {}

bool methodHuffman::compare::operator()(node* a, node* b) {
	return a->order > b->order;
}
void methodHuffman::Squeeze(fstream& fileName, const string& fileNameToSqueze) {
	//заповнення хешТаблиці парами ключ-значення (символ та частота)
	char ch;
	while (fileName.get(ch)) {
		this->order[ch]++;
	}
	fileName.clear();
	fileName.seekg(0);
	//заповнення пріорітетної черги символами
	priority_queue<node*, vector<node*>, compare> pq;
	for (const auto& pair : this->order) {
		pq.push(new node(pair.first, pair.second));
	}
	//створення дерева хафмана
	while (pq.size() > 1) {
		node* left = pq.top(); pq.pop();
		node* right = pq.top(); pq.pop();
		node* parent = new node('\0', left->order + right->order);
		parent->left = left;
		parent->right = right;
		pq.push(parent);
	}
	//присвоєння у хешТаблиці кодів 
	unordered_map<char, vector<bool>> chCode;
	vector<bool> tmp;
	this->fillCharCodes(pq.top(), chCode, &tmp);
	//відкриваю бінарний файл
	fstream fileToSqueze;
	fstream fileTableDecoding;
	fileToSqueze.open((fileNameToSqueze + ".Compressed.bin"), std::ios::out | std::ios::binary | std::ios::trunc);
	fileTableDecoding.open((fileNameToSqueze + ".DecodingTable"), std::ios::out | std::ios::trunc);
	if (!fileTableDecoding.is_open()) { throw ex("Невдалось відкрити файл для запису таблиці декодування"); }
	if (!fileToSqueze.is_open()) { throw ex("Невдалось відкрити бінарний файл для запису"); }

	//записую дані для декодування таблиці
	for (const auto& pair : chCode) {
		fileTableDecoding << pair.first;
		for (bool tmp : pair.second) {
			fileTableDecoding << tmp;
		}
		fileTableDecoding << '\n';
	}
	//записую коди символів у бінарний файл побітово (якщо залишаються залишкові біти, додаю до них нулі на записую
	uint8_t buffer = 0;
	int bitCount = 0;
	while (fileName.get(ch)) {
		for (bool bit : chCode[ch]) {
			buffer = (buffer << 1) | (int)bit;
			bitCount++;
			if (bitCount == 8) {
				fileToSqueze.put(buffer);
				buffer = 0;
				bitCount = 0;
			}
		}
	} 
	if (bitCount > 0) {
		buffer = buffer << (8 - bitCount);
		fileToSqueze.put(buffer);
	}
	//кількість нулів які було додано до останнього байту я записую у файл для декодування
	fileTableDecoding << (8-bitCount) % 8;
	//закриваю файли
	fileToSqueze.close();
	fileTableDecoding.close();
	//видаляю данні
	this->DeleteAllNode(pq.top());
}
void methodHuffman::DeleteAllNode(node* root) {
	if (!root) return;
	DeleteAllNode(root->left);
	DeleteAllNode(root->right);
	delete root;
}
void methodHuffman::fillCharCodes(node* root, unordered_map<char, vector<bool>>& charCode, vector<bool>* code) {
	if (!root)return;
	if (!root->left && !root->right) {
		charCode[root->ch] = *code;
	}
	code->push_back(false);
	fillCharCodes(root->left, charCode, code);
	code->pop_back();
	code->push_back(true);
	fillCharCodes(root->right, charCode, code);
	code->pop_back();
}

string methodHuffman::Decoder(const string& compressedFile) {
	fstream decodedFile;
	fstream squeezeFile;
	fstream decodingTable;
	string capasityInputFile = "";
	decodedFile.open(compressedFile + ".txt", std::ios::out | std::ios::trunc);
	squeezeFile.open(compressedFile + ".Compressed.bin", std::ios::in | std::ios::binary);
	decodingTable.open(compressedFile + ".DecodingTable", std::ios::in);
	if (!decodedFile.is_open()) throw ex("Помилка відкриття файлу для запису декодованих данних");
	if (!squeezeFile.is_open()) throw ex("Помилка відкриття файлу для читання закодованих данних");
	if (!decodingTable.is_open()) throw ex("Помилка відкриття файлу з інформацією для декодування");

	unordered_map<char, vector<bool>> chCode;
	unordered_map<vector<bool>, char> reverseChCode;
	//переписую всі символи з таблиці для декодування у хешТаблиці та у 
	//зворотню хешТаблицю щоб швидко шукати коди символів
	char ch;
	int NumZerosInLastByte = 0;
	while (true) {
		decodingTable.get(ch);
		decodingTable.get();
		if (decodingTable.eof()) {
			NumZerosInLastByte = ch - 48;  //щоб отримати число а не код ASCII
			break;
		}
		decodingTable.unget();
		vector<bool> code;
		char codeSymbl;
		decodingTable.get(codeSymbl);
		while (codeSymbl != '\n') {
			if (codeSymbl == '1') { code.push_back(true); }
			else { code.push_back(false); }
			decodingTable.get(codeSymbl);
		}
		chCode[ch] = code;
		reverseChCode[code] = ch;
	}

	vector<bool> buffer;
	char byte;
	auto getBits = [&](int stop = 0) {
		for (int i = 7; i >= stop; i--) {
			buffer.push_back((byte >> i) & 1);
			if (reverseChCode.count(buffer)) {
				decodedFile.put(reverseChCode[buffer]);
				capasityInputFile += reverseChCode[buffer];
				buffer.clear();
			}
		}
	};
	while (true) {
		squeezeFile.get(byte);
		squeezeFile.get();
		if (squeezeFile.eof()) {
			getBits(NumZerosInLastByte);
			break;
		}
		squeezeFile.unget();
		getBits();
	}
	squeezeFile.close();
	decodingTable.close();
	return capasityInputFile;
}