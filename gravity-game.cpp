#include <iostream>
#include <windows.h>
#include <conio.h>

class GravityGame {
    public: 
        int score;
        bool gameOver;
        std::string direction;
        int sleeptime;

        const int width = 50;
        const int height = 10;
        
        int x,y, obstx, obsty;

        GravityGame() {
            score = 0;
            direction = "down";
        }

        void Setup() {
            std::cout << "setup" << std::endl;
        }

        void Draw() {
            system("cls"); 

            // i is row, j is col, 
            for (int i=0; i<height; ++i) {
                for (int j=0; j<width; ++j) {
                    if (j == 0 || j == width-1 || i == 0 || i == height-1) {
                        std::cout << "#";
                    } else {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        void Input() {
            if (_kbhit()){
                switch(_getch()) {
                    case ' ':
                        if (direction == "up") {
                            direction = "down";
                        } else {
                            direction = "up";
                        }
                        break;
                }
            }
        }

        void Logic() {
            std::cout << "logic" << std::endl;
        }
};

int main() {
    GravityGame g;
    g.Setup();
    while(!g.gameOver) {
        g.Draw();
        g.Input();
        g.Logic();
    }
    return 0; 
}