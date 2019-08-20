package com.heng.subhey.consumer;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Restaurant{

    Meal meal;

    ExecutorService exec = Executors.newCachedThreadPool();

    ConsumerPerson consumerPerson =new ConsumerPerson(this);

    Chef chef=new Chef(this);

    public Restaurant(){

        exec.execute(chef);

        exec.execute(consumerPerson);

    }

    public static void main(String[] args){

        new Restaurant();

    }
}