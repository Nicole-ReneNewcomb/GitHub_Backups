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
    public static void selectSort (int[] arr_) {

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

    private static int pivot(int[] arr, int begin, int end) {

    }

    private static void quickSortRecursive(int[] arr, int begin, int end) {

    }
}