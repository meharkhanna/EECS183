/**
 * focaccia.cpp
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 *
 *
 * EECS 183: Project 1
 * Fall 2024
 *
 * This code calculates the cost of materials required to make a loaf of foccacia bread, dependent on the number of people needing to be served.
 *
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 */
string pluralize(string singular, string plural, int number);

int main() {

    // Declare how many units of ingredient are needed for each loaf
    const double cupsFlour = 5.0;
    const double teaspoonsYeast = 1.75;
    const double teaspoonsSalt = 1.875;
    const double tablespoonsOil = 2.0;
    
    // Declare units in each package of ingredient
    const int cupsFlourBag = 20;
    const double tspnYeastPackage = 2.25;
    const double tspnSaltCanister = 30 / 5;
    const double tblspnOilBottle = 500 / 14.8;
    
    // Calculate how many loaves can be produced from each package of ingredient
    const double cupsFlourPerLoaf = cupsFlourBag / cupsFlour;
    const double tspnYeastLoaf = tspnYeastPackage / teaspoonsYeast;
    const double tspnSaltLoaf = tspnSaltCanister / teaspoonsSalt;
    const double tblspnOilLoaf = tblspnOilBottle / tablespoonsOil;
    
    // Declare cost per package of ingredient
    const double costFlourBag = 2.69;
    const double costYeastPackage = 0.40;
    const double costSaltCanister = 0.49;
    const double costOilBottle = 6.39;

    // Ask for people input
    int people;
        cout << "How many people do you need to serve? ";
        cin >> people;
    
    // Calculate and print number of loaves
    int numLoaves = ceil(people / 4.0);
        cout << endl << endl << "You need to make: " << numLoaves << " " <<
            pluralize("loaf", "loaves", numLoaves) <<
            " of focaccia" << endl << endl;

    // Calculate number of packages needed of each ingredient
    double numFlourBag = ceil(numLoaves / cupsFlourPerLoaf);
    double numYeastPackage = ceil(numLoaves / tspnYeastLoaf);
    double numSaltCanister = ceil(numLoaves / tspnSaltLoaf);
    double numOilBottle = ceil(numLoaves / tblspnOilLoaf);

    // Calculate how much each ingredient will cost
    double flourCost = numFlourBag * costFlourBag;
    double yeastCost = numYeastPackage * costYeastPackage;
    double saltCost = numSaltCanister * costSaltCanister;
    double oilCost = numOilBottle * costOilBottle;

    // Print shopping lists with numbers of items
    cout << "Shopping List for Focaccia Bread" << endl <<
        "--------------------------------" << endl;
    
    cout << numFlourBag << " " <<
        pluralize("bag", "bags", numFlourBag) <<
        " of flour" << endl;
    
    cout << numYeastPackage << " " <<
        pluralize("package", "packages", numYeastPackage) <<
        " of yeast" << endl;

    cout << numSaltCanister << " " <<
        pluralize("canister", "canisters", numSaltCanister) <<
        " of salt" << endl;
   
    cout << numOilBottle << " " <<
        pluralize("bottle", "bottles", numOilBottle) <<
        " of olive oil" << endl << endl;
    
    // Calculate and print total cost
    double totalCost = flourCost + yeastCost + saltCost + oilCost;
    float rtotalCost = round(totalCost*100)/100;
    cout << "Total expected cost of ingredients: $" << rtotalCost << endl << endl;
    cout << "Have a great party!";


    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
