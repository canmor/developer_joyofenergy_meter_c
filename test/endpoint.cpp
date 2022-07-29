#include <adapter/protocol/protocol.h>
#include <adapter/protocol/reading.h>
#include <gmock/gmock.h>
#include <mocks/bsp.h>

#include "meter.h"

struct message make_request(message_type requestType) {
  struct message req = {0};
  req.head.size = sizeof(req);
  req.head.type = requestType;
  return req;
}

TEST(EndpointTest, ShouldReadReading) {
  struct bsp_mock mock;
  bsp_mock_init(&mock);
  struct meter meter;
  meter_init(&meter, (struct bsp *)&mock);
  struct message request = make_request(MESSAGE_READING_READ);
  endpoint_mock_send(&mock.endpoint, &request, sizeof(request));

  meter_process(&meter);

  const struct buffer received = endpoint_mock_receive(&mock.endpoint);
  ASSERT_GT(received.size, 0);
  struct message *response = (struct message *)received.data;
  ASSERT_EQ(response->head.type, MESSAGE_READING_READ);
  ASSERT_GT(response->head.size, sizeof(response->head));
  struct reading_message_response *data = (struct reading_message_response *)response->payload;
  ASSERT_EQ(data->reading.energy, 0);
}