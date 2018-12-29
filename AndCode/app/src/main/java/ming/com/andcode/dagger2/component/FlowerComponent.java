package ming.com.andcode.dagger2.component;

import dagger.Component;
import dagger.Module;
import ming.com.andcode.dagger2.delo.Flower;
import ming.com.andcode.dagger2.module.FlowerModule;
import ming.com.andcode.dagger2.qualifier.LilyFlower;
import ming.com.andcode.dagger2.qualifier.RoseFlower;

@Component(modules = FlowerModule.class)
public interface FlowerComponent {
    @RoseFlower
    Flower getRoseFlower();

    @LilyFlower
    Flower getLilyFlower();

}
