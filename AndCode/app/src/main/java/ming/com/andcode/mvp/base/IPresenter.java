package ming.com.andcode.mvp.base;

public interface IPresenter<T extends IView> {
    void attachView(T view);

    void detachView();

    boolean isAttached();

}
