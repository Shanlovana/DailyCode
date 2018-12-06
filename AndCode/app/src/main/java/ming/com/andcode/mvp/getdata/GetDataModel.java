package ming.com.andcode.mvp.getdata;

import ming.com.andcode.mvp.base.IModel;
import ming.com.andcode.mvp.callback.CallBack;

public interface GetDataModel extends IModel {
    void getData(String url, int current, final CallBack callBack);
    void getBanner(String url,final CallBack callBack);
}
