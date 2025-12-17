package raytracer.core;

// Immutable class that stores a magnitude + direction pair
public class len3 {
    public final dir3 dir;
    public final double len;

    public len3(dir3 d, double m) {
        this.dir = d;
        this.len = Math.abs(m);
    }

    public len3(double X, double Y, double Z) {
        this.dir = new dir3(X, Y, Z);     
        this.len = Math.hypot(Math.hypot(X, Y), Z);
    }

    public len3(pos3 from, pos3 to) {
        this(to.X - from.X, to.Y - from.Y, to.Z - from.Z);
    }

    public len3(dir3 d) {
        this.dir = d;
        this.len = 1.0;
    }

    public double squared_len() {
        return this.len * this.len;
    }

    //read as `this` scaled by factor `t`
    public len3 scld(double t) {
        if(t < 0) 
            return new len3(this.dir.revd(), this.len*(-t)); 
        else
            return new len3(this.dir, this.len*t);
    }

    // read as `this` squished by factor `t`
    public len3 sqshd(double t) {
        if(t < 0)
            return new len3(this.dir.revd(), this.len/(-t));
        else
            return new len3(this.dir, this.len/t);
    }

    // read as reversed or reverse direction
    public len3 revd() {
        return new len3(dir.revd(), len);
    }

    public double dot(len3 other) {
        return this.len * other.len * this.dir.cosAngleWith(other.dir);
    }

    //for convienience [ could name it projectedLengthAbout(dir3) ]
    public double dot(dir3 other) {
        return this.len * this.dir.cosAngleWith(other);
    }

    @Override public String toString() {
        return "(" + dir + ", " + len + ")";
    }
}
