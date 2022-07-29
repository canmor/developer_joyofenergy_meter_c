#ifndef DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_H
#define DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_H
#include <time.h>
#include <stdint.h>

struct electricity_energy {
  uint32_t energy;
};

static inline void electricity_reading_init(struct electricity_energy *reading, int energy) {
  reading->energy = energy;
}

#endif  // DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_H
