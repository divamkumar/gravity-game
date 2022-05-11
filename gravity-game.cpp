#include <iostream>
#include <windows.h>
#include <conio.h>

class GravityGame {
    public: 
        int score;
        bool gameOver;
        std::string direction;

        const int width = 30;
        const int height = 20;
        
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

            std::cout << direction << std::endl;
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