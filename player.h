#ifndef PLAYER_H
#define PLAYER_H

#include <QLabel>

// The player class. In mp mode, there
// will be multiple player objects, so
// we may as well make it an object from
// the start.

class Player
{
private:
    int rotation; // The direction the ship is pointing (360 degrees)
    int x, y; // x, y = current ship loc - int, to get proper movement. Should be rounded to ints for graphics purposes
    int speed; // the current speed the ship is traveling at (may be rewritten)
    int angle; // the angle the ship is drifting at
public:
    Player(int startX, int startY): x(startX), y(startY), rotation(0), speed(0) { }

    // Accessor methods (mostly for debugging)
    int getX() { return x; }
    int getY() { return y; }
    int getRot() { return rotation; }
    int getAngle() { return angle; }
    int getSpeed() { return speed; }

    // Updates the player's position based on speed and angle
    void move();
    // Rotates the ship to the left
    void turnLeft();
    // Rotates the ship to the right
    void turnRight();
    // Increases the ship's speed
    void accelerate();
    // Decreases the ship's speed
    void decelerate();

    // Save/load methods. Again, not
    // sure how appropriate this is
    // to our game concept.
    //void load();
    //void save();
    // Could not make Player inherit from SavableObject.
    // Kept complaining about 'undefined reference to vtable'
    // Because SavableObject has no constructor that takes
    // two ints.
    // How to fix this???
};

class Phaser : public QLabel
{

private:


public:
    int x, y, dx, dy, rad, speed, angle;
    int r;
    bool firing;

    explicit Phaser(QWidget *parent,int init_angle, int initx, int inity);

    int getX() { return x; }
    int getY() { return y; }
    int getDX() { return dx; }
    int getDY() { return dy; }
    int getRad() { return rad; }
    int getSpeed() { return speed; }
    int getR() { return r; }

    void setX(int initx) { x = initx; }
    void setY(int inity) { y = inity; }
    void setAngle(int init_angle) { angle = init_angle; }

};

#endif // PLAYER_H