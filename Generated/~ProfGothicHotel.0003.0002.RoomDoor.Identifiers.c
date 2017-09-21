
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Check Room Door Identifiers Unique */

void adm_check_identifiers_unique_room_door(
    adm_ent_room_door_typ * ent_source_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_room_door_typ * ent_target_room_door;

    adm_ent_room_device_typ * ent_room_device;
    adm_ent_room_typ * ent_room;

    adm_rel_room_door_specialisation_room_device_typ * rel_room_door_specialisation_room_device;
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_room_door");
    #endif

    if (!(
        ent_source_room_door->rel_specialisation_room_device_head == NULL ||
        ent_source_room_door->rel_specialisation_room_device_head !=
        ent_source_room_door->rel_specialisation_room_device_tail)) {

        rel_room_door_specialisation_room_device = ent_source_room_door->rel_specialisation_room_device_head;

        ent_room_device = rel_room_door_specialisation_room_device->ent_room_device;

        if (!(
            ent_room_device->rel_contained_in_room_head == NULL ||
            ent_room_device->rel_contained_in_room_head !=
            ent_room_device->rel_contained_in_room_tail)) {

            rel_room_device_contained_in_room = ent_room_device->rel_contained_in_room_head;

            ent_room = rel_room_device_contained_in_room->ent_room;

        } else {

            adm_error_report(
                ADM_ERROR_FOREIGN_KEY_IDENTIFIER_RELATION_INVALID,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_FOREIGN_KEY_IDENTIFIER_RELATION_INVALID,
            error_file, error_line, error_rank,
            "Room_Door",
            ent_source_room_door->identity,
            "Specialisation",
            "Room_Device");
    }

    ent_target_room_door = adm_entity_system.ent_room_door.live_list_head;

    while (ent_target_room_door != NULL) {

        if (
            !strcmp(((
                ent_target_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->atb_name, ent_room_device->atb_name) &&
            ((((
                ent_target_room_door->rel_specialisation_room_device_head)->
                ent_room_device)->rel_contained_in_room_head)->
                ent_room)->atb_number == ent_room->atb_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Room_Door",
                ent_target_room_door->identity,
                NULL,
                NULL);
        }

        ent_target_room_door = ent_target_room_door->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_room_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */