#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_LENGTH 100

struct message {
  long mtype;
  char mtext[MAX_MSG_LENGTH];
};

int main() {

  key_t key = ftok("/tmp/message_queue", 1);

  int msgid = msgget(key, IPC_CREAT | 0666);

  if (msgid < 0) {
    perror("Error creating message queue");
    exit(1);
  }

  struct message msg_to_send;
  msg_to_send.mtype = 1;
  strcpy(msg_to_send.mtext, "Hello from the sender process");

  if (msgsnd(msgid, &msg_to_send, strlen(msg_to_send.mtext) + 1, 0) < 0) {
    perror("Error sending message");
    exit(1);
  }
  printf("Sent message: %s\n", msg_to_send.mtext);

  struct message msg_received;

  if (msgrcv(msgid, &msg_received, MAX_MSG_LENGTH, 1, 0) < 0) {
    perror("Error receiving message");
    exit(1);
  }
  printf("Received message: %s\n", msg_received.mtext);

  if (msgctl(msgid, IPC_RMID, NULL) < 0) {
    perror("Error removing message queue");
    exit(1);
  }
  return 0;
}

