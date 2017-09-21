
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlock Step Event Senders */

void adm_send_event_unlock_step_reset(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlock_step_typ * pool_target;
    adm_pool_target_unlock_step_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_reset");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlock_step_reset(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlock_step(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlock_step_typ));

        pool_target->evente = ADM_EVENT_UNLOCK_STEP_RESET;
        pool_target->ent_unlock_step = (adm_ent_unlock_step_typ*)ent_unlock_step;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlock_step) {

            if (adm_entity_system.ent_unlock_step.home_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlock_step.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlock_step == ent_unlock_step) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlock_Step",
                            ent_unlock_step->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlock_step.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlock_step.away_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlock_step.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_reset");
    #endif
}

void adm_send_event_unlock_step_advance(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlock_step_typ * pool_target;
    adm_pool_target_unlock_step_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_advance");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlock_step_advance(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlock_step(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlock_step_typ));

        pool_target->evente = ADM_EVENT_UNLOCK_STEP_ADVANCE;
        pool_target->ent_unlock_step = (adm_ent_unlock_step_typ*)ent_unlock_step;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlock_step) {

            if (adm_entity_system.ent_unlock_step.home_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlock_step.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlock_step == ent_unlock_step) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlock_Step",
                            ent_unlock_step->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlock_step.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlock_step.away_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlock_step.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_advance");
    #endif
}

void adm_send_event_unlock_step_select(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlock_step_typ * pool_target;
    adm_pool_target_unlock_step_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_select");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlock_step_select(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlock_step(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlock_step_typ));

        pool_target->evente = ADM_EVENT_UNLOCK_STEP_SELECT;
        pool_target->ent_unlock_step = (adm_ent_unlock_step_typ*)ent_unlock_step;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlock_step) {

            if (adm_entity_system.ent_unlock_step.home_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlock_step.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlock_step == ent_unlock_step) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlock_Step",
                            ent_unlock_step->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlock_step.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlock_step.away_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlock_step.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_select");
    #endif
}

void adm_send_event_unlock_step_prime(
    const void * const source_object,
    const adm_ent_unlock_step_typ * const ent_unlock_step,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_unlock_step_typ * pool_target;
    adm_pool_target_unlock_step_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_prime");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_unlock_step_prime(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_unlock_step(
            ent_unlock_step,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_unlock_step_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_unlock_step_typ));

        pool_target->evente = ADM_EVENT_UNLOCK_STEP_PRIME;
        pool_target->ent_unlock_step = (adm_ent_unlock_step_typ*)ent_unlock_step;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_unlock_step) {

            if (adm_entity_system.ent_unlock_step.home_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_unlock_step.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_unlock_step == ent_unlock_step) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Unlock_Step",
                            ent_unlock_step->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_unlock_step.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_unlock_step.away_pool_head == NULL) {

                adm_entity_system.ent_unlock_step.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_unlock_step.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_unlock_step.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_unlock_step_prime");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */