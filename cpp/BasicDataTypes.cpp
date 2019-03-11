#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char ch;
    float f;
    double d;    
    scanf("%d %ld %c %f %lf", &i, &l, &ch, &f, &d);

    printf("%d", i);
    printf("\n%ld", l);
    printf("\n%c", ch);
    printf("\n%f", f);
    printf("\n%lf", d);
    return 0;
}

