#ifndef EXTRACT_H
#define EXTRACT_H

/*
 * Functions for programmatically extracting data from VisIt/Libsim.
 */

int extract_set_options(const char *format, int writeUsingGroups, int groupSize);

const char *extract_err(int err);

int extract_slice_3v(const char *filebase, 
                     const double *v0, const double *v1, const double *v2,
                     const char **extractvars);

int extract_slice_origin_normal(const char *filebase,
                                const double *origin,
                                const double *normal,
                                const char **extractvars);

int extract_slice(const char *filebase, int axis, double intercept,
                  const char **extractvars);

int extract_iso(const char *filebase, const char *isovar,
                const double *isovalues, int nisovalues,
                const char **extractvars);

int extract_streamline(const char *filebase, const char *vectorvar,
                       const double *seeds, int lseeds, const char **extractvars);

#endif
