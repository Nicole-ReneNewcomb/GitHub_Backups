package com.cis59;

import java.util.Random;

/*
 * Panthera base class that simulates GPS information
 */
public class Panthera extends PantheraGPS {

    /*
        TIP:
        Students will need to add additional attributes and methods to complete this classes
        implementation.
     */

    // weight attribute
    private int catWeight;
    private Random weightRandom;
    private Random catSpeedRandom;

    // constructor
    public Panthera(String name) {

        // call the super-class (parent) to instatiate it
        super(name);

        // initialize attributes
        this.setSpecies("panthera");

        // set weight of cats
        this.weightRandom = new Random();
        this.weightRandom.setSeed(this.seed(name + this.species()));
        this.catWeight = 10 + weightRandom.nextInt(600);

        // create random speed for cats
        this.catSpeedRandom = new Random();
        this.catSpeedRandom.setSeed(this.seed(this.name() + this.catWeight));
    }

    // serializes attributes into a string
    @Override // override superclass method
    public String toString() {
        String s;

        // since the object is complex, we return a JSON formatted string
        s = "{ ";
        s += "name: " + this.name();
        s += ", ";
        s += "species: " + this.species();
        s += ", ";
        s += "longitude: " + this.longitude();
        s += ", ";
        s += "latitude: " + this.latitude();
        s += " }";

        return s;

    }

    // function returns weight of cat
    public int getWeight()
    {
        return this.catWeight;
    }

    // function prints out “Rrrrrrrrroooooooaaaaarrrrr!”
    public void roar()
    {
        System.out.println("Rrrrrrrrroooooooaaaaarrrrr!");
    }

    // function returns current speed (random) of cat
    public float getSpeed()
    {
        float catSpeed = this.catSpeedRandom.nextFloat(50);

        return catSpeed;
    }


}
