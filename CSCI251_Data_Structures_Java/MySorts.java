/* Nicole-Rene Newcomb's Project 1 for CSCI251, Summer 2023:
 * MySorts.java includes the code to perform four sorts - 
 * insertion (insert) sort, selection (select) sort, quick sort, 
 * and merge sort. This file is called from CSCI251ProjOne.java 
 * after the user selects the desired sort from the menu.
 */

public class MySorts {

    // Called when user selects insert sort (option 3)
    public static void insertSort(int[] arr) {
        // assign length of array
        int l = arr.length;
        // counter for outer loop
        int i = 0;
        // counter for inner loop
        int j = 0;
        // temporary variable to hold value during position swap
        int tmp = 0;

        // outer loop - increments as sorted part grows
        // when outer loop finished, entire array sorted
        for (i = 1; i < l; i++) {
            // start index j at index i for each outer loop
            j = i;

            // inner loop - decrements to compare new value to sorted values
            while (j > 0 && arr[j] < arr[j-1]) {

                // swaps values (until sorted part in ascending order)
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                j--;
            }
        }
    }

    // Called when user selects select sort (option 2)
    public static void selectSort (int[] arr) {
        // assign length of array
        int l = arr.length;
        // counter for outer loop
        int i = 0;
        // counter for inner loop
        int j = 0;
        // temporary variable to hold value during position swap
        int tmp = 0;
        // variable to contain smallest unsorted element during loop
        int minIndex = 0;

        // outer loop - increments to next unsorted value
        // when outer loop finished, entire array sorted
        for (i = 0; i < l; i++) {
            // assign index i as minIndex value for each outer loop
            minIndex = i;

            // inner loop increments through unsorted part to find min value
            for (j = i + 1; j < l; j++) {

                // if smaller value found in unsorted, update minIndex
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            // swap values so minimum number from unsorted part moved to sorted part
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }

    // Called when user selects quick sort (option 4)
    public static void quickSort(int[] arr) {
        // assign begin value to pass to private method
        int begin = 0;
        // determine/assign end value to pass to private method
        int end = arr.length - 1;

        // call private quick sort recursive function
        quickSortRecursive(arr, begin, end);
    }

    // Called when user selects merge sort (option 5)
    public static void mergeSort(int[] arr) {
        // assign begin value to pass to private method
        int begin = 0;
        // determine/assign end value to pass to private method
        int end = arr.length - 1;

        // call private merge sort recursive function
        mergeSortRecursive(arr, begin, end);
    }

    // function merges left/right parts into sorted array (merge sort)
    private static void merge(int[] arr, int start, int middle, int end) {
        // assign number of elements to variable size
        int size = end - start + 1;
        // create temporary array to hold values sorted from left/right parts
        int[] mergedNums = new int[size];
        // create variable for temporary array (mergedNums) index
        int mergedIndex = 0;
        // create index variable for left part
        int leftIndex = 0;
        // create index variable for right part
        int rightIndex = 0;

        // assign start index as initial leftIndex
        leftIndex = start;
        // assign middle + 1 as initial rightIndex
        rightIndex = middle + 1;

        // while still elements in both right and left parts
        while (leftIndex <= middle && rightIndex <= end) {
            // if left part's index has lowest value (or equal value as right)
            if (arr[leftIndex] <= arr[rightIndex]) {
                // assign left value to temporary array
                mergedNums[mergedIndex] = arr[leftIndex];
                // increment leftIndex
                leftIndex++;
            }
            // else, if right part's index has lowest value
            else {
                // assign right value to temporary array
                mergedNums[mergedIndex] = arr[rightIndex];

                // increment rightIndex
                rightIndex++;
            }
            // increment mergedIndex
            mergedIndex++;
        }

        // if right partition empty and only left part has remaining values
        while (leftIndex <= middle) {
            // add remaining values from left part to temporary array
            mergedNums[mergedIndex] = arr[leftIndex];
            leftIndex++;
            mergedIndex++;
        }

        // if left partition is empty and only right part has remaining values
        while (rightIndex <= end) {
            // add remaining values from right part to temporary array
            mergedNums[mergedIndex] = arr[rightIndex];
            rightIndex++;
            mergedIndex++;
        }

        // copy numbers in temporary array back to arr array
        for (mergedIndex = 0; mergedIndex < size; mergedIndex++) {
            arr[start + mergedIndex] = mergedNums[mergedIndex];
        }
    }

    // recursive function calls itself and merge method for left/right parts (merge sort)
    private static void mergeSortRecursive(int[] arr, int begin, int end) {
        // create variable to hold midpoint index
        int middle = 0;

        // if begin < end, determine/assign midpoint to middle variable
        if (begin < end) {
            middle = (begin + end) / 2;
        }
        else {
            return;
        }
        
        // sort left/right partitions through recursively calling itself
        mergeSortRecursive(arr, begin, middle);
        mergeSortRecursive(arr, middle + 1, end);

        // call merge method to merge left/right into sorted array
        merge(arr, begin, middle, end);
    }

    // determines index from which to divide array into two parts (quick sort)
    private static int pivot(int[] arr, int begin, int end) {
        // assign index of middle element as mid
        int mid = begin + (end-begin) / 2;
        // assign value at mid as pivot value
        int pivot = arr[mid];
        // create boolean flag to indicate when array partitioned
        boolean partitioned = false;
        // create temporary variable to hold value during swaps
        int tmp = 0;

        while (!partitioned) {
            // increment begin index while value < pivot
            while (arr[begin] < pivot) {
                begin++;
            }

            // decrement end index while value > pivot
            while (pivot < arr[end]) {
                end--;
            }

            // if array fully partitioned (0 or 1 elements remain), flag true
            if (begin >= end) {
                partitioned = true;
            }

            // else, if not fully partitioned, swap values at begin and end
            else {
                tmp = arr[begin];
                arr[begin] = arr[end];
                arr[end] = tmp;

                // update begin and end index values
                begin++;
                end--;
            }
        }
        return end;
    }

    // recursively calls pivot method and itself to sort array (quick sort)
    private static void quickSortRecursive(int[] arr, int begin, int end) {
        // return if partition is 0 or 1 element since part already sorted
        if (begin >= end) {
            return;
        }

        // call pivot method to determine partition split index (end of low part)
        int splitIndex = pivot(arr, begin, end);

        // call method recursively for low/high partition sections
        quickSortRecursive(arr, begin, splitIndex);
        quickSortRecursive(arr, splitIndex + 1, end);
    }
}