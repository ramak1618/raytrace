package raytracer.core;

public class viewport {
    public final len3 right;
    public final len3 forward;
    public final len3 up;

    public viewport(len3 r, len3 f, len3 u) {
        this.right = r;
        this.forward = f;
        this.up = u;
    }
}
