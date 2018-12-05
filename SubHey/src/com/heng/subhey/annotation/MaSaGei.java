package com.heng.subhey.annotation;

public class MaSaGei {
    @CheckOut
    public void testOne() {
        System.out.println(" 1 + 0 = " + ((1 + 1) / 2));
    }

    @CheckOut
    public void testTwo() {
        System.out.println(" 1 + 1 = " + (8 / 4));
    }

    @CheckOut
    public void testThree() {
        System.out.println(" 1 + 2 = " + (6 / 2));
    }

    @CheckOut
    public void testFour() {
        System.out.println(" 1 / 3 = " + (6 / 0));
    }
}
