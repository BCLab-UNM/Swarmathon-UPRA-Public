#ifndef SEARCH_CONTROLLER
#define SEARCH_CONTROLLER

#include <random_numbers/random_numbers.h>
#include "Controller.h"

/**
 * This class implements the search control algorithm for the rovers. The code
 * here should be modified and enhanced to improve search performance.
 */
class SearchController : virtual Controller {

public:

  SearchController();

  void Reset() override;

  // performs search pattern
  Result DoWork() override;
  bool ShouldInterrupt() override;
  bool HasWork() override;

  // sets the value of the current location
  //void UpdateData(geometry_msgs::Pose2D currentLocation, geometry_msgs::Pose2D centerLocation);
  void SetCurrentLocation(Point currentLocation);
  void SetCenterLocation(Point centerLocation);
  void SetSuccesfullPickup();
  
//Christopher
void MoveStraight(int);
void MoveLeft(int);
void MoveRight(int);
void MoveDown(int);
void MoveUp(int);
void MoveDiagonalRight(int);
void MoveDiagonalLeft(int);
void DoSquare();




  int distance = 0;//

protected:

  void ProcessData();

private:

  random_numbers::RandomNumberGenerator* rng;
  Point currentLocation;
  Point centerLocation;
  Point searchLocation;
  int attemptCount = 0;

  //struct for returning data to ROS adapter
  Result result;

  // Search state
  // Flag to allow special behaviour for the first waypoint
  bool first_waypoint = true;
  bool second_waypoint = false;
  bool third_waypoint = false;
  bool fourth_waypoint = false;
  bool fifth_waypoint = false;
bool six_waypoint = false;
bool seven_waypoint = false;
bool eight_waypoint = false;
bool nine_waypoint = false;
bool ten_waypoint = false;
bool eleven_waypoint = false;
bool twelve_waypoint = false;
bool thirdteen_waypoint = false;
bool fourteen_waypoint = false;
bool fifthteen_waypoint = false;
bool sixteen_waypoint = false;
bool seventeen_waypoint = false;
bool eightteen_waypoint = false;
bool nineteen_waypoint = false;
  bool succesfullPickup = false;

};

#endif /* SEARCH_CONTROLLER */
