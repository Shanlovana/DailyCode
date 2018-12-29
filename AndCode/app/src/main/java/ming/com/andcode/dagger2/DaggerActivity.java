package ming.com.andcode.dagger2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import javax.inject.Inject;

import ming.com.andcode.R;


import ming.com.andcode.dagger2.component.DaggerDaggerActivityComp;
import ming.com.andcode.dagger2.delo.Flower;
import ming.com.andcode.dagger2.delo.OkHttpClient;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.delo.RetrofitManager;
import ming.com.andcode.dagger2.delo.Rose;
import ming.com.andcode.dagger2.module.DaggeActivityModule;
import ming.com.andcode.dagger2.module.FlowerModule;


public class DaggerActivity extends AppCompatActivity {
    private static final String TAG = "DaggerActivity";

    @Inject
    Pot pot;

    @Inject
    Rose rose;

    @Inject
    Flower flower;

    @Inject
    OkHttpClient okHttpClient;

    @Inject
    RetrofitManager retrofitManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dagger);
        // 这个类是重新编译后Dagger2自动生成的，所以写这行代码之前要先编译一次 Build --> Rebuild Project
        DaggerDaggerActivityComp.builder().daggeActivityModule(new DaggeActivityModule(3000)).flowerModule(new FlowerModule()).build().inject(this);
        toastWhisper();
    }

    private void toastWhisper() {
        Log.d(TAG, " pot.show() is :" + pot.show());
        Log.d(TAG, " rose is :" + rose.whisper());
        Log.d(TAG, " flower is :" + flower.toString());
        Log.d(TAG, " okHttpClient.toString() is :" + okHttpClient.toString());
        Log.d(TAG, " retrofitManager.getOkHttpClient().toString() is :" + retrofitManager.getOkHttpClient().toString());
    }

}
