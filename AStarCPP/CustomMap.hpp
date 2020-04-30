//
//  CustomMap.hpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/27/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#ifndef CustomMap_hpp
#define CustomMap_hpp

#include <stdio.h>
#include <vector>
#include "Intersection.hpp"

class CustomMap{
    
private:
 std::vector<Intersection> intersections;
 std::vector<std::vector<int>> roads;
 
public:
    
    /**
     Uses already constructed intersetions and roads
     */
    CustomMap();
    
    CustomMap(std::vector<Intersection> intersections,
              std::vector<std::vector<int>> roads);
    
    std::vector<Intersection> getIntersections();
    std::vector<std::vector<int>> getRoads();
    
    std::string mapStats();
    
};

#endif /* CustomMap_hpp */
