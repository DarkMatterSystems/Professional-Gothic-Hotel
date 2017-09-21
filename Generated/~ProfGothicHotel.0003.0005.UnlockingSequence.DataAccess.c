
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence Data Access */

/* Make Entity Object */

adm_ent_unlocking_sequence_typ * adm_make_object_unlocking_sequence(
    adm_sta_unlocking_sequence_typ status)
{
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_unlocking_sequence");
    #endif

    if (adm_entity_system.ent_unlocking_sequence.dead_list_head != NULL) {

        ent_unlocking_sequence = adm_entity_system.ent_unlocking_sequence.dead_list_head;

        if (adm_entity_system.ent_unlocking_sequence.dead_list_head == ent_unlocking_sequence) {

            adm_entity_system.ent_unlocking_sequence.dead_list_head = ent_unlocking_sequence->next;

        } else {

            (ent_unlocking_sequence->back)->next = ent_unlocking_sequence->next;
        }

        if (adm_entity_system.ent_unlocking_sequence.dead_list_tail == ent_unlocking_sequence) {

            adm_entity_system.ent_unlocking_sequence.dead_list_tail = ent_unlocking_sequence->back;

        } else {

            (ent_unlocking_sequence->next)->back = ent_unlocking_sequence->back;
        }

    } else {

        ent_unlocking_sequence = (adm_ent_unlocking_sequence_typ*)adm_allocate_memory(sizeof(adm_ent_unlocking_sequence_typ));
    }

    ent_unlocking_sequence->identity = ++adm_entity_system.ent_unlocking_sequence.tote;

    ent_unlocking_sequence->unique  = FALSE;
    ent_unlocking_sequence->deleted = FALSE;
    ent_unlocking_sequence->marked  = FALSE;
    ent_unlocking_sequence->status  = status;

    ent_unlocking_sequence->rel_opens_secret_panel_head = NULL;
    ent_unlocking_sequence->rel_opens_secret_panel_tail = NULL;

    ent_unlocking_sequence->rel_starts_at_unlock_step_head = NULL;
    ent_unlocking_sequence->rel_starts_at_unlock_step_tail = NULL;

    ent_unlocking_sequence->back = NULL;
    ent_unlocking_sequence->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_unlocking_sequence");
    #endif

    return (ent_unlocking_sequence);
}


/* Bind Entity Object */

void adm_bind_object_unlocking_sequence(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_unlocking_sequence");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_unlocking_sequence.live_list_head == NULL) {

        ent_unlocking_sequence->back = NULL;

        adm_entity_system.ent_unlocking_sequence.live_list_head = ent_unlocking_sequence;

    } else {

        ent_unlocking_sequence->back = adm_entity_system.ent_unlocking_sequence.live_list_tail;

        (adm_entity_system.ent_unlocking_sequence.live_list_tail)->next = ent_unlocking_sequence;
    }

    ent_unlocking_sequence->next = NULL;

    adm_entity_system.ent_unlocking_sequence.live_list_tail = ent_unlocking_sequence;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_unlocking_sequence");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_unlocking_sequence(
    void * source_object,
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_unlocking_sequence");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_unlocking_sequence) {

        if (ent_unlocking_sequence->rel_opens_secret_panel_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Opens",
                "Secret_Panel");
        }

        if (ent_unlocking_sequence->rel_starts_at_unlock_step_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Starts_at",
                "Unlock_Step");
        }

        if (adm_entity_system.ent_unlocking_sequence.live_list_head == ent_unlocking_sequence) {

            adm_entity_system.ent_unlocking_sequence.live_list_head = ent_unlocking_sequence->next;

        } else {

            (ent_unlocking_sequence->back)->next = ent_unlocking_sequence->next;
        }

        if (adm_entity_system.ent_unlocking_sequence.live_list_tail == ent_unlocking_sequence) {

            adm_entity_system.ent_unlocking_sequence.live_list_tail = ent_unlocking_sequence->back;

        } else {

            (ent_unlocking_sequence->next)->back = ent_unlocking_sequence->back;
        }

        ent_unlocking_sequence->deleted = TRUE;

        if (adm_entity_system.ent_unlocking_sequence.dead_list_head == NULL) {

            ent_unlocking_sequence->back = NULL;

            adm_entity_system.ent_unlocking_sequence.dead_list_head = ent_unlocking_sequence;

        } else {

            ent_unlocking_sequence->back = adm_entity_system.ent_unlocking_sequence.dead_list_tail;

            (adm_entity_system.ent_unlocking_sequence.dead_list_tail)->next = ent_unlocking_sequence;
        }

        ent_unlocking_sequence->next = NULL;

        adm_entity_system.ent_unlocking_sequence.dead_list_tail = ent_unlocking_sequence;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_unlocking_sequence");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_unlocking_sequence_opens_secret_panel(
    adm_ent_unlocking_sequence_typ * ent_source_unlocking_sequence,
    adm_ent_secret_panel_typ * ent_target_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_unlocking_sequence_opens_secret_panel_typ * rel_unlocking_sequence_opens_secret_panel;

    adm_base_boolean_typ secret_panel_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlocking_sequence_opens_secret_panel");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_source_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    secret_panel_not_found = TRUE;

    rel_unlocking_sequence_opens_secret_panel = ent_source_unlocking_sequence->rel_opens_secret_panel_head;

    while (
        secret_panel_not_found &&
        rel_unlocking_sequence_opens_secret_panel != NULL) {

        if (rel_unlocking_sequence_opens_secret_panel->ent_secret_panel == ent_target_secret_panel) {

            secret_panel_not_found = FALSE;
        }

        rel_unlocking_sequence_opens_secret_panel = rel_unlocking_sequence_opens_secret_panel->next;
    }

    if (secret_panel_not_found) {

        rel_unlocking_sequence_opens_secret_panel = (adm_rel_unlocking_sequence_opens_secret_panel_typ*)
            adm_allocate_memory(sizeof(adm_rel_unlocking_sequence_opens_secret_panel_typ));

        rel_unlocking_sequence_opens_secret_panel->ent_secret_panel = ent_target_secret_panel;

        if (ent_source_unlocking_sequence->rel_opens_secret_panel_head == NULL) {

            rel_unlocking_sequence_opens_secret_panel->back = NULL;

            ent_source_unlocking_sequence->rel_opens_secret_panel_head = rel_unlocking_sequence_opens_secret_panel;

        } else {

            rel_unlocking_sequence_opens_secret_panel->back = ent_source_unlocking_sequence->rel_opens_secret_panel_tail;

            (ent_source_unlocking_sequence->rel_opens_secret_panel_tail)->next = rel_unlocking_sequence_opens_secret_panel;
        }

        rel_unlocking_sequence_opens_secret_panel->next = NULL;

        ent_source_unlocking_sequence->rel_opens_secret_panel_tail = rel_unlocking_sequence_opens_secret_panel;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_source_unlocking_sequence->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlocking_sequence_opens_secret_panel");
    #endif
}

void adm_link_relation_unlocking_sequence_starts_at_unlock_step(
    adm_ent_unlocking_sequence_typ * ent_source_unlocking_sequence,
    adm_ent_unlock_step_typ * ent_target_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step;

    adm_base_boolean_typ unlock_step_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlocking_sequence_starts_at_unlock_step");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_source_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    unlock_step_not_found = TRUE;

    rel_unlocking_sequence_starts_at_unlock_step = ent_source_unlocking_sequence->rel_starts_at_unlock_step_head;

    while (
        unlock_step_not_found &&
        rel_unlocking_sequence_starts_at_unlock_step != NULL) {

        if (rel_unlocking_sequence_starts_at_unlock_step->ent_unlock_step == ent_target_unlock_step) {

            unlock_step_not_found = FALSE;
        }

        rel_unlocking_sequence_starts_at_unlock_step = rel_unlocking_sequence_starts_at_unlock_step->next;
    }

    if (unlock_step_not_found) {

        rel_unlocking_sequence_starts_at_unlock_step = (adm_rel_unlocking_sequence_starts_at_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_rel_unlocking_sequence_starts_at_unlock_step_typ));

        rel_unlocking_sequence_starts_at_unlock_step->ent_unlock_step = ent_target_unlock_step;

        if (ent_source_unlocking_sequence->rel_starts_at_unlock_step_head == NULL) {

            rel_unlocking_sequence_starts_at_unlock_step->back = NULL;

            ent_source_unlocking_sequence->rel_starts_at_unlock_step_head = rel_unlocking_sequence_starts_at_unlock_step;

        } else {

            rel_unlocking_sequence_starts_at_unlock_step->back = ent_source_unlocking_sequence->rel_starts_at_unlock_step_tail;

            (ent_source_unlocking_sequence->rel_starts_at_unlock_step_tail)->next = rel_unlocking_sequence_starts_at_unlock_step;
        }

        rel_unlocking_sequence_starts_at_unlock_step->next = NULL;

        ent_source_unlocking_sequence->rel_starts_at_unlock_step_tail = rel_unlocking_sequence_starts_at_unlock_step;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_source_unlocking_sequence->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlocking_sequence_starts_at_unlock_step");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_unlocking_sequence_opens_secret_panel(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_rel_unlocking_sequence_opens_secret_panel_typ * rel_unlocking_sequence_opens_secret_panel,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlocking_sequence_opens_secret_panel");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_unlocking_sequence_opens_secret_panel->next !=
        (adm_base_integer_typ)rel_unlocking_sequence_opens_secret_panel->ent_secret_panel) {

        if (ent_unlocking_sequence->rel_opens_secret_panel_head != NULL) {

            if (ent_unlocking_sequence->rel_opens_secret_panel_head == rel_unlocking_sequence_opens_secret_panel) {

                ent_unlocking_sequence->rel_opens_secret_panel_head = rel_unlocking_sequence_opens_secret_panel->next;

            } else {

                (rel_unlocking_sequence_opens_secret_panel->back)->next = rel_unlocking_sequence_opens_secret_panel->next;
            }

            if (ent_unlocking_sequence->rel_opens_secret_panel_tail == rel_unlocking_sequence_opens_secret_panel) {

                ent_unlocking_sequence->rel_opens_secret_panel_tail = rel_unlocking_sequence_opens_secret_panel->back;

            } else {

                (rel_unlocking_sequence_opens_secret_panel->next)->back = rel_unlocking_sequence_opens_secret_panel->back;
            }

            adm_deallocate_memory(rel_unlocking_sequence_opens_secret_panel);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Opens",
                "Secret_Panel");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Opens",
            "Secret_Panel");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlocking_sequence_opens_secret_panel");
    #endif
}

void adm_kill_relation_unlocking_sequence_starts_at_unlock_step(
    adm_ent_unlocking_sequence_typ * ent_unlocking_sequence,
    adm_rel_unlocking_sequence_starts_at_unlock_step_typ * rel_unlocking_sequence_starts_at_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlocking_sequence_starts_at_unlock_step");
    #endif

    adm_object_existent_unlocking_sequence(
        ent_unlocking_sequence,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_unlocking_sequence_starts_at_unlock_step->next !=
        (adm_base_integer_typ)rel_unlocking_sequence_starts_at_unlock_step->ent_unlock_step) {

        if (ent_unlocking_sequence->rel_starts_at_unlock_step_head != NULL) {

            if (ent_unlocking_sequence->rel_starts_at_unlock_step_head == rel_unlocking_sequence_starts_at_unlock_step) {

                ent_unlocking_sequence->rel_starts_at_unlock_step_head = rel_unlocking_sequence_starts_at_unlock_step->next;

            } else {

                (rel_unlocking_sequence_starts_at_unlock_step->back)->next = rel_unlocking_sequence_starts_at_unlock_step->next;
            }

            if (ent_unlocking_sequence->rel_starts_at_unlock_step_tail == rel_unlocking_sequence_starts_at_unlock_step) {

                ent_unlocking_sequence->rel_starts_at_unlock_step_tail = rel_unlocking_sequence_starts_at_unlock_step->back;

            } else {

                (rel_unlocking_sequence_starts_at_unlock_step->next)->back = rel_unlocking_sequence_starts_at_unlock_step->back;
            }

            adm_deallocate_memory(rel_unlocking_sequence_starts_at_unlock_step);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Unlocking_Sequence",
                ent_unlocking_sequence->identity,
                "Starts_at",
                "Unlock_Step");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            "Starts_at",
            "Unlock_Step");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlocking_sequence_starts_at_unlock_step");
    #endif
}


/* Object Existent */

void adm_object_existent_unlocking_sequence(
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_unlocking_sequence");
    #endif

    if (ent_unlocking_sequence->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Unlocking_Sequence",
            ent_unlocking_sequence->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_unlocking_sequence");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */