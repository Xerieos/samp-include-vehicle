/** ======================================================================== **\
	Vehicle Static Data

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


#if defined _inc_vehicle_static_data
	#undef _inc_vehicle_static_data
#endif

#if defined _TDW_VEHICLE_D_STATIC_DATA
	#endinput
#endif

#define _TDW_VEHICLE_D_STATIC_DATA


enum
	e_TDW_VEHICLE
{
	// I created only necessary elements in the enumeration.
	Float:ei_spos_x,
	Float:ei_spos_y,
	Float:ei_spos_z,
	Float:ei_spos_a,
	ei_modelid
};


static stock
	TDW_g_sVehicleData[MAX_VEHICLES][e_TDW_VEHICLE],
	TDW_g_sVehicleColor1[MAX_VEHICLES char],
	TDW_g_sVehicleColor2[MAX_VEHICLES char],
	TDW_g_sVehicleId;


native nst_AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y,
	Float:spawn_z, Float:z_angle, color1, color2) = AddStaticVehicle;

stock
	TDWVH@AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z,
		Float:z_angle, color1, color2)
{
	if ((TDW_g_sVehicleId = AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z,
		z_angle, color1, color2)) != INVALID_VEHICLE_ID)
	{
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_modelid] = modelid;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_x] = spawn_x;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_y] = spawn_y;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_z] = spawn_z;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_a] = z_angle;
		TDW_g_sVehicleColor1{TDW_g_sVehicleData} = color1;
		TDW_g_sVehicleColor2{TDW_g_sVehicleData} = color2;
	#if defined _TDW_VEHICLE_FOREACH_ARRAY
		Iter_Add(Vehicle, TDW_g_sVehicleData);
	#endif
	}
	return TDW_g_sVehicleId;
}
#if defined _ALS_AddStaticVehicle
	#undef AddStaticVehicle
#else
	#define _ALS_AddStaticVehicle
#endif
#define AddStaticVehicle(%0) TDWVH@AddStaticVehicle(%0)


native nst_AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y,
	Float:spawn_z, Float:z_angle, color1, color2, respawn_delay, addsiren
	) = AddStaticVehicleEx;

stock
	TDWVH@AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y,
		Float:spawn_z, Float:z_angle, color1, color2, respawn_delay,
		addsiren = 0)
{
	if ((TDW_g_sVehicleId = AddStaticVehicleEx(modelid, spawn_x, spawn_y,
		spawn_z, z_angle, color1, color2, respawn_delay, addsiren)
		) != INVALID_VEHICLE_ID)
	{
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_modelid] = modelid;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_x] = spawn_x;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_y] = spawn_y;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_z] = spawn_z;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_a] = z_angle;
		TDW_g_sVehicleColor1{TDW_g_sVehicleData} = color1;
		TDW_g_sVehicleColor2{TDW_g_sVehicleData} = color2;
	#if defined _TDW_VEHICLE_FOREACH_ARRAY
		Iter_Add(Vehicle, TDW_g_sVehicleData);
	#endif
	}
	return TDW_g_sVehicleId;
}
#if defined _ALS_AddStaticVehicleEx
	#undef AddStaticVehicleEx
#else
	#define _ALS_AddStaticVehicleEx
#endif
#define AddStaticVehicleEx(%0) TDWVH@AddStaticVehicleEx(%0)


native nst_CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation,
	color1, color2, respawn_delay, addsiren) = CreateVehicle;

stock
	TDWVH@CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation,
		color1, color2, respawn_delay, addsiren = 0)
{
	if ((TDW_g_sVehicleId = CreateVehicle(vehicletype, x, y, z, rotation,
		color1, color2, respawn_delay, addsiren)) != INVALID_VEHICLE_ID)
	{
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_modelid] = modelid;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_x] = x;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_y] = y;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_z] = z;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_a] = rotation;
		TDW_g_sVehicleColor1{TDW_g_sVehicleData} = color1;
		TDW_g_sVehicleColor2{TDW_g_sVehicleData} = color2;
	#if defined _TDW_VEHICLE_FOREACH_ARRAY
		Iter_Add(Vehicle, TDW_g_sVehicleData);
	#endif
	}
	return TDW_g_sVehicleId;
}
#if defined _ALS_CreateVehicle
	#undef CreateVehicle
#else
	#define _ALS_CreateVehicle
#endif
#define CreateVehicle(%0) TDWVH@CreateVehicle(%0)


native nst_DestroyVehicle(vehicleid) = DestroyVehicle;

stock
	TDWVH@DestroyVehicle(vehicleid)
{
	if (DestroyVehicle(vehicleid) == 0)
		return 0;
	TDW_g_sVehicleData[TDW_g_sVehicleData][ei_modelid] =
	TDW_g_sVehicleColor1{TDW_g_sVehicleData} =
	TDW_g_sVehicleColor2{TDW_g_sVehicleData} = 0;
	TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_x] =
	TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_y] =
	TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_z] =
	TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_a] = 0.0;
	return 1;
}
#if defined _ALS_DestroyVehicle
	#undef DestroyVehicle
#else
	#define _ALS_DestroyVehicle
#endif
#define DestroyVehicle(%0) TDWVH@DestroyVehicle(%0)


native nst_ChangeVehicleColor(vehicleid,
	color1, color2) = ChangeVehicleColor;

#if defined _ALS_ChangeVehicleColor
#undef ChangeVehicleColor
#else
	#define _ALS_ChangeVehicleColor
#endif
#define ChangeVehicleColor(%0) SetVehicleColor(%0)


public
	OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	TDW_g_sVehicleColor1{vehicleid} = color1;
	TDW_g_sVehicleColor2{vehicleid} = color2;
#if defined TDWVH@OnVehicleRespray
	return TDWVH@OnVehicleRespray(playerid, vehicleid, color1, color2);
#else
	return 1;
#endif
}
#if defined _ALS_OnVehicleRespray
	#undef OnVehicleRespray
#else
	#define _ALS_OnVehicleRespray
#endif
#define OnVehicleRespray(%0) TDWVH@OnVehicleRespray(%0)
#if defined TDWVH@OnVehicleRespray
	forward TDWVH@OnVehicleRespray(playerid, vehicleid, color1, color2);
#endif


stock
	GetVehicelColor(vehicleid, &color1, &color2)
{
	if (TDW_g_sVehicleData[vehicleid][ei_modelid] == 0)
		return _:(color1 = color2 = 0);
	color1 = TDW_g_sVehicleColor1{vehicleid};
	color2 = TDW_g_sVehicleColor2{vehicleid};
	return 1;
}

stock
	SetVehicleColor(vehicleid, color1, color2)
{
	return (TDW_g_sVehicleData[vehicleid][ei_modelid] != 0
		? ChangeVehicleColor(vehicleid,
			(TDW_g_sVehicleColor1{vehicleid} = color1),
			(TDW_g_sVehicleColor2{vehicleid} = color2)
		)
		: INVALID_VEHICLE_ID
	);
}


stock
	CreateVehicleEx(vehicletype, Float:x, Float:y, Float:z, Float:rotation,
		color1, color2, respawn_delay, addsiren = 0)
{
	switch (vehicletype)
	{
		case 537, 538, 570, 570, 449:
		{
			TDW_g_sVehicleData = AddStaticVehicleEx(vehicletype, x, y, z,
				rotation, color1, color2, respawn_delay, addsiren);
		}
		default:
		{
			TDW_g_sVehicleData = CreateVehicle(vehicletype, x, y, z, rotation,
				color1, color2, respawn_delay, addsiren);
		}
	}
	if (TDW_g_sVehicleData != INVALID_VEHICLE_ID)
	{
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_modelid] = modelid;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_x] = x;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_y] = y;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_z] = z;
		TDW_g_sVehicleData[TDW_g_sVehicleData][ei_spos_a] = rotation;
		TDW_g_sVehicleColor1{TDW_g_sVehicleData} = color1;
		TDW_g_sVehicleColor2{TDW_g_sVehicleData} = color2;
	#if defined _TDW_VEHICLE_FOREACH_ARRAY
		Iter_Add(Vehicle, TDW_g_sVehicleData);
	#endif
	}
	return TDW_g_sVehicleData;
}