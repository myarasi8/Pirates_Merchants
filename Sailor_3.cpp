Sailor.cpp
PA3 "Pirates on the High C's"
 
Modified by Douglas Densmore 10/31/15
Copyright (c) 2015 Boston University. All rights reserved.
*/
 
#include "Sailor.h"
 
//Checked
Sailor::Sailor()
    :GameObject('S', 0)
{
    this->init();
    this->hideout = NULL;
    this->state = 'a';
    cout << "Sailor default constructed" << endl;
}
 
//Checked
Sailor::Sailor(int id_num, Dock* hideout)
    :GameObject('S', id_num, hideout->get_location())
{
    this->init();
    this->hideout = hideout;
    this->state = 'h';
    cout << "Sailor constructed" << endl;
}
 
//Checked
void Sailor::init()
{
    this->health = 25;
    this->size = 15;
    this->hold=100;
    this->cargo=0;
 
    this->destination = CartPoint(0,0);
    this->port = NULL;
    this->dock = NULL;
}
 
//Checked
double Sailor::get_speed()
{
    return (size-(cargo*.1));
}
 
//Checked
double Sailor::get_cargo()
{
    return cargo;
}
 
//Checked
bool Sailor::update_location()
{
    CartVector vector_from_dest = destination - location;
 
    if ( (fabs(vector_from_dest.x) <= fabs(delta.x)) && (fabs(vector_from_dest.y) <= fabs(delta.y)) ) {
        location = destination;
        //If it is close enough, get there
        cout << display_code << get_id() << ": I’m there!" << endl ;
        return true;
    }
    //Else just keep going
    location = location + delta;
    cout << display_code << get_id() << ": Just keep sailing..." << endl ;
 
    return false;
}
 
//Checked
void Sailor::setup_destination(CartPoint dest)
{
  this->destination = dest;
  this->delta = (this->destination - this->location) *
            (this->get_speed() / cart_distance(this->destination,this->location));
}
 
 
//Checked
void Sailor::start_sailing(CartPoint dest)
{
  if(this->state=='d'&& dock!=NULL)
    this->dock->set_sail(this);
   
  this->setup_destination(dest);
  this->state = 's';
 
  cout << "Sailing " << this->get_id() << " to " << this->destination << endl;
  cout << this->display_code << this->get_id() << ": On my way" << endl;
}
 
//Checked
void Sailor::start_supplying(Port* dest_port)
{
  if(this->state=='d' && dock!=NULL)
    this->dock->set_sail(this);
   
  this->state = 'o';
  this->destination = dest_port->get_location();
  this->setup_destination(this->destination);
  this->port = dest_port;
 
  cout << "Sailor " << this->get_id() << " supplying at Port " << dest_port->get_id()
          << " and going to Port " << (this->port)->get_id() << endl;
 
  cout << this->display_code << this->get_id() << ": Supplies here I come!" << endl;
}
 
//Checked
void Sailor::start_docking(Dock* dest_dock)
{
  if(this->state=='d'&& dock!=NULL)
    this->dock->set_sail(this);
   
  this->state = 'i';
  this->destination = dest_dock->get_location();
  this->setup_destination(this->destination);
  this->dock = dest_dock;
 
  cout << "Sailor " << this->get_id() << " sailing to Dock " << dest_dock->get_id() << endl;
 
  cout << this->display_code << this->get_id() << ": Off to Dock" << endl;
}
 
//Checked
void Sailor::start_hiding()
{
   
  if(this->state=='d'&& dock!=NULL)
    this->dock->set_sail(this);
   
  this->state = 'h';
  this->destination = hideout->get_location();
  this->setup_destination(this->destination);
 
  cout << "Sailor " << this->get_id() << " hiding " << hideout->get_id() << endl;
 
  cout << this->display_code << this->get_id() << ": Off to hide" << endl;
}
 
//Checked
void Sailor::anchor()
{
  this->state = 'a';
  cout << "Stopping " << this->get_id() << endl;
  cout << this->display_code << this->get_id() << ": Dropping anchor" << endl;
}
 
//Checked
double Sailor::get_size()
{
  return this->size;
}
 
//Checked
bool Sailor::is_hidden()
{
  return cart_compare(this->location, hideout->get_location());
}
 
/*
States:
a - anchored
s - sailing
o - outbound
i - inbound
u - unloading
l - loading
d - docked
h - hidden
t - trouble
*/
bool Sailor::update()
{
    switch(this->state){
      case 'a'://checked
        return false;
        break;
//***********************       
      case 's': //Checked
        if(update_location()){
            this->state = 'a';
            return true;
        }else {
            return false;
        }
        break;
//***********************
      case 'o'://Checked
        if(update_location())
        {
          this->state = 'l';
          cout << this->display_code << this->get_id() << ": Starting to supply at a port" << endl;
          return true;
        }
        else
        {
          return false;
        }
        break;
//***********************
    case 'i'://Checked
        if(update_location())
        {
          this->state = 'u';
          cout << this->display_code << this->get_id() << ": Starting to unload at a dock" << endl;
          return true;
        }
        else
        {
          return false;
        }
        break;
//***********************
      case 'u'://Checked
        if(this->dock->dock_boat(this))
        {
            if(this->cargo >0)
            {
                this->size = size + this->cargo*.2; //you upgrade your size
                this->hold = hold + this->size*.1; //you upgrade your hold
                this->cargo = 0;//drop off the cargo
            }
            state = 'd';
            cout << this->display_code << this->get_id() << ": I unloading at the dock" << endl;
            return true;
        }
        else
        {
            state = 't';
            cout << this->display_code << this->get_id() << ": Help! My home dock is full" << endl;
            return true;
        }
          return false;
          break;
//***********************
    case 'd'://Checked
        return false;
        break;
    break;        
//***********************
      case 'l': //Checked
        if(this->cargo == this->hold)
        {
          state = 'a';
          cout << this->display_code << this->get_id() << ": My boat is filled up. Send me to a Dock to unload. Dropping anchor" << endl;
          return true;
        }
        else
        {
          if(!(this->port)->is_empty())
          { 
            this->cargo += (this->port)->provide_supplies();
            if(this->cargo > this->hold)
            {
                //The next update function will no have the first if statement true
                this->cargo = this->hold;
            }
            cout << this->display_code << this->get_id() << ": My new cargo is " << this->cargo << endl;
            return false;
          }
          else
          {
            state = 'a';
            cout << this->display_code << this->get_id() << ": This Port has no more supplies for me. Dropping anchor" << endl;
            return true;
          }
        }
        break;
//***********************
      case 'h': 
      //You don't take up space when you hide at a dock (duh, you're hidden)
      if(update_location()){
            this->state = 'a';
            return true;
        }else {
            return false;
        }
        break;
//***********************
      case 't'://checked
        return false;
        break;
//***********************
      default:
        return false;
    }
}
 
 
void Sailor::show_status()
{
  cout << "Sailor status: ";
  GameObject::show_status();
  switch(this->state){
    case 'a'://Checked
      cout << "is anchored. Has a size of: " << this->size<<", cargo of: "<<this->cargo << ", hold of: " << this->hold << ", and health of: " << this->health << endl;
      break;
    case 'o'://Checked
      cout << "is outbound to Port: " << (this->port)->get_id()
            << " with a speed of " << this->get_speed() << endl;
      break;
    case 'i'://Checked
      cout << "is inbound to Dock: " << (this->port)->get_id()
            << " with a speed of " << this->get_speed() << endl;
      break;
    case 's': //Checked
      cout << "Has a speed of: " << this->get_speed()
            << " and is heading to: " << this->destination << endl;
      break;
    case 'u'://Checked
      cout << "is unloading at Dock " << (this->dock)->get_id() << endl;
      break;
    case 'h'://Checked
      cout << "is hidden in Dock " << (this->hideout)->get_id() << endl;
      break;
    case 'l'://Checked
      cout << "is supplying at Port " << (this->port)->get_id() << endl;
      break;
    case 'd'://Checked
      cout << "is docked at Dock " << (this->dock)->get_id() << endl;
      break;
    case 't'://Checked
      cout << "is in trouble " << this->get_id() << endl;
      break;
    default:
      cout << "is in an undetermined state. Sailor Spy? \n";
  }
}
 
Sailor::~Sailor()
{
    cout << "Sailor destructed." << endl;
}