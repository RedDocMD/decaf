load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "ast",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    visibility = [
        "//test:__pkg__",
    ],
    deps = [
        "//grammar:grammar_lib",
    ],
)
