
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Sequence Event Senders */

void adm_send_event_unlocking_sequence_activate(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlocking_sequence_typ * pool_target;
    adm_pool_target_unlocking_sequence_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_activate");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlocking_sequence_activate(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlocking_sequence(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlocking_sequence_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlocking_sequence_typ));

        pool_target->evente = ADM_EVENT_UNLOCKING_SEQUENCE_ACTIVATE;
        pool_target->ent_unlocking_sequence = (adm_ent_unlocking_sequence_typ*)ent_unlocking_sequence;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlocking_sequence) {

            if (adm_entity_system.ent_unlocking_sequence.home_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlocking_sequence.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlocking_sequence == ent_unlocking_sequence) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlocking_Sequence",
                            ent_unlocking_sequence->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlocking_sequence.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlocking_sequence.away_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlocking_sequence.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_activate");
    #endif
}

void adm_send_event_unlocking_sequence_reset(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlocking_sequence_typ * pool_target;
    adm_pool_target_unlocking_sequence_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_reset");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlocking_sequence_reset(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlocking_sequence(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlocking_sequence_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlocking_sequence_typ));

        pool_target->evente = ADM_EVENT_UNLOCKING_SEQUENCE_RESET;
        pool_target->ent_unlocking_sequence = (adm_ent_unlocking_sequence_typ*)ent_unlocking_sequence;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlocking_sequence) {

            if (adm_entity_system.ent_unlocking_sequence.home_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlocking_sequence.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlocking_sequence == ent_unlocking_sequence) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlocking_Sequence",
                            ent_unlocking_sequence->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlocking_sequence.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlocking_sequence.away_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlocking_sequence.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_reset");
    #endif
}

void adm_send_event_unlocking_sequence_complete(
    const void * const source_object,
    const adm_ent_unlocking_sequence_typ * const ent_unlocking_sequence,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlocking_sequence_typ * pool_target;
    adm_pool_target_unlocking_sequence_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_complete");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlocking_sequence_complete(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlocking_sequence(
            ent_unlocking_sequence,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlocking_sequence_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlocking_sequence_typ));

        pool_target->evente = ADM_EVENT_UNLOCKING_SEQUENCE_COMPLETE;
        pool_target->ent_unlocking_sequence = (adm_ent_unlocking_sequence_typ*)ent_unlocking_sequence;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlocking_sequence) {

            if (adm_entity_system.ent_unlocking_sequence.home_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlocking_sequence.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlocking_sequence == ent_unlocking_sequence) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlocking_Sequence",
                            ent_unlocking_sequence->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlocking_sequence.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlocking_sequence.away_pool_head == NULL) {

                adm_entity_system.ent_unlocking_sequence.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlocking_sequence.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlocking_sequence.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlocking_sequence_complete");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */