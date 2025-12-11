package raytracer.core;

// Immutable class to store color
public class color {
    public final double red, green, blue;

    public color(double R, double G, double B) {
        this.red = R;
        this.green = G;
        this.blue = B;
    }

    public color intensified(double t) {
        return new color(this.red*t, this.green*t, this.blue*t);
    }

    public color mix(color c) {
        return new color(this.red*c.red, this.green*c.green, this.blue*c.blue);
    }

    public color gamma2() {
        return new color(Math.sqrt(this.red), Math.sqrt(this.green), Math.sqrt(this.blue));
    }

    @Override public String toString() {
        return "(" + this.red + "r, " + this.green + "g, " + this.blue + "b)";
    }
}
