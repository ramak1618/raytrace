package raytracer.core;

public class resolution {
    public final int width;
    public final int height;
    public final int samples_per_pixel;

    public resolution(int w, int h, int spp) {
        this.width = w;
        this.height = h;
        this.samples_per_pixel = spp;
    }
}
