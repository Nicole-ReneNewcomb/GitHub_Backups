public class sumofconcatenations {
    public static long sumOfConcatenations(int[] a) {
        long valueSums = 0l;
        long sumPowers = 0l;
        int length = a.length;

        for (int i = 0; i < a.length; i++) {
            valueSums += a[i];
            sumPowers += Math.pow(10, String.valueOf(a[i]).length());
        }

        return valueSums * (sumPowers + length);
    }

    public static void main(String[] args) {
        int[] a = { 1000000, 1000000, 1000000, 1000000 };
        long sum = sumOfConcatenations(a);
        System.out.println("Sum of concatenations: " + sum);
    }
}