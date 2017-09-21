
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Domain - Initialisation */

void adm_initialisation_gothic_security(
    void)
{
    /* Declare Objects */

    /* Room Device */
    adm_ent_room_device_typ * ent_room_device_0000000001;
    adm_ent_room_device_typ * ent_room_device_0000000002;
    adm_ent_room_device_typ * ent_room_device_0000000003;
    adm_ent_room_device_typ * ent_room_device_0000000004;

    /* Room Door */
    adm_ent_room_door_typ * ent_room_door_0000000005;

    /* Secret Panel */
    adm_ent_secret_panel_typ * ent_secret_panel_0000000006;

    /* Unlocking Device */
    adm_ent_unlocking_device_typ * ent_unlocking_device_0000000007;
    adm_ent_unlocking_device_typ * ent_unlocking_device_0000000008;

    /* Unlocking Sequence */
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000009;
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence_0000000010;

    /* Unlock Step */
    adm_ent_unlock_step_typ * ent_unlock_step_0000000011;
    adm_ent_unlock_step_typ * ent_unlock_step_0000000012;
    adm_ent_unlock_step_typ * ent_unlock_step_0000000013;
    adm_ent_unlock_step_typ * ent_unlock_step_0000000014;

    /* Room */
    adm_ent_room_typ * ent_room_0000000015;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_gothic_security");
    #endif

    /* Entity System */

    adm_entity_system.ent_room_device.tote = 0;
    adm_entity_system.ent_room_door.tote = 0;
    adm_entity_system.ent_secret_panel.tote = 0;
    adm_entity_system.ent_unlocking_device.tote = 0;
    adm_entity_system.ent_unlocking_sequence.tote = 0;
    adm_entity_system.ent_unlock_step.tote = 0;
    adm_entity_system.ent_room.tote = 0;

    adm_entity_system.ent_room_device.live_list_head = NULL;
    adm_entity_system.ent_room_door.live_list_head = NULL;
    adm_entity_system.ent_secret_panel.live_list_head = NULL;
    adm_entity_system.ent_unlocking_device.live_list_head = NULL;
    adm_entity_system.ent_unlocking_sequence.live_list_head = NULL;
    adm_entity_system.ent_unlock_step.live_list_head = NULL;
    adm_entity_system.ent_room.live_list_head = NULL;

    adm_entity_system.ent_room_device.live_list_tail = NULL;
    adm_entity_system.ent_room_door.live_list_tail = NULL;
    adm_entity_system.ent_secret_panel.live_list_tail = NULL;
    adm_entity_system.ent_unlocking_device.live_list_tail = NULL;
    adm_entity_system.ent_unlocking_sequence.live_list_tail = NULL;
    adm_entity_system.ent_unlock_step.live_list_tail = NULL;
    adm_entity_system.ent_room.live_list_tail = NULL;

    adm_entity_system.ent_room_device.dead_list_head = NULL;
    adm_entity_system.ent_room_door.dead_list_head = NULL;
    adm_entity_system.ent_secret_panel.dead_list_head = NULL;
    adm_entity_system.ent_unlocking_device.dead_list_head = NULL;
    adm_entity_system.ent_unlocking_sequence.dead_list_head = NULL;
    adm_entity_system.ent_unlock_step.dead_list_head = NULL;
    adm_entity_system.ent_room.dead_list_head = NULL;

    adm_entity_system.ent_room_device.dead_list_tail = NULL;
    adm_entity_system.ent_room_door.dead_list_tail = NULL;
    adm_entity_system.ent_secret_panel.dead_list_tail = NULL;
    adm_entity_system.ent_unlocking_device.dead_list_tail = NULL;
    adm_entity_system.ent_unlocking_sequence.dead_list_tail = NULL;
    adm_entity_system.ent_unlock_step.dead_list_tail = NULL;
    adm_entity_system.ent_room.dead_list_tail = NULL;

    adm_entity_system.ent_room_device.home_pool_head = NULL;
    adm_entity_system.ent_room_door.home_pool_head = NULL;
    adm_entity_system.ent_secret_panel.home_pool_head = NULL;
    adm_entity_system.ent_unlocking_device.home_pool_head = NULL;
    adm_entity_system.ent_unlocking_sequence.home_pool_head = NULL;
    adm_entity_system.ent_unlock_step.home_pool_head = NULL;

    adm_entity_system.ent_room_device.home_pool_tail = NULL;
    adm_entity_system.ent_room_door.home_pool_tail = NULL;
    adm_entity_system.ent_secret_panel.home_pool_tail = NULL;
    adm_entity_system.ent_unlocking_device.home_pool_tail = NULL;
    adm_entity_system.ent_unlocking_sequence.home_pool_tail = NULL;
    adm_entity_system.ent_unlock_step.home_pool_tail = NULL;

    adm_entity_system.ent_room_device.away_pool_head = NULL;
    adm_entity_system.ent_room_door.away_pool_head = NULL;
    adm_entity_system.ent_secret_panel.away_pool_head = NULL;
    adm_entity_system.ent_unlocking_device.away_pool_head = NULL;
    adm_entity_system.ent_unlocking_sequence.away_pool_head = NULL;
    adm_entity_system.ent_unlock_step.away_pool_head = NULL;

    adm_entity_system.ent_room_device.away_pool_tail = NULL;
    adm_entity_system.ent_room_door.away_pool_tail = NULL;
    adm_entity_system.ent_secret_panel.away_pool_tail = NULL;
    adm_entity_system.ent_unlocking_device.away_pool_tail = NULL;
    adm_entity_system.ent_unlocking_sequence.away_pool_tail = NULL;
    adm_entity_system.ent_unlock_step.away_pool_tail = NULL;


    /* Make Objects */

    /* Room Device */
    ent_room_device_0000000001 = adm_make_object_room_device(ADM_STATUS_ROOM_DEVICE_REDIRECT);
    ent_room_device_0000000002 = adm_make_object_room_device(ADM_STATUS_ROOM_DEVICE_REDIRECT);
    ent_room_device_0000000003 = adm_make_object_room_device(ADM_STATUS_ROOM_DEVICE_REDIRECT);
    ent_room_device_0000000004 = adm_make_object_room_device(ADM_STATUS_ROOM_DEVICE_REDIRECT);

    /* Room Door */
    ent_room_door_0000000005 = adm_make_object_room_door(ADM_STATUS_ROOM_DOOR_OPEN);

    /* Secret Panel */
    ent_secret_panel_0000000006 = adm_make_object_secret_panel(ADM_STATUS_SECRET_PANEL_CLOSED);

    /* Unlocking Device */
    ent_unlocking_device_0000000007 = adm_make_object_unlocking_device(ADM_STATUS_UNLOCKING_DEVICE_UPDATING);
    ent_unlocking_device_0000000008 = adm_make_object_unlocking_device(ADM_STATUS_UNLOCKING_DEVICE_UPDATING);

    /* Unlocking Sequence */
    ent_unlocking_sequence_0000000009 = adm_make_object_unlocking_sequence(ADM_STATUS_UNLOCKING_SEQUENCE_IDLE);
    ent_unlocking_sequence_0000000010 = adm_make_object_unlocking_sequence(ADM_STATUS_UNLOCKING_SEQUENCE_IDLE);

    /* Unlock Step */
    ent_unlock_step_0000000011 = adm_make_object_unlock_step(ADM_STATUS_UNLOCK_STEP_LOCKED);
    ent_unlock_step_0000000012 = adm_make_object_unlock_step(ADM_STATUS_UNLOCK_STEP_LOCKED);
    ent_unlock_step_0000000013 = adm_make_object_unlock_step(ADM_STATUS_UNLOCK_STEP_LOCKED);
    ent_unlock_step_0000000014 = adm_make_object_unlock_step(ADM_STATUS_UNLOCK_STEP_LOCKED);

    /* Room */
    ent_room_0000000015 = adm_make_object_room();


    /* Object Fact Assignments */

    /* Room Device */

    strcpy_s(ent_room_device_0000000001->atb_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Door");

    strcpy_s(ent_room_device_0000000002->atb_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Panel");

    strcpy_s(ent_room_device_0000000003->atb_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Light");

    strcpy_s(ent_room_device_0000000004->atb_name, ADM_TYPE_SIZE_TEXT+1,(adm_str_text_typ*)&"Drawer");

    /* Room */

    ent_room_0000000015->atb_number = 101;


    /* Bind Objects */

    /* Room Device */
    adm_bind_object_room_device(
        ent_room_device_0000000001,
        10, 15, 25);
    adm_bind_object_room_device(
        ent_room_device_0000000002,
        10, 16, 25);
    adm_bind_object_room_device(
        ent_room_device_0000000003,
        10, 17, 25);
    adm_bind_object_room_device(
        ent_room_device_0000000004,
        10, 18, 25);

    /* Room Door */
    adm_bind_object_room_door(
        ent_room_door_0000000005,
        10, 37, 25);

    /* Secret Panel */
    adm_bind_object_secret_panel(
        ent_secret_panel_0000000006,
        10, 46, 25);

    /* Unlocking Device */
    adm_bind_object_unlocking_device(
        ent_unlocking_device_0000000007,
        10, 58, 25);
    adm_bind_object_unlocking_device(
        ent_unlocking_device_0000000008,
        10, 59, 25);

    /* Unlocking Sequence */
    adm_bind_object_unlocking_sequence(
        ent_unlocking_sequence_0000000009,
        10, 71, 25);
    adm_bind_object_unlocking_sequence(
        ent_unlocking_sequence_0000000010,
        10, 72, 25);

    /* Unlock Step */
    adm_bind_object_unlock_step(
        ent_unlock_step_0000000011,
        10, 85, 25);
    adm_bind_object_unlock_step(
        ent_unlock_step_0000000012,
        10, 86, 25);
    adm_bind_object_unlock_step(
        ent_unlock_step_0000000013,
        10, 87, 25);
    adm_bind_object_unlock_step(
        ent_unlock_step_0000000014,
        10, 88, 25);

    /* Room */
    adm_bind_object_room(
        ent_room_0000000015,
        10, 103, 25);


    /* Link Relations */

    /* Room Device */

    adm_link_relation_room_device_contained_in_room(
        ent_room_device_0000000001,
        ent_room_0000000015,
        10, 20, 25);

    adm_link_relation_room_device_contained_in_room(
        ent_room_device_0000000002,
        ent_room_0000000015,
        10, 21, 25);

    adm_link_relation_room_device_contained_in_room(
        ent_room_device_0000000003,
        ent_room_0000000015,
        10, 22, 25);

    adm_link_relation_room_device_contained_in_room(
        ent_room_device_0000000004,
        ent_room_0000000015,
        10, 23, 25);

    adm_link_relation_room_device_generalisation_room_door(
        ent_room_device_0000000001,
        ent_room_door_0000000005,
        10, 25, 25);

    adm_link_relation_room_device_generalisation_secret_panel(
        ent_room_device_0000000002,
        ent_secret_panel_0000000006,
        10, 27, 25);

    adm_link_relation_room_device_generalisation_unlocking_device(
        ent_room_device_0000000003,
        ent_unlocking_device_0000000007,
        10, 29, 25);

    adm_link_relation_room_device_generalisation_unlocking_device(
        ent_room_device_0000000004,
        ent_unlocking_device_0000000008,
        10, 30, 25);

    /* Room Door */

    adm_link_relation_room_door_specialisation_room_device(
        ent_room_door_0000000005,
        ent_room_device_0000000001,
        10, 39, 25);

    /* Secret Panel */

    adm_link_relation_secret_panel_opened_by_unlocking_sequence(
        ent_secret_panel_0000000006,
        ent_unlocking_sequence_0000000009,
        10, 48, 25);

    adm_link_relation_secret_panel_opened_by_unlocking_sequence(
        ent_secret_panel_0000000006,
        ent_unlocking_sequence_0000000010,
        10, 49, 25);

    adm_link_relation_secret_panel_specialisation_room_device(
        ent_secret_panel_0000000006,
        ent_room_device_0000000002,
        10, 51, 25);

    /* Unlocking Device */

    adm_link_relation_unlocking_device_sets_unlock_step(
        ent_unlocking_device_0000000007,
        ent_unlock_step_0000000011,
        10, 61, 25);

    adm_link_relation_unlocking_device_sets_unlock_step(
        ent_unlocking_device_0000000007,
        ent_unlock_step_0000000014,
        10, 62, 25);

    adm_link_relation_unlocking_device_sets_unlock_step(
        ent_unlocking_device_0000000008,
        ent_unlock_step_0000000012,
        10, 63, 25);

    adm_link_relation_unlocking_device_sets_unlock_step(
        ent_unlocking_device_0000000008,
        ent_unlock_step_0000000013,
        10, 64, 25);

    /* Unlocking Sequence */

    adm_link_relation_unlocking_sequence_opens_secret_panel(
        ent_unlocking_sequence_0000000009,
        ent_secret_panel_0000000006,
        10, 74, 25);

    adm_link_relation_unlocking_sequence_opens_secret_panel(
        ent_unlocking_sequence_0000000010,
        ent_secret_panel_0000000006,
        10, 75, 25);

    adm_link_relation_unlocking_sequence_starts_at_unlock_step(
        ent_unlocking_sequence_0000000009,
        ent_unlock_step_0000000011,
        10, 77, 25);

    adm_link_relation_unlocking_sequence_starts_at_unlock_step(
        ent_unlocking_sequence_0000000010,
        ent_unlock_step_0000000013,
        10, 78, 25);

    /* Unlock Step */

    adm_link_relation_unlock_step_followed_by_unlock_step(
        ent_unlock_step_0000000011,
        ent_unlock_step_0000000012,
        10, 90, 25);

    adm_link_relation_unlock_step_followed_by_unlock_step(
        ent_unlock_step_0000000013,
        ent_unlock_step_0000000014,
        10, 91, 25);

    adm_link_relation_unlock_step_part_of_unlocking_sequence(
        ent_unlock_step_0000000011,
        ent_unlocking_sequence_0000000009,
        10, 93, 25);

    adm_link_relation_unlock_step_part_of_unlocking_sequence(
        ent_unlock_step_0000000012,
        ent_unlocking_sequence_0000000009,
        10, 94, 25);

    adm_link_relation_unlock_step_part_of_unlocking_sequence(
        ent_unlock_step_0000000013,
        ent_unlocking_sequence_0000000010,
        10, 95, 25);

    adm_link_relation_unlock_step_part_of_unlocking_sequence(
        ent_unlock_step_0000000014,
        ent_unlocking_sequence_0000000010,
        10, 96, 25);

    /* Room */

    adm_link_relation_room_contains_room_device(
        ent_room_0000000015,
        ent_room_device_0000000001,
        10, 105, 25);

    adm_link_relation_room_contains_room_device(
        ent_room_0000000015,
        ent_room_device_0000000002,
        10, 106, 25);

    adm_link_relation_room_contains_room_device(
        ent_room_0000000015,
        ent_room_device_0000000003,
        10, 107, 25);

    adm_link_relation_room_contains_room_device(
        ent_room_0000000015,
        ent_room_device_0000000004,
        10, 108, 25);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_initialisation_gothic_security");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */