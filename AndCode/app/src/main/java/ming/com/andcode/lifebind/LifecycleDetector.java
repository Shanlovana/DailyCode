package ming.com.andcode.lifebind;

import android.annotation.TargetApi;
import android.app.Activity;
import android.os.Build;

public class LifecycleDetector {

   private static final String FRAGMENT_TAG = "com.bumptech.glide.manager";

    private static volatile LifecycleDetector sInstance;

    public static LifecycleDetector getInstance() {
        if (sInstance == null) {
            synchronized (LifecycleDetector.class) {
                if (sInstance == null) {
                    sInstance = new LifecycleDetector();
                }
            }
        }

        return sInstance;
    }

    public void observer(Activity activity, LifecycleListener lifecycleListener) {
        // 获取当前activity的FragmentManager
        android.app.FragmentManager fm = activity.getFragmentManager();
        // 注册无UI的fragment
        LifecycleManagerFragment current = getRequestManagerFragment(fm);

        current.getLifecycle().addListener(lifecycleListener);
    }


    @TargetApi(Build.VERSION_CODES.JELLY_BEAN_MR1)
    LifecycleManagerFragment getRequestManagerFragment(final android.app.FragmentManager fm) {
        LifecycleManagerFragment current = (LifecycleManagerFragment) fm.findFragmentByTag(FRAGMENT_TAG);
        if (current == null) {
                current = new LifecycleManagerFragment();
                fm.beginTransaction().add(current, FRAGMENT_TAG).commitAllowingStateLoss();
        }
        return current;
    }
}
