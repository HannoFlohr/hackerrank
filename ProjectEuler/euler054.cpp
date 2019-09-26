#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned long long int ull;

//representation of cards 2 to A in bitmask;
const ull card2 = 1ULL << 0;
const ull card3 = 1ULL << 1;
const ull card4 = 1ULL << 2;
const ull card5 = 1ULL << 3;
const ull card6 = 1ULL << 4;
const ull card7 = 1ULL << 5;
const ull card8 = 1ULL << 6;
const ull card9 = 1ULL << 7;
const ull cardT = 1ULL << 8;
const ull cardJ = 1ULL << 9;
const ull cardQ = 1ULL << 10;
const ull cardK = 1ULL << 11;
const ull cardA = 1ULL << 12;

//convert the card into a 52 bit mask
/*
    bit 0-12    D
    bit 13-25   H
    bit 26-38   S
    bit 39-51   C
*/
ull cardToMask(const string& card) {
    ull result = 0;

    switch(card[0]) {
        case '2' : result = card2; break;
        case '3' : result = card3; break;
        case '4' : result = card4; break;
        case '5' : result = card5; break;
        case '6' : result = card6; break;
        case '7' : result = card7; break;
        case '8' : result = card8; break;
        case '9' : result = card9; break;
        case 'T' : result = cardT; break;
        case 'J' : result = cardJ; break;
        case 'Q' : result = cardQ; break;
        case 'K' : result = cardK; break;
        case 'A' : result = cardA; break;
        default : break;
    }
    switch(card[1]) {
        case 'D' : break;
        case 'H' : result <<= 13; break;
        case 'S' : result <<= 26; break;
        case 'C' : result <<= 39; break;
        default : break;
    }

    return result;
}

/*
Royal Flush     1
Straight Flush  2..10
Quadruplet      10000000000 + 100 * quad + single
Full House      10000000000 + 100 * trip + pair
Flush           10000000000 + 100000000 * highest + 1000000 * second + 10000 * third + 100 * fourth + lowest
Straight        10000000000 + 1..10
Triplet         10000000000 + 10000 * trip + 100 * highest single + single
Two Pairs       10000000000 + 10000 * high pair + 100 * low pair + single
Pair            10000000000 + 1000000 * pair + 10000 * highest single + 100 * mid single + low single
High Card       10000000000 + 100000000 * highest + ... + lowest
*/
ull handValue(ull hand) {
    //set lowest 13 bits
    const ull suit = (1LL << 13) - 1;
    const ull size = 10000000000ULL;
    ull result = 0;

//check for straight
    //card values ignoring suits
    ull straightcheck = (hand | (hand >> 13) | (hand >> 26) | (hand >> 39)) & suit;
    ull straight = 0;
    if(straightcheck == (cardT | cardJ | cardQ | cardK | cardA)) straight = 1;
    if(straightcheck == (card9 | cardT | cardJ | cardQ | cardK)) straight = 2;
    if(straightcheck == (card8 | card9 | cardT | cardJ | cardQ)) straight = 3;
    if(straightcheck == (card7 | card8 | card9 | cardT | cardJ)) straight = 4;
    if(straightcheck == (card6 | card7 | card8 | card9 | cardT)) straight = 5;
    if(straightcheck == (card5 | card6 | card7 | card8 | card9)) straight = 6;
    if(straightcheck == (card4 | card5 | card6 | card7 | card8)) straight = 7;
    if(straightcheck == (card3 | card4 | card5 | card6 | card7)) straight = 8;
    if(straightcheck == (card2 | card3 | card4 | card5 | card6)) straight = 9;
    if(straightcheck == (cardA | card2 | card3 | card4 | card5)) straight = 10;

//check for pairs, triplets, quadruplets
    int count[13];
    memset(count,0,sizeof(count));
    for(int i=0; i<13; i++) {
        if(hand & (1ULL << i)) count[i]++;
        if(hand & (1ULL << (i+13))) count[i]++;
        if(hand & (1ULL << (i+26))) count[i]++;
        if(hand & (1ULL << (i+39))) count[i]++;
    }

//check for flush
    bool flush = (hand == straightcheck) || (hand == straightcheck << 13) || (hand == straightcheck << 26) || (hand == straightcheck << 39);

//royal flush & straight flush
    if(flush && straight>0)
        return result + straight;
    result += size;

//quadruplets
    for(int i=0; i<13; i++)
        if(count[i] == 4)
            for(int j=0; j<13; j++)
                if(count[j] == 1)
                    return result + (13-i) * 100 + (13-j);
    result += size;

//full house
    for(int i=0; i<13; i++)
        if(count[i] == 3)
            for(int j=0; j<13; j++)
                if(count[j] == 2)
                    return result + (13-i) * 100 + (13-j);
    result += size;

//flush
    if(flush) {
        ull value = 0ULL;
        for(int i=12; i>=0; i--)
            if(count[i] == 1) {
                value *= 100;
                value += 13-i;
            }
        return result + value;
    }
    result += size;

//straight
    if(straight > 0)
        return result + straight;
    result += size;

//triplet
    for(int i=0; i<13; i++) 
        if(count[i] == 3) {
            ull value = 13-i;
            for(int j=12; j>=0; j--) 
                if(count[j] == 1) {
                    value *= 100;
                    value += 13-j;
                }
            return result + value;
        }
    result += size;

//pair(s)
    int pairs = 0;
    for(int i=0; i<13; i++) 
        if(count[i] == 2)
            pairs++;
    if(pairs > 0) {
        ull value = 0;
        //value of pair(s)
        for(int i=12; i>=0; i--)
            if(count[i] == 2) {
                value *= 100;
                value += 13-i;
            }
        //value of single cards
        for(int i=12; i>=0; i--) 
            if(count[i] == 1) {
                value *= 100;
                value += 13-i;
            }
        
        if(pairs == 1)
            result += size;
        return result + value;
    }

    //increment for one and two pairs
    result += 2 * size;

//high card
    ull value = 0;
    for(int i=12; i>=0; i--)
        if(count[i] == 1) {
            value *= 100;
            value += 13-i;
        }
    return result + value;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string player1[5], player2[5];
        cin >> player1[0] >> player1[1] >> player1[2] >> player1[3] >> player1[4];
        cin >> player2[0] >> player2[1] >> player2[2] >> player2[3] >> player2[4];

        //set bitmask for all cards of each player
        ull player1mask = cardToMask(player1[0]) |  cardToMask(player1[1]) | cardToMask(player1[2]) | cardToMask(player1[3]) | cardToMask(player1[4]);
        ull player2mask = cardToMask(player2[0]) |  cardToMask(player2[1]) | cardToMask(player2[2]) | cardToMask(player2[3]) | cardToMask(player2[4]);

        //get value for hand of each player;
        ull player1value = handValue(player1mask);
        ull player2value = handValue(player2mask);

        if(player1value < player2value) cout << "Player 1" << endl;
        else cout << "Player 2" << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler054/