package com.heng.subhey.consumer;

public class ConsumerPerson implements  Runnable{

    private  Restaurant restaurant;

    public ConsumerPerson(Restaurant restaurant) {
        this.restaurant = restaurant;
    }


    @Override
    public void run() {

        try{
            while (!Thread.interrupted()) {
                synchronized (this) {
                    while (restaurant.meal == null) {
                        wait();
                    }
                    System.out.println("consumerPerson got:"+restaurant.meal);
                }
                synchronized (restaurant.chef){
                    restaurant.meal=null;
                    restaurant.chef.notifyAll();
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
            System.out.println("consumerPerson interrupdate");
        }

    }
}