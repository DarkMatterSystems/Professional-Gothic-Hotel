
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Unlocking Device Dispatcher */

/* Dispatcher */

void adm_dispatcher_unlocking_device(
    void)
{
    adm_pool_target_unlocking_device_typ * pool_target_unlocking_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlocking_device");
    #endif

    pool_target_unlocking_device = adm_find_away_target_event_unlocking_device();

    adm_dispatch_state_action_unlocking_device(pool_target_unlocking_device);

    adm_dispatch_home_pool_unlocking_device();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatcher_unlocking_device");
    #endif
}


/* Dispatch Home Pool */

void adm_dispatch_home_pool_unlocking_device(
    void)
{
    adm_pool_target_unlocking_device_typ * pool_target_unlocking_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlocking_device");
    #endif

    while (adm_entity_system.ent_unlocking_device.home_pool_head != NULL) {

        pool_target_unlocking_device = adm_find_home_target_event_unlocking_device();

        adm_dispatch_state_action_unlocking_device(pool_target_unlocking_device);
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_home_pool_unlocking_device");
    #endif
}


/* Find Home Target Event */

adm_pool_target_unlocking_device_typ * adm_find_home_target_event_unlocking_device(
    void)
{
    adm_pool_target_unlocking_device_typ * pool_target_unlocking_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlocking_device");
    #endif

    pool_target_unlocking_device = adm_entity_system.ent_unlocking_device.home_pool_head;

    adm_entity_system.ent_unlocking_device.home_pool_head = pool_target_unlocking_device->next;

    if (adm_entity_system.ent_unlocking_device.home_pool_head == NULL) {

        adm_entity_system.ent_unlocking_device.home_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_home_target_event_unlocking_device");
    #endif

    return (pool_target_unlocking_device);
}


/* Find Away Target Event */

adm_pool_target_unlocking_device_typ * adm_find_away_target_event_unlocking_device(
    void)
{
    adm_pool_target_unlocking_device_typ * pool_target_unlocking_device;

    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlocking_device");
    #endif

    pool_target_unlocking_device = adm_entity_system.ent_unlocking_device.away_pool_head;

    adm_entity_system.ent_unlocking_device.away_pool_head = pool_target_unlocking_device->next;

    if (adm_entity_system.ent_unlocking_device.away_pool_head == NULL) {

        adm_entity_system.ent_unlocking_device.away_pool_tail = NULL;
    }

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_find_away_target_event_unlocking_device");
    #endif

    return (pool_target_unlocking_device);
}


/* Dispatch State Action */

void adm_dispatch_state_action_unlocking_device(
    adm_pool_target_unlocking_device_typ * pool_target)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlocking_device");
    #endif

    if (pool_target->ent_unlocking_device != NULL) {

        adm_object_existent_unlocking_device(
            pool_target->ent_unlocking_device,
            pool_target->error_location.file,
            pool_target->error_location.line,
            pool_target->error_location.rank);
    }

    switch (pool_target->evente) {

        /* Dynamic Events */

        case ADM_EVENT_UNLOCKING_DEVICE_DEVICE_UPDATE :

            switch ((pool_target->ent_unlocking_device)->status) {

                case ADM_STATUS_UNLOCKING_DEVICE_UPDATING :

                    adm_sim_display_state_unlocking_device_updating(pool_target);

                    (pool_target->ent_unlocking_device)->status = ADM_STATUS_UNLOCKING_DEVICE_UPDATING;

                    adm_state_action_unlocking_device_updating(
                        pool_target->ent_unlocking_device);

                break;
            }

        break;
    }

    adm_deallocate_memory(pool_target);

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_DISPATCHER, "adm_dispatch_state_action_unlocking_device");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */