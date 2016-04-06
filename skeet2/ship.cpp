//
//  ship.cpp
//  asteroids
//
//  Created by Administrator on 2/6/16.
//  Copyright © 2016 BYU. All rights reserved.
//

#include "ship.h"
void Ship :: turnLeft()
{
   //set degrees of rotation
   int degrees = 10;
   
   //if the tick count is less than or equal to zero
   if(ticks >= 0) ticks++;    //subract one from the tick count
   else           ticks = 1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = 3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   //if (this->getOrientation() < shipAngleMax)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   //else
      //Item::setOrientation(shipAngleMax); //otherwise, reset to max
}

void Ship :: turnRight()
{
   //set degrees of rotation
   int degrees = -10;
   
   //if the tick count is less than or equal to zero
   if(ticks <= 0) ticks--;    //subract one from the tick count
   else           ticks = -1; //otherwise, set the tick count to -1
   
   //if the tick count is less than -3
   if(ticks < -5) degrees = -3; //set the degrees of rotation to -3
   
   //if the rifle orientation is less than the max
   //if (this->getOrientation() > shipAngleMin)
      Item::setOrientation(Item::getOrientation() + degrees); //add degrees (-)
   //else
      //Item::setOrientation(shipAngleMin); //otherwise, reset to max
}

void Ship :: thrust()
{
   Velocity push(.2, 0.0);
   push.setAngle(this->getOrientation());
   Point p((velocity.getSlope().getX() + push.getSlope().getX()),
            velocity.getSlope().getY() + push.getSlope().getY());
   velocity.setSpeed(sqrt(pow(p.getX(),2) + pow(p.getY(),2)));
   velocity.setSlope(p);
}

void Ship :: fireShip(std::vector <Bullet> & bulletVector)
{
    //If we have less than 5 bullets in the vector
    if (bulletVector.size() < 5)
    {
       //create a new bullet
       Bullet b;
       
       Point l = this->getLocation();
       b.setLocation(l);

       b.setOrientation(0);
       
       Velocity v;
       v.setSpeed(10);
       v.setAngle(this->getOrientation());
       
       b.setVelocity(v);
       
       bulletVector.push_back(b);
    }
}