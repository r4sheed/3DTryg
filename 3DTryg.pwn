#define FILTERSCRIPT

#include <a_samp>
#include <sscanf2>
#include <izcmd>
#include <streamer>
#include <colandreas>
#include <progress>
#include <FCNPC>
#include <YSF>
#include <GPS>

#define TRYG3D_ENABLE_PLAYER
#define TRYG3D_ENABLE_VEHICLE
#define TRYG3D_ENABLE_COLANDREAS
#define TRYG3D_ENABLE_STREAMER
#define TRYG3D_ENABLE_FCNPC
//#define TRYG3D_ENABLE_ACTOR
#define TRYG3D_ENABLE_GRENADEDETECTION
#define TRYG3D_ENABLE_VEHICLECOL
//#define TRYG3D_ENABLE_PLAYERCOL
//#define TRYG3D_ENABLE_ACTORCOL
#define TRYG3D_ENABLE_UNIVERSAL
//#define TRYG3D_ENABLE_DRAW3D
//#define TRYG3D_ENABLE_CATCHITEMS
//#define TRYG3D_ENABLE_YSF
#define TRYG3D_ENABLE_CAST3D

//#include <vnpc/vnpc>
//#include <StreamerFunction/StreamerFunction>
//#include <FoxForeach/FoxForeach>
#include <3DTryg/3DTryg>
#include <EVF/EVF>
//#include <RGB/RGB>
//#include <BitFunctions/BitFunctions>
#include <SWAP/SWAP>
//#include <DataConvert/DataConvert>
//#include <Logs/Logs>
//#include <LY/LY>
//#include <MD5/MD5>
//#include <SHA256/SHA256>
//#include <Santa/Santa>
//#include <route_rand/route_rand>
//#include <ExtendedGrenade/ExtendedGrenade>
//#include <Missile/Missile>
//#include <Missions/Missions>
//#include <PortalGun/PortalGun>
//#include <Graffiti/Graffiti>
//#include <Mines/Mines>
//#include <VehPara/VehPara>
//#include <SpecialVehicle/SpecialVehicle>
//#include <Stingers/Stingers>
//#include <Knife/Knife>
//#include <Magic/Magic>
//#include <Hunting/Hunting>
//#include <Hyperion/Hyperion>
//#include <hashtag/hashtag>
//#include <mentiones/mentiones>
//#include <VehicleMissileCol/VehicleMissileCol>

#include <Legion/Legion>

public OnFilterScriptInit(){
	
	Streamer_SetVisibleItems(STREAMER_TYPE_OBJECT,1000,-1);
	Streamer_ToggleIdleUpdate(0,1);
	
	return 1;
}

/*
new player_view[800];

stock make_player_view(Float:x, Float:y, Float:z, Float:rx, Float:rz, Float:vrx, Float:vrz){
	new Float:tx, Float:ty, Float:tz;
	for(new i = 0; i < 800; i++){
		if(IsValidDynamicObject(player_view[i])) DestroyDynamicObject(player_view[i]);
		Tryg3D::GetPointOnSphericalSector(x,y,z,rx,rz,50.0, vrx, vrz, tx,ty,tz);
		player_view[i] = CreateDynamicObject(19789,tx,ty,tz,0.0,0.0,0.0);
	}
}

CMD:view(playerid, params[]){
	new Float:x, Float:y, Float:z, Float:rx, Float:rz, Float:vrx, Float:vrz;
	if(sscanf(params,"ff",vrx,vrz)) return SendClientMessage(playerid,0xFFFFFFFF,"Usage /view <vrx> <vrz>");
	GetPlayerCameraPos(playerid,x,y,z);
	Tryg3D::GetPlayerCameraRotation(playerid,rx,rz);
	make_player_view(x,y,z,rx,rz,vrx,vrz);
	return 1;
}
*/

#pragma dynamic 262144