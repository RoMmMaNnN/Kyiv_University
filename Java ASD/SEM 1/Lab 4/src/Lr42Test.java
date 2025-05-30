import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class Lr42Test {

    @Test
    void testTask2() {
        String fileText = "Line 1: first line.\nLine 2: second line.\nLine 3: third line.";
        String newLine = "Line 4: new line.";

        String expected = "Task 2 Result:\nLine 2: second line.\nLine 1: first line.\nLine 4: new line.\nLine 3: third line.\n";

        String result = Lr42.task2(fileText, newLine);
        assertEquals(expected, result);
    }

    @Test
    void testTask3zeroLines() {
        String fileText = "Line 1: first line.\nLine 2: second line 123.\nLine 3: third line.";
        String newLine = "Line 4: new line without numbers.";

        String expected = "Is not line without number";

        String result = Lr42.task3(fileText, newLine);
        assertEquals(expected, result);
    }

    @Test
    void testTask3() {
        String fileText = "Line 1: first line.\nLine 2: second line 123.\nLine 3: third line.";
        String newLine = "Line: new line without numbers.";

        String expected = "Task 3 Result (Lines without numbers):\nLine: new line without numbers.\n";

        String result = Lr42.task3(fileText, newLine);
        assertEquals(expected, result);
    }
}