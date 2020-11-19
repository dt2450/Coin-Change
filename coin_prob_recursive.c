#include <stdio.h>
#include <string.h>
#include <stdlib.h>


unsigned long long getWays(long n, int c_size, long int* c){
    unsigned long long total_ways = 0;
    for(int i = 0; i < c_size; i++) {
        if(c[i] > n) {
            break;
        }
        long value = n - c[i];
        
        if(value == 0) {
            total_ways++;
            break;
        } else if( value < 0) {
            break;
        } else {
            
            total_ways += getWays(value, c_size - i, c + i);

        }
    }
    return total_ways;
}


int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
    
    printf("Available coin denominations: \n");
    for(int i = 0; i < m; i++) {
        printf("%ld ", c[i]);
    }
    printf("\n");
    
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    unsigned long long ways = getWays(n, m, c);
    printf("Number of ways of making change for %d cents is %llu\n", n, ways);
    
    return 0;
}
