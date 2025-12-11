import raytracer.extra.PPM;
import raytracer.core.*;
import raytracer.shapes.*;
import raytracer.materials.*;

class test {
    public static void main(String[] args) throws Exception {
        double wanted_aspect_ratio = 16.0 / 9.0;
        int image_width = 400;
        int image_height = (int)Math.round(image_width / wanted_aspect_ratio);

        //we need to do this to eliminate any round-off errors caused in calc of image_height
        double actual_aspect_ratio = (double)(image_width) / (double)(image_height);

        double focal_length = 1.0;
        double vp_height = 2.0;
        double vp_width = vp_height * actual_aspect_ratio;
        pos3 cam_center = new pos3(0, 0, 0);


        len3 vp_w = new len3(vp_width, 0, 0);
        len3 vp_h = new len3(0, 0, vp_height);
        len3 vp_f = new len3(0, focal_length, 0);

        diffuse grey = new diffuse(new color(0.5, 0.5, 0.5));

        hittable[] world = new hittable[] {
                                        new hittable(new sphere(new pos3(0, 1, 0), 0.5), grey),
                                        new hittable(new sphere(new pos3(0, 1, -100.5), 100), grey)
        };

        camera cam = new camera( new pos3(0, 0, 0), new viewport(vp_w, vp_f, vp_h), new resolution(image_width, image_height, 500) );

        renderer rndrr = new renderer(cam, world);
        rndrr.render();

        PPM.generateFile(rndrr.img, "test.ppm");
    }
}
