#include <bits/stdc++.h>

using namespace std;

string primality(int n) { cout << n << endl;
    if(n==2) return "Prime";
    else if(n==1 || (n%2==0 && n!=2) ) return "Not prime";
    int s=sqrt(n);
    
    for(int i=3; i<=s; i++) {
        if(n%i==0) return "Not prime";
    }
    
    return "Prime";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
