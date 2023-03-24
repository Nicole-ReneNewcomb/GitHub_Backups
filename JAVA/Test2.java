public class Test2 {
    public static void main(String[] args) {
        class Acquaintance {
            public String name;
            
            Acquaintance(String name) {
                this.name = name;
            }
            
            public void getStatus() {
                    System.out.println(name + "is just an acquaintance.");   
                } 
        }
        
        class Friend extends Acquaintance {
            public String homeTown;
            
            public Friend(String name, String homeTown) {
                super(name);
                this.homeTown = homeTown;
            }
            
            public void getStatus() {
                    System.out.println(name + "is a friend and he is from " + homeTown + ".");
                }
        }
        
        class BestFriend extends Friend {
            public String favoriteSong;
            
            public BestFriend(String name, String homeTown, String favoriteSong) {
                super(name, homeTown);
                this.favoriteSong = favoriteSong;
            }
            
            public void getStatus() {
                    System.out.println(name + "is my best friend. He is from " 
                    + homeTown + " and his favorite song is " + favoriteSong);
                }
    }
} 
