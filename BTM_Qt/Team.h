#ifndef TEAM_H
#define TEAM_H
#include "Player.h"
#pragma once

#include <vector>

class Team {
public:
    Team(std::string na);
    Team();
    std::string name;
    std::vector<Player> players;
    //All attributes are are the averages over all the players
    int division;
    double age;
    double height;
    double defence;
    double motivation;
    double sprint;
    double rebound;
    double passing;
    double handling;
    double shooting;
    double stealing;
    double block;
    double jump;
    double strength;
    double weight;
    double attack;
    double overallgeneral;
    double energy;
    void Training(); //Trains team by increasing attributes
    void update_overall();


};

#endif // TEAM_H