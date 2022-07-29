#ifndef DEVELOPER_JOYOFENERGY_METER_C_BSP_H
#define DEVELOPER_JOYOFENERGY_METER_C_BSP_H

#include "clock.h"
#include "endpoint.h"
#include "metrology.h"

struct bsp;

struct clock* bsp_clock(struct bsp*);
struct endpoint* bsp_endpoint(struct bsp*);
struct metrology* bsp_metrology(struct bsp*);

#endif  // DEVELOPER_JOYOFENERGY_METER_C_BSP_H
