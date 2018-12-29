package ming.com.andcode.dagger2.module;

import dagger.Module;
import dagger.Provides;
import ming.com.andcode.dagger2.delo.Flower;
import ming.com.andcode.dagger2.delo.Pot;
import ming.com.andcode.dagger2.qualifier.LilyFlower;

@Module
public class PotModule {

    @Provides
    Pot providePot(@LilyFlower Flower flower) {
        return new Pot(flower);
    }
}
