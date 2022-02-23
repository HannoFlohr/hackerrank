#include<bits/stdc++.h>
using namespace std;

const unsigned MOD = 1e9+7;
const unsigned MAXN = 3e5;

//https://en.wikipedia.org/wiki/Fenwick_tree
struct FenwickTree {
    vector<int> data ;
    int n;
    
    FenwickTree(int num) { n = num; data = vector<int>(n,0); }
    int low_bit(int i) { return i & (-i); }
    
    void update(int i, int v) {
        for(int j=i+1; j<=n; j += low_bit(j))
            data[j] += v;
    }
    
    int querry(int i) {
        int sum = 0;
        for(int j=i+1; j>=1; j -= low_bit(j))
            sum += data[j];
        return sum;
    }
};

int n, unknowns=0;
vector<int> a (MAXN+5), factorial(MAXN+5), prev_set (MAXN+5);
FenwickTree tree (MAXN+5);

//addition, subtraction and multiplying % MOD
int addMod(int a, int b) {
    a += b;
    return a>=MOD ? a-MOD : a;
}
int subMod(int a, int b) {
    a -= b;
    return a<0 ? a+MOD : a;
}
int multiplyMod(int a, int b) {
    return 1LL*a*b % MOD;
}

//computes n*(n-1)/2 % MOD
int combMod(int a) {
    return multiplyMod(multiplyMod(a, subMod(a,1)), (MOD+1)>>1);
}                                                

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    cin >> n;
    
    //read input, count unknowns and set up the vector counting the items set up to the current
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i]--;
        if(a[i] == -1) unknowns++;
        if(a[i] >= 0) prev_set[a[i]] = 1;
    }
    
    //compute factorials;
    factorial[0] = 1;
    for(int i=1; i<=n; i++) 
        factorial[i] = multiplyMod(i, factorial[i-1]);
    
    //update the previous set vector  
    for(int i=1; i<=n; i++)
        prev_set[i] += prev_set[i-1];
        
    int combinations = combMod(n);  
    for(int i=1; i<=n; i++) 
        if(a[i]!=-1)
            combinations = subMod(combinations, a[i]);
            
    int sum, result = 0, cur = 0;

    //use functionality of the fenwick tree to compute the result
    for(int i=1; i<=n; i++) {
        if(a[i] != -1) {
            sum = multiplyMod(factorial[unknowns], a[i] - tree.querry(a[i])); 
            if(unknowns >= 1)
                sum = subMod(sum, multiplyMod(factorial[unknowns-1],multiplyMod(cur, a[i]+1-prev_set[a[i]])));
            sum = multiplyMod(sum, factorial[n-i]);
            result = addMod(result, sum);
            tree.update(a[i], 1);
            combinations = subMod(combinations, subMod(n-1-a[i], subMod(prev_set[n-1], prev_set[a[i]])));
        }
        else {
            sum = multiplyMod(combinations, factorial[unknowns-1]);
            if(unknowns >= 2) 
                sum = subMod(sum, multiplyMod(factorial[unknowns-2], multiplyMod(cur, combMod(unknowns))));
            sum = multiplyMod(sum, factorial[n-i]);
            result = addMod(result, sum);
            cur++;
        }
    }  
    
    cout << addMod(result, factorial[unknowns]) << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/cards-permutation/problem