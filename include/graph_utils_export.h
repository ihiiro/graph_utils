
#ifndef GRAPH_UTILS_EXPORT_H
#define GRAPH_UTILS_EXPORT_H

#ifdef GRAPH_UTILS_STATIC_DEFINE
#  define GRAPH_UTILS_EXPORT
#  define GRAPH_UTILS_NO_EXPORT
#else
#  ifndef GRAPH_UTILS_EXPORT
#    ifdef graph_utils_EXPORTS
        /* We are building this library */
#      define GRAPH_UTILS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define GRAPH_UTILS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef GRAPH_UTILS_NO_EXPORT
#    define GRAPH_UTILS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef GRAPH_UTILS_DEPRECATED
#  define GRAPH_UTILS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef GRAPH_UTILS_DEPRECATED_EXPORT
#  define GRAPH_UTILS_DEPRECATED_EXPORT GRAPH_UTILS_EXPORT GRAPH_UTILS_DEPRECATED
#endif

#ifndef GRAPH_UTILS_DEPRECATED_NO_EXPORT
#  define GRAPH_UTILS_DEPRECATED_NO_EXPORT GRAPH_UTILS_NO_EXPORT GRAPH_UTILS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GRAPH_UTILS_NO_DEPRECATED
#    define GRAPH_UTILS_NO_DEPRECATED
#  endif
#endif

#endif /* GRAPH_UTILS_EXPORT_H */
