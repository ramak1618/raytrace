package raytracer.core;

import raytracer.utils.math;

public class renderer {
    public final camera cam;
    public final hittable[] objs;
    public final color[][] img;

    public renderer(camera c, hittable[] o) {
        this.cam = c;
        this.objs = o;

        this.img = new color[c.res.height][c.res.width];
    }

    /// we'll leave this function unbounded until i stack overflow
    public color getColor(ray incident) {
        double[] hits = new double[objs.length];
        for(int i=0; i<objs.length; i++) {
            double t = objs[i].hit(incident);
            hits[i] = t < 1e-5 ? Double.POSITIVE_INFINITY : t;
        }
        int closest = math.idxOfMin(hits);
        if(hits[closest] != Double.POSITIVE_INFINITY) {
            return getColor(objs[closest].emergent(incident, hits[closest]));
        }
        else {
            double alpha = 0.5 * (incident.dir.Z + 1.0);
            return new color(1 - 0.5*alpha, 1 - 0.3*alpha, 1.0).mix(incident.clr);
        }
    }

    public void render() {
        len3 vp_dr = cam.vp.right.sqshd(cam.res.width);
        len3 vp_dd = cam.vp.up.revd().sqshd(cam.res.height);
        
        pos3 vp_top_left = cam.pos.step(cam.vp.forward)
                                  .step(cam.vp.right.revd().sqshd(2))
                                  .step(cam.vp.up.sqshd(2))
                                  .step(vp_dr.sqshd(2))
                                  .step(vp_dd.sqshd(2));
        

        for(int i=0; i<cam.res.height; i++) {
            for(int j=0; j<cam.res.width; j++) {

                color[] samples = new color[cam.res.samples_per_pixel];
                for(int k=0; k<cam.res.samples_per_pixel; k++) {
                    double r_off = math.random(0, 0.5);
                    double d_off = math.random(0, 0.5);
                    pos3 pixel = vp_top_left.step(vp_dr.scld(j + r_off)).step(vp_dd.scld(i + d_off));
                    ray incident = new ray(cam.pos, pixel, new color(1.0, 1.0, 1.0));

                    samples[k] = getColor(incident);
                }

                img[i][j] = math.avg(samples).gamma2();
            }
        }

    }
}
