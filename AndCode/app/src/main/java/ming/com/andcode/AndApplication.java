package ming.com.andcode;

import android.app.Application;

import com.alibaba.android.arouter.launcher.ARouter;

import ming.com.andcode.dagger2.component.DaggerFlowerComponent;
import ming.com.andcode.dagger2.component.DaggerPotComponent;
import ming.com.andcode.dagger2.component.PotComponent;

public class AndApplication extends Application {
    private PotComponent potComponent;
    @Override
    public void onCreate() {
        super.onCreate();
        initializeARouter();
        initializePotComponent();
    }

    private void initializeARouter() {
        if (BuildConfig.DEBUG) {    // 这两行必须写在init之前，否则这些配置在init过程中将无效
            ARouter.openLog();     // 打印日志
            ARouter.openDebug();   // 开启调试模式(如果在InstantRun模式下运行，必须开启调试模式！线上版本需要关闭,否则有安全风险)
        }
        ARouter.init(AndApplication.this); // 尽可能早，推荐在Application中初始化
    }
    private void initializePotComponent() {//PotComponent位全局变量，且只有一个
        potComponent = DaggerPotComponent.builder()
                .flowerComponent(DaggerFlowerComponent.create())
                .build();
    }

    public PotComponent getPotComponent() {
        return potComponent;
    }
}
