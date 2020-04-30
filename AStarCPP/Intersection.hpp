//
//  Intersection.hpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/27/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#ifndef Intersection_hpp
#define Intersection_hpp
struct Intersection {
    int id;
    double x;
    double y;
    Intersection(int id, double x, double y){
        this->x = x;
        this->y = y;
        this->id = id;
    }
};
#endif /* Intersection_hpp */
