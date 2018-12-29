package ming.com.andcode.dagger2.delo;


import javax.inject.Inject;



public class Rose extends Flower {
    @Inject
    public Rose() {
    }

    @Override
    public String whisper() {
        return "My lover Rose";
    }
}
