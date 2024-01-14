#include <stdio.h>
int MatrixChainMultuplication(int arr[], int n) {
   int minMul[n][n];
   int c=0;
   int j, q;
   for (int i = 1; i < n; i++)
      minMul[i][i] = 0;
   for (int L = 2; L < n; L++) {
               c++;
      for (int i = 1; i < n - L + 1; i++) {
         j = i + L - 1;
         minMul[i][j] = 99999999;
         for (int k = i; k <= j - 1; k++) {
            q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
            if (q < minMul[i][j])
            minMul[i][j] = q;
         } 
      }
   }
   printf("%d",c);
   return minMul[1][n - 1];
}

int main(){
   int arr[] = {5,4,6,2,7};
   int size = sizeof(arr) / sizeof(arr[0]);
   int n=size;
   printf("\n%d\n ",MatrixChainMultuplication(arr, size));
   for(int i=1;i<n-1;i++)
   {
     printf("(A%d)*",i);
   }
   getchar();
   return 0;
}