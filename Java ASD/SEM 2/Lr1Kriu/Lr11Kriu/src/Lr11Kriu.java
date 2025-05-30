public class Lr11Kriu {
    public static void main(String[] args) {
        Lr11String str1 = new Lr11String("I love my mum.");
        Lr11String str2 = new Lr11String("I love my dad.");
        Lr11String str3 = new Lr11String("");
        str3.setSentence("I love my sister");

        System.out.println("String 1: " + str1.getSentence());
        System.out.println("String 2: " + str2.getSentence());
        System.out.println("String 3: " + str3.getSentence());

        Lr11String str_concatenated = str1.concatenate(str2);
        System.out.println("Concatenation: " + str_concatenated.getSentence());

        Lr11String subStr = str3.substring(7, 9);
        System.out.println("Sub string: " + subStr.getSentence());

        System.out.println("Equals str1 and str2 ? " + str1.equals(str2));
        System.out.println("Unequals str1 and str2 ? " + str1.notEquals(str2));
        System.out.println("str2 < str3 ? " + str2.lessThan(str3));
        System.out.println("str2 > str3 ? " + str2.greaterThan(str3));
    }
}