#ifndef DEVELOPER_JOYOFENERGY_METER_C_PROTOCOL_H
#define DEVELOPER_JOYOFENERGY_METER_C_PROTOCOL_H

#include <app/service/electricity_reading_service.h>
#include <hal/endpoint.h>
#include <stdbool.h>

enum message_type {
  MESSAGE_INVALID = 0,
  MESSAGE_READING_READ,
};

struct message_head {
  uint32_t size;
  uint32_t type;
  char payload[0];
};

struct message {
  struct message_head head;
  char payload[1024];
};

struct protocol {
  struct electricity_reading_service* reading_service;
};

static inline void protocol_init(struct protocol *router, struct electricity_reading_service *reading_service) {
  router->reading_service = reading_service;
}

bool protocol_process(struct protocol* protocol, struct endpoint* endpoint);
#endif  // DEVELOPER_JOYOFENERGY_METER_C_PROTOCOL_H
