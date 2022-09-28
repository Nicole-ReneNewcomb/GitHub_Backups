/* Nicole-Rene Newcomb's code for project 2:
 * a calculator for Chavvi. This program seeks
 * to provide the operations of a calculator
 * using JAVA.
 */

package com.cis59;

import java.util.*;

public class ChavviCalc_NRN2 
{
    public static void main(String[] args) 
    {
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
            
            if (command == 'a')
            {
                userInputA = executeCommand(command);
            }
            else if (command == 'b')
            {
                userInputB = updateInputB(scan);
            }
            else if (command == 'c')
            {
                userInputA = 0.000f;
                userInputB = 0.000f;
            }
            else if (command == '+' || command == '-' || command == '*' || command == '/') {
                userInputA = executeCommand(command);
            }
            else {
                System.out.println("Please enter a single character shown on the menu.")
            }
        }
    
        scan.close();
    }
    

      
      // Function to Print Menu Block Seperation Lines
      private static void printMenuLine() 
      {
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
    
      // Function Returns Single Lowercase Character from User Input
      private static Character menuGetCommand(Scanner scan) {
        Character command = '_';
    
        String rawInput = scan.nextLine();
    
        // Converts Input to Lowercase and Keeps Only First Character
        if (rawInput.length() > 0) {
          rawInput = rawInput.toLowerCase();
          command = rawInput.charAt(0);
        }
    
        return command;
      }
    
      // Calculator Functions
      private static float executeCommand(Character command) {
        float calculationResult = 0.000f;
    
        switch (command) {
          case 'q':
            System.out.println("Thank you for using Chavvi Calc.");
            break;
          case 'a':
            System.out.println("Please enter a value for A.");
          default:
            System.out.println("ERROR: Unknown commmand. Please enter a single character option from the menu.");
            success = false;
        }
    
        return calculationResult;
      }

      // Function That Changes Value of A
      private static float updateInputA(Scanner scan) {

        // Instruct User to Input a Value for A
        System.out.println("Please enter a value for A.");
      }

      // Function That Changes Value of B
      private static float updateInputB(Scanner scan) {

        // Instruct User to Input a Value for A
        System.out.println("Please enter a value for A.");
    }
    
}
