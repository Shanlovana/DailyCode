package com.heng.leetcode.algorithms;

public class LeetAlogorithms {

    public static int[] twoSum(int[] nums, int target) {
        if (null != nums && nums.length > 0) {
            for (int i = 0; i < nums.length; i++) {
                for (int j = i + 1; j < nums.length; j++) {
                    if (target == nums[i] + nums[j]) {
                        return new int[]{i, j};
                    }
                }

            }
        }
        // return null;
        throw new IllegalArgumentException("No two sum solution can reach target");

    }
}
