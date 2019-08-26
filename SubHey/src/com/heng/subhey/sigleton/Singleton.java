package com.heng.subhey.sigleton;

/*
 * A journey to write double checked locking of Singleton class in Java.
 */

class Singleton {

    private volatile static Singleton _instance;

    private Singleton() {
        // preventing Singleton object instantiation from outside
    }

    /*
     * 1st version: creates multiple instance if two thread access
     * this method simultaneously
     */

    public static Singleton getInstance() {
        if (_instance == null) {
            _instance = new Singleton();
        }
        return _instance;
    }

    /*
     * 2nd version : this definitely thread-safe and only
     * creates one instance of Singleton on concurrent environment
     * but unnecessarily expensive due to cost of synchronization
     * at every call.
     */

    public static synchronized Singleton getInstanceTS() {
        if (_instance == null) {
            _instance = new Singleton();
        }
        return _instance;
    }

    /*
     * 3rd version : An implementation of double checked locking of Singleton.
     * Intention is to minimize cost of synchronization and  improve performance,
     * by only locking critical section of code, the code which creates instance of Singleton class.
     * By the way this is still broken, if we don't make _instance volatile, as another thread can
     * see a half initialized instance of Singleton.
     */

    public static Singleton getInstanceDC() {
        if (_instance == null) {
            synchronized (Singleton.class) {
                if (_instance == null) {
                    _instance = new Singleton();
                }
            }
        }
        return _instance;
    }

    /*
     * 4rd version : enum Singleton.
     * see  initialized instance of Singleton.
     */
    public enum EnumSingleton {
        INSTANCE;

        public EnumSingleton getInstance() {
            return INSTANCE;
        }
    }

    /**
     * @param StaticInnerSingleton
     * 5rd version : inner class Singleton.
     * see  initialized instance of StaticInnerSingleton.
     */

}
