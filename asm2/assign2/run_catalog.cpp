#include "catalog.h"

using namespace std;

int main(){

    string inputFile;// read file
    ifstream input(inputFile);

    

    inputFile = input_file(input);//get users file
    int teamsNum;
    input >> teamsNum;//get the first line as teams number

    Team * teams = setup(input, teamsNum);//store teams and players data
    while (true)
    {
        int op = choose_option(teams); //options
        if (op == 0) //if user wanna quit
        {
            break;
        }
        run_prog(teams, teamsNum, op);//do users choice
    }
    delete_info(teams, teamsNum);
}



    // }


   
