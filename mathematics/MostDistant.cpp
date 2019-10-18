#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    //find min and max for x and y of the input dots
    double x, y, xmin=0, xmax=0, ymin=0, ymax=0;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        if(x==0) {
            ymin = min(ymin, y);
            ymax = max(ymax, y);
        }
        else {
            xmin = min(xmin, x);
            xmax = max(xmax, x);
        }
    }

    //find max distance
    //first check distance on axes
    double maxDist = max(abs(xmax-xmin), abs(ymax-ymin));
    //check length of hypothenuses (h=sqrt(x^2+y^2))
    maxDist = max(maxDist, sqrt(xmax*xmax+ymax*ymax));
    maxDist = max(maxDist, sqrt(xmax*xmax+ymin*ymin));
    maxDist = max(maxDist, sqrt(xmin*xmin+ymax*ymax));
    maxDist = max(maxDist, sqrt(xmin*xmin+ymin*ymin));

    printf("%.10f",maxDist);
    return 0;
}
//https://www.hackerrank.com/challenges/most-distant/problem