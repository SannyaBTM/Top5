//
//  Player.hpp
//  Basketball
// player class


#ifndef Player_hpp
#define Player_hpp
#pragma once
#include <stdio.h>
#include <string>
class Player{
public:
    //constuctors
    Player();
    Player(std::string pos);
    
    //player attributes
    std::string name;
    std::string surname;
    std::string position; // PG=pointguard SG=shootingguard F=forward PF=powerforward C=center
    int division;
    int age;
    int height;
    int weight;
    int sprint;
    int rebound;
    int passing;
    int handling;
    int shooting;
    int stealing;
    int block;
    int jump;
    int strength;
    int motivation;
    int energy;
    double attack;
    double defence;
    double overallgeneral;
    double marketvalue;
    //player methods
    void update_overall();
    
};
#endif /* Player_hpp */
