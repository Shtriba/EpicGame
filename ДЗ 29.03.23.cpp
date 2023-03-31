#include  <iostream> 
#include <stdlib.h>
#include <ctime>

using namespace std;

class entity {
protected:
    int hp;
    int damage;
    int armor;
    int stamina;
    bool death_npc;
public:
    void move();
    void say();
    void interctable();
    void setReputation();
    void getReputation();


};

class GG : public entity {
public:

    void random() {
        srand(time(0));
        hp_gg = 50 + rand() % (100 - 50);
        damage_gg = 4 + rand() % (7 - 3);
        armor_gg = 2 + rand() % (2 - 1);
        stamina_gg = 30 + rand() % (40 - 30);
    }
    int reputation_gg_P = 50;
    int reputation_gg_L = -50;
    void getReputation() {
        cout << "Данные вашего персонажа:" << endl << "Здоровье: " << hp_gg << endl << "Урон: " << damage_gg << endl << "Броня: " << armor_gg << endl << "Выносливость: " << stamina_gg << endl << "Репутация среди Племени: " << reputation_gg_P << endl << "Репутация среди Линкольна: " << reputation_gg_L << endl;
        cout << "" << endl;
    }
    int hp_gg, damage_gg, armor_gg, stamina_gg;

};

class NPC : public entity {
public:
    bool relationships = 0;
    int reputation_gg_P = 50;
    int reputation_gg_L = -50;

    int getRepL() {
        return reputation_gg_L;
    }

    int getRepP() {
        return reputation_gg_P;
    }

    bool dialog(int type) {

    dialog:

        cout << endl << "1 - 'Как жизнь, боец?'" << endl << "2 - Атаковать" << endl << "3 - 'Бывай' (уйти)" << endl << endl;;
        char b;
        cin >> b;
        if (b == '1') {

            cout << endl << "- Да пойдет. Смотри не напорись на врагов, их в последнее время дофига тут..." << endl;
            goto dialog;
        }
        else if (b == '2') {
            cout << endl << "- Ах ты ж сволочь! Пошел вон отсюда! Еще раз увижу - зарежу к чертовой матери!" << endl;

            if (type <= 6) {
                reputation_gg_P -= 51;
                cout << "Ваша репутация среди племени упала" << endl;
            }
            else {
                reputation_gg_L -= 51;
                cout << "Ваша репутация среди линкольна упала" << endl;
                

            }
            relationships = 1;
        }
        else if (b == '3') {
            cout << endl << "–Удачи!" << endl; relationships = 0;
        }
        else { cout << endl << "Пожалуйста, выберите вариант ответа:" << endl; goto dialog; }
return relationships;
    }
    
};


class Enemy_entity : public NPC {
public:

    void move() {
        cout << "Перед вами враждебный NPC" << endl << "" << endl;
    }

    void say() {
        srand(time(0));

        int shans = rand() % 5;

        if (shans == 0) {
            cout << "–Не думал сегодня обнажать свой клинок" << endl << "" << endl;
        }
        else if (shans == 1) {
            cout << "–К оружию!" << endl << "" << endl;
        }
        else if (shans == 2) {
            cout << "–Сегодня твой последний день!" << endl << "" << endl;
        }
        else if (shans == 3) {
            cout << "–Твой вид слишком невозмутим для смертника" << endl << "" << endl;
        }
        else if (shans == 4) {
            cout << "–АААААРГХ *Бежит с большой скоростью на вас*" << endl << "" << endl;
        }
    };
};


class Friend_entity : public NPC {
public:

    void move() {
        cout << "Перед вами дружеский NPC" << endl << "" << endl;
    }

    void say() {

        srand(time(0));

        int shans_1 = rand() % 5;

        if (shans_1 == 0) {
            cout << "–Славный сегодня денек, не правда ли?" << "" << endl << endl;
        }
        else if (shans_1 == 1) {
            cout << "–*шепчет* а в обед будут катлеты... С пюрешкой..." << "" << endl << endl;
        }
        else if (shans_1 == 2) {
            cout << "–Как здоровье, путник?" << "" << endl << endl;
        }
        else if (shans_1 == 3) {
            cout << "–Отлично выглядишь!" << "" << endl << endl;
        }
        else if (shans_1 == 4) {
            cout << "–Интересно, почему в небе так много облаков..." << "" << endl << endl;
        }

    };



};


class Lincoln : public Enemy_entity {
public:
};


class Soldier_1 : public Lincoln {
public:

    int hp = 50 + rand() % (100 - 50);
    int damage = 3 + rand() % (7 - 3);
    int armor = 1 + rand() % (2 - 1);
    int stamina = 40 + rand() % (50 - 40);

    void interctable() {

        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused, staminaMax = stamina, gg_staminaMax = gg_stamina;
        bool Q;

    battleStart:
        cin >> c;

        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_P += 51;
        return Q;
    }

};


class Soldier_2 : public Lincoln {
public:

    int hp = 70 + rand() % (120 - 70);
    int damage = 5 + rand() % (10 - 5);
    int armor = 2 + rand() % (6 - 2);
    int stamina = 50 + rand() % (85 - 50);

    void interctable() {

        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused, staminaMax = stamina, gg_staminaMax = gg_stamina;
        bool Q;

    battleStart:
        cin >> c;
        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_P += 51;
        return Q;
    }


};

class Soldier_3 : public Lincoln {
public:

    int hp = 100 + rand() % (150 - 100);
    int damage = 10 + rand() % (6 - 3);
    int armor = 8 + rand() % (3 - 1);
    int stamina = 85 + rand() % (140 - 85);

    void interctable() {

        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused, staminaMax = stamina, gg_staminaMax = gg_stamina;
        bool Q;

    battleStart:
        cin >> c;

        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_P += 51;
        return Q;
    }

};

class Plema : public Friend_entity {
public:

};


class Warrior_I : public Plema {
public:
    int hp, damage, armor, stamina;
    void interctable() {
        srand(time(0));
        hp = 50 + rand() % (100 - 50);
        damage = 3 + rand() % (7 - 3);
        armor = 1 + rand() % (2 - 1);
        stamina = 30 + rand() % (40 - 30);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused;
        bool Q;

    battleStart:

        cout << "Враг атакует!" << endl << "Ваши действия?" << endl << "1 - Поставить блок" << endl << "2 - Попытаться уклониться" << endl;
        cin >> c;


        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_L += 51;
        return Q;
    }

};


class Warrior_II : public Plema {
public:
    int hp, damage, armor, stamina;
    void interctable() {
        srand(time(0));
        hp = 70 + rand() % (120 - 70);
        damage = 7 + rand() % (12 - 7);
        armor = 2 + rand() % (5 - 1);
        stamina = 40 + rand() % (75 - 40);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused;
        bool Q;

    battleStart:

        cout << "Враг атакует!" << endl << "Ваши действия?" << endl << "1 - Поставить блок" << endl << "2 - Попытаться уклониться" << endl;
        cin >> c;


        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_L += 51;
        return Q;
    }

};


class Warrior_III : public Plema {
public:
    int hp, damage, armor, stamina;

    void interctable() {
        srand(time(0));
        hp = 100 + rand() % (150 - 100);
        damage = 12 + rand() % (20 - 12);
        armor = 5 + rand() % (5 - 3);
        stamina = 70 + rand() % (110 - 70);
        cout << "Данные вашего врага:" << endl << "Здоровье: " << hp << endl << "Урон: " << damage << endl << "Броня: " << armor << endl << "Выносливость: " << stamina << endl;
    }
    int fight(int gg_hp, int gg_dmg, int gg_armor, int gg_stamina) {

        int c, v, damageCaused;
        bool Q;

    battleStart:

        cout << "Враг атакует!" << endl << "Ваши действия?" << endl << "1 - Поставить блок" << endl << "2 - Попытаться уклониться" << endl;
        cin >> c;


        if (c == 1) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - (gg_armor / 2)) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное парирование! Персонаж не потерял здоровье" << endl;
            }
            if (v == 1) {
                cout << "Вы успели поставить блок,. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            if (v == 2) {
                cout << "Вы попытались поставить блок, но враг оказался быстрее. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }


        else if (c == 2) {
            srand(time(0));
            v = rand() % 3;
            damageCaused = (damage - gg_armor) * (v / 2);
            gg_hp -= damageCaused;
            if (v == 0) {

                cout << "Идеальное уклонение! Персонаж не потерял здоровье" << endl;
            }
            else if (v == 1) {
                cout << "Вы успели отпрыгнуть, но вас все же зацепило. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
            else if (v == 2) {
                cout << "Вы попытались отпрыгнуть в сторону, но удар все же вас настиг. Персонаж теряет " << damageCaused << " здоровья" << endl;
            }
        }

        cout << "У Вас осталось " << gg_hp << " здоровья" << endl;

        if (gg_hp <= 0) {
            Q = 0;
            goto battleEnd;
        }

        cout << "Вы контратакуете врага..." << endl;
        v = rand() % 2 + 1;
        damageCaused = (gg_dmg - (armor / 2)) * v;
        hp -= damageCaused;
        if (v == 1) {

            cout << "Ваш клинок настигает цель. Враг теряет " << damageCaused << " здоровья" << endl;
        }
        else if (v == 2) {
            cout << "Ваш удар настиг врага врасплох, вы нанесли значительный урон! Враг теряет " << damageCaused << " здоровья" << endl;
        }

        cout << "У врага осталось " << hp << " здоровья" << endl;

        if (hp <= 0) {
            Q = 1;
            goto battleEnd;

        }
        else {
            goto battleStart;
        }
    battleEnd:
        reputation_gg_L += 51;
        return Q;
    }

};



int main() {

    setlocale(LC_ALL, "Russian");

    //sleep(2);
    cout << "Управление персонажем: " << endl << "" << endl << "Для ходьбы вперед кнопки w/8" << endl << "Для ходьбы назад кнопки s/2" << endl << "Для ходьбы вправо кнопки d/6" << endl << "Для ходьбы влево кнопки a/4" << endl << "Для выхода в меню кнопка 0" << endl << "" << endl;
    //sleep(8);
    cout << "Должны предупредить, что каждая клетка состоит из 20м², что равняется одному ходу героя соответственно, другими словами, если сдвинетесь в правую сторону, то ваш герой сдвинется ровно на одну клетку в правую сторону." << endl << "" << endl;
    //sleep(10);
    cout << "Приятной игры!" << endl << "" << endl;
    //sleep(2);
restart:


    int x = 0;
    int y = 0;
    bool BattleRes, relationships = 0, relationshipL1 = 0, relationshipL2 = 0, relationshipL3 = 0, relationshipP1 = 0, relationshipP2 = 0, relationshipP3 = 0;
    char move_gg;
    int hp_gg, damage_gg, armor_gg, stamina_gg, type, reputation_gg_L = -50, reputation_gg_P = 50;


    GG get;
    get.random();
    get.getReputation();

    NPC K;

    hp_gg = get.hp_gg;
    damage_gg = get.damage_gg;
    armor_gg = get.armor_gg;
    stamina_gg = get.stamina_gg;

    /*sleep(2);*/
    cout << "Вы просыпаетесь от долгого сна и вам подносят карту..." << endl;
    /*sleep(2);*/
    cout << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | | | | | | | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | |@| | | | | |@| | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | |@| | | | | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | | | | | | | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | | | | |&| | | |$| | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | |$| | | | | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | | | | | | |$| | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl <<
        " | | | | | | | | | | | | | | | " << endl <<
        "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
    cout << endl << "Примечание от разведки: " << endl <<
        "'Перед вами карта местности. Электронику будет легко обнаружить и вас вместе с ней, так что она бумажная" << endl <<
        "Условные обозначения:" << endl << "& - ваша стартовая позиция, она же <нулевая координата>" << endl <<
        "@ - позиции бойцов Линкольна" << endl <<
        "$ - позиции бойцов Племени" << endl <<
        "Не забывайте что враги нападут как только вы приблизитесь. Удачи, товарищ '" << endl << endl;
    /*sleep(2);*/
    bool death_npc1 = 0;
    bool death_npc2 = 0;
    bool death_npc3 = 0;
    bool death_npc4 = 0;
    bool death_npc5 = 0;
    bool death_npc6 = 0;
loop1:
    int i = 0;
    reputation_gg_L = K.getRepL();
    reputation_gg_P = K.getRepP();
    cout << "Ваши действия?" << endl;
    cin >> move_gg;
    i = 1;

    if ((move_gg == '6' || move_gg == 'd') && i == 1) {
        x += 20;
        i = 0;
        cout << "" << endl << "Вы повернули на право, ваши координаты x = " << x << "  y = " << y << endl << "" << endl;

    }
    else if ((move_gg == '4' || move_gg == 'a') && i == 1) {
        x -= 20;
        i = 0;
        cout << "" << endl << "Вы повернули на лево, ваши координаты x = " << x << "  y = " << y << endl << "" << endl;
    }

    else if ((move_gg == '8' || move_gg == 'w') && i == 1) {
        y += 20;
        i = 0;
        cout << "" << endl << "Вы прошли вперед, ваши координаты x = " << x << "  y = " << y << endl << "" << endl;
    }
    else if ((move_gg == '2' || move_gg == 's') && i == 1) {
        y -= 20;
        i = 0;
        cout << "" << endl << "Вы прошли назад, ваши координаты x = " << x << "  y = " << y << endl << "" << endl;
    }
    else if (move_gg == 'e' || move_gg == 'E') {
        get.getReputation();
    }
    else if (move_gg == '0') { goto menu; }


    if (((x == 0 && y == 40) || (x == 0 && y == 80) || (x == -20 && y == 60) || (x == 20 && y == 60)) && (death_npc1 == 0)) {
        type = 1;
        if (reputation_gg_L < 0 || relationshipL1 == 1) {

            Enemy_entity a;
            a.move();
            a.say();

            Soldier_1 b;

            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);

        }
        else {

            Friend_entity c;
            c.move();
            c.say();

            NPC d;
            relationships = d.dialog(type);

            if (relationships == 1) {
                relationshipL1 = 1;
                relationships = 0;
            }

            goto loop1;

        }

    }
    else if (((x == -60 && y == 20) || (x == -60 && y == 60) || (x == -40 && y == 40) || (x == -80 && y == 40)) && (death_npc2 == 0)) {
        type = 2;
        if (reputation_gg_L < 0 || relationshipL2 == 1) {

            Enemy_entity a;
            a.say();
            a.move();

            Soldier_2 b;
            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);

        }
        else {

            Friend_entity c;
            c.move();
            c.say();

            NPC d;
            relationships = d.dialog(type);
            if (relationships == 1) {
                relationshipL2 = 1;
                relationships = 0;
            }
            goto loop1;

        }

    }
    else if (((x == -120 && y == 40) || (x == -120 && y == 80) || (x == -140 && y == 60) || (x == 100 && y == 60)) && (death_npc3 == 0)) {
        type = 3;
        if (reputation_gg_L < 0 || relationshipL3 == 1) {

            Enemy_entity a;
            a.say();
            a.move();


            Soldier_3 b;

            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);

        }
        else {

            Friend_entity c;
            c.say();
            c.move();

            NPC d;
            relationships = d.dialog(type);
            if (relationships == 1) {
                relationshipL3 = 1;
                relationships = 0;
            }

            goto loop1;
        }

    }
    else if (((x == 60 && y == 0) || (x == 100 && y == 0) || (x == 80 && y == 20) || (x == 80 && y == -20)) && (death_npc4 == 0)) {
        type = 4;
        if (reputation_gg_P < 0 || relationshipP1 == 1) {

            Enemy_entity a;
            a.say();
            a.move();


            Warrior_I b;
            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);
        }
        else {


            Friend_entity c;
            c.move();
            c.say();

            NPC d;
            relationships = d.dialog(type);
            if (relationships == 1) {
                relationshipP1 = 1;
                relationships = 0;
            }


            goto loop1;
        }

    }
    else if (((x == -80 && y == -20) || (x == -40 && y == -20) || (x == -60 && y == -40) || (x == -60 && y == 0)) && (death_npc5 == 0)) {
        type = 5;
        if (reputation_gg_P < 0 || relationshipP2 == 1) {

            Enemy_entity a;
            a.say();
            a.move();


            Warrior_II b;
            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);
        }
        else {

            Friend_entity c;
            c.move();
            c.say();

            NPC d;
            relationships = d.dialog(type);

            if (relationships == 1) {
                relationshipP2 = 1;
                relationships = 0;
            }
            goto loop1;
        }

    }
    else if (((x == 20 && y == -40) || (x == 60 && y == -40) || (x == 40 && y == -60) || (x == 40 && y == 20)) && (death_npc6 == 0)) {
        type = 6;
        if (reputation_gg_P < 0 || relationshipP3 == 1) {

            Enemy_entity a;
            a.say();
            a.move();


            Warrior_III b;
            b.interctable();
            BattleRes = b.fight(hp_gg, damage_gg, armor_gg, stamina_gg);

        }
        else {
            Friend_entity c;
            c.move();
            c.say();

            NPC d;
            relationships = d.dialog(type);
            if (relationships == 1) {
                relationshipP3 = 1;
                relationships = 0;
            }

            goto loop1;
        }

    }
    else { goto loop1; }


    if (BattleRes == 0) {
        cout << "Вы мертвы" << endl;
        cout << "" << endl;
        cout << "   #####   ###   #   #  #####  #####" << endl << "   #   #  #   #  ## ##  #      #   #" << endl << "   #   #  #   #  # # #  ####   #####" << endl << "   #   #  #   #  #   #  #      #    " << endl << "   #   #   ###   #   #  #####  #    " << endl;

        goto EndGame;
    }
    else {
        cout << "Враг повержен. Вы восстановили здоровье" << endl;
        switch (type) {
        case 1: death_npc1 = 1; break;
        case 2: death_npc2 = 1; break;
        case 3: death_npc3 = 1; break;
        case 4: death_npc4 = 1; break;
        case 5: death_npc5 = 1; break;
        case 6: death_npc6 = 1; break;

        }
    }
    if (death_npc1 == 1 && death_npc2 == 1 && death_npc3 == 1) {
        cout << "Все бойцы Линкольна мертвы. Племя одержало победу" << endl;
        goto EndGame;
    }
    else if (death_npc4 == 1 && death_npc5 == 1 && death_npc6 == 1) {
        cout << "Все бойцы Племени мертвы. Линкольн одержал победу" << endl;
        goto EndGame;
    }
    goto loop1;
EndGame:
    cout << endl << " - - - - - - - - - - - - - - - - - -" << endl << "" << endl << "" << endl << "" << endl << "  для выхода в меню нажмите любую кнопку" << endl;
    char knopka;
    cin >> knopka;
    bool a;
menu:
    cout << "    ########################### " << endl << "   #                           #" << endl << "   # #   #  ####  #  #  #  ##  #" << endl << "   # ## ##  #     #  #  # #  # #" << endl << "   # # # #  ####  ####  ###  # #" << endl << "   # #   #  #     #  #  # #  # #" << endl << "   # #   #  ####  #  #  #  ##  #" << endl << "   #                           #" << endl << "    ########################### " << endl;
    cout << "" << endl << "" << endl << "" << endl << "Для выхода нажмите любую кнопку    Для рестарта нажмите 1" << endl;
    i = 0;

    cin >> a;
    if (a == 1) { goto restart; }

    return 0;
}
