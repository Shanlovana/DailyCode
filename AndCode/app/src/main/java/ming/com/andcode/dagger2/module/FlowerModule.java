package ming.com.andcode.dagger2.module;


import dagger.Module;
import dagger.Provides;
import ming.com.andcode.dagger2.delo.Flower;

import ming.com.andcode.dagger2.delo.Lily;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.delo.Rose;


@Module
public class FlowerModule {


    @Provides
    Flower provideRose() {
        return new Rose();
    }

    @Provides
    Pot providePot() {
        return new Pot(new Lily());
    }

}
