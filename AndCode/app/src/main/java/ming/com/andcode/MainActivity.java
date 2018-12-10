package ming.com.andcode;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import ming.com.andcode.jni.JNIManage;
import ming.com.andcode.mvp.MVPActivity;

public class MainActivity extends AppCompatActivity {
    TextView tv_mvp;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv_mvp = findViewById(R.id.tv_entry_mvp);
        tv.setText(JNIManage.getInstance().getNums());
        setOnClicks();
    }

    private void setOnClicks() {
        tv_mvp.setOnClickListener((view) -> {
            Intent intent = new Intent(this, MVPActivity.class);
            startActivity(intent);
        });
    }
}
