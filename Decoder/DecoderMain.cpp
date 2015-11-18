struct Node {
	Node *left;
	Node *right;
	int value;
};
Node* constructBST(int in[], int pre[], int n);
int getIndex(int arr[], int size, int val);

int main() {

	int in[8] = { 4, 10, 3, 1, 7, 11, 8, 2 };
	int pre[8] = { 7, 10, 4, 3, 1, 2, 8, 11 };

	Node *tree = constructBST(in, pre, 8);

	return 0;
}

Node* constructBST(int in[], int pre[], int size) {
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

int getIndex(int arr[], int size, int val) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == val)
			return i;
	}
}