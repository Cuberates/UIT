#include <bits/stdc++.h>
using namespace std;
using namespace chrono; // For measuring execution time 
int N = 1000000; vector<int> A(N); // All elements will be equal to 0
int mss_1 () { // O(N3)
   int maxSum = 0;
   for(int i = 0; i < A.size( ); i++ )
      for(int j = i; j < A.size( ); j++ ) {
         int thisSum = 0;
         for(int k = i; k <= j; k++ )
            thisSum += A[ k ];
         if (thisSum > maxSum)
            maxSum = thisSum;
      }
   return maxSum;
}
int mss_2 () { // O(N2)
   int maxSum = 0;
   for( int i = 0; i < A.size( ); i++ ) {
      int thisSum = 0;
      for( int j = i; j < A.size( ); j++ ) {
         thisSum += A[ j ];
         if( thisSum > maxSum )
            maxSum = thisSum;
      }
   }
   return maxSum;
}
int mss_3 (vector<int> arr, int l, int mid, int r) { // O(NLOGN)
   int sum = 0;
   int left_sum = INT_MIN;
   for (int i = mid; i >= l; i--) {
      sum = sum + arr[i];
      if (sum > left_sum) left_sum = sum;
   }
   sum = 0;
   int right_sum = INT_MIN;
   for (int i = mid+1; i <= r; i++) {
      sum = sum + arr[i];
      if (sum > right_sum) right_sum = sum;
   }
   return left_sum + right_sum;
}

int mss_4 () { // O(N)
   int maxSum = 0, thisSum = 0;
   for( int j = 0; j < A.size( ); j++ ) {
      thisSum += A[ j ];
      if ( thisSum > maxSum )
         maxSum = thisSum;
      else if ( thisSum < 0 )
         thisSum = 0;
   }
   return maxSum;
}
int main (void) {
   int k = 3; // The algorithm will run k times, and the result will be the average
   vector<double> t_list;
   for(int i=0;i<k;i++) {
      auto start = steady_clock::now(); // Start measuring time
      mss_3(A, 1, N/2, N); // Algorithm
      auto end   = steady_clock::now(); // Stop measuring time 
      auto diff  = end - start; // Stop measuring time 
      t_list.push_back (chrono::duration <double, milli> (diff).count()); // Stop measuring time 
   }
   double average_time = 0.0;
   for(double &t : t_list) average_time += t;
   cout << "Average runtime of algorithm: " << fixed << setprecision(3) << average_time / k / 1000 << "\n";
}
