package ming.com.andcode.dagger2.delo;


import javax.inject.Inject;

import ming.com.andcode.dagger2.qualifier.RoseFlower;


public class Pot {
    private Flower flower;

    @Inject
    public Pot(@RoseFlower Flower mRose) {
        this.flower = mRose;
    }

    public String show() {
        return flower.whisper();
    }
}
