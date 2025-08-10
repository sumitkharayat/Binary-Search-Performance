#include <stdio.h>
#include <time.h>
int binarySearch(int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[100000];
    // Define your 15 test cases here:
    int sizes[15] = {
        10, 100, 1000, 5000, 10000, // Best cases - middle element present
        10, 100, 1000, 5000, 10000, // Worst cases - element absent
        10, 100, 1000, 5000, 10000  // Average cases - element somewhere else
    };
    int targets[15] = {
        0, 0, 0, 0, 0,           // Best case: middle element (arr[n/2] = 0)
        500, 500, 500, 500, 500, // Worst case: target NOT present (outside range)
        3, 35, 450, 2100, 6000   // Average case: element present but not middle
    };
    char *caseTypes[15] = {
        "Best", "Best", "Best", "Best", "Best",
        "Worst", "Worst", "Worst", "Worst", "Worst",
        "Average", "Average", "Average", "Average", "Average"};

    for (int i = 0; i < 15; i++)
    {
        int n = sizes[i];
        int target = targets[i];

        // Fill array with sorted values including negatives: from -n/2 to n/2-1
        for (int j = 0; j < n; j++)
        {
            arr[j] = j - n / 2;
        }

        clock_t start = clock();
        int res = binarySearch(arr, n, target);
        clock_t end = clock();

        double time_us = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

        printf("Case: %-7s | Array Size: %6d | Target: %6d | Result Index: %6d | Time: %10.2f microseconds\n",
               caseTypes[i], n, target, res, time_us);
    }

    return 0;
}
