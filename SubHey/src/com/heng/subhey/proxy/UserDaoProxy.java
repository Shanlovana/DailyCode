package com.heng.subhey.proxy;

public class UserDaoProxy implements IUserDao {
    private IUserDao target;

    public UserDaoProxy(IUserDao target) {
        this.target = target;
    }

    @Override
    public void addRecord() {
        System.out.println("开始执行任务。。。。");
        target.addRecord();
        System.out.println("提交执行任务。。。。");

    }
}
