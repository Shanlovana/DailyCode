package ming.com.andcode.dagger2.component;

import dagger.Component;
import dagger.Subcomponent;
import ming.com.andcode.dagger2.DaggerActivity;


@Subcomponent
public interface DaggerActivityComp {
    void inject(DaggerActivity daggerActivity);
}
