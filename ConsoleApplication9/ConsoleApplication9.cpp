// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{

    struct {
        int id;
        std::string name;
        std::vector<int> door;
        std::vector<int> loot;
    } location[4];

    location[0].name = "home";
    location[0].door.push_back(1);

    location[1].name = "forest";
    location[1].id = 1;
    location[1].door.push_back(0);
    location[1].door.push_back(2);
    location[1].door.push_back(3);
    location[1].loot.push_back(0);

    location[2].name = "cave";
    location[2].door.push_back(1);

    location[3].name = "swamp";
    location[3].door.push_back(1);

    struct {
        int pos;
        std::vector<int> inventory;
    } player;

    struct {
        std::string name;
    } item[5];

    item[0].name = "stick";

    int act;
    int invact;
    std::string locact;
    int e;
    //e = location->id;

    player.pos = 0;
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
            //if (invact == 1) {
                //l -= 1;
                //player.inventory + item->name;
            //}
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

        std::cin >> locact;
        for (int i = 0; i < location[player.pos].door.size(); i++) {

            int dst = location[player.pos].door[i];

            if (locact == location[dst].name) 
            {
                player.pos = dst;
                std::cout << "current location: " << location[player.pos].name << "\n";
            }
            else {
                std::cout << "wrong name";
            }
        }
    }
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
