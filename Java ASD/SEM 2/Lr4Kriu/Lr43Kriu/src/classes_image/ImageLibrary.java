package classes_image;

import my_set_and_map.*;
import java.awt.Image;

public class ImageLibrary {
    private final MyHashMap<String, Image> imageMap;
    private final MyTreeSet<String> imageNames;

    public ImageLibrary() {
        imageMap = new MyHashMap<>();
        imageNames = new MyTreeSet<>();
    }

    public boolean addImage(String name, Image image) {
        if (imageNames.contains(name)) return false;
        imageMap.put(name, image);
        imageNames.add(name);
        return true;
    }

    public MyImage searchImageByName(String name) {
        if (imageMap.containsKey(name)) {
            return new MyImage(name, imageMap.get(name));
        }
        return null;
    }

    public String getFormattedData() {
        StringBuilder sb = new StringBuilder("Список зображень у бібліотеці:\n");
        for (String name : imageNames) {
            sb.append("- ").append(name).append("\n");
        }
        return sb.toString();
    }

    public MyImage[] getAllEntries() {
        MyImage[] result = new MyImage[imageNames.size()];
        int index = 0;
        for (String name : imageNames) {
            result[index++] = new MyImage(name, imageMap.get(name));
        }
        return result;
    }
}
