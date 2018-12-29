package ming.com.andcode.dagger2.delo;

public class OkHttpClient   {
    private int timeout;

    public OkHttpClient(int timeout) {
        this.timeout = timeout;
    }

    public OkHttpClient() {
    }

    public int getTimeout() {
        return timeout;
    }

    public void setTimeout(int timeout) {
        this.timeout = timeout;
    }


}
