#include <stdio.h> 
  
bool Hasil(int set[], int n, int total) 
{ 
    bool subset[n + 1][total + 1]; 
  
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    for (int i = 1; i <= total; i++) 
        subset[0][i] = false; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= total; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] ||  
                            subset[i - 1][j - set[i - 1]]; 
        } 
    } 
  

     for (int i = 0; i <= n; i++) 
     { 
       for (int j = 0; j <= total; j++) 
          printf ("%4d", subset[i][j]); 
       printf("\n"); 
     }
  
    return subset[n][total]; 
} 
  

int main() 
{ 
    int set[] = { 3, 34, 4, 12, 5, 2 }; 
    int total = 9; 
    int n = sizeof(set) / sizeof(set[0]); 
    if (Hasil(set, n, total) == true) 
        printf("Ditemukan"); 
    else
        printf("Tidak Ditemukan"); 
    return 0; 
}  