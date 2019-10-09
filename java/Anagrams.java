

    // Complete the function
    static boolean isAnagram(String a, String b) {
        if(a.length() != b.length())
            return false; 
        
        int frequencyA [] = new int[26];
        int frequencyB [] = new int[26];

        for(int i=0; i<26; i++) {
            frequencyA[i]=0;
            frequencyB[i]=0;
        }

        //'a'=97 'A'=65 -> -32
        for(int i=0; i<a.length(); i++) {
            int c = a.charAt(i);
            if(c > 96) c -= 32;
            c -= 65;
            frequencyA[c]++;

            c = b.charAt(i);
            if(c > 96) c -= 32;
            c -= 65;
            frequencyB[c]++;
        }

        for(int i=0; i<26; i++) 
            if(frequencyA[i] != frequencyB[i])
                return false;
        
        return true;
    }