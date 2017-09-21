
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Check Room Identifiers Unique */

void adm_check_identifiers_unique_room(
    adm_ent_room_typ * ent_source_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_ent_room_typ * ent_target_room;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_room");
    #endif

    ent_target_room = adm_entity_system.ent_room.live_list_head;

    while (ent_target_room != NULL) {

        if (
            ent_target_room->atb_number == ent_source_room->atb_number) {

            adm_error_report(
                ADM_ERROR_OBJECT_IDENTIFIER_ATTRIBUTES_NOT_UNIQUE,
                error_file, error_line, error_rank,
                "Room",
                ent_target_room->identity,
                NULL,
                NULL);
        }

        ent_target_room = ent_target_room->next;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_IDENTIFIER, "adm_check_identifiers_unique_room");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */