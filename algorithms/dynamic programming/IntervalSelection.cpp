#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;

class Interval{
public:
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

bool sortIntervalHelper(Interval i1, Interval i2) {
    return i2.end > i1.end;
}

int main()
{
    int s, n, start, end, count, end_point_1, end_point_2;
    cin >> s;
    while(s--) {
        cin >> n;

        vector<Interval> intervals;
        for(int i=0; i<n; i++) {
            cin >> start >> end;
            Interval newInterval (start,end);
            intervals.push_back(newInterval);
        }
            
        sort(intervals.begin(), intervals.end(), sortIntervalHelper);

        count = 0; end_point_1 = end_point_2 = -1;
        for(auto i : intervals) {
            if(i.start > end_point_2) {
                count++;
                end_point_2 = i.end;
            }
            else if(i.start > end_point_1) {
                count++;
                end_point_1 = end_point_2;
                end_point_2 = i.end;
            }
        }
        
        cout << count << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/interval-selection/problem