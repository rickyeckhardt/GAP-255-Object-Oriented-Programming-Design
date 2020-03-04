// Constants.h
#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

const int k_gridWidth = 10;
const int k_gridHeight = 10;

const int k_battleshipLength = 4;

// make sure everything matches up with our expectations
static_assert(k_battleshipLength * 2 < k_gridWidth && k_battleshipLength * 2 < k_gridHeight, "The grid is too small.");

#endif
