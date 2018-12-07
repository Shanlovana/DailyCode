package com.heng.subhey.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class PlaceForSell implements InvocationHandler {
    private Object target;

    public PlaceForSell(Object service) {
        this.target = service;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("this is a place for restaurant ,please coming");
        method.invoke(target, args);
        System.out.println("please seat down and have fun");
        return null;
    }
}
