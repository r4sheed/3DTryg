/*

Library: 3DTryg.inc
Copyright © 2022 Abyss Morgan. All rights reserved.
Contributors: Nero_3D (Shisk), Crayder, IllidanS4, RyDeR, Zoutdaxv, hesambia, Neil Lamoureux, Ivan_Ino, Ralfie, Unrea1, $continue$, Switel12, Mr.Reus

Website: N/A

Plugins: ColAndreas, Streamer, FCNPC, YSF
Internal Modules: Player, Vehicle, Actor, VehicleCollision, PlayerCollision, ActorCollision, GrenadeDetection, Universal, Draw3D, Cast3D, CatchItems

Platforms:
- SA:MP 0.3.7
- SA:MP 0.3 DL

File Version:
- Gen. 2 v1.0.2

Plugin Versions:
- ColAndreas Version: 1.5.0
- YSF Version: R19 (kurta999)
- Streamer Version: 2.9.5
- FCNPC Version: 2.0.0

Foreach Types:
- FoxForeach
- StandaloneForeach
- YSI Foreach
- GetPlayerPoolSize

Compiler Options:
- TRYG3D_DISABLE_INIT            //Use before 3DTryg.inc for disable ColAndreas Auto Init
- TRYG3D_ENABLE_PLAYER           //Use before 3DTryg.inc for enable Player Module
- TRYG3D_ENABLE_VEHICLE          //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_ACTOR            //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_GRENADEDETECTION //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_VEHICLECOL       //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_PLAYERCOL        //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_ACTORCOL         //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_UNIVERSAL        //Use before 3DTryg.inc for enable  Module
- TRYG3D_ENABLE_DRAW3D           //Use before 3DTryg.inc for enable Draw3D Module
- TRYG3D_ENABLE_CAST3D           //Use before 3DTryg.inc for enable Cast3D Module
- TRYG3D_ENABLE_CATCHITEMS       //Use before 3DTryg.inc for enable CatchItems Module
- TRYG3D_ENABLE_COLANDREAS       //Use before 3DTryg.inc for enable ColAndreas Plugin Module
- TRYG3D_ENABLE_STREAMER         //Use before 3DTryg.inc for enable Streamer Plugin Module
- TRYG3D_ENABLE_FCNPC            //Use before 3DTryg.inc for enable FCNPC Plugin Module
- TRYG3D_ENABLE_YSF              //Use before 3DTryg.inc for enable YSF Plugin Module

# Complementary Functions
Float: sqrtN(Float:value, Float:exponent);
abs(value);
Float: fabs(Float:value);
power(value, Float:exponent);
bool: IsEven(value);

# Internal Functions
Float: Tryg3D::RandomFloat(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY);
Float: Tryg3D::RandomFloatEx(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY);
Tryg3D::RandomInteger(const min, const max);
Float: Tryg3D::CalculatePercent(const Float:value, const Float:maxvalue);
Float: Tryg3D::CompressRotation(const Float:rotation);
Float: Tryg3D::DeCompressRotation(Float:rotation);
Tryg3D::SwapInt(&variable1, &variable2);
Tryg3D::SwapFloat(&Float:variable1, &Float:variable2);
Tryg3D::RecoilVector(&Float:vx, &Float:vy, &Float:vz, const Float:sx, const Float:sy, const Float:sz);
Float: Tryg3D::NormalizeVector(&Float:x, &Float:y, &Float:z = 0.0);
Float: Tryg3D::SingleClock(max_items,index);
Float: Tryg3D::EvenClock(max_items,index);
Float: Tryg3D::UnevenClock(max_items,index);
Tryg3D::NLTZ(value);
Tryg3D::NMTZ(value);
Float: Tryg3D::NLTZF(Float:value);
Float: Tryg3D::NMTZF(Float:value);
Tryg3D::NLTV(value, min);
Tryg3D::NMTV(value, max);
Float: Tryg3D::NLTVF(Float:value, Float:min);
Float: Tryg3D::NMTVF(Float:value, Float:max);
Tryg3D::GetWeaponDamage(weaponid);
bool: Tryg3D::RotationInRange(const Float:rotation, Float:min, Float:max);
Float: Tryg3D::RoundAccuracy(Float:value);
Tryg3D::AppendLineArguments2D(Float:line[2], Float:x, Float:y);
Tryg3D::AppendLineArguments3D(Float:line[3], Float:x, Float:y, Float:z);
Tryg3D::DivideValues(denominator, &Float:x, &Float:y, &Float:z);
Float: Tryg3D::RecoilFloat(Float:value, Float:recoil);
Tryg3D::SetStreamDistance(const Float:streamdistance);
Float: Tryg3D::GetStreamDistance();
Tryg3D::KeyPressed(key);
Tryg3D::KeyReleased(key);
Tryg3D::KeyHolding(key);
Tryg3D::SecToTimeDay(seconds);      //%d:%02d:%02d:%02d
Tryg3D::MSToTimeDay(milliseconds);  //%d:%02d:%02d:%02d
Tryg3D::SecToTime(seconds);         //%02d:%02d:%02d
Tryg3D::MSToTime(milliseconds);     //%02d:%02d:%02d
Tryg3D::SecToTimeMini(seconds);     //%02d:%02d
Tryg3D::MSToTimeMini(milliseconds); //%02d:%02d

# Quaternion Functions
Tryg3D::EulerToQuat(Float:rx, Float:ry, Float:rz, &Float:qw, &Float:qx, &Float:qy, &Float:qz);
Tryg3D::QuatToEuler(&Float:rx, &Float:ry, &Float:rz, Float:qw, Float:qx, Float:qy, Float:qz);
Tryg3D::GetRotationMatrixEuler(Float:matrix[][], const Float:rx, const Float:ry, const Float:rz);
Tryg3D::GetRotationMatrixEulerEx(Float:matrix[][], const Float:rx, const Float:ry, const Float:rz, const EulerModes: mode = T3D:euler_default);
Tryg3D::MatrixRotate(const Float:matrix[][], const Float:oX, const Float:oY, const Float:oZ, &Float:x, &Float:y, &Float:z);
Tryg3D::MatrixRotateReverse(const Float:matrix[][], const Float:oX, const Float:oY, const Float:oZ, &Float:x, &Float:y, &Float:z);
Tryg3D::GetQuatFromEuler(Float:rx, Float:ry, Float:rz, &Float:qw, &Float:qx, &Float:qy, &Float:qz, EulerModes: mode = T3D:euler_default);
Tryg3D::QuatRotate(const Float:qw, const Float:qx, const Float:qy, const Float:qz, const Float:oX, const Float:oY, const Float:oZ, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::EulerRotate(Float:rx, Float:ry, Float:rz, Float:oX, Float:oY, Float:oZ, &Float:tx,&Float:ty,&Float:tz);
Tryg3D::EulerRotateEx(Float:rx, Float:ry, Float:rz, Float:oX, Float:oY, Float:oZ, &Float:tx, &Float:ty, &Float:tz, EulerModes: mode = T3D:euler_default);
Tryg3D::GetQuatUpVector(const Float:qw, const Float:qx, const Float:qy, const Float:qz, &Float:vx, &Float:vy, &Float:vz);

# Screen Functions
Tryg3D::NormCrossProduct(&Float:x, &Float:y, &Float:z, Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z);
Tryg3D::ScreenToWorld(const playerid, const Float:screenX, const Float:screenY, &Float:vX, &Float:vY, &Float:vZ);
Tryg3D::WorldToScreen(const playerid, Float:x, Float:y, Float:z, &Float:screenX, &Float:screenY);
Tryg3D::ScreenToWorldCol(const playerid, const Float:distance, const Float:screenX, const Float:screenY, &Float:wX, &Float:wY, &Float:wZ);

# General Functions
Float: Tryg3D::GetDistance1D(const Float:x1, const Float:x2);
Float: Tryg3D::GetDistance2D(const Float:x1, const Float:y1, const Float:x2, const Float:y2);
Float: Tryg3D::GetDistance3D(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2);
bool: Tryg3D::IsPolygonClosed(const Float:points[], const max_points = sizeof(points));
bool: Tryg3D::IsValidPolygon(const Float:points[], const max_points = sizeof(points));
ElementOrientation: Tryg3D::GetOrientation(Float:angle);
bool: Tryg3D::GetOrientationName(orientation_name[], const Float:angle, bool:as_compass = false, const maxdest = sizeof(orientation_name));
Float: Tryg3D::GetEllipseRadius(const Float:x, const Float:y, const Float:angle);
Float: Tryg3D::GetLineSize2D(const Float:points[][2], const max_points = sizeof(points));
Float: Tryg3D::GetLineSize3D(const Float:points[][3], const max_points = sizeof(points));
Tryg3D::GetRotationFor2Point2D(const Float:x, const Float:y, const Float:tx, const Float:ty, &Float:rz);
Tryg3D::GetPointInFront2D(const Float:x, const Float:y, const Float:rz, const Float:radius, &Float:tx, &Float:ty);
Tryg3D::GetPointInFront3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetRotationFor2Point3D(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, &Float:rx, &Float:rz);
Tryg3D::GetPointInFront3DEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointFor2Point2D(const Float:x1, const Float:y1, const Float:x2, const Float:y2, const Float:percent_size, &Float:tx, &Float:ty);
Tryg3D::GetPointFor2Point3D(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2, const Float:percent_size, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointFor2Point2DEx(const Float:x1, const Float:y1, const Float:x2, const Float:y2, const Float:distance, &Float:tx, &Float:ty);
Tryg3D::GetPointFor2Point3DEx(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2, const Float:distance, &Float:tx, &Float:ty, &Float:tz);
Float: Tryg3D::GetDistancePointToLine(const Float:px, const Float:py, const Float:pz, const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:iX = 0.0, &Float:iY = 0.0, &Float:iZ = 0.0);
Float: Tryg3D::GetDistancePointToLineEx(const Float:px, const Float:py, const Float:pz, const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:iX = 0.0, &Float:iY = 0.0, &Float:iZ = 0.0);
Tryg3D::GetNearest2DPointOnPolygon(const Float:polygon_points[], const Float:x, const Float:y, &Float:tx, &Float:ty, const max_points = sizeof(polygon_points));
Float: Tryg3D::GetLineCosTheta2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]);
Float: Tryg3D::GetLineCosTheta3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]);
bool: Tryg3D::IsLinesParallel2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]);
bool: Tryg3D::IsLinesParallel3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]);
bool: Tryg3D::IsLinesPerpendicular2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]);
bool: Tryg3D::IsLinesPerpendicular3D(const Float:StartLine1[3], const Float:EndLine1[3], const Float:StartLine2[3], const Float:EndLine2[3]);
bool: Tryg3D::IsPointBetween2Points2D(const Float:px, const Float:py, const Float:x1, const Float:y1, const Float:x2, const Float:y2);
bool: Tryg3D::IsPointBetween2Points3D(const Float:px, const Float:py, const Float:pz, const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2);
Tryg3D::GetGangZone(const Float:x, const Float:y, const Float:radius, &Float:minx, &Float:miny, &Float:maxx, &Float:maxy);
bool: Tryg3D::IsProbable(const Float:chance, const accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY);
Tryg3D::RandomItemFromArray(const items[][LootArray], const max_items = sizeof(items), const accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY);
Tryg3D::GetWeaponShotPos(playerid, hittype, &Float:fx, &Float:fy, &Float:fz);
Tryg3D::GetCenterRectangle(const Float: x_min, const Float: y_min, const Float: x_max, const Float: y_max, &Float: x_center, &Float: y_center);

# Converter Functions
Float: Tryg3D::ShiftDegreeToRadian(const Float:value);
Float: Tryg3D::ShiftDegreeToRadianEx(const Float:value);
Float: Tryg3D::ShiftDegreeToGrades(const Float:value);
Float: Tryg3D::ShiftRadianToDegree(const Float:value);
Float: Tryg3D::ShiftRadianToDegreeEx(const Float:value);
Float: Tryg3D::ShiftRadianToGrades(const Float:value);
Float: Tryg3D::ShiftGradesToDegree(const Float:value);
Float: Tryg3D::ShiftGradesToRadian(const Float:value);
Tryg3D::ShiftRotationToVector(const Float:rx, const Float:rz, &Float:vx, &Float:vy, &Float:vz);
Tryg3D::ShiftVectorToRotation(const Float:vx, const Float:vy, const Float:vz, &Float:rx, &Float:rz);
bool: Tryg3D::ShiftVectorRotation(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::ShiftOffsetToPosition(const Float:x, const Float:y, const Float:z, Float:rx, Float:ry, Float:rz, const Float:offset_x, const Float:offset_y, const Float:offset_z, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::ShiftPositionToOffset(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:offset_x, &Float:offset_y, &Float:offset_z, const Float:tx, const Float:ty, const Float:tz);
Tryg3D::ShiftLineRotation(const Float:sX, const Float:sY, const Float:sZ, Float:eX, Float:eY, Float:eZ, const Float:rx, const Float:ry, const Float:rz, &Float:nX, &Float:nY, &Float:nZ);
bool: Tryg3D::ShiftLineRotationVector(const Float:sX, const Float:sY, const Float:sZ, Float:eX, Float:eY, Float:eZ, const Float:rx, const Float:ry, const Float:rz, &Float:nX, &Float:nY, &Float:nZ);
Tryg3D::ShiftSpeedToMoveTime(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const Float:speed);
Float: Tryg3D::ShiftMoveTimeToSpeed(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const movement_time);

# Extended Functions
bool: Tryg3D::IsPointToPointVector(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz);
Tryg3D::GetArcPoints3D(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, Float:ry, const Float:height, Float:points[][3], const max_points = sizeof(points));
Tryg3D::GetCube3DPoint(const OrientationCube3D:orientation, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z, &Float:tx, &Float:ty, &Float:tz);

# ColAndreas Functions
Tryg3D::IsColAndreasInit();
Tryg3D::SafeColAndreasInit();
Tryg3D::IsCollisionFlag(const value, const flag);
Tryg3D::IsPointInUnderwater(const Float:x, const Float:y, const Float:z);
Tryg3D::FindGroundZ(const Float:x, const Float:y, const Float:z, &Float:gZ);
Tryg3D::MovePointCol(const Float:StartX, const Float:StartY, const Float:StartZ, const Float:EndX, const Float:EndY, const Float:EndZ, &Float:x, &Float:y, &Float:z);
Tryg3D::MovePointColCutLine(const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:x, &Float:y, &Float:z, const Float:cut_size = 0.0);
Tryg3D::GetPointInFront3DCol(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInFront3DColEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Float: Tryg3D::GetPointInFrontOfPlayerCol(const playerid, &Float:tx, &Float:ty, const Float:radius);
Float: Tryg3D::GetPointInFrontOfCamera2DCol(const playerid, &Float:tx, &Float:ty, const Float:radius);
Tryg3D::GetPointInFrontOfCamera3DCol(const playerid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0);
Tryg3D::GetPointInFrontOfVehicleCol(const vehicleid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0);
Tryg3D::UndergroundFindZ(const Float:x, const Float:y, &Float:z);
Tryg3D::InteriorFindZ(const Float:px, const Float:py, const Float:pz, const Float:size = 2.0, &Float:z = 0.0);
bool: Tryg3D::IsPointInWater(const Float:x, const Float:y, const Float:z = 0.0);
bool: Tryg3D::IsPointInUnderground(const Float:x, const Float:y, const Float:z);
bool: Tryg3D::IsPointInAir(const Float:x, const Float:y, const Float:z, const bool:interior = false, const Float:max_distance = 2.2);
bool: Tryg3D::IsPointInGround(const Float:x, const Float:y, const Float:z, const bool:interior = false, const Float:max_distance = 2.2);
Tryg3D::GetPointCollisionFlags(const Float:x, const Float:y, const Float:z, const interiorid = 0);
Tryg3D::IsBetweenPlayersIsWall(const playerid, const targetid);
Tryg3D::IsBetweenPlayerToPointIsWall(const playerid, const Float:x, const Float:y, const Float:z);
bool: Tryg3D::GetPointInWallForPoint(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz, const Float:sector = 90.0);
Tryg3D::SetCameraDirectionLookAt(const playerid, const Float:x, const Float:y, const Float:z, const Float:distance = 5.0, const Float:rx = 20.0, const Float:sector = 90.0);
bool: Tryg3D::CollisionCheck(const Float:StartX, const Float:StartY, const Float:StartZ, const Float:EndX, const Float:EndY, const Float:EndZ, &Float:x, &Float:y, &Float:z, &Item3D:item_type = Item3D:0, &element_id = 0, const Float:cut_size = 0.0, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL);
bool: Tryg3D::GetWallRotation(const Float:sx, const Float:sy, const Float:sz, const Float:ex, const Float:ey, const Float:ez, &Float:rx, &Float:rz, &Float:px = 0.0, &Float:py = 0.0, &Float:pz = 0.0, const Float:size = 1.0, const Float:cut_size = 0.0);
Tryg3D::GetGroundRotation(const Float:x, const Float:y, const Float:size, &Float:rx, &Float:ry);
bool: Tryg3D::IsPointInWaterFrontOfPlayer(const playerid, const Float:radius);
bool: Tryg3D::IsPointInSphericalSectorEx(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT);

# ColAndreas Callbacks
OnColAndreasRemoveBuilding();
OnColAndreasInitSuccess();
OnColAndreasInitFail();

# Area Functions
bool: Tryg3D::IsPointInCylinder3D(const Float:px, const Float:py, const Float:pz, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius);
bool: Tryg3D::IsPointInCube(const Float:px, const Float:py, const Float:pz, const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz);
bool: Tryg3D::IsPointInCube3D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z);
bool: Tryg3D::IsPointInCone3D(const Float:px, const Float:py, const Float:pz, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b);
bool: Tryg3D::IsPointInCircularSector(const Float:px, const Float:py, const Float:x, const Float:y, Float:rz, const Float:radius, Float:view_angle);
bool: Tryg3D::IsPointInSphericalSector(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz);
bool: Tryg3D::IsPointInEllipse(const Float:px, const Float:py, const Float:cx, const Float:cy, const Float:size_x, const Float:size_y);
bool: Tryg3D::IsPointInEllipticalCylinder(const Float:px, const Float:py, const Float:pz, const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y);
bool: Tryg3D::IsPointInPolygon(const Float:x, const Float:y, const Float:points[], const max_points = sizeof(points));
bool: Tryg3D::IsPointInCylinder2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius);
bool: Tryg3D::IsPointInCone2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b);
bool: Tryg3D::IsPointInCircle(const Float:px, const Float:py, const Float:x, const Float:y, const Float:radius);
bool: Tryg3D::IsPointInSphere(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:radius);
bool: Tryg3D::IsPointInRectangle(const Float:px, const Float:py, const Float:minx, const Float:miny, const Float:maxx, const Float:maxy);

# Random Functions
Tryg3D::GetRandomHit(const Float:x, const Float:y, const Float:z, const range, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInCircle(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty);
Tryg3D::GetPointInCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
bool: Tryg3D::GetPointInCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInSphere(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, &Float:tx, &Float:ty);
Tryg3D::GetPointInCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInCone2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, Float:view_angle, &Float:tx, &Float:ty);
Tryg3D::GetPointInSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInEllipse(const Float:cx, const Float:cy, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty);
Tryg3D::GetPointInEllipticalCylinder(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, Float:size_y, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointInPolygon(const Float:points[], &Float:tx, &Float:ty, const max_points = sizeof(points), max_iterations = 10000);
Float: Tryg3D::GetPointOnClock(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty, &Float:trz, Float:rz = TRYG3D_INVALID_ROTATION);
Tryg3D::GetPointOnCircle(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty);
Tryg3D::GetPointOnCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnSphere(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, &Float:tx, &Float:ty);
Tryg3D::GetPointOnCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, Float:view_angle, &Float:tx, &Float:ty);
Tryg3D::GetPointOnSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz, &Float:tx, &Float:ty, &Float:tz);
Tryg3D::GetPointOnEllipse(const Float:cx, const Float:cy, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty);
Tryg3D::GetPointOnEllipticalCyl2D(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y, &Float:tx, &Float:ty, &Float:tz);

# Draw3D Functions
Tryg3D::DrawCircle3D(const Float:x, const Float:y, const Float:z, const Float:radius, Float:points[][3], const max_sector = 36, const Float:rx = 90.0, const Float:ry = 0.0, const max_points = sizeof(points));
Tryg3D::DrawCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points));
Tryg3D::DrawSphere(const Float:x, const Float:y, const Float:z, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points));
Tryg3D::DrawCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points));
Tryg3D::DrawRectangle2D(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, Float:points[][2], const points_per_wall = 36, const max_points = sizeof(points));
Tryg3D::DrawPolygon2D(const Float:polygon_points[], Float:points[][2], const points_per_line = 36, const max_polygon_points = sizeof(polygon_points), const max_points = sizeof(points));
Tryg3D::DrawCube2D(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, Float:points[][3], const points_per_wall = 36, const max_points = sizeof(points));

# Cast3D Functions
Tryg3D::CastExplosion(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0);
Tryg3D::CastExplosionDMG(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0, const Float:damage = 82.5, const Float:vehicle_damage = 82.5, const byplayerid = INVALID_PLAYER_ID, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE);
Tryg3D::CastExplosionRangeDMG(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0, const Float:min_damage = 10.0, const Float:max_damage = 82.5, const Float:min_vehicle_damage = 50.0, const Float:max_vehicle_damage = 250.0, const byplayerid = INVALID_PLAYER_ID, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE);
Tryg3D::CastDamage(const weaponid, const bodypart, const Float:damage, const Float:vehicle_damage, const Float:x, const Float:y, const Float:z, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const byplayerid = INVALID_PLAYER_ID);
Tryg3D::CastGravity(const Float:x, const Float:y, const Float:z, const Float:radius, Float:power = 1.0, const worldid = -1, const interiorid = -1, const playerid = -1, const byplayerid = INVALID_PLAYER_ID);

# Vehicle Functions
Tryg3D::GetVehicleFlags(vehicleid)
Tryg3D::IsVehicleFlag(vehicleid, flag)
Tryg3D::GetVehicleRotation(const vehicleid, &Float:rx, &Float:ry, &Float:rz);
Tryg3D::GetPartPos(const modelid, const partid, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:tx, &Float:ty, &Float:tz, Float:offset_x = 0.0, Float:offset_y = 0.0, Float:offset_z = 0.0);
Tryg3D::GetVehiclePartPos(const vehicleid, const partid, &Float:tx, &Float:ty, &Float:tz, Float:offset_x = 0.0, Float:offset_y = 0.0, Float:offset_z = 0.0);
Tryg3D::GenerateVehicleFlags(const modelid);
Tryg3D::GetVehicleModelDefaultFlags(const modelid);	
Tryg3D::GetVehicleModelFlags(const modelid);
Tryg3D::SetVehicleModelFlags(const modelid, const value);
Tryg3D::ToggleVehicleModelFlag(const modelid, const flag, const bool:toggle);
Tryg3D::IsVehicleInRangeOfPoint(const vehicleid, const Float:range, const Float:x, const Float:y, const Float:z);
Tryg3D::CountVisibleVehicles(const playerid);
Float: Tryg3D::GetVehicleSpeed(const vehicleid);
Tryg3D::SetVehicleSpeed(const vehicleid, const Float:speed);
Float: Tryg3D::GetPointInFrontOfVehicle2D(const vehicleid, &Float:tx, &Float:ty, const Float:radius);
Tryg3D::GetPointInFrontOfVehicle3D(const vehicleid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0);

# Actor Functions
Tryg3D::CountActors();
Tryg3D::CountVisibleActors(playerid);

# Player Functions
bool: Tryg3D::IsPlayerSpawned(const playerid);
bool: Tryg3D::IsPlayerSkydiving(playerid);
bool: Tryg3D::IsPlayerUsingParachute(playerid);
bool: Tryg3D::IsPlayerFall(playerid);
bool: Tryg3D::IsPlayerAiming(playerid);
bool: Tryg3D::IsPlayerStay(playerid);
bool: Tryg3D::IsPlayerSwim(playerid);
bool: Tryg3D::IsPlayerJump(playerid);
bool: Tryg3D::IsPlayerParaFall(playerid);
bool: Tryg3D::IsPlayerParaGlide(playerid);
bool: Tryg3D::IsPlayerRunning(playerid);
Tryg3D::GivePlayerDamage(const targetid, Float:amount, const playerid, const weaponid, const bodypart);
Tryg3D::CountPlayers(const bool:isplayer = true, const bool:isnpc = true);
Tryg3D::CountVisiblePlayers(const playerid, const bool:isplayer = true, const bool:isnpc = true);
Float: Tryg3D::GetPointInFrontOfPlayer(const playerid, &Float:tx, &Float:ty, const Float:radius);
Tryg3D::GetPlayerCameraRotation(const playerid, &Float:rx, &Float:rz);
Tryg3D::GetPlayerCameraZAngle(const playerid, &Float:z_angle);
Float: Tryg3D::GetPointInFrontOfCamera2D(const playerid, &Float:tx, &Float:ty, const Float:radius);
Float: Tryg3D::GetPlayerSpeed(const playerid);
Tryg3D::GetPlayerTargetAngle(const playerid, const Float:x, const Float:y, &Float:rz);
Tryg3D::SetPlayerTargetAngle(const playerid, const Float:x, const Float:y, &Float:rz = 0.0);
Tryg3D::GetPlayerTargetPlayerAngle(const playerid, const targetid, &Float:rz);
Tryg3D::SetPlayerTargetPlayerAngle(const playerid, const targetid, &Float:rz = 0.0);
Tryg3D::GetPointInFrontOfCamera3D(const playerid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0);
Tryg3D::IsPlayerLookAtSky(const playerid);
Tryg3D::IsPlayerFakeSpectating(const playerid, const bool:force_disable = true);
Float: Tryg3D::GetCameraTargetDistance(const Float:CamX, const Float:CamY, const Float:CamZ, const Float:ObjX, const Float:ObjY, const Float:ObjZ, const Float:FrX, const Float:FrY, const Float:FrZ);
Tryg3D::IsPlayerAimingAt(const playerid, const Float:x, const Float:y, const Float:z, const Float:radius);
Tryg3D::GetPlayerCameraLookAt(const playerid, &Float:x, &Float:y, &Float:z);

# Universal Functions
Tryg3D::ItemGetInvalidID(const Item3D:item_type);
bool: Tryg3D::ItemGetPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:x, &Float:y, &Float:z);
Tryg3D::ItemGetVirtualWorld(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type);
Tryg3D::ItemGetInterior(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type);
bool: Tryg3D::ItemGetRotationQuat(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:qw, &Float:qx, &Float:qy, &Float:qz);
bool: Tryg3D::ItemGetUpVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:vx, &Float:vy, &Float:vz);
bool: Tryg3D::ItemGetUpPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:radius, &Float:x, &Float:y, &Float:z, const bool:reverse = false);
bool: Tryg3D::ItemOnPlayerScreen(const playerid, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ElementOrientation:orientation = o_front, const Float:rx = TRYG3D_INVALID_ROTATION, const Float:rz = TRYG3D_INVALID_ROTATION, const Float:vrx = VERTICAL_CAMERA_RADIUS, const Float:vrz = HORIZONTAL_CAMERA_RADIUS, const bool:testVW = true, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT);
bool: Tryg3D::ItemOnFakeScreen(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const Float:rx, const Float:rz, const Float:vrx = VERTICAL_CAMERA_RADIUS, const Float:vrz = HORIZONTAL_CAMERA_RADIUS, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT);
Float: Tryg3D::ItemGetDistance(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type);
Float: Tryg3D::ItemGetDistanceFromPoint(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z);
bool: Tryg3D::ItemInCircle(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:radius);
bool: Tryg3D::ItemInCylinder3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius);
bool: Tryg3D::ItemInCylinder2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius);
bool: Tryg3D::ItemInSphere(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:radius);
bool: Tryg3D::ItemInRectangle(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:minx, const Float:miny, const Float:maxx, const Float:maxy);
bool: Tryg3D::ItemInCube(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:minx, const Float:miny, const Float:minz,Float:maxx, const Float:maxy, const Float:maxz);
bool: Tryg3D::ItemInPolygon(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:points[], const maxpoints = sizeof(points));
bool: Tryg3D::ItemInCircularSector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:rz, const Float:radius, const Float:view_angle);
bool: Tryg3D::ItemInSphericalSector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz);
bool: Tryg3D::ItemInCone2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b);
bool: Tryg3D::ItemInCone3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b);
bool: Tryg3D::ItemInCube3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z);
bool: Tryg3D::ItemInEllipse(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:cx, const Float:cy, const Float:size_x, const Float:size_y);
bool: Tryg3D::ItemInEllipticalCylinder2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y);
bool: Tryg3D::ItemGetToPointVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz);
bool: Tryg3D::ItemGetRotatedVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz, const bool:return_vector = true, const Float:rx = 0.0, const Float:ry = 0.0, const Float:rz = 0.0);
bool: Tryg3D::ItemGetOrientationPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const ElementOrientation:orientation, const Float:distance, &Float:tx, &Float:ty, &Float:tz);
bool: Tryg3D::ItemInRangeOfPoint(const Float:x, const Float:y, const Float:z, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE);
bool: Tryg3D::ItemInRangeOfItem(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE);
bool: Tryg3D::ItemIsPlayerInRange(const playerid, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE);

# Universal Functions (Streamer)
bool: Tryg3D::ItemInDynamicArea(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const STREAMER_TAG_AREA:areaid);
Tryg3D::ItemGetInDynamicArea(const STREAMER_TAG_AREA:areaid, const Item3D:element_type, element_list[], const max_element = sizeof(element_list));

# Universal Functions (ColAndreas)
bool: Tryg3D::ItemCollisionToPoint(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL);
bool: Tryg3D::ItemCollisionToItem(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL);
Tryg3D::ItemToItemIsWall(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type);
Tryg3D::ItemToPointIsWall(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type);
Tryg3D::ItemGetCollisionFlags(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type);
Tryg3D::ItemGetOrientationPosCol(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const ElementOrientation:orientation, const Float:distance, &Float:tx, &Float:ty, &Float:tz);
bool: Tryg3D::ItemIsPointInWaterOrient(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:radius, const ElementOrientation:orientation = o_front);

# Streamer Functions
Tryg3D::SetPlayerAbsolutePosition(const playerid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1);
Tryg3D::SetPlayerAbsolutePositionVeh(const playerid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1);
bool: Tryg3D::IsVehicleFullyInArea(const vehicleid, const STREAMER_TAG_AREA:areaid);
Tryg3D::GetPointInDynamicArea(const STREAMER_TAG_AREA:areaid, &Float:tx, &Float:ty, &Float:tz);

# FCNPC Functions
bool: FCNPC::InRangeOfPoint(const npcid, const Float:range, const Float:x, const Float:y, const Float:z);
Float: FCNPC::GetPointInFront(const npcid, &Float:tx, &Float:ty, const Float:radius);
FCNPC::GetTargetAngle(const npcid, const Float:x, const Float:y, &Float:rz);
FCNPC::SetTargetAngle(const npcid, const Float:x, const Float:y, &Float:rz = 0.0);
FCNPC::SetVehicleRotation(const npcid, const Float:rx, const Float:ry, const Float:rz);
bool: FCNPC::SetVehicleTargetRotation(const npcid, const Float:tx, const Float:ty, const Float:tz, const Float:ry = 0.0);
FCNPC::GoToAir(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const Float:min_distance = 0.0, const stopdelay = 250);
Float: FCNPC::GetPointInFrontCol(const npcid, &Float:tx, &Float:ty, const Float:radius);
FCNPC::GoToCol(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 0.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::GoToPlayerCol(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 0.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::GoToPlayerOnGroundCol(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 1.0, const Float:climbing = 2.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::GoToAirCol(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const Float:cut_size = 0.0, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::SetFloorPos(const npcid);
FCNPC::GoToPlayerOnGroundColVeh(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 1.0, const Float:climbing = 2.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::RandomMoveInDynamicArea(const npcid, const STREAMER_TAG_AREA:areaid, const Float:climbing = 2.0, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250);
FCNPC::SetAbsolutePosition(const npcid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1);

# YSF Functions
Tryg3D::GetPlayerHydraReactorRX(const playerid);
Tryg3D::IsPlayerHydraReactorBoost(const playerid);
Tryg3D::CountTextDraw();
Tryg3D::CountVisibleTextDraw(const playerid);
Tryg3D::CountPlayerTextDraw(const playerid);
Tryg3D::CountVisiblePlayerTextDraw(const playerid);
Tryg3D::CountGangZone();
Tryg3D::CountVisibleGangZone(const playerid);
Tryg3D::CountPlayerGangZone(const playerid);
Tryg3D::CountVisiblePlayerGangZone(const playerid);
bool: Tryg3D::IsVehicleOnSpawn(const vehicleid, const Float:check_radius = 1.0);
bool: Tryg3D::IsPlayerOnSpawn(const playerid, Float:check_radius = 1.0);
Tryg3D::GetPlayerRotation(const playerid, &Float:rx, &Float:ry, &Float:rz);
Tryg3D::GetPointInGangZone(const zoneid, &Float:tx, &Float:ty);
Tryg3D::GetPointInPlayerGangZone(const playerid,zoneid, &Float:tx, &Float:ty);

# CatchItems Functions
Tryg3D::GetStreamType(Stream:data);
Tryg3D::IsValidStream(Stream:data); 
bool: Tryg3D::IsPointInStream(const Float:x, const Float:y, const Float:z, const Stream:AreaData[Stream3D]);
bool: Tryg3D::ItemInStream(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Stream:AreaData[Stream3D], const worldid = -1, const interiorid = -1);
Tryg3D::GetInStream(const Stream:AreaData[Stream3D], const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCircle(const Float:x, const Float:y, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchSphere(const Float:x, const Float:y, const Float:z, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchStreamCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchPolygon(const Float:points[], const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list), const maxpoints = sizeof(points));
Tryg3D::CatchCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, const Float:view_angle, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCone2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:pointA_radius, const Float:pointB_radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchEllipse(const Float:cx,Float:cy, const Float:size_x, const Float:size_y, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchEllipticalCylinder2D(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));
Tryg3D::CatchSphericalSectorEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const Item3D:element_type, element_list[], const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT, const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list));

# Grenade Detection Callbacks
OnPlayerDroppingGrenade(playerid, weaponid, Float:x, Float:y, Float:z);
OnPlayerGrenadeExplode(playerid, weaponid, Float:x, Float:y, Float:z);
 
# VehicleCollision Functions
Tryg3D::IsVehicleCollisionEnabled();
Tryg3D::InitVehicleCollision(); //OnGameModeInit / OnFilterScriptInit
Tryg3D::ExitVehicleCollision();
Tryg3D::SyncVehicleCollision(vehicleid); //EVF -> OnVehicleCreated
bool: Tryg3D::IsToggledVehicleCollision(vehicleid);
Tryg3D::ToggleVehicleCollision(vehicleid, bool:toggle);

# PlayerCollision Functions
Tryg3D::IsPlayerCollisionEnabled();
Tryg3D::InitPlayerCollision(); //OnGameModeInit / OnFilterScriptInit
Tryg3D::ExitPlayerCollision();
Tryg3D::SyncPlayerCollision(playerid); //auto called after player spawn
bool: Tryg3D::IsToggledPlayerCollision(playerid);
Tryg3D::TogglePlayerCollision(playerid, bool:toggle);

# ActorCollision Functions
Tryg3D::IsActorCollisionEnabled();
Tryg3D::InitActorCollision(); //OnGameModeInit / OnFilterScriptInit
Tryg3D::ExitActorCollision();
Tryg3D::SyncActorCollision(actorid); //After create/change actor position
bool: Tryg3D::IsToggledActorCollision(actorid);
Tryg3D::ToggleActorCollision(actorid, bool:toggle);

# Definitions
TRYG3D_ELEMENT_TAG
FLOAT_PI
FLOAT_EULER
FLOAT_NAN
FLOAT_DEFECT
FLOAT_INFINITY
VERTICAL_CAMERA_RADIUS
HORIZONTAL_CAMERA_RADIUS

C_IN_GAME_X
C_IN_GAME_Y
C_IN_GAME_YW
C_ON_SCREEN_X
C_ON_SCREEN_Y

TRYG3D_MAX_POLYGON_POINTS
TRYG3D_VEHICLE_SPEED_MULTIPLIER
TRYG3D_PLAYER_SPEED_MULTIPLIER
TRYG3D_DEFAULT_RANDOM_ACCURACY
TRYG3D_CHARACTER_GROUND_Z_DIFF
TRYG3D_MAX_AREA_CHECK
TRYG3D_INVALID_ROTATION
TRYG3D_INVALID_VIRTUAL_WORLD
TRYG3D_INVALID_MOVE_TIME
TRYG3D_INVALID_MOVE_SPEED
TRYG3D_INVALID_ORIENTATION
TRYG3D_MAX_MODULES_STRING
TRYG3D_RANDOM_MAX_ANGLE
TRYG3D_VBTP
TRYG3D_VLTP

TRYG3D_EXTRA_DATA_FLAG_VEHICLE
TRYG3D_EXTRA_DATA_FLAG_PLAYER
TRYG3D_EXTRA_DATA_FLAG_ACTOR

WEAPON_DYNAMIC_EXPLOSION_DMG
WEAPON_DYNAMIC_EXPLOSION_RANGE

//ColAndreas collision flags
TRYG3D_COLLISION_FLAG_NONE, TRYG3D_COLLISION_FLAG_OBJECT, TRYG3D_COLLISION_FLAG_VEHICLE, TRYG3D_COLLISION_FLAG_PLAYER, TRYG3D_COLLISION_FLAG_ACTOR, TRYG3D_COLLISION_FLAG_ALL

//Player position flags
POSITION_FLAG_WORLD, POSITION_FLAG_INTERIOR, POSITION_FLAG_AIR, POSITION_FLAG_GROUND, POSITION_FLAG_WATER, POSITION_FLAG_UNDERWATER, POSITION_FLAG_UNDERGROUND

//Vehicle flags
VF_STREET, VF_AIRBORNE, VF_NATATORIAL, VF_MILITARY, VF_TRAIN, VF_RC, VF_CARRIAGE, VF_AIRPLANE, VF_HELICOPTER, VF_BIKES, VF_TRAILER, VF_TOWABLE, VF_POLICE

// Vehicle parts
VEHICLE_PART_RFTIRE    // Right Front tire
VEHICLE_PART_LFTIRE    // Left Front tire
VEHICLE_PART_RRTIRE    // Right Rear tire
VEHICLE_PART_LRTIRE    // Left Rear tire
VEHICLE_PART_HOOD      // In Front
VEHICLE_PART_TRUNK     // Behind
VEHICLE_PART_ROOF      // Roof
VEHICLE_PART_CHASSIS   // Chassis
VEHICLE_PART_PETROLCAP // Petrolcap

# Enums

enum 'EulerModes'
- T3D:euler_xzx
- T3D:euler_xyx
- T3D:euler_yxy
- T3D:euler_yzy
- T3D:euler_zyz
- T3D:euler_zxz
- T3D:euler_xzy
- T3D:euler_xyz
- T3D:euler_yxz
- T3D:euler_yzx
- T3D:euler_zyx
- T3D:euler_zxy

enum 'OrientationCube3D'
- o_left_back_down
- o_right_back_down
- o_right_front_down
- o_left_front_down
- o_left_back_up
- o_right_back_up
- o_right_front_up
- o_left_front_up

enum 'ElementOrientation'
- o_left
- o_right
- o_up
- o_down
- o_front
- o_back
- o_front_left
- o_front_right
- o_back_left
- o_back_right

enum 'Vectors3D'
- Float: T3D:X             - Position X
- Float: T3D:Y             - Position Y
- Float: T3D:Z             - Position Z
- Float: T3D:A             - Angle

enum 'Float3D'
- Float: T3D:X             - Position X
- Float: T3D:Y             - Position Y
- Float: T3D:Z             - Position Z
- Float: T3D:rX            - Rotation X
- Float: T3D:rY            - Rotation Y
- Float: T3D:rZ            - Rotation Z
- Float: T3D:tX            - Target Position X
- Float: T3D:tY            - Target Position Y
- Float: T3D:tZ            - Target Position Z
-        T3D:VW            - Virtual World ID
-        T3D:INT           - Interior ID
- Float: T3D:SPEED         - Speed

enum 'LongFloat3D'
- Float: T3D:X             - Position X
- Float: T3D:Y             - Position Y
- Float: T3D:Z             - Position Z
- Float: T3D:rX            - Rotation X
- Float: T3D:rY            - Rotation Y
- Float: T3D:rZ            - Rotation Z
- Float: T3D:tX            - Target Position X
- Float: T3D:tY            - Target Position Y
- Float: T3D:tZ            - Target Position Z
- Float: T3D:trX           - Target Rotation X
- Float: T3D:trY           - Target Rotation Y
- Float: T3D:trZ           - Target Rotation Z
- Float: T3D:VecX          - Vector Position X
- Float: T3D:VecY          - Vector Position Y
- Float: T3D:VecZ          - Vector Position Z
-        T3D:VW            - Virtual World ID
-        T3D:INT           - Interior ID
- Float: T3D:SPEED         - Speed

enum 'LootArray'
-        ItemID
- Float: ItemChance

enum 'Item3D'
- item_player
- item_npc
- item_actor
- item_object
- item_vehicle
- item_dynamic_object
- item_dynamic_pickup
- item_dynamic_cp
- item_dynamic_racecp
- item_dynamic_mapicon
- item_dynamic_3dtext
- item_dynamic_actor
- item_dynamic_vehicle
- item_fcnpc

enum 'StreamType'
- s_invalid
- s_circle
- s_cylinder2d
- s_cylinder3d
- s_sphere
- s_rectangle
- s_cube2d
- s_cube3d
- s_polygon
- s_circularsector
- s_sphericalsector
- s_cone2d
- s_cone3d
- s_ellipse
- s_ellipticalcyl2d
- a_sphericalsectorex

*/

/********************************
 * Version Check Example        *
 ********************************/

/*
//Check Version 3DTryg.inc
#if !defined TRYG3D_REMASTERED_INCLUDE
	#error [ADM] This include required 3DTryg.inc Gen. 2 v1.0.2
#elseif !defined TRYG3D_VERSION
	#error [ADM] Update your 3DTryg.inc to Gen. 2 v1.0.2
#elseif (TRYG3D_VERSION < 10002)
	#error [ADM] Update your 3DTryg.inc to Gen. 2 v1.0.2
#endif
*/

/********************************
 * Version                      *
 ********************************/

#if (defined TRYG3D_SAMP_INCLUDE) || (defined _3D_Tryg)
	#error [ADM] Trying to include 3DTryg.inc Gen. 2 with already included 3DTryg.inc Gen. 1
#endif

#if defined TRYG3D_REMASTERED_INCLUDE
	#endinput
#endif
#define TRYG3D_REMASTERED_INCLUDE

#define TRYG3D_VERSION                                  (10002) //a.b.c g+10000*a+100*b+c
#define TRYG3D_LIBRARY_NAME                             "3DTryg"
#define TRYG3D_AUTHOR_NAME                              "Abyss Morgan"

#define TRYG3D_PLATFORM_PAWN                            0x01
#define TRYG3D_PLATFORM_SAMP                            0x02

#if defined _samp_included
	#if (!defined GetPlayerPoolSize || !defined GetSVarInt)
		#error [ADM] This include requires SA:MP version 0.3.7
	#endif
	
	#define TRYG3D_PLATFORM_NAME                        "SA:MP"
	#if defined GetPlayerCustomSkin
		#define TRYG3D_PLATFORM_VERSION                 "0.3 DL"
	#else
		#define TRYG3D_PLATFORM_VERSION                 "0.3.7"
	#endif
	
	#define TRYG3D_PLATFORM_CODE                        TRYG3D_PLATFORM_SAMP
#endif

#if !defined TRYG3D_PLATFORM_CODE
	#define TRYG3D_PLATFORM_CODE                        TRYG3D_PLATFORM_PAWN
	#define TRYG3D_PLATFORM_NAME                        "Pawn"
	#define TRYG3D_PLATFORM_VERSION                     "3.0"
#endif

#define Tryg3D::                                        T3_
#define ColAndreas::									CA_
#define FCNPC::											FCNPC_
#define Streamer::										Streamer_

#define T3D:                                            v3D
#define v3Dfunction%0(%1)                               forward %0(%1); public %0(%1)

/********************************
 * Modules                      *
 ********************************/

#if defined TRYG3D_MOD_PLAYER
    #error [ADM] Module already defined: TRYG3D_MOD_PLAYER
#endif
#if defined TRYG3D_ENABLE_PLAYER
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable Player Module without initialized SA:MP Platform
	#else
		#define TRYG3D_MOD_PLAYER "Player"
	#endif
#endif

#if defined TRYG3D_MOD_VEHICLE
    #error [ADM] Module already defined: TRYG3D_MOD_VEHICLE
#endif
#if defined TRYG3D_ENABLE_VEHICLE
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable Vehicle Module without initialized SA:MP Platform
	#else
		#define TRYG3D_MOD_VEHICLE "Vehicle"
	#endif
#endif

//Detect foreach
#if defined _FoX_Foreach
	#define T3_Foreach(%0) FoxForeach(%0,Character)
	#define TRYG3D_MOD_FOREACH_FOX "foreach:fox"
#elseif defined _FOREACH_LOCAL_VERSION
	#define T3_Foreach(%0) foreach(new %0 : Character)
	#define TRYG3D_MOD_FOREACH_STANDALONE "foreach:standalone"
#elseif defined _Y_ITERATE_LOCAL_VERSION
	#define T3_Foreach(%0) foreach(new %0 : Character)
	#define TRYG3D_MOD_FOREACH_YSI "foreach:ysi"
#else
	#define T3_Foreach(%0) for(new %0 = 0, p_%0 = GetPlayerPoolSize(); %0 <= p_%0; %0++) if(IsPlayerConnected(%0))
#endif

//Detect SA:MP ColAndreas Plugin
#if defined TRYG3D_MOD_COLANDREAS
    #error [ADM] Module already defined: TRYG3D_MOD_COLANDREAS
#endif
#if defined TRYG3D_ENABLE_COLANDREAS
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable ColAndreas Module without initialized SA:MP Platform
	#elseif !defined _colandreas_included
		#error [ADM] Trying to enable ColAndreas Module without ColAndreas
	#else
		#define TRYG3D_MOD_COLANDREAS "ColAndreas v1.5.0"
		#define TRYG3D_VER_COLANDREAS (10500)
		#if !defined COLANDREAS_VERSION
			#error [ADM] Update your ColAndreas to v1.5.0 (github.com/Pottus/ColAndreas/releases)
		#elseif COLANDREAS_VERSION < TRYG3D_VER_COLANDREAS
			#error [ADM] Update your ColAndreas to v1.5.0 (github.com/Pottus/ColAndreas/releases)
		#endif
	#endif
#endif

//Detect SA:MP Streamer Plugin
#if defined TRYG3D_MOD_STREAMER
    #error [ADM] Module already defined: TRYG3D_MOD_STREAMER
#endif
#if defined TRYG3D_ENABLE_STREAMER
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable Streamer Module without initialized SA:MP Platform
	#elseif !defined Streamer_AppendArrayData
		#error [ADM] Trying to enable Streamer Module without Streamer
	#else
		#define TRYG3D_MOD_STREAMER "Streamer v2.9.5"
		#define TRYG3D_VER_STREAMER (0x295)
		#if ((!defined Streamer_GetItemPos) || (!defined INVALID_STREAMER_ID) || (!defined STREAMER_TYPE_ACTOR) || (!defined RemoveDynamicObjectMaterialText))
			#error [ADM] Update your Streamer to v2.9.5 (github.com/samp-incognito/samp-streamer-plugin/releases)
		#endif
	#endif
#endif

//Detect SA:MP FCNPC Plugin
#if defined TRYG3D_MOD_FCNPC
    #error [ADM] Module already defined: TRYG3D_MOD_FCNPC
#endif
#if defined TRYG3D_ENABLE_FCNPC
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable FCNPC Module without initialized SA:MP Platform
	#elseif !defined _FCNPC_included
		#error [ADM] Trying to enable FCNPC Module without FCNPC
	#else
		#define TRYG3D_MOD_FCNPC "FCNPC v2.0.0"
		#define TRYG3D_VER_FCNPC (200)
		#if !defined FCNPC_INCLUDE_VERSION
			#error [ADM] Update your FCNPC to v2.0.0 (github.com/ziggi/FCNPC/releases)
		#elseif (FCNPC_INCLUDE_VERSION < TRYG3D_VER_FCNPC)
			#error [ADM] Update your FCNPC to v2.0.0 (github.com/ziggi/FCNPC/releases)
		#endif
	#endif
#endif

//Detect SA:MP YSF Plugin
#if defined TRYG3D_MOD_YSF
    #error [ADM] Module already defined: TRYG3D_MOD_YSF
#endif
#if defined TRYG3D_ENABLE_YSF
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable YSF Module without initialized SA:MP Platform
	#elseif !defined _YSF_included
		#error [ADM] Trying to enable YSF Module without YSF
	#else
		#define TRYG3D_MOD_YSF "YSF R19"
		#if (!defined RemovePlayerForPlayer)
			#error [ADM] Update your YSF to R19 (github.com/kurta999/YSF/releases)
		#endif
	#endif
#endif

//Detect Actor Module
#if defined TRYG3D_MOD_ACTOR
    #error [ADM] Module already defined: TRYG3D_MOD_ACTOR
#endif
#if defined TRYG3D_ENABLE_ACTOR
	#if TRYG3D_PLATFORM_CODE != TRYG3D_PLATFORM_SAMP
		#error [ADM] Trying to enable Actor Module without initialized SA:MP Platform
	#elseif defined _actor_included
		#define TRYG3D_MOD_ACTOR "Actor"
	#endif
#endif

//Detect Grenade Module
#if defined TRYG3D_MOD_GRENADEDETECTION
    #error [ADM] Module already defined: TRYG3D_MOD_GRENADEDETECTION
#endif
#if defined TRYG3D_ENABLE_GRENADEDETECTION
	#if !defined TRYG3D_MOD_PLAYER
		#error [ADM] Trying to enable Grenade Detection without Player Module
	#elseif !defined TRYG3D_MOD_COLANDREAS
		#error [ADM] Trying to enable Grenade Detection without ColAndreas Module
	#else
		#define TRYG3D_MOD_GRENADEDETECTION "GrenadeDetection"
	#endif
#endif

//Detect VehicleCollision Modules
#if defined TRYG3D_MOD_VEHICLECOLLISION
    #error [ADM] Module already defined: TRYG3D_MOD_VEHICLECOLLISION
#endif
#if defined TRYG3D_ENABLE_VEHICLECOL
	#if !defined TRYG3D_MOD_STREAMER
		#error [ADM] Trying to enable VehicleCollision Module without Streamer Module
	#elseif !defined TRYG3D_MOD_COLANDREAS
		#error [ADM] Trying to enable VehicleCollision Module without ColAndreas Module
	#else
		#define TRYG3D_MOD_VEHICLECOLLISION "VehicleCollision"
	#endif
#endif

//Detect PlayerCollision Module
#if defined TRYG3D_MOD_PLAYERCOLLISION
    #error [ADM] Module already defined: TRYG3D_MOD_PLAYERCOLLISION
#endif
#if defined TRYG3D_ENABLE_PLAYERCOL
	#if !defined TRYG3D_MOD_STREAMER
		#error [ADM] Trying to enable PlayerCollision Module without Streamer Module
	#elseif !defined TRYG3D_MOD_COLANDREAS
		#error [ADM] Trying to enable PlayerCollision Module without ColAndreas Module
	#else
		#define TRYG3D_MOD_PLAYERCOLLISION "PlayerCollision"
	#endif
#endif

//Detect ActorCollision Module
#if defined TRYG3D_MOD_ACTORCOLLISION
    #error [ADM] Module already defined: TRYG3D_MOD_ACTORCOLLISION
#endif
#if defined TRYG3D_ENABLE_ACTORCOL
	#if !defined TRYG3D_MOD_ACTOR
		#error [ADM] Trying to enable ActorCollision Module without Actor Module
	#elseif !defined TRYG3D_MOD_STREAMER
		#error [ADM] Trying to enable ActorCollision Module without Streamer Module
	#elseif !defined TRYG3D_MOD_COLANDREAS
		#error [ADM] Trying to enable ActorCollision Module without ColAndreas Module
	#else
		#define TRYG3D_MOD_ACTORCOLLISION "ActorCollision"
	#endif
#endif

//Detect Universal Module
#if defined TRYG3D_MOD_UNIVERSAL
    #error [ADM] Module already defined: TRYG3D_MOD_UNIVERSAL
#endif
#if defined TRYG3D_ENABLE_UNIVERSAL
	#if !defined TRYG3D_MOD_PLAYER && !defined TRYG3D_MOD_VEHICLE && !defined TRYG3D_MOD_ACTOR && !defined TRYG3D_MOD_STREAMER && !defined TRYG3D_MOD_FCNPC
		#error [ADM] Trying to enable Universal Module without initialized any of supported elements
	#else
		#define TRYG3D_MOD_UNIVERSAL "Universal"
	#endif
#endif

//Detect Draw3D Module
#if defined TRYG3D_MOD_DRAW3D
    #error [ADM] Module already defined: TRYG3D_MOD_DRAW3D
#endif
#if defined TRYG3D_ENABLE_DRAW3D
	#define TRYG3D_MOD_DRAW3D "Draw3D"
#endif

//Detect Cast3D Module
#if defined TRYG3D_MOD_CAST3D
    #error [ADM] Module already defined: TRYG3D_MOD_CAST3D
#endif
#if defined TRYG3D_ENABLE_CAST3D
	#if !defined TRYG3D_MOD_UNIVERSAL
		#error [ADM] Trying to enable Cast3D Module without Universal Module
	#else
		#define TRYG3D_MOD_CAST3D "Cast3D"
	#endif
#endif

//Detect CatchItems Module
#if defined TRYG3D_MOD_CATCHITEMS
    #error [ADM] Module already defined: TRYG3D_MOD_CATCHITEMS
#endif
#if defined TRYG3D_ENABLE_CATCHITEMS
	#if !defined TRYG3D_MOD_UNIVERSAL
		#error [ADM] Trying to enable CatchItems Module without Universal Module
	#else
		#define TRYG3D_MOD_CATCHITEMS "CatchItems"
	#endif
#endif
 
/********************************
 * Definitions                  *
 ********************************/
 
#if !defined TRYG3D_ELEMENT_TAG
	#define TRYG3D_ELEMENT_TAG							{Text3D,DynamicObject,DynamicPickup,DynamicCP,DynamicRaceCP,DynamicMapIcon,DynamicText3D,DynamicArea,DynamicActor,_}
#endif

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
    #define VERTICAL_CAMERA_RADIUS                      (56.0)
#endif

#if !defined HORIZONTAL_CAMERA_RADIUS
    #define HORIZONTAL_CAMERA_RADIUS                    (86.0)
#endif

#if !defined TRYG3D_MAX_AREA_CHECK
    #define TRYG3D_MAX_AREA_CHECK                       (256)
#endif
#if TRYG3D_MAX_AREA_CHECK < 32
    #error [ADM] Definition TRYG3D_MAX_AREA_CHECK must be greater or equal than 32
#endif

#if !defined C_IN_GAME_X
	#define C_IN_GAME_X                                 (0.7)
#endif

#if !defined C_IN_GAME_Y
	#define C_IN_GAME_Y                                 (0.525)
#endif

#if !defined C_IN_GAME_YW
	#define C_IN_GAME_YW                                (0.4) // Widescreen
#endif

#if !defined C_ON_SCREEN_X
	#define C_ON_SCREEN_X                               (640.0)
#endif

#if !defined C_ON_SCREEN_Y
	#define C_ON_SCREEN_Y                               (448.0)
#endif

#define TRYG3D_INVALID_ROTATION                         (-1000.0)
#define TRYG3D_INVALID_VIRTUAL_WORLD                    (-2000)
#define TRYG3D_INVALID_MOVE_TIME                        (-1)
#define TRYG3D_INVALID_MOVE_SPEED                       (-1.0)
#define TRYG3D_INVALID_ORIENTATION                      (-1)
#define TRYG3D_MAX_MODULES_STRING                       (600)
#define TRYG3D_RANDOM_MAX_ANGLE                         (359.999999)
#define TRYG3D_VBTP                                     (0x7FFFFFFF)
#define TRYG3D_VLTP                                     (0x80000000)

#define TRYG3D_EXTRA_DATA_FLAG_VEHICLE                  (0xBABA0001)
#define TRYG3D_EXTRA_DATA_FLAG_PLAYER                   (0xBABA0002)
#define TRYG3D_EXTRA_DATA_FLAG_ACTOR                    (0xBABA0003)

#define WEAPON_DYNAMIC_EXPLOSION_DMG                    (109)
#define WEAPON_DYNAMIC_EXPLOSION_RANGE                  (110)

#define TRYG3D_COLLISION_FLAG_NONE                      (0b0000000000000000)
#define TRYG3D_COLLISION_FLAG_OBJECT                    (0b0000000000000001)
#define TRYG3D_COLLISION_FLAG_VEHICLE                   (0b0000000000000010)
#define TRYG3D_COLLISION_FLAG_PLAYER                    (0b0000000000000100)
#define TRYG3D_COLLISION_FLAG_ACTOR                     (0b0000000000001000)
#define TRYG3D_COLLISION_FLAG_ALL                       (0b0000000000001111)

//Player Position Flag
#if defined TRYG3D_MOD_COLANDREAS
	#define POSITION_FLAG_WORLD                         (0b0000000000000001)
	#define POSITION_FLAG_INTERIOR                      (0b0000000000000010)
	#define POSITION_FLAG_AIR                           (0b0000000000000100)
	#define POSITION_FLAG_GROUND                        (0b0000000000001000)
	#define POSITION_FLAG_WATER                         (0b0000000000010000)
	#define POSITION_FLAG_UNDERWATER                    (0b0000000000100000)
	#define POSITION_FLAG_UNDERGROUND                   (0b0000000001000000)
#endif

#if defined TRYG3D_MOD_VEHICLE
	
	//Vehicle Flags
	#define VF_STREET                                   (0b0000000000000001)
	#define VF_AIRBORNE                                 (0b0000000000000010)
	#define VF_NATATORIAL                               (0b0000000000000100)
	#define VF_MILITARY                                 (0b0000000000001000)
	#define VF_TRAIN                                    (0b0000000000010000)
	#define VF_RC                                       (0b0000000000100000)
	#define VF_CARRIAGE                                 (0b0000000001000000)
	#define VF_AIRPLANE                                 (0b0000000010000000)
	#define VF_HELICOPTER                               (0b0000000100000000)
	#define VF_BIKES                                    (0b0000001000000000)
	#define VF_TRAILER                                  (0b0000010000000000)
	#define VF_TOWABLE                                  (0b0000100000000000)
	#define VF_POLICE                                   (0b0001000000000000)

	#if !defined VEHICLE_PART_RFTIRE
		#define VEHICLE_PART_RFTIRE                     (1) // Right Front tire
		#define VEHICLE_PART_LFTIRE                     (2) // Left Front tire
		#define VEHICLE_PART_RRTIRE                     (3) // Right Rear tire
		#define VEHICLE_PART_LRTIRE                     (4) // Left Rear tire
		#define VEHICLE_PART_HOOD                       (5) // In Front
		#define VEHICLE_PART_TRUNK                      (6) // Behind
	#endif

	#define VEHICLE_PART_ROOF                           (7) // Roof
	#define VEHICLE_PART_CHASSIS                        (8) // Chassis
	#define VEHICLE_PART_PETROLCAP                      (9) // Petrolcap
	
#endif

/********************************
 * Enums                        *
 ********************************/
 
enum EulerModes {
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

enum OrientationCube3D {
	o_left_back_down,
	o_right_back_down,
	o_right_front_down,
	o_left_front_down,
	o_left_back_up,
	o_right_back_up,
	o_right_front_up,
	o_left_front_up
}

enum ElementOrientation {
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

enum LootArray {
	ItemID,
	Float:ItemChance
}

enum Item3D {
	item_player,
	item_npc,
	item_actor,
	item_object,
	item_vehicle,
	item_dynamic_object,
	item_dynamic_pickup,
	item_dynamic_cp,
	item_dynamic_racecp,
	item_dynamic_mapicon,
	item_dynamic_3dtext,
	item_dynamic_actor,
	item_dynamic_vehicle,
	item_fcnpc
}

#if defined TRYG3D_MOD_CATCHITEMS
	enum StreamType {
		s_invalid,
		s_circle,
		s_cylinder2d,
		s_cylinder3d,
		s_sphere,
		s_rectangle,
		s_cube2d,
		s_cube3d,
		s_polygon,
		s_circularsector,
		s_sphericalsector,
		s_cone2d,
		s_cone3d,
		s_ellipse,
		s_ellipticalcyl2d,
		a_sphericalsectorex
	}

	enum Stream3D {
		StreamType:	T3D:type,
		Float:		T3D:Poly[TRYG3D_MAX_POLYGON_POINTS * 2],
					T3D:INT,
					T3D:VW
	}
#endif

/********************************
 * Variables                    *
 ********************************/
 
new const Float: Tryg3D::WeaponDamage[] = {
	1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,82.5,0.0,1.0,9.9,46.2,0.0,8.25,13.2,46.2,3.3,3.3,4.95,6.6,8.25,
	9.9,9.9,6.6,24.75,41.25,82.5,82.5,1.0,46.2,82.5,0.0,0.33,0.33,0.0,0.0,0.0,0.0,0.0,2.64,9.9,330.0,82.5,1.0,1.0,165.0
};

const EulerModes: T3D:euler_default = T3D:euler_zxy;

new Float: Tryg3D::StreamDistance = 300.0,
	Tryg3D::ErrorLevel = 0,
	Tryg3D::UpTime = 0;
	
#if defined TRYG3D_MOD_PLAYER
	new Tryg3D::DeatchTick[MAX_PLAYERS];
#endif

#if defined TRYG3D_MOD_GRENADEDETECTION
	new Tryg3D::ExplosionTime = 2200;
#endif

#if defined TRYG3D_MOD_VEHICLE
	//Values getting from GenerateVehicleDefaultFlags
	new const Tryg3D::VehicleFlagsDefault[212] = {
		2049,2049,2049,1,2049,2049,1,4097,1,2049,2049,2049,2049,2049,2049,2049,6145,258,2049,2049,2049,2049,2049,2049,2049,266,2049,6145,2049,2049,4,1,9,1,2049,1025,2049,1,2049,2049,2049,33,2049,
		1,2049,2049,4,262,513,17,3073,2049,4,4,4,2049,2049,2049,2049,2049,134,513,513,513,33,33,2049,2049,513,258,2049,513,4,4,2049,2049,130,2049,2049,2049,2049,513,2049,2049,4,2049,2049,258,258,
		2049,6145,2049,2049,4,2049,2049,2049,258,2049,2049,2049,33,2049,2049,2049,2049,2049,2049,2049,513,513,130,130,130,1,1,2049,2049,2049,130,138,513,513,4609,1,2049,2049,2049,2049,2049,2049,
		2049,1,2049,2049,2049,2049,17,17,7,2049,2049,2049,2049,4097,2049,2049,2049,258,2049,2049,2049,2049,130,2049,2049,2049,2049,2049,2049,2049,2049,2049,258,33,2049,2049,2049,2049,65,65,2049,
		2049,2049,2049,2049,2049,130,2049,2049,2049,513,2049,2049,3073,2049,513,2049,2049,2049,3137,3073,130,130,33,4,6145,6145,6145,6145,2049,2049,2049,2049,2049,2049,3073,3073,3073,2049,3073,3073
	};

	new Tryg3D::VehicleFlagsCurrent[212] = {
		2049,2049,2049,1,2049,2049,1,4097,1,2049,2049,2049,2049,2049,2049,2049,6145,258,2049,2049,2049,2049,2049,2049,2049,266,2049,6145,2049,2049,4,1,9,1,2049,1025,2049,1,2049,2049,2049,33,2049,
		1,2049,2049,4,262,513,17,3073,2049,4,4,4,2049,2049,2049,2049,2049,134,513,513,513,33,33,2049,2049,513,258,2049,513,4,4,2049,2049,130,2049,2049,2049,2049,513,2049,2049,4,2049,2049,258,258,
		2049,6145,2049,2049,4,2049,2049,2049,258,2049,2049,2049,33,2049,2049,2049,2049,2049,2049,2049,513,513,130,130,130,1,1,2049,2049,2049,130,138,513,513,4609,1,2049,2049,2049,2049,2049,2049,
		2049,1,2049,2049,2049,2049,17,17,7,2049,2049,2049,2049,4097,2049,2049,2049,258,2049,2049,2049,2049,130,2049,2049,2049,2049,2049,2049,2049,2049,2049,258,33,2049,2049,2049,2049,65,65,2049,
		2049,2049,2049,2049,2049,130,2049,2049,2049,513,2049,2049,3073,2049,513,2049,2049,2049,3137,3073,130,130,33,4,6145,6145,6145,6145,2049,2049,2049,2049,2049,2049,3073,3073,3073,2049,3073,3073
	};
#endif

static const Float: Tryg3D::Cube3DOffset[OrientationCube3D][3] = {
	{-1.0,-1.0,-1.0},	//left - back - down
	{1.0,-1.0,-1.0},	//right - back - down
	{1.0,1.0,-1.0},		//right - front - down
	{-1.0,1.0,-1.0},	//left - front - down
	{-1.0,-1.0,1.0},	//left - back - up
	{1.0,-1.0,1.0},		//right - back - up
	{1.0,1.0,1.0},		//right - front - up
	{-1.0,1.0,1.0}		//left - front - up
};

new const Float: Tryg3D::OrientationRotation[ElementOrientation][2] = {
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

#if defined TRYG3D_MOD_PLAYERCOLLISION

	new STREAMER_TAG_AREA: Tryg3D::PlayerCollisionZone[MAX_PLAYERS],
		bool: Tryg3D::PlayerCollisionUsed[MAX_PLAYERS],
		bool: Tryg3D::PlayerCollisionSystem = false;

#endif

#if defined TRYG3D_MOD_VEHICLECOLLISION

	new STREAMER_TAG_AREA: Tryg3D::VehicleCollisionZone[MAX_VEHICLES],
		bool: Tryg3D::VehicleCollisionUsed[MAX_VEHICLES],
		bool: Tryg3D::VehicleCollisionSystem = false;

#endif

#if defined TRYG3D_MOD_ACTORCOLLISION

	new STREAMER_TAG_AREA: Tryg3D::ActorCollisionZone[MAX_ACTORS],
		bool: Tryg3D::ActorCollisionUsed[MAX_ACTORS],
		bool: Tryg3D::ActorCollisionSystem = false;

#endif
/********************************
 * Complementary Functions      *
 ********************************/

#define abs(%0)                                 (((%0) < 0)?(-(%0)):((%0)))
#define fabs(%0)                                (((%0) < 0.0)?(-(%0)):((%0)))
#define sqrtN(%0,%1)                            floatpower((%0),(1.0/(%1)))

#if !defined IsEven
	#define IsEven(%0)                          ((((%0) % 2) == 0)?(true):(false))
#endif

#define power(%0,%1)                            (floatround(floatpower((%0),(%1))))

/********************************
 * Platform Functions           *
 ********************************/

#if TRYG3D_PLATFORM_CODE == TRYG3D_PLATFORM_PAWN
	stock Float: VectorSize(const Float:x, const Float:y, const Float:z){
		return floatsqroot(floatpower(x,2.0)+floatpower(y,2.0)+floatpower(z,2.0));
	}
#endif

#if TRYG3D_PLATFORM_CODE == TRYG3D_PLATFORM_SAMP

	#if !defined isnull
		#define isnull(%1) 									((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
	#endif

	#if !defined CreateExplosionForPlayer
		native CreateExplosionForPlayer(playerid,Float:X,Float:Y,Float:Z,type,Float:Radius);
	#endif

	#if !defined IsValidVehicle
		native IsValidVehicle(vehicleid);
	#endif
	
#endif

/********************************
 * Internal Functions           *
 ********************************/

#define T3_SingleClock(%1,%2)                   ((360.0/(%1))*(%2))
#define T3_EvenClock(%1,%2)                     ((360.0/(%1))*(2*(%2)))
#define T3_UnevenClock(%1,%2)                   ((360.0/(%1))*((2*(%2))-1))

#define T3_NLTZ(%0)                             (((%0) < 0)?(0):(%0))
#define T3_NMTZ(%0)                             (((%0) > 0)?(0):(%0))
#define T3_NLTZF(%0)                            (((%0) < 0.0)?(0.0):(%0))
#define T3_NMTZF(%0)                            (((%0) > 0.0)?(0.0):(%0))

#define T3_NLTV(%0,%1)                          (((%0) < (%1))?(%1):(%0))
#define T3_NMTV(%0,%1)                          (((%0) > (%1))?(%1):(%0))
#define T3_NLTVF(%0,%1)                         (((%0) < (%1))?(%1):(%0))
#define T3_NMTVF(%0,%1)                         (((%0) > (%1))?(%1):(%0))

#define T3_GetWeaponDamage(%0)                  Tryg3D::WeaponDamage[(%0)]
#define T3_RoundAccuracy(%0)                    (floatround((%0)*10000.0)/10000.0)
#define T3_AppendLineArguments2D(%0,%1,%2)      %0[0] = (%1), %0[0] = (%2)
#define T3_AppendLineArguments3D(%0,%1,%2,%3)   %0[0] = (%1), %0[0] = (%2), %0[0] = (%3)
#define T3_DivideValues(%0,%1,%2,%3)            ((%1) /= (%0)), ((%2) /= (%0)), ((%3) /= (%0))
#define T3_RecoilFloat(%0,%1)                   (((%0) >= 0.0)?((%0)+(%1)):((%0)-(%1)))

#define T3_GetActiveTime()                      (GetTickCount()-Tryg3D::UpTime)
#define T3_GetVersion(%0)                       ((%0) / 10000),(((%0) % 10000) / 100),(((%0) % 10000) % 100)

#define T3_GetErrorCount()                      Tryg3D::ErrorLevel
#define T3_ResetErrorCount()                    Tryg3D::ErrorLevel = 0
#define T3_UpdateErrorCount()                   Tryg3D::ErrorLevel++

#define T3_SetStreamDistance(%0)                Tryg3D::StreamDistance = (%0)
#define T3_GetStreamDistance()                  Tryg3D::StreamDistance

#define T3_KeyPressed(%0)                       (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))
#define T3_KeyReleased(%0)                      (((newkeys & (%0)) != (%0)) && ((oldkeys & (%0)) == (%0)))
#define T3_KeyHolding(%0)                       ((newkeys & (%0)) == (%0))

//%d:%02d:%02d:%02d
#define T3_SecToTimeDay(%0)                     ((%0) / 86400),(((%0) % 86400) / 3600),((((%0) % 86400) % 3600) / 60),((((%0) % 86400) % 3600) % 60)
#define T3_MSToTimeDay(%0)                      Tryg3D::SecToTimeDay((%0)/1000)
//%02d:%02d:%02d
#define T3_SecToTime(%0)                        ((%0) / 3600),(((%0) % 3600) / 60),(((%0) % 3600) % 60)
#define T3_MSToTime(%0)                         Tryg3D::SecToTime((%0)/1000)
//%02d:%02d
#define T3_SecToTimeMini(%0)                    ((%0) / 60),((%0) % 60)
#define T3_MSToTimeMini(%0)                     Tryg3D::SecToTimeMini((%0)/1000)

//Author: hesambia random.inc, modified by Abyss Morgan
stock Float: Tryg3D::RandomFloat(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	if(min >= max) return 0.0;
	if(min < 0.0 || max < 0.0) return 0.0;
	if(accuracy < 1) accuracy = 1;
	if(accuracy > 6) accuracy = 6;
	new T3D:divValue = floatround(floatpower(10.0,accuracy)), T3D:prefix = floatround(max)-floatround(min), Float:T3D:rand_prefix = 0.0;
	if(T3D:prefix > 0) T3D:rand_prefix = 1.0 * random(T3D:prefix);
	return T3D:rand_prefix + min + (1.0*random(T3D:divValue+1)/(T3D:divValue*1.0));
}

stock Float: Tryg3D::RandomFloatEx(const Float:min, const Float:max, accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	if(min >= max) return 0.0;
	return Tryg3D::RandomFloat(0.0,max-min,accuracy) + min;
}

stock Tryg3D::RandomInteger(const min, const max){
	if(min >= max) return 0;
	return random(max-min+1) + min;
}

stock Float: Tryg3D::CalculatePercent(const Float:value, const Float:maxvalue){
	if(maxvalue == 0.0) return 0.0;
	return (value/maxvalue)*100.0;
}

stock Float: Tryg3D::CompressRotation(const Float:rotation){
	return (rotation-floatround(rotation/360.0,floatround_floor)*360.0);
}

stock Float: Tryg3D::DeCompressRotation(Float:rotation){
	rotation = Tryg3D::CompressRotation(rotation);
	if(rotation > 180.0) rotation -= 360.0;
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

stock Float: Tryg3D::NormalizeVector(&Float:x, &Float:y, &Float:z = 0.0){
	new Float:T3D:dist = VectorSize(x,y,z);
	if(T3D:dist <= 0.0) return 0.0;
	Tryg3D::DivideValues(T3D:dist,x,y,z);
	return T3D:dist;
}

stock bool: Tryg3D::RotationInRange(const Float:rotation, Float:r_min, Float:r_max){
	if(r_min > r_max) Tryg3D::SwapFloat(r_min,r_max);
	return (r_min <= rotation <= r_max);
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

stock Tryg3D::GetRotationMatrixEulerEx(Float:matrix[][], const Float:rx, const Float:ry, const Float:rz, const EulerModes: mode = T3D:euler_default){
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

stock Tryg3D::MatrixRotateReverse(const Float:matrix[][], const Float:oX, const Float:oY, const Float:oZ, &Float:x, &Float:y, &Float:z){
    x += oX * matrix[0][0] + oY * matrix[1][0] + oZ * matrix[2][0];
    y += oX * matrix[0][1] + oY * matrix[1][1] + oZ * matrix[2][1];
    z += oX * matrix[0][2] + oY * matrix[1][2] + oZ * matrix[2][2];
}

stock Tryg3D::GetQuatFromEuler(Float:rx, Float:ry, Float:rz, &Float:qw, &Float:qx, &Float:qy, &Float:qz, EulerModes: mode = T3D:euler_default){
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

stock Tryg3D::EulerRotateEx(Float:rx, Float:ry, Float:rz, Float:oX, Float:oY, Float:oZ, &Float:tx, &Float:ty, &Float:tz, EulerModes: mode = T3D:euler_default){
	Tryg3D::GetQuatFromEuler(rx,ry,rz,Float:mode,rx,ry,rz,mode);
	Tryg3D::QuatRotate(Float:mode,rx,ry,rz,oX,oY,oZ,tx,ty,tz);
}

stock Tryg3D::GetQuatUpVector(const Float:qw, const Float:qx, const Float:qy, const Float:qz, &Float:vx, &Float:vy, &Float:vz){
	vx = 2.0*(qy*qw+qz*qx);
	vy = 2.0*(qz*qy-qx*qw);
	vz = 1.0-(2.0*(qx*qx+qy*qy));
}

/********************************
 * Screen Functions             *
 ********************************/
 
//Provided by Nero_3D, updated by Crayder, Ralfie
stock Tryg3D::NormCrossProduct(&Float:x, &Float:y, &Float:z, Float:v1x, Float:v1y, Float:v1z, Float:v2x, Float:v2y, Float:v2z){
	x = v1y * v2z - v2y * v1z;
	y = v1z * v2x - v2z * v1x;
	z = v1x * v2y - v2x * v1y;
	v1x = VectorSize(x,y,z);
	x /= v1x;
	y /= v1x;
	z /= v1x;
}

#if defined TRYG3D_MOD_PLAYER

	stock Tryg3D::ScreenToWorld(const playerid, const Float:screenX, const Float:screenY, &Float:vX, &Float:vY, &Float:vZ){
		if((0.0 <= screenX <= C_ON_SCREEN_X) && (0.0 <= screenY <= C_ON_SCREEN_Y) && GetPlayerCameraFrontVector(playerid,vX,vY,vZ)){
			new Float:pX = ((screenX / C_ON_SCREEN_X) - 0.5) * 2.0 * C_IN_GAME_X,
				Float:pZ = ((screenY / C_ON_SCREEN_Y) - 0.5) * 2.0 * ((GetPlayerCameraAspectRatio(playerid) > 1.375) ? C_IN_GAME_YW : C_IN_GAME_Y),
				Float:nXx, Float:nYx, Float:nZx, Float:nXz, Float:nYz, Float:nZz;
			Tryg3D::NormCrossProduct(nXx,nYx,nZx,vX,vY,vZ,0.0,0.0,1.0);
			Tryg3D::NormCrossProduct(nXz,nYz,nZz,vX,vY,vZ,nXx,nYx,nZx);
			vX += nXx * pX + nXz * pZ;
			vY += nYx * pX + nYz * pZ;
			vZ += nZx * pX + nZz * pZ;
			return 1;
		}
		return 0;
	}

	stock Tryg3D::WorldToScreen(const playerid, Float:x, Float:y, Float:z, &Float:screenX, &Float:screenY){
		new Float:vX, Float:vY, Float:vZ, Float:cX, Float:cY, Float:cZ, Float:nXx, Float:nYx, Float:nZx, Float:nXz, Float:nYz, Float:nZz;
		
		if(GetPlayerCameraPos(playerid,cX,cY,cZ)){
			GetPlayerCameraFrontVector(playerid,vX,vY,vZ);

			Tryg3D::NormCrossProduct(nXx,nYx,nZx,vX,vY,vZ,0.0,0.0,1.0);
			Tryg3D::NormCrossProduct(nXz,nYz,nZz,vX,vY,vZ,nXx,nYx,nZx);
			
			// Distance, can be both positive and negative
			screenX = (vX * (x - cX) + vY * (y - cY) + vZ * (z - cZ) ) / ((vX * vX) + (vY * vY) + (vZ * vZ));

			if((_: screenX & (1 << (cellbits - 1))) == 0) { // only positive values
				z = (((z - cZ) / screenX) - vZ) / nZz;
				x = (((x - cX) / screenX) - vX - (z * nXz)) / nXx;

				screenX = ((x / (C_IN_GAME_X * 2.0)) + 0.5) * C_ON_SCREEN_X;
				screenY = ((z / (((GetPlayerCameraAspectRatio(playerid) > 1.375) ? C_IN_GAME_YW : C_IN_GAME_Y) * 2.0)) + 0.5) * C_ON_SCREEN_Y;
				return ((0.0 <= screenX <= C_ON_SCREEN_X) && (0.0 <= screenY <= C_ON_SCREEN_Y));
			}
		}
		return 0;
	}
	
	#if defined TRYG3D_MOD_COLANDREAS
		stock Tryg3D::ScreenToWorldCol(const playerid, const Float:distance, const Float:screenX, const Float:screenY, &Float:wX, &Float:wY, &Float:wZ){
			if(Tryg3D::ScreenToWorld(playerid,screenX,screenY,wX,wY,wZ)){
				new Float:cX,Float:cY,Float:cZ;
				GetPlayerCameraPos(playerid,cX,cY,cZ);
				wX = cX + (wX * distance);
				wY = cY + (wY * distance);
				wZ = cZ + (wZ * distance);
				return ColAndreas::RayCastLine(cX,cY,cZ,wX,wY,wZ+0.001,wX,wY,wZ) + 1;
			}
			return 0;
		}
	#endif
	
#endif

/********************************
 * General Functions            *
 ********************************/

stock Float: Tryg3D::GetDistance1D(const Float:x1, const Float:x2){
	return floatsqroot(floatpower(x1-x2,2.0));
}

stock Float: Tryg3D::GetDistance2D(const Float:x1, const Float:y1, const Float:x2, const Float:y2){
	return floatsqroot(floatpower(x1-x2,2.0)+floatpower(y1-y2,2.0));
}

stock Float: Tryg3D::GetDistance3D(const Float:x1, const Float:y1, const Float:z1, const Float:x2, const Float:y2, const Float:z2){
	return floatsqroot(floatpower(x1-x2,2.0)+floatpower(y1-y2,2.0)+floatpower(z1-z2,2.0));
}

stock bool: Tryg3D::IsPolygonClosed(const Float:points[], const max_points = sizeof(points)){
	if(max_points % 2 == 1 || max_points < 6) return false;
	if(points[0] == points[max_points-2] && points[1] == points[max_points-1]) return true;
	return false;
}

stock bool: Tryg3D::IsValidPolygon(const Float:points[], const max_points = sizeof(points)){
	if(max_points % 2 == 1) return false;
	if(Tryg3D::IsPolygonClosed(points,max_points)){
		if(max_points < 8) return false;
	} else {
		if(max_points < 6) return false;
	}
	return true;
}

stock Tryg3D::GetCenterRectangle(const Float: x_min, const Float: y_min, const Float: x_max, const Float: y_max, &Float: x_center, &Float: y_center)
{
	x_center = (x_min + x_max) / 2.0;
	y_center = (y_min + y_max) / 2.0;
	return 1;
}

stock ElementOrientation: Tryg3D::GetOrientation(Float:angle){
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
	return ElementOrientation: TRYG3D_INVALID_ORIENTATION;
}

stock bool: Tryg3D::GetOrientationName(orientation_name[], const Float:angle, bool:as_compass = false, const maxdest = sizeof(orientation_name)){
	new ElementOrientation: orientation = Tryg3D::GetOrientation(angle);
	if(_:orientation == TRYG3D_INVALID_ORIENTATION){
		format(orientation_name,maxdest,"Unknown");
		return false;
	}
	if(as_compass){
		format(orientation_name,maxdest,"%s",Tryg3D::OrientationCompass[_:orientation]);
	} else {
		format(orientation_name,maxdest,"%s",Tryg3D::OrientationNames[_:orientation]);
	}
	return true;
}

stock Float: Tryg3D::GetEllipseRadius(const Float:x, const Float:y, const Float:angle){
	if(x <= 0.0) return -1.0;
	new Float:theta = atan((y/x)*floattan(Tryg3D::CompressRotation(angle),degrees));
	return floatsqroot((floatpower(x,2.0)*floatpower(floatsin(theta,degrees),2.0))+(floatpower(y,2.0)*floatpower(floatcos(theta,degrees),2.0)));
}

stock Float: Tryg3D::GetLineSize2D(const Float:points[][2], const max_points = sizeof(points)){
	if(max_points < 2) return 0.0;
	new Float:T3D:distance = 0.0;
	for(new i = 1; i < max_points; i++){
		T3D:distance += Tryg3D::GetDistance2D(points[i-1][0],points[i-1][1],points[i][0],points[i][1]);
	}
	return T3D:distance;
}

stock Float: Tryg3D::GetLineSize3D(const Float:points[][3], const max_points = sizeof(points)){
	if(max_points < 2) return 0.0;
	new Float:T3D:distance = 0.0;
	for(new i = 1; i < max_points; i++){
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
stock Tryg3D::GetNearest2DPointOnPolygon(const Float:polygon_points[], const Float:x, const Float:y, &Float:tx, &Float:ty, const max_points = sizeof(polygon_points)){
	if(!Tryg3D::IsValidPolygon(polygon_points,max_points)) return 0;
	new Float:T3D:dist,Float:T3D:min_dist,Float:T3D:pX,Float:T3D:pY,Float:T3D:pZ,Float:T3D:sX,Float:T3D:sY,Float:T3D:eX = polygon_points[0],Float:T3D:eY = polygon_points[1];
	T3D:min_dist = cellmax;
	for(new i = 2; i < max_points; i += 2){
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
	if(!Tryg3D::IsPolygonClosed(polygon_points,max_points)){
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

stock Float: Tryg3D::GetLineCosTheta2D(const Float:StartLine1[2], const Float:EndLine1[2], const Float:StartLine2[2], const Float:EndLine2[2]){
	new Float:LineSize1 = Tryg3D::GetDistance2D(StartLine1[0],StartLine1[1],EndLine1[0],EndLine1[1]), Float:LineSize2 = Tryg3D::GetDistance2D(StartLine2[0],StartLine2[1],EndLine2[0],EndLine2[1]);
	return floatabs(((StartLine1[0]-EndLine1[0])/LineSize1)*((StartLine2[0]-EndLine2[0])/LineSize2)+((StartLine1[1]-EndLine1[1])/LineSize1)*((StartLine2[1]-EndLine2[1])/LineSize2));
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

stock bool: Tryg3D::IsProbable(const Float:chance, const accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
    if(chance <= 0.0) return false;
    if(chance >= 100.0) return true;
    return Tryg3D::RandomFloat(0.0,100.0,accuracy) <= chance;
}

stock Tryg3D::RandomItemFromArray(const items[][LootArray], const max_items = sizeof(items), const accuracy = TRYG3D_DEFAULT_RANDOM_ACCURACY){
	new Float:T3D:RNG = Tryg3D::RandomFloat(0.0,100.0,accuracy), Float:T3D:LootState = 0.0;
	for(new i = 0; i < max_items; i++){
		if(T3D:LootState <= T3D:RNG <= (T3D:LootState+items[i][ItemChance])){
			return items[i][ItemID];
		} else {
			T3D:LootState += items[i][ItemChance];
		}
	}
	return -1;
}

stock Tryg3D::GetWeaponShotPos(playerid, hittype, &Float:fx, &Float:fy, &Float:fz){
	new Float:ox,Float:oy,Float:oz;
	switch(hittype){
		case BULLET_HIT_TYPE_VEHICLE, BULLET_HIT_TYPE_OBJECT, BULLET_HIT_TYPE_PLAYER_OBJECT, BULLET_HIT_TYPE_PLAYER: {
			GetPlayerLastShotVectors(playerid,ox,oy,oz,fx,fy,fz);
		}
	}
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
	return Tryg3D::CompressRotation(floatabs((value/((FLOAT_PI*2)/360.0))+360.0));
}

stock Float: Tryg3D::ShiftRadianToGrades(const Float:value){
	return Tryg3D::ShiftDegreeToGrades(Tryg3D::ShiftRadianToDegree(value));
}

stock Float: Tryg3D::ShiftGradesToDegree(const Float:value){
	return value*0.9;
}

stock Float: Tryg3D::ShiftGradesToRadian(const Float:value){
	return Tryg3D::ShiftDegreeToRadian(Tryg3D::ShiftGradesToDegree(value));
}

stock Tryg3D::ShiftRotationToVector(const Float:rx, const Float:rz, &Float:vx, &Float:vy, &Float:vz){
	Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,1.0,vx,vy,vz);
}

stock Tryg3D::ShiftVectorToRotation(const Float:vx, const Float:vy, const Float:vz, &Float:rx, &Float:rz){
	rx = Tryg3D::CompressRotation(-(acos(vz)-90.0));
	rz = Tryg3D::CompressRotation((atan2(vy,vx)-90.0));
}

stock bool: Tryg3D::ShiftVectorRotation(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:tx, &Float:ty, &Float:tz){
	new Float:T3D:dist = VectorSize(x,y,z);
	if(T3D:dist <= 0.0) return false;
	new Float:T3D:matrix[3][3];
	Tryg3D::GetRotationMatrixEuler(T3D:matrix,rx,ry,rz);
	tx = ty = tz = 0.0;
	Tryg3D::MatrixRotate(T3D:matrix,(x/T3D:dist),(y/T3D:dist),(z/T3D:dist),tx,ty,tz);
	return true;
}

stock Tryg3D::ShiftOffsetToPosition(const Float:x, const Float:y, const Float:z, Float:rx, Float:ry, Float:rz, const Float:offset_x, const Float:offset_y, const Float:offset_z, &Float:tx, &Float:ty, &Float:tz){
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

stock Float: Tryg3D::ShiftMoveTimeToSpeed(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, const movement_time){
	if(movement_time/1000.0 <= 0.0){
		return TRYG3D_INVALID_MOVE_SPEED;
	} else {
		return (Tryg3D::GetDistance3D(x,y,z,tx,ty,tz)/(movement_time/1000.0));
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

stock Tryg3D::GetArcPoints3D(const Float:x, const Float:y, const Float:z, const Float:tx, const Float:ty, const Float:tz, Float:ry, const Float:height, Float:points[][3], const max_points = sizeof(points)){
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

stock Tryg3D::GetCube3DPoint(const OrientationCube3D:orientation, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z, &Float:tx, &Float:ty, &Float:tz){
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

stock bool: Tryg3D::IsPointInCube(const Float:px, const Float:py, const Float:pz, const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz){
	return ((px >= minx && px <= maxx) && (py >= miny && py <= maxy) && (pz >= minz && pz <= maxz));
}		

stock bool: Tryg3D::IsPointInCube3D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, Float:size_x, Float:size_y, Float:size_z){
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

stock bool: Tryg3D::IsPointInCircularSector(const Float:px, const Float:py, const Float:x, const Float:y, Float:rz, const Float:radius, Float:view_angle){
	new Float:T3D:dist = Tryg3D::GetDistance2D(px,py,x,y);
	if(T3D:dist == 0.0) return true;
	if(Tryg3D::RoundAccuracy(T3D:dist) > radius) return false;
	view_angle /= 2.0;
	new Float:trz, Float:T3D:min = -view_angle, Float:T3D:max = view_angle;
	Tryg3D::GetRotationFor2Point2D(x,y,px,py,trz);
	trz = Tryg3D::RoundAccuracy(Tryg3D::CompressRotation(trz-rz));
	if(T3D:min <= 0.0){
		T3D:min = floatabs(T3D:min);
		T3D:max += T3D:min;
		trz = Tryg3D::RoundAccuracy(Tryg3D::CompressRotation(trz+T3D:min));
		T3D:min = 0.0;
		if(trz == 360.0) trz = 0.0;
	} else if(T3D:max > 360.0){
		new Float:T3D:diff = -(360.0-T3D:max);
		T3D:max = 360.0;
		T3D:min -= T3D:diff;
		trz = Tryg3D::RoundAccuracy(Tryg3D::CompressRotation(trz-Float:T3D:diff));
		if(trz == 0.0) trz = 360.0;
	}
	return Tryg3D::RotationInRange(trz,T3D:min,T3D:max);
}

stock bool: Tryg3D::IsPointInSphericalSector(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz){
	new Float:dist = VectorSize(px-x,py-y,pz-z);
	if(dist == 0.0) return true;
	if(dist > radius) return false;
	new Float:matrix[3][3], Float:tx, Float:ty, Float:tz, Float:trx, Float:trz;
	Tryg3D::GetRotationMatrixEuler(matrix,rx,0.0,rz);
	Tryg3D::MatrixRotateReverse(matrix,px-x,py-y,pz-z,tx,ty,tz);
	Tryg3D::GetRotationFor2Point3D(0.0,0.0,0.0,tx,ty,tz,trx,trz);
	if(trx > 180.0) trx -= 360.0;
	if(trz > 180.0) trz -= 360.0;
	return floatabs(trx) < (vrx / 2.0) && floatabs(trz) < (vrz / 2.0);
}

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
stock bool: Tryg3D::IsPointInPolygon(const Float:x, const Float:y, const Float:points[], const max_points = sizeof(points)){
	if(!Tryg3D::IsValidPolygon(points,max_points)) return false;
	new polygon_Sides = ((max_points - 2) / 2), Float:polygon_Data[2][TRYG3D_MAX_POLYGON_POINTS], cross_Total = 0, idx = 0;
	for(new i = 0; i < max_points; i += 2){
		polygon_Data[0][idx] = points[i];
		polygon_Data[1][idx] = points[i+1];
		idx++;
	}
	if(!Tryg3D::IsPolygonClosed(points,max_points)){
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
	return (cross_Total & 0x1) == 1;
}

stock bool: Tryg3D::IsPointInCylinder2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius){
	return Tryg3D::IsPointInCylinder3D(px,py,pz,x,y,minz,x,y,maxz,radius);
}

stock bool: Tryg3D::IsPointInCone2D(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b){
	return Tryg3D::IsPointInCone3D(px,py,pz,x,y,minz,x,y,maxz,radius_a,radius_b);
}

stock bool: Tryg3D::IsPointInCircle(const Float:px, const Float:py, const Float:x, const Float:y, const Float:radius){
	return Tryg3D::GetDistance2D(px,py,x,y) <= radius;
}

stock bool: Tryg3D::IsPointInSphere(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:radius){
	return Tryg3D::GetDistance3D(px,py,pz,x,y,z) <= radius;
}

stock bool: Tryg3D::IsPointInRectangle(const Float:px, const Float:py, const Float:minx, const Float:miny, const Float:maxx, const Float:maxy){
	return (px >= minx && px <= maxx) && (py >= miny && py <= maxy);
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
	new Float:T3D:point_dist = Tryg3D::GetDistance1D(minz,maxz), Float:T3D:rand_dist = Tryg3D::RandomFloat(0.0,T3D:point_dist,4);
	tz = minz + T3D:rand_dist;
	Tryg3D::GetPointInCircle(x,y,Tryg3D::RandomFloat(0.0,(T3D:rand_dist*((radius_b-radius_a)*(1.0/T3D:point_dist))+radius_a)*2.0,4),tx,ty);
}

stock Tryg3D::GetPointInCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b, &Float:tx, &Float:ty, &Float:tz){
	new Float:trx,Float:trz;
	if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return 0;
	new Float:offset_x,Float:offset_y,Float:offset_z;
	Tryg3D::GetPointInCone2D(0.0,0.0,0.0,Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB),radius_a,radius_b,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(xA,yA,zA,Tryg3D::CompressRotation(trx-90),0.0,Tryg3D::CompressRotation(trz),offset_x,offset_y,offset_z,tx,ty,tz);
	return 1;
}

stock Tryg3D::GetPointInCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, Float:view_angle, &Float:tx, &Float:ty){
	view_angle /= 2.0;
	new Float:rand_rz = Tryg3D::RandomFloatEx(rz-view_angle,rz+view_angle,4), Float:rand_rad = Tryg3D::RandomFloat(0.0,radius,4);
	if(rand_rad > radius) rand_rad = radius;
	rand_rz = Tryg3D::NMTVF(rand_rz,(rz+view_angle));
	rand_rz = Tryg3D::NLTVF(rand_rz,(rz-view_angle));
	Tryg3D::GetPointInFront2D(x,y,Tryg3D::CompressRotation(rand_rz),rand_rad,tx,ty);
}

stock Tryg3D::GetPointInSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz, &Float:tx, &Float:ty, &Float:tz){
	vrx /= 2.0, vrz /= 2.0;
	new Float:rand_rx = Tryg3D::RandomFloatEx(-vrx,vrx,4), Float:rand_rz = Tryg3D::RandomFloatEx(-vrz,vrz,4), Float:rand_rad = Tryg3D::RandomFloat(0.0,radius,4);
	if(rand_rad == 0.0){
		tx = x, ty = y, tz = z;
	} else {
		new Float:offset_x,Float:offset_y,Float:offset_z;
		if(rand_rad > radius) rand_rad = radius;
		rand_rx = Tryg3D::NMTVF(rand_rx,vrx);
		rand_rx = Tryg3D::NLTVF(rand_rx,-vrx);
		rand_rz = Tryg3D::NMTVF(rand_rz,vrz);
		rand_rz = Tryg3D::NLTVF(rand_rz,-vrz);
		Tryg3D::GetPointInFront3D(0.0,0.0,0.0,Tryg3D::CompressRotation(rand_rx),Tryg3D::CompressRotation(rand_rz),rand_rad,offset_x,offset_y,offset_z);
		Tryg3D::ShiftOffsetToPosition(x,y,z,rx,0.0,rz,offset_x,offset_y,offset_z,tx,ty,tz);
	}
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

stock Tryg3D::GetPointInPolygon(const Float:points[], &Float:tx, &Float:ty, const max_points = sizeof(points), max_iterations = 10000){
	if(!Tryg3D::IsValidPolygon(points,max_points)) return -1;
	new Float:minx, Float:miny, Float:maxx, Float:maxy, recheck = 1;
	minx = maxx = points[0];
	miny = maxy = points[1];
	for(new i = 2; i < max_points; i += 2){
		if(points[i] < minx) minx = points[i];
		if(points[i] > maxx) maxx = points[i];
		if(points[i+1] < miny) miny = points[i+1];
		if(points[i+1] > maxy) maxy = points[i+1];
	}
	Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
	while(!Tryg3D::IsPointInPolygon(tx,ty,points,max_points)){
		Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
		recheck++;
		if(recheck >= max_iterations){
			printf("[ADM] Warrning: Tryg3D::GetPointInPolygon(%f,%f,%f,%f,%f,%f,...,tx,ty,%d) break after %d iterations",points[0],points[1],points[2],points[3],points[4],points[5],max_points,max_iterations);
			return -1;
		}
	}
	return recheck;
}

stock Float: Tryg3D::GetPointOnClock(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty, &Float:trz, Float:rz = TRYG3D_INVALID_ROTATION){
	if(rz == TRYG3D_INVALID_ROTATION) rz = Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE);
	Tryg3D::GetPointInFront2D(x,y,rz,radius,tx,ty);
	trz = Tryg3D::CompressRotation(rz-180.0);
	return trz;
}

stock Tryg3D::GetPointOnCircle(const Float:x, const Float:y, const Float:radius, &Float:tx, &Float:ty){
	Tryg3D::GetPointInFront2D(x,y,Tryg3D::RandomFloat(0.0,TRYG3D_RANDOM_MAX_ANGLE),radius,tx,ty);
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
	new Float:rand_rz = Tryg3D::CompressRotation(Tryg3D::RandomFloatEx(rz-view_angle+360.0,rz+view_angle+360.0,4));
	rand_rz = Tryg3D::NMTVF(rand_rz,(rz+view_angle));
	rand_rz = Tryg3D::NLTVF(rand_rz,(rz-view_angle));
	Tryg3D::GetPointInFront2D(x,y,rand_rz,radius,tx,ty);
}

stock Tryg3D::GetPointOnSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, Float:vrx, Float:vrz, &Float:tx, &Float:ty, &Float:tz){
	vrx /= 2.0, vrz /= 2.0;
	new Float:rand_rx = Tryg3D::RandomFloatEx(-vrx,vrx,4), Float:rand_rz = Tryg3D::RandomFloatEx(-vrz,vrz,4), Float:offset_x, Float:offset_y, Float:offset_z;
	rand_rx = Tryg3D::NMTVF(rand_rx,vrx);
	rand_rx = Tryg3D::NLTVF(rand_rx,-vrx);
	rand_rz = Tryg3D::NMTVF(rand_rz,vrz);
	rand_rz = Tryg3D::NLTVF(rand_rz,-vrz);	
	Tryg3D::GetPointInFront3D(0.0,0.0,0.0,Tryg3D::CompressRotation(rand_rx),Tryg3D::CompressRotation(rand_rz),radius,offset_x,offset_y,offset_z);
	Tryg3D::ShiftOffsetToPosition(x,y,z,rx,0.0,rz,offset_x,offset_y,offset_z,tx,ty,tz);
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
 * Actor Functions              *
 ********************************/

#if defined TRYG3D_MOD_ACTOR

	stock Tryg3D::CountActors(){
		new T3D:count = 0;
		for(new i = 0, j = GetActorPoolSize(); i <= j; i++) if(IsValidActor(i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountVisibleActors(playerid){
		new T3D:count = 0;
		for(new i = 0, j = GetActorPoolSize(); i <= j; i++) if(IsValidActor(i) && IsActorStreamedIn(i,playerid)) T3D:count++;
		return T3D:count;
	}
	
#endif

/********************************
 * Player Functions             *
 ********************************/

#if defined TRYG3D_MOD_PLAYER

	stock bool: Tryg3D::IsPlayerSpawned(const playerid){
		new T3D:pstate = GetPlayerState(playerid);
		if(T3D:pstate != 1 && T3D:pstate != 2 && T3D:pstate != 3) return false;
		return true;
	}
	
	stock bool: Tryg3D::IsPlayerSkydiving(playerid){
		return 958 <= GetPlayerAnimationIndex(playerid) <= 962;
	}

	stock bool: Tryg3D::IsPlayerUsingParachute(playerid){
		return 963 <= GetPlayerAnimationIndex(playerid) <= 979;
	}

	stock bool: Tryg3D::IsPlayerFall(playerid){
		return GetPlayerAnimationIndex(playerid) == 1130;
	}

	stock bool: Tryg3D::IsPlayerAiming(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 1160..1163,1167,1365,1643,1453,220: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerStay(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 1189,1133: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerSwim(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 1538,1539,1541,1544: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerJump(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 1195,1198: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerParaFall(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 958,959,961,962,1134: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerParaGlide(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 963,965,971,976,978: return true;
		}
		return false;
	}

	stock bool: Tryg3D::IsPlayerRunning(playerid){
		switch(GetPlayerAnimationIndex(playerid)){
			case 1231,1266,1196: return true;
		}
		return false;
	}
	
	stock Tryg3D::GivePlayerDamage(const targetid, Float:amount, const playerid, const weaponid, const bodypart){
		if(targetid == INVALID_PLAYER_ID) return 0;
		if(Tryg3D::DeatchTick[targetid] != 0 && GetTickCount() < Tryg3D::DeatchTick[targetid]) return 0;
		#if defined TRYG3D_MOD_FCNPC
			if(IsPlayerNPC(targetid) && FCNPC::IsValid(targetid)){
				new Float:T3D:health,Float:T3D:armour;
				T3D:health = FCNPC::GetHealth(targetid);
				T3D:armour = FCNPC::GetArmour(targetid);
				CallRemoteFunction("FCNPC_OnGiveDamage","ddddf",targetid,playerid,amount,weaponid,bodypart);
				CallRemoteFunction("FCNPC_OnTakeDamage","ddddf",targetid,playerid,amount,weaponid,bodypart);
				if(T3D:armour >= amount){
					FCNPC::SetArmour(targetid,T3D:armour-amount);
				} else if(T3D:armour < amount){
					amount -= T3D:armour;
					FCNPC::SetArmour(targetid,0.0);
					if(T3D:health-amount <= 0.0){
						CallRemoteFunction("OnPlayerDeath","ddd",targetid,playerid,weaponid);
						CallRemoteFunction("FCNPC_OnDeath","ddd",targetid,playerid,weaponid);
						Tryg3D::DeatchTick[targetid] = GetTickCount()+200;
						FCNPC::Respawn(targetid);
					} else {
						FCNPC::SetHealth(targetid,T3D:health-amount);
					}
				} else {
					if(T3D:health-amount <= 0.0){
						CallRemoteFunction("OnPlayerDeath","ddd",targetid,playerid,weaponid);
						CallRemoteFunction("FCNPC_OnDeath","ddd",targetid,playerid,weaponid);
						Tryg3D::DeatchTick[targetid] = GetTickCount()+200;
						FCNPC::Respawn(targetid);
					} else {
						FCNPC::SetHealth(targetid,T3D:health-amount);
					}
				}
			} else {
		#endif
			new Float:T3D:health,Float:T3D:armour;
			GetPlayerArmour(targetid,T3D:armour);
			GetPlayerHealth(targetid,T3D:health);
			CallRemoteFunction("OnPlayerGiveDamage","ddfdd",playerid,targetid,amount,weaponid,bodypart);
			CallRemoteFunction("OnPlayerTakeDamage","ddfdd",targetid,playerid,amount,weaponid,bodypart);
			if(T3D:armour >= amount){
				SetPlayerArmour(targetid,T3D:armour-amount);
			} else if(T3D:armour < amount){
				amount -= T3D:armour;
				SetPlayerArmour(targetid,0.0);
				if(T3D:health-amount <= 0.0){
					CallRemoteFunction("OnPlayerDeath","ddd",targetid,playerid,weaponid);
					Tryg3D::DeatchTick[targetid] = GetTickCount()+200;
					SpawnPlayer(targetid);
				} else {
					SetPlayerHealth(targetid,T3D:health-amount);
				}
			} else {
				if(T3D:health-amount <= 0.0){
					CallRemoteFunction("OnPlayerDeath","ddd",targetid,playerid,weaponid);
					Tryg3D::DeatchTick[targetid] = GetTickCount()+200;
					SpawnPlayer(targetid);
				} else {
					SetPlayerHealth(targetid,T3D:health-amount);
				}
			}
		#if defined TRYG3D_MOD_FCNPC
			}
		#endif
		return 1;
	}

	stock Tryg3D::CountPlayers(const bool:isplayer = true, const bool:isnpc = true){
		new T3D:count = 0;
		Tryg3D::Foreach(i){
			if(IsPlayerNPC(i)){
				if(isnpc) T3D:count++;
			} else {
				if(isplayer) T3D:count++;
			}
		}
		return T3D:count;
	}

	stock Tryg3D::CountVisiblePlayers(const playerid, const bool:isplayer = true, const bool:isnpc = true){
		new T3D:count = 0;
		Tryg3D::Foreach(i){
			if(i != playerid && IsPlayerStreamedIn(i,playerid)){
				if(IsPlayerNPC(i)){
					if(isnpc) T3D:count++;
				} else {
					if(isplayer) T3D:count++;
				}
			}
		}
		return T3D:count;
	}

	stock Float: Tryg3D::GetPointInFrontOfPlayer(const playerid, &Float:tx, &Float:ty, const Float:radius){
		new Float:rz,T3D:vid = GetPlayerVehicleID(playerid);
		GetPlayerPos(playerid,tx,ty,rz);
		if(T3D:vid != 0){
			GetVehicleZAngle(T3D:vid,rz);
		} else {
			GetPlayerFacingAngle(playerid,rz);
		}
		Tryg3D::GetPointInFront2D(tx,ty,rz,radius,tx,ty);
		return rz;
	}

	stock Tryg3D::GetPlayerCameraRotation(const playerid, &Float:rx, &Float:rz){
		new Float:mx,Float:my,Float:mz;
		GetPlayerCameraFrontVector(playerid,mx,my,mz);
		rx = Tryg3D::CompressRotation(-(acos(mz)-90.0));
		rz = Tryg3D::CompressRotation((atan2(my,mx)-90.0));
	}

	stock Tryg3D::GetPlayerCameraZAngle(const playerid, &Float:z_angle){
		new Float:mx,Float:my,Float:mz;
		GetPlayerCameraFrontVector(playerid,mx,my,mz);
		z_angle = Tryg3D::CompressRotation((atan2(my,mx)-90.0));
	}

	stock Float: Tryg3D::GetPointInFrontOfCamera2D(const playerid, &Float:tx, &Float:ty, const Float:radius){
		new Float:x,Float:y,Float:rz;
		GetPlayerCameraPos(playerid,x,y,rz);
		Tryg3D::GetPlayerCameraZAngle(playerid,rz);
		Tryg3D::GetPointInFront2D(x,y,rz,radius,tx,ty);
		return rz;
	}

	stock Float: Tryg3D::GetPlayerSpeed(const playerid){
		new Float:x,Float:y,Float:z;
		GetPlayerVelocity(playerid,x,y,z);
		return floatmul(VectorSize(x,y,z),TRYG3D_PLAYER_SPEED_MULTIPLIER);
	}

	stock Tryg3D::GetPlayerTargetAngle(const playerid, const Float:x, const Float:y, &Float:rz){
		new Float:mx,Float:my;
		GetPlayerPos(playerid,mx,my,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
	}

	stock Tryg3D::SetPlayerTargetAngle(const playerid, const Float:x, const Float:y, &Float:rz = 0.0){
		new Float:mx,Float:my;
		GetPlayerPos(playerid,mx,my,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
		SetPlayerFacingAngle(playerid,rz);
	}

	stock Tryg3D::GetPlayerTargetPlayerAngle(const playerid, const targetid, &Float:rz){
		new Float:mx,Float:my,Float:x,Float:y;
		GetPlayerPos(playerid,mx,my,rz);
		GetPlayerPos(targetid,x,y,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
	}

	stock Tryg3D::SetPlayerTargetPlayerAngle(const playerid, const targetid, &Float:rz = 0.0){
		new Float:mx,Float:my,Float:x,Float:y;
		GetPlayerPos(playerid,mx,my,rz);
		GetPlayerPos(targetid,x,y,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
		SetPlayerFacingAngle(playerid,rz);
	}

	stock Tryg3D::GetPointInFrontOfCamera3D(const playerid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0){
		new Float:x,Float:y,Float:z;
		GetPlayerCameraPos(playerid,x,y,z);
		Tryg3D::GetPlayerCameraRotation(playerid,rx,rz);
		Tryg3D::GetPointInFront3D(x,y,z,rx,rz,radius,tx,ty,tz);
	}

	stock Tryg3D::IsPlayerLookAtSky(const playerid){
		new Float:rx,Float:rz;
		Tryg3D::GetPlayerCameraRotation(playerid,rx,rz);
		return (rx > 0.0 && rx <= 90.0);
	}

	stock Tryg3D::IsPlayerFakeSpectating(const playerid, const bool:force_disable = true){
		if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING && IsPlayerAdmin(playerid)) return 0;
		if(GetPlayerCameraMode(playerid) != 4) return 0; 
		new Float:px,Float:py,Float:pz,Float:cx,Float:cy,Float:cz;
		GetPlayerPos(playerid,px,py,pz);
		GetPlayerCameraPos(playerid,cx,cy,cz);
		if(Tryg3D::GetDistance3D(px,py,pz,cx,cy,cz) < 20.0) return 0;
		if(force_disable) SetCameraBehindPlayer(playerid);
		return 1;
	}

	stock Float: Tryg3D::GetCameraTargetDistance(const Float:CamX, const Float:CamY, const Float:CamZ, const Float:ObjX, const Float:ObjY, const Float:ObjZ, const Float:FrX, const Float:FrY, const Float:FrZ){
		new Float:T3D:dist = Tryg3D::GetDistance3D(CamX,CamY,CamZ,ObjX,ObjY,ObjZ);
		return Tryg3D::GetDistance3D(ObjX,ObjY,ObjZ,(FrX * T3D:dist + CamX),(FrY * T3D:dist + CamY),(FrZ * T3D:dist + CamZ));
	}

	stock Tryg3D::IsPlayerAimingAt(const playerid, const Float:x, const Float:y, const Float:z, const Float:radius){
		new Float:cx,Float:cy,Float:cz,Float:fx,Float:fy,Float:fz;
		GetPlayerCameraPos(playerid,cx,cy,cz);
		GetPlayerCameraFrontVector(playerid,fx,fy,fz);
		return (radius >= Tryg3D::GetCameraTargetDistance(cx,cy,cz,x,y,z,fx,fy,fz));
	}
	
	stock Tryg3D::GetPlayerCameraLookAt(const playerid, &Float:x, &Float:y, &Float:z){
		Tryg3D::GetPointInFrontOfCamera3D(playerid,x,y,z,5.0);
	}

#endif

/********************************
 * Vehicle Functions            *
 ********************************/

#if defined TRYG3D_MOD_VEHICLE

	#define T3_GetVehicleFlags(%0)    Tryg3D::GetVehicleModelFlags(GetVehicleModel(%0))
	#define T3_IsVehicleFlag(%0,%1)   ((%0) & (%1))

	//Made by IllidanS4
	stock Tryg3D::GetVehicleRotation(const vehicleid, &Float:rx, &Float:ry, &Float:rz){
		new Float:qw,Float:qx,Float:qy,Float:qz;
		GetVehicleRotationQuat(vehicleid,qw,qx,qy,qz);
		Tryg3D::QuatToEuler(rx,ry,rz,qw,qx,qy,qz);
	}
	
	#if !defined GetVehicleRotation
		#define GetVehicleRotation Tryg3D::GetVehicleRotation
	#endif

	//Made by Ivan_Ino
	//SRC:https://github.com/Ino42O/VehiclePartPosition/blob/master/VehiclePartPosition.inc
	stock Tryg3D::GetPartPos(const modelid, const partid, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, &Float:tx, &Float:ty, &Float:tz, Float:offset_x = 0.0, Float:offset_y = 0.0, Float:offset_z = 0.0){
		new Float:ox,Float:oy,Float:oz;
		switch(partid){
			case VEHICLE_PART_RFTIRE: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_WHEELSFRONT,ox,oy,oz);
			}
			case VEHICLE_PART_LFTIRE: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_WHEELSFRONT,ox,oy,oz);
				ox *= (-1);
				offset_x *= (-1);
			}
			case VEHICLE_PART_RRTIRE: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_WHEELSREAR,ox,oy,oz);
			}
			case VEHICLE_PART_LRTIRE: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_WHEELSREAR,ox,oy,oz);
				ox *= (-1);
				offset_x *= (-1);
			}
			case VEHICLE_PART_HOOD: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_SIZE,ox,oy,oz);
				oy /= 2.0;
				ox = oz = 0.0;
			}
			case VEHICLE_PART_TRUNK: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_SIZE,ox,oy,oz);
				oy /= (-2.0);
				offset_y *= (-1);
				ox = oz = 0.0;
			}
			case VEHICLE_PART_ROOF: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_SIZE,ox,oy,oz);
				oz /= 2.0;
				ox = oy = 0.0;
			}
			case VEHICLE_PART_CHASSIS: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_SIZE,ox,oy,oz);
				oz /= (-2.0);
				offset_z *= (-1);
				ox = oy = 0.0;
			}
			case VEHICLE_PART_PETROLCAP: {
				GetVehicleModelInfo(modelid,VEHICLE_MODEL_INFO_PETROLCAP,ox,oy,oz);
			}
		}
		ox += offset_x;
		oy += offset_y;
		oz += offset_z;
		Tryg3D::ShiftOffsetToPosition(x,y,z,rx,ry,rz,ox,oy,oz,tx,ty,tz);
		return !(ox == 0.0 && oy == 0.0 && oz == 0.0);
	}

	//Made by Ivan_Ino Updated by Abyss Morgan 
	stock Tryg3D::GetVehiclePartPos(const vehicleid, const partid, &Float:tx, &Float:ty, &Float:tz, Float:offset_x = 0.0, Float:offset_y = 0.0, Float:offset_z = 0.0){
		new Float:x,Float:y,Float:z,Float:rx,Float:ry,Float:rz;
		GetVehiclePos(vehicleid,x,y,z);
		Tryg3D::GetVehicleRotation(vehicleid,rx,ry,rz);
		GetVehicleZAngle(vehicleid,rz);
		return Tryg3D::GetPartPos(GetVehicleModel(vehicleid),partid,x,y,z,rx,ry,rz,tx,ty,tz,offset_x,offset_y,offset_z);
	}
	
	stock Tryg3D::GenerateVehicleFlags(const modelid){
		new flag_value = 0;
		switch(modelid){
			case 425,548,417,487,497,563,469,447,488: flag_value += VF_AIRBORNE + VF_HELICOPTER;
			case 460,476,511,512,520,593,592,553,519,513,577: flag_value += VF_AIRBORNE + VF_AIRPLANE;
			case 539: flag_value += VF_AIRBORNE;
		}
		switch(modelid){
			case 425,520,432: flag_value += VF_MILITARY;
		}
		switch(modelid){
			case 472,473,493,595,484,430,453,452,446,454,539,447,460: flag_value += VF_NATATORIAL;
		}
		switch(modelid){
			case 441,464,465,501,564,594: flag_value += VF_RC;
		}
		switch(modelid){
			case 471,468,586,463,523,521,461,522,581,448,462,510,481,509: flag_value += VF_BIKES;
		}
		switch(modelid){
			case 435,450,584,590,591,606,607,608,610,611: flag_value += VF_TRAILER;
		}
		switch(modelid){
			case 449,537,538: flag_value += VF_TRAIN;
		}
		switch(modelid){
			case 569,570,590: flag_value += VF_CARRIAGE;
		}
		if(modelid == 539 || ((flag_value & VF_NATATORIAL != VF_NATATORIAL) && (flag_value & VF_AIRBORNE != VF_AIRBORNE))) flag_value += VF_STREET;
		switch(modelid){
			case 437,544,431,407,408,570,569,538,537,449,532,524,403,514,515,443,435,433,432,406: {	}
			default: {
				if(flag_value&VF_NATATORIAL!=VF_NATATORIAL && flag_value&VF_AIRBORNE!=VF_AIRBORNE && flag_value&VF_RC!=VF_RC && flag_value&VF_BIKES!=VF_BIKES){
					flag_value += VF_TOWABLE;
				}
			}
		}
		switch(modelid){
			case 416,523,427,490,407,544,596,598,597,599: flag_value += VF_POLICE;
		}
		return flag_value;
	}
	
	stock Tryg3D::GetVehicleModelDefaultFlags(const modelid){	
		if(!(400 <= modelid <= 611)) return 0;
		return Tryg3D::VehicleFlagsDefault[modelid - 400];
	}

	stock Tryg3D::GetVehicleModelFlags(const modelid){
		if(!(400 <= modelid <= 611)) return 0;
		return Tryg3D::VehicleFlagsCurrent[modelid - 400];
	}

	stock Tryg3D::SetVehicleModelFlags(const modelid, const value){
		if(!(400 <= modelid <= 611)) return 0;
		Tryg3D::VehicleFlagsCurrent[modelid - 400] = value;
		return 1;
	}

	stock Tryg3D::ToggleVehicleModelFlag(const modelid, const flag, const bool:toggle){
		if(!(400 <= modelid <= 611)) return 0;
		if(toggle){
			Tryg3D::VehicleFlagsCurrent[modelid - 400] |= flag;
		} else {
			Tryg3D::VehicleFlagsCurrent[modelid - 400] &= ~flag;
		}
		return 1;
	}
	
	stock Tryg3D::IsVehicleInRangeOfPoint(const vehicleid, const Float:range, const Float:x, const Float:y, const Float:z){
		return GetVehicleDistanceFromPoint(vehicleid,x,y,z) <= range;
	}

	stock Tryg3D::CountVisibleVehicles(const playerid){
		new T3D:count = 0;
		for(new i = 0, j = GetVehiclePoolSize(); i <= j; i++) if(IsValidVehicle(i) && IsVehicleStreamedIn(i,playerid)) T3D:count++;
		return T3D:count;
	}

	stock Float: Tryg3D::GetVehicleSpeed(const vehicleid){
		new Float:x,Float:y,Float:z;
		GetVehicleVelocity(vehicleid,x,y,z);
		return floatmul(VectorSize(x,y,z),TRYG3D_VEHICLE_SPEED_MULTIPLIER);
	}

	stock Tryg3D::SetVehicleSpeed(const vehicleid, const Float:speed){
		new Float:rx,Float:ry,Float:rz,Float:vx,Float:vy,Float:vz;
		Tryg3D::GetVehicleRotation(vehicleid,rx,ry,rz);
		Tryg3D::GetPointInFront3DEx(0.0,0.0,0.0,rx,ry,rz,(speed / TRYG3D_VEHICLE_SPEED_MULTIPLIER),vx,vy,vz);
		SetVehicleVelocity(vehicleid,vx,vy,vz);
	}

	stock Float: Tryg3D::GetPointInFrontOfVehicle2D(const vehicleid, &Float:tx, &Float:ty, const Float:radius){
		new Float:rz,Float:x,Float:y;
		GetVehiclePos(vehicleid,x,y,rz);
		GetVehicleZAngle(vehicleid,rz);
		Tryg3D::GetPointInFront2D(x,y,rz,radius,tx,ty);
		return rz;
	}

	stock Tryg3D::GetPointInFrontOfVehicle3D(const vehicleid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0){
		new Float:ry,Float:x,Float:y,Float:z;
		GetVehiclePos(vehicleid,x,y,z);
		Tryg3D::GetVehicleRotation(vehicleid,rx,ry,rz);
		Tryg3D::GetPointInFront3D(x,y,z,rx,rz,radius,tx,ty,tz);
	}

#endif

/********************************
 * ColAndreas Functions         *
 ********************************/
 
#if defined TRYG3D_MOD_COLANDREAS
 
	#define T3_IsCollisionFlag(%0,%1)        ((%0) & (%1))
	#define T3_IsPointInUnderwater(%1,%2,%3) (Tryg3D::IsPointInWater((%1),(%2),(%3)) && ((%3) < -1.0))
	
	forward OnColAndreasRemoveBuilding();
	forward OnColAndreasInitSuccess();
	forward OnColAndreasInitFail();

	stock Tryg3D::IsColAndreasInit(){
		new Float:mapunit;
		ColAndreas::FindZ_For2DCoord(0.0,0.0,mapunit);
		return !(mapunit <= 0.0);
	}

	stock Tryg3D::SafeColAndreasInit(){
		//check ColAndreas Init
		new bool:ColAndreasLastStat = false;
		if(!Tryg3D::IsColAndreasInit()){
			CallRemoteFunction("OnColAndreasRemoveBuilding","");
			ColAndreas::Init();
			ColAndreasLastStat = true;
		}
		if(!Tryg3D::IsColAndreasInit()){
			print("[ADM] Error: ColAndreas failed to initiated.");
			print("[ADM] Error: Cannot load /scriptfiles/colandreas/ColAndreas.cadb");
			Tryg3D::UpdateErrorCount();
			CallRemoteFunction("OnColAndreasInitFail","");
		} else {
			if(ColAndreasLastStat){
				CallRemoteFunction("OnColAndreasInitSuccess","");
				print("[ADM] Info: ColAndreas successfully init.");
			}
		}
	}

	stock Tryg3D::FindGroundZ(const Float:x, const Float:y, const Float:z, &Float:gZ){
		new Float:gX,Float:gY;
		return ColAndreas::RayCastLine(x,y,z,x,y,z-1000.0,gX,gY,gZ);
	}

	stock Tryg3D::MovePointCol(const Float:StartX, const Float:StartY, const Float:StartZ, const Float:EndX, const Float:EndY, const Float:EndZ, &Float:x, &Float:y, &Float:z){
		new objectid;
		x = y = z = FLOAT_INFINITY;
		objectid = ColAndreas::RayCastLine(StartX,StartY,StartZ,EndX,EndY,EndZ,x,y,z);
		if(x == FLOAT_INFINITY) x = EndX;
		if(y == FLOAT_INFINITY) y = EndY;
		if(z == FLOAT_INFINITY) z = EndZ;
		return objectid;
	}

	stock Tryg3D::MovePointColCutLine(const Float:sX, const Float:sY, const Float:sZ, const Float:eX, const Float:eY, const Float:eZ, &Float:x, &Float:y, &Float:z, const Float:cut_size = 0.0){
		new objectid, Float:radius, Float:rx, Float:rz;
		x = y = z = FLOAT_INFINITY;
		objectid = ColAndreas::RayCastLine(sX,sY,sZ,eX,eY,eZ,x,y,z);
		if(x == FLOAT_INFINITY) x = eX;
		if(y == FLOAT_INFINITY) y = eY;
		if(z == FLOAT_INFINITY) z = eZ;
		if((radius = Tryg3D::GetDistance3D(sX,sY,sZ,x,y,z)) <= 0.0) return objectid;
		rx = Tryg3D::CompressRotation(-(acos((z-sZ)/radius)-90.0));
		rz = Tryg3D::CompressRotation((atan2(y-sY,x-sX)-90.0));
		if((radius-cut_size > cut_size) && (radius-cut_size > 0.0)){
			radius -= cut_size;
		} else {
			radius = FLOAT_DEFECT;
		}
		Tryg3D::GetPointInFront3D(sX,sY,sZ,rx,rz,radius,x,y,z);
		return objectid;
	}

	stock Tryg3D::GetPointInFront3DCol(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
		return Tryg3D::MovePointCol(x,y,z,(x - (radius * floatcos(rx,degrees) * floatsin(rz,degrees))),(y + (radius * floatcos(rx,degrees) * floatcos(rz,degrees))),(z + (radius * floatsin(rx,degrees))),tx,ty,tz);
	}

	stock Tryg3D::GetPointInFront3DColEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:radius, &Float:tx, &Float:ty, &Float:tz){
		new Float:vx,Float:vy,Float:vz,Float:trx,Float:trz;
		Tryg3D::EulerRotate(rx,ry,rz,0.0,1.0,0.0,vx,vy,vz);
		Tryg3D::GetRotationFor2Point3D(0.0,0.0,0.0,vx,vy,vz,trx,trz);
		return Tryg3D::GetPointInFront3DCol(x,y,z,trx,trz,radius,tx,ty,tz);
	}

	stock Float: Tryg3D::GetPointInFrontOfPlayerCol(const playerid, &Float:tx, &Float:ty, const Float:radius){
		new Float:rz,Float:z,T3D:vid = GetPlayerVehicleID(playerid);
		GetPlayerPos(playerid,tx,ty,z);
		if(T3D:vid != 0){
			GetVehicleZAngle(T3D:vid,rz);
		} else {
			GetPlayerFacingAngle(playerid,rz);
		}
		Tryg3D::GetPointInFront3DCol(tx,ty,z,0.0,rz,radius,tx,ty,z);
		return rz;
	}

	stock Tryg3D::GetPointInFrontOfCamera3DCol(const playerid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0){
		new Float:x,Float:y,Float:z;
		GetPlayerCameraPos(playerid,x,y,z);
		Tryg3D::GetPlayerCameraRotation(playerid,rx,rz);
		Tryg3D::GetPointInFront3DCol(x,y,z,rx,rz,radius,tx,ty,tz);
	}
	
	stock Tryg3D::UndergroundFindZ(const Float:x, const Float:y, &Float:z){
		new Float:tmp_float;
		z = 0.0;
		return ColAndreas::RayCastLine(x,y,-0.002,x,y,-100.0,tmp_float,tmp_float,z);
	}

	stock Tryg3D::InteriorFindZ(const Float:px, const Float:py, const Float:pz, const Float:size = 2.0, &Float:z = 0.0){
		new Float:tmp_float;
		z = 0.0;
		return ColAndreas::RayCastLine(px,py,pz+size,px,py,pz-100.0,tmp_float,tmp_float,z);
	}

	stock bool: Tryg3D::IsPointInWater(const Float:x, const Float:y, const Float:z = 0.0){
		new Float:tmp_float;
		return (ColAndreas::RayCastLine(x,y,z+10.0,x,y,z-100.0,tmp_float,tmp_float,tmp_float) == WATER_OBJECT);
	}

	stock bool: Tryg3D::IsPointInUnderground(const Float:x, const Float:y, const Float:z){
		new Float:tmpzA;
		ColAndreas::FindZ_For2DCoord(x,y,tmpzA);
		return (z < tmpzA && !Tryg3D::IsPointInWater(x,y,z));
	}

	stock bool: Tryg3D::IsPointInAir(const Float:x, const Float:y, const Float:z, const bool:interior = false, const Float:max_distance = 2.2){
		new Float:tmpzA;
		if(interior){
			Tryg3D::InteriorFindZ(x,y,z,2.0,tmpzA);
		} else {
			ColAndreas::FindZ_For2DCoord(x,y,tmpzA);
		}
		return (z >= tmpzA+max_distance);
	}

	stock bool: Tryg3D::IsPointInGround(const Float:x, const Float:y, const Float:z, const bool:interior = false, const Float:max_distance = 2.2){
		if(z <= 0.0) return false;
		new Float:tmpzA;
		if(interior){
			Tryg3D::InteriorFindZ(x,y,z,2.0,tmpzA);
		} else {
			ColAndreas::FindZ_For2DCoord(x,y,tmpzA);
		}
		return (z <= tmpzA+max_distance);
	}

	stock Tryg3D::GetPointCollisionFlags(const Float:x, const Float:y, const Float:z, const interiorid = 0){
		new bool:isinterior = false, flag_value;
		if(interiorid != 0){
			flag_value |= POSITION_FLAG_INTERIOR;
			isinterior = true;
		} else {
			flag_value |= POSITION_FLAG_WORLD;
		}
		if(Tryg3D::IsPointInUnderwater(x,y,z)){
			flag_value |= POSITION_FLAG_WATER;
			flag_value |= POSITION_FLAG_UNDERWATER;
		} else if(Tryg3D::IsPointInWater(x,y,z)){
			flag_value |= POSITION_FLAG_WATER;
		} else if(Tryg3D::IsPointInAir(x,y,z,isinterior,2.2)){
			flag_value |= POSITION_FLAG_AIR;
		} else if(Tryg3D::IsPointInUnderground(x,y,z)){
			flag_value |= POSITION_FLAG_UNDERGROUND;
		} else {
			flag_value |= POSITION_FLAG_GROUND;
		}
		return flag_value;
	}

	stock Tryg3D::IsBetweenPlayersIsWall(const playerid, const targetid){
		new Float:xA,Float:yA,Float:zA,Float:xB,Float:yB,Float:zB,Float:T3D:tmp;
		GetPlayerPos(playerid,xA,yA,zA);
		GetPlayerPos(targetid,xB,yB,zB);
		return ColAndreas::RayCastLine(xA,yA,zA,xB,yB,zB,T3D:tmp,T3D:tmp,T3D:tmp);
	}

	stock Tryg3D::IsBetweenPlayerToPointIsWall(const playerid, const Float:x, const Float:y, const Float:z){
		new Float:xA,Float:yA,Float:zA,Float:T3D:tmp;
		GetPlayerPos(playerid,xA,yA,zA);
		return ColAndreas::RayCastLine(xA,yA,zA,x,y,z,T3D:tmp,T3D:tmp,T3D:tmp);
	}

	stock bool: Tryg3D::GetPointInWallForPoint(const Float:x, const Float:y, const Float:z, const Float:radius, &Float:tx, &Float:ty, &Float:tz, const Float:sector = 90.0){
		if(sector <= 0.0 || sector > 360.0) return false;
		new Float:px,Float:py,Float:pz,Float:tmp_dist,Float:near_dist = cellmax,sec_cnt = floatround(360.0/sector);
		if(sec_cnt > 360) sec_cnt = 360;
		for(new i = 0; i < sec_cnt; i++){
			Tryg3D::GetPointInFront3DCol(x,y,z,0.0,Tryg3D::CompressRotation(sector*i),radius,px,py,pz);
			tmp_dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
			if(tmp_dist < near_dist){
				near_dist = tmp_dist;
				tx = px;
				ty = py;
				tz = pz;
			}
		}
		return true;
	}

	stock Tryg3D::SetCameraDirectionLookAt(const playerid, const Float:x, const Float:y, const Float:z, const Float:distance = 5.0, const Float:rx = 20.0, const Float:sector = 90.0){
		new Float:tx,Float:ty,Float:tz, Float:ox,Float:oy,Float:oz,Float:z_angle;
		Tryg3D::GetPointInWallForPoint(x,y,z,distance,ox,oy,oz,sector);
		Tryg3D::GetRotationFor2Point2D(x,y,ox,oy,z_angle);
		Tryg3D::GetPointInFront3D(x,y,z,rx,Tryg3D::CompressRotation(z_angle+180.0),distance,tx,ty,tz);
		SetPlayerCameraPos(playerid,tx,ty,tz);
		SetPlayerCameraLookAt(playerid,x,y,z);
	}
	
	stock bool: Tryg3D::CollisionCheck(const Float:StartX, const Float:StartY, const Float:StartZ, const Float:EndX, const Float:EndY, const Float:EndZ, &Float:x, &Float:y, &Float:z, &Item3D:item_type = Item3D:0, &element_id = 0, const Float:cut_size = 0.0, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL){
		item_type = item_object;
		element_id = 0;
		x = y = z = FLOAT_INFINITY;
		if(Tryg3D::IsCollisionFlag(collision_flags,TRYG3D_COLLISION_FLAG_OBJECT)){
			element_id = ColAndreas::RayCastLine(StartX,StartY,StartZ,EndX,EndY,EndZ,x,y,z);
		}
		if(x == FLOAT_INFINITY) x = EndX;
		if(y == FLOAT_INFINITY) y = EndY;
		if(z == FLOAT_INFINITY) z = EndZ;
		#if ((defined TRYG3D_MOD_VEHICLECOLLISION) || (defined TRYG3D_MOD_PLAYERCOLLISION) || (defined TRYG3D_MOD_ACTORCOLLISION))
			new STREAMER_TAG_AREA:Tryg3D::Area[TRYG3D_MAX_AREA_CHECK], Float:T3D:dist, Tryg3D::AreaCount, Tryg3D::ExtraArray[2],
				Float:T3D:LastDistVehicle = cellmax, Float:T3D:LastDistPlayer = cellmax, Float:T3D:LastDistActor = cellmax,
				T3D:NearestVehicle = INVALID_VEHICLE_ID, T3D:NearestPlayer = INVALID_PLAYER_ID, T3D:NearestActor = INVALID_ACTOR_ID,
				Float:vx, Float:vy, Float:vz, Float:tx, Float:ty, Float:tz;
				
			Tryg3D::AreaCount = GetNumberDynamicAreasForLine(StartX,StartY,StartZ,x,y,z);
			if(Tryg3D::AreaCount > 0){
				GetDynamicAreasForLine(StartX,StartY,StartZ,x,y,z,Tryg3D::Area,sizeof(Tryg3D::Area));
				for(new k = 0; k < Tryg3D::AreaCount; k++){
					if(Tryg3D::AreaCount > TRYG3D_MAX_AREA_CHECK) break;
					Tryg3D::ExtraArray[0] = Tryg3D::ExtraArray[1] = 0;
					Streamer::GetArrayData(STREAMER_TYPE_AREA,Tryg3D::Area[k],E_STREAMER_EXTRA_ID,Tryg3D::ExtraArray);
					
					#if defined TRYG3D_MOD_VEHICLECOLLISION
						if(Tryg3D::VehicleCollisionSystem && Tryg3D::IsCollisionFlag(collision_flags,TRYG3D_COLLISION_FLAG_VEHICLE) && Tryg3D::ExtraArray[0] == TRYG3D_EXTRA_DATA_FLAG_VEHICLE){
							if(IsValidVehicle(Tryg3D::ExtraArray[1]) && Tryg3D::ExtraArray[1] != ignore_vehicle){
								if(Tryg3D::Area[k] == Tryg3D::VehicleCollisionZone[Tryg3D::ExtraArray[1]] && Tryg3D::VehicleCollisionUsed[Tryg3D::ExtraArray[1]]){
									GetVehiclePos(Tryg3D::ExtraArray[1],vx,vy,vz);
									if((T3D:dist = Tryg3D::GetDistance3D(StartX,StartY,StartZ,vx,vy,vz)) < T3D:LastDistVehicle){
										T3D:LastDistVehicle = T3D:dist;
										T3D:NearestVehicle = Tryg3D::ExtraArray[1];
									}
								}
							}
						}
					#else
						#pragma unused ignore_vehicle
					#endif
					#if defined TRYG3D_MOD_PLAYERCOLLISION
						if(Tryg3D::PlayerCollisionSystem && Tryg3D::IsCollisionFlag(collision_flags,TRYG3D_COLLISION_FLAG_PLAYER) && Tryg3D::ExtraArray[0] == TRYG3D_EXTRA_DATA_FLAG_PLAYER){
							if(IsPlayerConnected(Tryg3D::ExtraArray[1]) && Tryg3D::ExtraArray[1] != ignore_player){
								if(Tryg3D::Area[k] == Tryg3D::PlayerCollisionZone[Tryg3D::ExtraArray[1]] && Tryg3D::PlayerCollisionUsed[Tryg3D::ExtraArray[1]]){
									GetPlayerPos(Tryg3D::ExtraArray[1],vx,vy,vz);
									if((T3D:dist = Tryg3D::GetDistance3D(StartX,StartY,StartZ,vx,vy,vz)) < T3D:LastDistPlayer){
										T3D:LastDistPlayer = T3D:dist;
										T3D:NearestPlayer = Tryg3D::ExtraArray[1];
									}
								}
							}
						}
					#else
						#pragma unused ignore_player
					#endif
					#if defined TRYG3D_MOD_ACTORCOLLISION
						if(Tryg3D::ActorCollisionSystem && Tryg3D::IsCollisionFlag(collision_flags,TRYG3D_COLLISION_FLAG_ACTOR) && Tryg3D::ExtraArray[0] == TRYG3D_EXTRA_DATA_FLAG_ACTOR){
							if(IsValidActor(Tryg3D::ExtraArray[1]) && Tryg3D::ExtraArray[1] != ignore_actor){
								if(Tryg3D::Area[k] == Tryg3D::ActorCollisionZone[Tryg3D::ExtraArray[1]] && Tryg3D::ActorCollisionUsed[Tryg3D::ExtraArray[1]]){
									GetActorPos(Tryg3D::ExtraArray[1],vx,vy,vz);
									if((T3D:dist = Tryg3D::GetDistance3D(StartX,StartY,StartZ,vx,vy,vz)) < T3D:LastDistActor){
										T3D:LastDistActor = T3D:dist;
										T3D:NearestActor = Tryg3D::ExtraArray[1];
									}
								}
							}
						}
					#else
						#pragma unused ignore_actor
					#endif
				}
			}
			if(T3D:NearestVehicle != INVALID_VEHICLE_ID && T3D:LastDistVehicle < T3D:LastDistPlayer && T3D:LastDistVehicle < T3D:LastDistActor){
				new Float:T3D:sx, Float:T3D:sy, Float:T3D:sz;
				item_type = item_vehicle;
				element_id = T3D:NearestVehicle;
				GetVehiclePos(T3D:NearestVehicle,vx,vy,vz);
				GetVehicleModelInfo(GetVehicleModel(T3D:NearestVehicle),VEHICLE_MODEL_INFO_SIZE,T3D:sx,T3D:sy,T3D:sz);
				Tryg3D::GetPointFor2Point3DEx(StartX,StartY,StartZ,vx,vy,vz,Tryg3D::GetDistance3D(StartX,StartY,StartZ,vx,vy,vz)-VectorSize((T3D:sx/2.0),(T3D:sy/2.0),(T3D:sz/2.0)),tx,ty,tz);
				if(cut_size > 0.0){
					Tryg3D::GetPointFor2Point3DEx(StartX,StartY,StartZ,tx,ty,tz,(Tryg3D::GetDistance3D(StartX,StartY,StartZ,tx,ty,tz)-cut_size),x,y,z);
				} else {
					x = tx;
					y = ty;
					z = tz;
				}
				return true;
			} else if(T3D:NearestPlayer != INVALID_PLAYER_ID && T3D:LastDistPlayer < T3D:LastDistVehicle && T3D:LastDistPlayer < T3D:LastDistActor){
				item_type = item_player;
				element_id = T3D:NearestPlayer;
				GetPlayerPos(T3D:NearestPlayer,tx,ty,tz);
				if(cut_size > 0.0){
					Tryg3D::GetPointFor2Point3DEx(StartX,StartY,StartZ,tx,ty,tz,(Tryg3D::GetDistance3D(StartX,StartY,StartZ,tx,ty,tz)-cut_size),x,y,z);
				} else {
					x = tx;
					y = ty;
					z = tz;
				}
				return true;
			} else if(T3D:NearestActor != INVALID_PLAYER_ID && T3D:LastDistActor < T3D:LastDistVehicle && T3D:LastDistActor < T3D:LastDistPlayer){
				item_type = item_actor;
				element_id = T3D:NearestActor;
				GetActorPos(T3D:NearestActor,tx,ty,tz);
				if(cut_size > 0.0){
					Tryg3D::GetPointFor2Point3DEx(StartX,StartY,StartZ,tx,ty,tz,(Tryg3D::GetDistance3D(StartX,StartY,StartZ,tx,ty,tz)-cut_size),x,y,z);
				} else {
					x = tx;
					y = ty;
					z = tz;
				}
				return true;
			}
		#else
			if(cut_size > 0.0){
				Tryg3D::GetPointFor2Point3DEx(StartX,StartY,StartZ,EndX,EndY,EndZ,(Tryg3D::GetDistance3D(StartX,StartY,StartZ,EndX,EndY,EndZ)-cut_size),x,y,z);
			} else {
				x = EndX;
				y = EndY;
				z = EndZ;
			}
			#pragma unused ignore_vehicle
			#pragma unused ignore_player
			#pragma unused ignore_actor
		#endif
		return element_id > 0;
	}

	stock bool: Tryg3D::GetWallRotation(const Float:sx, const Float:sy, const Float:sz, const Float:ex, const Float:ey, const Float:ez, &Float:rx, &Float:rz, &Float:px = 0.0, &Float:py = 0.0, &Float:pz = 0.0, const Float:size = 1.0, const Float:cut_size = 0.0){
		new Float:line_rx, Float:line_rz, Float:T3D:tmp;
		if(!Tryg3D::GetRotationFor2Point3D(sx,sy,sz,ex,ey,ez,line_rx,line_rz)) return false;
		
		new VecStart[4][Vectors3D], VecEnd[4][Vectors3D], VecProduct[4][Vectors3D];
		
		//Start: Right -> Left
		Tryg3D::GetPointInFront3D(sx,sy,sz,line_rx,Tryg3D::CompressRotation(line_rz-90.0),size,VecStart[0][T3D:X],VecStart[0][T3D:Y],VecStart[0][T3D:Z]);
		Tryg3D::GetPointInFront3D(sx,sy,sz,line_rx,Tryg3D::CompressRotation(line_rz+90.0),size,VecStart[1][T3D:X],VecStart[1][T3D:Y],VecStart[1][T3D:Z]);
		
		//Start: Down -> Up
		Tryg3D::GetPointInFront3D(sx,sy,sz,Tryg3D::CompressRotation(line_rx-90.0),line_rz,size,VecStart[2][T3D:X],VecStart[2][T3D:Y],VecStart[2][T3D:Z]);
		Tryg3D::GetPointInFront3D(sx,sy,sz,Tryg3D::CompressRotation(line_rx+90.0),line_rz,size,VecStart[3][T3D:X],VecStart[3][T3D:Y],VecStart[3][T3D:Z]);
		
		//End: Right -> Left
		Tryg3D::GetPointInFront3D(ex,ey,ez,line_rx,Tryg3D::CompressRotation(line_rz-90.0),size,VecEnd[0][T3D:X],VecEnd[0][T3D:Y],VecEnd[0][T3D:Z]);
		Tryg3D::GetPointInFront3D(ex,ey,ez,line_rx,Tryg3D::CompressRotation(line_rz+90.0),size,VecEnd[1][T3D:X],VecEnd[1][T3D:Y],VecEnd[1][T3D:Z]);
		
		//End: Down -> Up
		Tryg3D::GetPointInFront3D(ex,ey,ez,Tryg3D::CompressRotation(line_rx-90.0),line_rz,size,VecEnd[2][T3D:X],VecEnd[2][T3D:Y],VecEnd[2][T3D:Z]);
		Tryg3D::GetPointInFront3D(ex,ey,ez,Tryg3D::CompressRotation(line_rx+90.0),line_rz,size,VecEnd[3][T3D:X],VecEnd[3][T3D:Y],VecEnd[3][T3D:Z]);

		for(new i = 0; i < 4; i++){
			Tryg3D::GetPointFor2Point3DEx(VecStart[1][T3D:X],VecStart[1][T3D:Y],VecStart[1][T3D:Z],VecEnd[i][T3D:X],VecEnd[i][T3D:Y],VecEnd[i][T3D:Z],20000.0,VecEnd[i][T3D:X],VecEnd[i][T3D:Y],VecEnd[i][T3D:Z]);
			Tryg3D::MovePointCol(VecStart[i][T3D:X],VecStart[i][T3D:Y],VecStart[i][T3D:Z],VecEnd[i][T3D:X],VecEnd[i][T3D:Y],VecEnd[i][T3D:Z],VecProduct[i][T3D:X],VecProduct[i][T3D:Y],VecProduct[i][T3D:Z]);
		}
		
		Tryg3D::MovePointColCutLine(sx,sy,sz,ex,ey,ez,px,py,pz,cut_size);
		
		if(!Tryg3D::GetRotationFor2Point3D(VecProduct[0][T3D:X],VecProduct[0][T3D:Y],VecProduct[0][T3D:Z],VecProduct[1][T3D:X],VecProduct[1][T3D:Y],VecProduct[1][T3D:Z],T3D:tmp,rz)) return false;
		if(!Tryg3D::GetRotationFor2Point3D(VecProduct[2][T3D:X],VecProduct[2][T3D:Y],VecProduct[2][T3D:Z],VecProduct[3][T3D:X],VecProduct[3][T3D:Y],VecProduct[3][T3D:Z],rx,T3D:tmp)) return false;
		return true;
	}
	
	stock Tryg3D::GetGroundRotation(const Float:x, const Float:y, const Float:size, &Float:rx, &Float:ry){
		new Float:tpx1,Float:tpy1,Float:tpz1, Float:tpx2,Float:tpy2,Float:tpz2, Float:T3D:tmp;
		Tryg3D::GetPointInFront2D(x,y,0.0,size,tpx1,tpy1);
		Tryg3D::GetPointInFront2D(x,y,180.0,size,tpx2,tpy2);
		ColAndreas::FindZ_For2DCoord(tpx1,tpy1,tpz1);
		ColAndreas::FindZ_For2DCoord(tpx2,tpy2,tpz2);
		Tryg3D::GetRotationFor2Point3D(tpx1,tpy1,tpz1,tpx2,tpy2,tpz2,rx,T3D:tmp);
		
		Tryg3D::GetPointInFront2D(x,y,90.0,size,tpx1,tpy1);
		Tryg3D::GetPointInFront2D(x,y,270.0,size,tpx2,tpy2);
		ColAndreas::FindZ_For2DCoord(tpx1,tpy1,tpz1);
		ColAndreas::FindZ_For2DCoord(tpx2,tpy2,tpz2);
		Tryg3D::GetRotationFor2Point3D(tpx1,tpy1,tpz1,tpx2,tpy2,tpz2,ry,T3D:tmp);
	}
	
	#if defined TRYG3D_MOD_VEHICLE

		stock Tryg3D::GetPointInFrontOfVehicleCol(const vehicleid, &Float:tx, &Float:ty, &Float:tz, const Float:radius, &Float:rx = 0.0, &Float:rz = 0.0){
			new Float:ry,Float:x,Float:y,Float:z;
			GetVehiclePos(vehicleid,x,y,z);
			Tryg3D::GetVehicleRotation(vehicleid,rx,ry,rz);
			Tryg3D::GetPointInFront3DCol(x,y,z,rx,rz,radius,tx,ty,tz);
		}
		
	#endif
	
	#if defined TRYG3D_MOD_PLAYER
	
		stock Float: Tryg3D::GetPointInFrontOfCamera2DCol(const playerid, &Float:tx, &Float:ty, const Float:radius){
			new Float:x,Float:y,Float:z,Float:rz;
			GetPlayerCameraPos(playerid,x,y,z);
			Tryg3D::GetPlayerCameraZAngle(playerid,rz);
			Tryg3D::GetPointInFront3DCol(x,y,z,0.0,rz,radius,tx,ty,z);
			return rz;
		}
		
		stock bool: Tryg3D::IsPointInWaterFrontOfPlayer(const playerid, const Float:radius){
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid,x,y,z);
			Tryg3D::GetPointInFrontOfPlayer(playerid,x,y,radius);
			return Tryg3D::IsPointInWater(x,y,0.0);
		}
		
	#endif
	
	stock bool: Tryg3D::IsPointInSphericalSectorEx(const Float:px, const Float:py, const Float:pz, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT){
		new Item3D:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
		if(Tryg3D::CollisionCheck(x,y,z,px,py,pz,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags)) return false;
		return Tryg3D::IsPointInSphericalSector(px,py,pz,x,y,z,rx,rz,radius,vrx,vrz);
	}

#endif

/********************************
 * Draw3D Functions             *
 ********************************/

#if defined TRYG3D_MOD_DRAW3D
	
	stock Tryg3D::DrawCircle3D(const Float:x, const Float:y, const Float:z, const Float:radius, Float:points[][3], const max_sector = 36, const Float:rx = 90.0, const Float:ry = 0.0, const max_points = sizeof(points)){
		new idx = 0, Float:mercury = (360.0 / max_sector), Float:px, Float:py, Float:pz;
		for(new Float:rz = 0.0; rz < 360.0; rz += mercury){
			Tryg3D::GetPointInFront3D(0.0,0.0,0.0,0.0,rz,radius,px,py,pz);
			Tryg3D::ShiftOffsetToPosition(x,y,z,Tryg3D::CompressRotation(rx-90.0),ry,0.0,px,py,pz,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
		}
		return idx;
	}
	
	stock Tryg3D::DrawCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points)){
		if(max_circles < 2) return 0;
		new idx = 0, Float:mercury = (360.0 / max_sector), Float:trx, Float:trz;
		if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return 0;
		new Float:tx, Float:ty, Float:tz, Float:px, Float:py, Float:pz, Float:dist = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB)/(max_circles-1);
		for(new i = 0; i < max_circles; i++){
			Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,dist*i,tx,ty,tz);
			for(new Float:rz = 0.0; rz < 360.0; rz += mercury){
				Tryg3D::GetPointInFront3D(0.0,0.0,0.0,0.0,rz,radius,px,py,pz);
				Tryg3D::ShiftOffsetToPosition(tx,ty,tz,Tryg3D::CompressRotation(trx-90.0),0.0,Tryg3D::CompressRotation(trz),px,py,pz,points[idx][0],points[idx][1],points[idx][2]);
				idx++;
				if(idx >= max_points) return idx;
			}
		}
		return idx;
	}

	stock Tryg3D::DrawSphere(const Float:x, const Float:y, const Float:z, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points)){
		if(max_circles < 2) return 0;
		new idx = 0, Float:mercury = (360.0 / max_sector), Float:trx, Float:trz, Float:xA, Float:yA, Float:zA, Float:xB, Float:yB, Float:zB;
		Tryg3D::GetPointInFront3D(x,y,z,270.0,0.0,radius,xA,yA,zA);
		Tryg3D::GetPointInFront3D(x,y,z,90.0,0.0,radius,xB,yB,zB);
		if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return 0;
		
		points[idx][0] = xA;
		points[idx][1] = yA;
		points[idx][2] = zA;
		idx++;
		if(idx >= max_points) return idx;
		
		new Float:tx, Float:ty, Float:tz, Float:px, Float:py, Float:pz, Float:point_dist = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB), Float:dist = point_dist/(max_circles+1), Float:omega;
		for(new i = 0; i <= max_circles+1; i++){
			if(i == 0){
				Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,dist*(i+0.25),tx,ty,tz);
			} else if(i == max_circles+1){
				Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,dist*(i-0.25),tx,ty,tz);
			} else {
				Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,dist*i,tx,ty,tz);
			}
			omega = (point_dist / 2) - Tryg3D::GetDistance3D(x,y,z,tx,ty,tz);
			for(new Float:rz = 0.0; rz < 360.0; rz += mercury){
				Tryg3D::GetPointInFront3D(0.0,0.0,0.0,0.0,rz,(floatsqroot((2*omega*radius)-floatpower(omega,2))),px,py,pz);
				Tryg3D::ShiftOffsetToPosition(tx,ty,tz,Tryg3D::CompressRotation(trx-90.0),0.0,Tryg3D::CompressRotation(trz),px,py,pz,points[idx][0],points[idx][1],points[idx][2]);
				idx++;
				if(idx >= max_points) return idx;
			}
		}
		
		points[idx][0] = xB;
		points[idx][1] = yB;
		points[idx][2] = zB;
		idx++;
		
		return idx;
	}
	
	stock Tryg3D::DrawCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, Float:points[][3], const max_sector = 36, const max_circles = 5, const max_points = sizeof(points)){
		if(max_circles < 2) return 0;
		new idx = 0, Float:mercury = (360.0 / max_sector), Float:trx, Float:trz;
		if(!Tryg3D::GetRotationFor2Point3D(xA,yA,zA,xB,yB,zB,trx,trz)) return 0;
		
		points[idx][0] = xA;
		points[idx][1] = yA;
		points[idx][2] = zA;
		idx++;
		if(idx >= max_points) return idx;
		
		new Float:tx, Float:ty, Float:tz, Float:px, Float:py, Float:pz, Float:point_dist = Tryg3D::GetDistance3D(xA,yA,zA,xB,yB,zB), Float:dist = point_dist/(max_circles+1), Float:stage_percent;
		for(new i = 1; i <= max_circles+1; i++){
			Tryg3D::GetPointInFront3D(xA,yA,zA,trx,trz,dist*i,tx,ty,tz);
			stage_percent = Tryg3D::GetDistance3D(xA,yA,zA,tx,ty,tz) / point_dist;
			for(new Float:rz = 0.0; rz < 360.0; rz += mercury){
				Tryg3D::GetPointInFront3D(0.0,0.0,0.0,0.0,rz,(stage_percent*radius*2),px,py,pz);
				Tryg3D::ShiftOffsetToPosition(tx,ty,tz,Tryg3D::CompressRotation(trx-90.0),0.0,Tryg3D::CompressRotation(trz),px,py,pz,points[idx][0],points[idx][1],points[idx][2]);
				idx++;
				if(idx >= max_points) return idx;
			}
		}
		
		points[idx][0] = xB;
		points[idx][1] = yB;
		points[idx][2] = zB;
		idx++;
		
		return idx;
	}

	stock Tryg3D::DrawRectangle2D(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, Float:points[][2], const points_per_wall = 36, const max_points = sizeof(points)){
		if(points_per_wall < 3) return 0;
		if(minx > maxx || miny > maxy) return 0;
		new idx = 0, Float:part_size;
		
		points[idx][0] = minx;
		points[idx][1] = miny;
		idx++;
		if(idx >= max_points) return idx;
		part_size = Tryg3D::GetDistance2D(minx,miny,minx,maxy) / (points_per_wall - 1);
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront2D(minx,miny,0.0,part_size*i,points[idx][0],points[idx][1]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = minx;
		points[idx][1] = maxy;
		idx++;
		if(idx >= max_points) return idx;
		part_size = Tryg3D::GetDistance2D(minx,maxy,maxx,maxy) / (points_per_wall - 1);
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront2D(minx,maxy,270.0,part_size*i,points[idx][0],points[idx][1]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = maxx;
		points[idx][1] = maxy;
		idx++;
		if(idx >= max_points) return idx;
		part_size = Tryg3D::GetDistance2D(maxx,maxy,maxx,miny) / (points_per_wall - 1);
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront2D(maxx,maxy,180.0,part_size*i,points[idx][0],points[idx][1]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = maxx;
		points[idx][1] = miny;
		idx++;
		if(idx >= max_points) return idx;
		part_size = Tryg3D::GetDistance2D(maxx,miny,minx,miny) / (points_per_wall - 1);
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront2D(maxx,miny,90.0,part_size*i,points[idx][0],points[idx][1]);
			if(idx >= max_points) return idx;
			idx++;
		}
		
		return idx;
	}
	
	stock Tryg3D::DrawPolygon2D(const Float:polygon_points[], Float:points[][2], const points_per_line = 36, const max_polygon_points = sizeof(polygon_points), const max_points = sizeof(points)){
		if(!Tryg3D::IsValidPolygon(polygon_points,max_polygon_points)) return 0;
		if(points_per_line < 3) return 0;
		new idx = 0, Float:part_size, Float:rz;
		for(new p = 0; p < max_polygon_points-2; p += 2){
			points[idx][0] = polygon_points[p];
			points[idx][1] = polygon_points[p+1];
			idx++;
			if(idx >= max_points) return idx;
			part_size = Tryg3D::GetDistance2D(polygon_points[p],polygon_points[p+1],polygon_points[p+2],polygon_points[p+3]) / (points_per_line - 1);
			Tryg3D::GetRotationFor2Point2D(polygon_points[p],polygon_points[p+1],polygon_points[p+2],polygon_points[p+3],rz);
			for(new i = 1; i < points_per_line-1; i++){
				Tryg3D::GetPointInFront2D(polygon_points[p],polygon_points[p+1],rz,part_size*i,points[idx][0],points[idx][1]);
				idx++;
				if(idx >= max_points) return idx;
			}
		}
		if(!Tryg3D::IsPolygonClosed(polygon_points,max_polygon_points)){
			new p = max_polygon_points-2;
			points[idx][0] = polygon_points[p];
			points[idx][1] = polygon_points[p+1];
			idx++;
			if(idx >= max_points) return idx;
			part_size = Tryg3D::GetDistance2D(polygon_points[p],polygon_points[p+1],polygon_points[0],polygon_points[1]) / (points_per_line - 1);
			Tryg3D::GetRotationFor2Point2D(polygon_points[p],polygon_points[p+1],polygon_points[0],polygon_points[1],rz);
			for(new i = 1; i < points_per_line-1; i++){
				Tryg3D::GetPointInFront2D(polygon_points[p],polygon_points[p+1],rz,part_size*i,points[idx][0],points[idx][1]);
				idx++;
				if(idx >= max_points) return idx;
			}
		}
		return idx;
	}
	
	stock Tryg3D::DrawCube2D(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, Float:points[][3], const points_per_wall = 36, const max_points = sizeof(points)){
		if(points_per_wall < 3) return 0;
		if(minx > maxx || miny > maxy || minz > maxz) return 0;
		new idx = 0, Float:part_size_x, Float:part_size_y, Float:part_size_z;
		
		points[idx][0] = minx;
		points[idx][1] = miny;
		points[idx][2] = minz;
		idx++;
		if(idx >= max_points) return idx;
		
		points[idx][0] = minx;
		points[idx][1] = miny;
		points[idx][2] = maxz;
		idx++;
		if(idx >= max_points) return idx;
		
		part_size_x = Tryg3D::GetDistance1D(minx,maxx) / (points_per_wall - 1);
		part_size_y = Tryg3D::GetDistance1D(miny,maxy) / (points_per_wall - 1);
		part_size_z = Tryg3D::GetDistance1D(minz,maxz) / (points_per_wall - 1);
		
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront3D(minx,miny,minz,0.0,0.0,part_size_y*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(minx,miny,maxz,0.0,0.0,part_size_y*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(minx,miny,minz,90.0,0.0,part_size_z*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = minx;
		points[idx][1] = maxy;
		points[idx][2] = minz;
		idx++;
		if(idx >= max_points) return idx;
		
		points[idx][0] = minx;
		points[idx][1] = maxy;
		points[idx][2] = maxz;
		idx++;
		if(idx >= max_points) return idx;
		
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront3D(minx,maxy,minz,0.0,270.0,part_size_x*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(minx,maxy,maxz,0.0,270.0,part_size_x*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(minx,maxy,minz,90.0,270.0,part_size_z*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = maxx;
		points[idx][1] = maxy;
		points[idx][2] = minz;
		idx++;
		if(idx >= max_points) return idx;
		
		points[idx][0] = maxx;
		points[idx][1] = maxy;
		points[idx][2] = maxz;
		idx++;
		if(idx >= max_points) return idx;
		
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront3D(maxx,maxy,minz,0.0,180.0,part_size_y*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(maxx,maxy,maxz,0.0,180.0,part_size_y*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(maxx,maxy,minz,90.0,180.0,part_size_z*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		points[idx][0] = maxx;
		points[idx][1] = miny;
		points[idx][2] = minz;
		idx++;
		if(idx >= max_points) return idx;
		
		points[idx][0] = maxx;
		points[idx][1] = miny;
		points[idx][2] = maxz;
		idx++;
		if(idx >= max_points) return idx;
		
		for(new i = 1; i < points_per_wall-1; i++){
			Tryg3D::GetPointInFront3D(maxx,miny,minz,0.0,90.0,part_size_x*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(maxx,miny,maxz,0.0,90.0,part_size_x*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
			
			Tryg3D::GetPointInFront3D(maxx,miny,minz,90.0,90.0,part_size_z*i,points[idx][0],points[idx][1],points[idx][2]);
			idx++;
			if(idx >= max_points) return idx;
		}
		
		
		return idx;
	}
	
#endif

/********************************
 * Universal Functions          *
 ********************************/
 
#if defined TRYG3D_MOD_UNIVERSAL

	stock Tryg3D::ItemGetInvalidID(const Item3D:item_type){
		switch(item_type){
			case item_player:				return INVALID_PLAYER_ID;
			case item_npc:					return INVALID_PLAYER_ID;
			
			#if defined TRYG3D_MOD_ACTOR
				case item_actor:			return INVALID_ACTOR_ID;
			#endif
			
			case item_object:				return INVALID_OBJECT_ID;
			case item_vehicle:				return INVALID_VEHICLE_ID;
			
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object:	return INVALID_STREAMER_ID;
				case item_dynamic_pickup:	return INVALID_STREAMER_ID;
				case item_dynamic_cp:		return INVALID_STREAMER_ID;
				case item_dynamic_racecp:	return INVALID_STREAMER_ID;
				case item_dynamic_mapicon:	return INVALID_STREAMER_ID;
				case item_dynamic_3dtext:	return INVALID_STREAMER_ID;
				case item_dynamic_actor:	return INVALID_STREAMER_ID;
			#endif
			
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc:			return INVALID_PLAYER_ID;
			#endif
		}
		return cellmax;
	}

	stock bool: Tryg3D::ItemGetPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:x, &Float:y, &Float:z){
		switch(element_type){
			case item_player: GetPlayerPos(_:elementid,x,y,z);
			case item_npc: {
				#if defined TRYG3D_MOD_FCNPC
					if(FCNPC::IsValid(_:elementid)){
						FCNPC::GetPosition(_:elementid,x,y,z);
					} else {
						GetPlayerPos(_:elementid,x,y,z);
					}
				#else
					GetPlayerPos(_:elementid,x,y,z);
				#endif
			}
			#if defined TRYG3D_MOD_ACTOR
				case item_actor: GetActorPos(_:elementid,x,y,z);
			#endif
			case item_object: GetObjectPos(_:elementid,x,y,z);
			case item_vehicle: GetVehiclePos(_:elementid,x,y,z);
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: GetDynamicObjectPos(STREAMER_TAG_OBJECT:elementid,x,y,z);
				case item_dynamic_pickup: Streamer::GetItemPos(STREAMER_TYPE_PICKUP,_:elementid,x,y,z);
				case item_dynamic_cp: Streamer::GetItemPos(STREAMER_TYPE_CP,_:elementid,x,y,z);
				case item_dynamic_racecp: Streamer::GetItemPos(STREAMER_TYPE_RACE_CP,_:elementid,x,y,z);
				case item_dynamic_mapicon: Streamer::GetItemPos(STREAMER_TYPE_MAP_ICON,_:elementid,x,y,z);
				case item_dynamic_3dtext: Streamer::GetItemPos(STREAMER_TYPE_3D_TEXT_LABEL,_:elementid,x,y,z);
				case item_dynamic_actor: GetDynamicActorPos(STREAMER_TAG_ACTOR:elementid,x,y,z);
			#endif
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: FCNPC::GetPosition(_:elementid,x,y,z);
			#endif
			
			default: return false;
		}
		return true;
	}

	stock Tryg3D::ItemGetVirtualWorld(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type){
		switch(element_type){
			case item_player: return GetPlayerVirtualWorld(_:elementid);
			case item_npc: {
				#if defined TRYG3D_MOD_FCNPC
					if(FCNPC::IsValid(_:elementid)) return FCNPC::GetVirtualWorld(_:elementid);
					return GetPlayerVirtualWorld(_:elementid);
				#else
					return GetPlayerVirtualWorld(_:elementid);
				#endif
			}
			#if defined TRYG3D_MOD_ACTOR
				case item_actor: return GetActorVirtualWorld(_:elementid);
			#endif
			case item_vehicle: return GetVehicleVirtualWorld(_:elementid);
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: return Streamer::GetIntData(STREAMER_TYPE_OBJECT,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_pickup: return Streamer::GetIntData(STREAMER_TYPE_PICKUP,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_cp: return Streamer::GetIntData(STREAMER_TYPE_CP,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_racecp: return Streamer::GetIntData(STREAMER_TYPE_RACE_CP,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_mapicon: return Streamer::GetIntData(STREAMER_TYPE_MAP_ICON,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_3dtext: return Streamer::GetIntData(STREAMER_TYPE_3D_TEXT_LABEL,_:elementid,E_STREAMER_WORLD_ID);
				case item_dynamic_actor: return GetDynamicActorVirtualWorld(STREAMER_TAG_ACTOR:elementid);
			#endif
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: return FCNPC::GetVirtualWorld(_:elementid);
			#endif
		}
		return TRYG3D_INVALID_VIRTUAL_WORLD;
	}

	stock Tryg3D::ItemGetInterior(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type){
		switch(element_type){
			case item_player: return GetPlayerInterior(_:elementid);
			case item_npc: {
				#if defined TRYG3D_MOD_FCNPC
					if(FCNPC::IsValid(_:elementid)) return FCNPC::GetInterior(_:elementid);
					return GetPlayerInterior(_:elementid);
				#else
					return GetPlayerInterior(_:elementid);
				#endif
			}
			#if defined TRYG3D_MOD_ACTOR
				case item_actor: return -1;
			#endif
			case item_vehicle: {
				#if defined GetVehicleInterior
					return GetVehicleInterior(_:elementid);
				#else
					return -1;
				#endif
			}
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: return Streamer::GetIntData(STREAMER_TYPE_OBJECT,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_pickup: return Streamer::GetIntData(STREAMER_TYPE_PICKUP,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_cp: return Streamer::GetIntData(STREAMER_TYPE_CP,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_racecp: return Streamer::GetIntData(STREAMER_TYPE_RACE_CP,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_mapicon: return Streamer::GetIntData(STREAMER_TYPE_MAP_ICON,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_3dtext: return Streamer::GetIntData(STREAMER_TYPE_3D_TEXT_LABEL,_:elementid,E_STREAMER_INTERIOR_ID);
				case item_dynamic_actor: return Streamer::GetIntData(STREAMER_TYPE_ACTOR,_:elementid,E_STREAMER_INTERIOR_ID);
			#endif
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: return FCNPC::GetInterior(_:elementid);
			#endif
		}
		return TRYG3D_INVALID_VIRTUAL_WORLD;
	}

	stock bool: Tryg3D::ItemGetRotationQuat(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:qw, &Float:qx, &Float:qy, &Float:qz){
		new Float:rx,Float:ry,Float:rz;
		qw = qx = qy = qz = 0.0;
		switch(element_type){
			#if defined TRYG3D_MOD_YSF
				case item_player: GetPlayerRotationQuat(_:elementid,qw,qx,qy,qz);
			#endif
			case item_object: {
				GetObjectRot(_:elementid,rx,ry,rz);
				Tryg3D::EulerToQuat(rx,ry,rz,qw,qx,qy,qz);
				qw *= (-1);
			}
			case item_vehicle: GetVehicleRotationQuat(_:elementid,qw,qx,qy,qz);
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: {
					GetDynamicObjectRot(STREAMER_TAG_OBJECT:elementid,rx,ry,rz);
					Tryg3D::EulerToQuat(rx,ry,rz,qw,qx,qy,qz);
					qw *= (-1);
				}
			#endif
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: FCNPC::GetQuaternion(_:elementid,qw,qx,qy,qz);
			#endif
			default: return true;
		}
		return false;
	}

	stock bool: Tryg3D::ItemGetUpVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, &Float:vx, &Float:vy, &Float:vz){
		new Float:qw,Float:qx,Float:qy,Float:qz;
		if(!Tryg3D::ItemGetRotationQuat(elementid,element_type,qw,qx,qy,qz)) return false;
		switch(element_type){
			case item_object: Tryg3D::GetQuatUpVector(qw,qx,qy,qz,vx,vy,vz);
			case item_vehicle, item_dynamic_vehicle: Tryg3D::GetQuatUpVector(qw,-qx,-qy,-qz,vx,vy,vz);
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: Tryg3D::GetQuatUpVector(qw,qx,qy,qz,vx,vy,vz);
			#endif
			default: return false;
		}
		return true;
	}

	stock bool: Tryg3D::ItemGetUpPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:radius, &Float:x, &Float:y, &Float:z, const bool:reverse = false){
		new Float:vx,Float:vy,Float:vz,Float:rx,Float:rz;
		if(!Tryg3D::ItemGetUpVector(elementid,element_type,vx,vy,vz)) return false;
		Tryg3D::ShiftVectorToRotation(vx,vy,vz,rx,rz);
		if(!Tryg3D::ItemGetPos(elementid,element_type,vx,vy,vz)) return false;
		if(!reverse){
			Tryg3D::GetPointInFront3D(vx,vy,vz,rx,rz,radius,x,y,z);
		} else {
			Tryg3D::GetPointInFront3D(vx,vy,vz,Tryg3D::CompressRotation(rx-180.0),rz,radius,x,y,z);
		}
		return true;
	}

	stock bool: Tryg3D::ItemOnPlayerScreen(const playerid, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ElementOrientation:orientation = o_front, const Float:rx = TRYG3D_INVALID_ROTATION, const Float:rz = TRYG3D_INVALID_ROTATION, const Float:vrx = VERTICAL_CAMERA_RADIUS, const Float:vrz = HORIZONTAL_CAMERA_RADIUS, const bool:testVW = true, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT){
		new Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz,Float:prx,Float:prz,worldid;
		GetPlayerCameraPos(playerid,x,y,z);
		Tryg3D::GetPlayerCameraRotation(playerid,prx,prz);
		worldid = GetPlayerVirtualWorld(playerid);
		if(rx != TRYG3D_INVALID_ROTATION){
			prx = rx;
		} else {
			prx = Tryg3D::CompressRotation(prx+Tryg3D::OrientationRotation[orientation][0]);
		}
		if(rz != TRYG3D_INVALID_ROTATION){
			prz = rz;
		} else {
			prz = Tryg3D::CompressRotation(prz+Tryg3D::OrientationRotation[orientation][1]);
		}
		if(!Tryg3D::ItemGetPos(targetid,target_type,tx,ty,tz)) return false;
		if(testVW){
			new T3D:vw = Tryg3D::ItemGetVirtualWorld(targetid,target_type);
			if(T3D:vw != worldid && T3D:vw != -1) return false;
		}
		return Tryg3D::IsPointInSphericalSectorEx(tx,ty,tz,x,y,z,prx,prz,Tryg3D::StreamDistance,vrx,vrz,ignore_vehicle,ignore_player,ignore_actor,collision_flags);
	}

	stock bool: Tryg3D::ItemOnFakeScreen(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const Float:rx, const Float:rz, const Float:vrx = VERTICAL_CAMERA_RADIUS, const Float:vrz = HORIZONTAL_CAMERA_RADIUS, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT){
		new Float:tx,Float:ty,Float:tz;
		if(!Tryg3D::ItemGetPos(targetid,target_type,tx,ty,tz)) return false;
		return Tryg3D::IsPointInSphericalSectorEx(tx,ty,tz,x,y,z,rx,rz,Tryg3D::StreamDistance,vrx,vrz,ignore_vehicle,ignore_player,ignore_actor,collision_flags);
	}

	stock Float: Tryg3D::ItemGetDistance(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type){
		new Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,x,y,z)) return -1.0;
		if(!Tryg3D::ItemGetPos(targetid,target_type,tx,ty,tz)) return -1.0;
		return Tryg3D::GetDistance3D(x,y,z,tx,ty,tz);
	}

	stock Float: Tryg3D::ItemGetDistanceFromPoint(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z){
		new Float:tx,Float:ty,Float:tz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,tx,ty,tz)) return -1.0;
		return Tryg3D::GetDistance3D(x,y,z,tx,ty,tz);
	}

	stock bool: Tryg3D::ItemInCircle(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:radius){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCircle(px,py,x,y,radius);
	}

	stock bool: Tryg3D::ItemInCylinder3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCylinder3D(px,py,pz,xA,yA,zA,xB,yB,zB,radius);
	}

	stock bool: Tryg3D::ItemInCylinder2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCylinder2D(px,py,pz,x,y,minz,maxz,radius);
	}

	stock bool: Tryg3D::ItemInSphere(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:radius){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInSphere(px,py,pz,x,y,z,radius);
	}

	stock bool: Tryg3D::ItemInRectangle(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:minx, const Float:miny, const Float:maxx, const Float:maxy){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInRectangle(px,py,minx,miny,maxx,maxy);
	}

	stock bool: Tryg3D::ItemInCube(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:minx, const Float:miny, const Float:minz,Float:maxx, const Float:maxy, const Float:maxz){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCube(px,py,pz,minx,miny,minz,maxx,maxy,maxz);
	}

	stock bool: Tryg3D::ItemInPolygon(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:points[], const maxpoints = sizeof(points)){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInPolygon(px,py,points,maxpoints);
	}

	stock bool: Tryg3D::ItemInCircularSector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:rz, const Float:radius, const Float:view_angle){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCircularSector(px,py,x,y,rz,radius,view_angle);
	}

	stock bool: Tryg3D::ItemInSphericalSector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInSphericalSector(px,py,pz,x,y,z,rx,rz,radius,vrx,vrz);
	}

	stock bool: Tryg3D::ItemInCone2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCone2D(px,py,pz,x,y,minz,maxz,radius_a,radius_b);
	}

	stock bool: Tryg3D::ItemInCone3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius_a, const Float:radius_b){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCone3D(px,py,pz,xA,yA,zA,xB,yB,zB,radius_a,radius_b);
	}

	stock bool: Tryg3D::ItemInCube3D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInCube3D(px,py,pz,x,y,z,rx,ry,rz,size_x,size_y,size_z);
	}

	stock bool: Tryg3D::ItemInEllipse(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:cx, const Float:cy, const Float:size_x, const Float:size_y){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInEllipse(px,py,cx,cy,size_x,size_y);
	}

	stock bool: Tryg3D::ItemInEllipticalCylinder2D(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		return Tryg3D::IsPointInEllipticalCylinder(px,py,pz,cx,cy,minz,maxz,size_x,size_y);
	}

	stock bool: Tryg3D::ItemGetToPointVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz){
		new Float:px,Float:py,Float:pz,Float:rx,Float:rz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		if(Tryg3D::GetRotationFor2Point3D(px,py,pz,tx,ty,tz,rx,rz)){
			Tryg3D::ShiftRotationToVector(rx,rz,vx,vy,vz);
			return true;
		} else {
			vx = vy = vz = 0.0;
			return false;
		}
	}

	stock bool: Tryg3D::ItemGetRotatedVector(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:tx, const Float:ty, const Float:tz, &Float:vx, &Float:vy, &Float:vz, const bool:return_vector = true, const Float:rx = 0.0, const Float:ry = 0.0, const Float:rz = 0.0){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		if(return_vector){
			Tryg3D::ShiftLineRotationVector(px,py,pz,tx,ty,tz,rx,ry,rz,vx,vy,vz);
		} else {
			Tryg3D::ShiftLineRotation(px,py,pz,tx,ty,tz,rx,ry,rz,vx,vy,vz);
		}
		return true;
	}

	stock bool: Tryg3D::ItemGetOrientationPos(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const ElementOrientation:orientation, const Float:distance, &Float:tx, &Float:ty, &Float:tz){
		new Float:x,Float:y,Float:z,Float:rx,Float:ry,Float:rz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,x,y,z)) return false;
		switch(element_type){
			case item_player: GetPlayerFacingAngle(_:elementid,rz);
			case item_npc: {
				#if defined TRYG3D_MOD_FCNPC
					if(FCNPC::IsValid(_:elementid)){
						rz = FCNPC::GetAngle(_:elementid);
					} else {
						GetPlayerFacingAngle(_:elementid,rz);
					}
				#else
					GetPlayerFacingAngle(_:elementid,rz);
				#endif
			}
			#if defined TRYG3D_MOD_ACTOR
				case item_actor: GetActorFacingAngle(_:elementid,rz);
			#endif
			case item_object: GetObjectRot(_:elementid,rx,ry,rz);
			case item_vehicle: Tryg3D::GetVehicleRotation(_:elementid,rx,ry,rz);
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: GetDynamicObjectRot(STREAMER_TAG_OBJECT:elementid,rx,ry,rz);
				case item_dynamic_actor: GetDynamicActorFacingAngle(STREAMER_TAG_ACTOR:elementid,rz);
			#endif
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: rz = FCNPC::GetAngle(_:elementid);
			#endif
			default: return false;
		}
		
		switch(element_type){
			case item_player, item_npc, item_actor, item_dynamic_actor, item_fcnpc: {
				Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::CompressRotation(rx+Tryg3D::OrientationRotation[orientation][0]),Tryg3D::CompressRotation(rz+Tryg3D::OrientationRotation[orientation][1]),distance,tx,ty,tz);
			}
			case item_vehicle, item_object, item_dynamic_object, item_dynamic_vehicle: {
				switch(orientation){
					case o_left:		Tryg3D::GetPointInFront3D(x,y,z,ry,Tryg3D::CompressRotation(rz+90.0),distance,tx,ty,tz);
					case o_right:		Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz+90.0),distance,tx,ty,tz);
					case o_up:			Tryg3D::ItemGetUpPos(elementid,element_type,distance,tx,ty,tz);
					case o_down:		Tryg3D::ItemGetUpPos(elementid,element_type,distance,tx,ty,tz,true);
					case o_front:		Tryg3D::GetPointInFront3D(x,y,z,rx,rz,distance,tx,ty,tz);
					case o_back:		Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::CompressRotation(rx+180.0),rz,distance,tx,ty,tz);
					case o_front_left:	Tryg3D::GetPointInFront3D(x,y,z,ry,Tryg3D::CompressRotation(rz+45.0),distance,tx,ty,tz);
					case o_front_right: Tryg3D::GetPointInFront3D(x,y,z,ry,Tryg3D::CompressRotation(rz-45.0),distance,tx,ty,tz);
					case o_back_left:	Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz-45.0),distance,tx,ty,tz);
					case o_back_right:	Tryg3D::GetPointInFront3D(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz+45.0),distance,tx,ty,tz);
				}
			}
		}
		return true;
	}

	stock bool: Tryg3D::ItemInRangeOfPoint(const Float:x, const Float:y, const Float:z, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE){
		new Float:tx,Float:ty,Float:tz;
		if(!Tryg3D::ItemGetPos(targetid,target_type,tx,ty,tz)) return false;
		#if defined TRYG3D_MOD_COLANDREAS
			new Item3D:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
			if(Tryg3D::CollisionCheck(x,y,z,tx,ty,tz,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags)) return false;
		#else
			#pragma unused ignore_vehicle
			#pragma unused ignore_player
			#pragma unused ignore_actor
			#pragma unused collision_flags
		#endif
		return (Tryg3D::GetDistance3D(x,y,z,tx,ty,tz) <= range);
	}

	stock bool: Tryg3D::ItemInRangeOfItem(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE){
		new Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,x,y,z)) return false;
		if(!Tryg3D::ItemGetPos(targetid,target_type,tx,ty,tz)) return false;
		#if defined TRYG3D_MOD_COLANDREAS
			new Item3D:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
			if(Tryg3D::CollisionCheck(x,y,z,tx,ty,tz,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags)) return false;
		#else
			#pragma unused ignore_vehicle
			#pragma unused ignore_player
			#pragma unused ignore_actor
			#pragma unused collision_flags
		#endif
		return (Tryg3D::GetDistance3D(x,y,z,tx,ty,tz) <= range);
	}

	stock bool: Tryg3D::ItemIsPlayerInRange(const playerid, const Float:range, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type = item_player, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE){
		return Tryg3D::ItemInRangeOfItem(playerid,item_player,range,targetid,target_type,ignore_vehicle,ignore_player,ignore_actor,collision_flags);
	}
	
	#if defined TRYG3D_MOD_STREAMER
		
		stock bool: Tryg3D::ItemInDynamicArea(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const STREAMER_TAG_AREA:areaid){
			new Float:px,Float:py,Float:pz;
			if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
			return IsPointInDynamicArea(areaid,px,py,pz) == 1;
		}

		stock Tryg3D::ItemGetInDynamicArea(const STREAMER_TAG_AREA:areaid, const Item3D:element_type, element_list[], const max_element = sizeof(element_list)){
			new T3D:cnt = 0, T3D:upp = -1;
			switch(element_type){
				case item_player: {
					Tryg3D::Foreach(i){
						if(T3D:upp >= max_element) break;
						if(!IsPlayerNPC(i)){
							if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				
				case item_npc: {
					Tryg3D::Foreach(i){
						if(T3D:upp >= max_element) break;
						if(IsPlayerNPC(i)){
							if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				
				#if defined TRYG3D_MOD_ACTOR
					case item_actor: {
						for(new i = 0, j = GetActorPoolSize(); i <= j; i++){
							if(T3D:upp >= max_element) break;
							if(IsValidActor(i) && Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				#endif
				
				case item_object: {
					for(new i = 0; i < MAX_OBJECTS; i++){
						if(T3D:upp >= max_element) break;
						if(IsValidObject(i) && Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
							element_list[T3D:upp++] = i;
							T3D:cnt++;
						}
					}
				}
				
				case item_vehicle: {
					for(new i = 0, j = GetVehiclePoolSize(); i <= j; i++){
						if(T3D:upp >= max_element) break;
						if(IsValidVehicle(i) && Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
							element_list[T3D:upp++] = i;
							T3D:cnt++;
						}
					}
				}
				
				#if defined TRYG3D_MOD_STREAMER
					case item_dynamic_object: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_OBJECT); i <= j; i++){
							if(IsValidDynamicObject(STREAMER_TAG_OBJECT:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_pickup: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_PICKUP); i <= j; i++){
							if(IsValidDynamicPickup(STREAMER_TAG_PICKUP:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_cp: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_CP); i <= j; i++){
							if(IsValidDynamicCP(STREAMER_TAG_CP:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_racecp: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_RACE_CP); i <= j; i++){
							if(IsValidDynamicRaceCP(STREAMER_TAG_RACE_CP:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_mapicon: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_MAP_ICON); i <= j; i++){
							if(IsValidDynamicMapIcon(STREAMER_TAG_MAP_ICON:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_3dtext: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_3D_TEXT_LABEL); i <= j; i++){
							if(IsValidDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
					case item_dynamic_actor: {
						for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_ACTOR); i <= j; i++){
							if(IsValidDynamicActor(STREAMER_TAG_ACTOR:i)){
								if(T3D:upp >= max_element) break;
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
				#endif
				
				#if defined TRYG3D_MOD_FCNPC
					case item_fcnpc: {
						Tryg3D::Foreach(i){
							if(T3D:upp >= max_element) break;
							if(IsPlayerNPC(i) && FCNPC::IsValid(i)){
								if(Tryg3D::ItemInDynamicArea(i,element_type,areaid)){
									element_list[T3D:upp++] = i;
									T3D:cnt++;
								}
							}
						}
					}
				#endif
			}
			return T3D:cnt;
		}
		
	#endif
	
	#if defined TRYG3D_MOD_COLANDREAS
	
		stock bool: Tryg3D::ItemCollisionToPoint(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL){
			new Float:xB,Float:yB,Float:zB;
			if(!Tryg3D::ItemGetPos(targetid,target_type,xB,yB,zB)) return false;
			new Item3D:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
			return Tryg3D::CollisionCheck(x,y,z,xB,yB,zB,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags);
		}

		stock bool: Tryg3D::ItemCollisionToItem(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_ALL){
			new Float:xA,Float:yA,Float:zA,Float:xB,Float:yB,Float:zB;
			if(!Tryg3D::ItemGetPos(elementid,element_type,xA,yA,zA)) return false;
			if(!Tryg3D::ItemGetPos(targetid,target_type,xB,yB,zB)) return false;
			new Item3D:item_type,element_id,Float:T3D:x,Float:T3D:y,Float:T3D:z;
			return Tryg3D::CollisionCheck(xA,yA,zA,xB,yB,zB,T3D:x,T3D:y,T3D:z,item_type,element_id,0.0,ignore_vehicle,ignore_player,ignore_actor,collision_flags);
		}

		stock Tryg3D::ItemToItemIsWall(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type){
			new Float:xA,Float:yA,Float:zA,Float:xB,Float:yB,Float:zB,Float:T3D:tmp;
			if(!Tryg3D::ItemGetPos(elementid,element_type,xA,yA,zA)) return 0;
			if(!Tryg3D::ItemGetPos(targetid,target_type,xB,yB,zB)) return 0;
			return ColAndreas::RayCastLine(xA,yA,zA,xB,yB,zB,T3D:tmp,T3D:tmp,T3D:tmp);
		}

		stock Tryg3D::ItemToPointIsWall(const Float:x, const Float:y, const Float:z, const TRYG3D_ELEMENT_TAG:targetid, const Item3D:target_type){
			new Float:xB,Float:yB,Float:zB,Float:T3D:tmp;
			if(!Tryg3D::ItemGetPos(targetid,target_type,xB,yB,zB)) return false;
			return ColAndreas::RayCastLine(xB,yB,zB,x,y,z,T3D:tmp,T3D:tmp,T3D:tmp);
		}

		stock Tryg3D::ItemGetCollisionFlags(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type){
			new Float:x,Float:y,Float:z;
			if(!Tryg3D::ItemGetPos(elementid,element_type,x,y,z)) return 0;
			return Tryg3D::GetPointCollisionFlags(x,y,z);
		}

		stock Tryg3D::ItemGetOrientationPosCol(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const ElementOrientation:orientation, const Float:distance, &Float:tx, &Float:ty, &Float:tz){
			new Float:x,Float:y,Float:z,Float:rx,Float:ry,Float:rz;
			if(!Tryg3D::ItemGetPos(elementid,element_type,x,y,z)) return -1;
			switch(element_type){
				case item_player: GetPlayerFacingAngle(_:elementid,rz);
				case item_npc: {
					#if defined TRYG3D_MOD_FCNPC
						if(FCNPC::IsValid(_:elementid)){
							rz = FCNPC::GetAngle(_:elementid);
						} else {
							GetPlayerFacingAngle(_:elementid,rz);
						}
					#else
						GetPlayerFacingAngle(_:elementid,rz);
					#endif
				}
				#if defined TRYG3D_MOD_ACTOR
					case item_actor: GetActorFacingAngle(_:elementid,rz);
				#endif
				case item_object: GetObjectRot(_:elementid,rx,ry,rz);
				case item_vehicle: Tryg3D::GetVehicleRotation(_:elementid,rx,ry,rz);
				#if defined TRYG3D_MOD_STREAMER
					case item_dynamic_object: GetDynamicObjectRot(STREAMER_TAG_OBJECT:elementid,rx,ry,rz);
					case item_dynamic_actor: GetDynamicActorFacingAngle(STREAMER_TAG_ACTOR:elementid,rz);
				#endif
				#if defined TRYG3D_MOD_FCNPC
					case item_fcnpc: rz = FCNPC::GetAngle(_:elementid);
				#endif
				default: return -1;
			}
			
			switch(element_type){
				case item_player, item_npc, item_actor, item_dynamic_actor, item_fcnpc: {
					return Tryg3D::GetPointInFront3DCol(x,y,z,Tryg3D::CompressRotation(rx+Tryg3D::OrientationRotation[orientation][0]),Tryg3D::CompressRotation(rz+Tryg3D::OrientationRotation[orientation][1]),distance,tx,ty,tz);
				}
				case item_vehicle, item_object, item_dynamic_object, item_dynamic_vehicle: {
					switch(orientation){
						case o_left:		return Tryg3D::GetPointInFront3DCol(x,y,z,ry,Tryg3D::CompressRotation(rz+90.0),distance,tx,ty,tz);
						case o_right:		return Tryg3D::GetPointInFront3DCol(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz+90.0),distance,tx,ty,tz);
						case o_up:		{
							new Float:ox,Float:oy,Float:oz;
							Tryg3D::ItemGetUpPos(elementid,element_type,distance,ox,oy,oz);
							return Tryg3D::MovePointCol(x,y,z,ox,oy,oz,tx,ty,tz);
						}
						case o_down:	{
							new Float:ox,Float:oy,Float:oz;
							Tryg3D::ItemGetUpPos(elementid,element_type,distance,ox,oy,oz,true);
							return Tryg3D::MovePointCol(x,y,z,ox,oy,oz,tx,ty,tz);
						}
						case o_front:		return Tryg3D::GetPointInFront3DCol(x,y,z,rx,rz,distance,tx,ty,tz);
						case o_back:		return Tryg3D::GetPointInFront3DCol(x,y,z,Tryg3D::CompressRotation(rx+180.0),rz,distance,tx,ty,tz);
						case o_front_left:	return Tryg3D::GetPointInFront3DCol(x,y,z,ry,Tryg3D::CompressRotation(rz+45.0),distance,tx,ty,tz);
						case o_front_right: return Tryg3D::GetPointInFront3DCol(x,y,z,ry,Tryg3D::CompressRotation(rz-45.0),distance,tx,ty,tz);
						case o_back_left:	return Tryg3D::GetPointInFront3DCol(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz-45.0),distance,tx,ty,tz);
						case o_back_right:	return Tryg3D::GetPointInFront3DCol(x,y,z,Tryg3D::CompressRotation(ry+180.0),Tryg3D::CompressRotation(rz+45.0),distance,tx,ty,tz);
					}
				}
			}
			return -1;
		}

		stock bool: Tryg3D::ItemIsPointInWaterOrient(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Float:radius, const ElementOrientation:orientation = o_front){
			new Float:px,Float:py,Float:pz,Float:x,Float:y,Float:z;
			if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
			if(!Tryg3D::ItemGetOrientationPos(elementid,element_type,orientation,radius,x,y,z)) return false;
			return Tryg3D::IsPointInWater(x,y,0.0);
		}
	
	#endif

#endif

/********************************
 * Cast Functions               *
 ********************************/

#if defined TRYG3D_MOD_CAST3D

	stock Tryg3D::CastExplosion(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0){
		new Float:px, Float:py, Float:pz, T3D:vid;
		if(playerid == -1){
			Tryg3D::Foreach(i){
				T3D:vid = GetPlayerVehicleID(i);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(i,px,py,pz);
				}
				if((GetPlayerInterior(i) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(i) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					CreateExplosionForPlayer(i,x,y,z,type,radius);
				}
			}
		} else {
			if(IsPlayerConnected(playerid)){
				T3D:vid = GetPlayerVehicleID(playerid);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(playerid,px,py,pz);
				}
				if((GetPlayerInterior(playerid) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(playerid) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					CreateExplosionForPlayer(playerid,x,y,z,type,radius);
				}
			}
		}
	}

	stock Tryg3D::CastExplosionDMG(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0, const Float:damage = 82.5, const Float:vehicle_damage = 82.5, const byplayerid = INVALID_PLAYER_ID, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE){
		if(radius <= 0.0) return 0;
		new Float:T3D:health,Float:T3D:armour,T3D:vid,Float:px,Float:py,Float:pz;
		if(playerid == -1){
			Tryg3D::Foreach(i){
				T3D:vid = GetPlayerVehicleID(i);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(i,px,py,pz);
				}
				if((GetPlayerInterior(i) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(i) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					if(Tryg3D::ItemInRangeOfPoint(x,y,z,radius,i,item_player,ignore_vehicle,byplayerid,ignore_actor,collision_flags)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							if(i != byplayerid) SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-vehicle_damage));
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
							if(i != byplayerid) Tryg3D::GivePlayerDamage(i,damage,byplayerid,WEAPON_DYNAMIC_EXPLOSION_DMG,3);
						}
					} else if(collision_flags != TRYG3D_COLLISION_FLAG_NONE && IsPlayerInRangeOfPoint(i,radius,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
						}
					} else if(IsPlayerInRangeOfPoint(i,50.0,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
						}
					} else {
						CreateExplosionForPlayer(i,x,y,z,type,radius);
					}
				}
			}
		} else {
			if(IsPlayerConnected(playerid)){
				T3D:vid = GetPlayerVehicleID(playerid);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(playerid,px,py,pz);
				}
				if((GetPlayerInterior(playerid) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(playerid) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					if(Tryg3D::ItemInRangeOfPoint(x,y,z,radius,playerid,item_player,ignore_vehicle,byplayerid,ignore_actor,collision_flags)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							if(playerid != byplayerid) SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-vehicle_damage));
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
							if(playerid != byplayerid) Tryg3D::GivePlayerDamage(playerid,damage,byplayerid,WEAPON_DYNAMIC_EXPLOSION_DMG,3);
						}
					} else if(collision_flags != TRYG3D_COLLISION_FLAG_NONE && IsPlayerInRangeOfPoint(playerid,radius,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
						}
					} else if(IsPlayerInRangeOfPoint(playerid,50.0,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
						}
					} else {
						CreateExplosionForPlayer(playerid,x,y,z,type,radius);
					}
				}
			}
		}
		return 1;
	}

	stock Tryg3D::CastExplosionRangeDMG(const Float:x, const Float:y, const Float:z, const type, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const Float:distance = 200.0, const Float:min_damage = 10.0, const Float:max_damage = 82.5, const Float:min_vehicle_damage = 50.0, const Float:max_vehicle_damage = 250.0, const byplayerid = INVALID_PLAYER_ID, const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_NONE){
		if(radius <= 0.0) return 0;
		new Float:T3D:health,Float:T3D:armour,T3D:vid,Float:px,Float:py,Float:pz,Float:T3D:dist,Float:T3D:damage;
		if(playerid == -1){
			Tryg3D::Foreach(i){
				T3D:vid = GetPlayerVehicleID(i);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(i,px,py,pz);
				}
				if((GetPlayerInterior(i) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(i) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					if(Tryg3D::ItemInRangeOfPoint(x,y,z,radius,i,item_player,ignore_vehicle,byplayerid,ignore_actor,collision_flags)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							if(i != byplayerid){
								T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
								T3D:damage = (1.0-(T3D:dist/radius))*(max_vehicle_damage-min_vehicle_damage)+min_vehicle_damage;
								SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-T3D:damage));
							}
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
							if(i != byplayerid){
								T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
								T3D:damage = (1.0-(T3D:dist/radius))*(max_damage-min_damage)+min_damage;
								Tryg3D::GivePlayerDamage(i,T3D:damage,byplayerid,WEAPON_DYNAMIC_EXPLOSION_RANGE,3);
							}
						}
					} else if(collision_flags != TRYG3D_COLLISION_FLAG_NONE && IsPlayerInRangeOfPoint(i,radius,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
						}
					} else if(IsPlayerInRangeOfPoint(i,50.0,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(i,T3D:health);
							GetPlayerArmour(i,T3D:armour);
							SetPlayerHealth(i,765.0);
							CreateExplosionForPlayer(i,x,y,z,type,radius);
							SetPlayerHealth(i,T3D:health);
							SetPlayerArmour(i,T3D:armour);
						}
					} else {
						CreateExplosionForPlayer(i,x,y,z,type,radius);
					}
				}
			}
		} else {
			if(IsPlayerConnected(playerid)){
				T3D:vid = GetPlayerVehicleID(playerid);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(playerid,px,py,pz);
				}
				if((GetPlayerInterior(playerid) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(playerid) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= distance)){
					if(Tryg3D::ItemInRangeOfPoint(x,y,z,radius,playerid,item_player,ignore_vehicle,byplayerid,ignore_actor,collision_flags)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							if(playerid != byplayerid){
								T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
								T3D:damage = (1.0-(T3D:dist/radius))*(max_vehicle_damage-min_vehicle_damage)+min_vehicle_damage;
								SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-T3D:damage));
							}
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
							if(playerid != byplayerid){
								T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
								T3D:damage = (1.0-(T3D:dist/radius))*(max_damage-min_damage)+min_damage;
								Tryg3D::GivePlayerDamage(playerid,T3D:damage,byplayerid,WEAPON_DYNAMIC_EXPLOSION_RANGE,3);
							}
						}
					} else if(collision_flags != TRYG3D_COLLISION_FLAG_NONE && IsPlayerInRangeOfPoint(playerid,radius,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
						}
					} else if(IsPlayerInRangeOfPoint(playerid,50.0,x,y,z)){
						if(T3D:vid != 0){
							GetVehicleHealth(T3D:vid,T3D:health);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetVehicleHealth(T3D:vid,T3D:health);
						} else {
							GetPlayerHealth(playerid,T3D:health);
							GetPlayerArmour(playerid,T3D:armour);
							SetPlayerHealth(playerid,765.0);
							CreateExplosionForPlayer(playerid,x,y,z,type,radius);
							SetPlayerHealth(playerid,T3D:health);
							SetPlayerArmour(playerid,T3D:armour);
						}
					} else {
						CreateExplosionForPlayer(playerid,x,y,z,type,radius);
					}
				}
			}
		}
		return 1;
	}

	stock Tryg3D::CastDamage(const weaponid, const bodypart, const Float:damage, const Float:vehicle_damage, const Float:x, const Float:y, const Float:z, const Float:radius, const worldid = -1, const interiorid = -1, const playerid = -1, const byplayerid = INVALID_PLAYER_ID){
		new Float:T3D:health, T3D:vid, Float:px, Float:py, Float:pz;
		if(playerid == -1){
			Tryg3D::Foreach(i){
				T3D:vid = GetPlayerVehicleID(i);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(i,px,py,pz);
				}
				if((GetPlayerInterior(i) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(i) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= radius)){
					if(T3D:vid != 0){
						GetVehicleHealth(T3D:vid,T3D:health);
						if(i != byplayerid) SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-vehicle_damage));
					} else {
						if(i != byplayerid) Tryg3D::GivePlayerDamage(i,damage,byplayerid,weaponid,bodypart);
					}
				}
			}
		} else {
			if(IsPlayerConnected(playerid)){
				T3D:vid = GetPlayerVehicleID(playerid);
				if(T3D:vid != 0){
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(playerid,px,py,pz);
				}
				if((GetPlayerInterior(playerid) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(playerid) == worldid || worldid == -1) && (Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= radius)){
					if(T3D:vid != 0){
						GetVehicleHealth(T3D:vid,T3D:health);
						if(playerid != byplayerid) SetVehicleHealth(T3D:vid,Tryg3D::NLTZF(T3D:health-vehicle_damage));
					} else {
						if(playerid != byplayerid) Tryg3D::GivePlayerDamage(playerid,damage,byplayerid,weaponid,bodypart);
					}
				}
			}
		}
	}

	stock Tryg3D::CastGravity(const Float:x, const Float:y, const Float:z, const Float:radius, Float:power = 1.0, const worldid = -1, const interiorid = -1, const playerid = -1, const byplayerid = INVALID_PLAYER_ID){
		new T3D:vid, Float:T3D:dist, Float:px, Float:py, Float:pz, Float:tx, Float:ty, Float:tz, Float:rx, Float:rz, bool:T3D:invert = false;
		if(power < 0){
			T3D:invert = true;
			power *= -1;
		}
		if(playerid == -1){
			Tryg3D::Foreach(i){
				if(i == byplayerid) continue;
				T3D:vid = GetPlayerVehicleID(i);
				if(T3D:vid != 0){
					if(GetPlayerVehicleSeat(i) != 0) continue;
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(i,px,py,pz);
				}
				T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
				if((GetPlayerInterior(i) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(i) == worldid || worldid == -1) && (T3D:dist <= radius)){
					if(T3D:vid != 0){
						if(T3D:invert){
							Tryg3D::GetRotationFor2Point3D(px,py,pz,x,y,z,rx,rz);
						} else {
							Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,rx,rz);
						}
						Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,(((radius-T3D:dist)/radius)*power),tx,ty,tz);
						SetVehicleVelocity(T3D:vid,tx,ty,tz);
					} else {
						if(T3D:invert){
							Tryg3D::GetRotationFor2Point3D(px,py,pz,x,y,z,rx,rz);
						} else {
							Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,rx,rz);
						}
						Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,(((radius-T3D:dist)/radius)*power),tx,ty,tz);
						SetPlayerVelocity(i,tx,ty,tz);
					}
				}
			}
		} else {
			if(IsPlayerConnected(playerid)){
				T3D:vid = GetPlayerVehicleID(playerid);
				if(T3D:vid != 0){
					if(GetPlayerVehicleSeat(playerid) != 0) return 0;
					GetVehiclePos(T3D:vid,px,py,pz);
				} else {
					GetPlayerPos(playerid,px,py,pz);
				}
				T3D:dist = Tryg3D::GetDistance3D(x,y,z,px,py,pz);
				if((GetPlayerInterior(playerid) == interiorid || interiorid == -1) && (GetPlayerVirtualWorld(playerid) == worldid || worldid == -1) && (T3D:dist <= radius)){
					if(T3D:vid != 0){
						if(T3D:invert){
							Tryg3D::GetRotationFor2Point3D(px,py,pz,x,y,z,rx,rz);
						} else {
							Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,rx,rz);
						}
						Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,(((radius-T3D:dist)/radius)*power),tx,ty,tz);
						SetVehicleVelocity(T3D:vid,tx,ty,tz);
					} else {
						if(T3D:invert){
							Tryg3D::GetRotationFor2Point3D(px,py,pz,x,y,z,rx,rz);
						} else {
							Tryg3D::GetRotationFor2Point3D(x,y,z,px,py,pz,rx,rz);
						}
						Tryg3D::GetPointInFront3D(0.0,0.0,0.0,rx,rz,(((radius-T3D:dist)/radius)*power),tx,ty,tz);
						SetPlayerVelocity(playerid,tx,ty,tz);
					}
				}
			}
		}
		return 1;
	}

#endif

/********************************
 * CatchItems Functions         *
 ********************************/
 
#if defined TRYG3D_MOD_CATCHITEMS
	
	#define T3_GetStreamType(%0) (%0[T3D:type])
	#define T3_IsValidStream(%0) (%0[T3D:type] != s_invalid)
	
	stock bool: Tryg3D::IsPointInStream(const Float:x, const Float:y, const Float:z, const Stream:AreaData[Stream3D]){
		switch(AreaData[T3D:type]){
			case s_circle:					return Tryg3D::IsPointInCircle(x,y,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][9]);
			case s_cylinder2d:				return Tryg3D::IsPointInCylinder2D(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][5],AreaData[T3D:Poly][8],AreaData[T3D:Poly][9]);
			case s_cylinder3d:				return Tryg3D::IsPointInCylinder3D(x,y,z,AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][5],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7],AreaData[T3D:Poly][8],AreaData[T3D:Poly][9]);
			case s_sphere:					return Tryg3D::IsPointInSphere(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][2],AreaData[T3D:Poly][9]);
			case s_rectangle:				return Tryg3D::IsPointInRectangle(x,y,AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7]);
			case s_cube2d:					return Tryg3D::IsPointInCube(x,y,z,AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][5],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7],AreaData[T3D:Poly][8]);
			case s_polygon:					return Tryg3D::IsPointInPolygon(x,y,AreaData[T3D:Poly],TRYG3D_MAX_POLYGON_POINTS * 2);
			case s_circularsector:			return Tryg3D::IsPointInCircularSector(x,y,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][5],AreaData[T3D:Poly][9],AreaData[T3D:Poly][8]);
			case s_sphericalsector:			return Tryg3D::IsPointInSphericalSector(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][2],AreaData[T3D:Poly][3],AreaData[T3D:Poly][5],AreaData[T3D:Poly][9],AreaData[T3D:Poly][6],AreaData[T3D:Poly][8]);
			case s_cone2d:					return Tryg3D::IsPointInCone2D(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][5],AreaData[T3D:Poly][8],AreaData[T3D:Poly][9],AreaData[T3D:Poly][2]);
			case s_cone3d:					return Tryg3D::IsPointInCone3D(x,y,z,AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][5],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7],AreaData[T3D:Poly][8],AreaData[T3D:Poly][0],AreaData[T3D:Poly][1]);
			case s_cube3d:					return Tryg3D::IsPointInCube3D(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][2],AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][5],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7],AreaData[T3D:Poly][8]);
			case s_ellipse:					return Tryg3D::IsPointInEllipse(x,y,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][3],AreaData[T3D:Poly][4]);
			case s_ellipticalcyl2d: 		return Tryg3D::IsPointInEllipticalCylinder(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][5],AreaData[T3D:Poly][8],AreaData[T3D:Poly][3],AreaData[T3D:Poly][4]);
			#if defined TRYG3D_MOD_COLANDREAS
				case a_sphericalsectorex:	return Tryg3D::IsPointInSphericalSectorEx(x,y,z,AreaData[T3D:Poly][0],AreaData[T3D:Poly][1],AreaData[T3D:Poly][2],AreaData[T3D:Poly][3],AreaData[T3D:Poly][4],AreaData[T3D:Poly][9],AreaData[T3D:Poly][6],AreaData[T3D:Poly][7],_:AreaData[T3D:Poly][10],_:AreaData[T3D:Poly][11],_:AreaData[T3D:Poly][12],_:AreaData[T3D:Poly][13]);
			#endif
		}
		return false;
	}

	stock bool: Tryg3D::ItemInStream(const TRYG3D_ELEMENT_TAG:elementid, const Item3D:element_type, const Stream:AreaData[Stream3D], const worldid = -1, const interiorid = -1){
		new Float:px,Float:py,Float:pz;
		if(!Tryg3D::ItemGetPos(elementid,element_type,px,py,pz)) return false;
		if((worldid == -1 || worldid == Tryg3D::ItemGetVirtualWorld(elementid,element_type)) && (interiorid == -1 || interiorid == Tryg3D::ItemGetInterior(elementid,element_type))){
			return Tryg3D::IsPointInStream(px,py,pz,AreaData);
		}
		return true;
	}

	stock Tryg3D::GetInStream(const Stream:AreaData[Stream3D], const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		if(!Tryg3D::IsValidStream(AreaData)) return 0;
		new T3D:cnt = 0, T3D:upp = -1;
		switch(element_type){
			case item_player: {
				Tryg3D::Foreach(i){
					if(T3D:upp >= max_element) break;
					if(!IsPlayerNPC(i)){
						if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
							element_list[T3D:upp++] = _:i;
							T3D:cnt++;
						}
					}
				}
			}
			
			case item_npc: {
				Tryg3D::Foreach(i){
					if(T3D:upp >= max_element) break;
					if(IsPlayerNPC(i)){
						if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
							element_list[T3D:upp++] = i;
							T3D:cnt++;
						}
					}
				}
			}
			
			#if defined TRYG3D_MOD_ACTOR
				case item_actor: {
					for(new i = 0, j = GetActorPoolSize(); i <= j; i++){
						if(T3D:upp >= max_element) break;
						if(IsValidActor(i) && Tryg3D::ItemInStream(i,element_type,AreaData)){
							element_list[T3D:upp++] = i;
							T3D:cnt++;
						}
					}
				}
			#endif
			
			case item_object: {
				for(new i = 0; i < MAX_OBJECTS; i++){
					if(T3D:upp >= max_element) break;
					if(IsValidObject(i) && Tryg3D::ItemInStream(i,element_type,AreaData)){
						element_list[T3D:upp++] = i;
						T3D:cnt++;
					}
				}
			}
			
			case item_vehicle: {
				for(new i = 0, j = GetVehiclePoolSize(); i <= j; i++){
					if(T3D:upp >= max_element) break;
					if(IsValidVehicle(i) && Tryg3D::ItemInStream(i,element_type,AreaData)){
						element_list[T3D:upp++] = i;
						T3D:cnt++;
					}
				}
			}
			
			#if defined TRYG3D_MOD_STREAMER
				case item_dynamic_object: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_OBJECT); i <= j; i++){
						if(IsValidDynamicObject(STREAMER_TAG_OBJECT:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_pickup: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_PICKUP); i <= j; i++){
						if(IsValidDynamicPickup(STREAMER_TAG_PICKUP:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_cp: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_CP); i <= j; i++){
						if(IsValidDynamicCP(STREAMER_TAG_CP:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_racecp: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_RACE_CP); i <= j; i++){
						if(IsValidDynamicRaceCP(STREAMER_TAG_RACE_CP:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_mapicon: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_MAP_ICON); i <= j; i++){
						if(IsValidDynamicMapIcon(STREAMER_TAG_MAP_ICON:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_3dtext: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_3D_TEXT_LABEL); i <= j; i++){
						if(IsValidDynamic3DTextLabel(STREAMER_TAG_3D_TEXT_LABEL:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
				case item_dynamic_actor: {
					for(new i = 1, j = Streamer::GetUpperBound(STREAMER_TYPE_ACTOR); i <= j; i++){
						if(IsValidDynamicActor(STREAMER_TAG_ACTOR:i)){
							if(T3D:upp >= max_element) break;
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
			#endif
			
			#if defined TRYG3D_MOD_FCNPC
				case item_fcnpc: {
					Tryg3D::Foreach(i){
						if(T3D:upp >= max_element) break;
						if(IsPlayerNPC(i) && FCNPC::IsValid(i)){
							if(Tryg3D::ItemInStream(i,element_type,AreaData,worldid,interiorid)){
								element_list[T3D:upp++] = i;
								T3D:cnt++;
							}
						}
					}
				}
			#endif
		}
		return T3D:cnt;
	}

	stock Tryg3D::CatchCircle(const Float:x, const Float:y, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_circle, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][9] = radius;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCylinder2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cylinder2d, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][5] = minz, T3D:AD[T3D:Poly][8] = maxz, T3D:AD[T3D:Poly][9] = radius;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCylinder3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cylinder3d, T3D:AD[T3D:Poly][3] = xA, T3D:AD[T3D:Poly][4] = yA, T3D:AD[T3D:Poly][5] = zA, T3D:AD[T3D:Poly][6] = xB, T3D:AD[T3D:Poly][7] = yB, T3D:AD[T3D:Poly][8] = zB, T3D:AD[T3D:Poly][9] = radius;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchSphere(const Float:x, const Float:y, const Float:z, const Float:radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_sphere, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][2] = z, T3D:AD[T3D:Poly][9] = radius;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchRectangle(const Float:minx, const Float:miny, const Float:maxx, const Float:maxy, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_rectangle, T3D:AD[T3D:Poly][3] = minx, T3D:AD[T3D:Poly][4] = miny, T3D:AD[T3D:Poly][6] = maxx, T3D:AD[T3D:Poly][7] = maxy;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchStreamCube(const Float:minx, const Float:miny, const Float:minz, const Float:maxx, const Float:maxy, const Float:maxz, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cube2d, T3D:AD[T3D:Poly][3] = minx, T3D:AD[T3D:Poly][4] = miny, T3D:AD[T3D:Poly][5] = minz, T3D:AD[T3D:Poly][6] = maxx, T3D:AD[T3D:Poly][7] = maxy, T3D:AD[T3D:Poly][8] = maxz;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchPolygon(const Float:points[], const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list), const maxpoints = sizeof(points)){
		if(maxpoints > TRYG3D_MAX_POLYGON_POINTS * 2) return 0;
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_polygon;
		for(new i = 0; i < maxpoints; i++) T3D:AD[T3D:Poly][i] = points[i];
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCircularSector(const Float:x, const Float:y, const Float:rz, const Float:radius, const Float:view_angle, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_circularsector, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][5] = rz, T3D:AD[T3D:Poly][9] = radius, T3D:AD[T3D:Poly][8] = view_angle;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchSphericalSector(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_sphericalsector, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][2] = z, T3D:AD[T3D:Poly][3] = rx, T3D:AD[T3D:Poly][5] = rz, T3D:AD[T3D:Poly][9] = radius, T3D:AD[T3D:Poly][6] = vrx, T3D:AD[T3D:Poly][8] = vrz;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCone2D(const Float:x, const Float:y, const Float:minz, const Float:maxz, const Float:radius_a, const Float:radius_b, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cone2d, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][5] = minz, T3D:AD[T3D:Poly][8] = maxz, T3D:AD[T3D:Poly][9] = radius_a, T3D:AD[T3D:Poly][2] = radius_b;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCone3D(const Float:xA, const Float:yA, const Float:zA, const Float:xB, const Float:yB, const Float:zB, const Float:pointA_radius, const Float:pointB_radius, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cone3d, T3D:AD[T3D:Poly][3] = xA, T3D:AD[T3D:Poly][4] = yA, T3D:AD[T3D:Poly][5] = zA, T3D:AD[T3D:Poly][6] = xB, T3D:AD[T3D:Poly][7] = yB, T3D:AD[T3D:Poly][8] = zB, T3D:AD[T3D:Poly][0] = pointA_radius, T3D:AD[T3D:Poly][1] = pointB_radius;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchCube3D(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:ry, const Float:rz, const Float:size_x, const Float:size_y, const Float:size_z, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_cube3d, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][2] = z, T3D:AD[T3D:Poly][3] = rx, T3D:AD[T3D:Poly][4] = ry, T3D:AD[T3D:Poly][5] = rz, T3D:AD[T3D:Poly][6] = size_x, T3D:AD[T3D:Poly][7] = size_y, T3D:AD[T3D:Poly][8] = size_z;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchEllipse(const Float:cx,Float:cy, const Float:size_x, const Float:size_y, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_ellipse, T3D:AD[T3D:Poly][0] = cx, T3D:AD[T3D:Poly][1] = cy, T3D:AD[T3D:Poly][3] = size_x, T3D:AD[T3D:Poly][4] = size_y;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchEllipticalCylinder2D(const Float:cx, const Float:cy, const Float:minz, const Float:maxz, const Float:size_x, const Float:size_y, const Item3D:element_type, element_list[], const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = s_ellipticalcyl2d, T3D:AD[T3D:Poly][0] = cx, T3D:AD[T3D:Poly][1] = cy, T3D:AD[T3D:Poly][5] = minz, T3D:AD[T3D:Poly][8] = maxz, T3D:AD[T3D:Poly][3] = size_x, T3D:AD[T3D:Poly][4] = size_y;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}

	stock Tryg3D::CatchSphericalSectorEx(const Float:x, const Float:y, const Float:z, const Float:rx, const Float:rz, const Float:radius, const Float:vrx, const Float:vrz, const Item3D:element_type, element_list[], const ignore_vehicle = INVALID_VEHICLE_ID, const ignore_player = INVALID_PLAYER_ID, const ignore_actor = INVALID_ACTOR_ID, const collision_flags = TRYG3D_COLLISION_FLAG_OBJECT, const worldid = -1, const interiorid = -1, const max_element = sizeof(element_list)){
		new Stream:T3D:AD[Stream3D];
		T3D:AD[T3D:type] = a_sphericalsectorex, T3D:AD[T3D:Poly][0] = x, T3D:AD[T3D:Poly][1] = y, T3D:AD[T3D:Poly][2] = z, T3D:AD[T3D:Poly][3] = rx, T3D:AD[T3D:Poly][4] = rz, T3D:AD[T3D:Poly][9] = radius, T3D:AD[T3D:Poly][6] = vrx, T3D:AD[T3D:Poly][7] = vrz, T3D:AD[T3D:Poly][10] = Float:ignore_vehicle, T3D:AD[T3D:Poly][11] = Float:ignore_player, T3D:AD[T3D:Poly][12] = Float:ignore_actor, T3D:AD[T3D:Poly][13] = Float:collision_flags;
		return Tryg3D::GetInStream(T3D:AD,element_type,element_list,max_element,worldid,interiorid);
	}
	
#endif

/********************************
 * FCNPC Functions              *
 ********************************/
 
#if defined TRYG3D_MOD_FCNPC

	stock bool: FCNPC::InRangeOfPoint(const npcid, const Float:range, const Float:x, const Float:y, const Float:z){
		new Float:px,Float:py,Float:pz;
		FCNPC::GetPosition(npcid,px,py,pz);
		return Tryg3D::GetDistance3D(x,y,z,px,py,pz) <= range;
	}

	stock Float: FCNPC::GetPointInFront(const npcid, &Float:tx, &Float:ty, const Float:radius){
		new Float:rz;
		FCNPC::GetPosition(npcid,tx,ty,rz);
		if(IsPlayerInAnyVehicle(npcid)){
			GetVehicleZAngle(FCNPC::GetVehicleID(npcid),rz);
		} else {
			rz = FCNPC::GetAngle(npcid);
		}
		Tryg3D::GetPointInFront2D(tx,ty,rz,radius,tx,ty);
		return rz;
	}

	stock FCNPC::GetTargetAngle(const npcid, const Float:x, const Float:y, &Float:rz){
		new Float:mx,Float:my;
		FCNPC::GetPosition(npcid,mx,my,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
	}

	stock FCNPC::SetTargetAngle(const npcid, const Float:x, const Float:y, &Float:rz = 0.0){
		new Float:mx,Float:my;
		FCNPC::GetPosition(npcid,mx,my,rz);
		Tryg3D::GetRotationFor2Point2D(mx,my,x,y,rz);
		FCNPC::SetAngle(npcid,rz);
	}

	stock FCNPC::SetVehicleRotation(const npcid, const Float:rx, const Float:ry, const Float:rz){
		new Float:qw,Float:qx,Float:qy,Float:qz;
		Tryg3D::EulerToQuat(rx,ry,rz,qw,qx,qy,qz);
		FCNPC::SetQuaternion(npcid,qw,qx,qy,qz);
	}

	stock bool: FCNPC::SetVehicleTargetRotation(const npcid, const Float:tx, const Float:ty, const Float:tz, const Float:ry = 0.0){
		new Float:x,Float:y,Float:z,Float:rx,Float:rz;
		GetVehiclePos(FCNPC::GetVehicleID(npcid),x,y,z);
		if(Tryg3D::GetRotationFor2Point3D(x,y,z,tx,ty,tz,rx,rz)){
			new Float:qw,Float:qx,Float:qy,Float:qz;
			Tryg3D::EulerToQuat(rx,ry,rz,qw,qx,qy,qz);
			FCNPC::SetQuaternion(npcid,qw,qx,qy,qz);
			return true;
		}
		return false;
	}

	stock FCNPC::GoToAir(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const Float:min_distance = 0.0, const stopdelay = 250){
		FCNPC::SetVehicleTargetRotation(npcid,x,y,z);
		FCNPC::GoTo(npcid,x,y,z,type,speed,FCNPC_MOVE_MODE_NONE,FCNPC_MOVE_PATHFINDING_NONE,0.0,false,min_distance,stopdelay);
	}

	#if defined TRYG3D_MOD_COLANDREAS

		stock Float: FCNPC::GetPointInFrontCol(const npcid, &Float:tx, &Float:ty, const Float:radius){
			new Float:rz,Float:z;
			FCNPC::GetPosition(npcid,tx,ty,z);
			if(IsPlayerInAnyVehicle(npcid)){
				GetVehicleZAngle(FCNPC::GetVehicleID(npcid),rz);
			} else {
				rz = FCNPC::GetAngle(npcid);
			}
			Tryg3D::GetPointInFront3DCol(tx,ty,z,0.0,rz,radius,tx,ty,z);
			return rz;
		}

		stock FCNPC::GoToCol(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 0.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250){
			new Float:px,Float:py,Float:pz,Float:tx,Float:ty,Float:tz;
			FCNPC::GetPosition(npcid,px,py,pz);
			Tryg3D::MovePointColCutLine(px,py,pz,x,y,z,tx,ty,tz,cut_size);
			if(Tryg3D::GetDistance3D(px,py,pz,tx,ty,tz) >= 0.0){
				FCNPC::GoTo(npcid,tx,ty,tz,type,speed,mode,FCNPC_MOVE_PATHFINDING_NONE,0.0,set_angle,min_distance,stopdelay);
			}
		}

		stock FCNPC::GoToPlayerCol(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 0.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250){
			new Float:px,Float:py,Float:pz,Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz;
			GetPlayerPos(playerid,x,y,z);
			FCNPC::GetPosition(npcid,px,py,pz);
			Tryg3D::MovePointColCutLine(px,py,pz,x,y,z,tx,ty,tz,cut_size);
			if(Tryg3D::GetDistance3D(px,py,pz,tx,ty,tz) >= 0.0){
				FCNPC::GoTo(npcid,tx,ty,tz,type,speed,mode,FCNPC_MOVE_PATHFINDING_NONE,0.0,set_angle,min_distance,stopdelay);
			}
		}

		stock FCNPC::GoToPlayerOnGroundCol(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 1.0, const Float:climbing = 2.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250){
			new Float:px,Float:py,Float:pz,Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz;
			GetPlayerPos(playerid,x,y,z);
			FCNPC::GetPosition(npcid,px,py,pz);
			if(Tryg3D::GetDistance1D(pz,z) > climbing) z = pz;
			Tryg3D::MovePointColCutLine(px,py,pz,x,y,z,tx,ty,tz,cut_size);
			if(Tryg3D::GetDistance3D(px,py,pz,tx,ty,tz) >= 0.0){
				FCNPC::GoTo(npcid,tx,ty,tz,type,speed,mode,FCNPC_MOVE_PATHFINDING_NONE,0.0,set_angle,min_distance,stopdelay);
			}
		}

		stock FCNPC::GoToAirCol(const npcid, const Float:x, const Float:y, const Float:z, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const Float:cut_size = 0.0, const Float:min_distance = 0.0, const stopdelay = 250){
			new Float:px,Float:py,Float:pz,Float:tx,Float:ty,Float:tz;
			GetVehiclePos(FCNPC::GetVehicleID(npcid),px,py,pz);
			Tryg3D::MovePointColCutLine(px,py,pz,x,y,z,tx,ty,tz,cut_size);
			if(Tryg3D::GetDistance3D(px,py,pz,tx,ty,tz) >= 0.0){
				FCNPC::SetVehicleTargetRotation(npcid,tx,ty,tz);
				FCNPC::GoTo(npcid,tx,ty,tz,type,speed,FCNPC_MOVE_MODE_NONE,FCNPC_MOVE_PATHFINDING_NONE,0.0,false,min_distance,stopdelay);
			}
		}

		stock FCNPC::SetFloorPos(const npcid){
			new Float:x,Float:y,Float:z, Float:target_z;
			FCNPC::GetPosition(npcid,x,y,z);
			Tryg3D::FindGroundZ(x,y,z,target_z);
			FCNPC::SetPosition(npcid,x,y,target_z+TRYG3D_CHARACTER_GROUND_Z_DIFF);
		}

		#if defined TRYG3D_MOD_VEHICLECOLLISION
			stock FCNPC::GoToPlayerOnGroundColVeh(const npcid, const playerid, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const Float:cut_size = 1.0, const Float:climbing = 2.0, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250){
				new Float:px,Float:py,Float:pz,Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz;
				GetPlayerPos(playerid,x,y,z);
				FCNPC::GetPosition(npcid,px,py,pz);
				if(Tryg3D::GetDistance1D(pz,z) > climbing) z = pz;
				if(Tryg3D::MovePointColWithVehicleCut(px,py,pz,x,y,z,tx,ty,tz,cut_size)){
					FCNPC::GoTo(npcid,tx,ty,tz,type,speed,mode,FCNPC_MOVE_PATHFINDING_NONE,0.0,set_angle,min_distance,stopdelay);
				}
			}
		#endif

		#if defined TRYG3D_MOD_STREAMER
			stock FCNPC::RandomMoveInDynamicArea(const npcid, const STREAMER_TAG_AREA:areaid, const Float:climbing = 2.0, const type = FCNPC_MOVE_TYPE_AUTO, const Float:speed = FCNPC_MOVE_SPEED_AUTO, const mode = FCNPC_MOVE_MODE_AUTO, const bool:set_angle = true, const Float:min_distance = 0.0, const stopdelay = 250){
				if(!FCNPC::IsValid(npcid) || FCNPC::IsDead(npcid)) return 0;
				new Float:x,Float:y,Float:z,Float:tx,Float:ty,Float:tz,Float:T3D:tmp,cnt = 0;
				FCNPC::GetPosition(npcid,x,y,z);
				do {
					if(cnt >= 100) return 0;
					Tryg3D::GetPointInDynamicArea(areaid,tx,ty,tz);
					ColAndreas::FindZ_For2DCoord(tx,ty,tz);
					tz += TRYG3D_CHARACTER_GROUND_Z_DIFF;
					cnt++;
				} while (Tryg3D::IsPointInWater(tx,ty) || ColAndreas::RayCastLine(x,y,z,tx,ty,tz,T3D:tmp,T3D:tmp,T3D:tmp) || Tryg3D::GetDistance1D(tz,z) > climbing || !IsPointInDynamicArea(areaid,tx,ty,tz));
				return FCNPC::GoTo(npcid,tx,ty,tz,type,speed,mode,FCNPC_MOVE_PATHFINDING_NONE,0.0,set_angle,min_distance,stopdelay);
			}
		#endif
	#endif

	#if defined TRYG3D_MOD_STREAMER
		stock FCNPC::SetAbsolutePosition(const npcid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1){
			Streamer::UpdateEx(npcid,x,y,z,worldid,interiorid,-1,compensatedtime,freezeplayer);
			if(worldid != -1) FCNPC::SetVirtualWorld(npcid,worldid);
			if(interiorid != -1) FCNPC::SetInterior(npcid,interiorid);
			FCNPC::SetPosition(npcid,x,y,z);
			FCNPC::SetAngle(npcid,angle);
		}
	#endif
#endif
 
/********************************
 * Streamer Functions           *
 ********************************/

#if defined TRYG3D_MOD_STREAMER

	stock Tryg3D::SetPlayerAbsolutePosition(const playerid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1){
		Streamer::UpdateEx(playerid,x,y,z,worldid,interiorid,-1,compensatedtime,freezeplayer);
		if(worldid != -1) SetPlayerVirtualWorld(playerid,worldid);
		if(interiorid != -1) SetPlayerInterior(playerid,interiorid);
		SetPlayerPos(playerid,x,y,z);
		SetPlayerFacingAngle(playerid,angle);
		SetCameraBehindPlayer(playerid);
		return 1;
	}

	stock Tryg3D::SetPlayerAbsolutePositionVeh(const playerid, const Float:x, const Float:y, const Float:z, const Float:angle, const worldid = -1, const interiorid = -1, const compensatedtime = -1, const freezeplayer = 1){
		new T3D:vehicleid = GetPlayerVehicleID(playerid), seatid;
		if(T3D:vehicleid == 0) return Tryg3D::SetPlayerAbsolutePosition(playerid,x,y,z,angle,worldid,interiorid,compensatedtime,freezeplayer);
		Tryg3D::SetPlayerAbsolutePosition(playerid,x,y,z,angle,worldid,interiorid,compensatedtime,freezeplayer);
		if(worldid != -1) SetVehicleVirtualWorld(T3D:vehicleid,worldid);
		if(interiorid != -1) LinkVehicleToInterior(T3D:vehicleid,interiorid);
		SetVehiclePos(T3D:vehicleid,x,y,z);
		SetVehicleZAngle(T3D:vehicleid,angle);
		PutPlayerInVehicle(playerid,T3D:vehicleid,0);
		if(worldid != -1 || interiorid != -1){
			Tryg3D::Foreach(i){
				if(GetPlayerVehicleID(i) == T3D:vehicleid && (seatid = GetPlayerVehicleSeat(i)) != 0){
					if(worldid != -1) SetPlayerVirtualWorld(i,worldid);
					if(interiorid != -1) SetPlayerInterior(i,interiorid);
					PutPlayerInVehicle(i,T3D:vehicleid,seatid);
				}
			}
		}
		return 1;
	}

	stock bool: Tryg3D::IsVehicleFullyInArea(const vehicleid, const STREAMER_TAG_AREA:areaid){
		new Float:size_x,Float:size_y,Float:size_z, Float:x,Float:y,Float:z, Float:minx,Float:miny,Float:minz, Float:maxx,Float:maxy,Float:maxz;
		GetVehicleModelInfo(GetVehicleModel(vehicleid),VEHICLE_MODEL_INFO_SIZE,size_x,size_y,size_z);
		size_x /= 2.0, size_y /= 2.0, size_z /= 2.0;

		GetVehiclePos(vehicleid,x,y,z);
		
		minx = x - size_x;
		miny = y - size_y;
		minz = z - size_z;
		
		maxx = x + size_x;
		maxy = y + size_y;
		maxz = z + size_z;
		
		if(!IsPointInDynamicArea(areaid,minx,miny,minz)) return false;
		if(!IsPointInDynamicArea(areaid,minx,miny,maxz)) return false;
		if(!IsPointInDynamicArea(areaid,minx,maxy,minz)) return false;
		if(!IsPointInDynamicArea(areaid,minx,maxy,maxz)) return false;
		if(!IsPointInDynamicArea(areaid,maxx,miny,minz)) return false;
		if(!IsPointInDynamicArea(areaid,maxx,miny,maxz)) return false;
		if(!IsPointInDynamicArea(areaid,maxx,maxy,minz)) return false;
		if(!IsPointInDynamicArea(areaid,maxx,maxy,maxz)) return false;
		return true;
	}

	stock Tryg3D::GetPointInDynamicArea(const STREAMER_TAG_AREA:areaid, &Float:tx, &Float:ty, &Float:tz){
		switch(GetDynamicAreaType(areaid)){
			case STREAMER_AREA_TYPE_CIRCLE: {
				new Float:x,Float:y,Float:z,Float:size;
				Streamer::GetItemPos(STREAMER_TYPE_AREA,areaid,x,y,z);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_SIZE,size);
				Tryg3D::GetPointInCircle(x,y,size,tx,ty);
				tz = FLOAT_INFINITY;
				return 1;
			}
			case STREAMER_AREA_TYPE_CYLINDER: {
				new Float:x,Float:y,Float:z,Float:size,Float:minz,Float:maxz;
				Streamer::GetItemPos(STREAMER_TYPE_AREA,areaid,x,y,z);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_Z,minz);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_Z,maxz);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_SIZE,size);
				Tryg3D::GetPointInCylinder2D(x,y,minz,maxz,size,tx,ty,tz);
				return 1;
			}
			case STREAMER_AREA_TYPE_SPHERE: {
				new Float:x,Float:y,Float:z,Float:size;
				Streamer::GetItemPos(STREAMER_TYPE_AREA,areaid,x,y,z);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_SIZE,size);
				Tryg3D::GetPointInSphere(x,y,z,size,tx,ty,tz);
				return 1;
			}
			case STREAMER_AREA_TYPE_RECTANGLE: {
				new Float:minx,Float:miny,Float:maxx,Float:maxy;
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_X,minx);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_Y,miny);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_X,maxx);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_Y,maxy);
				Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
				tz = FLOAT_INFINITY;
				return 1;
			}
			case STREAMER_AREA_TYPE_CUBOID: {
				new Float:minx,Float:miny,Float:minz,Float:maxx,Float:maxy,Float:maxz;
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_X,minx);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_Y,miny);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MIN_Z,minz);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_X,maxx);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_Y,maxy);
				Streamer::GetFloatData(STREAMER_TYPE_AREA,areaid,E_STREAMER_MAX_Z,maxz);
				Tryg3D::GetPointInCube(minx,miny,minz,maxx,maxy,maxz,tx,ty,tz);
				return 1;
			}
		}
		return 0;
	}

#endif

/********************************
 * YSF Functions                *
 ********************************/

#if defined TRYG3D_MOD_YSF

	#define T3_GetPlayerHydraReactorRX(%0)   Tryg3D::CompressRotation((GetPlayerHydraReactorAngle(%0)/55.5555555))
	#define T3_IsPlayerHydraReactorBoost(%0) (GetPlayerHydraReactorAngle(%0) == 0)

	stock Tryg3D::CountTextDraw(){
		new T3D:count = 0;
		for(new i = 0; i < MAX_TEXT_DRAWS; i++) if(IsValidTextDraw(Text:i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountVisibleTextDraw(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_TEXT_DRAWS; i++) if(IsValidTextDraw(Text:i) && IsTextDrawVisibleForPlayer(playerid,Text:i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountPlayerTextDraw(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_PLAYER_TEXT_DRAWS; i++) if(IsValidPlayerTextDraw(playerid,PlayerText:i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountVisiblePlayerTextDraw(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_PLAYER_TEXT_DRAWS; i++) if(IsValidPlayerTextDraw(playerid,PlayerText:i) && IsPlayerTextDrawVisible(playerid,PlayerText:i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountGangZone(){
		new T3D:count = 0;
		for(new i = 0; i < MAX_GANG_ZONES; i++) if(IsValidGangZone(i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountVisibleGangZone(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_GANG_ZONES; i++) if(IsValidGangZone(i) && IsGangZoneVisibleForPlayer(playerid,i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountPlayerGangZone(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_GANG_ZONES; i++) if(IsValidPlayerGangZone(playerid,i)) T3D:count++;
		return T3D:count;
	}

	stock Tryg3D::CountVisiblePlayerGangZone(const playerid){
		new T3D:count = 0;
		for(new i = 0; i < MAX_GANG_ZONES; i++) if(IsValidPlayerGangZone(playerid,i) && IsPlayerGangZoneVisible(playerid,i)) T3D:count++;
		return T3D:count;
	}

	#if defined TRYG3D_MOD_VEHICLE
		stock bool: Tryg3D::IsVehicleOnSpawn(const vehicleid, const Float:check_radius = 1.0){
			new Float:x,Float:y,Float:z,Float:rz,color1,color2;
			GetVehicleSpawnInfo(vehicleid,x,y,z,rz,color1,color2);
			return Tryg3D::IsVehicleInRangeOfPoint(vehicleid,check_radius,x,y,z) == 1;
		}
	#endif

	stock bool: Tryg3D::IsPlayerOnSpawn(const playerid, Float:check_radius = 1.0){
		new teamid,modelid,Float:spawn_x,Float:spawn_y,Float:spawn_z,Float:z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo;
		GetSpawnInfo(playerid,teamid,modelid,spawn_x,spawn_y,spawn_z,z_angle,weapon1,weapon1_ammo,weapon2,weapon2_ammo,weapon3,weapon3_ammo);
		return IsPlayerInRangeOfPoint(playerid,check_radius,spawn_x,spawn_y,spawn_z) == 1;
	}

	stock Tryg3D::GetPlayerRotation(const playerid, &Float:rx, &Float:ry, &Float:rz){
		new Float:qw,Float:qx,Float:qy,Float:qz;
		GetPlayerRotationQuat(playerid,qw,qx,qy,qz);
		Tryg3D::QuatToEuler(rx,ry,rz,qw,qx,qy,qz);
	}

	stock Tryg3D::GetPointInGangZone(const zoneid, &Float:tx, &Float:ty){
		new Float:minx,Float:miny,Float:maxx,Float:maxy;
		GangZoneGetPos(zoneid,minx,miny,maxx,maxy);
		Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
	}

	stock Tryg3D::GetPointInPlayerGangZone(const playerid,zoneid, &Float:tx, &Float:ty){
		new Float:minx,Float:miny,Float:maxx,Float:maxy;
		PlayerGangZoneGetPos(playerid,zoneid,minx,miny,maxx,maxy);
		Tryg3D::GetPointInRectangle(minx,miny,maxx,maxy,tx,ty);
	}
	
#endif

/********************************
 * GrenadeDetection Functions   *
 ********************************/

#if defined TRYG3D_MOD_GRENADEDETECTION

	new Tryg3D::PlayerGrenadeActive[MAX_PLAYERS],
		Tryg3D::GrenadeTimer[MAX_PLAYERS],
		Tryg3D::LastPos[MAX_PLAYERS][Vectors3D];

	forward OnPlayerDroppingGrenade(playerid, weaponid, Float:x, Float:y, Float:z);
	forward OnPlayerGrenadeExplode(playerid, weaponid, Float:x, Float:y, Float:z);

	T3D:function OnGrenadeHoldExpired(playerid, weaponid, Float:x, Float:y, Float:z, Float:angle){
		new time = GetTickCount() - Tryg3D::PlayerGrenadeActive[playerid], fly_time,
			Float:T3D:dist = (time/20.0), Float:points[16][3],
			Float:tx,Float:ty,Float:tz,
			Float:ftx,Float:fty,Float:ftz,
			vehicleid;
		
		Tryg3D::PlayerGrenadeActive[playerid] = 0;
		if(time > 600 && weaponid != 18){
			time = 600;
		} else if(time > 400 && weaponid == 18){
			time = 400;
		}
		if(time < 100){
			time = 100;
		}
		fly_time = 100 + floatround((T3D:dist/15.0)*1000.0) - time;
		Tryg3D::GetPointInFront2D(x,y,angle,T3D:dist,tx,ty);
		Tryg3D::GetArcPoints3D(x,y,z,tx,ty,z,0.0,(T3D:dist/6.0),points,sizeof(points));
		for(new i = 0; i < 15; i++){
			#if defined TRYG3D_MOD_VEHICLECOLLISION
				vehicleid = Tryg3D::MovePointColWithVehicle(points[i][0],points[i][1],points[i][2], points[i+1][0],points[i+1][1],points[i+1][2],ftx,fty,ftz);
			#else
				Tryg3D::MovePointCol(points[i][0],points[i][1],points[i][2], points[i+1][0],points[i+1][1],points[i+1][2],ftx,fty,ftz);
				vehicleid = INVALID_VEHICLE_ID;
			#endif
			if(vehicleid != INVALID_VEHICLE_ID){
				//vehicle collision
				Tryg3D::InteriorFindZ(ftx,fty,ftz,2.0,ftz);
				SetTimerEx("OnPlayerDroppingGrenade",fly_time,false,"ddfff",playerid,weaponid,ftx,fty,ftz);
				if(weaponid == 16) SetTimerEx("OnPlayerGrenadeExplode",fly_time+Tryg3D::ExplosionTime,false,"ddfff",playerid,weaponid,ftx,fty,ftz);
				return 1;
			} else if(ftx != points[i+1][0] || fty != points[i+1][1] || ftz != points[i+1][2]){
				//wall collision
				SetTimerEx("OnPlayerDroppingGrenade",fly_time,false,"ddfff",playerid,weaponid,ftx,fty,ftz);
				if(weaponid == 16) SetTimerEx("OnPlayerGrenadeExplode",fly_time+Tryg3D::ExplosionTime,false,"ddfff",playerid,weaponid,ftx,fty,ftz);
				return 1;
			}
		}
		//no collision
		Tryg3D::InteriorFindZ(tx,ty,z,2.0,tz);
		SetTimerEx("OnPlayerDroppingGrenade",fly_time,false,"ddfff",playerid,weaponid,tx,ty,tz);
		if(weaponid == 16) SetTimerEx("OnPlayerGrenadeExplode",fly_time+Tryg3D::ExplosionTime,false,"ddfff",playerid,weaponid,tx,ty,tz);
		return 1;
	}

#endif

//Hook: OnPlayerKeyStateChange
public OnPlayerKeyStateChange(playerid,newkeys,oldkeys){
	#if defined TRYG3D_MOD_GRENADEDETECTION
		new weaponid = GetPlayerWeapon(playerid);
		if(weaponid >= 16 && weaponid <= 18 && !Tryg3D::IsPlayerRunning(playerid) && GetPlayerSpecialAction(playerid) == 0){
			if(Tryg3D::KeyPressed(KEY_FIRE) && Tryg3D::PlayerGrenadeActive[playerid] == 0){
				GetPlayerPos(playerid,Tryg3D::LastPos[playerid][T3D:X],Tryg3D::LastPos[playerid][T3D:Y],Tryg3D::LastPos[playerid][T3D:Z]);
				GetPlayerFacingAngle(playerid,Tryg3D::LastPos[playerid][T3D:A]);
				Tryg3D::PlayerGrenadeActive[playerid] = GetTickCount();
				Tryg3D::GrenadeTimer[playerid] = SetTimerEx("OnGrenadeHoldExpired",600,false,"ddffff",playerid,weaponid,Tryg3D::LastPos[playerid][T3D:X],Tryg3D::LastPos[playerid][T3D:Y],Tryg3D::LastPos[playerid][T3D:Z],Tryg3D::LastPos[playerid][T3D:A]);
			}
			if(Tryg3D::KeyReleased(KEY_FIRE) && Tryg3D::PlayerGrenadeActive[playerid] != 0){
				KillTimer(Tryg3D::GrenadeTimer[playerid]);
				OnGrenadeHoldExpired(playerid,weaponid,Tryg3D::LastPos[playerid][T3D:X],Tryg3D::LastPos[playerid][T3D:Y],Tryg3D::LastPos[playerid][T3D:Z],Tryg3D::LastPos[playerid][T3D:A]);
			}
		}
	#endif
	
	#if defined T3_OnPlayerKeyStateChange
		T3_OnPlayerKeyStateChange(playerid,newkeys,oldkeys);
	#endif
	return 1;
}

#if defined _ALS_OnPlayerKeyStateChange
	#undef OnPlayerKeyStateChange
#else
	#define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange T3_OnPlayerKeyStateChange
#if defined T3_OnPlayerKeyStateChange
	forward T3_OnPlayerKeyStateChange(playerid,newkeys,oldkeys);
#endif
 
/********************************
 * VehicleCollision Functions   *
 ********************************/

#if defined TRYG3D_MOD_VEHICLECOLLISION

	#define T3_IsVehicleCollisionEnabled()   Tryg3D::VehicleCollisionSystem
	#define T3_IsToggledVehicleCollision(%0) Tryg3D::VehicleCollisionUsed[(%0)]
	#define T3_ToggleVehicleCollision(%0,%1) Tryg3D::VehicleCollisionUsed[(%0)] = (%1)
	
	T3D:function Tryg3D::SyncVehicleCollision(vehicleid){
		if(!Tryg3D::VehicleCollisionSystem) return 0;
		new Float:T3D:sx,Float:T3D:sy,Float:T3D:sz;
		GetVehicleModelInfo(GetVehicleModel(vehicleid),VEHICLE_MODEL_INFO_SIZE,T3D:sx,T3D:sy,T3D:sz);
		T3D:sx /= 2.0;
		T3D:sy /= 2.0;
		T3D:sz /= 2.0;
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MIN_X,-T3D:sx);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MIN_Y,-T3D:sy);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MIN_Z,-T3D:sz);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MAX_X,T3D:sx);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MAX_Y,T3D:sy);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_MAX_Z,T3D:sz);
		AttachDynamicAreaToVehicle(Tryg3D::VehicleCollisionZone[vehicleid],vehicleid);
		return 1;
	}

	T3D:function Tryg3D::InitVehicleCollision(){
		if(Tryg3D::VehicleCollisionSystem) return 0;
		Tryg3D::VehicleCollisionSystem = true;
		for(new vehicleid = 1; vehicleid < MAX_VEHICLES; vehicleid++){
			Tryg3D::VehicleCollisionZone[vehicleid] = CreateDynamicCube(-1.0,-1.0,-6000.0,1.0,1.0,-5000.0);
			Tryg3D::VehicleCollisionUsed[vehicleid] = true;
			new Tryg3D::ExtraArray[2];
			Tryg3D::ExtraArray[0] = TRYG3D_EXTRA_DATA_FLAG_VEHICLE;
			Tryg3D::ExtraArray[1] = vehicleid;
			Streamer::SetArrayData(STREAMER_TYPE_AREA,Tryg3D::VehicleCollisionZone[vehicleid],E_STREAMER_EXTRA_ID,Tryg3D::ExtraArray);
			if(IsValidVehicle(vehicleid)){
				Tryg3D::SyncVehicleCollision(vehicleid);
			}
		}
		print("[ADM] Info: VehicleCollision successfully init.");
		return 1;
	}

	T3D:function Tryg3D::ExitVehicleCollision(){
		if(!Tryg3D::VehicleCollisionSystem) return 0;
		for(new vehicleid = 1; vehicleid < MAX_VEHICLES; vehicleid++){
			if(IsValidDynamicArea(Tryg3D::VehicleCollisionZone[vehicleid])) DestroyDynamicArea(Tryg3D::VehicleCollisionZone[vehicleid]);
			Tryg3D::VehicleCollisionZone[vehicleid] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
			Tryg3D::VehicleCollisionUsed[vehicleid] = false;
		}
		Tryg3D::VehicleCollisionSystem = false;
		print("[ADM] Info: VehicleCollision successfully exit.");
		return 1;
	}

	stock Tryg3D::MovePointColWithVehicle(Float:StartX,Float:StartY,Float:StartZ,Float:EndX,Float:EndY,Float:EndZ,&Float:x,&Float:y,&Float:z){
		new Item3D:item_type,element_id;
		Tryg3D::CollisionCheck(StartX,StartY,StartZ,EndX,EndY,EndZ,x,y,z,item_type,element_id,0.0,.collision_flags = TRYG3D_COLLISION_FLAG_OBJECT + TRYG3D_COLLISION_FLAG_VEHICLE);
		if(item_type == item_vehicle) return element_id;
		return INVALID_VEHICLE_ID;
	}

	stock Tryg3D::MovePointColWithVehicleCut(Float:StartX,Float:StartY,Float:StartZ,Float:EndX,Float:EndY,Float:EndZ,&Float:x,&Float:y,&Float:z,Float:cut_size=0.0){
		new Item3D:item_type,element_id;
		Tryg3D::CollisionCheck(StartX,StartY,StartZ,EndX,EndY,EndZ,x,y,z,item_type,element_id,cut_size,.collision_flags = TRYG3D_COLLISION_FLAG_OBJECT + TRYG3D_COLLISION_FLAG_VEHICLE);
		if(item_type == item_vehicle) return element_id;
		return INVALID_VEHICLE_ID;
	}

	//Hook: OnVehicleSpawn
	public OnVehicleSpawn(vehicleid){
		if(!IsValidVehicle(vehicleid)) return 0;
		if(Tryg3D::VehicleCollisionSystem){
			Tryg3D::SyncVehicleCollision(vehicleid);
		}
		#if defined T3_OnVehicleSpawn
			T3_OnVehicleSpawn(vehicleid);
		#endif
		return 1;
	}

	#if defined T3_OnVehicleSpawn
		forward T3_OnVehicleSpawn(vehicleid);
	#endif
	#if defined _ALS_OnVehicleSpawn
		#undef OnVehicleSpawn
	#else
		#define _ALS_OnVehicleSpawn
	#endif
	#define OnVehicleSpawn T3_OnVehicleSpawn

#endif

/********************************
 * ActorCollision Functions     *
 ********************************/

#if defined TRYG3D_MOD_ACTORCOLLISION

	#define T3_IsActorCollisionEnabled()   Tryg3D::ActorCollisionSystem
	#define T3_IsToggledActorCollision(%0) Tryg3D::ActorCollisionUsed[(%0)]
	#define T3_ToggleActorCollision(%0,%1) Tryg3D::ActorCollisionUsed[(%0)] = (%1)

	T3D:function Tryg3D::SyncActorCollision(actorid){
		if(!Tryg3D::ActorCollisionSystem) return 0;
		new Float:T3D:pos[3];
		GetActorPos(actorid,T3D:pos[0],T3D:pos[1],T3D:pos[2]);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MIN_X,T3D:pos[0]-0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MIN_Y,T3D:pos[1]-0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MIN_Z,T3D:pos[2]-1.00);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MAX_X,T3D:pos[0]+0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MAX_Y,T3D:pos[0]+0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_MAX_Z,T3D:pos[2]+1.00);
		return 1;
	}

	T3D:function Tryg3D::InitActorCollision(){
		if(Tryg3D::ActorCollisionSystem) return 0;
		Tryg3D::ActorCollisionSystem = true;
		for(new actorid = 0; actorid < MAX_ACTORS; actorid++){
			Tryg3D::ActorCollisionZone[actorid] = CreateDynamicCube(-1.0,-1.0,-6000.0,1.0,1.0,-5000.0);
			Tryg3D::ActorCollisionUsed[actorid] = true;
			new Tryg3D::ExtraArray[2];
			Tryg3D::ExtraArray[0] = TRYG3D_EXTRA_DATA_FLAG_ACTOR;
			Tryg3D::ExtraArray[1] = actorid;
			Streamer::SetArrayData(STREAMER_TYPE_AREA,Tryg3D::ActorCollisionZone[actorid],E_STREAMER_EXTRA_ID,Tryg3D::ExtraArray);
			if(IsValidActor(actorid)){
				Tryg3D::SyncActorCollision(actorid);
			}
		}
		print("[ADM] Info: ActorCollision successfully init.");
		return 1;
	}

	T3D:function Tryg3D::ExitActorCollision(){
		if(!Tryg3D::ActorCollisionSystem) return 0;
		for(new actorid = 1; actorid < MAX_ACTORS; actorid++){
			if(IsValidDynamicArea(Tryg3D::ActorCollisionZone[actorid])) DestroyDynamicArea(Tryg3D::ActorCollisionZone[actorid]);
			Tryg3D::ActorCollisionZone[actorid] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
			Tryg3D::ActorCollisionUsed[actorid] = false;
		}
		Tryg3D::ActorCollisionSystem = false;
		print("[ADM] Info: ActorCollision successfully exit.");
		return 1;
	}

#endif

/********************************
 * PlayerCollision Functions    *
 ********************************/

#if defined TRYG3D_MOD_PLAYERCOLLISION

	#define T3_IsPlayerCollisionEnabled()   Tryg3D::PlayerCollisionSystem
	#define T3_IsToggledPlayerCollision(%0) Tryg3D::PlayerCollisionUsed[(%0)]
	#define T3_TogglePlayerCollision(%0,%1) Tryg3D::PlayerCollisionUsed[(%0)] = (%1)

	T3D:function Tryg3D::SyncPlayerCollision(playerid){
		if(!Tryg3D::PlayerCollisionSystem) return 0;
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MIN_X,-0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MIN_Y,-0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MIN_Z,-1.00);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MAX_X,0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MAX_Y,0.30);
		Streamer::SetFloatData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_MAX_Z,1.00);
		AttachDynamicAreaToPlayer(Tryg3D::PlayerCollisionZone[playerid],playerid);
		return 1;
	}

	T3D:function Tryg3D::InitPlayerCollision(){
		if(Tryg3D::PlayerCollisionSystem) return 0;
		Tryg3D::PlayerCollisionSystem = true;
		for(new playerid = 0; playerid < MAX_PLAYERS; playerid++){
			Tryg3D::PlayerCollisionZone[playerid] = CreateDynamicCube(-1.0,-1.0,-6000.0,1.0,1.0,-5000.0);
			Tryg3D::PlayerCollisionUsed[playerid] = true;
			new Tryg3D::ExtraArray[2];
			Tryg3D::ExtraArray[0] = TRYG3D_EXTRA_DATA_FLAG_PLAYER;
			Tryg3D::ExtraArray[1] = playerid;
			Streamer::SetArrayData(STREAMER_TYPE_AREA,Tryg3D::PlayerCollisionZone[playerid],E_STREAMER_EXTRA_ID,Tryg3D::ExtraArray);
			if(IsPlayerConnected(playerid)){
				Tryg3D::SyncPlayerCollision(playerid);
			}
		}
		print("[ADM] Info: PlayerCollision successfully init.");
		return 1;
	}

	T3D:function Tryg3D::ExitPlayerCollision(){
		if(!Tryg3D::PlayerCollisionSystem) return 0;
		for(new playerid = 1; playerid < MAX_PLAYERS; playerid++){
			if(IsValidDynamicArea(Tryg3D::PlayerCollisionZone[playerid])) DestroyDynamicArea(Tryg3D::PlayerCollisionZone[playerid]);
			Tryg3D::PlayerCollisionZone[playerid] = STREAMER_TAG_AREA:INVALID_STREAMER_ID;
			Tryg3D::PlayerCollisionUsed[playerid] = false;
		}
		Tryg3D::PlayerCollisionSystem = false;
		print("[ADM] Info: PlayerCollision successfully exit.");
		return 1;
	}

	//Hook: OnPlayerSpawn
	public OnPlayerSpawn(playerid){
		if(!IsPlayerConnected(playerid)) return 0;
		if(Tryg3D::PlayerCollisionSystem){
			Tryg3D::SyncPlayerCollision(playerid);
		}
		#if defined T3_OnPlayerSpawn
			T3_OnPlayerSpawn(playerid);
		#endif
		return 1;
	}

	#if defined T3_OnPlayerSpawn
		forward T3_OnPlayerSpawn(playerid);
	#endif
	#if defined _ALS_OnPlayerSpawn
		#undef OnPlayerSpawn
	#else
		#define _ALS_OnPlayerSpawn
	#endif
	#define OnPlayerSpawn T3_OnPlayerSpawn
	
	#if defined TRYG3D_MOD_FCNPC
		//Hook: FCNPC_OnSpawn
		public FCNPC_OnSpawn(npcid){
			if(!IsPlayerConnected(npcid)) return 0;
			if(Tryg3D::PlayerCollisionSystem){
				Tryg3D::SyncPlayerCollision(npcid);
			}
			#if defined T3_FCNPC_OnSpawn
				T3_FCNPC_OnSpawn(npcid);
			#endif
			return 1;
		}

		#if defined T3_FCNPC_OnSpawn
			forward T3_FCNPC_OnSpawn(npcid);
		#endif
		#if defined _ALS_FCNPC_OnSpawn
			#undef FCNPC_OnSpawn
		#else
			#define _ALS_FCNPC_OnSpawn
		#endif
		#define FCNPC_OnSpawn T3_FCNPC_OnSpawn

	#endif
	
#endif

/********************************
 * Init Functions               *
 ********************************/

stock Tryg3D::Init(){
	Tryg3D::UpTime = GetTickCount();
	
	new T3D:modules[TRYG3D_MAX_MODULES_STRING];

	#if defined TRYG3D_MOD_PLAYER
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_PLAYER);
	#endif

	#if defined TRYG3D_MOD_VEHICLE
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_VEHICLE);
	#endif

	#if defined TRYG3D_MOD_ACTOR
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_ACTOR);
	#endif

	#if defined TRYG3D_MOD_GRENADEDETECTION
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_GRENADEDETECTION);
	#endif

	#if defined TRYG3D_MOD_VEHICLECOL
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_VEHICLECOL);
	#endif

	#if defined TRYG3D_MOD_PLAYERCOL
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_PLAYERCOL);
	#endif

	#if defined TRYG3D_MOD_ACTORCOL
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_ACTORCOL);
	#endif

	#if defined TRYG3D_MOD_UNIVERSAL
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_UNIVERSAL);
	#endif

	#if defined TRYG3D_MOD_DRAW3D
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_DRAW3D);
	#endif

	#if defined TRYG3D_MOD_CAST3D
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_CAST3D);
	#endif

	#if defined TRYG3D_MOD_CATCHITEMS
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_CATCHITEMS);
	#endif

	#if defined TRYG3D_MOD_COLANDREAS
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_COLANDREAS);
	#endif

	#if defined TRYG3D_MOD_STREAMER
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_STREAMER);
	#endif

	#if defined TRYG3D_MOD_FCNPC
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_FCNPC);
	#endif

	#if defined TRYG3D_MOD_YSF
		format(T3D:modules,TRYG3D_MAX_MODULES_STRING,"%s %s,",T3D:modules,TRYG3D_MOD_YSF);
	#endif
	
	new T3D:ver_name[16];
	format(T3D:ver_name,sizeof(T3D:ver_name),"%d.%d.%d",Tryg3D::GetVersion(TRYG3D_VERSION));
	printf("[ADM] Info: Load %s Gen. 2 v%s for %s %s by %s",TRYG3D_LIBRARY_NAME,T3D:ver_name,TRYG3D_PLATFORM_NAME,TRYG3D_PLATFORM_VERSION,TRYG3D_AUTHOR_NAME);
	new T3D:len = strlen(T3D:modules);
	if(T3D:len > 0){
		T3D:modules[T3D:len-1] = EOS;
		printf("[ADM] Info: Load %s Modules:%s",TRYG3D_LIBRARY_NAME,T3D:modules);
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
	
	#if defined TRYG3D_MOD_FCNPC
		if(!fexist("FCNPC/nodes")){
			print("[ADM] Error: Plugin data not found /scriptfiles/FCNPC/nodes/*.dat");
			Tryg3D::UpdateErrorCount();
		}
	#endif
	
	//Init Map Precision
	#if !defined TRYG3D_DISABLE_INIT
		#if defined TRYG3D_MOD_COLANDREAS
			Tryg3D::SafeColAndreasInit();
		#endif
	#endif
	
	new T3D:errors = Tryg3D::GetErrorCount();
	if(T3D:errors > 0) printf("[ADM] Info: 3DTryg running with %d errors detected, see above",T3D:errors);
}

stock Tryg3D::Exit(){
	new T3D:ver_name[16];
	format(T3D:ver_name,sizeof(T3D:ver_name),"%d.%d.%d",Tryg3D::GetVersion(TRYG3D_VERSION));
	printf("[ADM] Info: Unload %s Gen. 2 v%s for %s %s by %s",TRYG3D_LIBRARY_NAME,T3D:ver_name,TRYG3D_PLATFORM_NAME,TRYG3D_PLATFORM_VERSION,TRYG3D_AUTHOR_NAME);
}

/********************************
 * Hooks                        *
 ********************************/

#if TRYG3D_PLATFORM_CODE == TRYG3D_PLATFORM_SAMP

	new bool: Tryg3D::StateInit = true, bool: Tryg3D::StateExit = true;
	
	//Hook: OnFilterScriptInit
	public OnFilterScriptInit(){
		if(Tryg3D::StateInit){
			Tryg3D::StateInit = false;
			Tryg3D::Init();
		}
		#if defined T3_OnFilterScriptInit
			T3_OnFilterScriptInit();	
		#endif
		return 1;
	}

	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit T3_OnFilterScriptInit
	#if defined T3_OnFilterScriptInit
		forward T3_OnFilterScriptInit();
	#endif

	//Hook: OnGameModeInit
	public OnGameModeInit(){
		if(Tryg3D::StateInit){
			Tryg3D::StateInit = false;
			Tryg3D::Init();
		}
		#if defined T3_OnGameModeInit
			T3_OnGameModeInit();
		#endif
		return 1;
	}

	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit T3_OnGameModeInit
	#if defined T3_OnGameModeInit
		forward T3_OnGameModeInit();
	#endif

	//Hook: OnFilterScriptExit
	public OnFilterScriptExit(){
		if(Tryg3D::StateExit){
			Tryg3D::StateExit = false;
			Tryg3D::Exit();
		}
		#if defined T3_OnFilterScriptExit
			T3_OnFilterScriptExit();
		#endif
		return 1;
	}

	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit T3_OnFilterScriptExit
	#if defined T3_OnFilterScriptExit
		forward T3_OnFilterScriptExit();
	#endif

	//Hook: OnGameModeExit
	public OnGameModeExit(){
		if(Tryg3D::StateExit){
			Tryg3D::StateExit = false;
			Tryg3D::Exit();
		}
		#if defined T3_OnGameModeExit
			T3_OnGameModeExit();
		#endif
		return 1;
	}

	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit T3_OnGameModeExit
	#if defined T3_OnGameModeExit
		forward T3_OnGameModeExit();
	#endif

#endif

/********************************
 * Additional operations        *
 ********************************/

#pragma unused T3_WeaponDamage
#pragma unused T3_StreamDistance
#pragma unused T3_ErrorLevel
#pragma unused T3_OrientationRotation
#pragma unused T3_UpTime


#if defined TRYG3D_MOD_GRENADEDETECTION
	#pragma unused T3_ExplosionTime
#endif
#if defined TRYG3D_MOD_PLAYER
	#pragma unused T3_DeatchTick
#endif
//EOF