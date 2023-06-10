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

    }

    // Called when user selects merge sort (option 5)
    public static void mergeSort(int[] arr) {

    }

    private static void merge(int[] arr, int start, int middle, int end) {

    }

    private static void mergeSortRecursive(int[] arr, int begin, int end) {

    }

    // determines pivot value from which to divide array into two parts
    private static int pivot(int[] arr, int begin, int end) {
        // assign index of middle element as mid
        int mid = begin + (end-begin) / 2;
        // assign value at mid as pivot value
        int pivot = arr[mid];
        // create boolean flag to indicate when array sorted
        boolean sorted = false;

        


    }

    private static void quickSortRecursive(int[] arr, int begin, int end) {

    }
}