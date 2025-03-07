#include <iostream>
#include <string>
using namespace std;

class Stage {
    string stageName;
    int stageNum;

public:
    Stage(string sname, int snum) : stageName(sname), stageNum(snum) {}

    string getStageName() {
        return stageName;
    }

    int getStageNum() {
        return stageNum;
    }
};

class Game {
    string gameName;
    string category;
    int totalStages;
    Stage** stages;
    int stageCount;

public:
    Game(string gname, string cat, int numStages, Stage* stage1) : gameName(gname), category(cat), totalStages(numStages), stageCount(0) {
        if (totalStages > 0) {
            stages = new Stage*[totalStages];
            addStage(stage1);
        }
    }

    void addStage(Stage* stage) {
        if (stageCount < totalStages) {
            stages[stageCount] = stage;
            stageCount++;
        } else {
            cout << "Maximum stage number reached" << endl;
        }
    }

    void displayGameDetails() {
        cout << "Game Name: " << gameName << endl;
        cout << "Category: " << category << endl;
        cout << "Stages: " << endl;
        for (int i = 0; i < stageCount; i++) {
            cout << "Stage " << stages[i]->getStageNum() << ": " << stages[i]->getStageName() << endl;
        }
    }

    ~Game() {
        for (int i = 0; i < stageCount; i++) {
            delete stages[i];
        }
        delete[] stages;
    }
};

int main() {
    Stage stage1("The Beginning", 1);
    Game game1("The Great Quest", "Adventure", 3, &stage1);
    Stage stage2("The Journey", 2);
    Stage stage3("The Final Battle", 3);

    game1.addStage(&stage2);
    game1.addStage(&stage3);

    game1.displayGameDetails();

    return 0;
}

