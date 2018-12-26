package ming.com.modulerone;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.alibaba.android.arouter.facade.annotation.Autowired;
import com.alibaba.android.arouter.facade.annotation.Route;
import com.alibaba.android.arouter.launcher.ARouter;

import ming.com.basemodule.Books;

@Route(path = "/moduleone/ModulerMainActivity", group = "module")
public class ModulerMainActivity extends AppCompatActivity {
    private TextView mShowMsg;

    @Autowired
    String name;
    @Autowired
    int age;
    @Autowired(name = "book")
    Books books;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_moduler_main);
        mShowMsg = findViewById(R.id.tv_module_two_show);
        // ARouter会自动对字段进行赋值，无需主动获取
        ARouter.getInstance().inject(this);
        printMsg();
        setResult(1314);
    }

    private void printMsg() {
        mShowMsg.setText("name " + name + " age " + age + " book is " + books.toString());

    }
}
