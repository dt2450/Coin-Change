#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


unsigned long long getWays(long n, int c_size, long int* c, unsigned int index){
    unsigned long long total_ways = 0;
    unsigned long long ways_n[n];

    memset(ways_n, 0 , sizeof(ways_n));

    for(long curr_n = 1; curr_n <= n; curr_n++) {
        for(int i = 0; i < c_size; i++) {
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
        }
    }
#if 0
    for(int k = 0; k < n; k++) {
        printf("%lld ", ways_n[k]);
    }
    printf("\n");
#endif

    return ways_n[n - 1];
}


int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
    
    change_ways_array = (unsigned long long **)malloc
        (sizeof(unsigned long long *)*m);

    for(int i = 0; i < m; i++) {
        change_ways_array[i] = (unsigned long long *)calloc
            (n, sizeof(unsigned long long));
    }
    
    printf("Available coin denominations: \n");
    for(int i = 0; i < m; i++) {
        printf("%ld ", c[i]);
    }
    printf("\n");

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    unsigned long long ways = getWays(n, m, c, 0);
    printf("Number of ways of making change for %d cents is %llu\n", n, ways);
    
    //print_change_ways_array(n, m);

    return 0;
}
