#include "reading.h"
#include "protocol.h"

#include <app/service/electricity_reading_service.h>

struct message reading_read(struct readings_controller *controller, const struct message *request) {
    struct message response;
    if (request->head.type == MESSAGE_READING_READ) {
        struct electricity_energy reading;
        electricity_reading_service_get(controller->service, &reading);
        response.head.type = MESSAGE_READING_READ;
        response.head.size = sizeof(struct message);
        struct reading_message_response *result = (struct reading_message_response *) response.payload;
        result->reading = reading;
    }
    return response;
}
