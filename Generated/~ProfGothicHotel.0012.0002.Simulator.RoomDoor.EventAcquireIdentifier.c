
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Simulator Room Door Acquire Identifier Event */

void adm_sim_acquire_identifier_event_room_door_door_closed_room_door_identifier(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_room_device_name [ADM_TYPE_SIZE_TEXT+1];
    adm_base_integer_typ key_num_room_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_door_closed_room_door_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_room_device_name,
        ADM_TYPE_SIZE_TEXT+1);

    key_num_room_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_room_number < ADM_TYPE_MINIMUM_NUMBER ||
        key_num_room_number > ADM_TYPE_MAXIMUM_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_room_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (
            !strcmp(((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->atb_name, key_nme_room_device_name) &&
            ((((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->rel_contained_in_room_head)->
                ent_room)->atb_number == key_num_room_number) {

            adm_send_event_room_door_door_closed(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_door_closed_room_door_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_room_door_door_opened_room_door_identifier(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_room_device_name [ADM_TYPE_SIZE_TEXT+1];
    adm_base_integer_typ key_num_room_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_door_opened_room_door_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_room_device_name,
        ADM_TYPE_SIZE_TEXT+1);

    key_num_room_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_room_number < ADM_TYPE_MINIMUM_NUMBER ||
        key_num_room_number > ADM_TYPE_MAXIMUM_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_room_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (
            !strcmp(((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->atb_name, key_nme_room_device_name) &&
            ((((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->rel_contained_in_room_head)->
                ent_room)->atb_number == key_num_room_number) {

            adm_send_event_room_door_door_opened(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_door_opened_room_door_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_room_door_lock_door_room_door_identifier(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_room_device_name [ADM_TYPE_SIZE_TEXT+1];
    adm_base_integer_typ key_num_room_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_lock_door_room_door_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_room_device_name,
        ADM_TYPE_SIZE_TEXT+1);

    key_num_room_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_room_number < ADM_TYPE_MINIMUM_NUMBER ||
        key_num_room_number > ADM_TYPE_MAXIMUM_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_room_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (
            !strcmp(((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->atb_name, key_nme_room_device_name) &&
            ((((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->rel_contained_in_room_head)->
                ent_room)->atb_number == key_num_room_number) {

            adm_send_event_room_door_lock_door(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_lock_door_room_door_identifier");
    #endif
}

void adm_sim_acquire_identifier_event_room_door_unlock_door_room_door_identifier(
    void)
{
    adm_ent_room_door_typ * ent_room_door;
    adm_base_boolean_typ entity_not_found;
    adm_base_string_typ key_nme_room_device_name [ADM_TYPE_SIZE_TEXT+1];
    adm_base_integer_typ key_num_room_number;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_unlock_door_room_door_identifier");
    #endif

    /* Fetch Event Keys */

    adm_sim_str_fetch(
        key_nme_room_device_name,
        ADM_TYPE_SIZE_TEXT+1);

    key_num_room_number = adm_sim_int_fetch();

    /* Check Event Key Type Ranges */

    if (
        key_num_room_number < ADM_TYPE_MINIMUM_NUMBER ||
        key_num_room_number > ADM_TYPE_MAXIMUM_NUMBER) {

        adm_sim_error_report(
            ADM_SIM_ERROR_RANGE_INTEGER,
            adm_sim_lib_itoa(key_num_room_number));
    }

    /* Generate Event */

    entity_not_found = TRUE;

    ent_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (
        entity_not_found &&
        ent_room_door != NULL) {

        if (
            !strcmp(((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->atb_name, key_nme_room_device_name) &&
            ((((
                ent_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->rel_contained_in_room_head)->
                ent_room)->atb_number == key_num_room_number) {

            adm_send_event_room_door_unlock_door(
                NULL,
                ent_room_door,
                0, 0, 0);

            entity_not_found = FALSE;
        }

        ent_room_door = ent_room_door->next;
    }

    /* Check Object Identifier */

    if (entity_not_found)
        adm_sim_error_report(
            ADM_SIM_ERROR_UNKNOWN_IDENTIFIER,
            NULL);

    adm_sim_simulate();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_SIMULATOR, "adm_sim_acquire_identifier_event_room_door_unlock_door_room_door_identifier");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */