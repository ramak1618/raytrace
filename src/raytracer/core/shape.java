package raytracer.core;

public abstract class shape {
    public abstract double hit(ray incident);
    public abstract dir3 normal(pos3 point);
}
