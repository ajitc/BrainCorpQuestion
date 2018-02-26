/*
CODE SAMPLE:
Please provide a code example written in C that dispatches messages based upon their type. There are two message types "display" and "motor". These two message types are mixed into the same packet format and the function that needs to be written needs to distinguish between these two messages and call the appropriate function. Display messages must be passed to the function called display_message() and motor messages must be passed to a function called update_motor(). Please write function declarations for these functions but empty function bodies are fine.


The packet format uses little-endian data (you can assume both sending and receiver are little-endian) and has the following fields of the specified fields:
packet_id (byte, position 0)
message_type (byte, position 1)
message_length (2 bytes, positions 2 to 3)
message_data (positions 4 to 4+message_length)


message_type values:
0x34: display message
0x80: motor message


message_data for display messages is a ASCII string of length message_length


message_data for motor messages is composed of the following data structure:
forward_back (float32, positions 0 to 3)
left_right (float32, positions 4 to 7)


Example packets for each message are defined below:
uint8_t display_packet[] = {0x1, 0x34, 0x05, 0x0, 0x48, 0x65, 0x6c, 0x6c, 0x6f};

uint8_t motor_packet[] = {0x2, 0x80, 0x08, 0x0, 0x0, 0x0, 0x80, 0x3f, 0x0, 0x0, 0x0, 0xbf};
*/

#ifndef ROBOT_MESSAGE
#define ROBOT_MESSAGE
#include<stdio>

typedef enum{ DISPLAY_MSG=0x34; MOTOR_MSG=0x80} MSG_TYPE_T;


typedef robo_mesg robo_mesg_type

typedef struct union
struct robo_mesg {
  u_int8   message_type;
  u_int16  message_len;
  msg_data *msg;
};

struct display_msg_data {
  u_int8 *dis_msg;
};

struct motor_msg_data {
  float forward_back;
  float left_right;
}

exec_codes dispatchMessage(u_int8 *buffer, uint_16 buffer_size);

void display_message();

void update_motor();

#endif
