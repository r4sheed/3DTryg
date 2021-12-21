#define FILTERSCRIPT

#include <a_samp>
#include <izcmd>
#include <sscanf2>
#include <streamer>
#include <colandreas>
#include <FCNPC>
#include <YSF>

#define TRYG3D_ENABLE_PLAYER
#define TRYG3D_ENABLE_VEHICLE
#define TRYG3D_ENABLE_COLANDREAS
#define TRYG3D_ENABLE_STREAMER
#define TRYG3D_ENABLE_FCNPC
#define TRYG3D_ENABLE_ACTOR
#define TRYG3D_ENABLE_GRENADEDETECTION
#define TRYG3D_ENABLE_VEHICLECOL
#define TRYG3D_ENABLE_PLAYERCOL
#define TRYG3D_ENABLE_ACTORCOL
#define TRYG3D_ENABLE_UNIVERSAL
#define TRYG3D_ENABLE_DRAW3D
#define TRYG3D_ENABLE_CATCHITEMS
#define TRYG3D_ENABLE_YSF
#define TRYG3D_ENABLE_CAST3D

#include "3DTryg.inc"

public OnFilterScriptInit(){
	
	return 1;
}

#pragma dynamic 262144