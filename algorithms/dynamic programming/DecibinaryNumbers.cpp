#include <bits/stdc++.h>

using namespace std;

const int LIMIT_DIM = 19;
const int N = 285112+3;
              
vector<vector<long long>> d;
vector<long long> add;

void fillD() {
    long long helper;
    for(long long i=0; i<=LIMIT_DIM; i++) { 
        for(long long j=0; j<=N; j++) { 
            if(i==0) {
                if(j==0) d[i][j] = 1;
                else d[i][j] = 0;
            }
            else {
                for(long long k=0; k<10; k++) {
                    helper = j - k * (1LL << (i-1LL));  
                    if(helper >=0) 
                        d[i][j] += d[i-1][helper];   
                }
            }
        }
    }
}

void fillAdd() {
    long long sum=0;
    for(long long i=0; i<add.size(); i++) {
        sum += d[LIMIT_DIM][i];
        add[i] = sum;
    }
}

long long decibinaryNumbers(long long x) { 

    auto a = lower_bound(add.begin(), add.end(), x);
    long long pos_x = (long long)(a - add.begin());
    long long before = x;
    if(pos_x != 0) before -= add[pos_x-1];   

    long long j;
    long long counter, prev_counter;
    long long result = 0LL;
    for(long long i=LIMIT_DIM; i>=1; i--) { 
        j=-1LL;
        counter = 0LL;
        while(counter < before) {
            j++;
            prev_counter = counter; 
            counter += d[i-1][pos_x - j *(1 << (i-1) ) ];
        }
        result += j * (long long)pow(10LL,i-1LL);

        pos_x -= j * (1LL << (i-1));
        before -= prev_counter;
    }

    return result;
}

int main()
{
    //compute d and c only once in the beginning
    d = vector<vector<long long>>(LIMIT_DIM+1, vector<long long>(N+1)); 
    add = vector<long long>(N+1);
    fillD();
    fillAdd();

    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long long x;
        cin >> x;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long result = decibinaryNumbers(x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
