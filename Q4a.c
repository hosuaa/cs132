#include <stdio.h>
int main() {
  int n, k;
  // define 2 integers n and k
  printf("Enter row: ");
  scanf("%d", &n);
  // user enters the row of Pascal's triangle they want printed. This row is stored at address n.
  for (k=0; k<=n; k++) {
    // begin for loop that will loop n times as for each row there is an equal number of values (row 1 has 1 value, row 2 has 2 etc)
    int result = choose(n, k);
    // call choose function with parameters n (row user wanted) and k (which will call n times and so call
    // the same number of times as there are values in the row) and store that in a result variable
    printf("%d\n", result);
    // print the result variable, which after looping through the whole for loop will print every value in the wanted row of
    // Pascal's triangle
  }
}
int choose(int n, int k) {
  // get 2 values n and k, where n is the nth row of Pascal's triangle and k is the value wanted in that row
  int result;
  // define a different result variable to main that will store the given value of Pascals's triangle
  if ((k == 0) || (n == k)){
    return 1;
    // if k equals 0 or n equals k return 1 (used to exit the recursion call and return the correct value for when 1 is entered).
  }
  if (k > 1) {
    result = choose(n, k - 1) * (n+1-k)/k;
    return result;
    // if k is greater than 1 recursively call the choose function with n and k-1 and multiply that with
    // (n+1-k)/k which is the formula given in 4a to calculate the kth value of Pascal's triangle on the nth column
    // when k reaches 0, above if statement is executed to return 1 and exit the recursion.
  }
}
