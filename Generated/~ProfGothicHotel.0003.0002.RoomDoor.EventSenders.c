
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Room Door Event Senders */

void adm_send_event_room_door_door_closed(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_room_door_typ * pool_target;
    adm_pool_target_room_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_door_closed");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_room_door_door_closed(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_room_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_room_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_room_door_typ));

        pool_target->evente = ADM_EVENT_ROOM_DOOR_DOOR_CLOSED;
        pool_target->ent_room_door = (adm_ent_room_door_typ*)ent_room_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_room_door) {

            if (adm_entity_system.ent_room_door.home_pool_head == NULL) {

                adm_entity_system.ent_room_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_room_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_room_door == ent_room_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Room_Door",
                            ent_room_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_room_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_room_door.away_pool_head == NULL) {

                adm_entity_system.ent_room_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_room_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_door_closed");
    #endif
}

void adm_send_event_room_door_door_opened(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_room_door_typ * pool_target;
    adm_pool_target_room_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_door_opened");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_room_door_door_opened(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_room_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_room_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_room_door_typ));

        pool_target->evente = ADM_EVENT_ROOM_DOOR_DOOR_OPENED;
        pool_target->ent_room_door = (adm_ent_room_door_typ*)ent_room_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_room_door) {

            if (adm_entity_system.ent_room_door.home_pool_head == NULL) {

                adm_entity_system.ent_room_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_room_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_room_door == ent_room_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Room_Door",
                            ent_room_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_room_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_room_door.away_pool_head == NULL) {

                adm_entity_system.ent_room_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_room_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_door_opened");
    #endif
}

void adm_send_event_room_door_lock_door(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_room_door_typ * pool_target;
    adm_pool_target_room_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_lock_door");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_room_door_lock_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_room_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_room_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_room_door_typ));

        pool_target->evente = ADM_EVENT_ROOM_DOOR_LOCK_DOOR;
        pool_target->ent_room_door = (adm_ent_room_door_typ*)ent_room_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_room_door) {

            if (adm_entity_system.ent_room_door.home_pool_head == NULL) {

                adm_entity_system.ent_room_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_room_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_room_door == ent_room_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Room_Door",
                            ent_room_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_room_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_room_door.away_pool_head == NULL) {

                adm_entity_system.ent_room_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_room_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_lock_door");
    #endif
}

void adm_send_event_room_door_unlock_door(
    const void * const source_object,
    const adm_ent_room_door_typ * const ent_room_door,
    const adm_err_file_typ error_file,
    const adm_err_line_typ error_line,
    const adm_err_rank_typ error_rank)
{
    adm_pool_target_room_door_typ * pool_target;
    adm_pool_target_room_door_typ * home_pool_target;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_unlock_door");
    #endif

    if (adm_sim_err_success) {

        adm_sim_display_event_room_door_unlock_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        adm_object_existent_room_door(
            ent_room_door,
            error_file,
            error_line,
            error_rank);

        pool_target = (adm_pool_target_room_door_typ*)
            adm_allocate_memory(sizeof(adm_pool_target_room_door_typ));

        pool_target->evente = ADM_EVENT_ROOM_DOOR_UNLOCK_DOOR;
        pool_target->ent_room_door = (adm_ent_room_door_typ*)ent_room_door;
        pool_target->error_location.file = error_file;
        pool_target->error_location.line = error_line;
        pool_target->error_location.rank = error_rank;
        pool_target->next = NULL;

        if (source_object == ent_room_door) {

            if (adm_entity_system.ent_room_door.home_pool_head == NULL) {

                adm_entity_system.ent_room_door.home_pool_head = pool_target;

            } else {

                home_pool_target = adm_entity_system.ent_room_door.home_pool_head;

                while (home_pool_target != NULL) {

                    if (home_pool_target->ent_room_door == ent_room_door) {

                        adm_error_report(
                            ADM_ERROR_ONLY_ONE_SELF_DIRECTED_EVENT_ALLOWED,
                            error_file, error_line, error_rank,
                            "Room_Door",
                            ent_room_door->identity,
                            NULL, NULL);
                    }

                    home_pool_target = home_pool_target->next;
                }

                (adm_entity_system.ent_room_door.home_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.home_pool_tail = pool_target;

        } else {

            if (adm_entity_system.ent_room_door.away_pool_head == NULL) {

                adm_entity_system.ent_room_door.away_pool_head = pool_target;

            } else {

                (adm_entity_system.ent_room_door.away_pool_tail)->next = pool_target;
            }

            adm_entity_system.ent_room_door.away_pool_tail = pool_target;
        }
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_EVENT_SENDER, "adm_send_event_room_door_unlock_door");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */