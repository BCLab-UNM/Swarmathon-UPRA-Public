#include "SearchController.h"
#include <angles/angles.h>

SearchController::SearchController() {
  rng = new random_numbers::RandomNumberGenerator();
  currentLocation.x = 0;
  currentLocation.y = 0;
  currentLocation.theta = 0;

  centerLocation.x = 0;
  centerLocation.y = 0;
  centerLocation.theta = 0;
  result.PIDMode = FAST_PID;

  result.fingerAngle = M_PI/2;
  result.wristAngle = M_PI/4;
}

void SearchController::Reset() {
  result.reset = false;
}

/**
 * This code implements a basic random walk search.
 */
Result SearchController::DoWork() {

  if (!result.wpts.waypoints.empty()) {
    if (hypot(result.wpts.waypoints[0].x-currentLocation.x, result.wpts.waypoints[0].y-currentLocation.y) < 0.15) {
      attemptCount = 0;
    }
  }

  if (attemptCount > 0 && attemptCount < 5) {
    attemptCount++;
    if (succesfullPickup) {
      succesfullPickup = false;
      attemptCount = 1;
    }
    return result;
  }
  else if (attemptCount >= 5 || attemptCount == 0)
  {
    attemptCount = 1;


    result.type = waypoint;
    Point  searchLocation;

    //select new position 50 cm from current location
    if (first_waypoint)
    {
first_waypoint = false;


    searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (5.5 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (5.5 * sin(searchLocation.theta));

second_waypoint = true;

    }
    else if (second_waypoint)//tiene que ser true para que entre
    {
second_waypoint = false;
      searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (2.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (2.0 * sin(searchLocation.theta));
third_waypoint = true;

    }

    else if (third_waypoint)
    {
        third_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
        //fourth_waypoint= true;
six_waypoint = true;
    }
   /*else if(fourth_waypoint)
        {
        fourth_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (4.5 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (4.5 * sin(searchLocation.theta));
fifth_waypoint = true;

        }
     else if(fifth_waypoint)
        {
        fifth_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (4.5 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (4.5 * sin(searchLocation.theta));
six_waypoint = true;

        }

*/
else if(six_waypoint)
{

six_waypoint = false;
searchLocation.theta = currentLocation.theta + 7*(M_PI/6);
      searchLocation.x = currentLocation.x + (5.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (5.0 * sin(searchLocation.theta));
seven_waypoint = true;

}

else if(seven_waypoint)
{
seven_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
eight_waypoint = true;

}
else if(eight_waypoint)
{
eight_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
nine_waypoint = true;

}
else if(nine_waypoint)
{
nine_waypoint = false;

searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (5.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (5.0 * sin(searchLocation.theta));

ten_waypoint = true;
}
else if(ten_waypoint)
{
ten_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
eleven_waypoint = true;
}
else if(eleven_waypoint)
{

eleven_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
twelve_waypoint = true;

}
else if(twelve_waypoint)
{
twelve_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));

thirdteen_waypoint = true;



}
else if(thirdteen_waypoint)
{

   thirdteen_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
fourteen_waypoint = true;


}
else if(fourteen_waypoint)
{
fourteen_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
fifthteen_waypoint = true;
}
else if(fifthteen_waypoint)
{
fifthteen_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
sixteen_waypoint = true;
}
else if(sixteen_waypoint)
{
sixteen_waypoint = false;
searchLocation.theta = currentLocation.theta + M_PI;
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
seventeen_waypoint = true;
}
else if(seventeen_waypoint)
{
seventeen_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (3.0 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (3.0 * sin(searchLocation.theta));
eightteen_waypoint = true;
}


else if(eightteen_waypoint)
{
eightteen_waypoint = false;
searchLocation.theta = currentLocation.theta + 5*(M_PI/4);
      searchLocation.x = currentLocation.x + (3.5 * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (3.5 * sin(searchLocation.theta));
nineteen_waypoint = true;
}

else if(nineteen_waypoint)
{
nineteen_waypoint = false;
searchLocation.theta = currentLocation.theta + 3*(M_PI/4);//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (2.5 * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (2.5 * sin(searchLocation.theta));

}



    result.wpts.waypoints.clear();
    result.wpts.waypoints.insert(result.wpts.waypoints.begin(), searchLocation);
    return result;
  }






}

void SearchController::SetCenterLocation(Point centerLocation) {

  float diffX = this->centerLocation.x - centerLocation.x;
  float diffY = this->centerLocation.y - centerLocation.y;
  this->centerLocation = centerLocation;

  //if (!result.wpts.waypoints.empty()) //Este if solamente se usa cuando cambiamos el currentLocation por centerLocation
  //{
  //result.wpts.waypoints.back().x -= diffX;
  //result.wpts.waypoints.back().y -= diffY;
  //}

}

void SearchController::SetCurrentLocation(Point currentLocation) {
  this->currentLocation = currentLocation;
}

void SearchController::ProcessData() {
}

bool SearchController::ShouldInterrupt(){
  ProcessData();

  return false;
}

bool SearchController::HasWork() {
  return true;
}

void SearchController::SetSuccesfullPickup() {
  succesfullPickup = true;
}

void SearchController::MoveLeft(int distance)
{
      searchLocation.theta = currentLocation.theta + M_PI;//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (distance * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (distance * sin(searchLocation.theta));
}
void SearchController::MoveRight(int distance)
{
searchLocation.theta = currentLocation.theta + 2*M_PI;//se mueve a 180 grados
      searchLocation.x = currentLocation.x + (distance * cos(searchLocation.theta));
      searchLocation.y = currentLocation.y + (distance * sin(searchLocation.theta));
}
void SearchController::MoveUp(int distance)
{
      searchLocation.theta = currentLocation.theta + M_PI/2;
      searchLocation.x = currentLocation.x + (distance * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (distance * sin(searchLocation.theta));
}
void SearchController::MoveDown(int distance)
{

searchLocation.theta = currentLocation.theta + 3*(M_PI/2);
      searchLocation.x = currentLocation.x + (distance * cos(searchLocation.theta));//corre a 5 metros
      searchLocation.y = currentLocation.y + (distance * sin(searchLocation.theta));



}

