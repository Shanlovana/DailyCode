package com.heng.subhey.consumer;

import java.util.concurrent.TimeUnit;

public class Chef  implements  Runnable{ //product

    private  Restaurant restaurant;

    private  int count=0;

    public Chef(Restaurant restaurant) {
        this.restaurant = restaurant;
    }

    @Override
    public void run() {

        try {
            while (!Thread.interrupted()) {

                synchronized (this) {

                    while (restaurant.meal != null) {

                        wait();
                    }
                    if (++count==10){

                        System.out.println("out of food,closing");
                        restaurant.exec.shutdownNow();
                    }
                    System.out.println("Chef product meal"+count);
                    synchronized (restaurant.consumerPerson){
                        restaurant.meal= new Meal(count);
                        restaurant.consumerPerson.notifyAll();
                    }
                    TimeUnit.MICROSECONDS.sleep(100);
                }

            }

        }catch (InterruptedException e){
            System.out.println("Chef interruped");

        }

    }
}