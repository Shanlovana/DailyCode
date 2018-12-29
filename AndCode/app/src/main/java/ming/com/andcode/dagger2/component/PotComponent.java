package ming.com.andcode.dagger2.component;

import dagger.Component;
import dagger.Subcomponent;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.module.PotModule;

@Subcomponent(modules = PotModule.class)
public interface PotComponent {
   DaggerActivityComp plus();
}
