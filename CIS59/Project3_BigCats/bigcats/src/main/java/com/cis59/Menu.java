package com.cis59;

import java.util.*;

/*
 * Menu class for the african big cat app
 */
public class Menu {

    // attributes
    private Scanner input;

    // constructor
    public Menu() {

        // initialize attributes
        this.input = new Scanner(System.in);

    }

    // prints the menu
    public void print() {

        printLine();
        System.out.println("African Big Cats App");
        printLine();

        /*
         * TIP:
         * In this area of the code, the additional commands need to be created and
         * added to the menu.
         */

        printCommand('c', "[C]reates a big cat");
        printCommand('d', "[D]eletes a big cat");
        printCommand('f', "[F]inds a big cat");
        printCommand('l', "[L]ists all big Cats");
        printCommand('r', "[R]isk Report");
        printCommand('w', "[W]arning Report");
        printCommand('q', "[Q]uits");

        printLine();

    }

    private static void printLine() {
        System.out.println("----------------------------------------------------------");
    }

    private static void printCommand(Character command, String desc) {
        System.out.printf("%s\t%s\n", command, desc);
    }

    // get first character from input
    public Character getCommand() {

        Character command = '_';

        String rawInput = input.nextLine();

        if (rawInput.length() > 0) {
            rawInput = rawInput.toLowerCase();
            command = rawInput.charAt(0);
        }

        return command;

    }

    // command switch
    public Boolean executeCommand(Character command, LinkedList<Panthera> catList) {

        Boolean success = true;

        /*
         * TIP:
         * In this area of the code, the additional commands need to be created and
         * added.
         */

        switch (command) {

            case 'c':
                executeCreate(catList);
                break;

            case 'd':
                executeDeleteCat(catList);
                break;

            case 'f':
                executeFindCat(catList);
                break;

            case 'l':
                executeList(catList);
                break;

            case 'r':
                executeRiskReport(catList);
                break;

            case 'w':
                executeWarning(catList);
                break;

            case 'q':
                executeQuit();
                break;

            default:
                System.out.println("ERROR: Unknown commmand");
                success = false;
        }

        return success;
    }

    // update the position of all the cats
    public void update(LinkedList<Panthera> catList) {

        // update by moving all the cats
        for (Panthera cat : catList) {
            cat.move();
        }

    }

    // quit the app
    public void executeQuit() {

        // close the scannner
        input.close();

        System.out.println();
        printLine();
        System.out.println("Thank you for using the African Big Cats App!");
        printLine();
        System.out.println();

    }

    public Panthera getNewCat(String name) {

        /*
         * TIP:
         * In this area of the code, students need to get input from the user for the
         * type of cat
         * and create the correct type.
         * 
         * Currently, the code always create a Tiger. But, support for Lions and Jaguars
         * also needs to be added.
         * 
         */

        // request user input to determine big cat type
        Panthera result = null;

        System.out.println("Is this big cat a tiger, lion, or jaguar? Please enter here: ");
        String userInput = input.nextLine();

        // convert input to lowercase
        if (userInput.length() > 0) {
            userInput = userInput.toLowerCase();
        }

        // input validation loop to ensure entries match tiger, lion, or jaguar
        while (!(userInput.equals("tiger") || userInput.equals("lion") || userInput.equals("jaguar"))) {
            this.input = new Scanner(System.in);
            System.out.println("Please enter one of the following options - tiger, lion, or jaguar: ");
            userInput = input.nextLine();
            userInput = userInput.toLowerCase();
        }

        // decision tree to create object of user-entered big cat type
        if (userInput.equals("tiger")) {
            result = new Tiger(name);
        }

        else if (userInput.equals("lion")) {
            result = new Lion(name);
        }

        else if (userInput.equals("jaguar")) {
            result = new Jaguar(name);
        }

        else {
            System.out.println("Error: Invalid input. Please be sure to enter tiger, lion, or jaguar only: ");
        }

        return result;

    }

    // create a cat, if it's unique
    public void executeCreate(LinkedList<Panthera> catList) {

        // get the name
        System.out.println();
        System.out.print("Enter a name for the big cat to create: ");
        String name = input.nextLine();
        System.out.println();

        /*
         * TIP:
         * In this area of the code, students would need to add in checking if the cat
         * name
         * already exists in order to prevent duplicates
         */

        // declare Panthera and string to hold linked list cat entries
        Panthera catEntry;
        String catName;
        boolean uniqueName;

        // loop to ensure valid, non-duplicate input for cat name
        do {

            // set unique name flag to true at start of loop
            uniqueName = true;

            // retrieve existing cat names from linked list via loop
            for (Integer i = 0; i < catList.size(); i++) {
                catEntry = catList.get(i);
                catName = catEntry.name();

                // if cat name matches user input, prints error message
                if (catName.equals(name)) {

                    // sets unique name flag to false and requests new name
                    uniqueName = false;
                    input = new Scanner(System.in);
                    System.out.println();
                    System.out.println("A cat by this name already exists. Please enter a unique name: ");
                    name = input.nextLine();
                }
            }

        } while (uniqueName == false);

        Panthera cat = getNewCat(name);
        catList.add(cat);

    }

    // list all big cats
    public void executeList(LinkedList<Panthera> catList) {

        System.out.println();
        printLine();
        System.out.println("African Big Cat List");
        printLine();

        Panthera cat;
        if (catList.size() > 0) {
            for (Integer i = 0; i < catList.size(); i++) {
                cat = catList.get(i);
                System.out.println(cat);
            }
        } else {
            System.out.println("There are no African Big Cats. :(");
        }

        System.out.println();

    }

    public void executeDeleteCat(LinkedList<Panthera> catList) {

        // declare Panthera and string to hold linked list cat entries
        Panthera catEntry;
        String catName;
        boolean nameExists = false;
        char userConfirmation = '_';

        // request user input to select name of cat for deletion
        System.out.println();
        System.out.print("Please enter the name of the cat to be deleted: ");
        String name = input.nextLine();
        System.out.println();

        do {

            // retrieve existing cat names from linked list via loop
            for (int i = 0; i < catList.size(); i++) {
                catEntry = catList.get(i);
                catName = catEntry.name();

                // if cat entry has matching name
                if (catName.equals(name)) {

                    // sets name exists flag to true
                    nameExists = true;

                    // requests confirmation of delete command
                    System.out.println("The entry for " + name + " was found.");
                    System.out.println();
                    System.out.println("Are you sure you wish to delete? Enter Y or N: ");
                    userConfirmation = input.next().toLowerCase().charAt(0);

                    // if delete confirmed
                    if (userConfirmation == 'y') {
                        catList.remove(i);
                        System.out.println();
                        input = new Scanner(System.in);
                    }

                    else if (userConfirmation == 'n') {
                        System.out.println();
                        input = new Scanner(System.in);
                        break;
                    }

                }
            }

            // loop to request valid name of existing cat
            if (nameExists == false) {
                input = new Scanner(System.in);
                System.out.println();
                System.out.println("No cat by this name was found. Please enter another name or enter quit to exit: ");
                name = input.nextLine();
                System.out.println();
            }

            if (name.equals("quit")) {
                System.out.println();
                input = new Scanner(System.in);
                break;
            }

        } while (nameExists == false);
    }

    public void executeFindCat(LinkedList<Panthera> catList) {

        String userInput;
        Panthera cat;
        String catName;
        boolean catFound = false;

        // request and store user input
        System.out.println("Please enter the name of the cat you wish to find: ");
        userInput = input.nextLine();
        userInput = userInput.toLowerCase();

        // retrieve cat names from linked list via loop
        for (Integer i = 0; i < catList.size(); i++) {
            cat = catList.get(i);
            catName = cat.name();

            // if cat name matches user input, prints out cat information
            if (catName.contains(userInput)) {

                System.out.println(cat);
                catFound = true;
            }

        }

        // if cat not found, output message to user
        if (catFound == false) {
            System.out.println("Sorry, no cat by that name was found.");
        }

    }

    public void executeRiskReport(LinkedList<Panthera> catList) {
        String userInput1;
        String userInput2;
        Panthera cat1;
        Panthera cat2;
        String catName1;
        String catName2;
        boolean catFound1 = false;
        boolean catFound2 = false;
        double cat1Latitude;
        double cat1Longitude;
        double cat2Latitude;
        double cat2Longitude;
        double distanceDegrees;
        double distanceKilometers;

        // request and store user input for cat1
        System.out.println("Please enter the name of the first cat: ");
        userInput1 = input.nextLine();
        userInput1 = userInput1.toLowerCase();

        do {
            // retrieve cat name from linked list via loop
            for (Integer i = 0; i < catList.size(); i++) {
                cat1 = catList.get(i);
                catName1 = cat1.name();

                // if cat name matches user input, locate and store coordinates
                if (catName1.equals(userInput1)) {

                    cat1Latitude = cat1.latitude();
                    cat1Longitude = cat1.longitude();
                    catFound1 = true;
                }

                // loop to request valid name of existing cat
                if (catFound1 == false) {
                    input = new Scanner(System.in);
                    System.out.println();
                    System.out.println(
                            "No cat by this name was found. Please enter another name or enter quit to exit: ");
                    catName1 = input.nextLine();
                    System.out.println();
                }

                if (catName1.equals("quit")) {
                    System.out.println();
                    input = new Scanner(System.in);
                    break;
                }

            }
        } while (catFound1 == false);

        // request and store user input for cat1
        System.out.println("Please enter the name of the second cat: ");
        userInput2 = input.nextLine();
        userInput2 = userInput2.toLowerCase();

        do {
            // retrieve cat name from linked list via loop
            for (Integer i = 0; i < catList.size(); i++) {
                cat2 = catList.get(i);
                catName2 = cat2.name();

                // if cat name matches user input, locate and store coordinates
                if (catName2.equals(userInput2)) {

                    cat2Latitude = cat2.latitude();
                    cat2Longitude = cat2.longitude();
                    catFound2 = true;
                }

                // loop to request valid name of existing cat
                if (catFound2 == false) {
                    input = new Scanner(System.in);
                    System.out.println();
                    System.out.println(
                            "No cat by this name was found. Please enter another name or enter quit to exit: ");
                    catName2 = input.nextLine();
                    System.out.println();
                }

                if (catName2.equals("quit")) {
                    System.out.println();
                    input = new Scanner(System.in);
                    break;
                }

            }
        } while (catFound2 == false);

        // calculate distance between two cats
        distanceDegrees = Math
                .sqrt(Math.pow((cat2Longitude - cat1Longitude), 2) + Math.pow((cat2Latitude - cat1Latitude), 2));
        distanceKilometers = distanceDegrees * 111;

        // output distance between the two cats
        System.out.println(
                "The distance between these two cats is " + distanceDegrees + " or " + distanceKilometers + " km");

    }

    public void executeWarning(LinkedList<Panthera> catList)
    {
        System.out.println("Testing");
    }
}