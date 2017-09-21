
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlock Step Data Access */

/* Make Entity Object */

adm_ent_unlock_step_typ * adm_make_object_unlock_step(
    adm_sta_unlock_step_typ status)
{
    adm_ent_unlock_step_typ * ent_unlock_step;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_unlock_step");
    #endif

    if (adm_entity_system.ent_unlock_step.dead_list_head != NULL) {

        ent_unlock_step = adm_entity_system.ent_unlock_step.dead_list_head;

        if (adm_entity_system.ent_unlock_step.dead_list_head == ent_unlock_step) {

            adm_entity_system.ent_unlock_step.dead_list_head = ent_unlock_step->next;

        } else {

            (ent_unlock_step->back)->next = ent_unlock_step->next;
        }

        if (adm_entity_system.ent_unlock_step.dead_list_tail == ent_unlock_step) {

            adm_entity_system.ent_unlock_step.dead_list_tail = ent_unlock_step->back;

        } else {

            (ent_unlock_step->next)->back = ent_unlock_step->back;
        }

    } else {

        ent_unlock_step = (adm_ent_unlock_step_typ*)adm_allocate_memory(sizeof(adm_ent_unlock_step_typ));
    }

    ent_unlock_step->identity = ++adm_entity_system.ent_unlock_step.tote;

    ent_unlock_step->unique  = FALSE;
    ent_unlock_step->deleted = FALSE;
    ent_unlock_step->marked  = FALSE;
    ent_unlock_step->status  = status;

    ent_unlock_step->rel_followed_by_unlock_step_head = NULL;
    ent_unlock_step->rel_followed_by_unlock_step_tail = NULL;

    ent_unlock_step->rel_part_of_unlocking_sequence_head = NULL;
    ent_unlock_step->rel_part_of_unlocking_sequence_tail = NULL;

    ent_unlock_step->back = NULL;
    ent_unlock_step->next = NULL;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_make_object_unlock_step");
    #endif

    return (ent_unlock_step);
}


/* Bind Entity Object */

void adm_bind_object_unlock_step(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_unlock_step");
    #endif

    adm_object_existent_unlock_step(
        ent_unlock_step,
        error_file,
        error_line,
        error_rank);

    if (adm_entity_system.ent_unlock_step.live_list_head == NULL) {

        ent_unlock_step->back = NULL;

        adm_entity_system.ent_unlock_step.live_list_head = ent_unlock_step;

    } else {

        ent_unlock_step->back = adm_entity_system.ent_unlock_step.live_list_tail;

        (adm_entity_system.ent_unlock_step.live_list_tail)->next = ent_unlock_step;
    }

    ent_unlock_step->next = NULL;

    adm_entity_system.ent_unlock_step.live_list_tail = ent_unlock_step;

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_bind_object_unlock_step");
    #endif
}


/* Kill Entity Object */

void adm_kill_object_unlock_step(
    void * source_object,
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_unlock_step");
    #endif

    adm_object_existent_unlock_step(
        ent_unlock_step,
        error_file,
        error_line,
        error_rank);

    if (source_object != ent_unlock_step) {

        if (ent_unlock_step->rel_followed_by_unlock_step_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Followed_by",
                "Unlock_Step");
        }

        if (ent_unlock_step->rel_part_of_unlocking_sequence_head != NULL) {

            adm_error_report(
                ADM_ERROR_OBJECT_HAS_EXISTING_RELATION,
                error_file, error_line, error_rank,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Part_of",
                "Unlocking_Sequence");
        }

        if (adm_entity_system.ent_unlock_step.live_list_head == ent_unlock_step) {

            adm_entity_system.ent_unlock_step.live_list_head = ent_unlock_step->next;

        } else {

            (ent_unlock_step->back)->next = ent_unlock_step->next;
        }

        if (adm_entity_system.ent_unlock_step.live_list_tail == ent_unlock_step) {

            adm_entity_system.ent_unlock_step.live_list_tail = ent_unlock_step->back;

        } else {

            (ent_unlock_step->next)->back = ent_unlock_step->back;
        }

        ent_unlock_step->deleted = TRUE;

        if (adm_entity_system.ent_unlock_step.dead_list_head == NULL) {

            ent_unlock_step->back = NULL;

            adm_entity_system.ent_unlock_step.dead_list_head = ent_unlock_step;

        } else {

            ent_unlock_step->back = adm_entity_system.ent_unlock_step.dead_list_tail;

            (adm_entity_system.ent_unlock_step.dead_list_tail)->next = ent_unlock_step;
        }

        ent_unlock_step->next = NULL;

        adm_entity_system.ent_unlock_step.dead_list_tail = ent_unlock_step;

    } else {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_DELETE_CURRENT_OBJECT,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_unlock_step->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_object_unlock_step");
    #endif
}


/* Link Entity Relations */

void adm_link_relation_unlock_step_followed_by_unlock_step(
    adm_ent_unlock_step_typ * ent_source_unlock_step,
    adm_ent_unlock_step_typ * ent_target_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step;

    adm_base_boolean_typ unlock_step_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlock_step_followed_by_unlock_step");
    #endif

    adm_object_existent_unlock_step(
        ent_source_unlock_step,
        error_file,
        error_line,
        error_rank);

    unlock_step_not_found = TRUE;

    rel_unlock_step_followed_by_unlock_step = ent_source_unlock_step->rel_followed_by_unlock_step_head;

    while (
        unlock_step_not_found &&
        rel_unlock_step_followed_by_unlock_step != NULL) {

        if (rel_unlock_step_followed_by_unlock_step->ent_unlock_step == ent_target_unlock_step) {

            unlock_step_not_found = FALSE;
        }

        rel_unlock_step_followed_by_unlock_step = rel_unlock_step_followed_by_unlock_step->next;
    }

    if (unlock_step_not_found) {

        rel_unlock_step_followed_by_unlock_step = (adm_rel_unlock_step_followed_by_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_rel_unlock_step_followed_by_unlock_step_typ));

        rel_unlock_step_followed_by_unlock_step->ent_unlock_step = ent_target_unlock_step;

        if (ent_source_unlock_step->rel_followed_by_unlock_step_head == NULL) {

            rel_unlock_step_followed_by_unlock_step->back = NULL;

            ent_source_unlock_step->rel_followed_by_unlock_step_head = rel_unlock_step_followed_by_unlock_step;

        } else {

            rel_unlock_step_followed_by_unlock_step->back = ent_source_unlock_step->rel_followed_by_unlock_step_tail;

            (ent_source_unlock_step->rel_followed_by_unlock_step_tail)->next = rel_unlock_step_followed_by_unlock_step;
        }

        rel_unlock_step_followed_by_unlock_step->next = NULL;

        ent_source_unlock_step->rel_followed_by_unlock_step_tail = rel_unlock_step_followed_by_unlock_step;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_source_unlock_step->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlock_step_followed_by_unlock_step");
    #endif
}

void adm_link_relation_unlock_step_part_of_unlocking_sequence(
    adm_ent_unlock_step_typ * ent_source_unlock_step,
    adm_ent_unlocking_sequence_typ * ent_target_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    adm_rel_unlock_step_part_of_unlocking_sequence_typ * rel_unlock_step_part_of_unlocking_sequence;

    adm_base_boolean_typ unlocking_sequence_not_found;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlock_step_part_of_unlocking_sequence");
    #endif

    adm_object_existent_unlock_step(
        ent_source_unlock_step,
        error_file,
        error_line,
        error_rank);

    unlocking_sequence_not_found = TRUE;

    rel_unlock_step_part_of_unlocking_sequence = ent_source_unlock_step->rel_part_of_unlocking_sequence_head;

    while (
        unlocking_sequence_not_found &&
        rel_unlock_step_part_of_unlocking_sequence != NULL) {

        if (rel_unlock_step_part_of_unlocking_sequence->ent_unlocking_sequence == ent_target_unlocking_sequence) {

            unlocking_sequence_not_found = FALSE;
        }

        rel_unlock_step_part_of_unlocking_sequence = rel_unlock_step_part_of_unlocking_sequence->next;
    }

    if (unlocking_sequence_not_found) {

        rel_unlock_step_part_of_unlocking_sequence = (adm_rel_unlock_step_part_of_unlocking_sequence_typ*)
            adm_allocate_memory(sizeof(adm_rel_unlock_step_part_of_unlocking_sequence_typ));

        rel_unlock_step_part_of_unlocking_sequence->ent_unlocking_sequence = ent_target_unlocking_sequence;

        if (ent_source_unlock_step->rel_part_of_unlocking_sequence_head == NULL) {

            rel_unlock_step_part_of_unlocking_sequence->back = NULL;

            ent_source_unlock_step->rel_part_of_unlocking_sequence_head = rel_unlock_step_part_of_unlocking_sequence;

        } else {

            rel_unlock_step_part_of_unlocking_sequence->back = ent_source_unlock_step->rel_part_of_unlocking_sequence_tail;

            (ent_source_unlock_step->rel_part_of_unlocking_sequence_tail)->next = rel_unlock_step_part_of_unlocking_sequence;
        }

        rel_unlock_step_part_of_unlocking_sequence->next = NULL;

        ent_source_unlock_step->rel_part_of_unlocking_sequence_tail = rel_unlock_step_part_of_unlocking_sequence;

    } else {

        adm_error_report(
            ADM_ERROR_OBJECTS_ALREADY_RELATED,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_source_unlock_step->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_link_relation_unlock_step_part_of_unlocking_sequence");
    #endif
}


/* Kill Entity Relations */

void adm_kill_relation_unlock_step_followed_by_unlock_step(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_rel_unlock_step_followed_by_unlock_step_typ * rel_unlock_step_followed_by_unlock_step,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlock_step_followed_by_unlock_step");
    #endif

    adm_object_existent_unlock_step(
        ent_unlock_step,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_unlock_step_followed_by_unlock_step->next !=
        (adm_base_integer_typ)rel_unlock_step_followed_by_unlock_step->ent_unlock_step) {

        if (ent_unlock_step->rel_followed_by_unlock_step_head != NULL) {

            if (ent_unlock_step->rel_followed_by_unlock_step_head == rel_unlock_step_followed_by_unlock_step) {

                ent_unlock_step->rel_followed_by_unlock_step_head = rel_unlock_step_followed_by_unlock_step->next;

            } else {

                (rel_unlock_step_followed_by_unlock_step->back)->next = rel_unlock_step_followed_by_unlock_step->next;
            }

            if (ent_unlock_step->rel_followed_by_unlock_step_tail == rel_unlock_step_followed_by_unlock_step) {

                ent_unlock_step->rel_followed_by_unlock_step_tail = rel_unlock_step_followed_by_unlock_step->back;

            } else {

                (rel_unlock_step_followed_by_unlock_step->next)->back = rel_unlock_step_followed_by_unlock_step->back;
            }

            adm_deallocate_memory(rel_unlock_step_followed_by_unlock_step);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Followed_by",
                "Unlock_Step");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_unlock_step->identity,
            "Followed_by",
            "Unlock_Step");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlock_step_followed_by_unlock_step");
    #endif
}

void adm_kill_relation_unlock_step_part_of_unlocking_sequence(
    adm_ent_unlock_step_typ * ent_unlock_step,
    adm_rel_unlock_step_part_of_unlocking_sequence_typ * rel_unlock_step_part_of_unlocking_sequence,
    adm_err_file_typ error_file,
    adm_err_line_typ error_line,
    adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlock_step_part_of_unlocking_sequence");
    #endif

    adm_object_existent_unlock_step(
        ent_unlock_step,
        error_file,
        error_line,
        error_rank);

    if (
        (adm_base_integer_typ)rel_unlock_step_part_of_unlocking_sequence->next !=
        (adm_base_integer_typ)rel_unlock_step_part_of_unlocking_sequence->ent_unlocking_sequence) {

        if (ent_unlock_step->rel_part_of_unlocking_sequence_head != NULL) {

            if (ent_unlock_step->rel_part_of_unlocking_sequence_head == rel_unlock_step_part_of_unlocking_sequence) {

                ent_unlock_step->rel_part_of_unlocking_sequence_head = rel_unlock_step_part_of_unlocking_sequence->next;

            } else {

                (rel_unlock_step_part_of_unlocking_sequence->back)->next = rel_unlock_step_part_of_unlocking_sequence->next;
            }

            if (ent_unlock_step->rel_part_of_unlocking_sequence_tail == rel_unlock_step_part_of_unlocking_sequence) {

                ent_unlock_step->rel_part_of_unlocking_sequence_tail = rel_unlock_step_part_of_unlocking_sequence->back;

            } else {

                (rel_unlock_step_part_of_unlocking_sequence->next)->back = rel_unlock_step_part_of_unlocking_sequence->back;
            }

            adm_deallocate_memory(rel_unlock_step_part_of_unlocking_sequence);

        } else {

            adm_error_report(
                ADM_ERROR_NO_RELATIONS_EXIST,
                error_file, error_line, error_rank,
                "Unlock_Step",
                ent_unlock_step->identity,
                "Part_of",
                "Unlocking_Sequence");
        }

    } else {

        adm_error_report(
            ADM_ERROR_RELATIONSHIP_ALREADY_UNRELATED,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_unlock_step->identity,
            "Part_of",
            "Unlocking_Sequence");
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_kill_relation_unlock_step_part_of_unlocking_sequence");
    #endif
}


/* Object Existent */

void adm_object_existent_unlock_step(
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_unlock_step");
    #endif

    if (ent_unlock_step->deleted) {

        adm_error_report(
            ADM_ERROR_ATTEMPT_TO_USE_DELETED_OBJECT,
            error_file, error_line, error_rank,
            "Unlock_Step",
            ent_unlock_step->identity,
            NULL, NULL);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DATA_ACCESS, "adm_object_existent_unlock_step");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */