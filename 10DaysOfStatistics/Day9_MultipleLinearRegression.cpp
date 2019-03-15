#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
using namespace std;

vector<vector<double>> transpose(const vector<vector<double>> &v) {
    int n = v.size();
    int m = v[0].size();
    vector<vector<double>> t = vector<vector<double>>(m, vector<double>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            t[i][j] = v[j][i];
    return t;
}

vector<vector<double>> multiply(const vector<vector<double>> &a, const vector<vector<double>> &b) {
    assert(a[0].size() == b.size());
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    vector<vector<double>> c = vector<vector<double>>(n, vector<double>(p));

    double sum;
    for(int i=0; i<n; i++) {
        for(int j=0; j<p; j++) {
            sum = 0.0;
            for(int k=0; k<m; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }

    return c;
}

//returns inverse of 3x3 matrix a
vector<vector<double>> inverse3(const vector<vector<double>> &a) {
    assert(a.size() == 3 && a[0].size() == 3);
    int n = 3;
    
    double determinant = 0;
    for(int i=0; i<n; i++)
        determinant += (a[0][i] * (a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][(i+2)%3] * a[2][(i+1)%3]));
    
    vector<vector<double>> inv = vector<vector<double>>(n, vector<double>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            inv[i][j] = ((a[(j+1)%3][(i+1)%3] * a[(j+2)%3][(i+2)%3]) - (a[(j+1)%3][(i+2)%3] * a[(j+2)%3][(i+1)%3])) / determinant;

    return inv;
}

void swap_row(vector<double> *x, vector<double> *y) {
    double temp;
    for(int i=0; i< x->size(); i++){
        temp = (*x)[i];
        (*x)[i] = (*y)[i];
        (*y)[i] = temp;
    }
}

//returns inverse of nxn matrix a
vector<vector<double>> inverse(vector<vector<double>> a) {
    int n = a.size();
    double factor;
    vector<vector<double>> res(n, vector<double>(n,0));
    for(int i=0; i<n; i++)
        res[i][i] = 1.0;
    
    //convert to row-echelon form
    for(int j=0; j<n-1; j++) {
        if(a[j][j]==0) 
            for(int i=j+1; i<n; i++) {
                if(a[i][j]!=0) {
                    swap_row(&a[j],&a[i]);
                    swap_row(&res[j],&res[i]);
                    break;
                }
            }
        if(a[j][j]==0)
            continue;
        for(int i=j+1; i<n; i++) {
            factor = -a[i][j] / a[j][j];
            for(int k=0; k<n; k++) {
                a[i][k] += factor * a[j][k];
                res[i][k] += factor * res[j][k];
            }
        }
    }
    //convert to diagonal form
    for(int i=n-1; i>0; i--) {
        for(int j=i-1; j>=0; j--) {
            factor = -a[j][i] / a[i][i]; 
            for(int k=0; k<n; k++){
                a[j][k] += factor * a[i][k];
                res[j][k] += factor * res[i][k];
            }
        }
    }
    //converting to unit
    for(int i=0; i< n; i++)
        for(int j=0; j <n; j++)
            res[i][j] /= a[i][i];
    
    return res;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<double>> y = vector<vector<double>>(n, vector<double>(1));    
    vector<vector<double>> x = vector<vector<double>>(n, vector<double>(m+1));
    for(int i=0; i<n; i++) { 
        x[i][0] = 1; 
        for(int j=0; j<=m; j++) {
            if(j<m) cin >> x[i][j+1];
            else cin >> y[i][0]; 
        }
    }
    vector<vector<double>> t = transpose(x);

    vector<vector<double>> res = multiply(t,x);
    res = inverse(res);
    res = multiply(res,t);
    res = multiply(res,y);

    int queries;
    double result;
    double values [m];
    cin >> queries;
    while(queries--) {
        for(int i=0; i<m; i++)
            cin >> values[i];

        result = res[0][0];
        for(int i=1; i<=m; i++)
            result += values[i-1] * res[i][0];
        
        cout<<fixed<<setprecision(2)<< result << endl;
    }
    

    return 0;
}
