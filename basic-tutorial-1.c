#include <gst/gst.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

  printf("hello!\n");
  gst_init(&argc, &argv);
  pipeline = gst_parse_launch("playbin uri=file://dog.mp4", NULL);

  printf("midway!\n");
  gst_element_set_state(pipeline, GST_STATE_PLAYING);
  bus = gst_element_get_bus(pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_ERROR | GST_MESSAGE_EOS);


  printf("cleanup!\n");
  if (msg != NULL) gst_message_unref(msg);
  gst_object_unref(bus);
  gst_element_set_state(pipeline, GST_STATE_NULL);
  gst_object_unref(pipeline);
  printf("done!\n");
  return 0;
}