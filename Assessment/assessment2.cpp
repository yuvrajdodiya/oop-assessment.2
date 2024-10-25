//assessment.2
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
using namespace std;
class Game 
{
    private:
        string player_name;
        int round;
        int playerscore = 0, computerscore = 0;
        int playerchoice;

    public:
    void Name() 
	{
		cout<<"*--*--*--*--*--*--"<<endl;
		cout<<" Name "<<endl;
		cout<<"*--*--*--*--*--*--"<<endl;
        cout<<"The Player Name Is : ";
        cin>>player_name;
    }
    void Rounds() 
	{
		cout<<"*--*--*--*--*--*--*"<<endl;
		cout<<" Rounds "<<endl;
		cout<<"*--*--*--*--*--*--*"<<endl;
        cout<<"\nHow Many Rounds Do You Want To Play? ";
        cin>>round;
    }
    int ComputerChoice() 
	{
        return (rand() % 3) + 1;
    }
    void getPlayerChoice() 
	{
        cout<<"1) ROCK " << endl;
        cout<<"2) PAPER" << endl;
        cout<<"3) SCISSOR" << endl;
        cout<<"\n--> Choose Your Choice :";
        cin>>playerchoice;
    }
    string ScoreName(int choice) 
	{
        switch (choice) 
		{
            case 1:
                return "Rock";
            case 2:
                return "Paper";
            case 3:
                return "Scissor";
            default:
                return "Invalid";
        }
    }

    void playGame() 
	{
        for (int i = 1; i <= round; i++) 
		{
			cout<<"*--*--*--*--*--*--*--"<<endl;
		    cout<<" Game "<<endl;
			cout<<"*--*--*--*--*--*--*--"<<endl;
            cout<<"Round NO : "<< i<<" /"<<round<<endl;
            cout<<"--* "<<player_name<<" score = "<<playerscore<<endl;
            cout<<"--* computerscore = "<<computerscore<<endl;
            getPlayerChoice();
            int computerchoice = ComputerChoice();
            cout<<player_name<<" choose: "<<ScoreName(playerchoice)<<endl;
            cout << "--> Computer choose: "<<ScoreName(computerchoice)<<endl;

            if (playerchoice == computerchoice) 
			{
                cout<<"DRAW"<<endl;
            } 
			else if ((playerchoice == 1 && computerchoice == 3) ||
                       (playerchoice == 2 && computerchoice == 1) ||
                       (playerchoice == 3 && computerchoice == 2)) 
			{
                cout<<player_name<<" wins this round!"<<endl;
                playerscore++;
            } 
			else 
			{
                cout<<"Computer wins this round!"<<endl;
                computerscore++;
            }
        }
        cout<<"\n Final Score:";
        cout<<player_name<< ": " <<playerscore<<endl;
        cout<<"\n Computer: "<<computerscore;

        if (playerscore > computerscore) 
		{
            cout<<player_name<<" wins the game!"<<endl;
        } else if (playerscore < computerscore) 
		{
            cout<<"\n Computer wins the game!";
        } 
		else 
		{
            cout<<"\n DRAW";
        }
    }
        void Continue() 
	    {
          char ans;
          cout<<"\nDo you want to continue? Press 'y' for yes and 'n' for no: "<<endl;
          cin>>ans;
        if(ans=='y') 
		{
            Game g;
            g.Name();
            g.Rounds();
            g.playGame();
            g.Continue();
        } 
		else if(ans=='n') 

		{
            exit(0);
        }
    }
};

int main() 
{
    srand(time(0));
    Game g1;
    g1.Name();
    g1.Rounds();

    g1.playGame();
    g1.Continue();

    return 0;
}




