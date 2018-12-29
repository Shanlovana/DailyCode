package ming.com.andcode.dagger2.module;


import dagger.Module;
import dagger.Provides;
import ming.com.andcode.dagger2.delo.Flower;

import ming.com.andcode.dagger2.delo.Lily;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.delo.Rose;
import ming.com.andcode.dagger2.qualifier.LilyFlower;
import ming.com.andcode.dagger2.qualifier.RoseFlower;


@Module
public class FlowerModule {

    @Provides
    @RoseFlower
    Flower provideRose() {
        return new Rose();
    }

    @Provides
    @LilyFlower
    Flower provideLily() {
        return new Lily();
    }

}
