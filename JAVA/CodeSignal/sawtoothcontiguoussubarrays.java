public class sawtoothcontiguoussubarrays {
    
    public static void main(String args[]) {
        int[] arr = {1, 0, 1, 1, 1, 0, 1, 0, 1};
        long numberWays = 0;
        int arrayLength = arr.length;
        int numberContiguous = 0;
    
        if ((arrayLength < 2) || (arrayLength == 2 && arr[0] == arr[1])) {
            System.out.println("Array < 2 elements or 2 repeat elements: 0 subarrays.");
        }
        else if (arrayLength == 2 && arr[0] != arr[1]) {
            System.out.println("Array = 2 elements: 1 way.");
        }
        else {
            if (arr[0] != arr[1]) {
                numberContiguous = 2;
            }
            else {
                numberContiguous = 1;
            }

            for (int i = 2; i < arrayLength; i++) {
                if ((arr[i-2] > arr[i-1] && arr[i-1] < arr[i]) 
                || (arr[i-2] < arr[i-1] && arr[i-1] > arr[i])){
                    numberContiguous += 1;
                }
                else if (arr[i-1] > arr[i] || arr[i-1] < arr[i]) {
                    numberWays += (numberContiguous * (numberContiguous - 1)) / 2;
                    numberContiguous = 2;
                }
                else {
                    numberWays += (numberContiguous * (numberContiguous - 1)) / 2;
                    numberContiguous = 1;
                }
            }

            numberWays += (numberContiguous * (numberContiguous - 1)) / 2;
        }

        System.out.println(numberWays);
    }
}