/** ======================================================================== **\
	Vehicle Doors

| License:
Copyright (c) 2016 Double V

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1.	The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgement in the product documentation would be
	appreciated but is not required.
2.	Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.
3.	This notice may not be removed or altered from any source distribution.
\** ======================================================================== **/


#if defined _inc_door_manage
	#undef _inc_door_manage
#endif

#if defined _TDW_VHLIB__DOOR_MANAGE
	#endinput
#endif

#define _TDW_VHLIB__DOOR_MANAGE


#if !defined OpenVehicleDoor
	// Arguments:
	// %1 - vehicleid
	// %2 - E_TDW_VEHICLE_DOOR:door
	#define OpenVehicleDoor%0(%1,%2) SetVehicleDoorState(%1,%2,DOOR_OPENED)
#endif

#if !defined CloseVehicleDoor
	// Arguments:
	// %1 - vehicleid
	// %2 - E_TDW_VEHICLE_DOOR:door
	#define CloseVehicleDoor%0(%1,%2) SetVehicleDoorState(%1,%2,DOOR_CLOSED)
#endif

#if !defined IsVehicleDoorInState
	// Arguments:
	// %1 - vehicleid
	// %2 - E_TDW_VEHICLE_DOOR:door
	// %3 - E_TDW_DOOR_STATE:state
	#define IsVehicleDoorInState%0(%1,%2,%3)\
		(_:(GetVehicleDoorState(%1,%2)) == _:(E_TDW_DOOR_STATE:(%3)))
#endif


enum
	E_TDW_DOOR_STATE
{
	DOOR_NOT_SET = -1,
	DOOR_OPENED = 1,
	DOOR_CLOSED = 2
};



stock
	GetVehicleDoorState(vehicleid, E_TDW_VEHICLE_DOOR:door)
{
	if (IsValidVehicle(vehicleid) == 0)
		return 0;
	if (_:(0 <= _:door < MAX_VEHICLE_DOORS) == 0)
		return 0;

	new driver, passenger, backleft, backright;

	GetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);

	// Return state of the door, which was specified when calling the function.
	switch (door)
	{
		case FRONT_LEFT_DOOR:
			return driver;
		case FRONT_RIGHT_DOOR:
			return passenger;
		case REAR_LEFT_DOOR:
			return backleft;
		case REAR_RIGHT_DOOR:
			return backright;
	}
	return 0; // For compiler!
}


// Returns true if the vehicle exists, otherwise false.
stock
	SetVehicleDoorState(vehicleid, E_TDW_VEHICLE_DOOR:door,
		E_TDW_DOOR_STATE:newstate)
{
	if (IsValidVehicle(vehicleid) == 0)
		return 0;
	if (_:(0 <= _:door < MAX_VEHICLE_DOORS) == 0)
		return 0;

	new driver, passenger, backleft, backright;

	GetVehicleParamsCarDoors(vehicleid, driver, passenger, backleft, backright);

	switch (door)
	{
		case FRONT_LEFT_DOOR:
			return SetVehicleParamsCarDoors(vehicleid, _:newstate, passenger,
				backleft, backright
			);
		case FRONT_RIGHT_DOOR:
			return SetVehicleParamsCarDoors(vehicleid, driver, _:newstate,
				backleft, backright
			);
		case REAR_LEFT_DOOR:
			return SetVehicleParamsCarDoors(vehicleid, driver, passenger,
				_:newstate, backright
			);
		case REAR_RIGHT_DOOR:
			return SetVehicleParamsCarDoors(vehicleid, driver, passenger,
				backleft, _:newstate
			);
	}
	return 0; // For compiler!
}


// Returns true if the vehicle exists, otherwise false.
stock
	GetVehicleDoorPos(vehicletype, E_TDW_VEHICLE_DOOR:door,
		&Float:x, &Float:y, &Float:z)
{
	if (GetVehiclePos(vehicletype, x, y, z) == 0)
		return _:(x = y = z = 0.0); // return 0
	new Float:z_angle, Float:vehicle_x, Float:vehicle_y, Float:vehicle_z,
		Float:div;
	GetVehicleZAngle(vehicletype, z_angle);
	vehicletype = GetVehicleModel(vehicletype);
	switch (door)
	{
		case FRONT_LEFT_DOOR, FRONT_RIGHT_DOOR:
			GetVehicleModelInfo(vehicletype,
				VEHICLE_MODEL_INFO_FRONTSEAT,
				vehicle_x, vehicle_y, vehicle_z
			);
		case REAR_LEFT_DOOR, REAR_RIGHT_DOOR:
			GetVehicleModelInfo(vehicletype,
				VEHICLE_MODEL_INFO_REARSEAT,
				vehicle_x, vehicle_y, vehicle_z
			);
	}
	div = (_:door % 2) ? (vehicle_x) : (-vehicle_x);
	x = (floatsin((z_angle = 360 - z_angle), degrees) * vehicle_y) +
		(floatcos(z_angle, degrees) * div) + x;
	y = (floatcos(z_angle, degrees) * vehicle_y) -
		(floatsin(z_angle, degrees) * div) + y;
	z += vehicle_z;
	return 1;
}
