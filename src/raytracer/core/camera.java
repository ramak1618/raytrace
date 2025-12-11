package raytracer.core;

public class camera {
    public final pos3 pos;
    public final viewport vp;
    public final resolution res;

    public camera(pos3 p, viewport v, resolution r) {
        this.pos = p;
        this.vp = v;
        this.res = r;
    }
}
