// two pointer technique is the technique in which we use two pointers to traverse array etc.
// used in problems involving arrays or linked lists. It involves using two indices (pointers) that move through the data structure, typically from the beginning and end, or starting together and moving at different speeds.

// Used when
// Sorted arrays (especially for searching or pairing problems)
// Finding subarrays or pairs that meet certain criteria
// Problems involving reverse traversal or window sliding

// check if an array has a pair with a given sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Time complexity O(n) after sorting
// space complexity O(1)
// work best with sorted input
bool has_pair_with_sum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int current_sum = arr[left] + arr[right];

        if (current_sum == target)
        {
            return true;
        }
        else if (current_sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    cout << (has_pair_with_sum(arr, target) ? "Found" : "Not Found") << endl;

    return 0;
}