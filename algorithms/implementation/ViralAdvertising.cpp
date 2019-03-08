#include <bits/stdc++.h>

using namespace std;

int viralAdvertising(int n) {
    int shared=5, liked=2, cum=2;
    if(n==1) return cum;
    for(int i=1; i<n; i++) {
        shared = floor(shared/2) * 3;
        liked = floor(shared/2);
        cum += liked;
    }
    return cum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
