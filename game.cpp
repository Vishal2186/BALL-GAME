#include<iostream>
#include<raylib.h>
#include "components.hpp"




using namespace std;


paddle paddle2;
ball ball1;
cpuPaddle paddle1;


// Color lightblue = {101,154,210,255};


const int screen_height = 500;
const int screen_width = 800;
int ball_speed = 4;
int paddle_speed = 4;
int score_player = 0;
int score_CPU = 0;
void setup()
{
    paddle1.height = paddle2.height = 80;
    paddle1.width = paddle2.width = 15;
    paddle1.color = paddle2.color = WHITE;
    paddle1.X = 3;
    paddle2.X = screen_width - 17;
    paddle1.Y = screen_height/2 - paddle1.height/2;
    paddle2.Y = screen_height/2 - paddle2.height/2;
    paddle1.speed = paddle2.speed = paddle_speed;

    ball1.radius = 10;
    ball1.X = screen_width/2;
    ball1.Y = screen_height/2;
    ball1.color = GREEN;
    ball1.speed_X = ball1.speed_Y = ball_speed;

}
void logic()
{
    ball1.move();
    if(ball1.Y + ball1.radius >= screen_height || ball1.Y - ball1.radius <= 0)
    {
        ball1.speed_Y *= -1;
    }
    if(ball1.X + ball1.radius >= screen_width -  paddle2.width / 3)
    {
        ball1.speed_X *= -1;
        score_CPU++;
    }
    if(ball1.X - ball1.radius <= 0 + paddle1.width / 3)
    {
        ball1.speed_X *= -1;
        score_player++;
    }
    
    if (CheckCollisionCircleRec(Vector2{ball1.X,ball1.Y},ball1.radius,Rectangle{paddle2.X,paddle2.Y,paddle2.width,paddle2.height}))
    {
        ball1.speed_X *= -1;
    }
    if (CheckCollisionCircleRec(Vector2{ball1.X,ball1.Y},ball1.radius,Rectangle{paddle1.X,paddle1.Y,paddle1.width,paddle1.height}))
    {
        ball1.speed_X *= -1;
    }

}
void winner()
{
    if(score_CPU == 10 || score_player == 10)
    {
        DrawText(TextFormat("%s IS WINNER: %i",((score_CPU > score_player)?"CPU":"PLAYER"),((score_CPU > score_player)? score_CPU : score_player)),screen_width/2 - 130,screen_height/2 - 100,30,VIOLET);
        ball1.stop();
    }
}

int main1(){
    
    setup();
    InitWindow(screen_width,screen_height,"BALL GAME");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        winner();
        DrawCircle(screen_width/2,screen_height/2,40,LIGHTGRAY);
        DrawLine(screen_width/2,0,screen_width/2,screen_height,BLACK);
        DrawText(TextFormat("SCORE:%i",score_player),screen_width - 100,15,20,LIGHTGRAY);
        DrawText(TextFormat("SCORE:%i",score_CPU),15,15,20,LIGHTGRAY);
        paddle1.draw();
        paddle2.draw();
        ball1.draw();
        EndDrawing();
        paddle1.movements(ball1.Y,ball1.X,ball1.speed_X);
        paddle2.move();
        logic();

    }
    

    CloseWindow();
    return 0;
}