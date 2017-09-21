
/* Entity Type Defines Header */

/* Entity Status Type Defines */

typedef enum {
    ADM_STATUS_ROOM_DEVICE_REDIRECT
} adm_sta_room_device_typ;

typedef enum {
    ADM_STATUS_ROOM_DOOR_OPEN,
    ADM_STATUS_ROOM_DOOR_CLOSED,
    ADM_STATUS_ROOM_DOOR_LOCKED,
    ADM_STATUS_ROOM_DOOR_UNLOCKED
} adm_sta_room_door_typ;

typedef enum {
    ADM_STATUS_SECRET_PANEL_CLOSED,
    ADM_STATUS_SECRET_PANEL_OPENED
} adm_sta_secret_panel_typ;

typedef enum {
    ADM_STATUS_UNLOCKING_DEVICE_UPDATING
} adm_sta_unlocking_device_typ;

typedef enum {
    ADM_STATUS_UNLOCKING_SEQUENCE_IDLE,
    ADM_STATUS_UNLOCKING_SEQUENCE_ACTIVE,
    ADM_STATUS_UNLOCKING_SEQUENCE_COMPLETE
} adm_sta_unlocking_sequence_typ;

typedef enum {
    ADM_STATUS_UNLOCK_STEP_WRONG_STEP,
    ADM_STATUS_UNLOCK_STEP_LOCKED,
    ADM_STATUS_UNLOCK_STEP_SELECTED,
    ADM_STATUS_UNLOCK_STEP_PRIMED,
    ADM_STATUS_UNLOCK_STEP_UNLOCKED
} adm_sta_unlock_step_typ;


/* Entity Event Type Defines */

typedef enum {
    ADM_EVENT_ROOM_DEVICE_DEVICE_UPDATE
} adm_evt_room_device_typ;

typedef enum {
    ADM_EVENT_ROOM_DOOR_DOOR_CLOSED,
    ADM_EVENT_ROOM_DOOR_DOOR_OPENED,
    ADM_EVENT_ROOM_DOOR_LOCK_DOOR,
    ADM_EVENT_ROOM_DOOR_UNLOCK_DOOR
} adm_evt_room_door_typ;

typedef enum {
    ADM_EVENT_SECRET_PANEL_UNLOCK_PANEL,
    ADM_EVENT_SECRET_PANEL_PANEL_CLOSED
} adm_evt_secret_panel_typ;

typedef enum {
    ADM_EVENT_UNLOCKING_DEVICE_DEVICE_UPDATE
} adm_evt_unlocking_device_typ;

typedef enum {
    ADM_EVENT_UNLOCKING_SEQUENCE_ACTIVATE,
    ADM_EVENT_UNLOCKING_SEQUENCE_RESET,
    ADM_EVENT_UNLOCKING_SEQUENCE_COMPLETE
} adm_evt_unlocking_sequence_typ;

typedef enum {
    ADM_EVENT_UNLOCK_STEP_RESET,
    ADM_EVENT_UNLOCK_STEP_ADVANCE,
    ADM_EVENT_UNLOCK_STEP_SELECT,
    ADM_EVENT_UNLOCK_STEP_PRIME
} adm_evt_unlock_step_typ;


/* Entity Type Defines */

/* Room Device */

typedef struct adm_ent_room_device {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_room_device_typ status;
    adm_str_text_typ * atb_name;
    struct adm_rel_room_device_contained_in_room * rel_contained_in_room_head;
    struct adm_rel_room_device_contained_in_room * rel_contained_in_room_tail;
    struct adm_rel_room_device_generalisation_room_door * rel_generalisation_room_door_head;
    struct adm_rel_room_device_generalisation_room_door * rel_generalisation_room_door_tail;
    struct adm_rel_room_device_generalisation_secret_panel * rel_generalisation_secret_panel_head;
    struct adm_rel_room_device_generalisation_secret_panel * rel_generalisation_secret_panel_tail;
    struct adm_rel_room_device_generalisation_unlocking_device * rel_generalisation_unlocking_device_head;
    struct adm_rel_room_device_generalisation_unlocking_device * rel_generalisation_unlocking_device_tail;
    struct adm_ent_room_device * back;
    struct adm_ent_room_device * next;
} adm_ent_room_device_typ;

/* Room Door */

typedef struct adm_ent_room_door {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_room_door_typ status;
    struct adm_rel_room_door_specialisation_room_device * rel_specialisation_room_device_head;
    struct adm_rel_room_door_specialisation_room_device * rel_specialisation_room_device_tail;
    struct adm_ent_room_door * back;
    struct adm_ent_room_door * next;
} adm_ent_room_door_typ;

/* Secret Panel */

typedef struct adm_ent_secret_panel {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_secret_panel_typ status;
    struct adm_rel_secret_panel_opened_by_unlocking_sequence * rel_opened_by_unlocking_sequence_head;
    struct adm_rel_secret_panel_opened_by_unlocking_sequence * rel_opened_by_unlocking_sequence_tail;
    struct adm_rel_secret_panel_specialisation_room_device * rel_specialisation_room_device_head;
    struct adm_rel_secret_panel_specialisation_room_device * rel_specialisation_room_device_tail;
    struct adm_ent_secret_panel * back;
    struct adm_ent_secret_panel * next;
} adm_ent_secret_panel_typ;

/* Unlocking Device */

typedef struct adm_ent_unlocking_device {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_unlocking_device_typ status;
    struct adm_rel_unlocking_device_sets_unlock_step * rel_sets_unlock_step_head;
    struct adm_rel_unlocking_device_sets_unlock_step * rel_sets_unlock_step_tail;
    struct adm_ent_unlocking_device * back;
    struct adm_ent_unlocking_device * next;
} adm_ent_unlocking_device_typ;

/* Unlocking Sequence */

typedef struct adm_ent_unlocking_sequence {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_unlocking_sequence_typ status;
    struct adm_rel_unlocking_sequence_opens_secret_panel * rel_opens_secret_panel_head;
    struct adm_rel_unlocking_sequence_opens_secret_panel * rel_opens_secret_panel_tail;
    struct adm_rel_unlocking_sequence_starts_at_unlock_step * rel_starts_at_unlock_step_head;
    struct adm_rel_unlocking_sequence_starts_at_unlock_step * rel_starts_at_unlock_step_tail;
    struct adm_ent_unlocking_sequence * back;
    struct adm_ent_unlocking_sequence * next;
} adm_ent_unlocking_sequence_typ;

/* Unlock Step */

typedef struct adm_ent_unlock_step {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_sta_unlock_step_typ status;
    struct adm_rel_unlock_step_followed_by_unlock_step * rel_followed_by_unlock_step_head;
    struct adm_rel_unlock_step_followed_by_unlock_step * rel_followed_by_unlock_step_tail;
    struct adm_rel_unlock_step_part_of_unlocking_sequence * rel_part_of_unlocking_sequence_head;
    struct adm_rel_unlock_step_part_of_unlocking_sequence * rel_part_of_unlocking_sequence_tail;
    struct adm_ent_unlock_step * back;
    struct adm_ent_unlock_step * next;
} adm_ent_unlock_step_typ;

/* Room */

typedef struct adm_ent_room {
    adm_base_integer_typ identity;
    adm_base_boolean_typ unique;
    adm_base_boolean_typ deleted;
    adm_base_boolean_typ marked;
    adm_base_integer_typ ignore;
    adm_int_number_typ atb_number;
    struct adm_rel_room_contains_room_device * rel_contains_room_device_head;
    struct adm_rel_room_contains_room_device * rel_contains_room_device_tail;
    struct adm_ent_room * back;
    struct adm_ent_room * next;
} adm_ent_room_typ;


/* Relationship Type Defines */

typedef struct adm_rel_room_device_contained_in_room {
    adm_ent_room_typ * ent_room;
    struct adm_rel_room_device_contained_in_room * back;
    struct adm_rel_room_device_contained_in_room * next;
} adm_rel_room_device_contained_in_room_typ;

typedef struct adm_rel_room_device_generalisation_room_door {
    adm_ent_room_door_typ * ent_room_door;
    struct adm_rel_room_device_generalisation_room_door * back;
    struct adm_rel_room_device_generalisation_room_door * next;
} adm_rel_room_device_generalisation_room_door_typ;

typedef struct adm_rel_room_device_generalisation_secret_panel {
    adm_ent_secret_panel_typ * ent_secret_panel;
    struct adm_rel_room_device_generalisation_secret_panel * back;
    struct adm_rel_room_device_generalisation_secret_panel * next;
} adm_rel_room_device_generalisation_secret_panel_typ;

typedef struct adm_rel_room_device_generalisation_unlocking_device {
    adm_ent_unlocking_device_typ * ent_unlocking_device;
    struct adm_rel_room_device_generalisation_unlocking_device * back;
    struct adm_rel_room_device_generalisation_unlocking_device * next;
} adm_rel_room_device_generalisation_unlocking_device_typ;

typedef struct adm_rel_room_door_specialisation_room_device {
    adm_ent_room_device_typ * ent_room_device;
    struct adm_rel_room_door_specialisation_room_device * back;
    struct adm_rel_room_door_specialisation_room_device * next;
} adm_rel_room_door_specialisation_room_device_typ;

typedef struct adm_rel_secret_panel_opened_by_unlocking_sequence {
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    struct adm_rel_secret_panel_opened_by_unlocking_sequence * back;
    struct adm_rel_secret_panel_opened_by_unlocking_sequence * next;
} adm_rel_secret_panel_opened_by_unlocking_sequence_typ;

typedef struct adm_rel_secret_panel_specialisation_room_device {
    adm_ent_room_device_typ * ent_room_device;
    struct adm_rel_secret_panel_specialisation_room_device * back;
    struct adm_rel_secret_panel_specialisation_room_device * next;
} adm_rel_secret_panel_specialisation_room_device_typ;

typedef struct adm_rel_unlocking_device_sets_unlock_step {
    adm_ent_unlock_step_typ * ent_unlock_step;
    struct adm_rel_unlocking_device_sets_unlock_step * back;
    struct adm_rel_unlocking_device_sets_unlock_step * next;
} adm_rel_unlocking_device_sets_unlock_step_typ;

typedef struct adm_rel_unlocking_sequence_opens_secret_panel {
    adm_ent_secret_panel_typ * ent_secret_panel;
    struct adm_rel_unlocking_sequence_opens_secret_panel * back;
    struct adm_rel_unlocking_sequence_opens_secret_panel * next;
} adm_rel_unlocking_sequence_opens_secret_panel_typ;

typedef struct adm_rel_unlocking_sequence_starts_at_unlock_step {
    adm_ent_unlock_step_typ * ent_unlock_step;
    struct adm_rel_unlocking_sequence_starts_at_unlock_step * back;
    struct adm_rel_unlocking_sequence_starts_at_unlock_step * next;
} adm_rel_unlocking_sequence_starts_at_unlock_step_typ;

typedef struct adm_rel_unlock_step_followed_by_unlock_step {
    adm_ent_unlock_step_typ * ent_unlock_step;
    struct adm_rel_unlock_step_followed_by_unlock_step * back;
    struct adm_rel_unlock_step_followed_by_unlock_step * next;
} adm_rel_unlock_step_followed_by_unlock_step_typ;

typedef struct adm_rel_unlock_step_part_of_unlocking_sequence {
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    struct adm_rel_unlock_step_part_of_unlocking_sequence * back;
    struct adm_rel_unlock_step_part_of_unlocking_sequence * next;
} adm_rel_unlock_step_part_of_unlocking_sequence_typ;

typedef struct adm_rel_room_contains_room_device {
    adm_ent_room_device_typ * ent_room_device;
    struct adm_rel_room_contains_room_device * back;
    struct adm_rel_room_contains_room_device * next;
} adm_rel_room_contains_room_device_typ;


/* Error Location Type Define */

typedef struct {
    adm_base_integer_typ file;
    adm_base_integer_typ line;
    adm_base_integer_typ rank;
} adm_error_location_typ;


/* Entity Event Pool Target Type Defines */

typedef struct adm_pool_target_room_device {
    adm_evt_room_device_typ evente;
    adm_ent_room_device_typ * ent_room_device;
    adm_error_location_typ error_location;
    struct adm_pool_target_room_device * next;
} adm_pool_target_room_device_typ;

typedef struct adm_pool_target_room_door {
    adm_evt_room_door_typ evente;
    adm_ent_room_door_typ * ent_room_door;
    adm_error_location_typ error_location;
    struct adm_pool_target_room_door * next;
} adm_pool_target_room_door_typ;

typedef struct adm_pool_target_secret_panel {
    adm_evt_secret_panel_typ evente;
    adm_ent_secret_panel_typ * ent_secret_panel;
    adm_error_location_typ error_location;
    struct adm_pool_target_secret_panel * next;
} adm_pool_target_secret_panel_typ;

typedef struct adm_pool_target_unlocking_device {
    adm_evt_unlocking_device_typ evente;
    adm_ent_unlocking_device_typ * ent_unlocking_device;
    adm_error_location_typ error_location;
    struct adm_pool_target_unlocking_device * next;
} adm_pool_target_unlocking_device_typ;

typedef struct adm_pool_target_unlocking_sequence {
    adm_evt_unlocking_sequence_typ evente;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;
    adm_error_location_typ error_location;
    struct adm_pool_target_unlocking_sequence * next;
} adm_pool_target_unlocking_sequence_typ;

typedef struct adm_pool_target_unlock_step {
    adm_evt_unlock_step_typ evente;
    adm_ent_unlock_step_typ * ent_unlock_step;
    adm_error_location_typ error_location;
    struct adm_pool_target_unlock_step * next;
} adm_pool_target_unlock_step_typ;


/* Entity System - Entity Type Defines */

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_room_device_typ * live_list_head;
    adm_ent_room_device_typ * live_list_tail;
    adm_ent_room_device_typ * dead_list_head;
    adm_ent_room_device_typ * dead_list_tail;
    adm_pool_target_room_device_typ * home_pool_head;
    adm_pool_target_room_device_typ * home_pool_tail;
    adm_pool_target_room_device_typ * away_pool_head;
    adm_pool_target_room_device_typ * away_pool_tail;
} adm_entity_system_room_device_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_room_door_typ * live_list_head;
    adm_ent_room_door_typ * live_list_tail;
    adm_ent_room_door_typ * dead_list_head;
    adm_ent_room_door_typ * dead_list_tail;
    adm_pool_target_room_door_typ * home_pool_head;
    adm_pool_target_room_door_typ * home_pool_tail;
    adm_pool_target_room_door_typ * away_pool_head;
    adm_pool_target_room_door_typ * away_pool_tail;
} adm_entity_system_room_door_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_secret_panel_typ * live_list_head;
    adm_ent_secret_panel_typ * live_list_tail;
    adm_ent_secret_panel_typ * dead_list_head;
    adm_ent_secret_panel_typ * dead_list_tail;
    adm_pool_target_secret_panel_typ * home_pool_head;
    adm_pool_target_secret_panel_typ * home_pool_tail;
    adm_pool_target_secret_panel_typ * away_pool_head;
    adm_pool_target_secret_panel_typ * away_pool_tail;
} adm_entity_system_secret_panel_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_unlocking_device_typ * live_list_head;
    adm_ent_unlocking_device_typ * live_list_tail;
    adm_ent_unlocking_device_typ * dead_list_head;
    adm_ent_unlocking_device_typ * dead_list_tail;
    adm_pool_target_unlocking_device_typ * home_pool_head;
    adm_pool_target_unlocking_device_typ * home_pool_tail;
    adm_pool_target_unlocking_device_typ * away_pool_head;
    adm_pool_target_unlocking_device_typ * away_pool_tail;
} adm_entity_system_unlocking_device_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_unlocking_sequence_typ * live_list_head;
    adm_ent_unlocking_sequence_typ * live_list_tail;
    adm_ent_unlocking_sequence_typ * dead_list_head;
    adm_ent_unlocking_sequence_typ * dead_list_tail;
    adm_pool_target_unlocking_sequence_typ * home_pool_head;
    adm_pool_target_unlocking_sequence_typ * home_pool_tail;
    adm_pool_target_unlocking_sequence_typ * away_pool_head;
    adm_pool_target_unlocking_sequence_typ * away_pool_tail;
} adm_entity_system_unlocking_sequence_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_unlock_step_typ * live_list_head;
    adm_ent_unlock_step_typ * live_list_tail;
    adm_ent_unlock_step_typ * dead_list_head;
    adm_ent_unlock_step_typ * dead_list_tail;
    adm_pool_target_unlock_step_typ * home_pool_head;
    adm_pool_target_unlock_step_typ * home_pool_tail;
    adm_pool_target_unlock_step_typ * away_pool_head;
    adm_pool_target_unlock_step_typ * away_pool_tail;
} adm_entity_system_unlock_step_typ;

typedef struct {
    adm_base_integer_typ tote;
    adm_ent_room_typ * live_list_head;
    adm_ent_room_typ * live_list_tail;
    adm_ent_room_typ * dead_list_head;
    adm_ent_room_typ * dead_list_tail;
} adm_entity_system_room_typ;


/* Entity System - System Type Define */

typedef struct {
    adm_entity_system_room_device_typ ent_room_device;
    adm_entity_system_room_door_typ ent_room_door;
    adm_entity_system_secret_panel_typ ent_secret_panel;
    adm_entity_system_unlocking_device_typ ent_unlocking_device;
    adm_entity_system_unlocking_sequence_typ ent_unlocking_sequence;
    adm_entity_system_unlock_step_typ ent_unlock_step;
    adm_entity_system_room_typ ent_room;
} adm_entity_system_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */