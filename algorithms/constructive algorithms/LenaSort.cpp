#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAXLENGTH 100000
vector<ll> lowerBounds (MAXLENGTH+1);
vector<ll> result (MAXLENGTH+1);

void setLowerBounds() {
    ll n = MAXLENGTH;
    lowerBounds[0] = 0;
    for(ll i=1; i<=n; i++) {
        if(i % 2 == 1) 
            lowerBounds[i] = (i-1) + (2 * lowerBounds[ floor( i/2 ) ] );
        else 
            lowerBounds[i] = (i-1) + lowerBounds[ i/2 ] + lowerBounds[ (i-1)/2 ];
    }
}

ll getUpperBound(const ll &n) {
    return n * (n-1LL) / 2LL;
}

//returns true if a solution for length n and c comparisons is possible
bool check(ll n, ll c) {
    if(lowerBounds[n] <= c && c <= getUpperBound(n))
        return true;
    else 
        return false;
}

void solve(ll x, ll y, ll c, ll left, ll right) {
    if(x > y) return;

    assert( check(y - x + 1, c) );

    ll dif = y - x;
    c -= dif;
    while(dif>=0 && check(dif, c)) {
        result[left++] = x++;
        c -= --dif;
    }
    if(dif>0) {
        ll mid = (x + y + 1) / 2;
        while( !check(y - mid, c - lowerBounds[mid - x] ) )
            mid--;
        assert(mid > x);

        result[left] = mid;
        solve(x, mid-1, lowerBounds[mid - x], left+1, left + mid - x); 
        solve(mid+1, y, c - lowerBounds[mid - x], left + mid - x+1, right);
    }
}

int main()
{
    setLowerBounds();

    ll q, length, comparisons;
    cin >> q;
    while(q--) {
        cin >> length >> comparisons;
        if( !check(length,comparisons) )
            cout << -1 << endl;
        else {
            solve(1,length,comparisons,1,length);
            for(ll i=1; i<=length; i++)
                cout << result[i] << " ";
            cout << endl;
        }
    }

    return 0;
}



/*  ---- FIRST TRY - 2/12, rest wrong answer



vector<int> lowerBounds (MAXLENGTH+1);

void setLowerBounds() {
    int n = MAXLENGTH;
    lowerBounds[0] = 0;
    for(int i=1; i<=n; i++) {
        if(i % 2 == 1) 
            lowerBounds[i] = (i-1) + (2 * lowerBounds[ floor( i/2 ) ] );
        else 
            lowerBounds[i] = (i-1) + lowerBounds[ i/2 ] + lowerBounds[ (i/2)-1 ];
    }
}

int getUpperBound(const int &n) {
    return n * (n-1) / 2;
}

vector<int> combine(vector<int> less, int pivot, vector<int> more) {
    less.push_back(pivot);
    less.insert(less.end(), more.begin(), more.end());
    return less;
}

int selectPivotPos(const int &n, const int &c, int &c1, int& c2) {
    c1 = c, c2 = 0;
    int pos = -1;
    while(c1>=c2) {
        if(lowerBounds[c1+1] <= c1 && lowerBounds[c2+1] <= c2) {
            pos = c1;
            return pos;
        }
        c1--;
        c2++;
    }
    
    return pos;
}

vector<int> solve(int n, int c, vector<int> v) {
    if(c==0) return v;
    
    int upperBound = getUpperBound(n);
    int lowerBound = lowerBounds[n];
//cout << lowerBound << " " << upperBound << " bounds" <<endl;
    int pivot, half;
    vector<int> less (0);
    vector<int> more (0);

    //if not possible to sort with c comparisons
    if(c < lowerBound || c > upperBound) 
        return less;
    //lower bound comparisons case
    if(c == lowerBound && c>1) {
        pivot = v[0];
        half = (n-1) / 2;
        for(int i=1; i<=half; i++) {
            less.push_back(v[i]);
            more.push_back(v[half+i]);
        }
        return combine(less,pivot,more);
    }
    //upper bound comparisons case
    else if(c == upperBound) {
        for(int i=n-1; i>=0; i--) 
            less.push_back(v[i]);
        return less;
    }
    //lowerBound < c < upperBound
    else {
        //we always do lower Bound comparisons
        //so in less and more we need n-lowerbound comparisons
        int cRemain = c - lowerBound;
        int c1, c2;
        int pivotPos = selectPivotPos(n,cRemain,c1,c2);
        if(pivotPos==-1){cout<<"Error with pivot pos."<<endl;exit(1);}
        pivot = v[0];
        //cout<<"pp "<<pivotPos<<endl;

        for(int i=1; i<=pivotPos+1; i++)
            less.push_back(v[i]);
        for(int i=pivotPos+2; i<v.size(); i++)
            more.push_back(v[i]);

        return combine(solve(less.size(),c1,less), 
                        pivot, 
                        solve(more.size(),c2,more) );
    }

    return less;
}

int main()
{
    int q, length, comparisons;
    cin >> q;

    setLowerBounds();

    while(q--) {
        cin >> length >> comparisons;
        
        //if no comparisons, print first n integers
        if(comparisons==0) {
            for(int i=1; i<=length; i++) 
                cout << i << " ";
            cout << endl;
        }
        else {
            vector<int> v (0);
            for(int i=1; i<=length; i++)
                v.push_back(i);
            v = solve(length,comparisons,v);
            if(v.size() == 0) 
                cout << -1;
            else 
                for(auto a:v) 
                    cout << a<<" ";
            cout<<endl;
        }
    }

    return 0;
}
*/