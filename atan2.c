#include <genesis.h>
#include "./atan2.h"

fix32 rad2deg(fix32 rad) {
    rad = fix32Sub(rad, FIX32(M_PI / 2));
    fix32 deg = fix32Mul(rad, FIX32(180 / M_PI));
    deg = fix32Sub(90, deg);
    return deg < FIX32(0) ? (fix32Add(deg, FIX32(360))) : deg;
}

fix32 rad2degSGDK(fix32 rad) {
    rad = fix32Sub(rad, FIX32(M_PI / 2));
    fix32 deg = fix32Mul(rad, FIX32(512 / M_PI));
    deg = fix32Sub(256, deg);
    return deg < FIX32(0) ? (fix32Add(deg, FIX32(1024))) : deg;
}

fix32 atan2LUTif(fix32 y, fix32 x) 
{
	fix32 absx, absy, val;

	if (x == FIX32(0) && y == FIX32(0)) {
		return FIX32(0.0);
	}

	absy = abs(y);
	absx = abs(x);
	
	if (fix32Sub(absy, absx) == absy) {
		return y < FIX32(0) ? FIX32(-M_PI_2) : FIX32(M_PI_2);
	}

    if (y > FIX32(0)) {
        if (absx > absy) {
            // val = ATAN_LUT[(int)(255 * absy / absx)]; // 1st octant
            val = ATAN_LUT[fix32ToInt(fix32Mul(FIX32(255), fix32Div(absy, absx)))];
        } else {
            // val = M_PI_2 - ATAN_LUT[(int)(255 * absx / absy)]; // 2nd octant
            val = fix32Sub(FIX32(M_PI_2), ATAN_LUT[fix32ToInt(fix32Mul(FIX32(255), fix32Div(absx, absy)))]);
        }
        // val = x < 0 ? (M_PI - val) : val; // 3 - 4th octants from 2 - 1
        val = x < FIX32(0) ? (fix32Sub(FIX32(M_PI), val)) : val;
    } else {
        if (absx > absy) {
            // val = -ATAN_LUT[(int)(255 * absy / absx)]; // 8th octant
            val = fix32Mul(FIX32(-1), ATAN_LUT[fix32ToInt(fix32Mul(FIX32(255), fix32Div(absy, absx)))]);
        } else {
            // val = -M_PI_2 + ATAN_LUT[(int)(255 * absx / absy)]; // 7th octant
            val = fix32Add(FIX32(-M_PI_2), ATAN_LUT[fix32ToInt(fix32Mul(FIX32(255), fix32Div(absx, absy)))]);
        }
        // val = x < 0 ? -M_PI - val : val; // 5 - 6th octants from 8 - 7
        val = x < FIX32(0) ? fix32Sub(FIX32(-M_PI), val) : val;
    }

	return val;
}