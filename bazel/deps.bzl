"""Dependency specific initialization."""

def deps(repo_mapping = {}):
    # We use '_repo_mapping' with underscore to avoid buildifier's warning
    # about using unused variable 'repo_mapping'.
    # https://github.com/bazelbuild/buildtools/blob/master/WARNINGS.md#variable-is-unused
    _repo_mapping = repo_mapping
    pass
