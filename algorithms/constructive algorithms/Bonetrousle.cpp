#include <bits/stdc++.h>

using namespace std;
vector<string> split_string(string);

typedef unsigned long long int ll;

vector<ll> bonetrousle(ll n, ll k, int b) {
    vector<ll> results (0);
    
    ll min=0, max=0;
    for(int i=1; i<=b; i++) {
        min += i;
        max += k-b+i;
    }

    //if n is not in [min,max] there is no solution
    if(n>max || n<min) 
        return results;
    

    ll add = (n - min) / b; 
    if(add == 0) add = 1;
//cout<<"add "<<add<<" | " <<min<<" "<<max<<endl;
    ll sum = 0;
    for(int i=1; i<=b; i++) {
        results.push_back(i);
        sum += i;
    }
    while(sum != n) {
        for(int i=b-1; i>=0; i--) {
            if(results[i] + add <= k-b+1+i) {
                results[i] += add;
                sum += add;
            }
            else {
                sum += (k-b+1+i - results[i]);
                results[i] = k-b+1+i;
            }

            if(n - sum < add) add = n-sum; //cout << "new add "<<add<<endl;}

            if(sum >= n) break; 
        }
        //for(auto a:results)cout<<a<<" ";cout<<endl;cout << sum << endl;
        if(sum > n) {cerr<<"ERROR: sum>n"<<endl;exit(1);}
    }

    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nkb_temp;
        getline(cin, nkb_temp);

        vector<string> nkb = split_string(nkb_temp);

        ll n = stol(nkb[0]);

        ll k = stol(nkb[1]);

        int b = stoi(nkb[2]);

        vector<ll> result = bonetrousle(n, k, b);

        if(result.size() == 0) fout<<"-1"<<endl;
        else {
            for (int result_itr = 0; result_itr < result.size(); result_itr++) {
                fout << result[result_itr];

                if (result_itr != result.size() - 1) {
                    fout << " ";
                }
            }
            fout << "\n";
        }
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