package com.heng.subhey.annotation;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class CheckOutTool {
    public static void checkAll() {
        MaSaGei maSaGei = new MaSaGei();
        Class clazz = maSaGei.getClass();
        Method[] method = clazz.getDeclaredMethods();
        StringBuilder log = new StringBuilder();
        // 记录异常的次数
        int errornum = 0;
        for (Method m : method) {
            if (m.isAnnotationPresent(CheckOut.class)) {
                m.setAccessible(true);
                try {
                    m.invoke(maSaGei, null);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                } catch (InvocationTargetException e) {
                    e.printStackTrace();
                    errornum++;
                    log.append(m.getName());
                    log.append("  ");
                    log.append("has error ");
                    log.append("\\n\\r  caused by ");
                    log.append(e.getCause().getClass().getSimpleName());
                    log.append("\n\r");
                    log.append(e.getCause().getMessage());
                    log.append("\n\r");
                }
            }
        }
        log.append(clazz.getSimpleName());
        log.append(" has  ");
        log.append(errornum);
        log.append(" error."); // 生成测试报告
        System.out.println(log.toString());
    }
}
