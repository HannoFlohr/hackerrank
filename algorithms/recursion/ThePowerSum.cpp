#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
int powerSum(int X, int N, int base) { 
    int cur = pow(base,N);
    if(cur<X)
        return powerSum(X,N,base+1) + powerSum(X-cur,N,base+1);
    else if(cur==X)
        return 1;
    else    
        return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N, 1);

    fout << result << "\n";

    fout.close();

    return 0;
}
