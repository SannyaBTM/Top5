//
//  League.cpp
//  Basketball
//


#include "League.hpp"
//random names for teams to be changed as well

//auxiliary function to find the intersection of two vectors
std::vector<int> intersection(std::vector<int> vect1, std::vector<int> vect2) {
    std::vector<int> intersect;
    for (int i = 0; i < vect1.size(); i++) {
        for (int j = 0; j < vect2.size(); j++) {
            if (vect1[i] == vect2[j]) {
                intersect.push_back(vect1[i]);
            }
        }
    }
    return intersect;
};
std::string teamNames[] = {"Los Angeles Lakers","Golden State Warriors","Toronto Raptors","Boston Celtics","San Antonio Spurs","Houston Rockets","Cleveland Cavaliers","New York Knicks","Chicago Bulls","Los Angeles Clippers","Washington Wizards","Memphis Grizzlies","Sacramento Kings","Charlotte Bobcats","Miami Heat","New Orleans Hornets","Dallas Mavericks","Detroit Pistons","Atlanta Hawks","Indiana Pacers","New Jersey Nets","Phoenix Suns","Utah Jazz","Denver Nuggets","Nanterre 92","Real Madrid","FC Barcelona","Abidjan Basket Club","New Zealand Breakers","Singapore Slingers","Portland Trail Blazers","Harlem Globetrotters","Rabat FUS","Casablanca Raja","Tangier Ittihad","Fez Maghreb","Berkane Renaissance","FAR Rabat","BC Teuta Durres","Tirana" };

// why a string for seas? how are you going to increment it? it should be an int.
League::League(int divi, std::string seas){          //Takes arguments : division as an int and a season as a string
    division = divi ;
    season = seas;
    int n = rand()%12 ;
    for (int i = 0; i < 12; i++) {
        Team t= Team( teamNames[(n + i) % 12] );
        League::teams.push_back(t);
    }
    
    /*std::map<std::string, double,std::list> attributes;
     attributes["season"] = seas;
     attributes["division"] = divi;
     */
}

std::map<int, std::vector< std::tuple<int,int> > > League::calendar()
{
    std::map<int, std::vector< std::tuple<int, int> > > calendar;
    
    //creating map assigning its possible opponents to each team
    std::map<int, std::vector<int> > possibilities;
    for (int i = 1; i < 13; i++) {
        std::vector<int> teams = { 1,2,3,4,5,6,7,8,9,10,11,12 };
        teams.erase(teams.begin() + i - 1);
        possibilities[i] = teams;
    }
    
    //create list of matches for each week
    for (int w = 1; w < 23; w++) {
        std::vector<int> freeTeams = { 1,2,3,4,5,6,7,8,9,10,11,12 };
        while (freeTeams.size() > 0) {
            int t = freeTeams[0];
            
            std::vector<int> possible_opponents = intersection(freeTeams, possibilities[t] );
            
            int opponent = possible_opponents[0];  //taking the first possible and match-free opponent
            
            std::tuple<int, int> match = std::make_tuple(t, opponent);
            
            calendar[w].push_back(match);  //adding match to the list of matches of the week
            
            //deleting the teams which already have a match assigned to them
            freeTeams.erase(freeTeams.begin() + opponent - t);
            freeTeams.erase(freeTeams.begin());
        }
    }
    
    return calendar;
}






