#include <bits/stdc++.h>

using namespace std;

map<char,int> makeMap(const string& s){
    map<char,int> m;
    for(auto c : s) {
        m[c]++;
    }
    return m;
}

int makeAnagram(string a, string b) {
    map<char,int> mapA, mapB;
    mapA = makeMap(a);
    mapB = makeMap(b);

    int both = 0;
    for(auto m : mapA) {
        if( mapB[m.first]>0 ) {
            while( mapB[m.first] > 0 && m.second >0 ) {
                mapB[m.first]--;
                m.second--;
                both++;
            }
        }
    }

    return (a.size()-both + b.size()-both);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
