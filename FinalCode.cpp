#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <MMSystem.h>

using namespace std;

///Functions
    void startup_menu();
    void create_person();
    void existing_player();
    void choose_second_fighter();
    void fight();
    int fight_moves(int st, int sp, int num);
    void won_round();
    void player_lost();
    void newlines();
    void help();
    void gamming();
    void player1();
    void CreatePerson1();
    void CreatePerson2();
    void SingleFight();
    void DualFight();

 ///Display Function
        void show();
        void show1();
        void show2();
        void show3();
        void show4();
        void reverse1();
        void reverse2();
        void reverse3();
        void reverse4();
        void Won();
        void lost();

class Person
{
    protected:
        string name;
        int Health,strength,speed;

    public:
        string get_name()
        {
            return name;
        }
        int get_health()
        {
            return Health;
        }
        int get_strength()
        {
            return strength;
        }
        int get_speed()
        {
            return speed;
        }

    void put_name(string n)
    {
        name = n;
    }
    void put_health(int h)
    {
        Health = h;
    }
    void put_strength(int st)
    {
        strength = st;
    }
    void put_speed(int sp)
    {
        speed = sp;
    }

    Person()
    {
        name = "Empty";
        Health = 0;
        strength = 0;
        speed = 0;
    }
    Person(string n, int h, int st, int sp)
    {
        name = n;
        Health = h;
        strength = st;
        speed = sp;
    }
};

///Global variables

    Person existing_person[4] = {Person("Leghorn", 100, 100, 100), Person("Rhode", 90, 50, 60), Person("Rock", 100, 145, 155), Person("Australorp", 80, 82, 77)};
    Person chosen_person[2] = {Person(), Person()}; /// Two selected fighters
    Person chosen_person_save("none" , 100, 0, 0); /// Saves player 1's health

    char repeat = 'y';
    int c = 0;
    bool Win;

int main()
{
    cout << "\tIf you are a new player and need to know about the game press '0'" << endl;
    cout << "\tFor play game press '1'" << endl;
    int i;
    cin >> i;
    if (i==0)
    {
        help();
        cout << "For play game press '1' and for quit press '00'" << endl;
        cin >> i;
        if (i==1)
        {
            ///Play Music
            PlaySound(TEXT("CockFight.wav"), NULL, SND_FILENAME | SND_ASYNC);

            cout << "\t\tWelcome" << endl << endl;
            startup_menu();
            gamming();
        }
        if (i==00)
        {
            system("Color 74");
            cout << endl << "\tThank You!" << endl;
        }
    }
    if (i==1)
    {
        ///Play Music
        PlaySound(TEXT("CockFight.wav"), NULL, SND_FILENAME | SND_ASYNC);

        cout << "\t\tWelcome" << endl << endl;
        startup_menu();
        gamming();
    }

    return 0;
}

void startup_menu()
{
    int i;
    system("Color F8");
    cout << "\t\tFor Single player press: 1\n\t\tFor Dual player press: 2" <<endl;
    cin >> i;
    if (i==1)
    {
        system("Color F4");
        cout << "Please enter your ID or Pass Code: ";
        string code;
        cin >> code;

        if (code == "2018-1-60-201")
        {
            c = 0;

            cout << "\n\n\t\t1: New Person";
            cout << "\n\t\t2: Existing Player";
            player1();
        }
        else
        {
            cout << endl << "\t\tPlease enter correct ID or Pass Code! ..." << endl << endl;
            startup_menu();
        }
    }
    if ((i==2)||(i!=1))
    {
        c = 1;
        system("Color F2");
        cout << "\n\n\t\tFirst player: ";
        create_person();
    }
}

void create_person()
{
    CreatePerson1();

    if ( c==0)
    {
        choose_second_fighter();
    }

    if (c==1)
    {
        CreatePerson2();
    }
}

void existing_player()
{
    string existing_player_choice;

    newlines();

    cout << "\n\n\t\tChoose your Player!";

    for(int i = 0, j = 1; i >= 0 && i <= 3; i++, j++)
    {
        cout << "\n\n\t\t" << j <<": " << existing_person[i].get_name();
        cout << "\n\t\t  Health: " << existing_person[i].get_health();
        cout << "\n\t\t  Strength: " << existing_person[i].get_strength();
        cout << "\n\t\t  Speed: " << existing_person[i].get_strength();
    }

    cout << "\n\n\t\tI Choose: ";

    cin.ignore();
    getline(cin, existing_player_choice);

    if(existing_player_choice == "1" || existing_player_choice == "Leghorn")
    {
        chosen_person[0] = existing_person[0]; chosen_person_save.put_health(existing_person[0].get_health());
    }
    else if(existing_player_choice == "2" || existing_player_choice == "Rhode")
    {
        chosen_person[0] = existing_person[1]; chosen_person_save.put_health(existing_person[1].get_health());
    }
    else if(existing_player_choice == "3" || existing_player_choice == "Rock")
    {
        chosen_person[0] = existing_person[2]; chosen_person_save.put_health(existing_person[2].get_health());
    }
    else if(existing_player_choice == "4" || existing_player_choice == "Australorp")
    {
        chosen_person[0] = existing_person[3]; chosen_person_save.put_health(existing_person[3].get_health());
    }
    else
    {
        cout << "\n\n\t\tInvalid Input! Program Failure... Please close and restart---";
    }

    choose_second_fighter();
}

void choose_second_fighter()
{
    string choose_fighter;

    newlines();

    cout << "\n\n\t\tChoose the person you want to fight.";

    for(int i = 0, j = 1; i >= 0 && i <= 3; i++, j++)
    {
        cout << "\n\n\t\t" << j <<": " << existing_person[i].get_name();
        cout << "\n\t\t  Health: " << existing_person[i].get_health();
        cout << "\n\t\t  Strength: " << existing_person[i].get_strength();
        cout << "\n\t\t  Speed: " << existing_person[i].get_speed();
    }

    cout << "\n\n\t\tI want to fight: ";

    cin >> choose_fighter;

    if(choose_fighter == "1" || choose_fighter == "Leghorn")
        chosen_person[1] = existing_person[0];

    else if(choose_fighter == "2" || choose_fighter == "Rhode")
        chosen_person[1] = existing_person[1];

    else if(choose_fighter == "3" || choose_fighter == "Rock")
        chosen_person[1] = existing_person[2];

    else if(choose_fighter == "4" || choose_fighter == "Australorp")
        chosen_person[1] = existing_person[3];

    else
    {
        cout << "\n\n\t\tInvalid Input! Program Failure... Please close and restart---" << endl;
    }
}

void fight()
{
    if (c==0)
    {
        SingleFight();
    }

    if (c==1)
    {
        DualFight();
    }

    if(Win == 1)
        won_round();

    else
        player_lost();
}

int fight_moves(int st, int sp, int num)
{
    srand(time(NULL));
    int rand_num;
    int addition;

    switch(num)
    {
        case 1:
        {  /// Punch
            rand_num = rand() % 60 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition;
            break;
        }
        case 2:
        {  /// Kick
            rand_num = rand() % 35 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition;
            break;
        }
        case 3:
        {  /// Slam
            rand_num = rand() % 45 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition;
            break;
        }
        case 4:
        {  /// Drop kick
            rand_num = rand() % 50 + 1;
            addition = (st + sp) / rand_num;
            cout << "\n\t\tDamage inflicted: " << addition;
            return addition;
            break;
        }
    }
}

void won_round()
{
    chosen_person[0].put_health(chosen_person_save.get_health());
    chosen_person[1].put_health(100);

    system("Color 7D");
    Won();
    cout << "\t\tYou won!" << endl;
    chosen_person[0].put_health(chosen_person[0].get_health());
    chosen_person[0].put_strength(chosen_person[0].get_strength());
    chosen_person[0].put_speed(chosen_person[0].get_speed());

    cout << "\t\tYour health is now: " << chosen_person[0].get_health() << endl;
    cout << "\t\tYour strength is now: " << chosen_person[0].get_strength() << endl;
    cout << "\t\tYour speed is now: " << chosen_person[0].get_speed() << endl << endl;

    cout << "\tWould you like to fight another person? (y/n) ";
    cin >> repeat;

}

void player_lost()
{
    chosen_person[0].put_health(chosen_person_save.get_health());
    chosen_person[1].put_health(100);

    system("Color 4E");
    lost();
    cout << "\t\tYou have lost." << endl;
    cout << "\n\t\tWould you like to fight another person? (y/n) ";
    cin >> repeat;

    return;
}

void newlines()
{
    cout << endl << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl << endl;
    cout << endl << endl << endl << endl;
}

void help()
{
    system("Color 70");
    cout << endl << "\tThe fight will be happened between two players. There are four option like 'Punch','Kick','Slam','Drop kick' to fight. " << endl;
    cout << endl << "\t\tPress 1 for Punch.\n\t\tPress 2 for Kick.\n\t\tPress 3 for Slam.\n\t\tPress 4 for Drop kick." << endl << endl;
    cout << "\tTo win the fight you have to finish your opponent's life by fighting. If your opponent finish your's life then you will lose the fight.";
    cout << endl << "\tThere will two type of fighting systems.\n\n\t\tSingle Fight\n\t\tDual Fight" << endl << endl;
    cout << "\tYou have to login for Single Fight.";
    cout << endl << endl;
}

void gamming()
{
    while(repeat == 'y' || repeat == 'Y')
    {
        if (repeat == 'y' || repeat == 'Y')
            fight();
        if(repeat == 'y' || repeat == 'Y')
        {
            cout << endl << endl;

            ///Play Music
            PlaySound(TEXT("CockFight.wav"), NULL, SND_FILENAME | SND_ASYNC);
            startup_menu();
        }
    }
    cout << "\n\n\t\t";
}

void player1()
{
    int choose_player;
    do
    {
        cout << "\n\n\t\tI would like: ";
        cin >> choose_player;
    }
    while(choose_player <= 0 || choose_player >= 3);

    if(choose_player == 1)
        create_person();
    else if(choose_player == 2)
        existing_player();
}

void CreatePerson1()
{
    string name;
    int h, st, sp;

    cout << "\n\t\tNew player name: ";
    cin >> name;

    cout << "\n\t\tHow much strength does " << name << " have?";
    cout << "\n\t\tSince you are new, you can't have more than 100.";

    do
    {
        cout << "\n\n\t\t";
        cout << name << "'s strength is: ";
        cin >> st;
    }
    while(st <= 0 || st >= 101);

    cout << "\n\t\tNow we need to know " << name << "'s speed.";
    cout << "\n\t\tAgain, the speed can not be more than 100.";

    do
    {
        cout << "\n\n\t\t";
        cout << name << "'s speed is: ";
        cin >> sp;
    }
    while(sp <= 0 || sp >= 101);

    h = 100;

    cout << "\n\t\tIn time " << name << " will gain more health with experiance" << "\n\t\tCurrently though " << name << "'s health is: " << h;

    cout << "\n\n\t\t";

    chosen_person[0] = Person(name, h, st, sp);

    cin.ignore();
}

 void CreatePerson2()
{
    string name;
    int h, st, sp;
    cout << "Second player: ";
    cout << "\n\t\tPlayer name: ";
    cin >> name;

    cout << "\n\t\tHow much strength does " << name << " have?";
    cout<< "\n\t\tSince you are new, you can't have more than 100.";

    do
    {
        cout << "\n\n\t\t";
        cout << name << "'s strength is: ";
        cin >> st;
    }
    while(st <= 0 || st >= 101);

    cout << "\n\t\tNow we need to know " << name << "'s speed.";
    cout << "\n\t\tAgain, the speed can not be more than 100.";

    do
    {
        cout << "\n\n\t\t";
        cout << name << "'s speed is: ";
        cin >> sp;
    }
    while(sp <= 0 || sp >= 101);

    h = 100;

    cout << "\n\t\tIn time " << name << " will gain more health with experiance" << "\n\t\tCurrently though " << name << "'s health is: " << h;

    cout << "\n\n\t\t";

    chosen_person[1] = Person(name, h, st, sp);

    cin.ignore();
}

void SingleFight()
{
    int fight_choice;
    int i = 0;
    int j = 5;

    system("Color FC");
    show();

    while(chosen_person[0].get_health() > 0 && chosen_person[1].get_health() > 0)
    {
        cout << "\t\t" << chosen_person[0].get_name() << " choose ";

        if(i == 0)
            cout << "an attack.";

        else
            cout << "another attack.";

        do
        {
            cout << endl << "\t\t";
            cin >> fight_choice;
        }
        while(fight_choice <= 0 || fight_choice >= j);

        if(fight_choice == 1)
        {
            system("Color 05");
            show1();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 1));
            cout << "\n\t\tYou Punched " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice == 2)
        {
            system("Color 05");
            show3();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 2));
            cout << "\n\t\tYou Kicked " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice == 3)
        {
            system("Color 05");
            show2();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 3));
            cout << "\n\t\tYou Slamed " << chosen_person[1].get_name() << " on the ground, his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice == 4)
        {
            system("Color 05");
            show4();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 4));
            cout << "\n\t\tYou Drop Kicked " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

/// Second fighter attack

        srand(time(NULL));
        int ran_pick = rand() % 5 + 1;

        if(chosen_person[1].get_health() < 0)
        {
            ran_pick = 0;
            Win = 1;
        }
        else if(chosen_person[1].get_health() > 0)
        {
            cout << "\n\t\t<" << chosen_person[1].get_name() << "'s turn>" << endl;
            Win = 0;
        }

        if(ran_pick == 0)
            continue;

        else if(ran_pick == 1)
        {
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 1));
            cout << "\n\t\t" << chosen_person[1].get_name() << " punched you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
        else if(ran_pick == 2)
        {
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 2));
            cout << "\n\t\t" << chosen_person[1].get_name() << " kicked you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
        else if(ran_pick == 3)
        {
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 3));                cout << "\n\t\t" << chosen_person[1].get_name() << " slammed you on the ground! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }

        else if(ran_pick == 4)
        {
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 4));
            cout << "\n\t\t" << chosen_person[1].get_name() << " drop kicked you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }

        else if(ran_pick == 5)
            cout << "\t\t" << chosen_person[1].get_name() << " missed you! Your health is still: " << chosen_person[0].get_health() << endl << endl;

        if(chosen_person[0].get_health() > 0)
        {
            cout << "\n\t\t";
        }

        i++;
    }
}

void DualFight()
{
    int fight_choice1,fight_choice2;
    int i = 0;
    int j = 5;

    system("Color 7A");
    show();

    while(chosen_person[0].get_health() > 0 && chosen_person[1].get_health() > 0)
    {
        cout << "\t\t" << chosen_person[0].get_name() << " choose ";

        if(i == 0)
            cout << "an attack.";

        else
            cout << "another attack.";

        do
        {
            cout << endl << "\t\t";
            cin >> fight_choice1;
        }
        while(fight_choice1 <= 0 || fight_choice1 >= j);

        if(fight_choice1 == 1)
        {
            system("Color 0E");
            show1();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 1));
            cout << "\n\t\tYou Punched " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice1 == 2)
        {
            system("Color 0E");
            show3();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 2));
            cout << "\n\t\tYou Kicked " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice1 == 3)
        {
            system("Color 0E");
            show2();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 3));
            cout << "\n\t\tYou Slamed " << chosen_person[1].get_name() << " on the ground, his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

        else if(fight_choice1 == 4)
        {
            system("Color 0E");
            show4();
            chosen_person[1].put_health(chosen_person[1].get_health() - fight_moves(chosen_person[0].get_strength(), chosen_person[0].get_speed(), 4));
            cout << "\n\t\tYou Drop Kicked " << chosen_person[1].get_name() << ", his health is now: ";

            if (chosen_person[1].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[1].put_health(-1);
            }

            else
                cout << chosen_person[1].get_health() << endl << endl;
        }

/// Second fighter attack

        if(chosen_person[1].get_health() < 0)
        {
            Win = 1;
        }
        else if(chosen_person[1].get_health() > 0)
        {
            cout << "\n\t\t<" << chosen_person[1].get_name() << "'s turn>" << endl;
            Win = 0;
        }

        do
        {
            cout << endl << "\t\t";
            cin >> fight_choice2;
        }
        while(fight_choice2 <= 0 || fight_choice2 >= j);

        if(fight_choice2 == 1)
        {
            system("Color 05");
            reverse1();
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 1));
            cout << "\n\t\t" << chosen_person[1].get_name() << " punched you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
        else if(fight_choice2 == 2)
        {
            system("Color 05");
            reverse3();
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 2));
            cout << "\n\t\t" << chosen_person[1].get_name() << " kicked you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }
        else if(fight_choice2 == 3)
        {
            system("Color 05");
            reverse2();
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 3));                cout << "\n\t\t" << chosen_person[1].get_name() << " slammed you on the ground! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }

        else if(fight_choice2 == 4)
        {
            system("Color 05");
            reverse4();
            chosen_person[0].put_health(chosen_person[0].get_health() - fight_moves(chosen_person[1].get_strength(), chosen_person[1].get_speed(), 4));
            cout << "\n\t\t" << chosen_person[1].get_name() << " drop kicked you! Your health is now: ";

            if (chosen_person[0].get_health() <= 0)
            {
                cout << "0" << endl << endl; chosen_person[0].put_health(-1);
            }

            else
                cout << chosen_person[0].get_health() << endl << endl;
        }

        i++;
    }
}

void show()
{
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                   **       **" << endl;
    cout << "\t\t\t\t\t\t\t\t                 *  ***   ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *      *  *       *  *      * *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *  *  *         *  *  *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *           *  *           *  *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **             **             *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *           *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *             *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *                 *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *                       *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **                           **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *                         *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **                     **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl << endl;
}

void show1()
{
    cout << "\t\t\t\t\t\t\t\t                                            " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                            **" << endl;
    cout << "\t\t\t\t\t\t\t\t                     * *  ***   *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *        *  *  *    *   *         * *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *   *  *  *  *     *   *   *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *           *  *   ***  *       *  *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **      **        **                *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *               *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *                 *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *                     *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *                            *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **                                **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *                              *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **                          **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                             " << endl << endl << endl << endl;
}

void show2()
{
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                       **" << endl;
    cout << "\t\t\t\t\t\t\t\t                     ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *       **     *   *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *  *  ***     *   *      * *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *           *  *           *  *  *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **             **             *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *           *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *              *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *                 *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *                       *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **                           **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *                         *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **                     **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl << endl;
}

void show3()
{
    cout << "\t\t\t\t\t\t\t\t                                  " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                      **" << endl;
    cout << "\t\t\t\t\t\t\t\t                    ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t                       *  *   *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *       **    *  *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *  *  ***   *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *           *  *    *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **    *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *   *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *     *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *     * *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *   *  *     *  *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **      *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **            **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                   " << endl << endl << endl << endl;
}

void show4()
{
    cout << "\t\t\t\t\t\t\t\t                                  " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                      **" << endl;
    cout << "\t\t\t\t\t\t\t\t                **  ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t              *  ***   *  *   *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *   *  *      *  *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *  *         *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *            *      *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *    *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *   *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *     *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *     * *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *   *  *     *  *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **      *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **             **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                   " << endl << endl << endl << endl;
}

void reverse1()
{
    cout << "\t\t\t\t\t\t\t\t                                             " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                         **" << endl;
    cout << "\t\t\t\t\t\t\t\t                      *   ***  * *" << endl;
    cout << "\t\t\t\t\t\t\t\t       * *         *   *     *  *  *        * *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *        *   *   *     *  *  *  *   *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *            *  *       *  ***   *  *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                **        **      **             *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                 *               *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *               *                 *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *           *                     *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *                            *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **                                **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *                              *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **                          **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                             " << endl << endl << endl << endl;
}

void reverse2()
{
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                        **" << endl;
    cout << "\t\t\t\t\t\t\t\t                      *  ***" << endl;
    cout << "\t\t\t\t\t\t\t\t                   *   *     **       **" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *      *   *     ***  *  *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *       *  *  *           *  *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **             **             *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *           *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t *              *              *              *" <<endl;
    cout << "\t\t\t\t\t\t\t\t    *          *                 *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *                       *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **                           **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *                         *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **                     **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                        " << endl << endl << endl << endl;
}

void reverse3()
{
    cout << "\t\t\t\t\t\t\t\t                                  " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                   **" << endl;
    cout << "\t\t\t\t\t\t\t\t                 *  ***" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *   *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *        *  *    **       * *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *            *   ***  *  *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *               *    *  *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                 *    **             *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                 *   *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *              *     *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *            * *     *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t        *    *  *     *  *   *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t               *        *      **" << endl;
    cout << "\t\t\t\t\t\t\t\t              *               *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t              **            **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                   " << endl << endl << endl << endl;
}

void reverse4()
{
    cout << "\t\t\t\t\t\t\t\t                                  " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                  **" << endl;
    cout << "\t\t\t\t\t\t\t\t                *  ***  **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *   *  *   ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *        *  *      *  *   * *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *            *         *  *       *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *               *      *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                 *    *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t *                 *   *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *              *     *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *            * *     *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t        *    *  *     *  *   *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t               *        *      **" << endl;
    cout << "\t\t\t\t\t\t\t\t              *               *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t              **            **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                                   " << endl << endl << endl << endl;
}

void Won()
{
    cout << "\t\t\t\t\t\t\t\t                    " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t    **" << endl;
    cout << "\t\t\t\t\t\t\t\t  ***   *" << endl;
    cout << "\t\t\t\t\t\t\t\t      *   *         * *" << endl;
    cout << "\t\t\t\t\t\t\t\t        *   *   *        *" << endl;
    cout << "\t\t\t\t\t\t\t\t           *  *            *" << endl;
    cout << "\t\t\t\t\t\t\t\t          **                *" << endl;
    cout << "\t\t\t\t\t\t\t\t          *                 *" << endl;
    cout << "\t\t\t\t\t\t\t\t           *               *" << endl;
    cout << "\t\t\t\t\t\t\t\t             *           *" << endl;
    cout << "\t\t\t\t\t\t\t\t                 *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t                   **" << endl;
    cout << "\t\t\t\t\t\t\t\t                  *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t                **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t                     " << endl << endl << endl << endl;
}

void lost()
{
    cout << "\t\t\t\t\t\t\t\t                        " << endl << endl << endl;
    cout << "\t\t\t\t\t\t\t\t                     * *" << endl;
    cout << "\t\t\t\t\t\t\t\t        * *        *  *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t     *       *   *  *  *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t   *           *  *   ***  *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *             **      **" << endl;
    cout << "\t\t\t\t\t\t\t\t *                *" << endl;
    cout << "\t\t\t\t\t\t\t\t  *              *" << endl;
    cout << "\t\t\t\t\t\t\t\t    *          *" << endl;
    cout << "\t\t\t\t\t\t\t\t       *    *" << endl;
    cout << "\t\t\t\t\t\t\t\t         **" << endl;
    cout << "\t\t\t\t\t\t\t\t        *  *" << endl;
    cout << "\t\t\t\t\t\t\t\t      **    **" << endl;
    cout << "\t\t\t\t\t\t\t\t              " << endl << endl << endl << endl;
}

