//
//  MovieRatings.cpp
//  movieRatings
//
//  Created by Ryan Munguia on 7/25/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include "MovieInfo.h"
using namespace std;

//constructor
movieInfo::movieInfo(const char * name, const char *mpaa)
{
    strcpy (movieName, name);
    strcpy (MPAA, mpaa);
    total = 0;
    count = 0;
}

void movieInfo::addRating(int rating)
{
    if (rating < 0 || rating > 5)
    {
        cout << "**** Invalid rating entered! Average will be inaccurrate, please correct the error by entering a 1-5 ****" << endl << endl;
    }
    else
        total += rating;    //add current rating to total
        count++;
}

double movieInfo::getAverage()
{
    return double(total)/count;
}


char *movieInfo::name()
{
    return movieName;
}

char *movieInfo::getMPAA()
{
    return MPAA;
}
