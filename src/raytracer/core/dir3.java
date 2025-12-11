package raytracer.core;

// Immutable class to store direction
public class dir3 {
    public final double X, Y, Z;

    public dir3(double x, double y, double z) {
        double magnitude = Math.sqrt(x*x + y*y + z*z);

        //special value for showing "null direction"
        if(magnitude < 1e-80) {
            this.X = 0.0;
            this.Y = 0.0;
            this.Z = 0.0;
        }
        else {
            this.X = x/magnitude;
            this.Y = y/magnitude;
            this.Z = z/magnitude;
        }
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

    public boolean isnull() {
        return this.X == this.Y && this.Y == this.Z && this.Z == 0.0;
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
