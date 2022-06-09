#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

struct Action{
ll x;
ull y;
char c; 
Action(ll _x, ull _y, char _c) {
    x = _x; y = _y; c = _c;
} 
};

bool compare_action(Action const& a1, Action const& a2) {
    if(a1.x == a2.x)
        return (a1.c < a2.c ? true : false);
    else
        return (a1.x < a2.x ? true : false);
}

vector<Action> sortActions(map<ll,ull> population, map<ll,ll> clouds) {
    vector<Action> actions;
    for(auto i:population) 
        actions.push_back( Action(i.first, i.second, 'P') );
    
    ll active_clouds = 0;
    for(auto i:clouds) {
        active_clouds += i.second;
        actions.push_back( Action(i.first, active_clouds, 'C') );
    }
        
    sort(actions.begin(), actions.end(), &compare_action);
    //for(auto a:actions)cerr<<a.x<<" "<<a.y<<" "<<a.c<<endl;
    return actions;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll n, m;
    cin >> n;
    
    //cities
    vector<ll> populations (n);
    vector<ll> city_locs (n);
    for(auto &i:populations)
        cin >> i;
    for(auto &i:city_locs)
        cin >> i;
    
    //clouds
    cin >> m;
    vector<ll> cloud_locs (m);
    vector<ll> ranges (m);
    for(auto &i:cloud_locs)
        cin >> i;
    for(auto &i:ranges)
        cin >> i;
    
     //map populations of cities to their locations
    map<ll,ull> population_at_loc;
    for(ll i=0; i<n; i++)
        population_at_loc[city_locs[i]] += populations[i];
    
    //map start and end of clouds to locations
    map<ll,ll> active_clouds_up_to;
    map<ll,ll> cloudend_starting_at;
    for(ll i=0; i<m; i++) { 
        active_clouds_up_to[cloud_locs[i] - ranges[i]]++;
        active_clouds_up_to[cloud_locs[i] + ranges[i] + 1]--;
        cloudend_starting_at[cloud_locs[i] - ranges[i]] = cloud_locs[i] + ranges[i] + 1;  
    } 
    
    vector<Action> actions = sortActions(population_at_loc, active_clouds_up_to);
    ll active_clouds = 0LL;
    ll cur_cloud = -1LL;
    map<ll,ull> cloudy_city;
    ull sunny_cities = 0ULL;
    for(auto a:actions) {
        if(a.c == 'C') {
            active_clouds = a.y;
            if(cur_cloud == -1 || (active_clouds == 1 && a.x >= cloudend_starting_at[cur_cloud]) )
                cur_cloud = a.x;
        }
        else if(active_clouds == 1)
            cloudy_city[cur_cloud] += a.y;
        else if(active_clouds == 0)
            sunny_cities += a.y;
    }
    
    ull max_cloudy_city = 0ULL;
    for(auto i = cloudy_city.begin(); i != cloudy_city.end(); i++) 
        max_cloudy_city = max(max_cloudy_city, i->second); 
    
    cout << max_cloudy_city + sunny_cities << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/cloudy-day/problem