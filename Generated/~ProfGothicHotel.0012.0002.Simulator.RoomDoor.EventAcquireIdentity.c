
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Room Door Acquire Identity Event */

void adm_sim_acquire_identity_event_room_door_door_closed(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_door_closed");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (ent_room_door->identity == identity) {

            adm_send_event_room_door_door_closed(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_door_closed");
    #endif
}

void adm_sim_acquire_identity_event_room_door_door_opened(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_door_opened");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (ent_room_door->identity == identity) {

            adm_send_event_room_door_door_opened(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_door_opened");
    #endif
}

void adm_sim_acquire_identity_event_room_door_lock_door(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_lock_door");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (ent_room_door->identity == identity) {

            adm_send_event_room_door_lock_door(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_lock_door");
    #endif
}

void adm_sim_acquire_identity_event_room_door_unlock_door(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_integer_typ identity;
    adm_base_boolean_typ entity_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_unlock_door");
    #endif

    /* Fetch Identity */

    identity = adm_sim_idt_fetch();

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (ent_room_door->identity == identity) {

            adm_send_event_room_door_unlock_door(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Identity */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTITY,
            adm_sim_lib_itoa(identity));

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identity_event_room_door_unlock_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */