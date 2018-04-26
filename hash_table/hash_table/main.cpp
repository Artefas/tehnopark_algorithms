#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class CHashTable {

private:
	vector<vector<string>> *hashTable;
	int countOfStringsInHashTable;

	vector<vector<string>>* InitHashTable(int size) {
		assert(size > 0);
	}

	int FirstHashByMethodOfGornor(string s);
	int SecondHashByMethodOfGornor(string s);
	
public:
	CHashTable();
	~CHashTable();

	bool AddKey(string key);
	bool DelKey(string key);
	bool CheckKey(string key);
};

CHashTable::CHashTable() {
	hashTable = new vector<vector<string>> (8);
	for (int i = 0; i < hashTable->size(); i++) {
		hashTable->push_back(new vector<string>(8));
	}
	countOfStringsInHashTable = 0;
}

CHashTable::~CHashTable() {
	delete hashTable;
}

bool CHashTable::AddKey(string key) {
	assert(key != "");
}

int CHashTable::FirstHashByMethodOfGornor(string s) {
	int hash = 0;
	int a = hashTable->size() - 1;
	int m = hashTable->size();

	for (int i = 0; i < s.size(); i++) {
		hash = (hash * a + s[i]) % m;
	}

	return hash;
}

int CHashTable::SecondHashByMethodOfGornor(string s) {
	int hash = 0;
	int a = hashTable->size() - 3;
	int m = hashTable->size();

	for (int i = 0; i < s.size(); i++) {
		hash = (hash * a + s[i]) % m;
	}

	return hash;
}