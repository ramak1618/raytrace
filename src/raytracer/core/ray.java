package raytracer.core;

public class ray {
    public final pos3 src;
    public final dir3 dir;
    public final color clr;

    public ray(pos3 s, dir3 d, color c) {
        this.src = s;
        this.dir = d;
        this.clr = c;
    }

    public ray(pos3 from, pos3 to, color c) {
        this.src = from;
        this.dir = new dir3(to.X - from.X, to.Y - from.Y, to.Z - from.Z);
        this.clr = c;
    }

    public pos3 at(double t) {
        return src.step(dir.scld(t));
    }
}
