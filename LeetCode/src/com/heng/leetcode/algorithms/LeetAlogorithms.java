package com.heng.leetcode.algorithms;

import java.util.HashMap;
import java.util.Map;

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

    public static int[] twoSumTwo(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int diff = target - nums[i];
            if (map.containsValue(diff)) {
                return new int[]{map.get(diff), i};
            }
            map.put(nums[i], i);
        }

        throw new IllegalArgumentException("No two sum solution can reach target");
    }

    public static void addTwoNums(){


    }
}
