package ming.com.andcode.mvp.callback;

public interface CallBack<K, V> {
    void onSuccess(K data);

    void onFailed(V data);
}
