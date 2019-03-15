#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;  //depth of each tree
	unordered_map<int, bool> hasMachine;
public:
	DisjointSet(int n) {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
			hasMachine[i] = false;
		}
	}

	void setMachines(const vector<int> &m) {
		for (int i = 0; i < m.size(); i++)
			hasMachine[m[i]] = true;
	}

	int find(int city) {
		if (parent[city] == city)
			return city;
		else
			return find(parent[city]);
	}

	bool tryUnion(int set1, int set2) {
		//if both sets contain a machine, sets cant be connected
		if (hasMachine[set1] && hasMachine[set2])
			return false;


		if (rank[set1] > rank[set2]) {
			if (hasMachine[set2]) hasMachine[set1] = true;
			parent[set2] = set1;
		}
		else if (rank[set1] < rank[set2]) {
			if (hasMachine[set1]) hasMachine[set2] = true;
			parent[set1] = set2;
		}
		else {
			if (hasMachine[set1]) hasMachine[set2] = true;
			parent[set1] = set2;
			rank[set2]++;
		}
		return true;
	}
};

bool compare(const vector<int> &v1, const vector<int> &v2) {
	return v1[2] > v2[2];
}

int main()
{
	int c, machines;
	cin >> c >> machines;

	DisjointSet cities(c);

	vector<vector<int>> roads(c - 1, vector<int>(3, -1));
	for (int i = 0; i < c - 1; i++)
		cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
	sort(roads.begin(), roads.end(), compare);

	vector<int> m(machines);
	for (int i = 0; i < machines; i++)
		cin >> m[i];
	cities.setMachines(m);

	int result = 0;
	for (int i = 0; i < roads.size(); i++)
		if (!cities.tryUnion(cities.find(roads[i][0]), cities.find(roads[i][1])))
			result += roads[i][2];

	cout << result << endl;
	return 0;
}
