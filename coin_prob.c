#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int l, int r) {
    if (l >= r) {
       return; 
    } else {
        int mid = (l + r - 1)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid +1, r);
        merge(arr, l, mid, r);        
    }
}

unsigned long long getWays(long n, int c_size, long int* c){
    // Complete this function
    unsigned long long change_i[n+1][50];
    unsigned long long ways_i[n+1];
    
    memset(change_i, 0, sizeof(change_i));
    memset(ways_i, 0, sizeof(ways_i));
    
    mergeSort(c, 0, c_size - 1);    
    
    for(int i = 1; i <= n; i++) {
        int remaining = i;
        for(int j = 0; j < c_size; j++) {
            int coin = c[j];
            if(coin > i) {
                break;
            }
            //choose coin to be the first coin
            int count = 0;
            remaining = i - coin;
            unsigned long long remain_ways = 0;
            
            if(remaining > 0) {
                if(remaining < i) {
                    for(int k = j; k < c_size; k++) {
                        remain_ways += change_i[remaining][k];
                    }
                    change_i[i][j] = remain_ways;
                }
            } else if(remaining == 0) {
                change_i[i][j] = 1;
            } else {
                change_i[i][j] = 0;
            }            
            ways_i[i] += change_i[i][j];
        }        
    }
    
    return ways_i[n];   
}

int main() {
    int n; 
    int m; 
    scanf("%d %d", &n, &m);
    long *c = malloc(sizeof(long) * m);
    for(int c_i = 0; c_i < m; c_i++){
       scanf("%ld",&c[c_i]);
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    unsigned long long ways = getWays(n, m, c);
    printf("%llu\n", ways);
    
    return 0;
}
