//
//  main.cpp
//  movieRatings

//Inputs: The program takes in different movie objects. Each movie object has its own name and movie rating for example, G,PG, PG-13, R).

// Outputs: The program will output the movie title, the rating of the movie, as well as the average rating for it.
//
//  Created by Ryan Munguia on 7/25/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cstring>
#include "MovieInfo.h"
using namespace std;

int main(int argc, const char * argv[]) {
    movieInfo SpiderMan ("Spiderman", "PG-13");
    SpiderMan.addRating(5);
    SpiderMan.addRating(4);
    SpiderMan.addRating(4);
    SpiderMan.addRating(5);
    
    movieInfo WonderWoman ("Wonder Woman", "G");
    WonderWoman.addRating(3);
    WonderWoman.addRating(3);
    WonderWoman.addRating(3);
    WonderWoman.addRating(3);
    //WonderWoman.addRating(9);
    
    movieInfo BatMan ("Batman", "R");
    BatMan.addRating(5);
    BatMan.addRating(5);
    BatMan.addRating(5);
    BatMan.addRating(5);
    BatMan.addRating(4);
    BatMan.addRating(5);
    
    cout << SpiderMan.name() << " is rated: " << SpiderMan.getMPAA() << ", with an average rating of: " << SpiderMan.getAverage() << endl << endl;;
    
    cout << WonderWoman.name() << " is rated: " << WonderWoman.getMPAA() << ", with an average rating of: " << WonderWoman.getAverage() << endl << endl;
    
     cout << BatMan.name() << " is rated: " << BatMan.getMPAA() << ", with an average rating of: " << BatMan.getAverage() << endl << endl;

    return 0;
}
