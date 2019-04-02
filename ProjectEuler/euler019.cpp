#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

//https://en.wikipedia.org/wiki/Zeller%27s_congruence
//algorithm to compute the weekday for a given year, month and day
//return values are the weekdays, with sunday=0 ... saturday=6
ll dayOfTheWeek(ll year, ll month, ll day) {
    if(month < 3) {
        month += 12;
        year--;
    } 
    ll q = day;
    ll m = month;
    ll k = year % 100;
    ll j = year / 100;
    return (q + 13*(m+1)/5 + k + k/4 + j/4 + 5*j) % 7;
}

int main() {
    ll t, y1, y2, m1, m2, d1, d2, year, month, day, sundaysOnFirst;
    cin >> t;
    while(t--) {
        cin >> y1 >> m1 >> d1;
        cin >> y2 >> m2 >> d2;
        sundaysOnFirst = 0;
        if(d1 > 1) {
            if(m1==12) {
                m1 = 1;
                y1++;
            }
            else 
                m1++;
        }

        for(year=y1; year<=y2; year++) {
            for(month=1; month<=12; month++) {
                if(year==y1 && month < m1) continue;
                if(year==y2 && month > m2) break;

                if(dayOfTheWeek(year,month,1) == 1) 
                    sundaysOnFirst++;
            }
        }

        cout << sundaysOnFirst << endl;
    }
    return 0;
}
