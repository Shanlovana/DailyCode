package com.heng.subhey;

import com.heng.subhey.annotation.CheckOutTool;
import com.heng.subhey.annotation.Chou;
import com.heng.subhey.annotation.Liming;
import com.heng.subhey.annotation.Person;

import java.lang.annotation.Annotation;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.List;

@Person(msg = "this is not default")
public class MainActivity {
    public static void main(String[] args) {
        Liming li = new Liming();
        li.say();
        li.speak();
        getAnnotation();
        getField();
        CheckOutTool.checkAll();
    }

    @SuppressWarnings("this method deprecation")
    public void testMethod() {
        Liming li = new Liming();
        li.speak();
    }

    @SafeVarargs // Not actually safe!
    public static void invalidMethod(List<String>... stringLists) {
        Object[] array = stringLists;
        List<Integer> tmpList = Arrays.asList(69);
        array[0] = tmpList; // Grammatically established, but build without warnings
        String s = stringLists[0].get(0); // ClassCastException at runtime!
    }

    public static void getAnnotation() {
        boolean hasAnnotation = MainActivity.class.isAnnotationPresent(Person.class);
        if (hasAnnotation) {
            Person testPerson = MainActivity.class.getAnnotation(Person.class);
            System.out.println("id is " + testPerson.id() + " msg is " + testPerson.msg());
        }
    }

    public static void getField() {
        try {
            Field a = Liming.class.getDeclaredField("beautiful");
            a.setAccessible(true);
            Chou chou = a.getAnnotation(Chou.class);
            if (chou != null) {
                System.out.println("check value:" + chou.value());
            }
            Method noUse = Liming.class.getDeclaredMethod("say");
            if (noUse != null) { // 获取方法中的注解
                Annotation[] ans = noUse.getAnnotations();
                for (int i = 0; i < ans.length; i++) {
                    System.out.println("method noUse annotation:" + ans[i].annotationType().getSimpleName());
                }
            }

        } catch (NoSuchFieldException e) {
            e.printStackTrace();
            System.out.println("NoSuchFieldException");
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
            System.out.println("NoSuchMethodException");
        }

    }
}
