/*
 * des.h
 *
 *  Created on: Feb 14, 2021
 *      Author: hurdleg
 */

#ifndef DOOR_ENTRY_SYSTEM_H_
#define DOOR_ENTRY_SYSTEM_H_


#define DIRECTION_INBOUND "inbound"
#define DIRECTION_OUTBOUND "outbound"

// Define MAX_INPUT_LENGTH if not already defined
#define MAX_INPUT_LENGTH 20


#define NUM_STATES 13  // number of states in your finite state machine (FSM)
typedef enum {
	START_STATE,
	LS_STATE,
	RS_STATE,
	LEFT_UNLOCK_STATE,
	LEFT_OPEN_STATE,
	WEIGHT_STATE,
	LEFT_CLOSE_STATE,
	GUARD_LEFT_LOCK_STATE,
	RIGHT_UNLOCK_STATE,
	RIGHT_OPEN_STATE,
	RIGHT_CLOSE_STATE,
	GUARD_RIGHT_LOCK_STATE
} State;

#define NUM_INPUTS 12  // number of input commands that drive the FSM
typedef enum {
	LS,
	RS,
	WS,
	LO,
	RO,
	LC,
	RC,
	GLU,
	GLL,
	GRU,
	GRL
} Input;

const char *inMessage[NUM_INPUTS] = {
	"ls",
	"rs",
	"ws",
	"lo",
	"ro",
	"lc",
	"rc",
	"glu",
	"gll",
	"gru",
	"grl"
};

#define NUM_OUTPUTS 11  // number of output messages from the FSM
typedef enum {
	PERSON_LEFT_SCAN,
	PERSON_RIGHT_SCAN,
	PERSON_WEIGHT,
	LEFT_DOOR_OPEN,
	RIGHT_DOOR_OPEN,
	LEFT_DOOR_CLOSE,
	RIGHT_DOOR_CLOSE,
	GUARD_LEFT_UNLOCK,
	GUARD_LEFT_LOCK,
	GUARD_RIGHT_UNLOCK,
	GUARD_RIGHT_LOCK
} Output;

const char *outMessage[NUM_OUTPUTS] = {
	"Person scanned left door",
	"Person scanned right door",
	"Person weighed",
	"Left door opened",
	"Right door opened",
	"Left door closed",
	"Right door closed",
	"Guard left unlocked",
	"Guard left locked",
	"Guard right unlocked",
	"Guard right locked"
};



typedef struct {
    char event[MAX_INPUT_LENGTH];
    int person_id;
    int weight;
} Message;


#endif /* DOOR_ENTRY_SYSTEM_H_ */

