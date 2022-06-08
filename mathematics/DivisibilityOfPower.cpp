#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAXN = 200000; 
vector<ll> A (MAXN+1);

//calculates (a*b) % mod, taking into account that (a*b) might overflow
ll mulMod(ll a, ll b, ll mod) {
    ll x = 0; 
    a %= mod;
    while (b) {
        if (b & 1) {
            x += a;
            if(x>=mod) x -= mod;
        }
        a <<= 1;
        if(a>=mod) a -= mod;
        
        b >>= 1;
    }
    return x;
}

bool solve(int i, int j, int k) {
    if(i>j)
        return k <= 1;
        
    ll x = 1;
    int new_k = 0;
    
    while(x<k) {
        if(x <= LLONG_MAX / A[i])
            x *= A[i];
        else 
            x = LLONG_MAX;
        
        new_k++;
    }
    
    return solve(i+1, j, new_k);
}

/*
x can be factorized as p1^e1 * p2^e2 * p3^e3 * ...
for x to divide find(i,j), A must contain such factors p1,p2,p3,...

x <= 10^16 <= 2^54
so if find(i,j) = k is greater than/equal to 54 the answer will be "No"  

(1) check if there exists a power A[i]^k that is divided by x, with k<54
(2) count the amount of values from A[i+1] to A[j], stopping when the current A[_]<=1
(3) check the A[_] in that range if a valid result can be found 
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,q,i,j,k;
    ll x,result;
    bool check;
    string results = "";
    
    cin >> n;
    for(int i=1; i<=n; i++) cin >> A[i];
    
    cin >> q;
    while(q--) {
        cin >> i >> j >> x;
        
        check = true;
        
        if(A[i] != 0) {
            if(j>i && A[i+1] == 0) { 
                if(x>1)
                    check = false;
            }
            else {
                k=0;
                result = 1;
                
                while(k<=53 && result%x != 0) {
                    result = mulMod(result, A[i], x);
                    k++;
                }
                
                if(k==54)
                    check = false;
                else {
                    int length = 0;
                    for(int cur=i+1; cur<=j && A[cur]>1; cur++)
                        length++;
                    
                    if(length+i+1 <= j && A[length+i+1]==0)
                        length--;
                    if(length<4 && !solve(i+1, i+length, k))
                        check = false;
                }
            }
        }
        
        check==true ? results+="Yes\n" : results+="No\n";
    }
    cout << results << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/divisibility-of-power/problem