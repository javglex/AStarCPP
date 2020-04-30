//
//  PathPlanner.hpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/28/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#ifndef PathPlanner_hpp
#define PathPlanner_hpp

#include <stdio.h>
#include "CustomMap.hpp"
#include <set>
#include <unordered_map>


class PathPlanner{
private:
    CustomMap map;
    std::set<int> closedSet;  //nodes already evaluated
    std::set<int> openSet;    //nodes currently discovered, but no evaluated
    std::unordered_map<int,int> cameFrom;   //holds which node can be reached from another
    std::unordered_map<int,double> gscore; //the cost of getting from the start node to a particular node. int = node, double = cost
    std::unordered_map<int, double> fscore; //cost of getting from start to goal, given a particular node. int = node, double = cost
    
    int start;
    int goal;
        
public:
    
    PathPlanner(CustomMap, int start, int goal);
    void setMap(CustomMap);
    void setStart(int start);
    void setGoal(int goal);
    bool isFrontierUnexplored();    //returns whether there are still nodes to explore on frontier
    int getCurrentNode();   //returns node in openSet with the lowest fscore
    std::vector<int> getNeighbors(int); //returns neighbors of a node
    std::set<int> createOpenSet();
    std::unordered_map<int,double> createG_score();
    std::unordered_map<int,double> createF_score();
    double getG_score(int); //return g score of a given node
    double distance(int, int); //calculates the distance between two nodes
    double getTentativeG_score(int, int);   //calculates gscore between current node and a neighbor;
    double heuristicCostEstimate(int); //calculates heuristic cost estimate of a node (cost from current node to goal)
    double calculateF_score(int);   //calculates the f score of a node (F = G + H)
    void recordBestPathTo(int, int);    //record the best path to a given neighbornode from the current node
};


#endif /* PathPlanner_hpp */
