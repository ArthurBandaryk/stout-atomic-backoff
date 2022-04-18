"""Dependency specific initialization."""

# We use '@unused' to avoid buildifier's warning
# about using unused variable 'repo_mapping'.
# https://github.com/bazelbuild/buildtools/blob/master/WARNINGS.md#variable-is-unused
# @unused
def deps(
    repo_mapping = {} # @unused
):
    pass
