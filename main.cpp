#include <iostream>

enum roomType
{
    BED,
    KITCHEN,
    BATHROOM,
    KIDS,
    LIVING_ROOM
};

enum buildingType
{
    GARAGE,
    BARN,
    BATH
};

struct room
{
    roomType type;
    int square;
};

struct floor
{
    room* rooms;
    int roomQty;
    int ceilingHeight;
};

struct house
{
    floor* floors;
    int floorQty;
    bool pipe;
};

struct building
{
    buildingType type;
    bool pipe;
};

struct site
{
    house* houses;
    int houseQty;
    building* buildings;
    int buildingQty;
};

int main()
{
    std::cout << "How many sites town has: " << std::endl;
    int sitesQty;
    std::cin >> sitesQty;

    site* sites=new site[sitesQty];

    std::string input;

    for(int i=0;i<sitesQty;i++)
    {

        std::cout << "SITE #" << i + 1 << ":\n" << "How many houses do you have on this site(you should have at least 1): ";
        do
        {
            std::cin >> (sites+i)->houseQty;
            if ((sites+i)->houseQty < 1)
            {
                std::cout << "There must be at least one house. Type again: ";
            }
            else
                break;
        }
        while(true);

        (sites+i)->houses=new house[(sites+i)->houseQty];

        for(int j=0;j<(sites+i)->houseQty;j++)
        {
            std::cout << "HOUSE #" << j+1 << " of SITE#:" << i+1 << "\n";
            std::cout << "How much floors does the house has: ";

            do
            {
                std::cin >> ((sites+i)->houses+j)->floorQty;
                if(((sites+i)->houses+j)->floorQty>3||((sites+i)->houses+j)->floorQty<1)
                {
                    std::cout << "There should be from 1 to 3 floors, type again: ";
                }
                else
                    break;
            }
            while(true);

            ((sites+i)->houses+j)->floors=new floor[((sites+i)->houses+j)->floorQty];

            for(int k=0;k<((sites+i)->houses+j)->floorQty;k++)
            {
                std::cout << "FLOOR #" << k+1 << " OF HOUSE #" << j+1 << " OF SITE#" << i+1 << ":\n";
                std::cout << "What is floor ceiling height: ";
                std::cin >> (((sites+i)->houses+j)->floors+k)->ceilingHeight;

                std::cout << "How much rooms does floor#" << k+1 << " has: ";

                do
                {
                    std::cin >> (((sites+i)->houses+j)->floors+k)->roomQty;
                    if((((sites+i)->houses+j)->floors+k)->roomQty>4||(((sites+i)->houses+j)->floors+k)->roomQty<2)
                    {
                        std::cout << "There should be from 2 to 4 rooms, type again: ";
                    }
                    else
                        break;
                }
                while(true);

                (((sites+i)->houses+j)->floors+k)->rooms=new room[(((sites+i)->houses+j)->floors+k)->roomQty];

                for(int l=0;l<(((sites+i)->houses+j)->floors+k)->roomQty;l++)
                {
                    std::cout << "ROOM #" << l+1 << " FLOOR #" << k+1 << " OF HOUSE #" << j+1 << " OF SITE#" << i+1 << ":\n";
                    std::cout << "Type in type of room(bedroom, kitchen, bathroom, kidsroom, livingroom): ";
                    do {
                        std::cin >> input;
                        if (input == "bedroom")
                        {
                            ((((sites + i)->houses + j)->floors + k)->rooms + l)->type = BED;
                            break;
                        }
                        else if (input == "kitchen")
                        {
                            ((((sites + i)->houses + j)->floors + k)->rooms + l)->type = KITCHEN;
                            break;
                        }
                        else if (input == "bathroom")
                        {
                            ((((sites + i)->houses + j)->floors + k)->rooms + l)->type = BATHROOM;
                            break;
                        }
                        else if (input == "kidsroom")
                        {
                            ((((sites + i)->houses + j)->floors + k)->rooms + l)->type = KIDS;
                            break;
                        }
                        else if (input == "livingroom")
                        {
                            ((((sites + i)->houses + j)->floors + k)->rooms + l)->type = LIVING_ROOM;
                            break;
                        }
                        else {
                            std::cout << "Not valid room, type again:";
                        }
                    }
                    while(true);

                    std::cout << "Type in room area: ";
                    std::cin >> ((((sites + i)->houses + j)->floors + k)->rooms + l)->square;
                }

            }
        }

        std::cout << "How much buildings does site#" << i+1 << " has: ";
        std::cin >> (sites+i)->buildings;

        (sites+i)->buildings = new building[(sites+i)->buildingQty];

        for(int j;j<(sites+i)->buildingQty;j++)
        {
            std::cout << "What is building#"<< j+1 << "type (garage, barn, bath): ";
            std::cin >> input;
            if(input == "garage")
                ((sites+i)->buildings+j)->type=GARAGE;
            if(input == "barn")
                ((sites+i)->buildings+j)->type=GARAGE;
            if(input == "bath")
                ((sites+i)->buildings+j)->type=GARAGE;
        }
    }

    return 0;
}
