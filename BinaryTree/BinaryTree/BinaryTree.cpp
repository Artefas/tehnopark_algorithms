
#include <iostream>
#include <queue>
#include <stack>
#include <assert.h>


class CBinTree {
public:
	~CBinTree();
	void Insert(int key);
	void PrintPostOrder();

private:
	struct CNode {
		int key;
		CNode *left;
		CNode *right;

		explicit CNode(int key) : key(key), left(nullptr), right(nullptr) {}
	};

	CNode *root = nullptr;

	
	
};

CBinTree::~CBinTree() {
	std::queue<CNode*> nodeQueue;
	CNode *toDelete;

	if (root != nullptr) nodeQueue.push(root);
	
	while (!nodeQueue.empty()) {
		toDelete = nodeQueue.front();
		nodeQueue.pop();

		if (toDelete->left != nullptr) nodeQueue.push(toDelete->left);
		if (toDelete->right != nullptr) nodeQueue.push(toDelete->right);

		delete toDelete;
	}
}

void CBinTree::Insert(int key) {
	if (root != nullptr) {
		CNode *node = root;
		while (true) {
			if (node->key < key) {
				if (node->right == nullptr) {
					node->right = new CNode(key);
					break;
				} else {
					node = node->right;
				}
			} else if (node->key > key) {
				if (node->left == nullptr) {
					node->left = new CNode(key);
					break;
				}
				else {
					node = node->left;
				}
			} else {
				break;
			}
		}
	} else {
		root = new CNode(key);
	}
}

void CBinTree::PrintPostOrder() {
	if (root != nullptr) {
		std::stack<CNode*> nodesStack;
		CNode *node = root;
		CNode *visitedNode = nullptr;

		nodesStack.push(node);
		while ( !nodesStack.empty() ) {
			node = nodesStack.top();
			if (node->right != nullptr) {
				if (node->right != visitedNode) {
					nodesStack.push(node->right);
				} else {
					std::cout << node->key << ' ';
					visitedNode = node;
					nodesStack.pop();
				}
			}

			if (node->left != nullptr) {
				if (node->left != visitedNode) {
					nodesStack.push(node->left);
				}
				else {
					std::cout << node->key << ' ';
					visitedNode = node;
					nodesStack.pop();
				}
			}

			if (node->left == nullptr && node->left == nullptr) {
				std::cout << node->key << ' ';
				visitedNode = node;
				nodesStack.pop();
			}
		}
	}
}

int main(int argc, char *argv[]) {


	return 0;
}




