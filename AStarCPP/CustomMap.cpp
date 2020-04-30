//
//  CustomMap.cpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/27/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#include "CustomMap.hpp"
#include <vector>
#include "Intersection.hpp"
#include <sstream>
#include <string>
#include <iostream>

CustomMap::CustomMap(){
    intersections = {
           Intersection(0, 0.7798606835438107, 0.6922727646627362),
           Intersection(1, 0.7647837074641568, 0.3252670836724646),
           Intersection(2, 0.7155217893995438, 0.20026498027300055),
           Intersection(3, 0.7076566826610747, 0.3278339270610988),
           Intersection(4, 0.8325506249953353, 0.02310946309985762),
           Intersection(5, 0.49016747075266875, 0.5464878695400415),
           Intersection(6, 0.8820353070895344, 0.6791919587749445),
           Intersection(7, 0.46247219371675075, 0.6258061621642713),
           Intersection(8, 0.11622158839385677, 0.11236327488812581),
           Intersection(9, 0.1285377678230034, 0.3285840695698353)
       };
    
    roads = {
        {7,6,5},
        {4,3,2},
        {4,3,1},
        {5,4,1,2},
        {1,2,3},
        {7,0,3},
        {0},
        {0,5},
        {9},
        {8}
    };
}

CustomMap::CustomMap(std::vector<Intersection> intersections, std::vector<std::vector<int>> roads){
    this->intersections = intersections;
    this->roads = roads;
}

std::vector<Intersection> CustomMap::getIntersections(){
    return this->intersections;
}

std::vector<std::vector<int>> CustomMap::getRoads(){
    return this->roads;
}

std::string CustomMap::mapStats(){
    std::ostringstream os;
    os << "You have " << intersections.size() << " intersections," << "\n";
    return os.str();
}
