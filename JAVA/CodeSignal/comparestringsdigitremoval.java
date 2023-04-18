public class comparestringsdigitremoval {
    public static void main(String args[]) {
        String stringA = "h3ab";
        String stringB = "4i2efghfgh23cd";
        int numberWays = 0;

        for (int i = 0; i < stringA.length(); i++) {
            if (Character.isDigit(stringA.charAt(i))) {
                String removedA = stringA.substring(0, i) + stringA.substring(i+1, stringA.length());
                if (removedA.compareTo(stringB) < 0) {
                    numberWays++;
                }
            }
        }
        for (int i = 0; i < stringB.length(); i++) {
            if (Character.isDigit(stringB.charAt(i))) {
                String removedB = stringB.substring(0, i) + stringB.substring(0+1, stringB.length());
                if (removedB.compareTo(stringA) > 0) {
                    numberWays++;
                }
            }
        }
        System.out.println(numberWays);
    }
}
