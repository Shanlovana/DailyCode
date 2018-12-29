package ming.com.andcode.dagger2;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

import javax.inject.Inject;

import ming.com.andcode.R;


import ming.com.andcode.dagger2.component.DaggerFlowerComponent;
import ming.com.andcode.dagger2.delo.OkHttpClient;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.delo.RetrofitManager;
import ming.com.andcode.dagger2.delo.Rose;
import ming.com.andcode.dagger2.module.DaggeActivityModule;
import ming.com.andcode.dagger2.module.FlowerModule;
import ming.com.andcode.dagger2.module.PotModule;


public class DaggerActivity extends AppCompatActivity {
    private static final String TAG = "DaggerActivity";
    @Inject
    Pot pot;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dagger);
        // 这个类是重新编译后Dagger2自动生成的，所以写这行代码之前要先编译一次 Build --> Rebuild Project
        DaggerFlowerComponent.create().
                plus(new PotModule())// 这个方法返回PotComponent
                .plus()              // 这个方法返回MainActivityComponent
                .inject(this);
        toastWhisper();
    }

    private void toastWhisper() {
        Log.d(TAG, " pot is :" + pot.show());
    }
}
