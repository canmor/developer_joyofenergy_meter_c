#ifndef DEVELOPER_JOYOFENERGY_METER_C_READING_H
#define DEVELOPER_JOYOFENERGY_METER_C_READING_H

#include <hal/endpoint.h>
#include <domain/electricity_energy.h>

struct readings_controller {
    struct electricity_reading_service *service;
};

static inline void readings_controller_init(struct readings_controller *controller,
                                            struct electricity_reading_service *service) {
    controller->service = service;
}

struct reading_message_response {
    struct electricity_energy reading;
};

struct message reading_read(struct readings_controller *controller, const struct message *request);

#endif  // DEVELOPER_JOYOFENERGY_METER_C_READING_H
