/*
 * ModSecurity for Apache 2.x, http://www.modsecurity.org/
 * Copyright (c) 2004-2006 Thinking Stone (http://www.thinkingstone.com)
 *
 * You should have received a copy of the licence along with this
 * program (stored in the file "LICENSE"). If the file is missing,
 * or if you have any other questions related to the licence, please
 * write to Thinking Stone at contact@thinkingstone.com.
 *
 */
#ifndef _MSC_GEO_H_
#define _MSC_GEO_H_

#define GEO_STRUCT_INFO_MAX_SIZE  20
#define GEO_DB_INFO_MAX_SIZE      100
#define GEO_COUNTRY_OFFSET        0xffff00
#define GEO_MAX_RECORD_LEN        4
#define GEO_COUNTRY_UNKNOWN       "Unknown"
#define GEO_CITY_UNKNOWN          "Unknown"
#define GEO_CITY_RECORD_LEN       50
#define GEO_COUNTRY_DATABASE      1
#define GEO_CITY_DATABASE_0       6
#define GEO_CITY_DATABASE_1       2

typedef struct geo_rec geo_rec;
typedef struct geo_db geo_db;

#include <apr_file_io.h>
#include "modsecurity.h"

/* Structures */

struct geo_rec {
    const char *country_code;
    const char *country_code3;
    const char *country_name;
    const char *country_continent;
    const char *region;
    const char *city;
    const char *postal_code;
    float       latitude;
    float       longitude;
    int         dma_code;
    int         area_code;
};

struct geo_db {
    apr_file_t *db;
    const char *dbfn;
    int dbtype;
    unsigned int ctry_offset;
};

/* Functions */

int DSOLOCAL geo_init(directory_config *dcfg, const char *dbfn, char **error_msg);

int DSOLOCAL geo_lookup(modsec_rec *msr, geo_rec *rec, const char *target, char **error_msg);

apr_status_t DSOLOCAL geo_cleanup(modsec_rec *msr);

#endif