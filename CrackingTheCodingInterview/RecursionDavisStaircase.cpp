#include <bits/stdc++.h>

using namespace std;

int stepPerms(int n) {
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    
    deque<int> perms = {1,2,4};
    int i=4;
    int perm;

    while(i<=n) {
        perm = perms[2] + perms[1] + perms[0];
        perms.pop_front();
        perms.push_back(perm);
        i++;
    }
    return perms[2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
