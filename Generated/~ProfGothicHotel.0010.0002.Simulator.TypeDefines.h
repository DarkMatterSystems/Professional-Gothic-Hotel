
/* Simulator System Type Defines Header */

typedef struct {
    adm_base_string_typ * name;
} adm_sim_domain_typ;

typedef struct {
    adm_base_integer_typ   domain;
    adm_base_string_typ  * name;
    adm_base_boolean_typ   active;
    void (*display_procedure)(void);
} adm_sim_entity_typ;

typedef struct {
    adm_base_integer_typ   domain;
    adm_base_integer_typ   entity;
    adm_base_string_typ  * name;
    adm_base_boolean_typ creation;
    void (*acquire_procedure)(void);
} adm_sim_event_typ;

typedef struct {
    adm_base_integer_typ   domain;
    adm_base_integer_typ   entity;
    adm_base_integer_typ   evente;
    adm_base_string_typ  * name;
    void (*acquire_procedure)(void);
} adm_sim_identifier_typ;

/* Trace Command Options */

typedef struct {
    adm_base_boolean_typ all;
    adm_base_boolean_typ display;
    adm_base_boolean_typ events;
    adm_base_boolean_typ states;
} adm_sim_trace_typ;

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */