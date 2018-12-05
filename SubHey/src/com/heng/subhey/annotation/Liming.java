package com.heng.subhey.annotation;

@Person(id = 10758, msg = "hello android")//或者直接默认@Person()
public class Liming {
    @Chou("She")
    public String beautiful;

    @NoUse
    public void say() {
        System.out.println(" say is using ");
    }

    @Deprecated
    public void speak() {
        System.out.println(" speak is out of date ");
    }
}
