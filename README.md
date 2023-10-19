# sgdk-atan2

This repository contains an implementation of the atan2 function for SGDK.

The code is based on the `atan2LUTif` function from the [fast_atan2](https://github.com/ducha-aiki/fast_atan2/tree/master) repository.

## Example

```cpp
#include <genesis.h>
#include <resources.h>
#include "./atan2.h"

char buff1[20];
char buff2[20];
char buff3[20];
char buff4[20];

int main() {
	fix32 thetaRad, thetaDeg, thetaSgdk;

	//                                y2-y1              x2-x1
	thetaRad  = atan2LUTif(intToFix32(11-11), intToFix32(12-11));
	thetaDeg  = rad2deg(thetaRad); // Return 0..360
	thetaSgdk = rad2degSGDK(thetaRad); // Return 0..1024 (Useful sin-cos opertaions)
	sprintf(buff1, "%d %d", fix32ToRoundedInt(thetaDeg), fix32ToRoundedInt(thetaSgdk));

	//                               y2-y1              x2-x1
	thetaRad = atan2LUTif(intToFix32(10-11), intToFix32(11-11));
	thetaDeg = rad2deg(thetaRad); // Return 0..360
	thetaSgdk = rad2degSGDK(thetaRad); // Return 0..1024 (Useful sin-cos opertaions)
	sprintf(buff2, "%d %d", fix32ToRoundedInt(thetaDeg), fix32ToRoundedInt(thetaSgdk));

	//                               y2-y1              x2-x1
	thetaRad = atan2LUTif(intToFix32(11-11), intToFix32(10-11));
	thetaDeg = rad2deg(thetaRad); // Return 0..360
	thetaSgdk = rad2degSGDK(thetaRad); // Return 0..1024 (Useful sin-cos opertaions)
	sprintf(buff3, "%d %d", fix32ToRoundedInt(thetaDeg), fix32ToRoundedInt(thetaSgdk));

	//                               y2-y1              x2-x1
	thetaRad = atan2LUTif(intToFix32(12-11), intToFix32(11-11));
	thetaDeg = rad2deg(thetaRad); // Return 0..360
	thetaSgdk = rad2degSGDK(thetaRad); // Return 0..1024 (Useful sin-cos opertaions)
	sprintf(buff4, "%d %d", fix32ToRoundedInt(thetaDeg), fix32ToRoundedInt(thetaSgdk));

	while(1)
	{
		VDP_drawText(buff1, 10, 10);
		VDP_drawText(buff2, 10, 11);
		VDP_drawText(buff3, 10, 12);
		VDP_drawText(buff4, 10, 13);
	}
	return (0);
}
```
