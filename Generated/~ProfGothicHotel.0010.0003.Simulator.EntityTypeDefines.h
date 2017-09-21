
/* Simulator System Entity Type Defines Header */

/* Domain Enumerations */

typedef enum {
    ADM_SIM_INDEX_DOMAIN_GOTHIC_SECURITY
} adm_sim_index_domain_typ;

/* Entity Enumerations */

typedef enum {
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DEVICE,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM_DOOR,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_SECRET_PANEL,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_DEVICE,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCKING_SEQUENCE,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_UNLOCK_STEP,
    ADM_SIM_INDEX_ENTITY_GOTHIC_SECURITY_ROOM
} adm_sim_index_entity_typ;

/* Event Enumerations */

typedef enum {
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DEVICE_DEVICE_UPDATE,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_DOOR_CLOSED,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_DOOR_OPENED,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_LOCK_DOOR,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_ROOM_DOOR_UNLOCK_DOOR,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_SECRET_PANEL_UNLOCK_PANEL,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_SECRET_PANEL_PANEL_CLOSED,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCKING_DEVICE_DEVICE_UPDATE,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCKING_SEQUENCE_ACTIVATE,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCKING_SEQUENCE_RESET,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCKING_SEQUENCE_COMPLETE,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCK_STEP_RESET,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCK_STEP_ADVANCE,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCK_STEP_SELECT,
    ADM_SIM_INDEX_EVENT_GOTHIC_SECURITY_UNLOCK_STEP_PRIME
} adm_sim_index_event_typ;

/* Entity Display Widths */

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
    adm_base_integer_typ atb_name;
} adm_sim_width_room_device_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_room_door_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_secret_panel_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_unlocking_device_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_unlocking_sequence_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ status;
} adm_sim_width_unlock_step_typ;

typedef struct {
    adm_base_integer_typ identity;
    adm_base_integer_typ atb_number;
} adm_sim_width_room_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */