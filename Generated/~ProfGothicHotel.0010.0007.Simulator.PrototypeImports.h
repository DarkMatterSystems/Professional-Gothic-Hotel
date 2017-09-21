
/* Simulator System Prototype Imports Header */

/* Main Prototype */

void adm_sim_main(
    int    argc,
    char * argv[]);


/* Fetch Prototypes */

adm_base_integer_typ adm_sim_idt_fetch(
    void);

adm_base_integer_typ adm_sim_int_fetch(
    void);

adm_base_boolean_typ adm_sim_bln_fetch(
    void);

adm_base_float_typ adm_sim_fxd_fetch(
    void);

adm_base_float_typ adm_sim_flt_fetch(
    void);

void adm_sim_enm_fetch(
    adm_base_string_typ * literal_string);

void adm_sim_str_fetch(
    adm_base_string_typ  * text_string,
    adm_base_integer_typ   string_length);


/* Library Prototypes */

void adm_sim_display_underline(
    adm_base_integer_typ length);

void adm_sim_display_row(
    adm_base_string_typ character,
    adm_base_integer_typ length);

adm_base_string_typ * adm_sim_lib_itoa(
    adm_base_integer_typ integer_number);

adm_base_string_typ * adm_sim_lib_fxtoa(
    adm_base_float_typ fixed_number);

adm_base_string_typ * adm_sim_lib_fltoa(
    adm_base_float_typ float_number);


/* Error Handler Prototype */

void adm_sim_error_report(
    adm_err_number_typ    error,
    adm_err_problem_typ * item);

/* Copyright (C) 2017 Dark Matter Systems Ltd. All rights reserved. */