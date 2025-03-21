#pragma once
#include<raylib.h>
class Button
{
    public:
        Button(const char* imagePath,Vector2 imagePosition,float scale);
        ~Button();
        void draw();
        bool isPressed(Vector2 mousePos,bool mosePressed);
    private:
        Texture2D Texture;
        Vector2 position;
};


Button::Button(const char *imagePath, Vector2 imagePosition,float scale)
{
    Image image = LoadImage(imagePath);
    int originalWidth = image.width;
    int originalHeight = image.height;
    int newWidth = static_cast<int>(originalWidth * scale);
    int newHeight = static_cast<int>(originalHeight * scale);
    ImageResize(&image,newWidth,newHeight);
    Texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = imagePosition;
}
Button::~Button()
{
    UnloadTexture(Texture);
}
void Button::draw()
{
    DrawTextureV(Texture,position,WHITE);
}
bool Button::isPressed(Vector2 mousePos,bool mosePressed)
{
    Rectangle rect = {position.x,position.y,static_cast<float>(Texture.width),static_cast<float>(Texture.height)};
    if(CheckCollisionPointRec(mousePos,rect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        return true;
    }
    return false;
}