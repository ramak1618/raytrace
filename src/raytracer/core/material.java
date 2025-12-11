package raytracer.core;

public abstract class material {
    public abstract ray emergent(ray incident, dir3 normal, pos3 point);
}
