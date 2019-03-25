#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int n;

//length of edges in step i
vector<int> a;
//count of nodes after step i
vector<int> nodesCount; 
//longestPath in graph after eacg step i
vector<int> longestPath;  
//sum of all paths ending in a corner of the current level
vector<int> sumOfPaths;
//total sum after each step i
vector<int> sum;

int addMod(int a, int b) {
    return static_cast<int>((0L + a + b) % MOD);
}

int multiplyMod(int a, int b) {
    return static_cast<int>((1L * a * b) % MOD);
}

void solve() {
    nodesCount = vector<int>(n+1);
    longestPath = vector<int>(n+1);  
    sumOfPaths = vector<int>(n+1);
    sum = vector<int>(n+1);
    nodesCount[0] = 1;
    longestPath[0] = 0;
    sumOfPaths[0] = 0;
    sum[0] = 0;
    int nCp, lPp, sOPp, helper;
    for(int i=1; i<=n; i++) {
        nCp = nodesCount[i-1];
        lPp = longestPath[i-1];
        sOPp = sumOfPaths[i-1];
		//nodesCount[i] = 4 * nodescount[i-1] + 2; nodesCount[0] = 1
        nodesCount[i] = addMod( multiplyMod(4,nCp), 2);
		//longestPath[i] = 3 * a[i] + 2 * longestPath[i-1]; longestPath[0] = 3 * a[0];
        longestPath[i] = addMod( multiplyMod(3,a[i]), multiplyMod(2,lPp));
		//sOP[i] = 4*sOP[i-1] + 3*a[i] + 2*longestPath[i-1] + nodesCount[i-1] * (8*a[i] + 3 * longestPath[i-1])
        sumOfPaths[i] = multiplyMod(4,sOPp);
        sumOfPaths[i] = addMod(sumOfPaths[i],multiplyMod(3,a[i]));
        sumOfPaths[i] = addMod(sumOfPaths[i],multiplyMod(2,lPp));
        helper = addMod(multiplyMod(8,a[i]),multiplyMod(3,lPp));
        sumOfPaths[i] = addMod(sumOfPaths[i],multiplyMod(nCp, helper));
        
        //sum[i] = a[i] + 4*sum[i-1] + 8*sOPp + 12*a[i]*nCp + 12*nCp*sOPp 
        //              + 16*a[i]*nCp^2
        sum[i] = addMod(a[i],multiplyMod(4,sum[i-1]));
        sum[i] = addMod(sum[i], multiplyMod(8,sOPp));
        helper = multiplyMod(12,nCp);
        sum[i] = addMod(sum[i],multiplyMod(helper,a[i]));
        sum[i] = addMod(sum[i],multiplyMod(helper,sOPp));
        helper = multiplyMod(nCp,nCp);
        helper = multiplyMod(helper,a[i]);
        helper = multiplyMod(helper,16);
        sum[i] = addMod(sum[i],helper);
    }
}

int main()
{
    cin >> n;
    a = vector<int>(n+1);
    a[0] = 0;
    for(int i=1; i<=n; i++) 
        cin >> a[i];
    
    solve();
    cout << sum[n] << endl;
    return 0;
}
