
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Device Data Access */

/* Make Entity Object */

adm_ent_room_device_typ * adm_make_object_room_device(
    adm_sta_room_device_typ status)
{
    adm_ent_room_device_typ * ent_room_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_room_device");
    #endif

    if (adm_entity_system.ent_room_device.dead_list_head != NULL) {

        ent_room_device = adm_entity_system.ent_room_device.dead_list_head;

        if (adm_entity_system.ent_room_device.dead_list_head == ent_room_device) {

            adm_entity_system.ent_room_device.dead_list_head = ent_room_device->next;

        } else {

            (ent_room_device->back)->next = ent_room_device->next;
        }

        if (adm_entity_system.ent_room_device.dead_list_tail == ent_room_device) {

            adm_entity_system.ent_room_device.dead_list_tail = ent_room_device->back;

        } else {

            (ent_room_device->next)->back = ent_room_device->back;
        }

    } else {

        ent_room_device = (adm_ent_room_device_typ*)adm_allocate_memory(sizeof(adm_ent_room_device_typ));
    }

    ent_room_device->identity = ++adm_entity_system.ent_room_device.tote;

    ent_room_device->unique  = FALSE;
    ent_room_device->deleted = FALSE;
    ent_room_device->marked  = FALSE;
    ent_room_device->status  = status;

    ent_room_device->atb_name = (adm_str_text_typ*)adm_allocate_memory(ADM_TYPE_SIZE_TEXT+1);

    ent_room_device->rel_contained_in_room_head = NULL;
    ent_room_device->rel_contained_in_room_tail = NULL;

    ent_room_device->rel_generalisation_room_door_head = NULL;
    ent_room_device->rel_generalisation_room_door_tail = NULL;

    ent_room_device->rel_generalisation_secret_panel_head = NULL;
    ent_room_device->rel_generalisation_secret_panel_tail = NULL;

    ent_room_device->rel_generalisation_unlocking_device_head = NULL;
    ent_room_device->rel_generalisation_unlocking_device_tail = NULL;

    ent_room_device->back = NULL;
    ent_room_device->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_room_device");
    #endif

    return (ent_room_device);
}


/* Bind Entity Object */

void adm_bind_object_room_device(
    adm_ent_room_device_typ * ent_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_room_device");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_room_device.live_list_head == NULL) {

        ent_room_device->back = NULL;

        adm_entity_system.ent_room_device.live_list_head = ent_room_device;

    } else {

        ent_room_device->back = adm_entity_system.ent_room_device.live_list_tail;

        (adm_entity_system.ent_room_device.live_list_tail)->next = ent_room_device;
    }

    ent_room_device->next = NULL;

    adm_entity_system.ent_room_device.live_list_tail = ent_room_device;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_room_device");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_room_device(
    void * source_object,
    adm_ent_room_device_typ * ent_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_room_device");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_room_device) {

        if (ent_room_device->rel_contained_in_room_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Contained_in",
                "Room");
        }

        if (ent_room_device->rel_generalisation_room_door_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Room_Door");
        }

        if (ent_room_device->rel_generalisation_secret_panel_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Secret_Panel");
        }

        if (ent_room_device->rel_generalisation_unlocking_device_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Unlocking_Device");
        }

        if (adm_entity_system.ent_room_device.live_list_head == ent_room_device) {

            adm_entity_system.ent_room_device.live_list_head = ent_room_device->next;

        } else {

            (ent_room_device->back)->next = ent_room_device->next;
        }

        if (adm_entity_system.ent_room_device.live_list_tail == ent_room_device) {

            adm_entity_system.ent_room_device.live_list_tail = ent_room_device->back;

        } else {

            (ent_room_device->next)->back = ent_room_device->back;
        }

        adm_deallocate_memory(ent_room_device->atb_name);

        ent_room_device->deleted = TRUE;

        if (adm_entity_system.ent_room_device.dead_list_head == NULL) {

            ent_room_device->back = NULL;

            adm_entity_system.ent_room_device.dead_list_head = ent_room_device;

        } else {

            ent_room_device->back = adm_entity_system.ent_room_device.dead_list_tail;

            (adm_entity_system.ent_room_device.dead_list_tail)->next = ent_room_device;
        }

        ent_room_device->next = NULL;

        adm_entity_system.ent_room_device.dead_list_tail = ent_room_device;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_room_device");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_room_device_contained_in_room(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_room_typ * ent_target_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room;

    adm_base_boolean_typ room_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_contained_in_room");
    #endif

    adm_object_existent_room_device(
        ent_source_room_device,
        error_file,
        error_line,
        error_rank);

    room_not_found = TRUE;

    rel_room_device_contained_in_room = ent_source_room_device->rel_contained_in_room_head;

    while (
        room_not_found &&
        rel_room_device_contained_in_room != NULL) {

        if (rel_room_device_contained_in_room->ent_room == ent_target_room) {

            room_not_found = FALSE;
        }

        rel_room_device_contained_in_room = rel_room_device_contained_in_room->next;
    }

    if (room_not_found) {

        rel_room_device_contained_in_room = (adm_rel_room_device_contained_in_room_typ*)
            adm_allocate_memory(sizeof(adm_rel_room_device_contained_in_room_typ));

        rel_room_device_contained_in_room->ent_room = ent_target_room;

        if (ent_source_room_device->rel_contained_in_room_head == NULL) {

            rel_room_device_contained_in_room->back = NULL;

            ent_source_room_device->rel_contained_in_room_head = rel_room_device_contained_in_room;

        } else {

            rel_room_device_contained_in_room->back = ent_source_room_device->rel_contained_in_room_tail;

            (ent_source_room_device->rel_contained_in_room_tail)->next = rel_room_device_contained_in_room;
        }

        rel_room_device_contained_in_room->next = NULL;

        ent_source_room_device->rel_contained_in_room_tail = rel_room_device_contained_in_room;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_source_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_contained_in_room");
    #endif
}

void adm_link_relation_room_device_generalisation_room_door(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_room_door_typ * ent_target_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door;

    adm_base_boolean_typ room_door_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_room_door");
    #endif

    adm_object_existent_room_device(
        ent_source_room_device,
        error_file,
        error_line,
        error_rank);

    room_door_not_found = TRUE;

    rel_room_device_generalisation_room_door = ent_source_room_device->rel_generalisation_room_door_head;

    while (
        room_door_not_found &&
        rel_room_device_generalisation_room_door != NULL) {

        if (rel_room_device_generalisation_room_door->ent_room_door == ent_target_room_door) {

            room_door_not_found = FALSE;
        }

        rel_room_device_generalisation_room_door = rel_room_device_generalisation_room_door->next;
    }

    if (room_door_not_found) {

        rel_room_device_generalisation_room_door = (adm_rel_room_device_generalisation_room_door_typ*)
            adm_allocate_memory(sizeof(adm_rel_room_device_generalisation_room_door_typ));

        rel_room_device_generalisation_room_door->ent_room_door = ent_target_room_door;

        if (ent_source_room_device->rel_generalisation_room_door_head == NULL) {

            rel_room_device_generalisation_room_door->back = NULL;

            ent_source_room_device->rel_generalisation_room_door_head = rel_room_device_generalisation_room_door;

        } else {

            rel_room_device_generalisation_room_door->back = ent_source_room_device->rel_generalisation_room_door_tail;

            (ent_source_room_device->rel_generalisation_room_door_tail)->next = rel_room_device_generalisation_room_door;
        }

        rel_room_device_generalisation_room_door->next = NULL;

        ent_source_room_device->rel_generalisation_room_door_tail = rel_room_device_generalisation_room_door;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_source_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_room_door");
    #endif
}

void adm_link_relation_room_device_generalisation_secret_panel(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_secret_panel_typ * ent_target_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel;

    adm_base_boolean_typ secret_panel_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_secret_panel");
    #endif

    adm_object_existent_room_device(
        ent_source_room_device,
        error_file,
        error_line,
        error_rank);

    secret_panel_not_found = TRUE;

    rel_room_device_generalisation_secret_panel = ent_source_room_device->rel_generalisation_secret_panel_head;

    while (
        secret_panel_not_found &&
        rel_room_device_generalisation_secret_panel != NULL) {

        if (rel_room_device_generalisation_secret_panel->ent_secret_panel == ent_target_secret_panel) {

            secret_panel_not_found = FALSE;
        }

        rel_room_device_generalisation_secret_panel = rel_room_device_generalisation_secret_panel->next;
    }

    if (secret_panel_not_found) {

        rel_room_device_generalisation_secret_panel = (adm_rel_room_device_generalisation_secret_panel_typ*)
            adm_allocate_memory(sizeof(adm_rel_room_device_generalisation_secret_panel_typ));

        rel_room_device_generalisation_secret_panel->ent_secret_panel = ent_target_secret_panel;

        if (ent_source_room_device->rel_generalisation_secret_panel_head == NULL) {

            rel_room_device_generalisation_secret_panel->back = NULL;

            ent_source_room_device->rel_generalisation_secret_panel_head = rel_room_device_generalisation_secret_panel;

        } else {

            rel_room_device_generalisation_secret_panel->back = ent_source_room_device->rel_generalisation_secret_panel_tail;

            (ent_source_room_device->rel_generalisation_secret_panel_tail)->next = rel_room_device_generalisation_secret_panel;
        }

        rel_room_device_generalisation_secret_panel->next = NULL;

        ent_source_room_device->rel_generalisation_secret_panel_tail = rel_room_device_generalisation_secret_panel;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_source_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_secret_panel");
    #endif
}

void adm_link_relation_room_device_generalisation_unlocking_device(
    adm_ent_room_device_typ * ent_source_room_device,
    adm_ent_unlocking_device_typ * ent_target_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_room_device_generalisation_unlocking_device_typ * rel_room_device_generalisation_unlocking_device;

    adm_base_boolean_typ unlocking_device_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_unlocking_device");
    #endif

    adm_object_existent_room_device(
        ent_source_room_device,
        error_file,
        error_line,
        error_rank);

    unlocking_device_not_found = TRUE;

    rel_room_device_generalisation_unlocking_device = ent_source_room_device->rel_generalisation_unlocking_device_head;

    while (
        unlocking_device_not_found &&
        rel_room_device_generalisation_unlocking_device != NULL) {

        if (rel_room_device_generalisation_unlocking_device->ent_unlocking_device == ent_target_unlocking_device) {

            unlocking_device_not_found = FALSE;
        }

        rel_room_device_generalisation_unlocking_device = rel_room_device_generalisation_unlocking_device->next;
    }

    if (unlocking_device_not_found) {

        rel_room_device_generalisation_unlocking_device = (adm_rel_room_device_generalisation_unlocking_device_typ*)
            adm_allocate_memory(sizeof(adm_rel_room_device_generalisation_unlocking_device_typ));

        rel_room_device_generalisation_unlocking_device->ent_unlocking_device = ent_target_unlocking_device;

        if (ent_source_room_device->rel_generalisation_unlocking_device_head == NULL) {

            rel_room_device_generalisation_unlocking_device->back = NULL;

            ent_source_room_device->rel_generalisation_unlocking_device_head = rel_room_device_generalisation_unlocking_device;

        } else {

            rel_room_device_generalisation_unlocking_device->back = ent_source_room_device->rel_generalisation_unlocking_device_tail;

            (ent_source_room_device->rel_generalisation_unlocking_device_tail)->next = rel_room_device_generalisation_unlocking_device;
        }

        rel_room_device_generalisation_unlocking_device->next = NULL;

        ent_source_room_device->rel_generalisation_unlocking_device_tail = rel_room_device_generalisation_unlocking_device;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_source_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_room_device_generalisation_unlocking_device");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_room_device_contained_in_room(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_contained_in_room_typ * rel_room_device_contained_in_room,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_contained_in_room");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_room_device_contained_in_room->next !=
        (adm_base_integer_typ)rel_room_device_contained_in_room->ent_room) {

        if (ent_room_device->rel_contained_in_room_head != NULL) {

            if (ent_room_device->rel_contained_in_room_head == rel_room_device_contained_in_room) {

                ent_room_device->rel_contained_in_room_head = rel_room_device_contained_in_room->next;

            } else {

                (rel_room_device_contained_in_room->back)->next = rel_room_device_contained_in_room->next;
            }

            if (ent_room_device->rel_contained_in_room_tail == rel_room_device_contained_in_room) {

                ent_room_device->rel_contained_in_room_tail = rel_room_device_contained_in_room->back;

            } else {

                (rel_room_device_contained_in_room->next)->back = rel_room_device_contained_in_room->back;
            }

            adm_deallocate_memory(rel_room_device_contained_in_room);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Contained_in",
                "Room");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            "Contained_in",
            "Room");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_contained_in_room");
    #endif
}

void adm_kill_relation_room_device_generalisation_room_door(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_room_door_typ * rel_room_device_generalisation_room_door,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_room_door");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_room_device_generalisation_room_door->next !=
        (adm_base_integer_typ)rel_room_device_generalisation_room_door->ent_room_door) {

        if (ent_room_device->rel_generalisation_room_door_head != NULL) {

            if (ent_room_device->rel_generalisation_room_door_head == rel_room_device_generalisation_room_door) {

                ent_room_device->rel_generalisation_room_door_head = rel_room_device_generalisation_room_door->next;

            } else {

                (rel_room_device_generalisation_room_door->back)->next = rel_room_device_generalisation_room_door->next;
            }

            if (ent_room_device->rel_generalisation_room_door_tail == rel_room_device_generalisation_room_door) {

                ent_room_device->rel_generalisation_room_door_tail = rel_room_device_generalisation_room_door->back;

            } else {

                (rel_room_device_generalisation_room_door->next)->back = rel_room_device_generalisation_room_door->back;
            }

            adm_deallocate_memory(rel_room_device_generalisation_room_door);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Room_Door");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            "Generalisation",
            "Room_Door");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_room_door");
    #endif
}

void adm_kill_relation_room_device_generalisation_secret_panel(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_secret_panel_typ * rel_room_device_generalisation_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_secret_panel");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_room_device_generalisation_secret_panel->next !=
        (adm_base_integer_typ)rel_room_device_generalisation_secret_panel->ent_secret_panel) {

        if (ent_room_device->rel_generalisation_secret_panel_head != NULL) {

            if (ent_room_device->rel_generalisation_secret_panel_head == rel_room_device_generalisation_secret_panel) {

                ent_room_device->rel_generalisation_secret_panel_head = rel_room_device_generalisation_secret_panel->next;

            } else {

                (rel_room_device_generalisation_secret_panel->back)->next = rel_room_device_generalisation_secret_panel->next;
            }

            if (ent_room_device->rel_generalisation_secret_panel_tail == rel_room_device_generalisation_secret_panel) {

                ent_room_device->rel_generalisation_secret_panel_tail = rel_room_device_generalisation_secret_panel->back;

            } else {

                (rel_room_device_generalisation_secret_panel->next)->back = rel_room_device_generalisation_secret_panel->back;
            }

            adm_deallocate_memory(rel_room_device_generalisation_secret_panel);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Secret_Panel");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            "Generalisation",
            "Secret_Panel");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_secret_panel");
    #endif
}

void adm_kill_relation_room_device_generalisation_unlocking_device(
    adm_ent_room_device_typ * ent_room_device,
    adm_rel_room_device_generalisation_unlocking_device_typ * rel_room_device_generalisation_unlocking_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_unlocking_device");
    #endif

    adm_object_existent_room_device(
        ent_room_device,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_room_device_generalisation_unlocking_device->next !=
        (adm_base_integer_typ)rel_room_device_generalisation_unlocking_device->ent_unlocking_device) {

        if (ent_room_device->rel_generalisation_unlocking_device_head != NULL) {

            if (ent_room_device->rel_generalisation_unlocking_device_head == rel_room_device_generalisation_unlocking_device) {

                ent_room_device->rel_generalisation_unlocking_device_head = rel_room_device_generalisation_unlocking_device->next;

            } else {

                (rel_room_device_generalisation_unlocking_device->back)->next = rel_room_device_generalisation_unlocking_device->next;
            }

            if (ent_room_device->rel_generalisation_unlocking_device_tail == rel_room_device_generalisation_unlocking_device) {

                ent_room_device->rel_generalisation_unlocking_device_tail = rel_room_device_generalisation_unlocking_device->back;

            } else {

                (rel_room_device_generalisation_unlocking_device->next)->back = rel_room_device_generalisation_unlocking_device->back;
            }

            adm_deallocate_memory(rel_room_device_generalisation_unlocking_device);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Room_Device",
                ent_room_device->identity,
                "Generalisation",
                "Unlocking_Device");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            "Generalisation",
            "Unlocking_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_room_device_generalisation_unlocking_device");
    #endif
}


/* Object Existent */

void adm_object_existent_room_device(
    const adm_ent_room_device_typ * const ent_room_device,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_room_device");
    #endif

    if (ent_room_device->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Room_Device",
            ent_room_device->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_room_device");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */