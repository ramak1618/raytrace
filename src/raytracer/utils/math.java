package raytracer.utils;

import raytracer.core.dir3;
import raytracer.core.color;

public /* namespace */ class math {
    private math() {}

    public static int idxOfMin(double[] array) {
        double min = array[0];
        int track = 0;
        for(int i=1; i<array.length; i++) {
            if(min > array[i]) {
                min = array[i];
                track = i;
            }
        }
        return track;
    }

    //generates random number in range [min, max)
    public static double random(double min, double max) {
        return min + (max - min) * (Math.random());
    }

    public static dir3 random_dir() {
        dir3 ret = new dir3(0, 0, 0); 
        while(ret.isnull()) 
            ret = new dir3(random(-1, 1), random(-1, 1), random(-1, 1));
        
        return ret;
    }

    public static color avg(color[] cols) {
        double red = 0, green = 0, blue = 0;
        for(int i=0; i<cols.length; i++) {
            red += cols[i].red;
            green += cols[i].green;
            blue += cols[i].blue;
        }

        return new color(red / cols.length, green / cols.length, blue / cols.length);
    }
}
