package ming.com.andcode.mvp.getdata;

import ming.com.andcode.mvp.base.IView;
import ming.com.andcode.mvp.getdata.bean.ArticleListBean;
import ming.com.andcode.mvp.getdata.bean.BannerBean;

public interface GetDataContract {
    interface View<T> extends IView {
        void showSuccessMsg(T bean);

        void showFaiedMsg(String msg);

    }

    interface Presenter {
        void getData(String url, int current);

        void getBanner(String baseUrl);
    }
}
