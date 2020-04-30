//
//  PathPlanner.cpp
//  AStarCPP
//
//  Created by Javier Gonzalez on 4/28/20.
//  Copyright © 2020 Javier Gonzalez. All rights reserved.
//

#include "PathPlanner.hpp"
#include <cmath>

PathPlanner::PathPlanner(CustomMap m, int start, int goal){
    this->map = m;
    this->start = start;
    this-> goal = goal;
    //closedset, camefrom don't need to be initialized
    this->openSet = createOpenSet();
    this->fscore = createF_score();
    this->gscore = createG_score();
    
}

void PathPlanner::setMap(CustomMap m){
    this->map = m;
}

void PathPlanner::setStart(int start){
    this->start = start;
}

void PathPlanner::setGoal(int goal){
    this->goal = goal;
}

bool PathPlanner::isFrontierUnexplored(){
    if (this->openSet.size()==0)
        return true;
    return false;
}

int PathPlanner::getCurrentNode(){
    std::set<int> openSet = this->openSet;
    double lowestF_score = std::numeric_limits<double>::infinity();
    int lowestFNode = NULL;
    int size = openSet.size();
    for (auto node : openSet){
        
        if (lowestFNode==NULL)
            lowestFNode = node;
        double fScore = this->fscore[node];
        if (fScore<lowestF_score){
            lowestF_score = fScore;
            lowestFNode = node;
        }
    }
    
    return lowestFNode;
}

std::vector<int> PathPlanner::getNeighbors(int node){
    std::vector<int> neighbors = this->map.getRoads()[node];
    return neighbors;
}

std::set<int> PathPlanner::createOpenSet(){
    if (this->start!=NULL){
        std::set<int> openSet;
        openSet.insert(start);
        return openSet;
    }
    throw "Start node must be specified!";
}

std::unordered_map<int,double> PathPlanner::createG_score(){

    std::unordered_map<int, double> g_scores;
    long size = this->map.getIntersections().size();

    for (int i = 0; i < size; i++){
        g_scores[i] = std::numeric_limits<double>::infinity();
    }
    
    g_scores[this->start] = 0;
    
    return g_scores;
}

std::unordered_map<int,double> PathPlanner::createF_score(){
    std::unordered_map<int, double> f_scores;
    long size = this->map.getIntersections().size();

    for (int i = 0; i < size; i++){
        f_scores[i] = std::numeric_limits<double>::infinity();
    }
    
    f_scores[this->start] = 0; //TODO: Heuristic cost estimate function
    
    return f_scores;
}

double PathPlanner::getG_score(int node){
    return this->gscore[node];
}

double PathPlanner::distance(int node1, int node2){
    
    double x1 = map.getIntersections()[node1].x;
    double y1 = map.getIntersections()[node1].y;
    double x2 = map.getIntersections()[node2].x;
    double y2 = map.getIntersections()[node2].y;
    
    double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    
    return dist;
}

double PathPlanner::getTentativeG_score(int currentNode, int neighborNode){
    return this->getG_score(currentNode) + this->distance(currentNode, neighborNode);
}

double PathPlanner::heuristicCostEstimate(int node){
    return this->distance(node, this->goal);
}

double PathPlanner::calculateF_score(int node){
    return this->getG_score(node) + this->heuristicCostEstimate(node);
}

void PathPlanner::recordBestPathTo(int currentNode, int neighborNode){
    this->cameFrom[neighborNode] = currentNode;
    this->gscore[neighborNode] = this->getTentativeG_score(currentNode, neighborNode);
    this->fscore[neighborNode] = this->calculateF_score(neighborNode);
}
