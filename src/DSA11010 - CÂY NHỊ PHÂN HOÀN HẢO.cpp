#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define run() \
	int t;    \
	cin >> t; \
	while (t--)
#define faster()                      \
	cin.tie(0);                       \
	ios_base::sync_with_stdio(false); \
	cout.tie(0);

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

int isPerfect(binTree root)
{
	queue<binTree> Q;
	Q.push(root);
	int s = 0, f = 0, l = 0;
	while (Q.size())
	{
		s = Q.size();
		// check if amount of nodes in a level is == pow(2, l);
		if (s != pow(2, l))
			return 0;
		for (int i = 0; i < s; i++)
		{
			binTree tmp = Q.front();
			Q.pop();
			if (tmp->left)
				Q.push(tmp->left);
			if (tmp->right)
				Q.push(tmp->right);
		}
		l++;
	}
	return 1;
}

int n, a, b;
main()
{
	faster();
	run()
	{
		binTree root = NULL;
		cin >> n;
		int parent, child;
		char c;

		cin >> parent >> child >> c;
		root = createNode(parent);
		insertNode(root, parent, child, c);

		n--;
		while (n--)
		{
			cin >> parent >> child >> c;
			insertNode(root, parent, child, c);
		}
		if (isPerfect(root))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
