package ming.com.andcode.lifebind;

import android.util.Log;

public class TestLife implements LifecycleListener {
    @Override
    public void onStart() {
        Log.d("TestLife", "onStart");
    }

    @Override
    public void onStop() {
        Log.d("TestLife", "onStop");

    }

    @Override
    public void onDestroy() {
        Log.d("TestLife", "onDestroy");

    }
}
