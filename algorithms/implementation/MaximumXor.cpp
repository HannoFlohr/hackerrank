#include <bits/stdc++.h>

using namespace std;

class TrieNode {
public:
	vector<TrieNode*> children = vector<TrieNode*>(2, NULL);
	void add(int v, int index) {
		int bitPos = 31 - index;
		if (bitPos < 0) return;

		int power = 1 << bitPos;
		int bit = v / power;
		int remainder = v % power;

		if (!children[bit])
			children[bit] = new TrieNode();
		children[bit]->add(remainder, index + 1);
	}
};

class BitTrie {
public:
	TrieNode *root = new TrieNode();
	void add(int v) {
		root->add(v, 0);
	}

	int solve(int v) {
		TrieNode* cur = root;
		int xorV = 0, bitPos, power, bit, remainder = v;
		for (int i = 0; i < 32; i++) {
			bitPos = 31 - i;
			power = 1 << bitPos;
			bit = remainder / power;
			remainder = remainder % power;

			if (cur->children[bit ^ 1]) {
				xorV += power;
				cur = cur->children[bit ^ 1];
			}
			else
				cur = cur->children[bit];
		}
		return xorV;
	}
};

vector<int> maxXor(vector<int> arr, vector<int> queries) {
	vector<int> results(0);
	BitTrie bt;
	for (auto a : arr)
		bt.add(a);
	for (auto q : queries)
		results.push_back(bt.solve(q));

	return results;
}

int main()
{
	int n, m;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;

	vector<int> queries(m);
	for (int i = 0; i < m; i++)
		cin >> queries[i];

	vector<int> result = maxXor(arr, queries);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}
