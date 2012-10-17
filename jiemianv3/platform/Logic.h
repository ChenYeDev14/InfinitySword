#ifndef LOGIC_H
#define LOGIC_H

#include "Status.h"
#include <string>
#include <fstream>



namespace DS14
{

const int VERSION_LOGIC = 103;

class logic
{
private:
    Status gameState;
    Names gameNames;



public:
    bool FIRSTBLOOD;        //whether firstblood or not

    logic();
    bool init(std::string path);//init from a map file.Liu Xiaoyu will do the job.
    void init(DS14::Status s) {gameState = s;}
    GameInfo toPlayer(int side);//convert the status to send message to AIs.Wen Yuhao & Li Yudu will complete this function.
    void update (PlayerCommand * command1,PlayerCommand * command2);//update status using commands of AI.Zhou Erjin will complete this function.
    //void toReplay(std::string directory, Status * statusToFile, Names * namesToFile);//write to the replay file.Fan Mingxiang will do the job.
    Status getStatus();

    void HeroDeath(Status & gameState);

};

}

#endif
