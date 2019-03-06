#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class City {
public:
    int id;
    vector<int> neighbors;
    City(){}
    City(int i) {
        id = i;
        neighbors = vector<int>();
    }
};

int visitNeighbors(int n, const vector<City*>& cities, vector<bool>& visited, int& roads) {
    City* c;
    int neighborhood = 0;
    queue<City*> q;
    q.push( cities[n] );

    while(!q.empty()) {
        c = q.front();
        q.pop();
        if(!visited[c->id]) { 
            visited[c->id] = true;
            if(c->id != n) roads++; 
            neighborhood++;

            for(int i=0; i<c->neighbors.size(); i++) 
                if(!visited[ c->neighbors[i] ]) 
                    q.push( cities[ c->neighbors[i] ] );
        }
    }
    return neighborhood;
}

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> roads) {
    vector<bool> visited (n,false); 
    vector<City*> cities; 
    City* c;
    for(int i=0; i<n; i++) {
        c = new City(i);
        cities.push_back(c);
    }
    for(int i=0; i<roads.size(); i++) {
        cities[ roads[i][0]-1 ]->neighbors.push_back( roads[i][1]-1 );
        cities[ roads[i][1]-1 ]->neighbors.push_back( roads[i][0]-1 );
    }

    int roadsToBuild;
    vector<int> neighborhoods;
    vector<int> roadsInNeighborHood;
    for(int i=0; i<n; i++) { 
        if(!visited[i]) {
            roadsToBuild = 0;
            neighborhoods.push_back( visitNeighbors(i,cities,visited, roadsToBuild) );
            roadsInNeighborHood.push_back(roadsToBuild);
        }
    }

    long totalCost=0, costLibrariesInAllCities=0, costMinRoadsOneLibrary=0; 
    for(int i=0; i<neighborhoods.size(); i++) {
        if(neighborhoods[i]==1) 
            totalCost += c_lib;
        else {
            costLibrariesInAllCities = neighborhoods[i] * c_lib;
            costMinRoadsOneLibrary = roadsInNeighborHood[i] * c_road + c_lib;
            
            totalCost += min(costLibrariesInAllCities,costMinRoadsOneLibrary);
        }
    }

    for(int i=0; i<cities.size(); i++) delete cities[i];
    cities.clear();

    return totalCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
