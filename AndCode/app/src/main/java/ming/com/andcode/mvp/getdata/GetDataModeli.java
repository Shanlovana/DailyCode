package ming.com.andcode.mvp.getdata;

import java.util.Random;

import ming.com.andcode.mvp.base.Api;
import ming.com.andcode.mvp.callback.CallBack;
import ming.com.andcode.mvp.getdata.bean.ArticleListBean;
import ming.com.andcode.mvp.getdata.bean.BannerBean;
import ming.com.andcode.mvp.getdata.utils.LogUtil;
import ming.com.andcode.mvp.getdata.utils.RetrofitUtils;
import rx.Scheduler;
import rx.Subscriber;
import rx.android.schedulers.AndroidSchedulers;
import rx.schedulers.Schedulers;

public class GetDataModeli implements GetDataModel {
    @Override
    public void getData(String url, int current, final CallBack callBack) {
        RetrofitUtils.getRetrofit().create(Api.class).getData(current)
                .subscribeOn(Schedulers.io()).observeOn(AndroidSchedulers.mainThread())
                .subscribe(new Subscriber<ArticleListBean>() {
                    @Override
                    public void onCompleted() {
                        LogUtil.d("getData onCompleted");
                    }

                    @Override
                    public void onError(Throwable e) {
                        LogUtil.w("getData onError");
                    }

                    @Override
                    public void onNext(ArticleListBean articleListBean) {
                        if (null == articleListBean) {
                            callBack.onFailed("something was wrong");
                        } else {
                            if (articleListBean.errorCode != 0) {
                                callBack.onFailed(articleListBean.errorMsg);
                            } else {
                                callBack.onSuccess(articleListBean);
                            }
                        }

                    }
                });


    }

    @Override
    public void getBanner(String url, CallBack callBack) {
        RetrofitUtils.getRetrofit().create(Api.class).getBanner()
                .subscribeOn(Schedulers.io()).observeOn(AndroidSchedulers.mainThread())
                .subscribe(new Subscriber<BannerBean>() {
                    @Override
                    public void onCompleted() {
                        LogUtil.d("getData onCompleted");
                    }

                    @Override
                    public void onError(Throwable e) {
                        LogUtil.w("getData onError");
                    }

                    @Override
                    public void onNext(BannerBean articleListBean) {
                        if (null == articleListBean) {
                            callBack.onFailed("something was wrong");
                        } else {
                            if (articleListBean.errorCode != 0) {
                                callBack.onFailed(articleListBean.errorMsg);
                            } else {
                                callBack.onSuccess(articleListBean);
                            }
                        }

                    }
                });
    }
}
