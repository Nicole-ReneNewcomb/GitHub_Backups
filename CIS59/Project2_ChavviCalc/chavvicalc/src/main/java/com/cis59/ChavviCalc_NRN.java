/* Nicole-Rene Newcomb's code for project 2:
 * a calculator for Chavvi. This program seeks
 * to provide the operations of a calculator
 * using JAVA.
 */

package com.cis59;

import java.util.*;

public class ChavviCalc_NRN 
{
    public static void main(String[] args) {
        // Create Scanner to Accept Keyboard Input
        Scanner scan = new Scanner(System.in);

        // Declare & Initialize Variables
        Character command = '_';
        float userInputA = 0.000f;
        float userInputB = 0.000f;
    
        // Calculator Loop - Repeats Until User Quits
        while (command != 'q') {
          printMenu(userInputA, userInputB);
          System.out.print("Enter a command: ");
          command = menuGetCommand(scan);
    
          executeCommand(scan, command);
        }
    
        scan.close();
      }
    
      
      // Function to Print Menu Block Seperation Lines
      private static void printMenuLine() {
        System.out.println(
          "----------------------------------------------------------"
        );
      }
    
      // Function to Print Formatted Menu Command Options
      private static void printMenuCommand(Character command, String desc) {
        System.out.printf("%s\t%s\n", command, desc);
      }
    
      // Function to Print Entire Menu
      public static void printMenu(float userInputA, float userInputB) {
        printMenuLine();
        System.out.println("Chavvi Calc");
        printMenuLine();
        System.out.printf("A = %,.3f\tB = %,.3f\n", userInputA, userInputB);
    
        printMenuCommand('a', "Enter a value for A");
        printMenuCommand('b', "Enter a value for B");
        printMenuCommand('+', "Add");
        printMenuCommand('-', "Subtract");
        printMenuCommand('*', "Multiply");
        printMenuCommand('/', "Divide");
        printMenuCommand('c', "Clear");
        printMenuCommand('q', "Quit");
    
        printMenuLine();
      }
    
      // get first character from input
      private static Character menuGetCommand(Scanner scan) {
        Character command = '_';
    
        String rawInput = scan.nextLine();
    
        if (rawInput.length() > 0) {
          rawInput = rawInput.toLowerCase();
          command = rawInput.charAt(0);
        }
    
        return command;
      }
    
      // calculator functions
      private static Boolean executeCommand(Scanner scan, Character command) {
        Boolean success = true;
    
        switch (command) {
          case 'q':
            System.out.println("Thank you for using Chavvi Calc");
            break;
          default:
            System.out.println("ERROR: Unknown commmand");
            success = false;
        }
    
        return success;
    }

    
}
