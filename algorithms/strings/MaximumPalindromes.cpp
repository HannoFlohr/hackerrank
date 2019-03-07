#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const long long m = 1000000007LL;
const long long limit = 100001; // 1<=s<=10^5

string input;
long long factorials [limit];
long long modularMultiplicativeInverses [limit];
vector<vector<long long>> freq;

long long exponentiationBySquaring(long x, long long n) {
    if (n == 0) return 1;
    if (n & 1) return exponentiationBySquaring(x, n - 1) * x % m;
    else {
        long long p = exponentiationBySquaring(x, n / 2);
        return p * p % m;
    }
}

void initialize(string s) {
    input = s;

    //precompute the frequencies for each char of the string
    freq = vector<vector<long long>>(s.size(), vector<long long>(26,0));
    int cur;
    for (int j = 0; j < 26; j++) {
        if (s[0]-'a' == j) freq[0][j] = 1;
    }
    for (unsigned int i = 1; i < s.size(); i++) {
        cur = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            if (cur == j) freq[i][j] = freq[i - 1][j] + 1;
            else freq[i][j] = freq[i - 1][j];
        }
    }

    //initialize array of factorials and their modular multiplicative inverses
    factorials[0] = 1;
    modularMultiplicativeInverses[0] = 1;
    for (int i = 1; i<limit ; i++) {
        factorials[i] = factorials[i - 1] * i % m;
        modularMultiplicativeInverses[i] = (long long)exponentiationBySquaring(factorials[i], m - 2LL);
    }
}

long long answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    
    vector<long long> subfreq (26,0);
    for (unsigned int i = 0; i < 26; i++) {
        if (l == 1) subfreq[i] = freq[r - 1][i]; 
        else subfreq[i] = freq[r - 1][i] - freq[l - 2][i];
    }
    long long sum = 0, odd = 0, res = 1;
    for (int i = 0; i < 26; i++) {
        sum += (long long)subfreq[i] / 2LL;
        odd += (long long)subfreq[i] % 2LL;
        res = res * modularMultiplicativeInverses[subfreq[i] / 2] % m;
    }

    res = res * max(1LL, odd) % m;
    return res * factorials[sum] % m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        long long result = answerQuery(l, r);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
