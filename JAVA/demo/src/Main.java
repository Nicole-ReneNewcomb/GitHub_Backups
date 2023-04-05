import java.util.OptionalInt;
import java.util.stream.IntStream;

public class Main {

    public static void main(String args[]) {
        int[] nums = { 2, 5, 3, 8, 4, 10 };

        int max = IntStream.range(0, nums.length - 1).map(n -> nums[n] * nums[n+1]).max().getAsInt();
        System.out.println(max);
    }
}
