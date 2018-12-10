package ming.com.andcode.jni;

public class JNIManage {
    private static  JNIManage instance;

    public static JNIManage getInstance() {
        if (instance == null) {
            synchronized (JNIManage.class) {
                if (instance == null) {
                    instance = new JNIManage();
                }
            }
        }
        return instance;
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native void setNums(int i);

    public native String getNums();
}
