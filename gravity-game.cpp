#include <iostream>

class GravityGame {
    public: 
        int score;
        bool gameOver;
        std::string direction;

        const int width = 40;
        const int height = 20;
        
        GravityGame() {
            score = 0;
            direction = "down";
        }

        void Setup() {
            std::cout << "setup" << std::endl;
        }

        void Draw() {
            std::cout << "draw" << std::endl;
        }

        void Input() {
            std::cout << "input" << std::endl;
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