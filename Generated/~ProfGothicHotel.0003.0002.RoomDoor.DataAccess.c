
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Door Data Access */

/* Make Entity Object */

adm_ent_room_door_typ * adm_make_object_room_door(
    adm_sta_room_door_typ status)
{
    adm_ent_room_door_typ * ent_room_door;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_room_door");
    #endif

    if (adm_entity_system.ent_room_door.dead_list_head != NULL) {

        ent_room_door = adm_entity_system.ent_room_door.dead_list_head;

        if (adm_entity_system.ent_room_door.dead_list_head == ent_room_door) {

            adm_entity_system.ent_room_door.dead_list_head = ent_room_door->next;

        } else {

            (ent_room_door->back)->next = ent_room_door->next;
        }

        if (adm_entity_system.ent_room_door.dead_list_tail == ent_room_door) {

            adm_entity_system.ent_room_door.dead_list_tail = ent_room_door->back;

        } else {

            (ent_room_door->next)->back = ent_room_door->back;
        }

    } else {

        ent_room_door = (adm_ent_room_door_typ*)adm_allocate_memory(sizeof(adm_ent_room_door_typ));
    }

    ent_room_door->identity = ++adm_entity_system.ent_room_door.tote;

    ent_room_door->unique  = FALSE;
    ent_room_door->deleted = FALSE;
    ent_room_door->marked  = FALSE;
    ent_room_door->status  = status;

    ent_room_door->rel_specialisation_room_device_head = NULL;
    ent_room_door->rel_specialisation_room_device_tail = NULL;

    ent_room_door->back = NULL;
    ent_room_door->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_room_door");
    #endif

    return (ent_room_door);
}


/* Bind Entity Object */

void adm_bind_object_room_door(
    adm_ent_room_door_typ * ent_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_room_door");
    #endif

    adm_object_existent_room_door(
        ent_room_door,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_room_door.live_list_head == NULL) {

        ent_room_door->back = NULL;

        adm_entity_system.ent_room_door.live_list_head = ent_room_door;

    } else {

        ent_room_door->back = adm_entity_system.ent_room_door.live_list_tail;

        (adm_entity_system.ent_room_door.live_list_tail)->next = ent_room_door;
    }

    ent_room_door->next = NULL;

    adm_entity_system.ent_room_door.live_list_tail = ent_room_door;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_room_door");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_room_door(
    void * source_object,
    adm_ent_room_door_typ * ent_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_room_door");
    #endif

    adm_object_existent_room_door(
        ent_room_door,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_room_door) {

        if (ent_room_door->rel_specialisation_room_device_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Room_Door",
                ent_room_door->identity,
                "Specialisation",
                "Room_Device");
        }

        if (adm_entity_system.ent_room_door.live_list_head == ent_room_door) {

            adm_entity_system.ent_room_door.live_list_head = ent_room_door->next;

        } else {

            (ent_room_door->back)->next = ent_room_door->next;
        }

        if (adm_entity_system.ent_room_door.live_list_tail == ent_room_door) {

            adm_entity_system.ent_room_door.live_list_tail = ent_room_door->back;

        } else {

            (ent_room_door->next)->back = ent_room_door->back;
        }

        ent_room_door->deleted = TRUE;

        if (adm_entity_system.ent_room_door.dead_list_head == NULL) {

            ent_room_door->back = NULL;

            adm_entity_system.ent_room_door.dead_list_head = ent_room_door;

        } else {

            ent_room_door->back = adm_entity_system.ent_room_door.dead_list_tail;

            (adm_entity_system.ent_room_door.dead_list_tail)->next = ent_room_door;
        }

        ent_room_door->next = NULL;

        adm_entity_system.ent_room_door.dead_list_tail = ent_room_door;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Room_Door",
            ent_room_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_room_door");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_room_door_specialisation_room_device(
    adm_ent_room_door_typ * ent_source_room_door,
    adm_ent_room_device_typ * ent_target_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device;

    adm_base_boolean_typ room_device_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_door_specialisation_room_device");
    #endif

    adm_object_existent_room_door(
        ent_source_room_door,
        error_file,
        error_line,
        error_rank);

    room_device_not_found = TRUE;

    rel_room_door_specialisation_room_device = ent_source_room_door->rel_specialisation_room_device_head;

    while (
        room_device_not_found &&
        rel_room_door_specialisation_room_device != NULL) {

        if (rel_room_door_specialisation_room_device->ent_room_device == ent_target_room_device) {

            room_device_not_found = FALSE;
        }

        rel_room_door_specialisation_room_device = rel_room_door_specialisation_room_device->next;
    }

    if (room_device_not_found) {

        rel_room_door_specialisation_room_device = (adm_rel_room_door_specialisation_room_device_typ*)
            adm_allocate_memory(sizeof(adm_rel_room_door_specialisation_room_device_typ));

        rel_room_door_specialisation_room_device->ent_room_device = ent_target_room_device;

        if (ent_source_room_door->rel_specialisation_room_device_head == NULL) {

            rel_room_door_specialisation_room_device->back = NULL;

            ent_source_room_door->rel_specialisation_room_device_head = rel_room_door_specialisation_room_device;

        } else {

            rel_room_door_specialisation_room_device->back = ent_source_room_door->rel_specialisation_room_device_tail;

            (ent_source_room_door->rel_specialisation_room_device_tail)->next = rel_room_door_specialisation_room_device;
        }

        rel_room_door_specialisation_room_device->next = NULL;

        ent_source_room_door->rel_specialisation_room_device_tail = rel_room_door_specialisation_room_device;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Room_Door",
            ent_source_room_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_door_specialisation_room_device");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_room_door_specialisation_room_device(
    adm_ent_room_door_typ * ent_room_door,
    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_door_specialisation_room_device");
    #endif

    adm_object_existent_room_door(
        ent_room_door,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_room_door_specialisation_room_device->next !=
        (adm_base_integer_typ)rel_room_door_specialisation_room_device->ent_room_device) {

        if (ent_room_door->rel_specialisation_room_device_head != NULL) {

            if (ent_room_door->rel_specialisation_room_device_head == rel_room_door_specialisation_room_device) {

                ent_room_door->rel_specialisation_room_device_head = rel_room_door_specialisation_room_device->next;

            } else {

                (rel_room_door_specialisation_room_device->back)->next = rel_room_door_specialisation_room_device->next;
            }

            if (ent_room_door->rel_specialisation_room_device_tail == rel_room_door_specialisation_room_device) {

                ent_room_door->rel_specialisation_room_device_tail = rel_room_door_specialisation_room_device->back;

            } else {

                (rel_room_door_specialisation_room_device->next)->back = rel_room_door_specialisation_room_device->back;
            }

            adm_deallocate_memory(rel_room_door_specialisation_room_device);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Room_Door",
                ent_room_door->identity,
                "Specialisation",
                "Room_Device");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Room_Door",
            ent_room_door->identity,
            "Specialisation",
            "Room_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_door_specialisation_room_device");
    #endif
}


/* Object Existent */

void adm_object_existent_room_door(
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_room_door");
    #endif

    if (ent_room_door->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Room_Door",
            ent_room_door->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_room_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */