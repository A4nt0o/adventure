// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{
    enum class items {
        stick1, stick2, stick3, stick4
    };

    struct {
        std::string name;
    } item[4];

    item[0].name = "stick1";
    item[1].name = "stick2";
    item[2].name = "stick3";
    item[3].name = "stick4";


    struct {
        int id;
        std::string name;
        std::vector<int> door;
        std::vector<items> loot;
    } location[4];

    location[0].name = "home";
    location[0].door.push_back(1);
    location[0].loot.push_back(items::stick2);

    location[1].name = "forest";
    location[1].id = 1;
    location[1].door.push_back(0);
    location[1].door.push_back(2);
    location[1].door.push_back(3);
    location[1].loot.push_back(items::stick1);
    location[1].loot.push_back(items::stick3);

    location[2].name = "cave";
    location[2].door.push_back(1);
    location[2].loot.push_back(items::stick3);
    location[2].loot.push_back(items::stick3);

    location[3].name = "swamp";
    location[3].door.push_back(1);

    struct {
        int pos;
        std::vector<int> inventory;
    } player;


    int act;
    int invact;
    std::string locact;
    int e;
    //e = location->id;

    player.pos = 0;

    while (true) {
        std::cout << "current location: " << location[player.pos].name << "\n";
        std::cout << "your action:\n" << "1.open inventory " << "2.items around " << "3.go to location " << "\n";
        std::cin >> act;
        if (act == 2) {
            if (location[player.pos].loot.size() > 0) {
                for (int c = 0; c < location[player.pos].loot.size(); c++) {
                    std::cout << item->name << "\n";
                }
                std::cout << "your action:\n" << "1.pick up " << "2.leave ";
                std::cin >> invact;
                if (invact == 1) {
                    
                    //l -= 1;
                    //player.inventory + item->name;
                }
            }
            else {
                std::cout << "nothing here\n";
            }
        }

        if (act == 3) {
            std::cout << "choose location:\n";

            for (int i = 0; i < location[player.pos].door.size(); i++)
            {
                int dst = location[player.pos].door[i];
                std::cout << location[dst].name << "\n";

            }

            
            bool is_ok = false;
            while (is_ok == false) {
                std::cin >> locact;
                for (int i = 0; i < location[player.pos].door.size(); i++) {

                    int dst = location[player.pos].door[i];

                    if (locact == location[dst].name)
                    {
                        player.pos = dst;
                        is_ok = true;
                        
                    }
                }

                if (!is_ok) {
                    std::cout << "wrong name \n";
                }
            }

        }
    }
    
}

