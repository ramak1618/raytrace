package raytracer.core;

// Immutable class to store position vector of an object
public class pos3 {
    public final double X, Y, Z;

    public pos3(double x, double y, double z) {
        this.X = x;
        this.Y = y;
        this.Z = z;
    }

    public dir3 dir() {
        return new dir3(this.X, this.Y, this.Z);
    }

    public pos3 step(len3 path) {
        return new pos3(this.X + path.len*path.dir.X, this.Y + path.len*path.dir.Y, this.Z + path.len*path.dir.Z);
    }

    @Override public String toString() {
        return "(" + X + ", " + Y + ", " + Z + ")";
    }
}

