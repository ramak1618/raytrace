package raytracer.core;

// Immutable class to store direction
public class dir3 {
    public final double X, Y, Z;

    public dir3(double x, double y, double z) {
        //safe way to calculate magnitude as hypot automatically takes care of underflow/overflow
        //magnitude is ensured to be non-bad unless input itself is Infinity / NaN
        double magnitude = Math.hypot(Math.hypot(x, y), z);
        if(magnitude == 0) 
            throw new IllegalArgumentException("Unexpected inputs (0, 0, 0), not a direction");
        if(Double.isInfinite(magnitude) || Double.isNaN(magnitude))
            throw new IllegalArgumentException("Unexpected input of Infinity / NaN");

        this.X = x/magnitude;
        this.Y = y/magnitude;
        this.Z = z/magnitude;
    }

    public dir3(pos3 from, pos3 to) {
        this(to.X - from.X, to.Y - from.Y, to.Z - from.Z);
    }

    // read as reversed or reverse direction
    public dir3 revd() {
        return new dir3(-this.X, -this.Y, -this.Z);
    }

    public len3 scld(double t) {
        return new len3(this, t);
    }

    public double cosAngleWith(dir3 d) {
        return this.X*d.X + this.Y*d.Y + this.Z*d.Z;
    }

    public dir3 abs(dir3 about) {
        if(this.cosAngleWith(about) < 0)
            return this.revd();
        else
            return this;
    }

    @Override public String toString() {
        return "(" + X + ", " + Y + ", " + Z + ")";
    }
}
