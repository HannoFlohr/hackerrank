'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function isVowel(c) {
    return 'aeiou'.indexOf(c) !== -1;
}

/*
 * Complete the vowelsAndConsonants function.
 * Print your output using 'console.log()'.
 */
function vowelsAndConsonants(s) {
    let c = [];
    for (const a of s) {
        if (isVowel(a))
            console.log(a);
        else
            c.push(a);
    }
    for (const a of c)
        console.log(a);
}


function main() {
    const s = readLine();
    
    vowelsAndConsonants(s);
}