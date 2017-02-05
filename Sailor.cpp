#include <iostream>
#include <math.h>
#include "Sailor.h"
#include "Dock.h"

Sailor::Sailor(): GameObject('S', 0) 
{
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	state = 'a';
	cout << "Sailor default constructed" << endl;
	destination.x = 0;
	destination.y = 0; 
	port = NULL;
	dock = NULL;
	hideout = NULL;
	preSize = 15;
}

Sailor::~Sailor()
{
	cout << "Sailor deconstructed" << endl;
}

Sailor::Sailor(int in_id, Dock* hideout): GameObject('S', in_id, hideout->get_location())
{
	this->hideout = hideout;
	health = 25;
	size = 15;
	hold = 100;
	cargo = 0;
	port = NULL;
	//dock = NULL;
	dock = hideout;
	//dock->get_location().x = hideout->get_location().x;
	//dock->get_location().y = hideout->get_location().y;
	state = 'h';
	destination.x = hideout->get_location().x;
	destination.y = hideout->get_location().y;
	preSize = 15;
	cout << "Sailor constructed" << endl;
}

bool Sailor::update_location()
{
	double dest_dist = cart_distance(destination, location);
	if (dest_dist <= get_speed())
	{
		location.x = destination.x;
		location.y = destination.y;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}
	else
	{
		location.x += delta.x;
		location.y += delta.y;
		cout << "Just keep sailing..." << endl;
		return false;
	}

}

void Sailor::setup_destination(CartPoint dest)
{	
	if ((location.x == destination.x) && (location.y == destination.y))
	{
		delta.x = 0;
		delta.y = 0;
	}

	state = 'o';
	destination.x = dest.x;
	destination.y = dest.y;
	delta.x = ((destination.x - location.x)*(get_speed()/cart_distance(destination, location)));
	delta.y = ((destination.y - location.y)*(get_speed()/cart_distance(destination, location)));
}

bool Sailor::update()
{
	switch(state)
	{
		case 'a':
			return false; //*
		break;

		case 's':
			update_location();
			location.x = get_location().x;
			location.y = get_location().y;
			if ((location.x == destination.x) && (location.y == destination.y))
			{
				state = 'a';
				return true;
			}
			//show_status();
			return false;
		
		break;

		case 'o':
			update_location();
			location.x = get_location().x;
			location.y = get_location().y;
			if ((location.x == destination.x) && (location.y == destination.y))
			{
				state = 'l';
				return true;
			}
			return false;
		break;

		case 'i':
			if (update_location() == true)
			{
				cout << display_code << get_id() << ": Starting to unload at a dock" << endl;
				state = 'u';
				return true;
			}
			else
			{
				return false;
			}
			break;

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

		case 'd':
			//show_status();
			return false; //*
			break;

		case 'h':
		//if ((destination.x == location.x) && (destination.y == location.y))
		if (update_location())
		{
			state = 'a';
			//cout << "I'm going to hide" << endl;
			dock = hideout;
			//cout << "I have hidden" << endl;
			//cout << display_code << get_id() << "Is hidden in dock" << dock->get_id() << endl;
			//cout << display_code << get_id() << "Is hidden in dock" << hideout->get_id() << endl;
			return true; //*
		}
		return false;
		/*else
			{
				cout<< display_code <<get_id() <<" is going to hide at Dock" << hideout->get_location();
				return false; 
			}*/
		break;



		case 't':
			//show_status();
			return false; //*
		break;

		default:
			cout << "Invalid case" << endl;
			return false; //*
		break;
	}
	return false; //*
} 

void Sailor::show_status()
{
	switch(state)
	{
		case 'a':

		if (this->is_hidden())
		{
			//cout <<"Is anchored and hiding. Has a size of: " << size << "cargo of: " << cargo << "hold of: " << hold << "health of: " << health << endl;
			cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is anchored (and hiding). Has a size of " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
		}
		else
		{
			//cout <<"Is anchored. Has a size of: " << size << "cargo of: " << cargo << "hold of: " << hold << "health of: " << health << endl;
			cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is anchored. Has a size of " << size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl; 
		}
		break;

		case 's':
		cout << "Has a speed of: " << get_speed() << "and is heading to: " << "<" << destination.x << ", " << destination.y << ">" << endl;
		break;

		case 'o':
		//cout << "Is outbound to Port: " << get_id() << "at location " << get_location() << "is outbound to Port " << port->get_id() << "with a speed of " << get_speed() << endl;
		cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() <<  "is outbound to Port: " << port->get_id() << " with a speed of " << get_speed() << endl;
		break;
		
		case 'i':
		cout << "Is inbound to Dock: " << get_id() << " with a speed " << get_speed() << endl;
		break;

		case 'l':
		//cout << "is supplying at Port " << get_id() << endl;
		cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is supplying at Port " << port->get_id() << endl;
		break;

		case 'u':
		//cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is supplying at Port " << port->get_id() << endl;
		cout << "Is unloading at Dock " << get_id() << endl;
		break;

		case 'd':
		cout << "Is docked at Dock " << get_id() << endl;
		//cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is supplying at Port " << port->get_id() << endl;
		break;

		case 't':
		cout << "is in trouble" << get_id() << endl;
		//cout << "Sailor status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "is supplying at Port " << port->get_id() << endl;

		case 'h':
		cout << "Sailor status: " << display_code << " with ID " << get_id() << "at location " << get_location() <<  "is going to hide at Dock " << dock->get_id() << endl;


	}
}

void Sailor::start_sailing(CartPoint dest)
{
	setup_destination(dest);
	if (state == 'd')
	{
		//set_sail(this);
		dock->set_sail(this);
	}
	state = 's';
	cout << "Sailing " << this->get_id() << "to " << "(" << destination.x << ", " << destination.y << ")" << endl;
	cout << display_code <<this->get_id() << " On my way" << endl;
}


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

void Sailor::start_hiding()
{
	setup_destination(hideout->get_location());
	state = 'h';
	cout << "Sailor " << get_id() << " hiding " << hideout->get_id() << endl;
	cout << display_code << get_id() << "Off ot hide" << endl;
}

bool Sailor::is_hidden()
{
	if ((location.x == hideout->get_location().x) && (location.y == hideout->get_location().y))
	{
		return true;
	}
	return false;
}

void Sailor::start_docking(Dock* destDock)
{
	dock = destDock;
	setup_destination(destDock->get_location());
	state = 'i';
	cout << "Sailor " << get_id() << "sailing to Dock " << dock->get_id() << endl;
	cout << display_code << get_id() << ": Off to dock " << endl;
}

void Sailor::anchor()
{
	state = 'a';
	cout << "Stopping " << get_id() << endl;
	cout << display_code << get_id() << "Dropping anchor" << endl;
}

double Sailor::get_speed()
{
	double speed = (get_size() - (cargo*0.1));
	return speed;
}

double Sailor::get_size()
{
	return size;
}

double Sailor::get_cargo()
{
	return cargo;
}

double Sailor::get_preSize()
{
	return preSize;
}


    















