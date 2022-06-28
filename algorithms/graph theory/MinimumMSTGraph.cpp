#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int g;
    ll n, m, s;
    cin >> g;
    while(g--) {
        cin >> n >> m >> s;
        
        //mst is already full graph
        if(m == n-1) {
            cout << s << endl;
            continue;
        }
        
        /*
        (property 1+2) we have n nodes connected by maximum n-1 edges
        (property 3) mimimum edges: n-1
        (property 5) there exists a edge connecting two nodes with minimal weight 1

        the other n-1 nodes are connected by a maximum of (n-1)(n-2)/2 edges of the same weight
        so if the desired graph has m <= 1 + (n-1)(n-2)/2 edges all edges not in the MST have value 1
        */
        const ll limit = (n*n - 3*n + 4) / 2;
        
        //all edges have weight 1
        if(m <= limit) {
            cout << s + m - (n - 1) << endl;
            continue;
        }
		
        //edges in complete graph of n-1 nodes
        const ll max_edges = (n-1) * (n-2) / 2;
        
        ll result = 0;
		
		/*
		case m > limit: 
		result = sum for i=1..n-2 of (weight_i * i + weight_n-1 * (m-max_edges))
		assume weight_1 = 1, weight_2=1, .. weight_n-2=1, weight_n-1 = S-(n-2)  (else case)
		not legit for all MST sums, in other cases need to look at the MST sum and use
		that to compute the result (if case)
		*/
        if(max_edges - (n-2) * (m - max_edges) < 0) {
            ll div = s / (n-1);
            ll rem = s % (n-1);
            result = (m - max_edges) * (s - (n-2) * div) + max_edges * div;
            if(rem != 0)
                result = min(result, (div+1) * (m - max_edges) + max_edges * div + (rem-1) * (2 * n - rem - 2) / 2);  
        }
        else 
            result = (m - max_edges) * (s - (n - 2)) + max_edges;
        
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/minimum-mst-graph/problem