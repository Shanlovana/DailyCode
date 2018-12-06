package com.heng.leetcode;

import com.heng.leetcode.algorithms.LeetAlogorithms;

public class MainActivity {
    public static void main(String[] args) {
        int[] array = new int[]{1, 3, 5, 7, 9};
        //array = LeetAlogorithms.twoSum(array, 12);
        array = LeetAlogorithms.twoSumTwo(array, 12);
        StringBuffer result = new StringBuffer();
        for (int i : array) {
            result.append(" " + i);
        }
        System.out.println(result);
    }
}
