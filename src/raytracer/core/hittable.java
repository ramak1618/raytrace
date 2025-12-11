package raytracer.core;

public class hittable {
    public final shape shp;
    public final material mat;

    public hittable(shape s, material m) {
        shp = s;
        mat = m;
    }

    public double hit(ray incident) {
        return shp.hit(incident);
    }

    public dir3 normal(pos3 point) {
        return shp.normal(point);
    }

    public ray emergent(ray incident, dir3 normal, pos3 point) {
        return mat.emergent(incident, normal, point);
    }

    public ray emergent(ray incident, double t) {
        pos3 intersection = incident.at(t);
        dir3 normal = this.normal(intersection);
        return this.emergent(incident, normal, intersection);
    }
}

