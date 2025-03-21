#include<iostream>
#include<raylib.h>
#include "Button.hpp"
#include "game.cpp"

using namespace std;
int main()
{
    InitWindow(800,500,"BUTTONS");
    SetTargetFPS(60);
    bool exit = false;
    Image image = LoadImage("Graphics/background.png");
    Texture2D background = LoadTextureFromImage(image);
    UnloadImage(image);
    Button startButton{"Graphics/start_button.png",{300,150},0.65};
    Button ExitButton{"Graphics/exit_button.png",{300,300},0.65};
    while (!WindowShouldClose() && exit == false)
    {
        Vector2 MousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if(startButton.isPressed(MousePosition,mousePressed))
        {
            cout<<"Start button pressed"<<endl;
            CloseWindow();
            main1();
        }
        if(ExitButton.isPressed(MousePosition,mousePressed))
        {
            cout<<"Exit button pressed"<<endl;
            exit = true;
        }

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background,0,0,WHITE);
        startButton.draw();
        ExitButton.draw();
        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
    return 0;
}