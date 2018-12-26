/*
package ming.com.andcode.arouter;

import android.content.Context;
import android.util.Log;

import com.alibaba.android.arouter.facade.Postcard;
import com.alibaba.android.arouter.facade.annotation.Interceptor;
import com.alibaba.android.arouter.facade.callback.InterceptorCallback;
import com.alibaba.android.arouter.facade.template.IInterceptor;

@Interceptor(priority = 1)
public class LoginInterceptor implements IInterceptor {
    private static final String TAG = "LoginInterceptor";

    private Context mContext;

    @Override
    public void process(Postcard postcard, InterceptorCallback callback) {

        String name=Thread.currentThread().getName();
        Log.i(TAG, "LoginInterceptor begain to process"+"thread name is"+name);
        if (postcard.getPath().equals("/moduleone/ModulerMainActivity")){
            Log.i(TAG, "LoginInterceptor process is interceptor ");
        }
    }

    @Override
    public void init(Context context) {
        mContext = context;

        Log.i(TAG, "LoginInterceptor init");

    }
}
*/
