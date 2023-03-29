#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

class entity {
protected:
    int hp;
    int damage;
    int armor;
    int stamina;
public:
    void move();
    void say();
    void interctable();
    void setReputation();
    void getReputation();

};

class GG : public entity {

};

class NPC : public entity {

};

class Enemy_entity : public NPC {
public:

};


class Friend_entity : public NPC {
public:
};


class Lincoln : public Enemy_entity {
public:

};


class Soldier_1 : public Lincoln {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }

    void interctable() {
        srand(time(0));
        int hp = 50 + rand() % (100 - 50);
        int damage = 3 + rand() % (7 - 3);
        int armor = 1 + rand() % (2 - 1);
        int stamina = 40 + rand() % (50 - 40);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }

};

class Soldier_2 : public Lincoln {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }

    void interctable() {
        srand(time(0));
        int hp = 70 + rand() % (120 - 70);
        int damage = 5 + rand() % (10 - 5);
        int armor = 2 + rand() % (6 - 2);
        int stamina = 50 + rand() % (85 - 50);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }


};

class Soldier_3 : public Lincoln {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }
    void interctable() {
        srand(time(0));
        int hp = 100 + rand() % 150;
        int damage = 10 + rand() % 16;
        int armor = 18 + rand() % 30;
        int stamina = 85 + rand() % 140;
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }


};

class Plema : public Friend_entity {
public:

};


class Warrior_I : public Plema {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }

    void interctable() {
        srand(time(0));
        int hp = 50 + rand() % (100 - 50);
        int damage = 3 + rand() % (7 - 3);
        int armor = 1 + rand() % (2 - 1);
        int stamina = 30 + rand() % (40 - 30);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }


};

class Warrior_II : public Plema {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }

    void interctable() {
        srand(time(0));
        int hp = 70 + rand() % (120 - 70);
        int damage = 7 + rand() % (12 - 7);
        int armor = 5 + rand() % (10 - 5);
        int stamina = 40 + rand() % (75 - 40);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }


};

class Warrior_III : public Plema {
public:


    void move() {
        cout << "Вы пришли к мобу" << endl << "" << endl;
    }

    void interctable() {
        srand(time(0));
        int hp = 100 + rand() % (150 - 100);
        int damage = 12 + rand() % (20 - 12);
        int armor = 25 + rand() % (60 - 25);
        int stamina = 70 + rand() % (110 - 70);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }


};

int main() {

    setlocale(LC_ALL, "Russian");

    int x = 0;
    int y = 0;

    char move_gg;

    srand(time(0));
    int hp_gg = 50 + rand() % (100 - 50);
    int damage_gg = 3 + rand() % (7 - 3);
    int armor_gg = 1 + rand() % (2 - 1);
    int stamina_gg = 30 + rand() % (40 - 30);
    int reputation_gg_P = 100;
    int reputation_gg_L = -100;

    cout << "Данные вашего персонажа:" << endl << "Здоровье: " << hp_gg << endl << "Урон: " << damage_gg << endl << "Броня: " << armor_gg << endl << "Выносливость: " << stamina_gg << endl;



loop1:
    int i = 0;
    cout << "Ваши действия?" << endl;
    cin >> move_gg;
    i = 1;

    if ((move_gg == '6' || move_gg == 'd') && i == 1) {
        x += 20;
        i = 0;
        cout << "Вы повернули на право, ваши координаты x = " << x << "  y = " << y << endl;

    }
    else if ((move_gg == '4' || move_gg == 'a') && i == 1) {
        x -= 20;
        i = 0;
        cout << "Вы повернули на лево, ваши координаты x = " << x << "  y = " << y << endl;
    }

    else if ((move_gg == '8' || move_gg == 'w') && i == 1) {
        y += 20;
        i = 0;
        cout << "Вы прошли вперед, ваши координаты x = " << x << "  y = " << y << endl;
    }
    else if ((move_gg == '2' || move_gg == 's') && i == 1) {
        y -= 20;
        i = 0;
        cout << "Вы прошли назад, ваши координаты x = " << x << "  y = " << y << endl;
    }



    if (x == 0 && y == 40) {
        Soldier_1 a;
        a.move();
        a.interctable();
    }
    else goto loop1;

    return 0;
}
