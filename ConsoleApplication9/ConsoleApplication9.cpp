// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{       
    std::vector<int> a{1,2,3};
    a.erase(a.begin()+1);
    

    enum item_id { stick, sword, rubin };

    struct items {
        item_id id;        
        std::string name;
        int dmgup;
        int hpup;
    };

    enum enemies_id { slime, bat };

    struct enemies{
        enemies_id id;
        std::string name;
        int hp;
        int dmg;
    }enemy[2];

    /*struct {
        std::string name;
        int hp;
        int dmg;
    } enemy[2];*/

    enemy[0].dmg = 3;
    enemy[0].hp = 3;

    enemy[1].dmg = 1;
    enemy[1].hp = 3;

    struct {
        std::string name;
    } item[3];
        
    /*item[0].name = "stick1";
    item[1].name = "stick2";
    item[2].name = "stick3";
    item[3].name = "stick4";*/

     
    struct {
        int id;
        std::string name;
        std::vector<int> door;
        std::vector<items> loot;
        std::vector<enemies> enemy;
    } location[4];

    location[0].name = "home";
    location[0].door.push_back(1);

    location[1].name = "forest";
    location[1].id = 1;
    location[1].door.push_back(0);
    location[1].door.push_back(2);
    location[1].door.push_back(3);
    location[1].loot.push_back({ item_id::stick,"stick "});

    location[2].name = "cave";
    location[2].door.push_back(1);
    location[2].loot.push_back({ item_id::sword,"sword ",2,0 });
    location[2].enemy.push_back({ enemies_id::bat,"bat",2,1 });

    location[3].name = "swamp";
    location[3].door.push_back(1);
    location[3].loot.push_back({ item_id::rubin,"rubin ",0,10 });
    location[3].enemy.push_back({ enemies_id::slime,"slime",5,3 });

    struct {
        std::string name;
    }inventory;

    struct {
        int pos;
        int hp;
        int dmg;
        std::vector<items> inventory;
    } player;


    int act;
    int invact;
    std::string locact;
    int e;
    //e = location->id;

    player.pos = 0;
    player.hp = 20;
    player.dmg = 1;

    int enemy_hp;
    int enemy_dmg = 0;

            while (true) {
                
                for (int i = 0; i < location[player.pos].enemy.size(); i++)
                {
                    
                    //std::cout << "enemy: " << location[player.pos].enemy[i].name << "\n";
                    
                    while (location[player.pos].enemy[i].hp > 0) {
                        if (player.hp <= 0) {                            
                            break;
                        }
                        std::cout << "enemy: " << location[player.pos].enemy[i].name << "\n";
                        std::cout << "your stats: " << "hp: " << player.hp << " dmg: " << player.dmg << "\n";
                        std::cout << "enemy stats: " << "hp: " << location[player.pos].enemy[i].hp << " dmg: " << location[player.pos].enemy[i].dmg << "\n";
                        std::cout << "your next move:\n" << "1.atack " << "2.defence " << "\n";
                        std::cin >> invact;
                        if (invact == 1) {
                            location[player.pos].enemy[i].hp -= player.dmg;
                            player.hp -= location[player.pos].enemy[i].dmg;
                        }
                        if (invact == 2) {
                            player.hp -= (location[player.pos].enemy[i].dmg-1);
                        }
                    }         
                }

                std::cout << "current location: " << location[player.pos].name << "\n";
                std::cout << "your stats: \n" << "hp: " << player.hp << "\n" << "dmg: " << player.dmg << "\n";
                //std::cout << "your equip: " <<  << "\n";                                
                   
               

                if (player.hp <= 0) {
                    std::cout << "game over! \n";
                    break;
                }
                
                std::cout << "your action:\n" << "1.inventory " << "2.items around " << "3.go to location " << "\n";

                std::cin >> act;
                
                if (act == 1) {
                    if (player.inventory.size() == 0) {
                        std::cout << "empty \n";
                    }
                    else
                        std::cout << "your items: \n";
                    for (int c = 0; c < player.inventory.size(); c++) {
                        std::cout << player.inventory[c].name << "\n";
                    }                        
                }

                if (act == 2) {
                    if (location[player.pos].loot.size() > 0) {
                        for (int c = 0; c < location[player.pos].loot.size(); c++) {
                            std::cout << location[player.pos].loot[c].name << "\n";

                            std::cout << "your action:\n" << "1.pick up " << "2.leave ";
                            std::cin >> invact;
                            if (invact == 1) {
                                player.inventory.push_back({ location[player.pos].loot[c] });

                                player.dmg += location[player.pos].loot[c].dmgup;
                                player.hp += location[player.pos].loot[c].hpup;
                                location[player.pos].loot.erase(location[player.pos].loot.begin());
                            }
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
                        std::cout << "go to: ";
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

