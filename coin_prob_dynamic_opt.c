#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
unsigned long long **change_ways_array = NULL;

void print_change_ways_array(long n, int c_size) {
    printf("-----\n");
    for(int i = 0; i < c_size; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lld ", change_ways_array[i][j]);
        }
        printf("\n");
    }
    printf("-----\n");
}
#endif

unsigned long long getWays(long n, int c_size, long int* c){
    unsigned long long total_ways = 0;
    unsigned long long ways_n[n + 1];

    memset(ways_n, 0 , sizeof(ways_n));
    
    /* this is needed esp. for values of n when it is same as the
     * value of the coin denomination.
     */
    ways_n[0] = 1;
    

    /* Reversed the order of the loops.
     * Inner loop is on n and outer loop is on coin denominations
     */
    for(int i = 0; i < c_size; i++) {
        for(long curr_n = 0; curr_n <= n; curr_n++) {
            if(c[i] <= curr_n) {
#if 0
            total_ways = 0;
            if (c[i] > curr_n) {
                break;
            }
            if(c[i] == curr_n) {
                total_ways++;
            } else {
                unsigned long long remaining = curr_n - c[i];

                for(int j = i; j < c_size; j++) {
                    total_ways += change_ways_array[j][remaining - 1];
                }
            }
            change_ways_array[i][curr_n - 1] = total_ways; 
            
            ways_n[curr_n - 1] += total_ways;
#endif
            ways_n[curr_n] += ways_n[curr_n - c[i]];
            }
        }
    }
#if 0
    for(int k = 0; k < n; k++) {
        //printf("%lld ", ways_n[k]);
    }
    printf("\n");
#endif
    return ways_n[n];
}


int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
#if 0 
    change_ways_array = (unsigned long long **)malloc
        (sizeof(unsigned long long *)*m);

    for(int i = 0; i < m; i++) {
        change_ways_array[i] = (unsigned long long *)calloc
            (n, sizeof(unsigned long long));
    }
#endif
    
    printf("Available coin denominations: \n");
    for(int i = 0; i < m; i++) {
        printf("%ld ", c[i]);
    }
    printf("\n");

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    unsigned long long ways = getWays(n, m, c);
    printf("Number of ways of making change for %d cents is %llu\n", n, ways);
    
    //print_change_ways_array(n, m);

    return 0;
}
