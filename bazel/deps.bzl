"""Dependency specific initialization."""

# We use '_repo_mapping' with underscore as the parameter
# in the 'deps()' function to avoid buildifier's warning
# about using unused variable 'repo_mapping'.
# https://github.com/bazelbuild/buildtools/blob/master/WARNINGS.md#variable-is-unused
def deps(_repo_mapping = {}):
    pass
