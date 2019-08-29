package ming.com.andcode.lifebind;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class LifeUtil {
    public static <T> List<T> getSnapshot(Collection<T> other) {
        // toArray creates a new ArrayList internally and this way we can guarantee entries will not
        // be null. See #322.
        List<T> result = new ArrayList<T>(other.size());
        result.addAll(other);
        return result;
    }
}
