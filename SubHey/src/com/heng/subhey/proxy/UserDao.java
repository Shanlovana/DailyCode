package com.heng.subhey.proxy;

public class UserDao implements IUserDao {
    @Override
    public void addRecord() {
        System.out.println("UserDao--为您添加一条新记录");
    }
}
