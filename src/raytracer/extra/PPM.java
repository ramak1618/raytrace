package raytracer.extra;

import java.io.File;
import java.io.PrintStream;

import java.io.IOException;
import java.io.FileNotFoundException;

import raytracer.core.color;

public class PPM {
    private PPM() {}

    // data :: rows x cols x 3 
    // data.length = number of rows = height
    // data[0].length = number of cols = width
    /// a small realization: image is the only matrix in which we prefer to write the order as cols x rows
    public static void generateFile(int[][][] data, String filename) throws IOException, FileNotFoundException {
        // Truncate on open
        File ppmFile = new File(filename);
        if(ppmFile.exists()) ppmFile.delete();
        ppmFile.createNewFile();

        PrintStream stream = new PrintStream(ppmFile);

        //Magic number
        stream.println("P3");
        //width height
        stream.println(data[0].length + " " + data.length);
        //Max byte
        stream.println(255);

        for(int i=0; i<data.length; i++)
            for(int j=0; j<data[i].length; j++)
                stream.println(data[i][j][0] + " " + data[i][j][1] + " " + data[i][j][2]);
    }

    // pixels :: rows x cols
    // pixels.length = number of rows = height
    // pixels[0].length = number of cols = width
    public static void generateFile(color[][] pixels, String filename) throws IOException, FileNotFoundException {
        int[][][] data = new int[pixels.length][pixels[0].length][3];
        for(int i=0; i < pixels.length; i++) {
            for(int j=0; j < pixels[i].length; j++) {
                data[i][j][0] = (int)(255.999999 * pixels[i][j].red);
                data[i][j][1] = (int)(255.999999 * pixels[i][j].green);
                data[i][j][2] = (int)(255.999999 * pixels[i][j].blue);
            }
        }
        generateFile(data, filename);
    }
}
