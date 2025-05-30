import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Lr41Test {
    Lr41 o = new Lr41();
    
    @Test
    void testTask1_SimpleReplacement() {
        String input = "I want to learn Java, and I want to succeed.";
        String target = "want to";
        String replacement = "wanna";

        String expected = "I want to learn Java, and I wanna succeed.";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_NoOccurrences() {
        String input = "I like to learn Java.";
        String target = "want to";
        String replacement = "wanna";

        String expected = "I like to learn Java.";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_AllOccurrencesReplaced() {
        String input = "I want to learn, want to eat, want to sleep.";
        String target = "want to";
        String replacement = "wanna";

        String expected = "I want to learn, wanna eat, want to sleep.";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_OverlappingTargets() {
        String input = "I want to want to dream.";
        String target = "want to";
        String replacement = "wanna";

        String expected = "I want to wanna dream.";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_EmptyInput() {
        String input = "";
        String target = "want to";
        String replacement = "wanna";

        String expected = "";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_EmptyTarget() {
        String input = "I want to learn Java.";
        String target = "";
        String replacement = "wanna";

        String expected = "I want to learn Java.";
        assertEquals(expected, o.task1(input, target, replacement));
    }

    @Test
    void testTask1_EmptyReplacement() {
        String input = "I want to learn Java, and I want to succeed.";
        String target = "want to";
        String replacement = "";

        String expected = "I want to learn Java, and I  succeed.";
        assertEquals(expected, o.task1(input, target, replacement));
    }
}