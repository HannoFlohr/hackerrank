#include <bits/stdc++.h>

using namespace std;

long strangeCounter(long t) {
    long timer_max = 3;
    long sum = 0;
    for(int i=0; ;i++) {
        if(sum+timer_max >= t) break;
        sum += timer_max;
        timer_max *= 2;
    }

    t -= sum +1;
    return timer_max-t;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
