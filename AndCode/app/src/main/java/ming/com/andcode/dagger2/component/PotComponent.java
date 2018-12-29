package ming.com.andcode.dagger2.component;

import dagger.Component;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.module.PotModule;

@Component(modules = PotModule.class, dependencies = FlowerComponent.class)
public interface PotComponent {
    Pot getPot();
}
