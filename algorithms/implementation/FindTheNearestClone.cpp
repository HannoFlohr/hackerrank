#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    int color [graph_nodes+1];
    //maps the colors
    map<long,int> colors;
    for(int i=0; i<ids.size(); i++) {
        color[i+1] = ids[i];  
        colors[ ids[i] ]++; 
    } 
    
    //saves the neighbors for each node in a vector
    vector<vector<int>> neighbors (graph_nodes+1);
    for(int i=0; i<graph_from.size(); i++) {
        neighbors[ graph_from[i] ].push_back( graph_to[i] );
        neighbors[ graph_to[i] ].push_back( graph_from[i] );
    }
       
    if(colors[val] < 2 ) 
        return -1;
    else {
        vector<int> distances;
        bool visited[graph_nodes+1] = {false};
        int dist[graph_nodes+1] = {-1};

        queue<int> q;
        q.push(val); //cout << "val " << val << endl;

        int cur, shortest = 0;
        while(!q.empty()) {
            shortest = 0;
            cur = q.front();
            //cout << "cur " << cur << " " << color[cur] << endl;
            if(!visited[cur]) dist[cur] = shortest;
            visited[cur] = true; 
            q.pop();
            for(auto n : neighbors[cur]) {
                if(!visited[n]) {
                    q.push(n);
                    shortest++; 
                    dist[n] = dist[cur]+1; //cout << "shortest " << dist[n] << endl;
                    visited[n] = true;
                    //cout <<"id val "<< id[val] << endl;
                    if(color[n]==val) {
                        distances.push_back(dist[n]);
                        //cout << "push" << dist[n] << endl;
                    }
                }
            }       
        }

        int min = *min_element(distances.begin(),distances.end());
        return min;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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
