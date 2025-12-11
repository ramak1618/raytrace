package raytracer.shapes;

import raytracer.core.*;

public class sphere extends shape {
    public final pos3 center;
    public final double radius;

    public sphere(pos3 c, double r) {
        this.center = c;
        this.radius = r;
    }

    @Override public double hit(ray incident) {
        len3 center_wrt_src = new len3(incident.src, center);
        double s = center_wrt_src.dot(incident.dir);
        double p = center_wrt_src.squared_len() - radius*radius;
        double D = s*s - p;

        if(D > 0) {
            if(s > 0 && p > 0)
                return s - Math.sqrt(D);
            else if(p < 0)
                return s + Math.sqrt(D);
        }

        return Double.POSITIVE_INFINITY;
    }

    @Override public dir3 normal(pos3 point) {
        return new dir3(center, point);
    }
}
