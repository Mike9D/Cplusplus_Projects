//
//  MovieInfo.h
//  movieRatings
//
//  Created by Ryan Munguia on 7/25/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#ifndef MovieInfo_h
#define MovieInfo_h

//define the class
class movieInfo{
private:
    char movieName[100];
    char MPAA[20];
    int total;
    int count;
public:
    movieInfo (const char *name, const char *mpaa);
    void addRating (int rating);
    double getAverage();
    char *getMPAA();
    char *name();
};


#endif /* MovieInfo_h */
