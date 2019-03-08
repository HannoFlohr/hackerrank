#include <bits/stdc++.h>

using namespace std;

int pageCount(int n, int p) {
    int front = 0;
    front += p/2;

    int back = 0;
    if(p%2!=0 && n-p == 1) back += 1;
    else back += (n-p)/2;
    
    return min(front,back);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
