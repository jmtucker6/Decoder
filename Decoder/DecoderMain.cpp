#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

struct Node {
	Node *left;
	Node *right;
	std::string value;
};
Node* constructBST(std::string in[], std::string pre[], int n);
int getIndex(std::string arr[], int size, std::string val);
std::vector<std::string> fillVector(std::vector<std::string>, std::string);

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cout << "Expected './main <filename>" << std::endl;
		return 0;
	}
	std::ifstream treeInput(argv[1]);
	std::string preorderTraversal = "";
	std::string inorderTraversal = "";

	getline(treeInput, preorderTraversal);
	getline(treeInput, inorderTraversal);

	std::vector<std::string> inorder;
	std::vector<std::string> preorder;

	inorder = fillVector(inorder, inorderTraversal);
	preorder = fillVector(preorder, preorderTraversal);
	
	std::string *in = &inorder[0];
	std::string *pre = &preorder[0];

	Node *tree = constructBST(in, pre, inorder.size());

	return 0;
}

Node* constructBST(std::string in[], std::string pre[], int size) {
	if (size <= 0)
		return nullptr;
	int i = getIndex(in, size, pre[0]);
	int sizeLeft = i;
	int sizeRight = size - i - 1;
	Node *temp = new Node;
	temp->value = pre[0];
	temp->left = constructBST(in, pre + 1, sizeLeft);
	temp->right = constructBST(in + i + 1, pre + sizeLeft + 1, sizeRight);
	return temp;
}

int getIndex(std::string arr[], int size, std::string val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val)
			return i;
	}
}

std::vector<std::string> fillVector(std::vector<std::string> v, std::string s) {
	std::istringstream sstream(s);
	std::string temp = "";
	while (sstream >> temp) {
		v.push_back(temp);
	}
	return v;
}