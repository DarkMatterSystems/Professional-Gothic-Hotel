
#include "~ProfGothicHotel.0000.0000.Header.h"


/* Domain Scheduler Initialisation */

void adm_scheduler_initialisation_gothic_security(
    void)
{
    #if ADM_PROBE
    adm_probe_enter(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_gothic_security");
    #endif

    adm_dispatch_home_pool_room_device();
    adm_dispatch_home_pool_room_door();
    adm_dispatch_home_pool_secret_panel();
    adm_dispatch_home_pool_unlocking_device();
    adm_dispatch_home_pool_unlocking_sequence();
    adm_dispatch_home_pool_unlock_step();

    #if ADM_PROBE
    adm_probe_leave(ADM_PROBE_GROUP_INITIALISATION, "adm_scheduler_initialisation_gothic_security");
    #endif
}

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */