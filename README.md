Provides `stout::AtomicBackoff` as well as some thread helpers (such as `stout::this_thread::pause()` which compliments `std::this_thread::yield()`).

# Bazel build rules

Follows a "repos/deps" pattern (in order to help with recursive dependencies). To use:

1. Copy `bazel/repos.bzl` into your repository at `3rdparty/stout-atomic-backoff/repos.bzl` and add an empty `BUILD` (or `BUILD.bazel`) to `3rdparty/stout-atomic-backoff` as well.

2. Copy all of the directories from `3rdparty` that you ***don't*** already have in ***your*** repository's `3rdparty` directory (if applicable).

3. Either ... add the following to your `WORKSPACE` (or `WORKSPACE.bazel`):

```bazel
load("//3rdparty/stout-atomic-backoff:repos.bzl", stout_atomic_backoff_repos="repos")
stout_atomic_backoff_repos()

load("@com_github_3rdparty_stout_atomic_backoff//bazel:deps.bzl", stout_atomic_backoff_deps="deps")
stout_atomic_backoff_deps()
```

Or ... to simplify others depending on ***your*** repository, add the following to your `repos.bzl`:

```bazel
load("//3rdparty/stout-atomic-backoff:repos.bzl", stout_atomic_backoff="repos")

def repos():
    stout_atomic_backoff()
```

And the following to your `deps.bzl`:

```bazel
load("@com_github_3rdparty_stout_atomic_backoff//bazel:deps.bzl", stout_atomic_backoff="deps")

def deps():
    stout_atomic_backoff()
```

4. You can then use `@com_github_stout_atomic_backoff//:atomic-backoff` in your target's `deps`.

5. Repeat the steps starting at (1) at the desired version of this repository that you want to use.