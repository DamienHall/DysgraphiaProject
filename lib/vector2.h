#include <string>

class Vector2 {
  private:
    float x;
    float y;
  public:
    Vector2();
    Vector2(float x, float y);
    std::string toString();
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    void set(float x, float y);
    Vector2 add(Vector2 vec);
    Vector2 subtract(Vector2 vec);
    Vector2 scale(float scalar);
    float getMagnitude();
    float distanceFrom(Vector2 vec);
};
