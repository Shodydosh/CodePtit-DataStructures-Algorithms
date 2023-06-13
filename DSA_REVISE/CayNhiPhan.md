### CAY NHI PHAN TIM KIEM

```cpp
struct Node
{
	int val;
	Node *left, *right;
	Node(int x)
	{
		val = x;
		left = right = NULL;
	}
};

void insert(Node *&root, int x)
{
	if (root == NULL)
	{
		root = new Node(x);
		return;
	}
	if (root->val > x)
		insert(root->left, x);
	if (root->val < x)
		insert(root->right, x);
}

void postOrder(Node *root)
{
	if (root == NULL)
		return;
	if (root->left)
		postOrder(root->left);
	if (root->right)
		postOrder(root->right);
	cout << root->val << ' ';
}
```

### CAY BINH THUONG

```cpp
struct Node
{
	int val;
	Node *left, *right;
};
typedef Node *binTree;

binTree createNode(int x)
{
	binTree tmp = new Node;
	tmp->val = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void insertNode(binTree root, int parent, int child, char c)
{
	if (root == NULL)
		return;
	if (root->val == parent)
	{
		if (c == 'L')
			root->left = createNode(child);
		else
			root->right = createNode(child);
	}
	else
	{
		// nếu khác parent thì sang trái, phải tìm vị trí để insert
		insertNode(root->left, parent, child, c);
		insertNode(root->right, parent, child, c);
	}
}
```

### DUYET CAY THEO MUC

```cpp
void levelOrder(binTree root)
{
	queue<binTree> Q;
	Q.push(root);
	while (!Q.empty())
	{
		binTree tmp = Q.front();
		Q.pop();
		cout << tmp->val << ' ';
		if (tmp->left)
			Q.push(tmp->left);
		if (tmp->right)
			Q.push(tmp->right);
	}
	cout << endl;
}
```

### INORDER + PREORDER -> POSTORDER

```cpp
struct Node
{
	int val;
	Node *left, *right;
};

int search(int a[], int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}

void postOrder(int in[], int pre[], int n)
{
	int root = search(in, pre[0], n);
	if (root != 0)
		postOrder(in, pre + 1, root);
	if (root != n - 1)
		postOrder(in + root + 1, pre + root + 1, n - root - 1);
	cout << pre[0] << ' ';
}

main()
{
	faster();
	run()
	{
		int n;
		cin >> n;
		int in[n], pre[n];
		for (int i = 0; i < n; i++)
			cin >> in[i];
		for (int i = 0; i < n; i++)
			cin >> pre[i];
		postOrder(in, pre, n);
		cout << endl;
	}
}
```
