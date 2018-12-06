package ming.com.andcode.mvp.getdata;

import java.util.Random;

import ming.com.andcode.mvp.base.BasePresenter;
import ming.com.andcode.mvp.callback.CallBack;
import ming.com.andcode.mvp.getdata.bean.ArticleListBean;
import ming.com.andcode.mvp.getdata.bean.BannerBean;
import ming.com.andcode.mvp.getdata.utils.LogUtil;

public class GetDataPresenter extends BasePresenter<GetDataContract.View> implements GetDataContract.Presenter {
    private final GetDataModeli getDataModeli;

    @Override
    public void getData(String url, int current) {
        getDataModeli.getData(url, current, new CallBack<ArticleListBean, String>() {
            @Override
            public void onSuccess(ArticleListBean data) {
                LogUtil.d("getData onSuccess data is " + data.toString());
                mView.showSuccessMsg(data);

            }

            @Override
            public void onFailed(String data) {
                LogUtil.w(data);

            }
        });

    }

    @Override
    public void getBanner(String baseUrl) {
        getDataModeli.getBanner(baseUrl, new CallBack<BannerBean,String >() {
            @Override
            public void onSuccess(BannerBean data) {
                mView.showSuccessMsg(data);
            }

            @Override
            public void onFailed(String data) {
                mView.showFaiedMsg(data);

            }
        });

    }

    public GetDataPresenter(GetDataModeli getDataModeli) {
        this.getDataModeli = getDataModeli;
    }

}
