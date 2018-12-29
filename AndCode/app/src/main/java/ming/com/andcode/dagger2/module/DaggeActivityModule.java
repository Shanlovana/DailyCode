package ming.com.andcode.dagger2.module;



import dagger.Module;
import dagger.Provides;
import ming.com.andcode.dagger2.delo.OkHttpClient;
import ming.com.andcode.dagger2.delo.RetrofitManager;

@Module
public class DaggeActivityModule {
    private int timeout;

    public DaggeActivityModule(int timeout) {
        this.timeout = timeout;
    }

    @Provides
    OkHttpClient provideOkHttpClient() {
        OkHttpClient client = new OkHttpClient();
        client.setTimeout(timeout);
        return client;
    }

    @Provides
    RetrofitManager provideretrofitManager(OkHttpClient client) {
        return new RetrofitManager(client);
    }
}
