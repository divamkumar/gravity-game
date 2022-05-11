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

        bool processing;

        GravityGame() {
            score = 0;
            direction = "down";
            x = 5;
            y = 8;
            processing = false;
        }

        void Setup() {
            std::cout << "setup" << std::endl;
        }

        void Draw() {
            system("cls"); 

            // i is row, j is col, 
            for (int j=0; j<height; ++j) {
                for (int i=0; i<width; ++i) {
                    if (i == 0 || i == width-1 || j == 0 || j == height-1) {
                        std::cout << "#";
                    } else if (i == x && j == y) {
                        if (direction == "down") {
                            std::cout << "6";
                        } else {
                            std::cout << "9";
                        }
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
                            if (y == 1 && !processing) {
                                direction = "down";
                                processing = true;
                            }
                        } else {
                            if (y == 8) {
                                direction = "up";
                                processing = true;
                            }
                        }
                        break;
                }
            }
        }

        void Logic() {
            if (direction == "up" && processing) {
                --y;
                if (y == 1) {
                    processing = false;
                }
            } else if (direction == "down" && processing) {
                ++y;
                if (y == 8) {
                    processing = false;
                }
            }
        }
};

int main() {
    GravityGame g;
    g.Setup();
    while(!g.gameOver) {
        g.Draw();
        g.Input();
        g.Logic();
        // Sleep(100);
    }
    return 0; 
}