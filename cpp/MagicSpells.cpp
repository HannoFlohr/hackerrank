

/* Enter your code here. Read input from STDIN. Print output to STDOUT */
//cout << SpellJournal::journal << endl;

if (Fireball *fb=dynamic_cast<Fireball*>(spell)) {
    fb->revealFirepower();
} 
else if (Frostbite *fz=dynamic_cast<Frostbite*>(spell)) {
    fz->revealFrostpower();
} 
else if (Thunderstorm *ts=dynamic_cast<Thunderstorm*>(spell)) {
    ts->revealThunderpower();
} 
else if (Waterbolt *wb=dynamic_cast<Waterbolt*>(spell)) {
    wb->revealWaterpower();
}
else { // generic spell
    string spellN = spell->revealScrollName();
    string spellJ = SpellJournal::read();
    int m=spellN.length();
    int n=spellJ.length();
    int array[m+1][n+1]; 

    // solve for LCS
    for (int i=0;i<=m;i++) array[i][0]=0;
    for (int j=0;j<=n;j++) array[0][j]=0;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (spellN[i-1] == spellJ[j-1])
                array[i][j]=array[i-1][j-1]+1;
            else
                array[i][j]=max(array[i][j-1],array[i-1][j]);
        }
    }  
    cout << array[m][n] << endl; 
}

