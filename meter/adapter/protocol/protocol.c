#include "protocol.h"

#include "reading.h"

struct message default_handle(struct protocol* controller, const struct message* request) {
  struct message message = {0};
  return message;
}

typedef struct message (*handle_func)(void* controller, const struct message* request);

static struct message protocol_handle(struct protocol* router, const struct message* request) {
  struct readings_controller reading;
  readings_controller_init(&reading, router->reading_service);

  void* handler = router;
  handle_func func = (handle_func)default_handle;
  switch (request->head.type) {
    case MESSAGE_READING_READ:
      handler = &reading;
      func = (handle_func)reading_read;
      break;
    default:
      break;
  }
  return func(handler, request);
}

bool protocol_process(struct protocol* protocol, struct endpoint* endpoint) {
  char buffer[1024];
  int rec = endpoint_receive(endpoint, buffer, sizeof(buffer));
  if (rec == 0) {
    return true;
  }
  struct message* request = (struct message*)buffer;
  struct message response = protocol_handle(protocol, request);
  endpoint_send(endpoint, &response, sizeof(response));
  return false;
}
