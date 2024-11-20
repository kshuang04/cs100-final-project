#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#include "../header/Item.hpp"

vector<Item*> generateItem() {
        
    vector<Item*> listOfItems;

    int stat;
    int stage;
    string name;
    int rarity;
    string desc;

    ifstream file;

    file.open("../Item.txt");

    int nameIndex;
    int descIndex;


    if (!(file.is_open())) {
        throw runtime_error("File not open");
    }

    while (file >> stat >> stage >> name >> rarity >> desc) {

        //Replace the "_" with " "
        nameIndex = name.find("_");
        descIndex = desc.find("_");

        if (nameIndex != string::npos) {
            name.replace(nameIndex, 1, " ");
        }

        //the desc has multiplie "_"
        while (descIndex != string::npos) {
            desc.replace(descIndex, 1, " ");
            descIndex = desc.find("_");
        }
        if (name.find("attack") != string::npos) 
            listOfItems.push_back(new AttackItem(stat, stage, name, rarity, desc));
        else if (name.find("defense") != string ::npos) 
            listOfItems.push_back(new DefenseItem(stat, stage, name, rarity, desc));
        else if (name.find("HP") != string::npos)
            listOfItems.push_back(new MaxHPPot(stat, stage, name, rarity, desc));
        else
            listOfItems.push_back(new HealingPot(stat, stage, name, rarity, desc));

    }
    return listOfItems;
}
