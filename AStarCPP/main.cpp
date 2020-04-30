//
//  main.cpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/26/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#include <iostream>
#include <vector>
#include "CustomMap.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    std::cout << "Hello, Maps!\n";
    
    CustomMap *myMap = new CustomMap();
    
    cout<<myMap->mapStats()<<endl;
    
    return 0;
}
