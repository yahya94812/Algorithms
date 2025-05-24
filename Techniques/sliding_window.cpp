// The Sliding Window technique is an optimization method used for problems involving contiguous sequences (subarrays or substrings). It helps reduce the time complexity from O(n²) (brute-force) to O(n) by maintaining a moving window over the data.

// use when
// Problems involving subarrays or substrings
// Finding maximum/minimum sum of a subarray
// Finding the longest/shortest subarray that satisfies a condition

// maximum sum of a subarray of size k
#include <iostream>
#include <vector>
using namespace std;

int max_sum_sub_array(vector<int> &arr, int k) // Avoid Copying the Whole Vector and Pass by Reference Is Faster and More Efficient and You Can Also Modify the Original Vector (if needed)
{                                              // here k is the size of sub array
    int n = arr.size();

    if (n < k)
        return -1;

    int window_sum = 0;

    for (int i = 0; i < k; i++)
    { // calculating the sum of first window
        window_sum += arr[i];
    }
    int max_sum = window_sum;

    // sliding window
    for (int i = k; i < n; i++)
    {                                                  // because (n-1) is the last right place window can reach; remember k is the size of window and kth index is not included in window
        window_sum = window_sum - arr[i - k] + arr[i]; // Add next, remove first of previous value from window
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {2, 4, 6, 4, 3, 5, 4, 7, 4};
    int k = 4;
    cout << "max subarray of size: " << k << " is: " << max_sum_sub_array(arr, k);

    return 0;
}