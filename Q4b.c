#include <stdio.h>
int main() {
  int n, k;
  // define 2 integers n and k
  printf("Enter fibonacci number: ");
  scanf("%d", &n);
  // user enters fibonacci number they want stored at address n
  if (n == 0) {
    printf("0\n");
    // if the user wants the 0th fibonacci number output 0
  } else {
    int result;
    // define a result variable where resulting fibonacci number will be stored
    for (k=0; k<=(n-1)/2; k++) {
      // begin fibonacci formula by creating a for loop that loops (n-1)/2 times
      result = result + choose(n - k - 1, k);
      // for each value of k which is always an integer (0, 1, 2...(n-1)/2), store in result the
      // previous result variable as well as calling the choose function with parameters n-k-1 and k.
      // this is based on the formula given in the question which should get the correct values of
      // Pascal's triangle to sum to the correct fibonacci number.
    }
    printf("%d\n", result);
    // print the fibonacci number
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
