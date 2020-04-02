/*
 * Copyright 2020 Christian Lienen <christian.lienen@upb.de>
 */

#ifndef ROS_PUB_H
#define ROS_PUB_H

#include "ros.h"

#include <rcl/context.h>
#include <rcl/allocator.h>
#include <rcl/node.h>
#include <rcl/publisher.h>
#include <stdint.h>

/*
 * Structure representing a mbox
 */
struct ros_publisher_t {
    rcl_node_t*     node;
    rcl_publisher_t rcl_pub;
    uint32_t        max_msg_size;
};

/*
 * Initializes the mbox. You must call this method before you
 * can use the mbox.
 *
 *  mb   - pointer to the mbox
 *  size - size of the mbox in 32bit-words
 */
extern int ros_publisher_init(struct ros_publisher_t *ros_pub, struct ros_node_t * ros_node , char* topic_name, uint32_t max_msg_size);

/*
 * Frees all used memory of the mbox.
 *
 *   mb - pointer to the mbox
 */
extern int ros_publisher_destroy(struct ros_publisher_t *ros_pub);

/*
 * Puts a single word into the mbox and blocks if it is full.
 *
 *   mb  - pointer to the mbox
 *   msg - message to put into the mbox
 */
extern int ros_publisher_publish(struct ros_publisher_t *ros_pub, uint8_t * msg, uint32_t msg_size);


#endif /* MBOX_H */
