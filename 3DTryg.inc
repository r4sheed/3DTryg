/*
 3DTryg.inc
 Copyright © 2021 Abyss Morgan. All rights reserved.
 Contributors: Crayder, IllidanS4, Nero_3D, RyDeR, Zoutdaxv, hesambia, Neil Lamoureux, Ivan_Ino, Ralfie, Unrea1, $continue$, Mr.Reus, Switel12

 Website: N/A

 Plugins: N/A
 Internal Modules: N/A
 
 Platform: RAW

 File Version: 1.0.0
*/

/********************************
 * Version Check Example        *
 ********************************/

/*
//Check Version 3DTryg.inc
#if !defined TRYG3D_REMASTERED_INCLUDE
	#error [ADM] This include required 3DTryg.inc Gen.2 v1.0.0
#elseif !defined TRYG3D_VERSION
	#error [ADM] Update your 3DTryg.inc to Gen.2 v1.0.0
#elseif (TRYG3D_VERSION < 10000)
	#error [ADM] Update your 3DTryg.inc to Gen.2 v1.0.0
#endif
*/

/********************************
 * Version                      *
 ********************************/

#if defined TRYG3D_SAMP_INCLUDE
	#error [ADM] Trying to include 3DTryg.inc Gen. 2 with already included 3DTryg.inc Gen. 1
#endif

#if defined TRYG3D_REMASTERED_INCLUDE
	#endinput
#endif
#define TRYG3D_REMASTERED_INCLUDE

#define TRYG3D_VERSION                                  (10000) //a.b.c g+10000*a+100*b+c
#define TRYG3D_LIBRARY_NAME                             "3DTryg"
#define TRYG3D_AUTHOR_NAME                              "Abyss Morgan"

#define TRYG3D_PLATFORM_NAME                            "RAW"
#define TRYG3D_PLATFORM_VERSION                         "1.0.0"

#define Tryg3D::                                        T3_

#define T3D:                                            v3D

/********************************
 * Modules                      *
 ********************************/

#if defined TRYG3D_MODULE_PLAYER
    #error [ADM] Module already defined: TRYG3D_MODULE_PLAYER
#else
    #if defined TRYG3D_ENABLE_PLAYER
        #define TRYG3D_MODULE_PLAYER                    "Player"
    #endif
#endif

#if defined TRYG3D_MODULE_VEHICLE
    #error [ADM] Module already defined: TRYG3D_MODULE_VEHICLE
#else
    #if defined TRYG3D_ENABLE_VEHICLE
        #define TRYG3D_MODULE_VEHICLE                   "Vehicle"
    #endif
#endif

#if defined TRYG3D_MODULE_DRAW3D
    #error [ADM] Module already defined: TRYG3D_MODULE_DRAW3D
#else
    #if defined TRYG3D_ENABLE_DRAW3D
        #define TRYG3D_MODULE_DRAW3D                    "Draw3D"
    #endif
#endif
 
/********************************
 * Definitions                  *
 ********************************/

#if !defined FLOAT_PI
    #define FLOAT_PI                                    (3.14159265358979323846)
#endif

#if !defined FLOAT_EULER
    #define FLOAT_EULER                                 (2.718281828459)
#endif

#if !defined FLOAT_NAN
    #define FLOAT_NAN                                   (Float:0xFFFFFFFF)
#endif

#if !defined FLOAT_DEFECT
    #define FLOAT_DEFECT                                (0.000001)
#endif

#if !defined FLOAT_INFINITY
    #define FLOAT_INFINITY                              (Float:0x7F800000)
#endif

#if !defined TRYG3D_MAX_POLYGON_POINTS
    #define TRYG3D_MAX_POLYGON_POINTS                   (256)
#endif
#if TRYG3D_MAX_POLYGON_POINTS < 10
    #error [ADM] Definition TRYG3D_MAX_POLYGON_POINTS must be greater or equal than 10
#endif

#if !defined TRYG3D_VEHICLE_SPEED_MULTIPLIER
    #define TRYG3D_VEHICLE_SPEED_MULTIPLIER             (170.0)
#endif

#if !defined TRYG3D_PLAYER_SPEED_MULTIPLIER
    #define TRYG3D_PLAYER_SPEED_MULTIPLIER              (1.0)
#endif
 
#if !defined TRYG3D_DEFAULT_RANDOM_ACCURACY
    #define TRYG3D_DEFAULT_RANDOM_ACCURACY              (4)
#endif

#if !defined TRYG3D_CHARACTER_GROUND_Z_DIFF
    #define TRYG3D_CHARACTER_GROUND_Z_DIFF              (0.992288)
#endif

#if !defined VERTICAL_CAMERA_RADIUS
    #define VERTICAL_CAMERA_RADIUS                      (55.0) // 27.5 * 2
#endif

#if !defined HORIZONTAL_CAMERA_RADIUS
    #define HORIZONTAL_CAMERA_RADIUS                    (70.0) // 35.0 * 2
#endif

#if !defined TRYG3D_MAX_AREA_CHECK
    #define TRYG3D_MAX_AREA_CHECK                       (256)
#endif
#if TRYG3D_MAX_AREA_CHECK < 32
    #error [ADM] Definition TRYG3D_MAX_AREA_CHECK must be greater or equal than 32
#endif

#define TRYG3D_INVALID_ROTATION                         (-1000.0)
#define TRYG3D_INVALID_VIRTUAL_WORLD                    (-2000)
#define TRYG3D_INVALID_MOVE_TIME                        (-1)
#define TRYG3D_INVALID_MOVE_SPEED                       (-1.0)
#define TRYG3D_INVALID_ORIENTATION                      (-1)
#define TRYG3D_MAX_MODULES_STRING                       (400)
#define TRYG3D_RANDOM_MAX_ANGLE                         (359.999999)
#define TRYG3D_VBTP                                     (0x7FFFFFFF)
#define TRYG3D_VLTP                                     (0x80000000)

/********************************
 * Enums                        *
 ********************************/
 
enum Tryg3D::EulerModes {
	// Proper / Classic Euler angles
	T3D:euler_xzx,
	T3D:euler_xyx,
	T3D:euler_yxy,
	T3D:euler_yzy,
	T3D:euler_zyz,
	T3D:euler_zxz,
	// Tait-Bryan angles
	T3D:euler_xzy,
	T3D:euler_xyz,
	T3D:euler_yxz,
	T3D:euler_yzx,
	T3D:euler_zyx, // pitch roll yaw
	T3D:euler_zxy // sa-mp
}

enum Tryg3D::OrientationCube3D {
	o_left_back_down,
	o_right_back_down,
	o_right_front_down,
	o_left_front_down,
	o_left_back_up,
	o_right_back_up,
	o_right_front_up,
	o_left_front_up
}

enum Tryg3D::ElementOrientation {
	o_left,
	o_right,
	o_up,
	o_down,
	o_front,
	o_back,
	o_front_left,
	o_front_right,
	o_back_left,
	o_back_right,
}

enum Vectors3D {
	Float:T3D:X, Float:T3D:Y, Float:T3D:Z, Float:T3D:A
}

enum Float3D {
	Float:T3D:X, Float:T3D:Y, Float:T3D:Z,
	Float:T3D:rX, Float:T3D:rY, Float:T3D:rZ,
	
	Float:T3D:tX, Float:T3D:tY, Float:T3D:tZ,
	
	T3D:VW, T3D:INT, Float:T3D:SPEED
}

enum LongFloat3D {
	Float:T3D:X, Float:T3D:Y, Float:T3D:Z,
	Float:T3D:rX, Float:T3D:rY, Float:T3D:rZ,
	
	Float:T3D:tX, Float:T3D:tY, Float:T3D:tZ,
	Float:T3D:trX, Float:T3D:trY, Float:T3D:trZ,
	
	Float:T3D:VecX, Float:T3D:VecY, Float:T3D:VecZ,
	
	T3D:VW, T3D:INT, Float:T3D:SPEED
}

/********************************
 * Variables                    *
 ********************************/
 
new const Float: Tryg3D::WeaponDamage[] = {
	1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,82.5,0.0,1.0,9.9,46.2,0.0,8.25,13.2,46.2,3.3,3.3,4.95,6.6,8.25,
	9.9,9.9,6.6,24.75,41.25,82.5,82.5,1.0,46.2,82.5,0.0,0.33,0.33,0.0,0.0,0.0,0.0,0.0,2.64,9.9,330.0,82.5,1.0,1.0,165.0
};

const Tryg3D::EulerModes: T3D:euler_default = T3D:euler_zxy;

new bool: Tryg3D::StateInit = true,
	bool: Tryg3D::StateExit = true,
	Float: Tryg3D::StreamDistance = 300.0,
	Tryg3D::UpTime = 0;

static const Float: Tryg3D::Cube3DOffset[Tryg3D::OrientationCube3D][3] = {
	{-1.0,-1.0,-1.0},	//left - back - down
	{1.0,-1.0,-1.0},	//right - back - down
	{1.0,1.0,-1.0},		//right - front - down
	{-1.0,1.0,-1.0},	//left - front - down
	{-1.0,-1.0,1.0},	//left - back - up
	{1.0,-1.0,1.0},		//right - back - up
	{1.0,1.0,1.0},		//right - front - up
	{-1.0,1.0,1.0}		//left - front - up
};

new const Float: Tryg3D::OrientationRotation[Tryg3D::ElementOrientation][2] = {
	{0.0,90.0},
	{0.0,-90.0},
	{90.0,0.0},
	{-90.0,0.0},
	{0.0,0.0},
	{0.0,-180.0},
	{0.0,45.0},
	{0.0,-45.0},
	{0.0,135.0},
	{0.0,-135.0}
};

#if !defined T3_OrientationNames
	new Tryg3D::OrientationNames[10][] = {
		"Left","Right","Up","Down","Front","Back","Front left","Front right","Back left","Back right"
	};
#endif

#if !defined T3_OrientationCompass
	new Tryg3D::OrientationCompass[10][] = {
		"West","East","","","North","South","North West","North East","South West","South East"
	};
#endif

/********************************
 * Complementary Functions      *
 ********************************/

#define abs(%0)									(((%0) < 0)?(-(%0)):((%0)))
#define fabs(%0)								(((%0) < 0.0)?(-(%0)):((%0)))
#define	sqrtN(%0,%1)							floatpower((%0),(1.0/(%1)))
#define IsEven(%0)								((((%0) % 2) == 0)?(true):(false))
#define power(%0,%1)							(floatround(floatpower((%0),(%1))))

/********************************
 * Internal Functions           *
 ********************************/

#define T3_SingleClock(%1,%2)					((360.0/(%1))*(%2))
#define T3_EvenClock(%1,%2)						((360.0/(%1))*(2*(%2)))
#define T3_UnevenClock(%1,%2)					((360.0/(%1))*((2*(%2))-1))

#define T3_NLTZ(%0)								(((%0) < 0)?(0):(%0))
#define T3_NMTZ(%0)								(((%0) > 0)?(0):(%0))
#define T3_NLTZF(%0)							(((%0) < 0.0)?(0.0):(%0))
#define T3_NMTZF(%0)							(((%0) > 0.0)?(0.0):(%0))

#define T3_NLTV(%0,%1)							(((%0) < (%1))?(%1):(%0))
#define T3_NMTV(%0,%1)							(((%0) > (%1))?(%1):(%0))
#define T3_NLTVF(%0,%1)							(((%0) < (%1))?(%1):(%0))
#define T3_NMTVF(%0,%1)							(((%0) > (%1))?(%1):(%0))

#define T3_GetWeaponDamage(%0)					Tryg3D::WeaponDamage[(%0)]
#define T3_RotationInRange(%0,%1,%2)			((%0) >= (%1) && (%0) <= (%2))
#define T3_RoundAccuracy(%0)					(floatround((%0)*10000.0)/10000.0)
#define T3_AppendLineArguments2D(%0,%1,%2) 		%0[0] = (%1), %0[0] = (%2)
#define T3_AppendLineArguments3D(%0,%1,%2,%3) 	%0[0] = (%1), %0[0] = (%2), %0[0] = (%3)
#define T3_DivideValues(%0,%1,%2,%3)			((%1) /= (%0)), ((%2) /= (%0)), ((%3) /= (%0))
#define T3_RecoilFloat(%0,%1)					(((%0) >= 0.0)?((%0)+(%1)):((%0)-(%1)))
#define T3_CalculatePercent(%0,%1)				(((%0)/(%1))*100.0)

#define T3_GetActiveTime()						(GetTickCount()-Tryg3D::UpTime)
#define T3_GetVersion(%0)						((%0) / 10000),(((%0) % 10000) / 100),(((%0) % 10000) % 100)

#define T3_GetActiveCount()						GetSVarInt("ADM:3DTryg:ACTIVE")
#define T3_GetErrorCount()						GetSVarInt("ADM:3DTryg:Error")
#define T3_ResetErrorCount()					SetSVarInt("ADM:3DTryg:Error",0)
#define T3_UpdateErrorCount()					SetSVarInt("ADM:3DTryg:Error",Tryg3D::GetErrorCount()+1)

#define T3_SetStreamDistance(%0)				Tryg3D::StreamDistance = (%0)
#define T3_GetStreamDistance()					Tryg3D::StreamDistance
#define T3_RandomInteger(%0,%1)					(random((%1)-(%0)+1)+(%0))

#define T3_KeyPressed(%0)						(((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define T3_KeyReleased(%0)						(((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define T3_KeyHolding(%0)						((newkeys & (%0)) == (%0))

//%d:%02d:%02d:%02d
#define T3_SecToTimeDay(%0)						((%0) / 86400),(((%0) % 86400) / 3600),((((%0) % 86400) % 3600) / 60),((((%0) % 86400) % 3600) % 60)
#define T3_MSToTimeDay(%0)						Tryg3D::SecToTimeDay((%0)/1000)
//%02d:%02d:%02d
#define T3_SecToTime(%0)						((%0) / 3600),(((%0) % 3600) / 60),(((%0) % 3600) % 60)
#define T3_MSToTime(%0)							Tryg3D::SecToTime((%0)/1000)
//%02d:%02d
#define T3_SecToTimeMini(%0)					((%0) / 60),((%0) % 60)
#define T3_MSToTimeMini(%0)						Tryg3D::SecToTimeMini((%0)/1000)

//Author: hesambia random.inc, modified by Abyss Morgan
stock Float: Tryg3D::RandomFloat(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	if(min >= max) return 0.0;
	if(min < 0.0 || max < 0.0) return 0.0;
	if(accuracy < 1) accuracy = 1;
	if(accuracy > 6) accuracy = 6;
	new T3D:divValue = floatround(floatpower(10.0,accuracy)), T3D:prefix = floatround(max)-floatround(min), Float:T3D:rand_prefix = 0.0;
	if(T3D:prefix > 0) T3D:rand_prefix = 1.0 * random(T3D:prefix);
	return T3D:rand_prefix + min + (1.0*random(T3D:divValue)/(T3D:divValue*1.0));
}

stock Float: Tryg3D::RandomFloatEx(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	if(min >= max) return 0.0;
	return Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(min-max,2.0)),accuracy) - min;
}

stock Float: Tryg3D::CompressRotation(const Float:rotation){
	return (rotation-floatround(rotation/360.0,floatround_floor)*360.0);
}

stock Float: Tryg3D::DeCompressRotation(Float:rotation){
	rotation = Tryg3D::CompressRotation(rotation);
	if(rotation >= 180.0) rotation -= 360.0;
	return rotation;
}

stock Tryg3D::SwapInt(&variable1, &variable2){
	new T3D:tmp = variable2;
	variable2 = variable1;
	variable1 = T3D:tmp;
}

stock Tryg3D::SwapFloat(&Float:variable1, &Float:variable2){
	new Float: T3D:tmp = variable2;
	variable2 = variable1;
	variable1 = T3D:tmp;
}

stock Tryg3D::RecoilVector(&Float:vx, &Float:vy, &Float:vz, const Float:sx, const Float:sy, const Float:sz){
	vx = Tryg3D::RecoilFloat(vx,sx);
	vy = Tryg3D::RecoilFloat(vy,sy);
	vz = Tryg3D::RecoilFloat(vz,sz);
}

stock Tryg3D::NormalizeVector(&Float:x, &Float:y, &Float:z = 0.0){
	new Float:T3D:dist = VectorSize(x,y,z);
	if(T3D:dist <= 0.0) return 0.0;
	Tryg3D::DivideValues(T3D:dist,x,y,z);
	return T3D:dist;
}

/********************************
 * Quaternion Functions         *
 ********************************/
 
//Provided by Nero_3D
stock Tryg3D::EulerToQuat(Float:rx, Float:ry, Float:rz, &Float:qw, &Float:qx, &Float:qy, &Float:qz){
	Tryg3D::DivideValues(2.0,rx,ry,rz);
	new Float:cosX = floatcos(rx,degrees), Float:cosY = floatcos(ry,degrees), Float:cosZ = floatcos(rz,degrees), Float:sinX = floatsin(rx,degrees), Float:sinY = floatsin(ry,degrees), Float:sinZ = floatsin(rz,degrees);
	qw = Tryg3D::RoundAccuracy((sinX * sinY * sinZ - cosX * cosY * cosZ));
	qx = Tryg3D::RoundAccuracy((sinX * cosY * cosZ - cosX * sinY * sinZ));
	qy = Tryg3D::RoundAccuracy((cosX * sinY * cosZ + sinX * cosY * sinZ));
	qz = Tryg3D::RoundAccuracy((cosX * cosY * sinZ + sinX * sinY * cosZ));
}

stock Tryg3D::QuatToEuler(&Float:rx, &Float:ry, &Float:rz, Float:qw, Float:qx, Float:qy, Float:qz){
	qw = Tryg3D::RoundAccuracy(qw);
	qx = Tryg3D::RoundAccuracy(qx);
	qy = Tryg3D::RoundAccuracy(qy);
	qz = Tryg3D::RoundAccuracy(qz);
	rx = Tryg3D::CompressRotation(asin(2*qy*qz-2*qx*qw));
	ry = Tryg3D::CompressRotation(-atan2(qx*qz+qy*qw,0.5-qx*qx-qy*qy));
	rz = Tryg3D::CompressRotation(-atan2(qx*qy+qz*qw,0.5-qx*qx-qz*qz));
}

stock Tryg3D::GetRotationMatrixEuler(Float:matrix[][], const Float:rx, const Float:ry, const Float:rz){
	new Float:cosX = floatcos(rx,degrees), Float:cosY = floatcos(ry,degrees), Float:cosZ = floatcos(rz,degrees), Float:sinX = floatsin(rx,degrees), Float:sinY = floatsin(ry,degrees), Float:sinZ = floatsin(rz,degrees);
	matrix[0][0] = cosZ * cosY - sinZ * sinX * sinY;
	matrix[0][1] = -sinZ * cosX;
	matrix[0][2] = cosZ * sinY + sinZ * sinX * cosY;
	matrix[1][0] = sinZ * cosY + cosZ * sinX * sinY;
	matrix[1][1] = cosZ * cosX;
	matrix[1][2] = sinZ * sinY - cosZ * sinX * cosY;
	matrix[2][0] = -cosX * sinY;
	matrix[2][1] = sinX;
	matrix[2][2] = cosX * cosY;
}

stock Tryg3D::GetRotationMatrixEulerEx(Float:matrix[][], const Float:rx, const Float:ry, const Float:rz, const Tryg3D::EulerModes: mode = T3D:euler_default){
	new Float:cosX = floatcos(rx,degrees), Float:cosY = floatcos(ry,degrees), Float:cosZ = floatcos(rz,degrees), Float:sinX = floatsin(rx,degrees), Float:sinY = floatsin(ry,degrees), Float:sinZ = floatsin(rz,degrees);
	switch(mode){
		case T3D:euler_xzx: {
			matrix[0][0] = cosY;
			matrix[0][1] = -cosZ * sinY;
			matrix[0][2] = sinY * sinZ;
			matrix[1][0] = cosX * sinY;
			matrix[1][1] = cosX * cosY * cosZ - sinX * sinZ;
			matrix[1][2] = -cosZ * sinX - cosX * cosY * sinZ;
			matrix[2][0] = sinX * sinY;
			matrix[2][1] = cosX * sinZ + cosY * cosZ * sinX;
			matrix[2][2] = cosX * cosZ - cosY * sinX * sinZ;
		}
		case T3D:euler_xyx: {
			matrix[0][0] = cosY;
			matrix[0][1] = sinY * sinZ;
			matrix[0][2] = cosZ * sinY;
			matrix[1][0] = sinX * sinY;
			matrix[1][1] = cosX * cosZ - cosY * sinX * sinZ;
			matrix[1][2] = -cosX * sinZ - cosY * cosZ * sinX;
			matrix[2][0] = -cosX * sinY;
			matrix[2][1] = cosZ * sinX + cosX * cosY * sinZ;
			matrix[2][2] = cosX * cosY * cosZ - sinX * sinZ;
		}
		case T3D:euler_yxy: {
			matrix[0][0] = cosX * cosZ - cosY * sinX * sinZ;
			matrix[0][1] = sinX * sinY;
			matrix[0][2] = cosX * sinZ + cosY * cosZ * sinX;
			matrix[1][0] = sinY * sinZ;
			matrix[1][1] = cosY;
			matrix[1][2] = -cosZ * sinY;
			matrix[2][0] = -cosZ * sinX - cosX * cosY * sinZ;
			matrix[2][1] = cosX * sinY;
			matrix[2][2] = cosX * cosY * cosZ - sinX * sinZ;
		}
		case T3D:euler_yzy: {
			matrix[0][0] = cosX * cosY * cosZ - sinX * sinZ;
			matrix[0][1] = -cosX * sinY;
			matrix[0][2] = cosZ * sinX + cosX * cosY * sinZ;
			matrix[1][0] = cosZ * sinY;
			matrix[1][1] = cosY;
			matrix[1][2] = sinY * sinZ;
			matrix[2][0] = -cosX * sinZ - cosY * cosZ * sinX;
			matrix[2][1] = sinX * sinY;
			matrix[2][2] = cosX * cosZ - cosY * sinX * sinZ;
		}
		case T3D:euler_zyz: {
			matrix[0][0] = cosX * cosY * cosZ - sinX * sinZ;
			matrix[0][1] = -cosZ * sinX - cosX * cosY * sinZ;
			matrix[0][2] = cosX * sinY;
			matrix[1][0] = cosX * sinZ + cosY * cosZ * sinX;
			matrix[1][1] = cosX * cosZ - cosY * sinX * sinZ;
			matrix[1][2] = sinX * sinY;
			matrix[2][0] = -cosZ * sinY;
			matrix[2][1] = sinY * sinZ;
			matrix[2][2] = cosY;
		}
		case T3D:euler_zxz: {
			matrix[0][0] = cosX * cosZ - cosY * sinX * sinZ;
			matrix[0][1] = -cosX * sinZ - cosY * cosZ * sinX;
			matrix[0][2] = sinX * sinY;
			matrix[1][0] = cosZ * sinX + cosX * cosY * sinZ;
			matrix[1][1] = cosX * cosY * cosZ - sinX * sinZ;
			matrix[1][2] = -cosX * sinY;
			matrix[2][0] = sinY * sinZ;
			matrix[2][1] = cosZ * sinY;
			matrix[2][2] = cosY;
		}
		case T3D:euler_xzy: {
			matrix[0][0] = cosZ * cosY;
			matrix[0][1] = -sinZ;
			matrix[0][2] = cosZ * sinY;
			matrix[1][0] = sinX * sinY + cosX * cosY * sinZ;
			matrix[1][1] = cosX * cosZ;
			matrix[1][2] = cosX * sinZ * sinY - cosY * sinX;
			matrix[2][0] = cosY * sinX * sinZ - cosX * sinY;
			matrix[2][1] = cosZ * sinX;
			matrix[2][2] = cosX * cosY + sinX * sinZ * sinY;
		}
		case T3D:euler_xyz: {
			matrix[0][0] = cosY * cosZ;
			matrix[0][1] = -cosY * sinZ;
			matrix[0][2] = sinY;
			matrix[1][0] = cosX * sinZ + cosZ * sinX * sinY;
			matrix[1][1] = cosX * cosZ - sinX * sinY * sinZ;
			matrix[1][2] = -cosY * sinX;
			matrix[2][0] = sinX * sinZ - cosX * cosZ * sinY;
			matrix[2][1] = cosZ * sinX + cosX * sinY * sinZ;
			matrix[2][2] = cosX * cosY;
		}
		case T3D:euler_yxz: {
			matrix[0][0] = cosY * cosZ + sinY * sinX * sinZ;
			matrix[0][1] = cosZ * sinY * sinX - cosY * sinZ;
			matrix[0][2] = cosX * sinY;
			matrix[1][0] = cosX * sinZ;
			matrix[1][1] = cosX * cosZ;
			matrix[1][2] = -sinX;
			matrix[2][0] = cosY * sinX * sinZ - cosZ * sinY;
			matrix[2][1] = cosY * cosZ * sinX + sinY * sinZ;
			matrix[2][2] = cosY * cosX;
		}
		case T3D:euler_yzx: {
			matrix[0][0] = cosY * cosZ;
			matrix[0][1] = sinY * sinX - cosY * cosX * sinZ;
			matrix[0][2] = cosX * sinY + cosY * sinZ * sinX;
			matrix[1][0] = sinZ;
			matrix[1][1] = cosZ * cosX;
			matrix[1][2] = -cosZ * sinX;
			matrix[2][0] = -cosZ * sinY;
			matrix[2][1] = cosY * sinX + cosX * sinY * sinZ;
			matrix[2][2] = cosY * cosX - sinY * sinZ * sinX;
		}
		case T3D:euler_zyx: {
			matrix[0][0] = cosZ * cosY;
			matrix[0][1] = cosZ * sinY * sinX - cosX * sinZ;
			matrix[0][2] = sinZ * sinX + cosZ * cosX * sinY;
			matrix[1][0] = cosY * sinZ;
			matrix[1][1] = cosZ * cosX + sinZ * sinY * sinX;
			matrix[1][2] = cosX * sinZ * sinY - cosZ * sinX;
			matrix[2][0] = -sinY;
			matrix[2][1] = cosY * sinX;
			matrix[2][2] = cosY * cosX;
		}
		case T3D:euler_zxy: {
			matrix[0][0] = cosZ * cosY - sinZ * sinX * sinY;
			matrix[0][1] = -sinZ * cosX;
			matrix[0][2] = cosZ * sinY + sinZ * sinX * cosY;
			matrix[1][0] = sinZ * cosY + cosZ * sinX * sinY;
			matrix[1][1] = cosZ * cosX;
			matrix[1][2] = sinZ * sinY - cosZ * sinX * cosY;
			matrix[2][0] = -cosX * sinY;
			matrix[2][1] = sinX;
			matrix[2][2] = cosX * cosY;
		}
	}
}

stock Tryg3D::MatrixRotate(const Float:matrix[][], const Float:oX, const Float:oY, const Float:oZ, &Float:x, &Float:y, &Float:z){
	x += oX * matrix[0][0] + oY * matrix[0][1] + oZ * matrix[0][2];
	y += oX * matrix[1][0] + oY * matrix[1][1] + oZ * matrix[1][2];
	z += oX * matrix[2][0] + oY * matrix[2][1] + oZ * matrix[2][2];
}

stock Tryg3D::GetQuatFromEuler(Float:rx, Float:ry, Float:rz, &Float:qw, &Float:qx, &Float:qy, &Float:qz, Tryg3D::EulerModes: mode = T3D:euler_default){
	Tryg3D::DivideValues(2.0,rx,ry,rz);
	new	Float:cosX = floatcos(rx,degrees), Float:cosY = floatcos(ry,degrees), Float:cosZ = floatcos(rz,degrees), Float:sinX = floatsin(rx,degrees), Float:sinY = floatsin(ry,degrees), Float:sinZ = floatsin(rz,degrees);
	switch(mode) {
		case T3D:euler_xzx: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = cosX * cosY * sinZ + sinX * cosY * cosZ;
			qy = cosX * sinY * sinZ - sinX * sinY * cosZ;
			qz = cosX * sinY * cosZ + sinX * sinY * sinZ;
		}
		case T3D:euler_xyx: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = cosX * cosY * sinZ + sinX * cosY * cosZ;
			qy = cosX * sinY * cosZ + sinX * sinY * sinZ;
			qz = sinX * sinY * cosZ - cosX * sinY * sinZ;
		}
		case T3D:euler_yxy: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = cosX * sinY * cosZ + sinX * sinY * sinZ;
			qy = cosX * cosY * sinZ + sinX * cosY * cosZ;
			qz = cosX * sinY * sinZ - sinX * sinY * cosZ;
		}
		case T3D:euler_yzy: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = sinX * sinY * cosZ - cosX * sinY * sinZ;
			qy = cosX * cosY * sinZ + sinX * cosY * cosZ;
			qz = cosX * sinY * cosZ + sinX * sinY * sinZ;
		}
		case T3D:euler_zyz: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = cosX * sinY * sinZ - sinX * sinY * cosZ;
			qy = cosX * sinY * cosZ + sinX * sinY * sinZ;
			qz = cosX * cosY * sinZ + sinX * cosY * cosZ;
		}
		case T3D:euler_zxz: {
			qw = sinX * cosY * sinZ - cosX * cosY * cosZ;
			qx = cosX * sinY * cosZ + sinX * sinY * sinZ;
			qy = sinX * sinY * cosZ - cosX * sinY * sinZ;
			qz = cosX * cosY * sinZ + sinX * cosY * cosZ;
		}
		case T3D:euler_xzy: {
			qw = cosX * cosY * cosZ + sinX * sinY * sinZ;
			qx = cosX * sinY * sinZ - sinX * cosY * cosZ;
			qy = sinX * cosY * sinZ - cosX * sinY * cosZ;
			qz = -(cosX * cosY * sinZ + sinX * sinY * cosZ);
		}
		case T3D:euler_xyz: {
			qw = sinX * sinY * sinZ - cosX * cosY * cosZ;
			qx = sinX * cosY * cosZ + cosX * sinY * sinZ;
			qy = cosX * sinY * cosZ - sinX * cosY * sinZ;
			qz = cosX * cosY * sinZ + sinX * sinY * cosZ;
		}
		case T3D:euler_yxz: {
			qw = cosX * cosY * cosZ + sinX * sinY * sinZ;
			qx = -(sinX * cosY * cosZ + cosX * sinY * sinZ);
			qy = sinX * cosY * sinZ - cosX * sinY * cosZ;
			qz = sinX * sinY * cosZ - cosX * cosY * sinZ;
		}
		case T3D:euler_yzx: {
			qw = sinX * sinY * sinZ - cosX * cosY * cosZ;
			qx = sinX * cosY * cosZ + cosX * sinY * sinZ;
			qy = cosX * sinY * cosZ + sinX * cosY * sinZ;
			qz = cosX * cosY * sinZ - sinX * sinY * cosZ;
		}
		case T3D:euler_zyx: {
			qw = cosX * cosY * cosZ + sinX * sinY * sinZ;
			qx = cosX * sinY * sinZ - sinX * cosY * cosZ;
			qy = -(cosX * sinY * cosZ + sinX * cosY * sinZ);
			qz = sinX * sinY * cosZ - cosX * cosY * sinZ;
		}
		case T3D:euler_zxy: {
			qw = sinX * sinY * sinZ - cosX * cosY * cosZ;
			qx = sinX * cosY * cosZ - cosX * sinY * sinZ;
			qy = cosX * sinY * cosZ + sinX * cosY * sinZ;
			qz = cosX * cosY * sinZ + sinX * sinY * cosZ;
		}
	}
}

stock Tryg3D::QuatRotate(const Float:qw, const Float:qx, const Float:qy, const Float:qz, const Float:oX, const Float:oY, const Float:oZ, &Float:tx, &Float:ty, &Float:tz){
	new Float:dot = qx * oX + qy * oY + qz * oZ, Float:abs = qw * qw - 0.5;
	tx += 2.0 * (dot * qx + abs * oX + qw * (qz * oY - qy * oZ));
	ty += 2.0 * (dot * qy + abs * oY + qw * (qx * oZ - qz * oX));
	tz += 2.0 * (dot * qz + abs * oZ + qw * (qy * oX - qx * oY));
}

stock Tryg3D::EulerRotate(Float:rx, Float:ry, Float:rz, Float:oX, Float:oY, Float:oZ, &Float:tx,&Float:ty,&Float:tz){
	new Float:qw;
	Tryg3D::EulerToQuat(rx,ry,rz,qw,rx,ry,rz);
	Tryg3D::QuatRotate(qw,rx,ry,rz,oX,oY,oZ,tx,ty,tz);
}

stock Tryg3D::EulerRotateEx(Float:rx, Float:ry, Float:rz, Float:oX, Float:oY, Float:oZ, &Float:tx, &Float:ty, &Float:tz, Tryg3D::EulerModes: mode = T3D:euler_default){
	Tryg3D::GetQuatFromEuler(rx,ry,rz,Float:mode,rx,ry,rz,mode);
	Tryg3D::QuatRotate(Float:mode,rx,ry,rz,oX,oY,oZ,tx,ty,tz);
}

stock Tryg3D::GetQuatUpVector(const Float:qw, const Float:qx, const Float:qy, const Float:qz, &Float:vx, &Float:vy, &Float:vz){
	vx = 2.0*(qy*qw+qz*qx);
	vy = 2.0*(qz*qy-qx*qw);
	vz = 1.0-(2.0*(qx*qx+qy*qy));
}

/********************************
 * General Functions            *
 ********************************/

stock Float: Tryg3D::GetDistance1D(const Float:x1, const Float:x2){
	return VectorSize(x1-x2,0.0,0.0);
}

stock Float: Tryg3D::GetDistance2D(const Float:x1, const Float:y1, const Float:x2, const Float:y2){
	return VectorSize(x1-x2,y1-y2,0.0);
}

stock Float: Tryg3D::GetDistance3D(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2){
	return VectorSize(x1-x2,y1-y2,z1-z2);
}

stock bool: Tryg3D::IsPolygonClosed(const Float:points[], maxpoints = sizeof(points)){
	if(maxpoints % 2 == 1 || maxpoints < 6) return false;
	if(points[0] == points[maxpoints-2] && points[1] == points[maxpoints-1]) return true;
	return false;
}

stock bool: Tryg3D::IsValidPolygon(const Float:points[], maxpoints = sizeof(points)){
	if(maxpoints % 2 == 1) return false;
	if(Tryg3D::IsPolygonClosed(points,maxpoints)){
		if(maxpoints < 8) return false;
	} else {
		if(maxpoints < 6) return false;
	}
	return true;
}

stock Tryg3D::GetOrientation(const Float:angle){
	angle = Tryg3D::CompressRotation(angle+22.5);
	if(0.0 <= angle < 45.0){
		return o_front;
	} else if(45.0 <= angle < 90.0){
		return o_front_left;
	} else if(90.0 <= angle < 135.0){
		return o_left;
	} else if(135.0 <= angle < 180.0){
		return o_back_left;
	} else if(180.0 <= angle < 225.0){
		return o_back;
	} else if(225.0 <= angle < 270.0){
		return o_back_right;
	} else if(270.0 <= angle < 315.0){
		return o_right;
	} else if(315.0 <= angle < 360.0){
		return o_front_right;
	}
	return TRYG3D_INVALID_ORIENTATION;
}

stock bool: Tryg3D::GetOrientationName(orientation_name[], const Float:angle, bool:as_compass = false, maxdest = sizeof(orientation_name)){
	new orientation = Tryg3D::GetOrientation(angle);
	if(orientation == TRYG3D_INVALID_ORIENTATION){
		format(orientation_name,maxdest,"Unknown");
		return false;
	}
	if(as_compass){
		format(orientation_name,maxdest,"%s",Tryg3D::OrientationCompass[orientation]);
	} else {
		format(orientation_name,maxdest,"%s",Tryg3D::OrientationNames[orientation]);
	}
	return true;
}

stock Float: Tryg3D::GetEllipseRadius(const Float:x, const Float:y, const Float:angle){
	if(x <= 0.0) return -1.0;
	new Float:theta = atan((y/x)*floattan(Tryg3D::CompressRotation(angle),degrees));
	return floatsqroot((floatpower(x,2.0)*floatpower(floatsin(theta,degrees),2.0))+(floatpower(y,2.0)*floatpower(floatcos(theta,degrees),2.0)));
}

stock Float: Tryg3D::GetLineSize2D(const Float:points[][2], maxpoints = sizeof(points)){
	if(maxpoints < 2) return 0.0;
	new Float:T3D:distance = 0.0;
	for(new i = 1; i < maxpoints; i++){
		T3D:distance += Tryg3D::GetDistance2D(points[i-1][0],points[i-1][1],points[i][0],points[i][1]);
	}
	return T3D:distance;
}

stock Float: Tryg3D::GetLineSize3D(const Float:points[][3], maxpoints = sizeof(points)){
	if(maxpoints < 2) return 0.0;
	new Float:T3D:distance = 0.0;
	for(new i = 1; i < maxpoints; i++){
		T3D:distance += Tryg3D::GetDistance3D(points[i-1][0],points[i-1][1],points[i-1][2],points[i][0],points[i][1],points[i][2]);
	}
	return T3D:distance;
}

//Made by Zoutdaxv
stock Tryg3D::GetRotationFor2Point2D(const Float:x, const Float:y, const Float:tx, const Float:ty, &Float:rz){
	rz = Tryg3D::CompressRotation(atan2(ty-y,tx-x)-90.0);
}

//Made by Abyss Morgan, Updated by Nero_3D
stock Tryg3D::GetPointInFront2D(const Float:x, const Float:y, const Float:rz, const Float:radius, &Float:tx, &Float:ty){
	tx = x - (radius * floatsin(rz,degrees));
	ty = y + (radius * floatcos(rz,degrees));
}

//Made by Abyss Morgan, Updated by Nero_3D
stock Tryg3D::GetPointInFront3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	tx = x - (radius * floatcos(rx,degrees) * floatsin(rz,degrees));
	ty = y + (radius * floatcos(rx,degrees) * floatcos(rz,degrees));
	tz = z + (radius * floatsin(rx,degrees));
}

stock Tryg3D::GetRotationFor2Point3D(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, &Float:rx, &Float:rz){
	new Float:radius = Tryg3D::GetDistance3D(x,y,z,tx,ty,tz);
	if(radius <= 0.0) return 0;
	rx = Tryg3D::CompressRotation(-(acos((tz-z)/radius)-90.0));
	rz = Tryg3D::CompressRotation(atan2(ty-y,tx-x)-90.0);
	return 1;
}

stock Tryg3D::GetPointInFront3DEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	new Float:vx,Float:vy,Float:vz,Float:trx,Float:trz;
	Tryg3D::EulerRotate(rx,ry,rz,0.0,1.0,0.0,vx,vy,vz);
	Tryg3D::GetRotationFor2Point3D(0.0,0.0,0.0,vx,vy,vz,trx,trz);
	Tryg3D::GetPointInFront3D(x,y,z,trx,trz,radius,tx,ty,tz);
}

stock Tryg3D::GetPointFor2Point2D(const Float:x1, const Float:y1, const Float:x2, const Float:y2, const Float:percent_size, &Float:tx, &Float:ty){
	new Float:rz;
	Tryg3D::GetRotationFor2Point2D(x1,y1,x2,y2,rz);
	Tryg3D::GetPointInFront2D(x1,y1,rz,(Tryg3D::GetDistance2D(x1,y1,x2,y2)*(percent_size/100.0)),tx,ty);
}

stock Tryg3D::GetPointFor2Point3D(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2, const Float:percent_size, &Float:tx, &Float:ty, &Float:tz){
	new Float:rx,Float:rz;
	Tryg3D::GetRotationFor2Point3D(x1,y1,z1,x2,y2,z2,rx,rz);
	Tryg3D::GetPointInFront3D(x1,y1,z1,rx,rz,(Tryg3D::GetDistance3D(x1,y1,z1,x2,y2,z2)*(percent_size/100.0)),tx,ty,tz);
}

stock Tryg3D::GetPointFor2Point2DEx(const Float:x1, const Float:y1, const Float:x2, const Float:y2, const Float:distance, &Float:tx, &Float:ty){
	new Float:rz;
	Tryg3D::GetRotationFor2Point2D(x1,y1,x2,y2,rz);
	Tryg3D::GetPointInFront2D(x1,y1,rz,distance,tx,ty);
}

stock Tryg3D::GetPointFor2Point3DEx(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2, const Float:distance, &Float:tx, &Float:ty, &Float:tz){
	new Float:rx,Float:rz;
	Tryg3D::GetRotationFor2Point3D(x1,y1,z1,x2,y2,z2,rx,rz);
	Tryg3D::GetPointInFront3D(x1,y1,z1,rx,rz,distance,tx,ty,tz);
}

//Made by Crayder
stock Float: Tryg3D::GetDistancePointToLine(const Float:px, const Float:py, const Float:pz, const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:iX = 0.0, &Float:iY = 0.0, &Float:iZ = 0.0){
	new Float:T3D:dist = Tryg3D::GetDistance3D(eX,eY,eZ,sX,sY,sZ);
	if(T3D:dist <= 0.0) return -1.0;
	new Float:T3D:U = (((px - sX) * (eX - sX)) + ((py - sY) * (eY - sY)) + ((pz - sZ) * (eZ - sZ))) / (T3D:dist*T3D:dist);
	if(T3D:U < 0.0 || T3D:U > 1.0) return -1.0;
	iX = sX + T3D:U * (eX - sX);
	iY = sY + T3D:U * (eY - sY);
	iZ = sZ + T3D:U * (eZ - sZ);
	return Tryg3D::GetDistance3D(iX,iY,iZ,px,py,pz);
}

//Made by $continue$, Nero_3D
stock Float: Tryg3D::GetDistancePointToLineEx(const Float:px, const Float:py, const Float:pz, const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:iX = 0.0, &Float:iY = 0.0, &Float:iZ = 0.0){
	new Float:T3D:v1x = eX - sX, Float:T3D:v1y = eY - sY, Float:T3D:v1z = eZ - sZ, Float:T3D:v2x = px - sX, Float:T3D:v2y = py - sY, Float:T3D:v2z = pz - sZ, Float:T3D:dist = VectorSize(T3D:v1x,T3D:v1y,T3D:v1z);
	if(T3D:dist <= 0.0) return -1.0;
	new Float:T3D:U = ((T3D:v2x * T3D:v1x) + (T3D:v2y * T3D:v1y) + (T3D:v2z * T3D:v1z)) / (T3D:dist * T3D:dist);
	if(T3D:U < 0.0){
		iX = sX;
		iY = sY;
		iZ = sZ;
		return VectorSize(T3D:v2x,T3D:v2y,T3D:v2z);
	} else if(T3D:U > 1.0){
		iX = eX;
		iY = eY;
		iZ = eZ;
		return VectorSize(eX-px,eY-py,eZ-pz);
	} else {
		T3D:dist *= T3D:U;
		iX = sX + (T3D:v1x * T3D:U);
		iY = sY + (T3D:v1y * T3D:U);
		iZ = sZ + (T3D:v1z * T3D:U);
		return floatsqroot(((T3D:v2x * T3D:v2x) + (T3D:v2y * T3D:v2y) + (T3D:v2z * T3D:v2z)) - (T3D:dist*T3D:dist));
	}
}

//Made by $continue$
stock Tryg3D::GetNearest2DPointOnPolygon(const Float:polygon_points[], const Float:x, const Float:y, &Float:tx, &Float:ty, maxpoints = sizeof(polygon_points)){
	if(!Tryg3D::IsValidPolygon(polygon_points,maxpoints)) return 0;
	new Float:T3D:dist,Float:T3D:min_dist,Float:T3D:pX,Float:T3D:pY,Float:T3D:pZ,Float:T3D:sX,Float:T3D:sY,Float:T3D:eX = polygon_points[0],Float:T3D:eY = polygon_points[1];
	T3D:min_dist = cellmax;
	for(new i = 2; i < maxpoints; i += 2){
		T3D:sX = T3D:eX;
		T3D:sY = T3D:eY;
		T3D:eX = polygon_points[i];
		T3D:eY = polygon_points[i+1];
		T3D:dist = Tryg3D::GetDistancePointToLineEx(x,y,0.0,T3D:sX,T3D:sY,0.0,T3D:eX,T3D:eY,0.0,T3D:pX,T3D:pY,T3D:pZ);
		if(T3D:dist < T3D:min_dist && T3D:dist >= 0.0){
			T3D:min_dist = T3D:dist;
			tx = T3D:pX;
			ty = T3D:pY;
		}
	}
	if(!Tryg3D::IsPolygonClosed(polygon_points,maxpoints)){
		T3D:sX = T3D:eX;
		T3D:sY = T3D:eY;
		T3D:eX = polygon_points[0];
		T3D:eY = polygon_points[1];
		T3D:dist = Tryg3D::GetDistancePointToLineEx(x,y,0.0,T3D:sX,T3D:sY,0.0,T3D:eX,T3D:eY,0.0,T3D:pX,T3D:pY,T3D:pZ);
		if(T3D:dist < T3D:min_dist && T3D:dist >= 0.0){
			T3D:min_dist = T3D:dist;
			tx = T3D:pX;
			ty = T3D:pY;
		}
	}
	#pragma unused v3DpZ
	return 1;
}

stock Float: Tryg3D::GetLineCosTheta2D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]){
	new Float:LineSize1 = Tryg3D::GetDistance2D(StartLine1[0],StartLine1[1],EndLine1[0],EndLine1[1]), Float:LineSize2 = Tryg3D::GetDistance2D(StartLine2[0],StartLine2[1],EndLine2[0],EndLine2[1]);
	return floatabs(((StartLine1[0]-EndLine1[0])/LineSize1)*((StartLine2[0]-EndLine2[0])/LineSize2)+((StartLine1[1]-EndLine1[1])/LineSize1)*((StartLine2[1]-EndLine2[1])/LineSize2);
}

stock Float: Tryg3D::GetLineCosTheta3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]){
	new Float:LineSize1 = Tryg3D::GetDistance3D(StartLine1[0],StartLine1[1],StartLine1[2],EndLine1[0],EndLine1[1],EndLine1[2]), Float:LineSize2 = Tryg3D::GetDistance3D(StartLine2[0],StartLine2[1],StartLine2[2],EndLine2[0],EndLine2[1],EndLine2[2]);
	return floatabs(((StartLine1[0]-EndLine1[0])/LineSize1)*((StartLine2[0]-EndLine2[0])/LineSize2)+((StartLine1[1]-EndLine1[1])/LineSize1)*((StartLine2[1]-EndLine2[1])/LineSize2)+((StartLine1[2]-EndLine1[2])/LineSize1)*((StartLine2[2]-EndLine2[2])/LineSize2));
}

stock bool: Tryg3D::IsLinesParallel2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]){
	return Tryg3D::GetLineCosTheta2D(StartLine1,EndLine1,StartLine2,EndLine2) == 1.0;
}

stock bool: Tryg3D::IsLinesParallel3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]){
    return Tryg3D::GetLineCosTheta3D(StartLine1,EndLine1,StartLine2,EndLine2) == 1.0;
}

stock bool: Tryg3D::IsLinesPerpendicular2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]){
	return Tryg3D::GetLineCosTheta2D(StartLine1,EndLine1,StartLine2,EndLine2) == 0.0;
}

stock bool: Tryg3D::IsLinesPerpendicular3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]){
    return Tryg3D::GetLineCosTheta3D(StartLine1,EndLine1,StartLine2,EndLine2) == 0.0;
}

stock bool: Tryg3D::IsPointBetween2Points2D(const Float:px, const Float:py, const Float:x1, const Float:y1, const Float:x2, const Float:y2){
	new Float:StartLine1[2], Float:EndLine1[2], Float:StartLine2[2], Float:EndLine2[2];
	Tryg3D::AppendLineArguments2D(StartLine1,x1,y1);
	Tryg3D::AppendLineArguments2D(EndLine1,px,py);
	Tryg3D::AppendLineArguments2D(StartLine2,px,py);
	Tryg3D::AppendLineArguments2D(EndLine2,x2,y2);
	return (Tryg3D::GetDistance2D(x1,y1,x2,y2) == (Tryg3D::GetDistance2D(x1,y1,px,py) + Tryg3D::GetDistance2D(x2,y2,px,py)) && Tryg3D::IsLinesParallel2D(StartLine1,EndLine1,StartLine2,EndLine2));
}

stock bool: Tryg3D::IsPointBetween2Points3D(const Float:px, const Float:py, const Float:pz, const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2){
	new Float:StartLine1[3], Float:EndLine1[3], Float:StartLine2[3], Float:EndLine2[3];
	Tryg3D::AppendLineArguments3D(StartLine1,x1,y1,z1);
	Tryg3D::AppendLineArguments3D(EndLine1,px,py,pz);
	Tryg3D::AppendLineArguments3D(StartLine2,px,py,pz);
	Tryg3D::AppendLineArguments3D(EndLine2,x2,y2,z2);
	return (Tryg3D::GetDistance3D(x1,y1,z1,x2,y2,z2) == (Tryg3D::GetDistance3D(x1,y1,z1,px,py,pz) + Tryg3D::GetDistance3D(x2,y2,z2,px,py,pz)) && Tryg3D::IsLinesParallel3D(StartLine1,EndLine1,StartLine2,EndLine2));
}

stock Tryg3D::GetGangZone(const Float:x, const Float:y, const Float:radius, &Float:minx, &Float:miny, &Float:maxx, &Float:maxy){
	minx = x - radius;
	miny = y - radius;
	maxx = x + radius;
	maxy = y + radius;
}

stock bool: Tryg3D::IsProbable(Float:chance, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
    if(chance <= 0.0) return false;
    if(chance >= 100.0) return true;
    return Tryg3D::RandomFloat(0.0,100.0,accuracy) <= chance;
}

stock Tryg3D::RandomItemFromArray(const items[][2], max_items = sizeof(items), accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	new Float:T3D:RNG = Tryg3D::RandomFloat(0.0,100.0,accuracy), Float:T3D:LootState = 0.0;
	for(new i = 0; i < max_items; i++){
		if(T3D:LootState <= T3D:RNG <= (T3D:LootState+items[i][1])){
			return items[i][0];
		} else {
			T3D:LootState += items[i][1];
		}
	}
	return -1;
}

/********************************
 * Converter Functions          *
 ********************************/

stock Float: Tryg3D::ShiftDegreeToRadian(const Float:value){
	return (value*((FLOAT_PI*2)/360.0));
}

stock Float: Tryg3D::ShiftDegreeToRadianEx(const Float:value){
	return ((360.0-Tryg3D::CompressRotation(value))*(-((FLOAT_PI*2)/360.0)));
}

stock Float: Tryg3D::ShiftDegreeToGrades(const Float:value){
	return (value*(10.0/9.0));
}

stock Float: Tryg3D::ShiftRadianToDegree(const Float:value){
	return (value/((FLOAT_PI*2)/360.0));
}

stock Float: Tryg3D::ShiftRadianToDegreeEx(const Float:value){
	return Tryg3D::CompressRotation(floatabs((value/((FLOAT_PI*2)/360.0))+360.0))
}

stock Float: Tryg3D::ShiftRadianToGrades(const Float:value){
	return Tryg3D::ShiftDegreeToGrades(Tryg3D::ShiftRadianToDegree(value))
}

stock Float: Tryg3D::ShiftGradesToDegree(const Float:value){
	return value*0.9;
}

stock Float: Tryg3D::ShiftGradesToRadian(const Float:value){
	return Tryg3D::ShiftDegreeToRadian(Tryg3D::ShiftGradesToDegree(value));
}

stock Tryg3D::ShiftRotationToVector(const Float:rx, const Float:rz, const Float:vx, const Float:vy, const Float:vz){
	return Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,1.0,vx,vy,vz);
}

stock Tryg3D::ShiftVectorToRotation(const Float:vx, const Float:vy, const Float:vz, &Float:rx, &Float:rz){
	rx = Tryg3D::CompressRotation(-(acos(vz)-90.0));
	rz = Tryg3D::CompressRotation((atan2(vy,vx)-90.0));
}

stock bool: Tryg3D::ShiftVectorRotation(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:tx, &Float:ty, &Float:tz){
	new Float:T3D:dist = VectorSize(x,y,z);
	if(T3D:dist <= 0.0){
		tx = x, ty = y, tz = z;
		return false;
	}
	new Float:T3D:matrix[3][3];
	Tryg3D::GetRotationMatrixEuler(T3D:matrix,rx,ry,rz);
	Tryg3D::MatrixRotate(T3D:matrix,(x/T3D:dist),(y/T3D:dist),(z/T3D:dist),tx,ty,tz);
	return true;
}

stock Tryg3D::ShiftOffsetToPosition(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:offset_x, const Float:offset_y, const Float:offset_z, &Float:tx, &Float:ty, &Float:tz){
	new Float:px,Float:py,Float:pz;
	if(!Tryg3D::ShiftVectorRotation(offset_x,offset_y,offset_z,rx,ry,rz,px,py,pz)){
		tx = x, ty = y, tz = z;
	} else {
		Tryg3D::GetRotationFor2Point3D(0.0,0.0,0.0,px,py,pz,rx,rz);
		Tryg3D::GetPointInFront3D(x,y,z,rx,rz,VectorSize(offset_x,offset_y,offset_z),tx,ty,tz);
	}
}

stock Tryg3D::ShiftPositionToOffset(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:offset_x, &Float:offset_y, &Float:offset_z, const Float:tx, const Float:ty, const Float:tz){
	new Float:px,Float:py,Float:pz,Float:trx,Float:trz,Float:T3D:dist = Tryg3D::GetDistance3D(x,y,z,tx,ty,tz);
	if(!Tryg3D::GetRotationFor2Point3D(x,y,z,tx,ty,tz,trx,trz)){
		offset_x = x, offset_y = y, offset_z = z;
	} else {
		new Float:ex,Float:ey,Float:ez;
		Tryg3D::GetPointInFront3D(0.0,0.0,0.0,trx,trz,1.0,px,py,pz);
		Tryg3D::ShiftVectorRotation(px,py,pz,Tryg3D::CompressRotation(-rx),Tryg3D::CompressRotation(-ry),Tryg3D::CompressRotation(-rz),ex,ey,ez);
		Tryg3D::GetPointFor2Point3DEx(0.0,0.0,0.0,ex,ey,ez,T3D:dist,offset_x,offset_y,offset_z);
	}
}

//Made by Crayder
stock Tryg3D::ShiftLineRotation(const Float:sX, const Float:sY, const Float:sZ, Float:eX, Float:eY, Float:eZ, const Float:rx, const Float:ry, const Float:rz, &Float:nX, &Float:nY, &Float:nZ){
	eX -= sX, eY -= sY, eZ -= sZ;
	new Float:T3D:matrix[3][3];
	Tryg3D::GetRotationMatrixEuler(T3D:matrix,rx,ry,rz);
	Tryg3D::MatrixRotate(T3D:matrix,eX,eY,eZ,nX,nY,nZ);
}

//Made by Crayder
stock bool: Tryg3D::ShiftLineRotationVector(const Float:sX, const Float:sY, const Float:sZ, Float:eX, Float:eY, Float:eZ, const Float:rx, const Float:ry, const Float:rz, &Float:nX, &Float:nY, &Float:nZ){
	eX -= sX, eY -= sY, eZ -= sZ;
	new Float:T3D:dist = VectorSize(eX,eY,eZ);
	if(T3D:dist <= 0.0){
		nX = eX, nY = eY, nZ = eZ;
		return false;
	}
	new Float:T3D:matrix[3][3];
	Tryg3D::GetRotationMatrixEuler(T3D:matrix,rx,ry,rz);
	Tryg3D::MatrixRotate(T3D:matrix,(eX/T3D:dist),(eY/T3D:dist),(eZ/T3D:dist),nX,nY,nZ);
	return true;
}

stock Tryg3D::ShiftSpeedToMoveTime(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const Float:speed){
	if(speed <= 0.0){
		return TRYG3D_INVALID_MOVE_TIME;
	} else {
		return floatround((Tryg3D::GetDistance3D(x,y,z,tx,ty,tz)/speed)*1000.0);
	}
}

stock Tryg3D::ShiftMoveTimeToSpeed(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const movement_time){
	if(movement_time/1000.0 <= 0.0){
		return = TRYG3D_INVALID_MOVE_SPEED;
	} else {
		return = (Tryg3D::GetDistance3D(x,y,z,tx,ty,tz)/(movement_time/1000.0));
	}
}

/********************************
 * Extended Functions           *
 ********************************/

stock bool: Tryg3D::IsPointToPointVector(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz){
	new Float:rx,Float:rz;
	if(Tryg3D::GetRotationFor2Point3D(x,y,z,tx,ty,tz,rx,rz)){
		Tryg3D::ShiftRotationToVector(rx,rz,vx,vy,vz);
		return true;
	} else {
		vx = vy = vz = 0.0;
		return false;
	}
}

stock Tryg3D::GetArcPoints3D(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const Float:ry, const Float:height, Float:points[][3], max_points = sizeof(points)){
	if(max_points < 3) return 0;
	if(height <= 0.0) return 0;
	new Float:rx,Float:rz;
	if(!Tryg3D::GetRotationFor2Point3D(x,y,z,tx,ty,tz,rx,rz)) return 0;
	ry = Tryg3D::CompressRotation(ry);
	new Float:px, Float:py, Float:pz, Float:cx, Float:cy, Float:cz, Float:center_dist = (Tryg3D::GetDistance3D(x,y,z,tx,ty,tz)/2.0), Float:mercury = (180.0/max_points), Float:omega, idx = 0;
	Tryg3D::GetPointInFront3D(x,y,z,rx,rz,center_dist,cx,cy,cz);
	for(new i = max_points-1; i >= 0; i--){
		omega = Tryg3D::CompressRotation(180.0-(mercury*idx));
		Tryg3D::GetPointInFront3D(0.0,0.0,0.0,omega,0.0,Tryg3D::GetEllipseRadius(height,center_dist,omega),px,py,pz);
		Tryg3D::ShiftOffsetToPosition(cx,cy,cz,rx,ry,rz,px,py,pz,points[idx][0],points[idx][1],points[idx][2]);
		idx++;
	}
	return idx;
}

stock Tryg3D::GetCube3DPoint(const Tryg3D::OrientationCube3D:orientation, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z, &Float:tx, &Float:ty, &Float:tz){
	Tryg3D::ShiftOffsetToPosition(x,y,z,rx,ry,rz,(Tryg3D::Cube3DOffset[orientation][0]*size_x),(Tryg3D::Cube3DOffset[orientation][1]*size_y),(Tryg3D::Cube3DOffset[orientation][2]*size_z),tx,ty,tz);
}

/********************************
 * Area Functions               *
 ********************************/

//Made by Crayder
stock bool: Tryg3D::IsPointInCylinder3D(const Float:px, const Float:py, const Float:pz, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius){
	new Float:cylinder_length = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB);
	if(cylinder_length <= 0.0) return false;
	new Float:iX, Float:iY, Float:iZ,
		Float:distance = Tryg3D::GetDistancePointToLine(px,py,pz,xA,yA,zA,xB,yB,zB,iX,iY,iZ),
		Float:tmp_radius = (Tryg3D::GetDistance3D(iX,iY,iZ,xA,yA,zA) / cylinder_length * radius) + (Tryg3D::GetDistance3D(iX,iY,iZ,xB,yB,zB) / cylinder_length * radius);
	return (distance != -1.0 && distance <= tmp_radius);
}

stock bool: Tryg3D::IsPointInCube3D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z){
	if(size_x <= 0.0 || size_y <= 0.0 || size_z <= 0.0) return false;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::DivideValues(2.0,size_x,size_y,size_z);
	Tryg3D::ShiftPositionToOffset(x,y,z,rx,ry,rz,offset_x,offset_y,offset_z,px,py,pz);
	return Tryg3D::IsPointInCube(offset_x,offset_y,offset_z,-size_x,-size_y,-size_z,size_x,size_y,size_z);
}

//Made by Crayder
stock bool: Tryg3D::IsPointInCone3D(const Float:px, const Float:py, const Float:pz, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b){
	new Float:cylinder_length = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB);
	if(cylinder_length <= 0.0) return false;
	new Float:iX, Float:iY, Float:iZ,
		Float:distance = Tryg3D::GetDistancePointToLine(px,py,pz,xA,yA,zA,xB,yB,zB,iX,iY,iZ),
		Float:radius = (Tryg3D::GetDistance3D(iX,iY,iZ,xA,yA,zA) / cylinder_length * radius_b) + (Tryg3D::GetDistance3D(iX,iY,iZ,xB,yB,zB) / cylinder_length * radius_a);
	return (distance != -1.0 && distance <= radius);
}

stock bool: Tryg3D::IsPointInCircularSector(const Float:px, Float:py, Float:x, Float:y, Float:rz, Float:radius, Float:view_angle){
	if(Tryg3D::GetDistance2D(px,py,x,y) > radius) return false;
	new Float:trz;
	view_angle /= 2.0;
	Tryg3D::GetRotationFor2Point2D(x,y,px,py,trz);
	return Tryg3D::RotationInRange(trz,rx-view_angle,rx+view_angle);
}

stock bool: Tryg3D::IsPointInSphericalSector(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz){
	if(Tryg3D::GetDistance3D(px,py,pz,x,y,z) > radius) return false;
	new Float:trx,Float:trz;
	vrx /= 2.0;
	vrz /= 2.0;
	if(!Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,trx,trz)) return false;
	return (Tryg3D::RotationInRange(trx,rx-vrx,rx+vrx) && Tryg3D::RotationInRange(trz,rz-vrz,rz+vrz));
}

/*
stock bool: Tryg3D::IsPointInSphericalSectorEx(Float:px, Float:py, Float:pz, Float:x, Float:y, Float:z, Float:rx, Float:rz, Float:radius, Float:vrx, Float:vrz, ignore_vehicle = INVALID_VEHICLE_ID, ignore_player = INVALID_PLAYER_ID, ignore_actor = INVALID_ACTOR_ID, collision_flags = TRYG3D_COLLISION_FLAG_OBJECT){
	if(Tryg3D::GetDistance3D(px,py,pz,x,y,z) > radius) return false;
	
	#if defined TRYG3D_COLANDREAS
		new Item3D_Type:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
		if(Tryg3D::CollisionCheck(x,y,z,px,py,pz,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags)) return false;
	#else
		#pragma unused ignore_vehicle
		#pragma unused ignore_player
		#pragma unused ignore_actor
		#pragma unused collision_flags
	#endif
	
	vrx /= 2.0;
	vrz /= 2.0;
	
	new Float:trx,Float:trz;
	
	if(!Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,trx,trz)) return false;
	return (Tryg3D::RotationInRange(trx,rx-vrx,rx+vrx) && Tryg3D::RotationInRange(trz,rz-vrz,rz+vrz));
}
*/

stock bool: Tryg3D::IsPointInEllipse(const Float:px, const Float:py, const Float:cx, const Float:cy, const Float:size_x, const Float:size_y){
	new Float:rz;
	Tryg3D::GetRotationFor2Point2D(cx,cy,px,py,rz);
	return (Tryg3D::GetDistance2D(px,py,cx,cy) <= Tryg3D::GetEllipseRadius(size_x,size_y,rz));
}

stock bool: Tryg3D::IsPointInEllipticalCylinder(const Float:px, const Float:py, const Float:pz, const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y){
	if(!((pz >= minz) && (pz <= maxz))) return false;
	new Float:rz;
	Tryg3D::GetRotationFor2Point2D(cx,cy,px,py,rz);
	return (Tryg3D::GetDistance2D(px,py,cx,cy) <= Tryg3D::GetEllipseRadius(size_x,size_y,rz));
}

//Made by RyDeR
stock bool: Tryg3D::IsPointInPolygon(const Float:x, const Float:y, const Float:points[], maxpoints = sizeof(points)){
	if(!Tryg3D::IsValidPolygon(points,maxpoints)) return false;
	new polygon_Sides = ((maxpoints - 2) / 2), Float:polygon_Data[2][TRYG3D_MAX_POLYGON_POINTS], cross_Total = 0, idx = 0;
	for(new i = 0; i < maxpoints; i += 2){
		polygon_Data[0][idx] = points[i];
		polygon_Data[1][idx] = points[i+1];
		idx++;
	}
	if(!Tryg3D::IsPolygonClosed(points,maxpoints)){
		polygon_Data[0][idx] = points[0];
		polygon_Data[1][idx] = points[1];
		polygon_Sides++;
	}
	for(new i, j = polygon_Sides - 1; i < polygon_Sides; j = i, i++){
		if((polygon_Data[1][i] < y && polygon_Data[1][j] >= y) || (polygon_Data[1][j] < y && polygon_Data[1][i] >= y)){
			if(polygon_Data[0][i] + (y - polygon_Data[1][i]) / (polygon_Data[1][j] - polygon_Data[1][i]) * (polygon_Data[0][j] - polygon_Data[0][i]) < x){
				cross_Total++;
			}
		}
	}
	return (cross_Total & 0x1);
}

stock bool: Tryg3D::PointInCylinder2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius){
	return Tryg3D::IsPointInCylinder3D(px,py,pz,x,y,minx,x,y,maxz,radius);
}

stock bool: Tryg3D::PointInCone2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b){
	return Tryg3D::IsPointInCone3D(px,py,pz,x,y,minx,x,y,maxz,radius_a,radius_b));
}

stock bool: Tryg3D::PointInCircle(const Float:px, const Float:py, const Float:x, const Float:y, const Float:radius){
	return Tryg3D::GetDistance2D(px,py,x,y) <= radius;
}

stock bool: Tryg3D::PointInSphere(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:radius){
	return Tryg3D::GetDistance3D(px,py,pz,x,y,z) <= radius;
}

stock bool: Tryg3D::PointInRectangle(const Float:px, const Float:py, const Float:minx, const Float:miny, const Float:maxx, const Float:maxy){
	return (px >= minx && px <= maxx) && (py >= miny && py <= maxy);
}

stock bool: Tryg3D::PointInCube(const Float:px, const Float:py, const Float:pz, const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz){
	return (px >= minx && px <= maxx) && (py >= minxy && py <= maxy) && (pz >= minz && pz <= maxz);
}

/********************************
 * Random Functions             *
 ********************************/

stock Tryg3D::GetRandomHit(const Float:x, const Float:y, const Float:z, const range, &Float:tx, &Float:ty, &Float:tz){
	tx = x + (random(range * 2 + 1) - range);
	ty = y + (random(range * 2 + 1) - range);
	tz = z + (random(range * 2 + 1) - range);
}

//Made by Crayder
stock Tryg3D::GetPointInCircle(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty){
	new Float:T3D:alfa = float(random(1000000)+1)/1000000.0, Float:T3D:beta = float(random(1000000)+1)/1000000.0;
	if(T3D:beta < T3D:alfa) Tryg3D::SwapFloat(T3D:alfa,T3D:beta);
	tx = x + (T3D:beta * radius * floatcos(2.0 * FLOAT_PI * T3D:alfa / T3D:beta));
	ty = y + (T3D:beta * radius * floatsin(2.0 * FLOAT_PI * T3D:alfa / T3D:beta));
}

//Made by Crayder
stock Tryg3D::GetPointInCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	Tryg3D::GetPointInCircle(x,y,radius,tx,ty);
	tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)))+minz;
}

stock bool: Tryg3D::GetPointInCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	new Float:trx,Float:trz;
	if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return false;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::GetPointInCylinder2D(0.0,0.0,0.0,Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB),radius,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(xA,yA,zA,Tryg3D::CompressRotation(trx-90),0.0,Tryg3D::CompressRotation(trz),offset_x,offset_y,offset_z,tx,ty,tz);
	return true;
}

stock Tryg3D::GetPointInSphere(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE),Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE),Tryg3D::RandomFloat(0.0,radius),tx,ty,tz);
}

stock Tryg3D::GetPointInRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, &Float:tx, &Float:ty){
	tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
	ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
}

stock Tryg3D::GetPointInCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, &Float:tx, &Float:ty, &Float:tz){
	tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
	ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
	tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
}

stock Tryg3D::GetPointInCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z, &Float:tx, &Float:ty, &Float:tz){
	if(size_x <= 0 || size_y <= 0 || size_z <= 0.0) return 0;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::DivideValues(2.0,size_x,size_y,size_z);
	Tryg3D::GetPointInCube(-size_x,-size_y,-size_z,size_x,size_y,size_z,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(x,y,z,rx,ry,rz,offset_x,offset_y,offset_z,tx,ty,tz);
	return 1;
}

stock Tryg3D::GetPointInCone2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz){
	new Float:T3D:point_dist = Tryg3D::GetDistance1D(minz,maxz), Float:T3D:rand_dist = Tryg3D::RandomFloat(0.0,T3D:point_dist);
	tz = minz + T3D:rand_dist;
	Tryg3D::GetPointInCircle(x,y,Tryg3D::RandomFloat(0.0,(T3D:rand_dist*((radius_b-radius_a)*(1.0/T3D:point_dist))+radius_a)*2.0),tx,ty);
}

stock Tryg3D::GetPointInCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz){
	new Float:trx,Float:trz;
	if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return 0;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::GetPointInCone2D(0.0,0.0,0.0,Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB),radius_a,radius_b,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(xA,yA,zA,Tryg3D::CompressRotation(trx-90),0.0,Tryg3D::CompressRotation(trz),offset_x,offset_y,offset_z,tx,ty,tz);
	return 1;
}

stock Tryg3D::GetPointInCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, const Float:view_angle, &Float:tx, &Float:ty){
	view_angle /= 2.0;
	new Float:rand_rz = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rz-view_angle+360.0,rz+view_angle+360.0,6)), Float:rand_rad = Tryg3D::RandomFloat(0.0,radius,6);
	if(rand_rad > radius) rand_rad = radius;
	rand_rz = Tryg3D::NMTV(rand_rz,(rz+view_angle));
	rand_rz = Tryg3D::NLTV(rand_rz,(rz-view_angle));
	Tryg3D::GetPointInFront2D(x,y,rand_rz,rand_rad,tx,ty);
}

stock Tryg3D::GetPointInSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, &Float:tx, &Float:ty, &Float:tz){
	new Float:rand_rx = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rx-vrx+360.0,rx+vrx+360.0,6)), Float:rand_rz = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rz-vrz+360.0,rz+vrz+360.0,6)), Float:rand_rad = Tryg3D::RandomFloat(0.0,radius,6);
	vrx /= 2.0;
	vrz /= 2.0;
	if(rand_rad > radius) rand_rad = radius;
	if(rand_rx > rx+vrx) rand_rx = rx+vrx;
	if(rand_rx < rx-vrx) rand_rx = rx-vrx;	
	if(rand_rz > rz+vrz) rand_rz = rz+vrz;
	if(rand_rz < rz-vrz) rand_rz = rz-vrz;
	Tryg3D::GetPointInFront3D(x,y,z,rand_rx,rand_rz,rand_rad,tx,ty,tz);
}

stock Tryg3D::GetPointInEllipse(const Float:cx, const Float:cy, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty){
	new Float:omega = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE,6);
	Tryg3D::GetPointInFront2D(cx,cy,omega,Tryg3D::RandomFloat(0.0,Tryg3D::GetEllipseRadius(size_x,size_y,omega),6),tx,ty);
}

stock Tryg3D::GetPointInEllipticalCylinder(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, Float:size_y, &Float:tx, &Float:ty, &Float:tz){
	new Float:omega = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE,6);
	Tryg3D::GetPointInFront2D(cx,cy,omega,Tryg3D::RandomFloat(0.0,Tryg3D::GetEllipseRadius(size_x,size_y,omega),6),tx,ty);
	tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
}

stock Tryg3D::GetPointInPolygon(const Float:points[], &Float:tx, &Float:ty, maxpoints = sizeof(points),  max_iterations = 10000){
	if(!Tryg3D::IsValidPolygon(points,maxpoints)) return -1;
	new Float:minx, Float:miny, Float:maxx, Float:maxy, recheck = 1;
	minx = maxx = points[0];
	miny = maxy = points[1];
	for(new i = 2; i < maxpoints; i += 2){
		if(points[i] < minx) minx = points[i];
		if(points[i] > maxx) maxx = points[i];
		if(points[i+1] < miny) miny = points[i+1];
		if(points[i+1] > maxy) maxy = points[i+1];
	}
	Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
	while(!Tryg3D::IsPointInPolygon(tx,ty,points,maxpoints)){
		Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
		recheck++;
		if(recheck >= max_iterations){
			printf("[ADM] Warrning: Tryg3D::GetPointInPolygon(%f,%f,%f,%f,%f,%f,...,tx,ty,%d) break after %d iterations",points[0],points[1],points[2],points[3],points[4],points[5],maxpoints,max_iterations);
			return -1;
		}
	}
	return recheck;
}

stock Float:Tryg3D::GetPointOnClock(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty, &Float:trz, Float:rz = TRYG3D_INVALID_ROTATION){
	if(rz == TRYG3D_INVALID_ROTATION) rz = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE);
	Tryg3D::GetPointInFront2D(x,y,rz,radius,tx,ty);
	trz = Tryg3D::CompressRotation(rz-180.0);
	return trz;
}

stock Tryg3D::GetPointOnCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	Tryg3D::GetPointOnCircle(x,y,radius,tx,ty);
	tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)))+minz;
}

stock Tryg3D::GetPointOnCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	new Float:px,Float:py,Float:pz,Float:trx,Float:trz;
	Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz);
	Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,Tryg3D::RandomFloat(0.0,Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB)),px,py,pz);
	Tryg3D::GetPointInFront3DEx(px,py,pz,Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE),trx,Tryg3D::CompressRotation(trz+90.0),radius,tx,ty,tz);
}

//Made by Neil Lamoureux
stock Tryg3D::GetPointOnSphere(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
	new Float:T3D:theta = 2 * FLOAT_PI * (float(random(1000000)+1)/1000000.0), Float:T3D:phi = acos(2 * (float(random(1000000)+1)/1000000.0) - 1);
	tx = x + (radius * floatsin(T3D:phi,degrees) * floatcos(T3D:theta,degrees));
	ty = y + (radius * floatsin(T3D:phi,degrees) * floatsin(T3D:theta,degrees));
	tz = z + (radius * floatcos(T3D:phi,degrees));
}

stock Tryg3D::GetPointOnRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, &Float:tx, &Float:ty){
	switch(random(4)){
		case 0: {
			tx = minx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
		}
		case 1: {
			tx = maxx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
		}
		case 2: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = miny;
		}
		case 3: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = maxy;
		}
	}
}

stock Tryg3D::GetPointOnCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, &Float:tx, &Float:ty, &Float:tz){
	switch(random(12)){
		case 0: {
			tx = minx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
			tz = minz;
		}
		case 1: {
			tx = maxx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
			tz = minz;
		}
		case 2: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = miny;
			tz = minz;
		}
		case 3: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = maxy;
			tz = minz;
		}
		case 4: {
			tx = minx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
			tz = maxz;
		}
		case 5: {
			tx = maxx;
			ty = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(miny-maxy,2)),6)+miny;
			tz = maxz;
		}
		case 6: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = miny;
			tz = maxz;
		}
		case 7: {
			tx = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minx-maxx,2)),6)+minx;
			ty = maxy;
			tz = maxz;
		}
		case 8: {
			tx = minx;
			ty = miny;
			tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
		}
		case 9: {
			tx = maxx;
			ty = miny;
			tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
		}
		case 10: {
			tx = minx;
			ty = maxy;
			tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
		}
		case 11: {
			tx = maxx;
			ty = maxy;
			tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
		}
	}
}

stock Tryg3D::GetPointOnCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z, &Float:tx, &Float:ty, &Float:tz){
	if(size_x <= 0 || size_y <= 0 || size_z <= 0.0) return 0;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::DivideValues(2.0,size_x,size_y,size_z);
	Tryg3D::GetPointOnCube(-size_x,-size_y,-size_z,size_x,size_y,size_z,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(x,y,z,rx,ry,rz,offset_x,offset_y,offset_z,tx,ty,tz);
	return 1;
}

stock Tryg3D::GetPointOnCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz){
	new Float:px,Float:py,Float:pz,Float:trx,Float:trz, Float:T3D:dist = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB), Float:rand_dist = Tryg3D::RandomFloat(0.0,T3D:dist);
	Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz);
	Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,rand_dist,px,py,pz);
	Tryg3D::GetPointInFront3DEx(px,py,pz,Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE),trx,Tryg3D::CompressRotation(trz+90.0),rand_dist*((radius_b-radius_a)*(1.0/T3D:dist))+radius_a,tx,ty,tz);
}

stock Tryg3D::GetPointOnCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, Float:view_angle, &Float:tx, &Float:ty){
	view_angle /= 2.0;
	new Float:rand_rz = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rz-view_angle+360.0,rz+view_angle+360.0,6));
	rand_rz = Tryg3D::NMTV(rand_rz,(rz+view_angle));
	rand_rz = Tryg3D::NLTV(rand_rz,(rz-view_angle));
	Tryg3D::GetPointInFront2D(x,y,rand_rz,radius,tx,ty);
}

stock Tryg3D::GetPointOnSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz, &Float:tx, &Float:ty, &Float:tz){
	vrx /= 2.0;
	vrz /= 2.0;
	new Float:rand_rx = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rx-vrx+360.0,rx+vrx+360.0,6)), Float:rand_rz = Tryg3D::CompressRotation(Tryg3D::RandomFloat(rz-vrz+360.0,rz+vrz+360.0,6));
	if(rand_rx > rx+vrx) rand_rx = rx+vrx;
	if(rand_rx < rx-vrx) rand_rx = rx-vrx;
	if(rand_rz > rz+vrz) rand_rz = rz+vrz;
	if(rand_rz < rz-vrz) rand_rz = rz-vrz;
	Tryg3D::GetPointInFront3D(x,y,z,rand_rx,rand_rz,radius,tx,ty,tz);
}

stock Tryg3D::GetPointOnEllipse(const Float:cx, const Float:cy, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty){
	new Float:omega = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE,6);
	Tryg3D::GetPointInFront2D(cx,cy,omega,Tryg3D::GetEllipseRadius(size_x,size_y,omega),tx,ty);
}

stock Tryg3D::GetPointOnEllipticalCyl2D(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty, &Float:tz){
	new Float:omega = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE,6);
	Tryg3D::GetPointInFront2D(cx,cy,omega,Tryg3D::GetEllipseRadius(size_x,size_y,omega),tx,ty);
	tz = Tryg3D::RandomFloat(0.0,floatsqroot(floatpower(minz-maxz,2)),6)+minz;
}

/********************************
 * Player Functions             *
 ********************************/

#if defined TRYG3D_MODULE_PLAYER

#endif

/********************************
 * Vehicle Functions            *
 ********************************/

#if defined TRYG3D_MODULE_VEHICLE

#endif

/********************************
 * Draw3D Functions             *
 ********************************/

#if defined TRYG3D_MODULE_DRAW3D

#endif

/********************************
 * Init Functions               *
 ********************************/

stock Tryg3D::Init(){
	Tryg3D::UpTime = GetTickCount();
	SetSVarInt("ADM:3DTryg:ACTIVE",Tryg3D::GetActiveCount()+1);
	
	new T3D:modules[TRYG3D_MAX_MODULES_STRING];
	/* todo */
	
	new T3D:ver_name[16];
	format(T3D:ver_name,sizeof(T3D:ver_name),"%d.%d.%d",Tryg3D::GetVersion(TRYG3D_VERSION));
	if(GetSVarInt("TRYG3D:REMASTERED:INIT") == 0){
		SetSVarInt("TRYG3D:REMASTERED:INIT",1);
		printf("[ADM] Info: Load %s Gen 2. v%s for %s %s by %s",TRYG3D_LIBRARY_NAME,T3D:ver_name,TRYG3D_PLATFORM_NAME,TRYG3D_PLATFORM_VERSION,TRYG3D_AUTHOR_NAME);
		new T3D:len = strlen(T3D:modules);
		if(T3D:len > 0){
			T3D:modules[T3D:len-1] = EOS;
			printf("[ADM] Info: Load %s Modules:%s",TRYG3D_LIBRARY_NAME,T3D:modules);
		}
	}

	if(TRYG3D_VEHICLE_SPEED_MULTIPLIER < 1.0){
		print("[ADM] Error: Definition TRYG3D_VEHICLE_SPEED_MULTIPLIER must be greater or equal 1.0");
		Tryg3D::UpdateErrorCount();
	}
	if(TRYG3D_PLAYER_SPEED_MULTIPLIER < 1.0){
		print("[ADM] Error: Definition TRYG3D_PLAYER_SPEED_MULTIPLIER must be greater or equal 1.0");
		Tryg3D::UpdateErrorCount();
	}
	if(VERTICAL_CAMERA_RADIUS < 1.0){
		print("[ADM] Error: Definition VERTICAL_CAMERA_RADIUS must be greater or equal 1.0");
		Tryg3D::UpdateErrorCount();
	}
	if(HORIZONTAL_CAMERA_RADIUS < 1.0){
		print("[ADM] Error: Definition HORIZONTAL_CAMERA_RADIUS must be greater or equal 1.0");
		Tryg3D::UpdateErrorCount();
	}
	if(TRYG3D_CHARACTER_GROUND_Z_DIFF < 0.0){
		print("[ADM] Error: Definition TRYG3D_CHARACTER_GROUND_Z_DIFF must be greater or equal 0.0");
		Tryg3D::UpdateErrorCount();
	}
	
	new T3D:errors = Tryg3D::GetErrorCount();
	if(T3D:errors > 0) printf("[ADM] Info: 3DTryg running with %d errors detected, see above",T3D:errors);
}

stock Tryg3D::Exit(){
	SetSVarInt("ADM:3DTryg:ACTIVE",Tryg3D::GetActiveCount()-1);
	new T3D:ver_name[16];
	format(T3D:ver_name,sizeof(T3D:ver_name),"%d.%d.%d",Tryg3D::GetVersion(TRYG3D_VERSION));
	if(Tryg3D::GetActiveCount() == 0){
		SetSVarInt("TRYG3D:REMASTERED:INIT",0);
		printf("[ADM] Info: Unload %s Gen 2. v%s for %s %s by %s",TRYG3D_LIBRARY_NAME,T3D:ver_name,TRYG3D_PLATFORM_NAME,TRYG3D_PLATFORM_VERSION,TRYG3D_AUTHOR_NAME);
	}
}

/********************************
 * Hooks                        *
 ********************************/

//Hook: OnFilterScriptInit
public OnFilterScriptInit(){
	if(Tryg3D::StateInit){
		Tryg3D::StateInit = false;
		Tryg3D::Init();
	}
	#if defined T3_OnFilterScriptInit
		Tryg3D::OnFilterScriptInit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptInit
	#undef OnFilterScriptInit
#else
	#define _ALS_OnFilterScriptInit
#endif
#define OnFilterScriptInit Tryg3D::OnFilterScriptInit
#if defined T3_OnFilterScriptInit
	forward Tryg3D::OnFilterScriptInit();
#endif

//Hook: OnGameModeInit
public OnGameModeInit(){
	if(Tryg3D::StateInit){
		Tryg3D::StateInit = false;
		Tryg3D::Init();
	}
	#if defined T3_OnGameModeInit
		Tryg3D::OnGameModeInit();
	#endif
	return 1;
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit Tryg3D::OnGameModeInit
#if defined T3_OnGameModeInit
	forward Tryg3D::OnGameModeInit();
#endif

//Hook: OnFilterScriptExit
public OnFilterScriptExit(){
	if(Tryg3D::StateExit){
		Tryg3D::StateExit = false;
		Tryg3D::Exit();
	}
	#if defined T3_OnFilterScriptExit
		Tryg3D::OnFilterScriptExit();
	#endif
	return 1;
}

#if defined _ALS_OnFilterScriptExit
	#undef OnFilterScriptExit
#else
	#define _ALS_OnFilterScriptExit
#endif
#define OnFilterScriptExit Tryg3D::OnFilterScriptExit
#if defined T3_OnFilterScriptExit
	forward Tryg3D::OnFilterScriptExit();
#endif

//Hook: OnGameModeExit
public OnGameModeExit(){
	if(Tryg3D::StateExit){
		Tryg3D::StateExit = false;
		Tryg3D::Exit();
	}
	#if defined T3_OnGameModeExit
		Tryg3D::OnGameModeExit();
	#endif
	return 1;
}

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit Tryg3D::OnGameModeExit
#if defined T3_OnGameModeExit
	forward Tryg3D::OnGameModeExit();
#endif

/********************************
 * Additional operations        *
 ********************************/

#pragma unused T3_WeaponDamage
//#pragma unused T3_StreamDistance
//#pragma unused T3_DeatchTick
#pragma unused T3_OrientationRotation
//#pragma unused T3_ExplosionTime
#pragma unused T3_UpTime

//#undef T3_UpdateErrorCount

//EOF