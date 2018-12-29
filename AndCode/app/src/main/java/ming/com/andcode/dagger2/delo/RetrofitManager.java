package ming.com.andcode.dagger2.delo;

public class RetrofitManager {
    private OkHttpClient okHttpClient;

    public RetrofitManager(OkHttpClient okHttpClient) {
        this.okHttpClient = okHttpClient;
    }

    public OkHttpClient getOkHttpClient() {
        return okHttpClient;
    }
}
