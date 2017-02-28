// Author: Dhruv Pachauri,13117022

#include <bits/stdc++.h>

#define SIZE 50
#define debug(x) {cout << #x << " : " << x << endl ;}
using namespace std;

int main(){
    
    int a[SIZE] = {396, 549, 22, 819, 611, 972, 730, 638, 978, 342, 566, 514, 752, 
                   871, 911, 172, 488, 542, 482, 974, 210, 474, 66, 387, 1, 872, 799, 
                   262, 567, 113, 578, 308, 813, 515, 716, 905, 434, 101, 632, 450, 
                   74, 254, 1000, 780, 633, 496, 513, 772, 925, 746};

    int signs[SIZE] = {0};
    int dp[SIZE] = {1};
    // we have to find the longest zig zag sequence till i
    for(int i=1;i<SIZE;i++){
        /* 
        * For each i, we should figure out the previous element to jump from.
        * it can be the one right before i or it could be element at index 0.
        * so we have to go all the way from i-1 down to 0.
        */
        
        for(int j = i-1; j>=0; j--){
            /* 
            * What's most important is.. we cannot jump from any element.. 
            * we are looking for an element which when subtracted from this 
            * has the desired sign. variable sign indicates whether the previous 
            * was a positive jump or a negative jump. 
            */
            
            int sign = signs[j];
            
            if( (sign == 0) || ( (sign < 0) && (a[i] - a[j] > 0) ) || 
                    ( (sign > 0) && (a[i] - a[j] < 0) ) ){
                 /*
                 The different cases.
                 1. sign == 0 : We are just beginning.. we can pick either 
                        positive difference or negative difference.
                        
                 2. (sign < 0) && (a[i] - a[j] > 0) : Previous value resulted in a negative 
                        difference, so we need to pick a positive differencevalue
                 3. (sign > 0) && (a[i] - a[j] < 0) : Previous value resulted in a positive 
                        difference, pick negative difference this time.
                 Once we have found an element, store the difference in signs, so that it 
                 helps in subsequent iterations.
                */
                dp[i] = dp[j] + 1;
                
                signs[i] = a[i] - a[j];
                break;
            }
        }
    }

    cout << dp[SIZE-1] << endl;
    return 0;
}