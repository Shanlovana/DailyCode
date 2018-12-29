package ming.com.andcode.dagger2.delo;


import javax.inject.Inject;

public class Lily extends Flower {
    @Inject
    public Lily() {
    }

    @Override
    public String whisper() {
        return "My lover Lily";
    }
}
