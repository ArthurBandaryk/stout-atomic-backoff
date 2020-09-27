#include "gtest/gtest.h"

#include "stout/atomic-backoff.h"

TEST(AtomicBackoffTest, Backoff)
{
  size_t i = 0;
  for (stout::atomic_backoff b; ; b.pause()) {
    if (i < 10) {
      break;
    }
  }
}
