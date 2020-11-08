#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long long **change_ways_array = NULL;

unsigned long long getWays(long n, int c_size, long int* c, unsigned int index){
    unsigned long long total_ways = 0;

    if(index > c_size) {
        printf("Bad index\n");
        return 0;
    }
    for(int i = index; i < c_size; i++) {
        if(c[i] > n) {
            break;
        }
        long value = n - c[i];
        
        if(value == 0) {
            total_ways++;
            break;
        } else {

            unsigned long long curr_ways = 0;
            
            if(change_ways_array[i][value-1] != 0) {
                /* we have calculated and updated this value earlier.
                 * pick from here. no need to recalculate
                 */
                curr_ways = change_ways_array[i][value-1] - 1;
            } else {
                curr_ways = getWays(value, c_size, c, i);
                /* treating 0 as initial value and to avoid conflict when
                 * we want to store 0 as value, we store by increment 1
                 * i.e. in the array if the value is 1 then it represents 0
                 * if it is 100 it represents 99 and so on.
                 * If it is 0 then it is the initial value
                 */
                change_ways_array[i][value-1] = curr_ways + 1;
            }
            total_ways += curr_ways;

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
    
    change_ways_array = (unsigned long long **)malloc
        (sizeof(unsigned long long *)*m);

    for(int i = 0; i < m; i++) {
        change_ways_array[i] = (unsigned long long *)calloc
            (n, sizeof(unsigned long long));
    }


    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    unsigned long long ways = getWays(n, m, c, 0);
    printf("%llu\n", ways);
    
    return 0;
}
