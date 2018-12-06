package ming.com.andcode.mvp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import java.util.Random;

import ming.com.andcode.R;
import ming.com.andcode.mvp.base.IPresenter;
import ming.com.andcode.mvp.base.IView;
import ming.com.andcode.mvp.getdata.GetDataContract;
import ming.com.andcode.mvp.getdata.GetDataModeli;
import ming.com.andcode.mvp.getdata.GetDataPresenter;
import ming.com.andcode.mvp.getdata.bean.ArticleListBean;


public class MVPActivity<T extends IPresenter> extends AppCompatActivity implements GetDataContract.View {
    private GetDataPresenter mPeresenter;
    private Button mGetData;
    private TextView showMsg;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mvp);
        mGetData = findViewById(R.id.bt_check_mvp);
        showMsg = findViewById(R.id.tv_show_msg);
        initPresenter();
        mGetData.setOnClickListener((view -> {
            mPeresenter.getData("", new Random().nextInt(5) + 1);
        }));

    }

    private void initPresenter() {
        mPeresenter = new GetDataPresenter(new GetDataModeli());
        mPeresenter.attachView(this);

    }

    @Override
    protected void onDestroy() {
        if (mPeresenter != null) {
            mPeresenter.detachView();
        }
        super.onDestroy();
    }

   /* @Override
    public void showSuccessMsg(ArticleListBean bean) {
        showMsg.setText(bean.data.datas.get(0).chapterName);
    }*/

    @Override
    public void showSuccessMsg(Object bean) {
        if (bean != null) {
            showMsg.setText((bean instanceof ArticleListBean) ? ((ArticleListBean) bean).data.datas.get(0).chapterName : bean.toString());
        }
    }

    @Override
    public void showFaiedMsg(String msg) {
        showMsg.setText(R.string.checkout_is_wrong);

    }
}
