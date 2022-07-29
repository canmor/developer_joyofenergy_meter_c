#include "meter.h"

#include <stdlib.h>

#include "adapter/protocol/protocol.h"
#include "adapter/schedule/schedule.h"
#include "configuration.h"

int meter_init(struct meter *meter, struct bsp *bsp) {
    memset(meter, 0, sizeof(struct meter));
    meter->bsp = bsp;
    electricity_reading_service_init(&meter->reading_service, bsp, &meter->reading);
    schedule_init(&meter->schedule, &meter->reading_service, bsp);
    protocol_init(&meter->protocol, &meter->reading_service);
    return 0;
}

bool meter_process(struct meter *meter) {
    while (!protocol_process(&meter->protocol, bsp_endpoint(meter->bsp)));
    return schedule_process(&meter->schedule);
}
