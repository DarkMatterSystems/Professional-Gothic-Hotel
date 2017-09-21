
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Secret Panel Data Access */

/* Make Entity Object */

adm_ent_secret_panel_typ * adm_make_object_secret_panel(
    adm_sta_secret_panel_typ status)
{
    adm_ent_secret_panel_typ * ent_secret_panel;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_secret_panel");
    #endif

    if (adm_entity_system.ent_secret_panel.dead_list_head != NULL) {

        ent_secret_panel = adm_entity_system.ent_secret_panel.dead_list_head;

        if (adm_entity_system.ent_secret_panel.dead_list_head == ent_secret_panel) {

            adm_entity_system.ent_secret_panel.dead_list_head = ent_secret_panel->next;

        } else {

            (ent_secret_panel->back)->next = ent_secret_panel->next;
        }

        if (adm_entity_system.ent_secret_panel.dead_list_tail == ent_secret_panel) {

            adm_entity_system.ent_secret_panel.dead_list_tail = ent_secret_panel->back;

        } else {

            (ent_secret_panel->next)->back = ent_secret_panel->back;
        }

    } else {

        ent_secret_panel = (adm_ent_secret_panel_typ*)adm_allocate_memory(sizeof(adm_ent_secret_panel_typ));
    }

    ent_secret_panel->identity = ++adm_entity_system.ent_secret_panel.tote;

    ent_secret_panel->unique  = FALSE;
    ent_secret_panel->deleted = FALSE;
    ent_secret_panel->marked  = FALSE;
    ent_secret_panel->status  = status;

    ent_secret_panel->rel_opened_by_unlocking_sequence_head = NULL;
    ent_secret_panel->rel_opened_by_unlocking_sequence_tail = NULL;

    ent_secret_panel->rel_specialisation_room_device_head = NULL;
    ent_secret_panel->rel_specialisation_room_device_tail = NULL;

    ent_secret_panel->back = NULL;
    ent_secret_panel->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_secret_panel");
    #endif

    return (ent_secret_panel);
}


/* Bind Entity Object */

void adm_bind_object_secret_panel(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_secret_panel");
    #endif

    adm_object_existent_secret_panel(
        ent_secret_panel,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_secret_panel.live_list_head == NULL) {

        ent_secret_panel->back = NULL;

        adm_entity_system.ent_secret_panel.live_list_head = ent_secret_panel;

    } else {

        ent_secret_panel->back = adm_entity_system.ent_secret_panel.live_list_tail;

        (adm_entity_system.ent_secret_panel.live_list_tail)->next = ent_secret_panel;
    }

    ent_secret_panel->next = NULL;

    adm_entity_system.ent_secret_panel.live_list_tail = ent_secret_panel;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_secret_panel");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_secret_panel(
    void * source_object,
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_secret_panel");
    #endif

    adm_object_existent_secret_panel(
        ent_secret_panel,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_secret_panel) {

        if (ent_secret_panel->rel_opened_by_unlocking_sequence_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Opened_by",
                "Unlocking_Sequence");
        }

        if (ent_secret_panel->rel_specialisation_room_device_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Specialisation",
                "Room_Device");
        }

        if (adm_entity_system.ent_secret_panel.live_list_head == ent_secret_panel) {

            adm_entity_system.ent_secret_panel.live_list_head = ent_secret_panel->next;

        } else {

            (ent_secret_panel->back)->next = ent_secret_panel->next;
        }

        if (adm_entity_system.ent_secret_panel.live_list_tail == ent_secret_panel) {

            adm_entity_system.ent_secret_panel.live_list_tail = ent_secret_panel->back;

        } else {

            (ent_secret_panel->next)->back = ent_secret_panel->back;
        }

        ent_secret_panel->deleted = TRUE;

        if (adm_entity_system.ent_secret_panel.dead_list_head == NULL) {

            ent_secret_panel->back = NULL;

            adm_entity_system.ent_secret_panel.dead_list_head = ent_secret_panel;

        } else {

            ent_secret_panel->back = adm_entity_system.ent_secret_panel.dead_list_tail;

            (adm_entity_system.ent_secret_panel.dead_list_tail)->next = ent_secret_panel;
        }

        ent_secret_panel->next = NULL;

        adm_entity_system.ent_secret_panel.dead_list_tail = ent_secret_panel;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_secret_panel->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_secret_panel");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_secret_panel_opened_by_unlocking_sequence(
    adm_ent_secret_panel_typ * ent_source_secret_panel,
    adm_ent_unlocking_sequence_typ * ent_target_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence;

    adm_base_boolean_typ unlocking_sequence_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_secret_panel_opened_by_unlocking_sequence");
    #endif

    adm_object_existent_secret_panel(
        ent_source_secret_panel,
        error_file,
        error_line,
        error_rank);

    unlocking_sequence_not_found = TRUE;

    rel_secret_panel_opened_by_unlocking_sequence = ent_source_secret_panel->rel_opened_by_unlocking_sequence_head;

    while (
        unlocking_sequence_not_found &&
        rel_secret_panel_opened_by_unlocking_sequence != NULL) {

        if (rel_secret_panel_opened_by_unlocking_sequence->ent_unlocking_sequence == ent_target_unlocking_sequence) {

            unlocking_sequence_not_found = FALSE;
        }

        rel_secret_panel_opened_by_unlocking_sequence = rel_secret_panel_opened_by_unlocking_sequence->next;
    }

    if (unlocking_sequence_not_found) {

        rel_secret_panel_opened_by_unlocking_sequence = (adm_rel_secret_panel_opened_by_unlocking_sequence_typ*)
            adm_allocate_memory(sizeof(adm_rel_secret_panel_opened_by_unlocking_sequence_typ));

        rel_secret_panel_opened_by_unlocking_sequence->ent_unlocking_sequence = ent_target_unlocking_sequence;

        if (ent_source_secret_panel->rel_opened_by_unlocking_sequence_head == NULL) {

            rel_secret_panel_opened_by_unlocking_sequence->back = NULL;

            ent_source_secret_panel->rel_opened_by_unlocking_sequence_head = rel_secret_panel_opened_by_unlocking_sequence;

        } else {

            rel_secret_panel_opened_by_unlocking_sequence->back = ent_source_secret_panel->rel_opened_by_unlocking_sequence_tail;

            (ent_source_secret_panel->rel_opened_by_unlocking_sequence_tail)->next = rel_secret_panel_opened_by_unlocking_sequence;
        }

        rel_secret_panel_opened_by_unlocking_sequence->next = NULL;

        ent_source_secret_panel->rel_opened_by_unlocking_sequence_tail = rel_secret_panel_opened_by_unlocking_sequence;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_source_secret_panel->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_secret_panel_opened_by_unlocking_sequence");
    #endif
}

void adm_link_relation_secret_panel_specialisation_room_device(
    adm_ent_secret_panel_typ * ent_source_secret_panel,
    adm_ent_room_device_typ * ent_target_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_secret_panel_specialisation_room_device_typ * rel_secret_panel_specialisation_room_device;

    adm_base_boolean_typ room_device_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_secret_panel_specialisation_room_device");
    #endif

    adm_object_existent_secret_panel(
        ent_source_secret_panel,
        error_file,
        error_line,
        error_rank);

    room_device_not_found = TRUE;

    rel_secret_panel_specialisation_room_device = ent_source_secret_panel->rel_specialisation_room_device_head;

    while (
        room_device_not_found &&
        rel_secret_panel_specialisation_room_device != NULL) {

        if (rel_secret_panel_specialisation_room_device->ent_room_device == ent_target_room_device) {

            room_device_not_found = FALSE;
        }

        rel_secret_panel_specialisation_room_device = rel_secret_panel_specialisation_room_device->next;
    }

    if (room_device_not_found) {

        rel_secret_panel_specialisation_room_device = (adm_rel_secret_panel_specialisation_room_device_typ*)
            adm_allocate_memory(sizeof(adm_rel_secret_panel_specialisation_room_device_typ));

        rel_secret_panel_specialisation_room_device->ent_room_device = ent_target_room_device;

        if (ent_source_secret_panel->rel_specialisation_room_device_head == NULL) {

            rel_secret_panel_specialisation_room_device->back = NULL;

            ent_source_secret_panel->rel_specialisation_room_device_head = rel_secret_panel_specialisation_room_device;

        } else {

            rel_secret_panel_specialisation_room_device->back = ent_source_secret_panel->rel_specialisation_room_device_tail;

            (ent_source_secret_panel->rel_specialisation_room_device_tail)->next = rel_secret_panel_specialisation_room_device;
        }

        rel_secret_panel_specialisation_room_device->next = NULL;

        ent_source_secret_panel->rel_specialisation_room_device_tail = rel_secret_panel_specialisation_room_device;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_source_secret_panel->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_secret_panel_specialisation_room_device");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_secret_panel_opened_by_unlocking_sequence(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_rel_secret_panel_opened_by_unlocking_sequence_typ * rel_secret_panel_opened_by_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_secret_panel_opened_by_unlocking_sequence");
    #endif

    adm_object_existent_secret_panel(
        ent_secret_panel,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_secret_panel_opened_by_unlocking_sequence->next !=
        (adm_base_integer_typ)rel_secret_panel_opened_by_unlocking_sequence->ent_unlocking_sequence) {

        if (ent_secret_panel->rel_opened_by_unlocking_sequence_head != NULL) {

            if (ent_secret_panel->rel_opened_by_unlocking_sequence_head == rel_secret_panel_opened_by_unlocking_sequence) {

                ent_secret_panel->rel_opened_by_unlocking_sequence_head = rel_secret_panel_opened_by_unlocking_sequence->next;

            } else {

                (rel_secret_panel_opened_by_unlocking_sequence->back)->next = rel_secret_panel_opened_by_unlocking_sequence->next;
            }

            if (ent_secret_panel->rel_opened_by_unlocking_sequence_tail == rel_secret_panel_opened_by_unlocking_sequence) {

                ent_secret_panel->rel_opened_by_unlocking_sequence_tail = rel_secret_panel_opened_by_unlocking_sequence->back;

            } else {

                (rel_secret_panel_opened_by_unlocking_sequence->next)->back = rel_secret_panel_opened_by_unlocking_sequence->back;
            }

            adm_deallocate_memory(rel_secret_panel_opened_by_unlocking_sequence);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Opened_by",
                "Unlocking_Sequence");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_secret_panel->identity,
            "Opened_by",
            "Unlocking_Sequence");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_secret_panel_opened_by_unlocking_sequence");
    #endif
}

void adm_kill_relation_secret_panel_specialisation_room_device(
    adm_ent_secret_panel_typ * ent_secret_panel,
    adm_rel_secret_panel_specialisation_room_device_typ * rel_secret_panel_specialisation_room_device,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_secret_panel_specialisation_room_device");
    #endif

    adm_object_existent_secret_panel(
        ent_secret_panel,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_secret_panel_specialisation_room_device->next !=
        (adm_base_integer_typ)rel_secret_panel_specialisation_room_device->ent_room_device) {

        if (ent_secret_panel->rel_specialisation_room_device_head != NULL) {

            if (ent_secret_panel->rel_specialisation_room_device_head == rel_secret_panel_specialisation_room_device) {

                ent_secret_panel->rel_specialisation_room_device_head = rel_secret_panel_specialisation_room_device->next;

            } else {

                (rel_secret_panel_specialisation_room_device->back)->next = rel_secret_panel_specialisation_room_device->next;
            }

            if (ent_secret_panel->rel_specialisation_room_device_tail == rel_secret_panel_specialisation_room_device) {

                ent_secret_panel->rel_specialisation_room_device_tail = rel_secret_panel_specialisation_room_device->back;

            } else {

                (rel_secret_panel_specialisation_room_device->next)->back = rel_secret_panel_specialisation_room_device->back;
            }

            adm_deallocate_memory(rel_secret_panel_specialisation_room_device);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Secret_Panel",
                ent_secret_panel->identity,
                "Specialisation",
                "Room_Device");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_secret_panel->identity,
            "Specialisation",
            "Room_Device");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_secret_panel_specialisation_room_device");
    #endif
}


/* Object Existent */

void adm_object_existent_secret_panel(
    const adm_ent_secret_panel_typ * const ent_secret_panel,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_secret_panel");
    #endif

    if (ent_secret_panel->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Secret_Panel",
            ent_secret_panel->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_secret_panel");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */