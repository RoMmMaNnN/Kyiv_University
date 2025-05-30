package classes_image;

import java.awt.Image;

public class MyImage {
    private String name;
    private Image image;

    public MyImage(String name, Image image) {
        this.name = name;
        this.image = image;
    }

    public String getName() { return name; }
    public Image getImage() { return image; }
}
