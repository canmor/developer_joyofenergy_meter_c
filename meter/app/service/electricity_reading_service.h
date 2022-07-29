#ifndef DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_SERVICE_H
#define DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_SERVICE_H

#include <domain/electricity_energy.h>
#include <hal/bsp.h>
#include <string.h>

struct electricity_reading_service {
    struct bsp *bsp;
    struct electricity_energy reading;
};

static inline void electricity_reading_service_init(struct electricity_reading_service *service, struct bsp *bsp,
                                                    const struct electricity_energy* reading) {
    service->bsp = bsp;
    service->reading = *reading;
}

static inline void
electricity_reading_service_get(struct electricity_reading_service *service, struct electricity_energy *reading) {
    memcpy(reading, &service->reading, sizeof(struct electricity_energy));
}

#endif  // DEVELOPER_JOYOFENERGY_METER_C_ELECTRICITY_READING_SERVICE_H
