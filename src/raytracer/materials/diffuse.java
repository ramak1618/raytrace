package raytracer.materials;

import raytracer.core.*;
import raytracer.utils.math;

public class diffuse extends material {
    public final color albedo;

    public diffuse(color a) {
        this.albedo = a;
    }

    @Override public ray emergent(ray incident, dir3 normal, pos3 point) {
        return new ray(point, math.random_dir().abs(normal), incident.clr.mix(albedo));
    }
}
    
