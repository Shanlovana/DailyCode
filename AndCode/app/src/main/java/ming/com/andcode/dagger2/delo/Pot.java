package ming.com.andcode.dagger2.delo;


import javax.inject.Inject;


public class Pot {
    private Flower flower;

    @Inject
    public Pot( Flower mRose) {
        this.flower = mRose;
    }

    public String show() {
        return flower.whisper();
    }
}
