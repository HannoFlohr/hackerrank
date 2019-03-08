#include <bits/stdc++.h>

using namespace std;

int findDigits(int n) {
    int digits = 0;
    int d, m=n;
    while(m>0) {
        d = m%10;
        if(d>0 && n%d==0) digits++; 
        m /= 10;
    }
    return digits;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
