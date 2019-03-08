#include <bits/stdc++.h>

using namespace std;

long flippingBits(long n) {
    vector<int> v (32,0);
    string binary = bitset<32>(n).to_string();
    for(int i=0; i<32; i++) {
        v[i] = binary[i] - '0'; 
        if(v[i]==0) v[i] = 1;
        else v[i] = 0;
    }
    
    long result = 0L;
    for(int i=31; i>=0; i--) {
        result += v[i] * pow(2,31-i);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
