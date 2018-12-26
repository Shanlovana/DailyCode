package ming.com.andcode;

import android.content.Intent;
import android.net.Uri;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.alibaba.android.arouter.facade.Postcard;
import com.alibaba.android.arouter.facade.annotation.Route;
import com.alibaba.android.arouter.facade.callback.NavigationCallback;
import com.alibaba.android.arouter.launcher.ARouter;


import ming.com.andcode.jni.JNIManage;
import ming.com.andcode.mvp.MVPActivity;
import ming.com.basemodule.Books;

@Route(path = "/app/MainActivity", group = "demo")
public class MainActivity extends AppCompatActivity {
    private static final String TAG = "LoginInterceptor";
    TextView tv_mvp, tv_arouter;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ARouter.getInstance().inject(this);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv_mvp = findViewById(R.id.tv_entry_mvp);
        tv_arouter = findViewById(R.id.tv_entry_arouter);
        tv.setText(JNIManage.getInstance().getNums());
        setOnClicks();
    }

    private void setOnClicks() {
        tv_mvp.setOnClickListener((view) -> {
            Intent intent = new Intent(this, MVPActivity.class);
            startActivity(intent);
        });
        tv_arouter.setOnClickListener((view -> {
            ARouter.getInstance().build("/moduleone/ModulerMainActivity", "module")
                    .withString("name", "DeLux")
                    .withInt("age", 25)
                    .withParcelable("book", new Books("ShuiXu", 396, 3012345, "HuNanPress"))
                    .navigation(MainActivity.this, 1314);
        }));
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (requestCode) {
            case 1314:
                Log.i(TAG, "onActivityResult  has receieve the msg requestCode is " + requestCode + " resultCode is " + resultCode);
                break;
            default:
                break;
        }
    }
}




/*navigation(MainActivity.this, new NavigationCallback() {
                        @Override
                        public void onFound(Postcard postcard) {
                            String group = postcard.getGroup();
                            String path = postcard.getPath();
                            Log.i(TAG, "Interceptor onFound group is " + group + " path is " + path);
                        }

                        @Override
                        public void onLost(Postcard postcard) {
                            Log.i(TAG, "Interceptor onLost");
                        }

                        @Override
                        public void onArrival(Postcard postcard) {
                            Log.i(TAG, "Interceptor onArrival");
                        }

                        @Override
                        public void onInterrupt(Postcard postcard) {
                            Log.i(TAG, "Interceptor onInterrupt");
                        }
                    });*/