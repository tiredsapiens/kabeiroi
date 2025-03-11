#pragma once
#include "../defines.h"

// to disable assertions comment out
#define KASSERTIONS_ENABLED

#ifdef KASSERTIONS_ENABLED
#if _MSC_VER
#define debugBreak() _debug_break()
#else
#define debugBREAK() __builtin_trap()
#endif

KAPI void report_assertion_failure(const char *expression, const char *message, const char *file,
                              i32 line);

#define KASSERT(expr)                                                                              \
  {                                                                                                \
    if (expr) {                                                                                    \
    } else {                                                                                       \
      report_assertion_failure(#expr, "", __FILE__, __LINE__);                                        \
      debugBREAK();                                                                                \
    }                                                                                              \
  }
#define KASSERT_MSG(expr, message)                                                                 \
  {                                                                                                \
    if (expr) {                                                                                    \
    } else {                                                                                       \
      report_assertion_failure(#expr, message, __FILE__, __LINE__);                                   \
      debugBREAK();                                                                                \
    }                                                                                              \
  }
#ifdef _DEBUG
#define KASSERT_DEBUG(expr)                                                                        \
  {                                                                                                \
    if (expr) {                                                                                    \
    } else {                                                                                       \
      reoprt_assertion_failure(#expr, "", __FILE__, __LINE__);                                        \
      debugBREAK();                                                                                \
    }                                                                                              \
  }
#else
#define KASSERT_DEBUG(expr, message)
#endif
#else
#define KASSERT(expr) //does nothing at all
#define KASSERT_MSG(expr, message)
#define KASSERT_DEBUG(expr)
#endif