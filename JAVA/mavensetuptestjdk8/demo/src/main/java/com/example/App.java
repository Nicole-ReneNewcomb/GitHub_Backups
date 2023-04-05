package com.example;

import java.util.stream.IntStream;

/**
 * Hello world!
 */
public final class App {
    private App() {
    }

    /**
     * Says hello to the world.
     * @param args The arguments of the program.
     */
    public static void main(String[] args) {
        int[] nums = { 2, 5, 30, 8, 4, 20 };

        int max = IntStream.range(0, nums.length - 1).map(n -> nums[n] * nums[n+1]).max().getAsInt();
        System.out.println(max);
    }
}
