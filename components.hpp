#include<raylib.h>


class ball
{
    
    public:
        float radius, X, Y;
        Color color;
        int speed_X;
        int speed_Y;

        void draw()
        {
            DrawCircle(X,Y,radius,color);
        }
        void move()
        {
            X += speed_X;
            Y += speed_Y;
        }
        void stop()
        {
            speed_X = speed_Y = 0;
            X = GetScreenWidth()/2;
            Y = GetScreenHeight()/2;

        }
};

class paddle
{
    protected:
        void limits()
        {
            if(Y <= 0){Y = 0;}
            if(Y + height >= GetScreenHeight()){Y = GetScreenHeight() - height;}
        }
    public:
        float width, 
        X, Y, height,speed;
        Color color;
        void draw()
        {
            DrawRectangle(X,Y,width,height,color);
        }
        void move()
        {
            if(IsKeyDown(KEY_UP))
            {
                Y -= speed;
            }
            if (IsKeyDown(KEY_DOWN))
            {
                Y += speed;
            }
            limits();

        }
    
};

class cpuPaddle : public paddle
{
    public:
        void movements(float ball_y,float ball_x,int speed_x)
        {
            if(Y + height/2 > ball_y && speed_x < 0 )
            {
                Y -= speed - speed/4;
            }
            if(Y + height/2 <= ball_y && speed_x < 0)
            {
                Y += speed - speed/4;
            }
            limits();
        }
};

