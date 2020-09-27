#pragma once

#include <sched.h>

#ifndef STOUT_ATOMIC_BACKOFF_PAUSE
#define STOUT_ATOMIC_BACKOFF_PAUSE() sched_yield()
#endif

#ifndef STOUT_ATOMIC_BACKOFF_YIELD
#define STOUT_ATOMIC_BACKOFF_YIELD() sched_yield()
#endif

namespace stout {

class atomic_backoff
{
public:
  atomic_backoff(size_t pauses_before_yield = 16, size_t pauses = 1)
    : pauses_before_yield(pauses_before_yield), pauses(pauses) {}

  atomic_backoff(const atomic_backoff&) = delete;
  atomic_backoff& operator=(const atomic_backoff&) = delete;

public:
  void pause()
  {
    if (pauses <= pauses_before_yield) {
      STOUT_ATOMIC_BACKOFF_PAUSE();
      pauses *= 2;
    } else {
      STOUT_ATOMIC_BACKOFF_YIELD();
    }
  }

private:
  const size_t pauses_before_yield;
  size_t pauses;
};

} // namespace stout {
