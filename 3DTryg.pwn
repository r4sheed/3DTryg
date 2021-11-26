#define FILTERSCRIPT

#include <a_samp>

//#define TRYG3D_ENABLE_PLAYER
//#define TRYG3D_ENABLE_VEHICLE
#define TRYG3D_ENABLE_DRAW3D

#include "3DTryg.inc"

public OnFilterScriptInit(){
	
	new Float:rng;
	
	print("stage 1");
	
	new Float:fmin = 9999.0, Float:fmax = -1.0;
	for(new i = 0; i < 250000; i++){
		rng = Tryg3D::RandomFloat(0.0,50.0,4);
		if(rng < fmin) fmin = rng;
		if(rng > fmax) fmax = rng;
	}
	
	printf("%f %f",fmin,fmax);
	
	print("stage 2");
	for(new i = 0; i < 25000; i++){
		rng = Tryg3D::RandomFloatEx(-5.0,115.0);
		if(rng < -5.0 || rng > 115.0) printf("%f",rng);
	}
	
	print("stage 3");
	for(new i = 0; i < 25000; i++){
		rng = Tryg3D::RandomFloatEx(-50.0,-15.0);
		if(rng < -50.0 || rng > -15.0) printf("%f",rng);
	}
	
	
	
	return 1;
}

#pragma dynamic 262144